#include "glos.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
#include <math.h>

void myinit(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);

GLUquadricObj* rocketPlate;
GLUnurbsObj* theNurb;



#pragma region MiscareRacheta
int rotate = 0, rotateRacheta=0;
int umbra = 0;

void CALLBACK Rotate()
{
    rotate = (5 + rotate) % 360;
}
void CALLBACK RotateRacheta()
{
    rotateRacheta = (5 + rotateRacheta) % 360;
}
void CALLBACK RotateRachetaInvers()
{
    rotateRacheta = ( rotateRacheta-5) % 360;
}
void CALLBACK RotateInvers()
{
    rotate = (rotate - 5) % 360;
}


#pragma endregion




int xSursa = 25, ySursa = 30, zSursa = 500;

void CALLBACK CresteXSursa()
{
    xSursa = (xSursa + 5) ;
}
void CALLBACK ScadeXSursa()
{
    xSursa = (xSursa - 5) ;
}

void CALLBACK CresteYSursa()
{
    ySursa = (ySursa + 5) ;
}
void CALLBACK ScadeYSursa()
{
    ySursa = (ySursa - 5) ;
}

void CALLBACK CresteZSursa()
{
    zSursa = (zSursa + 5);
}
void CALLBACK ScadeZSursa()
{
    zSursa = (zSursa - 5);
}



GLfloat ctrlpoints[4][4][3] = {
    {   {-3, -24, 0}, {-2, -26, 0}, {2, -26, 0}, {3, -24,0 }   },
    {   {-12, -5, 0}, {-7, -5, 18}, {7, -5, 18}, {12, -5, 0}   },
    {   {-12, 5, 0}, {-7, 5, 18}, {7, 5, 18}, {12, 5, 0}    },
    {   {-1, 29,0}, {-0.5, 30, 0}, {0.5, 30, 0}, {1, 29, 0} }

};

GLfloat ctrlpointsGeam[4][4][3] = {
    {   {-0.8, -1.2, 0.5}, {-0.5, -1.5, 2}, {0.5, -1.5, 2}, {0.8, -1.2, 0.5}   },
    {   {-1.5, -0.5, 1}, {-0.5, -0.5, 3}, {0.5, -0.5,3}, {1.5, -0.5, 1}   },
    {   {-1.5, 0.5, 1}, {-0.5, 0.5, 3}, {0.5, 0.5, 3}, {1.5, 0.5, 1}    },
    {   {-0.8, 1.2, 0.5}, {-0.5, 1.5, 2}, {0.5, 1.5, 2}, {0.8, 1.2, 0.5} }
};



// setari pentru iluminarea suprafetei
void initlights(void)
{
 
    GLfloat ambient[] = { 0.2, 0.2, 0.2, 1.0 };

    GLfloat mat_diffuse[] = { 0.6, 0.6, 0.6, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);

    //SETEAZA SURSA 
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

    //SETEAZA MATERIALUL
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   


  
}

