#include <iostream>
#include <graphics.h>
#include <cmath>
#include <string.h>
#include "Transformation.h"
#define SIZE 100
using namespace std;
class Transformation{

	public:
	int a;
	float x[SIZE];
	float y[SIZE];
	float angle;
	int ch;
	float sk[2];
	float tk[2];
	float ref[2]={0,0};
	float sh[2]={0,0};
		Transformation(){
			cout<<"Enter No of dimension: ";
		 cin>>a;
		}
	void takeData(){
		cout<<"Enter the points (x,y) :"<<endl;
	for(int i=0;i<a;i++){
		cout<<"Enter the point (x"<<i+1<<" y"<<i+1<<") ";
		cin>>x[i]>>y[i];
	}
}
	void takeDataForScaling(){
		cout<<"Enter the scalling factor (sx,sy) ";
		cin>>sk[0]>>sk[1];
	}
	void takeDataForTranslation(){
		cout<<"Enter the translation factor (tx,ty) ";
		cin>>tk[0]>>tk[1];
	}
	void takeDataForRotation(){
		cout<<"Enter the angle of rotation";
		cin>>angle;
	}
	void takeDataForShear(){
		
		do{
		cout<<"Enter in which axis Shear is reference (1 for x-axis or 2 for y axis) ";
		cin>>ch;
	}while(ch<= 0 || ch>2);
	if(ch==1){
		cout<<"Enter Xref ";
			cin>>ref[0];
		cout<<"Enter shy ";
		cin>>sh[1];	
	}else{
			cout<<"Enter Yref ";
			cin>>ref[1];
			cout<<"Enter shx";
		cin>>sh[0];	
	}
	}
	void doScallingFromCentroid(){
		Scaling(x,y,a,sk,"centroid");
	}
	void doScalling(){
		Scaling(x,y,a,sk);
	}
	void doTranslation(){
		Translation(x,y,a,tk);
	}
	void doRotationAboutCentroid(){
		Rotation(x,y,a,angle,"centroid");
	}
	void doRotation(){
		Rotation(x,y,a,angle);
	}
	void doShear(){
		Shear(x,y,a,ref,sh);
	};
	
};

int main()
{

    initwindow(600,600, "Rotation");
    Transformation T;
    int n;
    do{
	
cout<<"Enter the no for which transformation do you want:" <<endl;
cout<<"1) Scalling\n2) ScallingFromCentroid\n3) Rotation\n4) RotationAboutCentroid\n5) Shear\n6)Translation\n7) exit"<<endl;
cin>>n;
system("cls");
}while(n>8);

switch(n){

		
	case 1:
		T.takeData();
		T.takeDataForScaling();
		T.doScalling();
		break;
	case 2:
		T.takeData();
		T.takeDataForScaling();
		T.doScallingFromCentroid();
		break;
		
	case 3:
		T.takeData();
		T.takeDataForRotation();
		T.doRotation();
		break;
	case 4:
		T.takeData();
		T.takeDataForRotation();
		T.doRotationAboutCentroid();
		break;
	case 5:
		T.takeData();
		 T.takeDataForShear();
		 T.doShear();
		 break;
	case 6:
		T.takeData();
		 T.takeDataForTranslation();
		 T.doTranslation();
		 break;
	case 7:
		 exit(0); 
		 break;	 	 
	default:
		cout<<"Choose right option";
		break;
		 
		
		
}
    getch();
    closegraph();
}
