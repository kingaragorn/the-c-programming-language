#include <stdio.h>

int main(int argc, const char * argv[]) {
//    int i;
//    
//    for (i = 1; i < argc; i++) {
//        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
//    }
//    
//    printf("\n");
//    return 0;
    
    while (--argc > 0) {
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    }
    
    printf("\n");
    return 0;
}