void CALLBACK stars() {

    glPushMatrix();
    glScalef(2, 2, 2);

    glColor3f(0.482, 0.937, 0.145);
    glPushMatrix();
    glTranslated(-5.5, 5, -300);
    auxSolidSphere(2.5);
    glPopMatrix();

    glColor3f(0.937, 0.145, 0.145);
    glPushMatrix();
    glTranslated(-15.5, -2.5, -200);
    auxSolidSphere(1.15);
    glPopMatrix();

    glColor3f(0.145, 0.882, 0.937);
    glPushMatrix();
    glTranslated(-5.5, 5, -200);
    auxSolidSphere(2);
    glPopMatrix();


    glColor3f(0.129, 0.168, 0.949);
    glPushMatrix();
    glTranslated(-26.5, 19, -400);
    auxSolidSphere(1.6);
    glPopMatrix();

    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslated(-30, -20, -100);
    auxSolidIcosahedron(1);
    glPopMatrix();

    glColor3f(1, 0, 1);
    glPushMatrix();
    glTranslated(-10, 0, -100);
    auxSolidIcosahedron(1);
    glPopMatrix();

    glColor3f(1, 0.51, 0.04);
    glPushMatrix();
    glTranslated(35.5, 20, -250);
    auxSolidSphere(2);
    glPopMatrix();


    glColor3f(0, 0.51, 0.72);
    glPushMatrix();
    glTranslated(35.5, -20, -200);
    glRotated(-90, 1, 0, 0);
    auxSolidSphere(1.5);
    glPopMatrix();

    glColor3f(0.486, 0.862, 0.035);
    glPushMatrix();
    glTranslated(-50, -10, -150);
    auxSolidIcosahedron(1);
    glPopMatrix();
    glPopMatrix();
    //p2

    glPushMatrix();
    glTranslatef(-180, 0, 0);
    glScalef(2, 2, 2);

    glColor3f(0.482, 0.937, 0.145);
    glPushMatrix();
    glTranslated(-5.5, 5, -300);
    auxSolidSphere(2.5);
    glPopMatrix();

    glColor3f(0.937, 0.145, 0.145);
    glPushMatrix();
    glTranslated(-15.5, -2.5, -200);
    auxSolidSphere(1.15);
    glPopMatrix();

    glColor3f(0.145, 0.882, 0.937);
    glPushMatrix();
    glTranslated(-5.5, 5, -200);
    auxSolidSphere(2);
    glPopMatrix();


    glColor3f(0.129, 0.168, 0.949);
    glPushMatrix();
    glTranslated(-26.5, 19, -400);
    auxSolidSphere(1.6);
    glPopMatrix();

    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslated(-30, -20, -100);
    auxSolidIcosahedron(1);
    glPopMatrix();

    glColor3f(1, 0, 1);
    glPushMatrix();
    glTranslated(-10, 0, -100);
    auxSolidIcosahedron(1);
    glPopMatrix();

    glColor3f(1, 0.51, 0.04);
    glPushMatrix();
    glTranslated(35.5, 20, -250);
    auxSolidSphere(2);
    glPopMatrix();


    glColor3f(0, 0.51, 0.72);
    glPushMatrix();
    glTranslated(35.5, -20, -200);
    glRotated(-90, 1, 0, 0);
    auxSolidSphere(1.5);
    glPopMatrix();

    glColor3f(0.486, 0.862, 0.035);
    glPushMatrix();
    glTranslated(-50, -10, -150);
    auxSolidIcosahedron(1);
    glPopMatrix();
    glPopMatrix();

    //p3
    glPushMatrix();
    glTranslatef(180, 0, 0);
    glScalef(2, 2, 2);

    glColor3f(0.482, 0.937, 0.145);
    glPushMatrix();
    glTranslated(-5.5, 5, -300);
    auxSolidSphere(2.5);
    glPopMatrix();

    glColor3f(0.937, 0.145, 0.145);
    glPushMatrix();
    glTranslated(-15.5, -2.5, -200);
    auxSolidSphere(1.15);
    glPopMatrix();

    glColor3f(0.145, 0.882, 0.937);
    glPushMatrix();
    glTranslated(-5.5, 5, -200);
    auxSolidSphere(2);
    glPopMatrix();


    glColor3f(0.129, 0.168, 0.949);
    glPushMatrix();
    glTranslated(-26.5, 19, -400);
    auxSolidSphere(1.6);
    glPopMatrix();

    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslated(-30, -20, -100);
    auxSolidIcosahedron(1);
    glPopMatrix();

    glColor3f(1, 0, 1);
    glPushMatrix();
    glTranslated(-10, 0, -100);
    auxSolidIcosahedron(1);
    glPopMatrix();

    glColor3f(1, 0.51, 0.04);
    glPushMatrix();
    glTranslated(35.5, 20, -250);
    auxSolidSphere(2);
    glPopMatrix();


    glColor3f(0, 0.51, 0.72);
    glPushMatrix();
    glTranslated(35.5, -20, -200);
    glRotated(-90, 1, 0, 0);
    auxSolidSphere(1.5);
    glPopMatrix();

    glColor3f(0.486, 0.862, 0.035);
    glPushMatrix();
    glTranslated(-50, -10, -150);
    auxSolidIcosahedron(1);
    glPopMatrix();
    glPopMatrix();
    //p4

    glPushMatrix();
    glTranslatef(0, 100, 0);
    glScalef(2, 2, 2);

    glColor3f(0.482, 0.937, 0.145);
    glPushMatrix();
    glTranslated(-5.5, 5, -300);
    auxSolidSphere(2.5);
    glPopMatrix();

    glColor3f(0.937, 0.145, 0.145);
    glPushMatrix();
    glTranslated(-15.5, -2.5, -200);
    auxSolidSphere(1.15);
    glPopMatrix();

    glColor3f(0.145, 0.882, 0.937);
    glPushMatrix();
    glTranslated(-5.5, 5, -200);
    auxSolidSphere(2);
    glPopMatrix();


    glColor3f(0.129, 0.168, 0.949);
    glPushMatrix();
    glTranslated(-26.5, 19, -400);
    auxSolidSphere(1.6);
    glPopMatrix();

    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslated(-30, -20, -100);
    auxSolidIcosahedron(1);
    glPopMatrix();

    glColor3f(1, 0, 1);
    glPushMatrix();
    glTranslated(-10, 0, -100);
    auxSolidIcosahedron(1);
    glPopMatrix();

    glColor3f(1, 0.51, 0.04);
    glPushMatrix();
    glTranslated(35.5, 20, -250);
    auxSolidSphere(2);
    glPopMatrix();


    glColor3f(0, 0.51, 0.72);
    glPushMatrix();
    glTranslated(35.5, -20, -200);
    glRotated(-90, 1, 0, 0);
    auxSolidSphere(1.5);
    glPopMatrix();

    glColor3f(0.486, 0.862, 0.035);
    glPushMatrix();
    glTranslated(-50, -10, -150);
    auxSolidIcosahedron(1);
    glPopMatrix();
    glPopMatrix();

    //p5

    glPushMatrix();
    glTranslatef(0, -100, 0);
    glScalef(2, 2, 2);

    glColor3f(0.482, 0.937, 0.145);
    glPushMatrix();
    glTranslated(-5.5, 5, -300);
    auxSolidSphere(2.5);
    glPopMatrix();

    glColor3f(0.937, 0.145, 0.145);
    glPushMatrix();
    glTranslated(-15.5, -2.5, -200);
    auxSolidSphere(1.15);
    glPopMatrix();

    glColor3f(0.145, 0.882, 0.937);
    glPushMatrix();
    glTranslated(-5.5, 5, -200);
    auxSolidSphere(2);
    glPopMatrix();


    glColor3f(0.129, 0.168, 0.949);
    glPushMatrix();
    glTranslated(-26.5, 19, -400);
    auxSolidSphere(1.6);
    glPopMatrix();

    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslated(-30, -20, -100);
    auxSolidIcosahedron(1);
    glPopMatrix();

    glColor3f(1, 0, 1);
    glPushMatrix();
    glTranslated(-10, 0, -100);
    auxSolidIcosahedron(1);
    glPopMatrix();

    glColor3f(1, 0.51, 0.04);
    glPushMatrix();
    glTranslated(35.5, 20, -250);
    auxSolidSphere(2);
    glPopMatrix();


    glColor3f(0, 0.51, 0.72);
    glPushMatrix();
    glTranslated(35.5, -20, -200);
    glRotated(-90, 1, 0, 0);
    auxSolidSphere(1.5);
    glPopMatrix();

    glColor3f(0.486, 0.862, 0.035);
    glPushMatrix();
    glTranslated(-50, -10, -150);
    auxSolidIcosahedron(1);
    glPopMatrix();
    glPopMatrix();





}



