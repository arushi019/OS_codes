#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#define MAX_LEN 100
static char *history[100];
static unsigned h_count=0;
static int cd_flag=0;
void read_num_line(){
	FILE *hist_file;
	hist_file=fopen("/home/arushi/Desktop/c_files/history.txt","r");
	if (hist_file==NULL)printf("Error in opening the file");
	else{
		for (char c=getc(hist_file);c!=EOF;c=getc(hist_file)){
			if (c=='\n')h_count++;
		}
	}
	fclose(hist_file);
}
void add_to_history(const char *cmd){
	FILE *hist_file;
	hist_file=fopen("/home/arushi/Desktop/c_files/history.txt","a");
	if (hist_file==NULL){
		fprintf(stderr, "Error opening the history file\n");
		exit(1);
	}
	fprintf(hist_file,"%s\n",cmd);
	//printf("%s added to file",cmd);
	fclose(hist_file);
	h_count++;
}
int main(void){
	printf("\t\t\t\t***********************************************************************\n");
	printf("\t\t\t\t\t\t\tULTRA SIMPLE SHELL\n");
	printf("\t\t\t\t***********************************************************************\n");
	read_num_line();
	while(1){
	printf("arushi>>");
	char cd_prev_path[MAX_LEN];
	char save_prev_path[MAX_LEN];
	char line_buffer[MAX_LEN];
	char *envp[]={NULL};
	//read_num_line();
	gets(line_buffer);
	add_to_history(line_buffer);
	int i=0;
	char *temp=strtok(line_buffer," ");
	char *arr[100];
	char *arg[100];
	while(temp!=NULL){
		arg[i]=temp;
		arr[i++]=temp;
		temp=strtok(NULL," ");
	}
	int num=i;
	arg[i]=NULL;
	int t1=strcmp("cd",arr[0]);
	int t2=strcmp("echo",arr[0]);
	int t3=strcmp("history",arr[0]);
	int t4=strcmp("pwd",arr[0]);
	int t5=strcmp("exit",arr[0]);
	int t6=strcmp("ls",arr[0]);
	int t7=strcmp("cat",arr[0]);
	int t8=strcmp("date",arr[0]);
	int t9=strcmp("rm",arr[0]);
	int t10=strcmp("mkdir",arr[0]);
	getcwd(cd_prev_path,MAX_LEN);
	if (t1==0){
		int n_temp=strcmp("~",arr[1]);
		int n_temp2=strcmp("-",arr[1]);
		getcwd(cd_prev_path,MAX_LEN);
		history[cd_flag]=cd_prev_path;
		//printf("%s", history[cd_flag]);
		cd_flag++;
		//printf("%d %d\n",n_temp2,cd_flag);
		if (n_temp==0){
			DIR *d=opendir("/home/arushi/");
			if (d){
				chdir("/home/arushi/");
			}else printf("directory not found\n");
		}else if ((n_temp2==0)&&(cd_flag>0)){
			const char* st=history[cd_flag-2];
			printf("%s",history[cd_flag-2]);
			DIR *d=opendir(st);
			if (d)chdir(st);
			else printf("directory not found\n");
		}else if ((n_temp2==0)&&(cd_flag==0)){
			printf("Error: no last location saved\n");
		}
		else{
			//getcwd(cd_prev_path,MAX_LEN);
			DIR *d=opendir(arr[1]);
			if (d){
				chdir(arr[1]);
			}else printf("directory not found\n");
		}
		//cd_flag=cd_flag+1;
		//getcwd(cd_prev_path,MAX_LEN);
	}else if (t2==0){
		int t11=strcmp("-n",arr[1])*strcmp("-n",arr[2]);
		int t12=strcmp("-E",arr[1])*strcmp("-E",arr[2]);
		for (int j=1;j<num;j++){
			if ((t11!=0)&&(j!=num-1)&&(t12!=0)){
				char *a;
			a=arr[j];
			for (int i=0;i<strlen(arr[j]);i++){
				if ((*a!='\\')&&(*a!='\''))printf("%c",*a);
				a++;
			}
				//printf("%s ",arr[j]);
			}
			if ((j==num-1)&&(t11!=0)&&(t12!=0)){
				char *a;
			a=arr[j];
			for (int i=0;i<strlen(arr[j]);i++){
				if ((*a!='\\')&&(*a!='\''))printf("%c",*a);
				a++;
			}
				//printf("%s ",arr[j]);
				printf("\n");
			}
			else if ((j==num-1)&&(t11==0)&&(t12!=0)){
				char *a;
			a=arr[j];
			for (int i=0;i<strlen(arr[j]);i++){
				if ((*a!='\\')&&(*a!='\''))printf("%c",*a);
				a++;
			}
				//printf("%s ",arr[j]);
			}
		}
	}else if (t3==0){
		FILE *hist_file;
		hist_file=fopen("/home/arushi/Desktop/c_files/history.txt","r");
		for (int j=0;j<h_count;j++){
			char cmd[100];
			fgets(cmd,100,hist_file);
			//printf("%s",cmd);
			printf("\t%d % s",j,cmd);
		}
		fclose(hist_file);
	}else if (t4==0){
		char buffer[MAX_LEN];
		if (!getcwd(buffer,MAX_LEN)){
			printf("Error in accessing current directory\n");
		}else printf("%s\n",buffer);
	}else if (t5==0){
		return 1;
		
	}else if ((t6==0)||(t7==0)||(t8==0)||(t9==0)||(t10==0)){
		int cpid=fork();
		if (cpid==0){
			for (int i=0;i<num;i++)printf("%s",arg[i]);
			if (t6==0)execve("/home/arushi/Desktop/c_files/ls",arg,NULL);
			else if (t7==0)execve("/home/arushi/Desktop/c_files/cat",arg,NULL);
			else if (t8==0)execve("/home/arushi/Desktop/c_files/date",arg,NULL);
			else if (t9==0)execve("/home/arushi/Desktop/c_files/rm",arg,NULL);
			else if (t10==0)execve("/home/arushi/Desktop/c_files/mkdir",arg,NULL);
		}
		else{
			wait(NULL);
		}
	}else printf("Not a valid command\n");

}
}