#include<cstdio>
int NumTriangles(int n){
	int x1,x2,x3,y1,y2,y3;
	int a,b,c;
	int num_triangles=0;
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
		a=(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ;
		b=(x1-x3)*(x1-x3) + (y1-y3)*(y1-y3) ;
		c=(x3-x2)*(x3-x2) + (y3-y2)*(y3-y2) ;
		if(a==b+c || b==a+c || c==a+b)
			num_triangles++;
	}
	return num_triangles ;
}

int main(){
	int n ;
	scanf("%d",&n);
	printf("%d\n",NumTriangles(n));
	return 0;
}