void myinit(void) {
    //155, 167, 186
    glClearColor(0.18, 0.23, 0.3, 1.0);//seteaza culoarea de stergere a ecranului - nu sterge defapt ecranul

    glEnable(GL_DEPTH_TEST); // se activeaza ascunderea suprafetelor

 

    glEnable(GL_MAP2_VERTEX_3);
    // validarea tipului de evaluare GL_MAP2_VERTEX_3
    glEnable(GL_AUTO_NORMAL);
   glEnable(GL_NORMALIZE); // pentru iluminare
    glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);// intervalele de esantionare 
    // a suprafetei pentru parametrii u si v

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);// CULORI 


#pragma region bandaAlba
    glShadeModel(GL_FLAT);
    // glEnable(GL_DEPTH_TEST);
    theNurb = gluNewNurbsRenderer(); // obiectul de tip GLUnurbsObj
    // este creat dinamic in memoria libera prin apelul functiei gluNewNurbsRenderer()
    gluNurbsProperty(theNurb, GLU_SAMPLING_TOLERANCE, 10.0);
    // er0area de esantionare a curbei la redare
    glLineStipple(1, 0x0F0F);
    glPointSize(5);
#pragma endregion
    initlights();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
}

void rocket_body() {
    if(umbra)	glColor3f(0.4, 0.4, 0.4);
    else
    glColor3f(0.8, 0, 0);
    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
        0, 1, 12, 4, &ctrlpoints[0][0][0]);
    glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);



 

    glPushMatrix();
    //  glRotatef(90.0, 1, 0, 0);
    //    glutSolidIcosahedron();

    glRotatef(90.0, 0, 1, 0);
    glEvalMesh2(GL_FILL, 0, 20, 0, 20); // specifica modul
    // de redare al poligoanelor (GL_FILL, GL_POINT, GL_LINE, 
    // si intervalele de esantionare a suprafetei pentru u si v

    glPopMatrix();

    //a doua capita


    glPushMatrix();
    glRotatef(-90.0, 0, 1, 0);
    glEvalMesh2(GL_FILL, 0, 20, 0, 20); // specifica modul
    // de redare al poligoanelor (GL_FILL, GL_POINT, GL_LINE, 
    // si intervalele de esantionare a suprafetei pentru u si v
    glPopMatrix();

    //glRotatef(180.0, 0, 1, 0);
   // glTranslatef(-7, -1, 0);

}

