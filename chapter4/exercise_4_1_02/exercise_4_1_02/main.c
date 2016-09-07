//
//  main.c
//  exercise_4_1_02
//
//  Created by chengaojie on 16/9/7.
//  Copyright © 2016年 chengaojie. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000    /* maxinum input line length */

int ngetline(char line[], int max);
int nstrrightmostindex(char s[], char t[]);

char pattern[] = "ould";    /* pattern to search for */

/*  find all lines matching pattern */
int main(int argc, const char * argv[]) {
    char line[MAXLINE];
    int found  = 0;
    
    while (ngetline(line, MAXLINE) > 0) {
        if (nstrrightmostindex(line, pattern) >= 0) {
            found++;
        }
    }
    
    printf("%d line contains %s\n", found, pattern);
    return found;
}

/* ngetline: get line into s, return length */
int ngetline(char line[], int max) {
    int c, i;
    
    c = 0;
    i = 0;
    while (--max > 0 && (c=getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }
    
    if (c == '\n') {
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}

/* nstrrightmostindex: returns rightmost index of t in s, -1 if none */
int nstrrightmostindex(char s[], char t[]) {
    int i, j, k;
    
    for (i = (int)(strlen(s) - strlen(t)); i >= 0; i--) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
            ;
        }
        
        if (k > 0 && t[k] == '\0') {
            return i;
        }
    }
    return -1;
}
