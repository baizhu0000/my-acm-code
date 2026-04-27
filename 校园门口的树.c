#include <stdio.h>
#include <stdbool.h>

int main()
{
	
	int l,m;
	scanf("%d %d", &l, &m);
	int i;
	
	bool trees[l+1];
	for( i=0;i<l+1;i++ ){
		trees[i] = true;
	}

	for( i=0;i<m;i++ ){
		int u,v;
		scanf("%d %d", &u, &v);
		int j;
		for( j=u;j<=v;j++){
			trees[j]=false;
    	}
    }

    int sum=0;
    for( i=0;i<=l;i++ ){
        if(trees[i]){
            sum++;
        }
    }

	printf("%d",sum);
	
	return 0;
}