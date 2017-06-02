#include "btree.h"

struct Btree{
    struct Node *root;
};

struct Node{
    char *string;
    struct Node *pred, *right, *left;
};

//Work with Tree
//int go_left(FILE *out, struct Node *node);
int go_right(FILE *out, struct Node *node);
int print_node(FILE *out, struct Node *node);

void Insert(struct Node *node, struct Node *temp);
void PrintInOrder(FILE *out, struct Node *node);
void free_node(struct Node *node);
void Free_tree(struct Node *node);

//Work with DOT
void Export_to_dot(FILE *f, struct Node *node);
void to_dot(struct Node *tree, FILE *f);
void print_dot(FILE *f, struct Node *tree);

Btree *create_tree(){
    Btree *tree = (Btree*) malloc (sizeof(Btree));
    if (!tree)  return NULL;
    tree->root = NULL;
    return tree;
}

int add_in_tree(Btree *tree, char *str){
    if (tree->root == NULL) {
        tree->root = (struct Node*) malloc(sizeof(struct Node));
        tree->root->left = NULL, tree->root->right = NULL;
        tree->root->string = (char*) malloc(sizeof(char)*(strlen(str) + 1));
        if(!(tree->root->string))
            return MEMORY_NO_ALLOCATED;
        strcpy(tree->root->string, str);
        tree->root->pred = NULL;
    }
    else{
        struct Node *node = (struct Node*) malloc(sizeof(struct Node));
        node->left = NULL, node->right = NULL, node->pred = NULL;
        node->string = (char*) malloc(sizeof(char)*(strlen(str) + 1));
        if(!(tree->root->string))
            return MEMORY_NO_ALLOCATED;
        strcpy(node->string, str);
        Insert(tree->root, node);
    }
    return 0;
}

void Insert(struct Node *node, struct Node *temp) {
    while (node != NULL){
        if (strcmp(temp->string, node->string) > 0){
            if (node->right != NULL)
                node = node->right;
            else{
                temp->pred = node;
                node->right = temp;
                break;
            }
        }
        else if (strcmp(temp->string, node->string) <= 0){
            if (node->left != NULL)
                node = node->left;
            else{
                temp->pred = node;
                node->left = temp;
                break;
            }
        }
    }
}

int print_reverse_sort_tree(FILE *out, Btree *tree){
    if (go_right(out, tree->root) == ERROR_OUT_FILE)
        return ERROR_OUT_FILE;
    return 0;
}

/*int go_left(FILE *out, struct Node *node){
    if (node->right != NULL)
        go_right(out, node->right);
    if (print_node(out, node) == ERROR_OUT_FILE)
        return ERROR_OUT_FILE;
    if (node->left != NULL)
        go_left(out, node->left);
    return 0;
}*/

int go_right(FILE *out, struct Node *node){
    if (node->right != NULL)
        go_right(out, node->right);
    if (print_node(out, node) == ERROR_OUT_FILE)
        return ERROR_OUT_FILE;
    if (node->left != NULL)
        go_right(out, node->left);
    return 0;
}

int print_node(FILE *out, struct Node *node){
    if (node){
        fprintf(out, "%s    ", node->string);
        if (ferror(out) != 0)
            return ERROR_OUT_FILE;
        return 0;
    }
    return -1;
}

void printInOrder(FILE *out, Btree *tree){
    PrintInOrder(out, tree->root);
}

void PrintInOrder(FILE *out, struct Node *node) {
    if (node->left != NULL)
        PrintInOrder(out, node->left);
    print_node(out, node);
    if (node->right != NULL)
        PrintInOrder(out, node->right);
}

void free_tree(Btree *tree){
    if(tree){
        Free_tree(tree->root);
        free(tree);
    }
}

void Free_tree(struct Node *node){
    if (node){
        Free_tree(node->left);
        Free_tree(node->right);
        free_node(node);
    }
}

void free_node(struct Node *node){
    free(node->string);
    free(node);
}

//Work with DOT
void export_to_dot(FILE *f, Btree *tree){
    if (tree->root)
        Export_to_dot(f, tree->root);
}

void to_dot(struct Node *tree, FILE *f){
    if (tree == NULL)
        return;   
    to_dot(tree->left, f);
    print_dot(f, tree);
    to_dot(tree->right, f);
}

void print_dot(FILE *f, struct Node *tree){
    if (tree->left != NULL)
        fprintf(f, "%s -> %s;\n", tree->string, tree->left->string);
    if (tree->right != NULL)
        fprintf(f, "%s -> %s;\n", tree->string, tree->right->string);
}

void Export_to_dot(FILE *f, struct Node *node){
    fprintf(f, "digraph BINAR_TREE {\n" );
    to_dot(node, f);
    fprintf(f, "}\n");
}
