#include <stdio.h>
#include <stdlib.h>

//run this program using the console pauser ot add your own getch , system("pause")
//how to pass and return a struct to a function 

typedef struct Point{
	double x,y;
}Point;

Point getMiddlePoint(Point a,Point b){

	Point m;
	m.x = (a.x +b.x)/2;
	m.y = (a.y+ b.y)/2;
	return m;

}

int main(){

	Point p1={
		.x =1,
		.y =1
	};

	Point p2={
		.x =3,
		.y =2
	};

	Point middle;
	middle =getMiddlePoint(p1,p2);
	printf("%lf , %lf\n", middle.x,middle.y);
	return 0;

}