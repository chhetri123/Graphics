#ifndef ROTATE_H
#define ROTATE_H

void Rotation(float x[],float [],int size,float angle, const std::string& rotation_name="normal");
void Plot(float  x[],float y[],int size,int color=4);
void Translation (float  x[],float y[],int size,float t[]);
void Scaling(float x[], float y[],int size,float sk[],const std::string& scale_from="origin");
void Shear(float x[],float y[],int size,float ref[],float sh[]);

#endif
