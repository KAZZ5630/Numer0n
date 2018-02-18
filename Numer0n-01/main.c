#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>


void target(int x,char *a);
void slash (char *a);
void highlow(char *a);


int main()
{
	char ans[5]={'\0'},b[5]={'\0'};
	int eat=0,bite=0;
	int h;
	int m=1;
	int i,j;
	int k[3];

	srand((unsigned)time(NULL));
	
	while(b[0]==b[1]||b[1]==b[2]||b[2]==b[0]){
		b[0]=rand()%10+48;
		b[1]=rand()%10+48;
		b[2]=rand()%10+48;
	}

	// 答え
	for(i=0;i<3;i++)
		printf("%d ",b[i]-48);

	printf("\n");
	printf("--------Numer0n--------\n");
	printf("target   :tg\n");
	printf("slash    :sl\n");
	printf("high&low :hl\n");
	printf("quit     :quit\n");
	printf("--------Numer0n--------\n");
	printf("3桁の数を発生させました。\n");

	do{
		while(1){
			printf("%d回目：数またはコマンドを入力---",m);	scanf("%s",ans);

			if(isdigit(ans[0])!=0 && isdigit(ans[1])!=0 && isdigit(ans[2])!=0)
				break;

			if(strcmp(ans,"tg")==0){
				printf("target!\n");
				printf("数字を一つ入力--");	scanf("%d",&h);
				target(h,b);
				printf("---------\n");
				m++;
				continue;
			}
			if(strcmp(ans,"sl")==0){
				printf("slash!\n");
				slash(b);
				printf("---------\n");
				m++;
				continue;
			}
			if(strcmp(ans,"hl")==0){
				printf("high&low!\n");
				highlow(b);
				printf("---------\n");
				m++;
				continue;
			}
			if(strcmp(ans,"quit")==0){
				printf("---------\n");
				printf("quitted!!\n");
				printf("正解:%c%c%c\n\n",b[0],b[1],b[2]);
				return 0;
			}
			else{
				printf("不正な入力です\n");
				printf("---------\n");
				continue;
			}					 
		}
		

		eat=0;
		bite=0;

		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(b[i]==ans[j]){
					if(i==j){
						eat+=1;
					}else{
						bite+=1;
					}
				}
			}
		}



		for(i=0;i<3;i++){
			if(b[i]==ans[i])
				k[i]=1;
			else
				k[i]=0;
		}
		/* printf("%d %d %d\n",k[0],k[1],k[2]); */
		printf("%dEAT-%dBITE",eat,bite);
		printf("\n-------------\n");
		m++;
	}while(eat!=3);

	printf("congraduations！！！（%d回目）\n",--m);

	return 0;
}


void target(int x,char *a){

	if(*a==x+48){
		printf("\n%d",x);
	}else{
		printf("\nx");
	}
	if(*(a+sizeof(char))==x+48){
		printf("%d",x);
	}else{
		printf("x");
	}
	if(*(a+2*sizeof(char))==x+48){
		printf("%d\n\n",x);
	}else{
		printf("x\n\n");
	}
}

void slash (char *a){
	int l,m,n,b;

	l=fabs((double)*a-*(a+sizeof(char)));
	m=fabs((double)*(a+sizeof(char))-*(a+2*sizeof(char)));
	n=fabs((double)*(a+2*sizeof(char))-*a);

	if(m<n){
		b=m;
		m=n;
		n=b;
	}
	if(l<m){
		b=l;
		l=m;
		m=b;
	}

	printf("%d\n",l);
}

void highlow(char *a){
	int i;

	for(i=0;i<3;i++){
		if(*(a+i*sizeof(char))<'5')
			printf("↓");
		else
			printf("↑");
	}
	printf("\n");
}
