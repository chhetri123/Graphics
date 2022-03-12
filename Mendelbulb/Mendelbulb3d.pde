import peasy.*;
int dim = 150;
int n = 16; // Try with Differents powers
int iteration=16; // Try With different Iterations
PeasyCam cam;
ArrayList<PVector> MendalBulb = new ArrayList<PVector>();
void setup() {
    size(600,600,P3D);
    windowMove(1300,100);
    cam = new PeasyCam(this,500);
    
    for (int i = 0;i < dim;i++) {
        for (int j = 0;j < dim;j++) {
            boolean edge = false;
            for (int k = 0;k < dim;k++) {
                float x = map(i,0,dim, -1,1);
                float y = map(j,0,dim, -1,1);
                float z = map(k,0,dim, -1,1);
                
                PVector man = new PVector(0,0,0);
                int it = 0;
                while(it<= iteration) {
                    
                    Spherical C = spherical(man.x,man.y,man.z);
                    
                    
                    float newx = pow(C.r,n) * sin(C.theta * n) * cos(C.phi * n);
                    float newy = pow(C.r,n) * sin(C.theta * n) * sin(C.phi * n);
                    float newz = pow(C.r,n) * cos(C.theta * n);
                    
                    man.x = newx + x;
                    man.y = newy + y;
                    man.z = newz + z;
                    it++;
                    
                    if (C.r > 12) {
                        if (edge) {
                            edge = false;
                        }
                        break;
                    }
                    if (it > iteration) {
                        if (!edge) {
                            edge = true;
                            MendalBulb.add(new PVector(x * 100,y * 100,z * 100));
                        }
                    }
                }
                
                
                
            }
        }
    }
}
class Spherical{
    float r,theta,phi;
    
    Spherical(float r, float theta, float phi) {
        this.r = r;
        this.theta = theta;
        this.phi = phi;
    }
    
}
Spherical spherical(float x, float y,float z) {
    float  r = sqrt(x * x + y * y + z * z);
    float theta = atan2(sqrt(x * x + y * y), z);
    float phi = atan2(y,x);
    
    return new Spherical(r,theta,phi);
}
void draw() { // loop
    background(0);
    
    for (PVector v : MendalBulb) {
        
        stroke(150);
        point(v.x,v.y,v.z);
    }
    
}
