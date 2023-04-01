#include<stdio.h>

int main(){
	double nc;
	printf("EOF is %d \n", EOF);
	for(nc=0; getchar()!=EOF; ++nc);
	printf("%.0f\n",nc);
	return 0;
}