void rocketWhiteBand()
{
    GLfloat ctlpoints[14][3] = {
    {10, 0, 10},
    {8.09204, 5.87528, 10},
    {3.09623, 9.50859, 10},
    {-3.08108, 9.51351, 10},
    {-8.08267, 5.88816, 10},
    {-9.99999, 0.0159265, 10},
    {-8.10139, -5.86238, 10},
    {-3.11137, -9.50365, 10},
    {3.06592, -9.51841, 10},
    {8.07329, -5.90102, 10},
    {10, 0, 10},
    {10, 0, 10},
    {10, 0, 10},
    {10, 0, 10},
    };

    GLfloat knots[18] = { 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 11, 11, 11 };


    // incepe corpul de redare al curbei Spline
    glPushMatrix();
    //glScalef(0.5, 0.5, 0.5);
    if (umbra)	glColor3f(0.4, 0.4, 0.4);
    else
    glColor3f(1, 1, 1);

    glTranslatef(0, 2.5, 0);
    glRotatef(90, 1, 0, 0);
    glLineWidth(15.0);//grosimea benzii


    glDisable(GL_LINE_STIPPLE);
    gluBeginCurve(theNurb);
    gluNurbsCurve(theNurb,	// pointer obiect NURBS
        18, knots,			//numar noduri, tablou noduri
        3,					// intervalul de valori dintre doua puncte de control consecutive
        &ctlpoints[0][0],	// vector puncte de control
        4,					// ordinul curbei 
        GL_MAP1_VERTEX_3);	// tip evaluator
    gluEndCurve(theNurb);
    glPopMatrix();

    glEnd();
}





