// This is a valid comment
/*             */#include<stdio.h>                                                           
#include<conio.h> 
	

	
	
/* Multi
       Line
  Comment 
*/                                                           
void main()                                                                
{                                                                             
   FILE *fp;    //this is a single line comment                                                                 
   char c;                                                                       
   /*       */clrscr();                                                                   
   /*     */fp=fopen("try.txt","r");                                                    
  do                                                                            
  {        
  int a;                                                                     
   c = getc(fp);                                                                 
   printf("%c",c);                                                              
  }                                                                             
  while(!feof(fp));                                                             
  getch();                                                                      
}
