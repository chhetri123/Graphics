#include<graphics.h>
#include<math.h>
#include<conio.h>
#include <dos.h>
#include<iostream>
#include<iomanip>
using namespace std;
void calculation(int x1,int y1,int x2,int  y2 );
void display(int k,int x1,int x2);
void takeData();
void calculation(int x1,int y1,int x2 ,int y2  ){
	int dx=x2-x1;
	int dy=y2-y1;

//	slope checking 
if(abs(dx)<= abs(dy)){ //slope is less than equal to  1
	int temp=dy;
	dy=dx;
	dx=temp;
	
}
int p1=2*dy;
int p2=p1-2*dx;
int p=p1-dx;
for(int k=0;k<dx;k++){
	
	
	if(p<0){
			display(k+1,x1++,y1);
			p=p+p1;
	}else{
			display(k+1,x1++,y1++);
			p=p+p2;
	}

}
	
	
	
}
void takeData(){
	int x1,y1, x2,y2 ;
	cout<<"Enter the Coordinates to draw Line :"<<endl;
	cout <<"Enter( x1, y1): ";
	cin>>x1>> y1;
	cout <<endl<<"Enter (x2,y2): ";
	cin >>x2>>y2;
cout<<"-------------------------------------"<<endl;
cout << left << setw(20)<< "No. of Steps" << "Point" << endl;
cout<<"-------------------------------------"<<endl;
	calculation(x1,y1,x2,y2);
	
			
};
void display(int k,int x1,int y1){
	delay(50);
	putpixel(x1,y1,RED);
cout <<setw(5) << "|"<<setw(10) << k << "|  ("<<x1 << ","<<y1  << ")  |" << endl;
    
};
int main(){
int gd=DETECT ,gm,i;
initgraph(&gd,&gm,"chhetri");

	takeData();		
getch();
closegraph();
return 0;

}
