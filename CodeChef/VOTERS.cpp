#include<cstdio>
#define MAX 50000
void AddToVoterList(int *ans, int *ans_length, int x, int *ptr1, int *ptr2){
	ans[*ans_length] = x;
	(*ans_length)++;
	(*ptr1)++;
	(*ptr2)++;
}
void SetUpVoterList(int *l1, int n1, int *l2, int n2, int *l3, int n3, int *ans, int *ans_length){
	int i,j,k;
	i=j=k=0;
	while(i<n1 && j<n2 && k<n3){
		if(l1[i]==l2[j])
			AddToVoterList(ans, ans_length, l1[i], &i, &j);
		else if(l1[i]==l3[k])
			AddToVoterList(ans, ans_length, l1[i], &i, &k);
		else if(l2[j]==l3[k])
			AddToVoterList(ans, ans_length, l2[j], &j, &k);
		else if(l1[i]<l2[j] && l1[i]<l3[k])
		       ++i;	
		else if(l2[j]<l1[i] && l2[j]<l3[k])
		       ++j;
		else 
			++k;	
	}
	while(i<n1 && j<n2){
		if(l1[i]==l2[j])
			AddToVoterList(ans, ans_length, l1[i], &i, &j);
		else 
			l1[i]<l2[j] ? ++i : ++j ;
	}
	while(i<n1 && k<n3){
		if(l1[i]==l3[k])
			AddToVoterList(ans, ans_length, l1[i], &i, &k);
		else 
			l1[i]<l3[k] ? ++i : ++k ;
	}
	while(k<n3 && j<n2){
		if(l3[k]==l2[j])
			AddToVoterList(ans, ans_length, l3[k], &k, &j);
		else 
			l3[k]<l2[j] ? ++k : ++j ;
	}
}

int main(){
	int l1[MAX],l2[MAX],l3[MAX],ans[MAX],n1,n2,n3,ans_length=0;
	scanf("%d%d%d",&n1,&n2,&n3);
	for(int i=0;i<n1;i++)
		scanf("%d",l1+i);
	for(int i=0;i<n2;i++)
		scanf("%d",l2+i);
	for(int i=0;i<n3;i++)
		scanf("%d",l3+i);
	SetUpVoterList(l1,n1,l2,n2,l3,n3,ans,&ans_length);
	printf("%d\n",ans_length);
	for(int i=0;i<ans_length;i++)
		printf("%d\n",*(ans+i));
	return 0;
}
