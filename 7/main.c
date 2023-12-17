#include <stdio.h>
#include <locale.h>

#define CONSONANTS (1 << (225 - 224) | 1 << (226 - 224) | 1 << (227 - 224) | 1 << (228 - 224) | 1 << (231 - 224) | 1 << (230 - 224) | 1 << (235 - 224) | 1 << (236 - 224) | 1 << (237 - 224) | 1 << (240 - 224) | 1 << (233 - 224) | 1 << (239 - 224) | 1 << (244 - 224) | 1 << (234 - 224) | 1 << (242 - 224) | 1 << (241 - 224) | 1 << (248 - 224) | 1 << (245 - 224) | 1 << (246 - 224) | 1 << (247 - 224))
#define HISSING_SET (1 << (247 - 224) | 1 << (230 - 224) | 1 << (248 - 224) | 1 << (249 - 224))

int main(){
    int state = 0; int s;
    setlocale(LC_ALL, ".866");

    while ((s = getchar()) != EOF) {
        switch (state) {
            case 0:
            case 1:
                if ((192 <= s) && (s <= 223)) { s += 32; }

                if ((224 <= s) && (s <= 255)){
                    unsigned int current_mask = 0;
                    int index = s - 224;
                    current_mask |= (1 << index);

                    if ((CONSONANTS | current_mask) == CONSONANTS) {
                        if ((HISSING_SET | current_mask) == HISSING_SET) { state = 2; }
                        else { state = 3; }
                    }
                    else { state = 2; }
                }
                else { state = 1; }

                break;

            case 2:
                if ((192 <= s) && (s <= 223)) { s += 32; }

                if ((224 <= s) && (s <= 255)){
                    unsigned int current_mask = 0;
                    int index = s - 224;
                    current_mask |= (1 << index);

                    if ((CONSONANTS | current_mask) == CONSONANTS){
                        if ((HISSING_SET | current_mask) == HISSING_SET) { state = 2; }
                        else { state = 3; }
                    }
                    else { state = 2; }
                }
                else { printf("YES"); return 0; }
                break;

            case 3:
                if ((192 <= s) && (s <= 255)) { state = 3; }
                else { state = 1; }
        }
    }

    if (state == 2) { printf("YES"); }
    else { printf("NO"); }

    return 0;
}