void rocket_plates() {


    rocketPlate = gluNewQuadric();
    gluQuadricDrawStyle(rocketPlate, GLU_FILL);
    gluQuadricNormals(rocketPlate, GLU_SMOOTH);
    //  gluQuadricOrientation(rocketPlate, GLU_OUTSIDE);

    //rotire partea de jos
    glPushMatrix();
    glTranslatef(0, -21, 0);
    glRotatef(rotate, 0, 1, 0);
    glTranslatef(0, 21, 0);

  //conuri laterale
    if (umbra)	glColor3f(0.4, 0.4, 0.4);
    else
    glColor3f(0.72, 0.72, 0.72);

    glPushMatrix();
    glTranslatef(6.5, -20, 0);
    glRotatef(180, 0, 1, 0);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(rocketPlate, 3, 0.5, 10, 5, 5);
    glPopMatrix();

    if (umbra)	glColor3f(0.4, 0.4, 0.4);
    else 
    glColor3f(0.58, 0.0039, 0.0039);

    glPushMatrix();
    glTranslatef(6.5, -20, 0);
    glRotatef(180, 0, 1, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(rocketPlate, 3, 0.5, 17, 5, 5);
    glPopMatrix();


    //cilindru baza racheta
  
    glPushMatrix();
    if (umbra)	glColor3f(0.4, 0.4, 0.4);
    else 
    glColor3f(0.21, 0.72, 1);

    glTranslatef(0, -21, 0);

    glRotatef(180, 0, 0, 1);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(rocketPlate, 7, 5, 2, 5, 5);
    glPopMatrix();

    glPushMatrix();

    if (umbra)	glColor3f(0.4, 0.4, 0.4);
    else
    glColor3f(0.70, 0.7, 0.7);

    glTranslatef(0, -23, 0);

    glRotatef(180, 0, 0, 1);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(rocketPlate, 5, 3, 3, 5, 5);
    glPopMatrix();


    //conuri laterale

    glPushMatrix();
    if (umbra)	glColor3f(0.4, 0.4, 0.4);
    else
    glColor3f(0.72, 0.72, 0.72);

    glTranslatef(-7, -20, 0);
    glRotatef(180, 0, 1, 0);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(rocketPlate, 3, 0.5, 10, 5, 5);
    glPopMatrix();


    glPushMatrix();
    if (umbra)	glColor3f(0.4, 0.4, 0.4);
    else
    glColor3f(0.58, 0.0039, 0.0039);

    glTranslatef(-7, -20, 0);
    glRotatef(180, 0, 1, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(rocketPlate, 3, 0.5, 17, 5, 5);
    glPopMatrix();
    glPopMatrix();





}
void rocket_windowFace() {

    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
        0, 1, 12, 4, &ctrlpointsGeam[0][0][0]);
    glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);

    
   

    glPushMatrix();

    glTranslatef(-0.6, 6, 3.9);
    glRotatef(-5.5, 1, 0, 0);
    glScalef(3.5, 3.5, 3.5);

    if (umbra)	glColor3f(0.4, 0.4, 0.4);
    else
    glColor3f(0.21, 0.72, 1);

    glPushMatrix();
    glEvalMesh2(GL_FILL, 0, 20, 0, 20);
    glPopMatrix();

    if (umbra)	glColor3f(0.4, 0.4, 0.4);
    else
    glColor3f(1, 1, 1);

    glTranslatef(0, 0, 1.3);
    auxSolidTorus(0.3, 1.5);


    glPopMatrix();
   





}

void rocket_windowBack() {

    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
        0, 1, 12, 4, &ctrlpointsGeam[0][0][0]);
    glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
    if (umbra)	glColor3f(0.4, 0.4, 0.4);
    else     glColor3f(0.21, 0.72, 1);

    //a doua capita

    glPushMatrix();
    glRotatef(180, 1, 0, 0);
    glTranslatef(-0.6, -6, 3.9);
    glRotatef(5.5, 1, 0, 0);
    glScalef(3.5, 3.5, 3.5);

    glPushMatrix();
    glEvalMesh2(GL_FILL, 0, 20, 0, 20);
    glPopMatrix();
    if (umbra)	glColor3f(0.4, 0.4, 0.4);
    else 
    glColor3f(1, 1, 1);
    glTranslatef(0, 0, 1.3);
    auxSolidTorus(0.3, 1.5);

    glPopMatrix();

    // glPopMatrix();
}


