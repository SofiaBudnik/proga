#define MAX_STRINGS_AMOUNT 10

#define MAX_STRING_LENGTH 80

typedef struct {
    int a_amount;
    int e_amount;
    int i_amount;
    int o_amount;
    int u_amount;
    int y_amount;
} vowels;
vowels get_info(char str[MAX_STRINGS_AMOUNT][MAX_STRING_LENGTH]);
void get_diagram(vowels vow);

