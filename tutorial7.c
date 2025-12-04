#include <stdio.h>
#include <ctype.h>
int main() {
    FILE *fin = fopen("file.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    if (!fin) {
        printf("Error: Cannot open file.txt\n");
        return 1;
    }
    if (!fout) {
        printf("Error: Cannot create output.txt\n");
        fclose(fin);
        return 1;
    }
    char ch, prev = 0;
    int capitalize = 0;

    while ((ch = fgetc(fin)) != EOF) {
        if (capitalize && isalpha(ch)) {
            ch = toupper(ch);
            capitalize = 0;
        }
        if (ch == '.') {
            capitalize = 1;
            fputc(ch, fout);
            continue;
        }
        if (ch == ' ') {
            if (prev != ' ') {       
                fputc(ch, fout);
            }
        } else {
            fputc(ch, fout);        
        }
        prev = ch;
    }

    fclose(fin);
    fclose(fout);
    printf("Output written to output.txt successfully.\n");
    return 0;
}