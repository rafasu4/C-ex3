#include <stdio.h>
#include <string.h>
#define WORD 30
#define LINE 256

int getFirstWord(char w[], char* op){
    char c = getchar();
    int i = 0;
    while(c!=EOF && c!='\n' && c!=' ' && c!='\t' && i<WORD){
        w[i] = c;
        c = getchar();
//        if(c==EOF || c=='\n' || c==' ' || c=='\t'){
//            w[i] = c;
//        }
        i++;
    }
    *op = getchar();
    w[i] = '\0';
    return i;
}

int getWord(char w[]){
    char cr = getchar();
    int i = 0;
    while(cr!=EOF && cr!='\n' && cr!=' ' && cr!='\t' && i<WORD){
        w[i] = cr;
        cr = getchar();
        
//        if(c==EOF || c=='\n' || c==' ' || c=='\t'){
//            w[i] = c;
//        }
        i++;
    }
    if(i>0) {
        w[i] = '\0';
    }
    return i;
}


int getLine(char s[]){
    char c = getchar();
    if(c==EOF) return -1;
    int i = 0;
    while(c!=EOF && c!='\n' && i<LINE){
        s[i] = c;
        c = getchar();
        i++;
    }
    s[i] = '\0';
    return i;
}


int substring1(char *str1, char *str2) {
    int len2 = strlen(str2);
    int len1 = strlen(str1);
    int i = 0;
    int j = 0;
    int flag = 0;
    //running all over st1
    while (i < len1) {
        //if we reach to the end of str2 - str2 is in str1
        if(j==len2){
            flag = 1;
            break;
        }
        //if they have the same char - move to the next char
        if (str1[i] == str2[j]) {
            i++;
            j++;
        }
            //if there isn't match - move to the next char in str1
        else if(str1[i] == str2[0]){
            j=1;
            i++;}
        else{
            j=0;
            i++;
        }
    }
    if (j == len2) flag = 1;
    return flag;
}

int substring2(char *str1, char *str2){
    int len2= strlen(str2);
    int len1= strlen(str1);
    int i=0;
    int j=0;
    int flag=0;

    while(i<len1){
        if( str1[i]==str2[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    if(j==len2){
        flag=1;
    }
    return flag;
}

int similar(char *s, char *t, int n) {
    int len2 = strlen(s);
    int len1 = strlen(t);
    int ans = len2 - len1;
    if (substring2(s, t) == 0) { return 0; }
    else if (ans > n) { return 0; }
    return 1;
}


void print_lines(char* str) {
    char currentLine[LINE];
    while(getLine(currentLine) > 0){
        if(substring1(currentLine,str)){
            printf("%s\n",currentLine);
        }
    }
}

void print_similar_words(char* str) {
    char someWord[WORD];
    int ans, i;
    while (1) {
        i = getWord(someWord);
        if(i==0) break;
        ans = similar(someWord, str, 1);
        //printf("|%d + %s |\n",ans, someWord);
//        for (int j = 0; j <i ; ++j) {
//            printf("%c, ",someWord[j]);
//        }
//        printf("\n");
        if (ans == 1) {
            printf("%s\n", someWord);
        }
    }
}



int main(){
    int i = 0, j = 0, ans;
    char firstWord[WORD];
    char someLine[LINE], operation;
    char* ptr = &operation;
    i = getFirstWord(firstWord, ptr);
    printf("%s\n",firstWord);
    printf("%c\n",operation);
//    while(getLine(someLine)>0){
//        printf("%s\n",someLine);
//    }
//    for (int k = 0; k < i; ++k) {
//        printf("%c",firstWord[k]);
//    }
//    printf("\n");

//
    switch (operation) {
        case 'a':
            print_lines(firstWord);
            break;

        case 'b':
            print_similar_words(firstWord);
            break;

        default:
            printf("Nothing to do");
    }

//    printf("\n");
//    printf("%d",j);
//    printf("\n");
    return 0;
}
