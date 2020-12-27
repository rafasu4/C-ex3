#include <stdio.h>
#include <string.h>
#define LINE 256

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


int similar( char*s, char* t, int n){
    int len2= strlen(s);
    int len1= strlen(t);
    int ans= len2-len1;
    if( substring2(s,t)==0){ return 0; }
    else{ if(ans>n){ return 0; }
    else{ return 1; }
    }
}

void print_lines(char* str, char* cur) {
    char arr[250][256];
    int j = 0;
    int str_len = strlen(str);
    int ans = 0;

    for (int i = 0; i < 250; ++i) {
        for (int k = 0; k < 256; ) {
            while (str[j] != '\n' && j < str_len) {
                arr[i][k] = str[j];
                j++;
                k++;
            }
            j++;
            break;
        }
    }
    for (int i = 0; i < 250; ++i) {
        j = 0;
        ans = substring1(arr[i], cur);
        if (ans == 1) {
            while ( j < 256) {//j != '\n'
                printf("%c", arr[i][j]);
                j++;
            }
            printf("\n");
        }
    }
}

void print_similar_words(char* str,char* cur){
    char arr[250][256];
    int j = 0;
    int str_len = strlen(str);
    int ans = 0;
    for (int i = 0; i < 250; ++i) {
        for (int k = 0; k < 256; ) {
            while (str[j] != '\n' && str[j] != '\t' && str[j]  && str[j] != ' ' && j < str_len) {
                arr[i][k] = str[j];
                j++;
                k++;
            }
            j++;
            break;
        }
    }
    for (int i = 0; i < 250; ++i) {
        j = 0;
        ans = similar(arr[i], cur,1);
        if (ans == 1) {
            while (str[j] != '\n' && str[j] != '\t' &&  str[j] != ' ' && j != 256) {
                printf("%c", arr[i][j]);
                j++;
            }
            printf("\n");
        }
    }
}

int main() {

	char word[LINE];
	char arr[250][256];
	char operation, temp;
	int i=0;

	./isort < isort_input.txt
    ./txtfind < find_input.txt

    for (int i = 0; i < 250; ++i)
    {
    	for (int j = 0; j <256; ++j)
    	{
    		scanf("%c",&temp);
    		
    		if(temp=='\n'){
    			arr[i][j]=temp;
    			break;
    		}

    		else{
    			arr[i][j]=temp;
    		}
    	}
    }
    i=0;

    while(arr[0][i]!=' '){
    	word[i]=arr[0][i];
    }
    i++;

    operation=arr[0][i];


	switch(operation){

		case 'a':
		print_lines(arr[2][0],word);
		break;

		case 'b';
		print_similar_words(arr[2][0],word);
		break;
	}




    // char str[] = {'t','h','i','s',' ','s',' ','a',' ', 't','e','x','t',' ', 'f','i','l','e','\n',
    //         'l','o','o','k','i','n','g',' ', 'f','o','r',' ', 't','h','e',' ', 'w','o','r','d',' ', 'c','a','t','\n'
    //         ,'t','h','e',' ', 'p','r','o','g','r','a','m',' ', 's','h','o','u','l','d',' ', 'p','r','i','n','t',' ', 'a','l','s','o',' ', 'c','a','t','s','\n',
    //         'a','f','t','e','r', ' ','c','a','t','s', ' ','c','r','a','t',' ', 'a','n','d',' ', 'l','c','a','t',' ', 'a','r','e',' ', 'p','r','i','n','t','e','d','\n'
    //         ,'t','h','e',' ', 'p','r','o','g','r','a','m',' ', 's','h','o','u','l','d','n','\’','t',' ', 'p','r','i','n','t','\n',
    //         't','h','e', ' ','w','o','r','d', ' ', 'c','a','a','t','s','\0'};
    // char cur[] = {'c', 'a','t', '\0'};
    // print_lines(str, cur);
    // printf("\n");
    // print_similar_words(str,cur);
    return 0;
}




