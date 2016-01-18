#include <stdio.h>
#include <string.h>

typedef enum {false, true} bool;


void main(){
	char *keywords[32] = {"auto", "break", "case", "char", "const", "continue", "default", "do" , "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
	char *line = NULL;
	FILE *ptr;
	ptr=fopen("CD_lab1.c","r");
	if(ptr==NULL){
		printf("File couldn't be opened\n");
	}
	else{
		int read;
		int buf_size = 3;
		bool comment_start = false;
		int start_index;
		while((read = getline(&line,&buf_size,ptr)) != -1){
			int i = 0;
			bool exec_line = false;
			bool single_line_comment = false;
			int j=0;
			char keyword_check[100] = {'\0'};
			while(line[i] != '\0'){
				if(line[i] == '/'){
					if(line[i+1] == '/'){
						single_line_comment = true;
					}
					else if(line[i+1] == '*'){
						comment_start = true;
					}
					else if(line[i-1] == '*')
						comment_start = false;
				}
				else if(line[i] != '\n' && line[i] != '\t' && line[i] != '\r'  && !single_line_comment && !comment_start){
					if(line[i] == ' '){
						j = 0;
						int k;
						for(k=0;k<32;k++){
							if(strcmp(keyword_check, keywords[k]) == 0){
								printf("%s\n", keywords[k]);
								break;
							}
						}
						for(k=0;k<100;k++)
							keyword_check[k] = '\0';
					}
					else{
						keyword_check[j] = line[i];
						j++;
					}
				}
				i++;
			}
		}
	}
	fclose(ptr);
}