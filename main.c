#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "rules.h"


int main(void) { 

    //#ifdef __unix__
    rules r;                           
    long password;
    char r_buff[rules_buffer_size];   // create buffer to hold error message incase check_rules() fails

    rules_init(&r, 15, 2, 3, false, true);
    
    if (!check_rules(&r, r_buff)) {       // check if your rules are valid 
        fprintf(stderr,"%s", r_buff);     // print out error message
        exit(1);                        // best option is to exit if rule check fails
    }

    password = generate_password(&r);
    //char *s = get_random_bytes(20, 2);
    //for(int i = 0; i < 20; i++) {
        //printf("%x\n", *s);
        //s++;
    //}


    //#endif

}






