#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

main()
{

FILE* fp; 
char* address; 
char returnData[64]; 
char h[100][100]; 
int x =0; 

fp = popen("/sbin/ifconfig | awk '/^eth/{s=$1;getline;print $1,$2}'", "r");
while (fgets(returnData, 64, fp) != NULL) {
 char* tmp = returnData; 
 address= strtok(tmp, " ");

 while(address) { 
   strcpy(h[x], address); 
   x++;
   address = strtok(NULL," "); } 
} 

printf("The IP %s\n",h[1]);
pclose(fp); 

}