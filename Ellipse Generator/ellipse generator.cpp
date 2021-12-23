#include<iostream>
#include<math.h>
#include<graphics.h>
#include<conio.h>
#include<iomanip>
#include<dos.h>
using namespace std;
static int  i=1;

void display(int xc,int yc,int x,int y,int a,int b,int p){
	delay(30);
	putpixel(x+xc,y+yc,RED);
	putpixel(xc-x,yc+y,YELLOW);
	putpixel(xc+x,yc-y,BLUE);
	putpixel(xc-x,yc-y,GREEN);
	
	cout <<setw(5) << "|"<<setw(10) <<i++ << "|    "  <<setw(8)<<p<<setw(3)<<" | " << setw(8)<<a<< setw(3)<<" |   "<<setw(8)<< b<<setw(4)<<"| "<< "("<<xc+x << ","<<yc+y << ")  |" << endl;
}
void drawEllipse(int xc,int yc,int a,int b){
	int x=0,y=b,p;
	int rx=pow(a,2);
	int ry=pow(b,2);
	int p1=round(ry-rx *b+rx*0.25);
	display(xc,yc,x,y,2*ry*x,2*rx*y,p1);

	while(2*ry*x<=2*rx*y){
		x++;
		p=2*ry*x+ry;
		if(p1<0){
			p1+=p;
		}else{
			y--;
			p1+=p-2*rx*y;
			
		}
		display(xc,yc,x,y,2*ry*x,2*rx*y,p1);
		
	}
	
//	for region 2

cout<<"Region 2"<<endl;
int p2=round(pow((x+0.5),2)*ry+rx*pow((y-1),2)-rx*ry);

while(y!=0){
	y--;
	if(p2>0){
		p2+=rx-2*rx*y;
		
	}else{
		x++;
		p2+=rx-2*rx*y+2*ry*x;
		
	}
	display(xc,yc,x,y,2*ry*x,2*rx*y,p2);
}


}
void takedata(){
		int xc,yc,rx,ry;
		cout<<"Enter the centre of ellipse: ";
		cin>>xc>>yc;
		cout<<"Enter the length of  major axis (a) and minor axis (b)  of ellipse: ";
		cin>> rx>>ry;
	cout<<"****************************"<<endl;
	cout<<"-----------------------------------------------------------------------------"<<endl;
cout << left << setw(20)<< "No. of Steps" <<setw(10)<<"pk"<<setw(10)<<"2ry^2x1"<<setw(11)<<"2rx^2y1"<<setw(10)<< "Points of Ellipse (x1,y1)" << endl;
cout<<"----------------------------------------------------------------------------------"<<endl;
drawEllipse(xc,yc,rx,ry);				
}
int main(){
	int gd=DETECT,gm,i;
	initgraph(&gd,&gm,"chhetri");
	takedata();
	getch(); 
	closegraph();
	return 0;
	
}
