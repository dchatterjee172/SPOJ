#include "stdio.h"
int mem[100][100],arr[100][100];
int best(int h,int w,int maxh,int maxw){
	if(w>=maxw)	w=maxw-1;
	else if(w<0)	w=0;
	if(mem[h][w]>-1)    return mem[h][w];
	if(h==maxh-1){
		mem[maxh-1][w]=arr[maxh-1][w];
		return arr[maxh-1][w];
	}	
	int step0=best(h+1,w-1,maxh,maxw),step1=best(h+1,w,maxh,maxw),step2=best(h+1,w+1,maxh,maxw);
	if(step0>step1&&step0>step2){
		mem[h][w]=step0+arr[h][w];
		return mem[h][w];
	}
	else if(step1>step2){
		mem[h][w]=step1+arr[h][w];
		return mem[h][w];
	}
	else{
		mem[h][w]=step2+arr[h][w];
		return mem[h][w];
	}
	
}
int getResult(int h,int w){
	int mem1[w];
	for(int i=0;i<h;i++) for(int j=0;j<w;j++) mem[i][j]=-1;
	for(int i=0;i<w;i++){
		mem1[i]=best(0,i,h,w);
		//printf("%d\n",mem1[i]);
	}
	int max=mem1[0];
	for(int i=1;i<w;i++){
		if(max<mem1[i])	max=mem1[i];
	}
	return max;
}
int main(){
	int test,h,w;
	scanf("%d",&test);
	while(test--){
		scanf("%d %d",&h,&w);
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++)
				scanf("%d",&arr[i][j]);
		}
		printf("%d\n",getResult(h,w));
	}
}
