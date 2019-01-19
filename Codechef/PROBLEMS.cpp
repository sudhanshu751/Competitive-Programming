#include<cstdio>
#include<cstdlib>
#define MAX_S 30
#define MAX_P 100000

struct difficulty{
	int Pnum, n;
};

void swap(int *SubTasks, int *Solvers, int i, int j){
	int temp = SubTasks[i];
	SubTasks[i]=SubTasks[j];
	SubTasks[j]=temp;
	temp=Solvers[i];
	Solvers[i]=Solvers[j];
	Solvers[j]=temp;
}
int partition(int *SubTasks,int *Solvers, int start, int end){
	int key = SubTasks[end];
	int i=start,pivot = start;
	for(;i<end;i++){
		if(SubTasks[i]<key){
			swap(SubTasks,Solvers,pivot,i);
			pivot++;
		}
	}
	swap(SubTasks,Solvers,pivot,end);
	return pivot;
}
void quicksort(int *SubTasks, int *Solvers,int start, int end){
	if(start>=end)
		return;
	int pivot = partition(SubTasks,Solvers,start,end);
	quicksort(SubTasks,Solvers,start,pivot-1);
	quicksort(SubTasks,Solvers,pivot+1,end);
}
int compare(const void *x, const void *y){
	struct difficulty a = (*(struct difficulty*)x);
	struct difficulty b = (*(struct difficulty*)y);
	if(a.n < b.n){
		return -1;
	}
	else if(a.n>b.n)
		return 1;
	else{
		if(a.Pnum<b.Pnum)
			return -1;
		else if(a.Pnum > b.Pnum)
			return 1;
		else return 0;
	}
}

int calcN(int *Solvers, int length){
	int n=0;
	if(length <2)
		return 0;
	for(int i=0;i<length-1;i++)
		if(Solvers[i]>Solvers[i+1])
			n++;
	return n;
}
int main(){
	struct difficulty diff[MAX_P];
	int SubTasks[MAX_S],Solvers[MAX_S];
	int num_problems,num_tasks;
	scanf("%d%d",&num_problems,&num_tasks);
	for(int i=0;i<num_problems;i++){
		diff[i].Pnum = i+1;
		for(int j=0;j<num_tasks;j++){
			scanf("%d",SubTasks+j);
		}
		for(int j=0;j<num_tasks;j++)
			scanf("%d",Solvers+j);
		quicksort(SubTasks,Solvers,0,num_tasks-1);
		diff[i].n = calcN(Solvers,num_tasks);
	}
	qsort(diff,num_problems,sizeof(struct difficulty),compare);
	for(int i=0;i<num_problems;i++)
		printf("%d\n",diff[i].Pnum);
	return 0;
}

