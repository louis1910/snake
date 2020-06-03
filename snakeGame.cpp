#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include "./console/console.cpp"
#include <string.h>
#include <conio.h>
#include <time.h>

#define consoleWidth 40
#define consoleHeight 25
#define MAXLENGTH 1000


enum State {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

struct Coordinates{
	int x;
	int y;
};

struct Bait{
	Coordinates position;
};

struct Snake{
	Coordinates dot[MAXLENGTH];
	int total_dot;
	State state;
};

void snake_init(Snake &snake, Bait &bait){
	
	snake.total_dot = 1;
	snake.dot[0].x = 0;
	snake.dot[0].y = 0;
	snake.state = RIGHT;
	
	bait.position.x = 10;
	bait.position.y = 10;
	
}

//void bait_appear(Bait &bait){
//	
//	srand(time(NULL));
//	int s = rand();
//	
//	bait.position.x = s%40;
//	bait.position.y = s%25;
//	
//}

//Bait bait_renew(int c, Bait bait){
//	switch(c){
//		case 0: break;
//		case 1: bait_appear(bait); break;
//		default: break;
//	}
//}

//void bait_presented(Bait bait){
//	clrscr;
//	gotoXY(bait.position.x, bait.position.y);
//	printf("x");
//}


void snake_presented(Snake snake, Bait &bait){
	clrscr;
	
	gotoXY(bait.position.x, bait.position.y);
	putchar('A');
	
	for(int i = 0; i < snake.total_dot; i++){
		gotoXY(snake.dot[i].x, snake.dot[i].y);
		putchar('*');
	}
	

}

void snake_behavior(Snake &snake){
	
	//truyen trang thai dot ke tiep
	for (int i = snake.total_dot - 1; i > 0 ; i--){
		snake.dot[i] = snake.dot[i-1];
	}
	
	
	//behavior
	if(kbhit()){
		char key = _getch();
		if(key == 'A' || key == 'a'){
			snake.state = LEFT;
		}
		else if(key == 'D' || key == 'd'){
			snake.state = RIGHT;
		}
		else if(key == 'W' || key == 'w'){
			snake.state = UP;
		}
		else if(key == 'S' || key == 's'){
			snake.state = DOWN;
		}
	}
	
	if(snake.state == DOWN)
		snake.dot[0].y++;
	else if(snake.state == UP)
		snake.dot[0].y--;
	else if(snake.state == LEFT)
		snake.dot[0].x--;	
	else if(snake.state == RIGHT)
		snake.dot[0].x++;
			
}

int compare_coordinates(Coordinates s1, Coordinates s2){
	if(s1.x == s2.x && s1.y == s2.y){
		return 1;
	}
	return 0;
}

void snake_eating(Snake &snake, Bait &bait){
	if(compare_coordinates(snake.dot[0], bait.position)){
		snake.total_dot++;
	}
}







int main(){

	Snake snake;
	Bait bait;
	
	snake_init(snake, bait);
	
	
	while(1){
		system("cls");
		
		
		snake_presented(snake, bait);
		
		snake_behavior(snake);
		
//		xu ly cham bien

		
		
//		xu ly trang thaii
				
		snake_eating(snake, bait);	
		
		
//		dieu khien

	
		
		Sleep(200);
		
	}
	return 0;
}
