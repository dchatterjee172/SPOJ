#include "iostream"
#include "queue"
using namespace std;
bool mem[10000],visit[10000];
void prime(){
	for(int i=2;i<10000;i++) mem[i]=true;
	for(int i=2;i<=100;i++){
		if(mem[i]==true){
			for(int j=i*i;j<=10000;j+=i)
				mem[j]=false;
		}
	}
}
typedef struct{
	int num,cost;
}Num;
Num newNum(int num,int cost){
	Num temp;
	temp.num=num;
	temp.cost=cost;
	return temp;
}
int getResult(int start,int end){
	int result=-1,arr[4],temp;
	queue<Num> q;
	q.push(newNum(start,0));
	visit[start]=true;
	Num *current;
	while(!q.empty()){
		current=&(q.front());
		//cout<<current->num<<endl;
		q.pop();
		if(current->num==end){
			result=current->cost;
			return result;
		}
		arr[0]=current->num%10;
		arr[1]=(current->num%100)/10;
		arr[2]=(current->num%1000)/100;
		arr[3]=current->num/1000;
		for(int i=0;i<4;i++){
			if(i==1)	arr[0]=current->num%10;
			else if(i==2)	arr[1]=(current->num%100)/10;
			else if(i==3)	arr[2]=(current->num%1000)/100;
			for(int j=0;j<10;j++){
				if((i==0||i==3)&&j==0)	continue;
				arr[i]=j;
				temp=1000*arr[3]+100*arr[2]+10*arr[1]+arr[0];
				if(mem[temp]&&!visit[temp]){
					q.push(newNum(temp,current->cost+1));
					//cout<<temp<<endl;
					visit[temp]=true;
				}
			}
		}
	}
	return result;
}
int main(){
	prime();
	int test,start,end,result;
	cin>>test;
	while(test--){
		for(int i=1000;i<9999;i++)	visit[i]=false;
		cin>>start>>end;
		result=getResult(start,end);
		if(result>-1){
			cout<<result<<endl;
		}
		else cout<<"Impossible"<<endl; 
	}
	return 0;
}