void rocket_assembly() {
  //  glPushMatrix();
  //  stars();
  //  glPopMatrix();


    glPushMatrix();

    glScalef(2, 2, 2);
   // glRotatef(rotate, 0, 1, 0);

    rocket_body();
    rocket_plates();
   // rocketWhiteBand();

    rocket_windowFace();
    rocket_windowBack();

    glPopMatrix();

}

//umbra

void plan(void)
{
    glColor3f(0, 0, 0);
  
    glBegin(GL_QUADS);
    glVertex3f(460, -150, -13000);
    glVertex3f(-460.0f, -150, -13000);
    glVertex3f(-460.0f, -150, 13000);
    glVertex3f(460.0f, -150, 13000);
    glEnd();
   //auxSolidBox(100, 10, 100);
}

void calcCoeficientiPlan(float P[3][3], float coef[4])
{
    float v1[3], v2[3];
    float length;
    static const int x = 0;
    static const int y = 1;
    static const int z = 2;
    //calculeazã doi vectori din trei puncte
    v1[x] = P[0][x] - P[1][x];
    v1[y] = P[0][y] - P[1][y];
    v1[z] = P[0][z] - P[1][z];

    v2[x] = P[1][x] - P[2][x];
    v2[y] = P[1][y] - P[2][y];
    v2[z] = P[1][z] - P[2][z];

    //se cacluleazã produsul vectorial al celor doi vectori
    // care reprezintã un al treilea vector perpendicular pe plan 
    // ale cãrui componente sunt chiar coeficienþii A, B, C din ecuaþia planului
    coef[x] = v1[y] * v2[z] - v1[z] * v2[y];
    coef[y] = v1[z] * v2[x] - v1[x] * v2[z];
    coef[z] = v1[x] * v2[y] - v1[y] * v2[x];
    //normalizeazã vectorul
    length = (float)sqrt((coef[x] * coef[x]) + (coef[y] * coef[y]) + (coef[z] * coef[z]));
    coef[x] /= length;
    coef[y] /= length;
    coef[z] /= length;
}
void MatriceUmbra(GLfloat puncte[3][3], GLfloat pozSursa[4],
    GLfloat mat[4][4])
{
    GLfloat coefPlan[4];
    GLfloat temp;
    //determinã coeficienþii planului
    calcCoeficientiPlan(puncte, coefPlan);
    //determinã si pe D
    coefPlan[3] = -(
        (coefPlan[0] * puncte[2][0]) +
        (coefPlan[1] * puncte[2][1]) +
        (coefPlan[2] * puncte[2][2]));
    //temp=A*xL+B*yL+C*zL+D*w
    temp = coefPlan[0] * pozSursa[0] +
        coefPlan[1] * pozSursa[1] +
        coefPlan[2] * pozSursa[2] +
        coefPlan[3] * pozSursa[3];
    //prima coloanã
    mat[0][0] = temp - pozSursa[0] * coefPlan[0];
    mat[1][0] = 0.0f - pozSursa[0] * coefPlan[1];
    mat[2][0] = 0.0f - pozSursa[0] * coefPlan[2];
    mat[3][0] = 0.0f - pozSursa[0] * coefPlan[3];
    //a doua coloana
    mat[0][1] = 0.0f - pozSursa[1] * coefPlan[0];
    mat[1][1] = temp - pozSursa[1] * coefPlan[1];
    mat[2][1] = 0.0f - pozSursa[1] * coefPlan[2];
    mat[3][1] = 0.0f - pozSursa[1] * coefPlan[3];
    //a treia coloana
    mat[0][2] = 0.0f - pozSursa[2] * coefPlan[0];
    mat[1][2] = 0.0f - pozSursa[2] * coefPlan[1];
    mat[2][2] = temp - pozSursa[2] * coefPlan[2];
    mat[3][2] = 0.0f - pozSursa[2] * coefPlan[3];
    //a patra coloana
    mat[0][3] = 0.0f - pozSursa[3] * coefPlan[0];
    mat[1][3] = 0.0f - pozSursa[3] * coefPlan[1];
    mat[2][3] = 0.0f - pozSursa[3] * coefPlan[2];
    mat[3][3] = temp - pozSursa[3] * coefPlan[3];
}


