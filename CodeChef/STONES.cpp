#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 101

int CharacterIntersection(char *mine_stones, char *jewels){
	if(strlen(mine_stones)==1 && strlen(jewels)==1)
		return *mine_stones==*jewels ? 1 : 0 ;
	int common=0;
	std::sort(mine_stones, mine_stones+strlen(mine_stones));
	std::sort(jewels, jewels +strlen(jewels));

	while(*mine_stones){
		if(std::binary_search(jewels, jewels+strlen(jewels),*mine_stones))
			common++;
		mine_stones++;
	}
	return common ;
}

int main(){
	int num_tests;
	char mine_stones[MAX], jewels[MAX];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%s%s",jewels,mine_stones);
		printf("%d\n",CharacterIntersection(mine_stones,jewels));
	}
	return 0;
}
