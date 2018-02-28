#include<dirent.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 100
int op1;
int op2;
void check_for_args(int ct,char **ar){
	if (ct==1){
		op1=0;
		op2=0;
	}else if (ct==3){
		//check if arguments are i and s 
		int s1=strcmp(ar[1],"-i");
		int s2=strcmp(ar[2],"-i");
		int s3=strcmp(ar[1],"-s");
		int s4=strcmp(ar[2],"-s");
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
		int t1=strcmp(ar[1],"-i");
		//int t2=strcmp(ar[1],"-I");
		int t3=strcmp(ar[1],"-s");
		//int t4=strcmp(ar[1],"-S");
		int t5=strcmp(ar[1],"-is");
		//int t6=strcmp(ar[1],"-IS");
		//int t7=strcmp(ar[1],"-iS");
		//int t8=strcmp(ar[1],"-Is");
		int t9=strcmp(ar[1],"-si");
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
		}else{
			char *a;
			a=ar[1];
			for (int i=0;i<strlen(ar[1]);i++){
				if (*a=='i')op1=1;
				if (*a=='s')op2=1;
				a++;
			}
			if ((op1==0)&&(op2==0))printf("%s\n","Invalid Option");
		}
	} 
}
int main(int argc,char**argv){
	check_for_args(argc,argv);
	DIR *d;
	char buffer[MAX_LEN];
	if (!getcwd(buffer,MAX_LEN)){
		printf("%s","Error in accessing current directory");
	}
	d=opendir(buffer);
	if (d==NULL)printf("%s","Operation Unsuccessful");
	else{
		struct dirent *temp=readdir(d);
		while(temp!=NULL){
			//printf("%20s ",temp->d_name);
			//printf("%10lu",temp->d_ino);
			//printf("%5d\n",temp->d_reclen-20);
			int s1=strcmp(".",temp->d_name);
			int s2=strcmp("..",temp->d_name);
			if ((s1!=0)&&(s2!=0)){
			if ((op1==1)&&(op2==1))printf("%20s%10lu%5d\n",temp->d_name,temp->d_ino,temp->d_reclen-20);
			else if ((op1==1)&&(op2==0))printf("%20s%10lu\n",temp->d_name,temp->d_ino);
			else if ((op1==0)&&(op2==1))printf("%20s%5d\n",temp->d_name,temp->d_reclen-20);
			else printf("%20s\n",temp->d_name);}
			temp=readdir(d);
		}
	}
}