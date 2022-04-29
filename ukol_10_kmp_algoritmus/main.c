#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int knuth(char *string, char *pattern) {
    if (string == NULL) return -1;
    if (pattern == NULL) return -1;

    int stringLen = (int) strlen(string);
    int patternLen = (int) strlen(pattern);
    int *fail = calloc(patternLen, sizeof(int));
    {
        // sestavení fail funkce
        int j = 0;
        int i = 1;
        while (i < patternLen) {
            if (pattern[j] == pattern[i]) {
                fail[i] = j + 1;
                i++;
                j++;
            } else if (j > 0)
                j = fail[j - 1];
            else {
                fail[i] = 0;
                i++;
            }
        }
    }


    int i = 0; // index kontrolovaného charu ve stringu
    int j = 0; // index kontrolovaného charu v patternu

    // projde všechny chary ve stringu
    while (i < stringLen) {
        // pokud máme shodu
        if (pattern[j] == string[i]) {
            // pokud je "j" na posledním charu patternu
            // takže se všechny písmena shodují
            if (j == patternLen - 1)
                // vrátí index prvního písmena nalezeného slova
                return i - patternLen + 1;
            // pokud ještě ní na konci patternu
            // tak kontroluje další chary
            i++;
            j++;
        } else if (j > 0)
            // pokud se chary nerovnají
            // a kontroluje se NEprvní písmeno patternu

            j = fail[j - 1];
        else
            // pokud se chary nerovnají
            // a kontroluje se PRVNÍ písmeno patternu
            i++;
    }
    return -1;


}

int main() {
    printf("%d\n", knuth("ABABCBABABCABAB", "ABABCA"));
    return 0;
}
