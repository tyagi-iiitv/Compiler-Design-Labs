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
		int buf_size = 1024;
		int comments = 0;
		int exec = 0;
		bool comment_start = false;
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
					else if(line[i-1] == '*'){
						comment_start = false;
						comments++;
					}

				}
				else if(line[i] != ' ' && line[i] != '\n' && line[i] != '\t' && line[i] != '\r'  && !single_line_comment && !comment_start)
					exec_line = true;
				i++;
			}
			if(exec_line){
				exec++;
			}
			if(comment_start || single_line_comment){
				comments++;
			}
		}
		printf("Executable lines = %d\n",exec);
		printf("Commented lines = %d\n", comments);
	}
	fclose(ptr);
}