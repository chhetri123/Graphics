#include <GL/glut.h>

float ver1[8][3] =
{
    {-0.1,-3.0,0.3},
    {-0.1,3.0,0.3},
    {0.1,3.0,0.3},
    {0.1,-3.0,0.3},
    {-0.1,-3.0,-0.3},
    {-0.1,3.0,-0.3},
    {0.1,3.0,-0.30},
    {0.1,-3.0,-0.30},
};
float ver2[8][3];

void setAnotherVertices() {

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            ver2[i][j] = ver1[i][j];
        }
        ver2[i][1] = 0.1 * ver1[i][1];
        ver2[i][2] = 3 * ver1[i][2];


    }
}
GLfloat color[8][3] =
{
    {0.0,0.0,0.0},
    {1.0,0.0,0.0},
    {1.0,1.0,0.0},
    {0.0,1.0,0.0},
    {0.0,0.0,1.0},
    {1.0,0.0,1.0},
    {1.0,1.0,1.0},
    {0.0,1.0,1.0},
};

void quad(int a, int b, int c, int d, float ver[][3])
{
    glBegin(GL_QUADS);
    glColor3fv(color[a]);
    glVertex3fv(ver[a]);

    glColor3fv(color[b]);
    glVertex3fv(ver[b]);

    glColor3fv(color[c]);
    glVertex3fv(ver[c]);

    glColor3fv(color[d]);
    glVertex3fv(ver[d]);
    glEnd();
}



void colorcube(float ver[][3])
{
    quad(0, 3, 2, 1, ver);
    quad(2, 3, 7, 6, ver);
    quad(0, 4, 7, 3, ver);
    quad(1, 2, 6, 5, ver);
    quad(4, 5, 6, 7, ver);
    quad(0, 1, 5, 4, ver);
}


void display()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    gluPerspective(100, (double)640 / 480, 0.1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt
    (
        5, 0, 0,
        0, 0, 0,
        0, 0, 1
    );
    setAnotherVertices();
     glTranslatef(-3.0f, 0.0f, 6.0f);
    colorcube(ver1);
    glTranslatef(0.0f, -2.7f, -1.0f);
    colorcube(ver2);
    glTranslatef(0.0f, 2.7f, -1.2f);
    colorcube(ver1);
    glTranslatef(0.0f, 2.7f, -1.0f);
    colorcube(ver2);
    glTranslatef(0.0f, -2.7f, -1.2f);
    colorcube(ver1);
   

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(800, 800);
    glutCreateWindow("SANDIP SHRESTHA (PAS076BEI032) S");;
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}