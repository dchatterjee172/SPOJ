#include "stdio.h"//                                       1011111011111101
int getResult(char *arr,int count){
	int mem[256],add,count1;
	mem[0]=arr[0]-'0';
	for(int i=1;i<count;i++){
		mem[i]=mem[i-1];
		count1=0;
		for(int j=i;j>=0;j--){
			count1+=((arr[j]=='1')?1:-1);
			if(count1>0){
				add=i-j+1;
				if(j>0)	add+=mem[j-1];
				if(mem[i]<add)	mem[i]=add;
			}
		}
		printf("%d\n",mem[i]);
	}
	return mem[count-1];
}
int main(){
	int cases,num;
	char arr1[256];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&num);
		scanf("%s",arr1);
		printf("%d\n",getResult(arr1,num));
	}
	return 0;
}
