#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include "./console/console.h"
#include <string.h>



struct move{
	char s[10];
	int x;
	int y;
}move;

int main(){
	

	move A;
	
	strcpy(A.s, "*");
	
	A.x = 0;
	A.y = 0;
	
	while(1){
		system("cls");
		
		gotoXY(1,2);
		
		printf("%s", A.s);
		
		A.x++;
		A.y++;
		
		Sleep(400);
		
	}
	return 0;
}
