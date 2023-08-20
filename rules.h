#include <stdbool.h>
#include <stdint.h>

# define rules_buffer_size 100
# define u_random "/dev/urandom"

extern const char *err_zero_message;
extern const char *err_exceed_message;

typedef struct rules { 
    uint64_t total_characters;
    uint64_t n_digits;
    uint64_t n_symbols;
    bool allow_upper_case;
    bool allow_repeating;
} rules;

void rules_init(rules *r, uint64_t total_characters, 
                          uint64_t n_digits, 
                          uint64_t n_symbols,
                          bool allow_upper_case, 
                          bool allow_repeating);

bool check_rules(rules *r, char *mssg);
long generate_password(rules *r);
char *get_random_bytes(long amount, int range);