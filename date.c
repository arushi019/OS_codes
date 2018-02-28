#include<dirent.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX_LEN 100
int op1;
int op2;
void check_for_args(int ct,char **ar){
	if (ct==1){
		op1=0;
		op2=0;
	}else if (ct==3){
		//check if arguments are i and s 
		int s1=strcmp(ar[1],"-R");
		int s2=strcmp(ar[2],"-R");
		int s3=strcmp(ar[1],"-u");
		int s4=strcmp(ar[2],"-u");
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
		int t1=strcmp(ar[1],"-R");
		//int t2=strcmp(ar[1],"-I");
		int t3=strcmp(ar[1],"-u");
		//int t4=strcmp(ar[1],"-S");
		int t5=strcmp(ar[1],"-Ru");
		//int t6=strcmp(ar[1],"-IS");
		//int t7=strcmp(ar[1],"-iS");
		//int t8=strcmp(ar[1],"-Is");
		int t9=strcmp(ar[1],"-uR");
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
				if (*a=='R')op1=1;
				if (*a=='u')op2=1;
				a++;
			}
			if ((op1==0)&&(op2==0))printf("%s\n","Invalid Option");
		}
	} 
}
int main(int argc,char**argv){
	check_for_args(argc,argv);
	time_t t1=time(NULL);
	struct tm t2=*localtime(&t1);
	if (t1==NULL){printf("Error in getting time\n");return 0;}
	if (op2==1){
		time(&t1);
		t2=*gmtime(&t1);
		if (t1==NULL){printf("Error in getting time\n");return 0;}
	}
	int yr=t2.tm_year+1900;
	int month=t2.tm_mon+1;
	char *str_month;
	if (month==1)str_month="Jan";
	if (month==2)str_month="Feb";
	if (month==3)str_month="Mar";
	if (month==4)str_month="Apr";
	if (month==5)str_month="May";
	if (month==6)str_month="Jun";
	if (month==7)str_month="Jul";
	if (month==8)str_month="Aug";
	if (month==9)str_month="Sep";
	if (month==10)str_month="Oct";
	if (month==11)str_month="Nov";
	if (month==12)str_month="Dec";
	int date=t2.tm_mday;
	int day=t2.tm_wday;
	char *str_day;
	if (day==0)str_day="Sun";
	if (day==1)str_day="Mon";
	if (day==2)str_day="Tue";
	if (day==3)str_day="Wed";
	if (day==4)str_day="Thu";
	if (day==5)str_day="Fri";
	if (day==6)str_day="Sat";
	int hr=t2.tm_hour;
	int min=t2.tm_min;
	int sec=t2.tm_sec;
	if ((op1==0)&&(op2==0))printf("%s %s %d %d:%d:%d IST %d\n",str_day,str_month,date,hr,min,sec,yr);
	else if ((op1==1)&&(op2==0))printf("%s , %d %s %d %d:%d:%d +0530\n",str_day,date,str_month,yr,hr,min,sec);
	else if ((op1==0)&&(op2==1))printf("%s %s %d %d:%d:%d UTC %d\n",str_day,str_month,date,hr,min,sec,yr);
	else printf("%s , %d %s %d %d:%d:%d \n",str_day,date,str_month,yr,hr,min,sec);
}