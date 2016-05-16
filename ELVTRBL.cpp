#include "iostream"
#include "queue"
using namespace std;
typedef struct{
	int flr,step;
}Floor;

Floor newStep(int flr,int stp){
	Floor temp;
	temp.flr=flr;
	temp.step=stp;
	return temp;
}

bool visit[1000005];

int main(){
	int f,s,g,u,d,stepfinal=-1;
	
	cin>>f>>s>>g>>u>>d;
	queue<Floor> q;
	q.push(newStep(s,0));
	visit[s]=true;
	Floor *now;
	while(!q.empty()){
		now=&(q.front());
		q.pop();
		if(now->flr==g){
			stepfinal=now->step;
			break;
		}
		if(now->flr+u<=f && !visit[now->flr+u]){
			q.push(newStep(now->flr+u,now->step+1));
			visit[now->flr+u]=true;
		}
		if(now->flr-d>=0 && !visit[now->flr-d]){
			q.push(newStep(now->flr-d,now->step+1));
			visit[now->flr-d]=true;
		}
	}
	if(stepfinal==-1)	cout<<"use the stairs\n";
	else	cout<<stepfinal<<endl;
	return 0;
}	


        
