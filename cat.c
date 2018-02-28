#include<dirent.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 100
int op1;
int op2;
int f_count;
char *files[MAX_LEN];
void check_for_args(int ct,char **ar){
	int flag=-1;
	f_count=0;
	//printf("%s %s %s",ar[0],ar[1],ar[2]);
	for (int i=0;i<ct;i++){
		//printf("%s",ar[i]);
		int t1=strcmp("-b",ar[i]);
		int t2=strcmp("-n",ar[i]);
		int t3=strcmp("-bn",ar[i]);
		int t4=strcmp("-nb",ar[i]);
		//printf("%d %d %d %d",t1,t2,t3,t4);
		if (t1==0){
			op1=1;
			op2=0;
		}else if (t2==0){
			op1=0;
			op2=1;
		}else if ((t3==0)||(t4==0)){
			op1=1;
			op2=1;
		}else{
			//printf("%s",ar[i]);
			files[f_count]=ar[i];
			f_count++;
		}
		char *a;
		a=ar[i];
		if (*a=='-')flag=0;
		if ((flag==0)&&(op1==0)&&(op2==0))printf("Invalid Option\n");
	}
	/*if (ct==2){
		op1=0;
		op2=0;
	}else if (ct==4){
		//check if arguments are i and s 
		int s1=strcmp(ar[2],"-b");
		int s2=strcmp(ar[3],"-b");
		int s3=strcmp(ar[2],"-n");
		int s4=strcmp(ar[3],"-n");
		if ((s1==0)&&(s4==0)){
			//printf("%s\n","Printing inode number and size");
			op1=1;
			op2=1;
		}else if ((s3==0)&&(s2==0)){
			//printf("%s\n","Printing inode number and size");
			op1=1;
			op2=1;
		}else if ((s1==0)||(s2==0)){
			//printf("%s\n","Printing inode number");
			op1=1;
			op2=0;
		}else if((s3==0)||(s4==0)){
			//printf("%s\n","Printing size");
			op1=0;
			op2=1;
		}
	}else{
		int t1=strcmp(ar[2],"-b");
		//int t2=strcmp(ar[1],"-I");
		int t3=strcmp(ar[2],"-n");
		//int t4=strcmp(ar[1],"-S");
		int t5=strcmp(ar[2],"-bn");
		//int t6=strcmp(ar[1],"-IS");
		//int t7=strcmp(ar[1],"-iS");
		//int t8=strcmp(ar[1],"-Is");
		int t9=strcmp(ar[2],"-nb");
		//int t10=strcmp(ar[1],"-SI");
		//int t11=strcmp(ar[1],"-Si");
		//int t12=strcmp(ar[1],"-sI");
		int s1=t1;
		int s2=t3;
		int s3=t5;
		int s4=t9;
		if (s1==0){
			//printf("%s\n","Printing inode number");
			op1=1;
			op2=0;
		}else if (s2==0){
			//printf("%s\n","Printing size");
			op1=0;
			op2=1;
		}else if ((s3==0)||(s4==0)){
			//printf("%s\n","Printing inode number and size");
			op1=1;
			op2=1;
		}else printf("%s\n","Invalid Option");
	}*/ 
}
int main(int argc,char**argv){
	//printf("%s",argv[0]);
	check_for_args(argc,argv);
	//printf("%d",f_count);
	//char buffer[MAX_LEN];
	//if (!getcwd(buffer,MAX_LEN)){
	//	printf("%s","Error in accessing current directory");
	//}
	//strcat(buffer,"/");
	//strcat(buffer,argv[1]);
	for (int i=0;i<f_count;i++){
	printf("\n");
	char buffer[MAX_LEN];
	strcpy(buffer,files[i]);
	FILE* stream=fopen(buffer,"r");
	if (stream==NULL){printf("Error in opening file\n");return 0;}
	char line_buffer[MAX_LEN];
	if ((op1==0)&&(op2==0)){
	while(fgets(line_buffer,MAX_LEN,stream)){
		printf("%s",line_buffer);
		}
	}else if ((op1==0)&&(op2==1)){
		int ct=1;
		while(fgets(line_buffer,MAX_LEN,stream)){
		int temp=strcmp("\n",line_buffer);
		if (temp!=0)printf("%d %s",ct,line_buffer);
		else printf("%s",line_buffer);
		ct++;
		}
	}else if ((op1==1)&&(op2==0)){
		int ct=1;
		while(fgets(line_buffer,MAX_LEN,stream)){
		printf("%d %s",ct,line_buffer);
		ct++;
		}
	}else{
		int ct=1;
		while(fgets(line_buffer,MAX_LEN,stream)){
		int temp=strcmp("\n",line_buffer);
		if (temp!=0)printf("%d %s",ct,line_buffer);
		else printf("%s",line_buffer);
		ct++;
		}
	}
}
}