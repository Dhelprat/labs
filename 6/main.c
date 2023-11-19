#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    int state = 0; double answer = 0; int last_ind = 0; char num[1000] = {0};
    char s;

    while ((scanf("%c", &s)) != EOF) {
        switch (state) {
            case 0:
                if ( isdigit(s) ) { num[last_ind] = s; last_ind ++; state = 1; }
                else { state = 0; }

                break;

            case 1:
                if ( isdigit(s) ) { state = 1; num[last_ind] = s; last_ind ++; }
                else if ( s == 'i' ) { state = 2; }
                else { last_ind = 0; memset(num, '\0', sizeof num); state = 0; }

                break;

            case 2:
                if ( s == 'n' ) { state = 3; }
                else if ( isdigit(s) ) { last_ind = 1; memset(num, '\0', sizeof num);; num[0] = s; state = 1; }
                else { last_ind = 0; memset(num, '\0', sizeof num); state = 0; }

                break;

            case 3:
                answer = strtol(num, NULL, 10) * 25.4;
                printf("%.2fmm\n", answer);

                if ( isdigit(s) ) { memset(num, '\0', sizeof num);; last_ind = 1; num[0] = s; state = 1; }
                else { memset(num, '\0', sizeof num); last_ind = 0; state = 0; }

                break;
        }
    }

    if (state == 3){
        answer = strtol(num, NULL, 10) * 25.4;
        printf("%.2fmm\n", answer);
    }
}
