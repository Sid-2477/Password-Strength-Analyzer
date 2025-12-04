#include <stdio.h>
int main() {
    char password[20];
    int i = 0, uppercase = 0, lowercase = 0, digit = 0, special = 0, length = 0;
    printf("Enter your password: ");
    scanf("%s", password);
    while (password[i] != '\0') {
        char ch = password[i];
        length++;
        if (ch >= 'A' && ch <= 'Z') {
            uppercase++;}
        else if (ch >= 'a' && ch <= 'z') {
            lowercase++;}
        else if (ch >= '0' && ch <= '9') {
            digit++;}
        else if (ch=='!'||ch =='@'||ch=='#'||ch=='$'||
                 ch=='%'||ch =='^'||ch=='&'||ch=='*'||
                 ch=='-'||ch =='_'||ch=='+'||ch=='=') {
            special++;}
        i++;
    }
    if (length >= 12 && uppercase >= 1 && lowercase >= 1 && 
        digit >= 1 && special >= 1) {
        printf("\nPassword Strength: STRONG\n");
    } else {
        printf("\nPassword Strength: WEAK\n");
        printf("Requirements not met:\n");
        if (length < 12) printf("- Minimum 12 characters required\n");
        if (uppercase < 1) printf("- At least 1 uppercase letter needed\n");
        if (lowercase < 1) printf("- At least 1 lowercase letter needed\n");
        if (digit < 1)    printf("- At least 1 number required\n");
        if (special < 1)  printf("- At least 1 special character (!,@,#,$,%%,^,&,*,-,_,+,=) needed\n");
    }
return 0;
}