void CALLBACK display(void)
{
   
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//esentiala,stergerea ecranului, a scrie tot buffer ul de culoare cu inf data

    glLoadIdentity();//matricea curenta o incarca cu matricea identitate
    GLfloat pozSursa[] = { xSursa, ySursa, zSursa, 1.0 };

    GLfloat matUmbra[4][4];
    //oricare trei puncte din plan în sens CCW
    GLfloat puncte[3][3] = { {-50.0f, -150.0f, -50.0f},
                            {-50.0, -150.0f, 50.0},
                            {50.0f, -150.0f, 50.0f} };
    //determinã matricea pentru calcularea umbrei	
    MatriceUmbra(puncte, pozSursa, matUmbra);
    
  
   glPushMatrix();
        stars();
        glRotatef(10, 1, 1, 0);
     

    umbra = 1;
    //deseneazã umbra
    //mai întâi se dezactiveazã iluminarea si se salveazã starea matricei de proiectie
    glPushAttrib(GL_LIGHTING_BIT);
      glDisable(GL_LIGHTING);

      glPushMatrix();

            glMultMatrixf((GLfloat*)matUmbra);
            glRotatef(rotateRacheta, 0, 1, 0);
            rocket_assembly();
            glTranslatef(0, -300, 0);
           glRotatef(30, 1, 1, 1);

       glPopMatrix(); //reface matricea de proiecþie la normal


       glPushMatrix();

          
            glTranslatef(xSursa, 0, 0);
            glTranslatef(0, ySursa, 0);
            glTranslatef(0, 0, zSursa);

            glLightfv(GL_LIGHT0, GL_POSITION, pozSursa);
            glTranslated(-75.0, 125, 25.0);
            glDisable(GL_LIGHTING);
            glColor3f(0.59, 0.96, 0.93);
            auxSolidSphere(10);
            glEnable(GL_LIGHTING);


        glPopMatrix();
            umbra = 0;

            glPushMatrix();
            glRotatef(rotateRacheta,0, 1, 0);
            rocket_assembly();
            glPopMatrix();
            plan();

     glPopAttrib();

   glPopMatrix(); 
    glFlush();//esential, fortam golirea buffer ului, comenzile pleaca cand se umple buffer ul
}

void CALLBACK myReshape(GLsizei w, GLsizei h)//latimea si inaltimea 
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-250, 250, -250 * (GLfloat)h / (GLfloat)w,
            250 * (GLfloat)h / (GLfloat)w, -10000.0, 10000.0);
    else
        glOrtho(-250 * (GLfloat)w / (GLfloat)h,
            250 * (GLfloat)w / (GLfloat)h, -250, 250, -10000.0, 10000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}



int main(int argc, char** argv)
{
    //crearea ferestrei
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB | AUX_DEPTH16); 
    auxInitPosition(0, 0, 500, 500);
    auxInitWindow("My rocket");//bara de titlu
    myinit();

    auxKeyFunc(AUX_a, Rotate);
    auxKeyFunc(AUX_d, RotateInvers);
    auxKeyFunc(AUX_w, RotateRacheta);
    auxKeyFunc(AUX_s, RotateRachetaInvers);

   
    
    auxKeyFunc(AUX_UP, CresteYSursa);
    auxKeyFunc(AUX_DOWN, ScadeYSursa);

    auxKeyFunc(AUX_RIGHT, CresteXSursa);
    auxKeyFunc(AUX_LEFT, ScadeXSursa);

    auxKeyFunc(AUX_i, CresteZSursa);
    auxKeyFunc(AUX_k, ScadeZSursa);

    auxReshapeFunc(myReshape);
    auxMainLoop(display);
    return(0);
}