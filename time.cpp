#include <stdio.h>
#include <time.h>
#include <Windows.h>

struct Coordinates{
	int x;
	int y;
};

struct Bait{
	Coordinates position;
};

void bait_appear(Bait &bait){
	srand(time(NULL));
	int s = rand();
	printf("x:%d --- y:%d", s%40, s%25);
}
void bait_renew(Bait bait){
	bait_appear(bait);
}

int main(){
	Bait bait;
	bait_appear(bait);

	int c;
	scanf("%d", &c);
	
	switch(c){
		case 1: bait_appear(bait); break;
		case 2: bait_appear(bait); break;
		default: break;
	}
}
