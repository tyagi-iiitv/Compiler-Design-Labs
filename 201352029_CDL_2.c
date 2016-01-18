#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

void main(){
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
				else if(line[i] != ' ' && line[i] != '\n' && line[i] != '\t' && line[i] != '\r'  && !single_line_comment && !comment_start){
					exec_line = true;
					start_index = i;
					break;
				}
				i++;
			}
			if(exec_line){
				bool hash_found = false;
				bool less_found = false;
				bool include_found = false;
				if(line[start_index] == '#'){
					hash_found = true;
				}
				else{
					break;
				}
				int i = start_index;
				if(hash_found){
					while(line[i] != '<'){
						if(line[i] == 'i' && line[i+1] == 'n' && line[i+2] == 'c' && line[i+3] == 'l' && line[i+4] == 'u' && line[i+5] == 'd' && line[i+6] == 'e'){
							include_found = true;
							i+=6;	
						}
						i++;
					}
				}
				if(include_found){
					i++;
					while(line[i] != '>'){
						if(line[i] != '\t' && line[i] != ' ' && line[i] != '\r')
							printf("%c", line[i]);
						i++;
					}
				}
				printf("\n");		
			}
		}
	}
	fclose(ptr);
}
