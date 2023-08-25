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

    r->lower_letters = "abcdefghijklmnopqrstuvwxyz";
    r->upper_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    r->symbols = "~!@#$%^&*()_+`-={}|[]\\:\"<>?,./";
    r->digits = "0123456789";
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
    uint8_t *s;
    int letter_availability = r->allow_upper_case ? 52: 26;

    long letters_needed = r->total_characters - r->n_digits - r->n_symbols;
    printf("total_characters: %d\n", r->total_characters);
    printf("n_digits: %d\n", r->n_digits);
    printf("n_symbols: %d\n", r->n_symbols);
    printf("letters needed is: %d\n", letters_needed);
    printf("the letter_avail is: %d\n", letter_availability);
    // letter range
    int range =  256 - letter_availability -1;
    long amount = letters_needed;


    // letters
    if (letters_needed != 0) {
        s = malloc(letters_needed * sizeof(char));
        load_bytes(letters_needed, range, s);

        //if (letters_needed > 26) { 

        //}
        //char *letters = (letters_needed > 26) ? 



        //printf("the range is: %d\n", range);
        //for(int i = 0; i < letters_needed; i++) {
            //printf("%x\n", s[i]);
        //}
    }

    // symbols
    if (r->n_digits != 0) { 
        range = 256 - r->n_digits - 1;
        s = malloc(r->n_digits * sizeof(char));
        load_bytes(r->n_digits,range,s);

        //printf("the range is: %d\n", range);
        //for(int i = 0; i < r->n_digits; i++) {
            //printf("%x\n", s[i]);
        //}
    }

    if (r->n_symbols != 0) { 
        range = 256 - r->n_symbols - 1;
        s = malloc(r->n_symbols * sizeof(char));
        load_bytes(r->n_symbols,range,s);

        printf("the range is: %d\n", range);
        for(int i = 0; i < r->n_symbols; i++) {
            printf("%x\n", s[i]);
        }
    }




    //for(int i = 0; i < 30; i++){
        //printf("%c", r->symbols[i]);
    //}

    free(s);
    return 5;

}

void load_bytes(long amount, int range, uint8_t *copier){
    FILE *file; 
    file = fopen(u_random, "rb");
    bool finished = false;
    for (int i = 0; !finished; i++) { 

        fread(copier+i,1,1, file);
        if (copier[i] > range) {
            printf("the buffer is over the range and is: %x\n", copier[i]); 
            i--;
            amount++;
        }
        amount--;
    
        if (amount == 0) finished = true;
    }
}