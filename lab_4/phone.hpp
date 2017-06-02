#ifndef PHONE_HPP
#define PHONE_HPP

class Phone {
    public:
        Phone();
        Phone(char *name, char *surname, char *fathername,
            char *address, char *number, double time_in, double time_out);
        ~Phone();
        Phone &operator=(const Phone &rhs);

        static int sort_alphabit(Phone *phone, int len);

        int set_name(char *name);
        int set_surname(char *surname);
        int set_fathername(char *fathername);
        int set_address(char *address);
        int set_number(char *number);

        void set_time_in(double time_in);
        void set_time_out(double time_out);
        void print_phone();

        const char* get_name() const;
        const char* get_surname() const;
        const char* get_fathername() const;
        const char* get_address() const;
        const char* get_number() const;
        const double get_time_in() const;
        const double get_time_out() const;

    private:
        static int cmp(const void *a, const void *b);

        char *name, *surname, *fathername, *address, *number;
        double time_in, time_out;
};

#endif // PHONE_HPP
