#include<graphics.h>
#include<math.h>
#include<conio.h>
#include <dos.h>
#include<iostream>
#include<iomanip>
using namespace std;
void cone();
void circlePoint(int a,int b,int r);
void circlePlot(int a,int b,int x ,int y,int k);
void takeData();
void display(int a,int b);
static int i=0;


int main(){
int gd=DETECT ,gm,i;
	initgraph(&gd,&gm,"manosh");
	takeData();
getch();
closegraph();
return 0;
	
}
void takeData(){
	int a,b,r;
	cout<<"Enter the center and radius  to draw circle :"<<endl;
	cout <<"Enter center ( a, b): ";
	cin>>a>> b;
	cout <<endl<<"Enter radius (r): ";
	cin >>r;
cout<<"-------------------------------------"<<endl;
cout << left << setw(20)<< "No. of Steps" << "Points of circle " << endl;
cout<<"-------------------------------------"<<endl;
	circlePoint(a,b,r);
				
};

void cone(){
	for(int i;i<100;i++){
		circlePoint(200+i,200+i,i);
	}
}
void circlePoint(int a,int b,int r){
	int x=0;
	int y=r;
	float  p=1-r;
	circlePlot(a,b,x,y,1);
	while(x <=y){
			x++;
		if(p<0){
		p+=2*x+ 1;
	
		
	}else{
	    y--;
		p+=2*(x-y)+1;
	
	}
	delay(30);	
	circlePlot(a,b,x,y,1);
	
	}
	
}
void display(int a,int b){
	cout <<setw(5) << "|"<<setw(15) <<i++ << "|  ("<<a << ","<<b << ")  |" << endl;
}
void circlePlot(int a,int b,int x ,int y,int k){

	putpixel(a+x,b+y,GREEN);
	putpixel(a-x,b+y,RED);
	putpixel(a+x,b-y,YELLOW);
	putpixel(a-x,b-y,WHITE);
	display(a+x,b+y);
	display(a-x,b+y);
	display(a+x,b-y);
	display(a-x,b-y);
	if(k==1){
	circlePlot(a,b,y,x,0);
	}
	

	
}



















