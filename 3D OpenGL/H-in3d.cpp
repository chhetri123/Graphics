#include <GL/glut.h>

float ver1[8][3] =
{
    {-0.1,-0.1,1.0},
    {-0.1,0.1,1.0},
    {0.1,0.1,1.0},
    {0.1,-0.1,1.0},
    {-0.1,-0.1,-1.0},
    {-0.1,0.1,-1.0},
    {0.1,0.1,-1.0},
    {0.1,-0.1,-1.0},
};
float ver2[8][3];
float ver3[8][3];

void setAnotherVertices() {

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            ver2[i][j] = ver1[i][j];
            ver3[i][j] = ver1[i][j];
            

        }
        ver3[i][1] = 7* ver3[i][1];
        ver3[i][2] = 0.1 * ver3[i][2];
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

double rotate_y = 0;
double rotate_x = 0;
void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;
    else if (key == GLUT_KEY_UP)
        rotate_x += 5;
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;
    glutPostRedisplay();
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
        3, 0, 0,
        0, 0, 0,
        0, 0, 1
    );

    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    setAnotherVertices();
    colorcube(ver1);
    glTranslatef(0.0f, 0.8f, 0.0f);
    colorcube(ver3);
    glTranslatef(0.0f, 0.8f, 0.0f);
    colorcube(ver2);

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Manish Chhetri (PAS076BEI015) H");
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}