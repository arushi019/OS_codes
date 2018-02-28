#include<dirent.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#define MAX_LEN 100
int op1;
int op2;
void check_for_args(int ct,char **ar){
	if (ct==5){
		//check if options entered are valid
		op1=1;
		op2=1;
	}else if (ct==4){
		//check if options entered are valid
		op1=0;
		op2=1;
	}else if (ct==3){
		//check if options entered are valid
		op1=1;
		op2=0;
	}else{
		op1=0;
		op2=0;
	}
}
int main(int argc,char**argv){
	check_for_args(argc,argv);
	printf("%d%d",op1,op2);
	int val;
	char buffer[MAX_LEN];
	if (!getcwd(buffer,MAX_LEN)){
		printf("%s","Error in accessing current directory");
	}
	strcat(buffer,"/");
	strcat(buffer,argv[1]);
	//printf("%s",buffer);
	if ((op1==0)&&(op2==0)){
		val=mkdir(buffer,S_IRWXU|S_IRWXG|S_IRWXO);
		if (val==-1)printf("%s\n","Error in creating directory");	
	}else if ((op1==1)&&(op2==0)){
		val=mkdir(buffer,S_IRWXU|S_IRWXG|S_IRWXO);
		if (val==-1)printf("%s\n","Error in creating directory");
		else printf("mkdir: created directory '%s'\n",argv[1]);	
	}else if ((op1==1)&&(op2==1)){
		int temp=strcmp("-v",argv[2]);
		if (temp==0){
			//-v -m value
			int chmod_value=atoi(argv[4]);
			mode_t chm=umask((mode_t)0);
			//umask(chm);
			int user=chmod_value/100;
			int grp=(chmod_value/10)%10;
			int oth=chmod_value%10;
			if (user==7)chm=chm|S_IRWXU;
			if (user==6)chm=chm|S_IRUSR|S_IWUSR;
			if (user==5)chm=chm|S_IRUSR|S_IXUSR;
			if (user==4)chm=chm|S_IRUSR;
			if (user==3)chm=chm|S_IWUSR|S_IXUSR;
			if (user==2)chm=chm|S_IWUSR;
			if (user==1)chm=chm|S_IXUSR;
			if (grp==7)chm=chm|S_IRWXG;
			if (grp==6)chm=chm|S_IRGRP|S_IWGRP;
			if (grp==5)chm=chm|S_IRGRP|S_IXGRP;
			if (grp==4)chm=chm|S_IRGRP;
			if (grp==3)chm=chm|S_IWGRP|S_IXGRP;
			if (grp==2)chm=chm|S_IWGRP;
			if (grp==1)chm=chm|S_IXGRP;
			if (oth==7)chm=chm|S_IRWXO;
			if (oth==6)chm=chm|S_IROTH|S_IWOTH;
			if (oth==5)chm=chm|S_IROTH|S_IXOTH;
			if (oth==4)chm=chm|S_IROTH;
			if (oth==3)chm=chm|S_IWOTH|S_IXOTH;
			if (oth==2)chm=chm|S_IWOTH;
			if (oth==1)chm=chm|S_IXOTH;
			printf("%4o\n%d\n",chm,chmod_value);
			val=mkdir(buffer,chm);
			if (val==-1)printf("%s\n","Error in creating directory");
			else printf("mkdir: created directory '%s'\n",argv[1]);
		}else{
			int chmod_value=atoi(argv[3]);
			mode_t chm=umask((mode_t)0);
			//umask(chm);
			int user=chmod_value/100;
			int grp=(chmod_value/10)%10;
			int oth=chmod_value%10;
			if (user==7)chm=chm|S_IRWXU;
			if (user==6)chm=chm|S_IRUSR|S_IWUSR;
			if (user==5)chm=chm|S_IRUSR|S_IXUSR;
			if (user==4)chm=chm|S_IRUSR;
			if (user==3)chm=chm|S_IWUSR|S_IXUSR;
			if (user==2)chm=chm|S_IWUSR;
			if (user==1)chm=chm|S_IXUSR;
			if (grp==7)chm=chm|S_IRWXG;
			if (grp==6)chm=chm|S_IRGRP|S_IWGRP;
			if (grp==5)chm=chm|S_IRGRP|S_IXGRP;
			if (grp==4)chm=chm|S_IRGRP;
			if (grp==3)chm=chm|S_IWGRP|S_IXGRP;
			if (grp==2)chm=chm|S_IWGRP;
			if (grp==1)chm=chm|S_IXGRP;
			if (oth==7)chm=chm|S_IRWXO;
			if (oth==6)chm=chm|S_IROTH|S_IWOTH;
			if (oth==5)chm=chm|S_IROTH|S_IXOTH;
			if (oth==4)chm=chm|S_IROTH;
			if (oth==3)chm=chm|S_IWOTH|S_IXOTH;
			if (oth==2)chm=chm|S_IWOTH;
			if (oth==1)chm=chm|S_IXOTH;
			printf("%4o\n%d\n",chm,chmod_value);
			val=mkdir(buffer,chm);
			if (val==-1)printf("%s\n","Error in creating directory");
			else printf("mkdir: created directory '%s'\n",argv[1]);
		}
	}else{
		int chmod_value=atoi(argv[3]);
		mode_t chm=umask((mode_t)0);
			//umask(chm);
		int user=chmod_value/100;
			int grp=(chmod_value/10)%10;
			int oth=chmod_value%10;
			if (user==7)chm=chm|S_IRWXU;
			if (user==6)chm=chm|S_IRUSR|S_IWUSR;
			if (user==5)chm=chm|S_IRUSR|S_IXUSR;
			if (user==4)chm=chm|S_IRUSR;
			if (user==3)chm=chm|S_IWUSR|S_IXUSR;
			if (user==2)chm=chm|S_IWUSR;
			if (user==1)chm=chm|S_IXUSR;
			if (grp==7)chm=chm|S_IRWXG;
			if (grp==6)chm=chm|S_IRGRP|S_IWGRP;
			if (grp==5)chm=chm|S_IRGRP|S_IXGRP;
			if (grp==4)chm=chm|S_IRGRP;
			if (grp==3)chm=chm|S_IWGRP|S_IXGRP;
			if (grp==2)chm=chm|S_IWGRP;
			if (grp==1)chm=chm|S_IXGRP;
			if (oth==7)chm=chm|S_IRWXO;
			if (oth==6)chm=chm|S_IROTH|S_IWOTH;
			if (oth==5)chm=chm|S_IROTH|S_IXOTH;
			if (oth==4)chm=chm|S_IROTH;
			if (oth==3)chm=chm|S_IWOTH|S_IXOTH;
			if (oth==2)chm=chm|S_IWOTH;
			if (oth==1)chm=chm|S_IXOTH;
			printf("%4o\n%d\n",chm,chmod_value);
			val=mkdir(buffer,chm);
			if (val==-1)printf("%s\n","Error in creating directory");
	}
}