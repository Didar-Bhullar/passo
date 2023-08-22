#include "rules.h"
#include "stdio.h"
#include "stdlib.h"
#include <string.h>

const char *err_zero_message = "Error: Number of characters must be greater than 0\n";
const char *err_exceed_message = "Error: Number of symbols and digits cannot exceed the total number of characters\n";

void rules_init(rules *r, 
                uint64_t total_characters, 
                uint64_t n_digits,
                uint64_t n_symbols, 
                bool allow_upper_case,   
                bool allow_repeating) {
    r->total_characters = total_characters;
    r->n_digits = n_digits;
    r->n_symbols = n_symbols;
    r->allow_upper_case = allow_upper_case;
    r->allow_repeating = allow_repeating;
}

bool check_rules(rules *r, char *mssg) { 
    if ((r-> total_characters == 0)) { 
        strcpy(mssg, err_zero_message);
        return false;
    }

    if ( (r->total_characters < (r->n_symbols + r->n_digits) )) { 
        strcpy(mssg, err_exceed_message);
        return false;
    }

    return true;
}

long generate_password(rules *r){
    long t_chars = r->total_characters;
    long n_d = r->n_digits;
    long n_s = r->n_symbols;
    bool u_case = r->allow_upper_case;
    bool repeat = r->allow_repeating;

    // bytes needed is total_characters * 2
    // extra byte needed for random insertion
    long bytes_needed = t_chars * 2;
    long letters_needed = t_chars - n_d - n_s;
    uint8_t letter_availability = u_case ? 52: 26;
}

char *get_random_bytes(long amount, int range){
    uint8_t *buffer = malloc(amount * sizeof(char));

    FILE *file; 
    file = fopen(u_random, "rb");
    bool finished = false;
    for (int i = 0; !finished; i++) { 

        fread(buffer+i,1,1, file);
        if (buffer[i] > range) { 
            i--;
            amount++;
        }
        amount--;
    
        if (amount == 0) finished = true;
    }
    //free(buffer);
    return buffer;
}

// long generate_letters(long amount)
// long generate_digits(long amount)
// long generate_symbols(long amount)