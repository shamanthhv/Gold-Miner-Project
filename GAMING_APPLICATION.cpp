#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

void display();
void update();
void startscreen();

#define PI 3.142857142857143
GLint tc = 0;
GLint startflag = 0;
GLfloat cx = 0, cy = 3; //centre of line cordinates
GLfloat z1 = 0, z2 = 0; //end coordinates of line
GLfloat theta = 180; // angle of line in the range 180 to 360
GLfloat r = 2, inc = 1.5, rinc = 0.01; //radius , theta inc , radius lenght rinc 
GLint bflag = 0; // mouse button flag
GLint endflag = 0; // to check max limit of line
GLint tdelay = 10,t1delay = 1;
GLint max = 17;
GLint w = 500, h = 500;
GLint count = 0;
GLint initial_time =45;
GLint t2delay = 1000;
GLint gameover_flag = 1;
char tn[50];
char str4[20] = { "YOU WIN!!!!" };
char str8[22] = { "TIME UP....YOU LOSE!" };
GLint count1 = 0;
GLint flag = 0;
class goldblocks
{
	float gx1, gy1, gx2, gy2, gx3, gy3, gx4, gy4;
public:
	int hit;
	int result;
	void display_block()
	{

		glColor3f(1,0.843,0);
		glBegin(GL_POLYGON);
		glVertex2f(gx1, gy1);
		glVertex2f(gx2, gy2);
		glVertex2f(gx3, gy3);
		glVertex2f(gx4, gy4);
		glEnd();

	}
	int check()
	{
		if ((z1 >= gx1) && (z1 <= gx2) && (z2 <= gy1) && (z2 >= gy4))
		{
			flag = 1;
			return 0;
		}
		else
			return 1;
	}
	goldblocks(float a, float b, float c, float d, float e, float f, float g, float h)
	{
		gx1 = a;
		gy1 = b;
		gx2 = c;
		gy2 = d;
		gx3 = e;
		gy3 = f;
		gx4 = g;
		gy4 = h;
		hit = 0;
	}

};

goldblocks obj1(-2, -3, -1, -3, -1, -4, -2, -4);
goldblocks obj2(3, -3, 4, -3, 4, -4, 3, -4);
goldblocks obj3(-9, -3, -8, -3, -8, -4, -9, -4);
goldblocks obj4(-6, -5, -5, -5, -5, -6, -6, -6);
goldblocks obj5(8, -8, 9, -8, 9, -9, 8, -9);
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);


}


void startscreen()
{
	char str1[20] = { "PRESS 'S' TO START" };
	char str2[20] = { "PRESS 'H' FOR HELP" };
	int n1 = strlen(str1);
	int n2 = strlen(str2);
	glClearColor(0.4,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(255,215,0);
	glLineWidth(10);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-7, 3.5);
	glVertex2f(-7, 4);
	glVertex2f(-8, 4);
	glVertex2f(-8,2);
	glVertex2f(-7,2);
	glVertex2f(-7,3);
	glVertex2f(-7.5, 3);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(-5, 4);
	glVertex2f(-6, 4);
	glVertex2f(-6, 2);
	glVertex2f(-5, 2);
	glVertex2f(-5, 4);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(-4, 4);
	glVertex2f(-4, 2);
	glVertex2f(-3, 2);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(-2, 4);
	glVertex2f(-2, 2);
	glVertex2f(-1.5, 2);
	glVertex2f(-1, 2.5);
	glVertex2f(-1, 3.5);
	glVertex2f(-1.5, 4);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(-4, 1);
	glVertex2f(-4, -1);
	glVertex2f(-3.5, -1);
	glVertex2f(-3,-0.5);
	glVertex2f(-3, 0.5);
	glVertex2f(-3.5, 1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-2, 1);
	glVertex2f(-1, 1);
	glVertex2f(-1.5, 1);
	glVertex2f(-1.5, -1);
	glVertex2f(-2, -1);
	glVertex2f(-1, -1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(1, 0.5);
	glVertex2f(1, 1);
	glVertex2f(0, 1);
	glVertex2f(0, -1);
	glVertex2f(1, -1);
	glVertex2f(1, 0);
	glVertex2f(0.5, 0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(3, 0.5);
	glVertex2f(3, 1);
	glVertex2f(2, 1);
	glVertex2f(2, -1);
	glVertex2f(3, -1);
	glVertex2f(3, 0);
	glVertex2f(2.5, 0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(5, 1);
	glVertex2f(4, 1);
	glVertex2f(4, 0);
	glVertex2f(5, 0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(4, 0);
	glVertex2f(4, -1);
	glVertex2f(5, -1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(6, -1);
	glVertex2f(6, 0);
	glVertex2f(6, 1);
	glVertex2f(7, 1);
	glVertex2f(7, 0.5);
	glVertex2f(6.5, 0);
	glVertex2f(7, -1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(6, 0);
	glVertex2f(6.5, 0);
	glEnd();

	glColor3f(0, 1, 0);
	glRasterPos2f(-2, -4);
	for (int i = 0; i < n1; i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str1[i]);
	glRasterPos2f(-2, -5);
	for (int i = 0; i < n2; i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str2[i]);
	glPointSize(10);
	glColor3f(255, 215, 0);
	glBegin(GL_POINTS);
	glVertex2f(-2.5, -3.8);
	glVertex2f(-2.5, -4.8);
	glEnd();

}


void decline()
{

	endflag = 1;                  //the line has reached max size
	glBegin(GL_LINES);            // to increase the line length
	glVertex2f(cx, cy);           // center of line 
	z1 = cx+r*cos(theta*PI / 180);   //x coordinate with different length
	z2 = cy+r*sin(theta*PI / 180);   // same for y

	if (r >= 1)                   //decreases the size of line until size is >= 1
	{
		r = r - rinc;
		glVertex2f(z1, z2);
		glEnd();
	}

	if (r < 1)                   //after executing the above condition the radius becomes zero so set r = 1
	{

		r = 1;
		bflag = 0;                //set bflag=0 to perform oscillation
		glutPostRedisplay();
	}




}

void update(int value)
{
	
	if (bflag == 0) // if left button is not pressed
	{
		endflag = 0;   // ensure that the line is not at its max limit during oscillation i.e radius is 1


		z1 = cx+r*cos(theta*PI / 180); //x coordinate of end of line
		z2 = cy+r*sin(theta*PI / 180); //y coordinate of end of line
		theta = theta + inc;        //increments the angle for oscillation either clockwise or anticolckwise depending upon inc


		if (((theta > 180) && (theta > 360)) | ((theta < 180) && (theta < 360)))   //limit of theta between 180 and 360
			inc = -inc;                                                            //change inc +ve or -ve 
		glutPostRedisplay();
		glutTimerFunc(tdelay, update, 0);

	}
	if (bflag == 1 )              // if mouse button is pressed
	{
		
		glBegin(GL_LINES);            // to increase the line length
		glVertex2f(cx, cy);           // center of line 
		z1 = cx+r*cos(theta*PI / 180);   //x coordinate with different length
		z2 = cy+r*sin(theta*PI / 180); // y coordinate with different length
		obj1.result = obj1.check();
		obj2.result = obj2.check();
		obj3.result = obj3.check();
		obj4.result = obj4.check();
		obj5.result = obj5.check();
		if ((r < max) && (endflag == 0) && (obj1.result||obj1.hit) && (obj2.result||obj2.hit) && (obj3.result||obj3.hit) && (obj4.result||obj4.hit) && (obj5.result||obj5.hit)) // increase line length until endflag is 0 and length is < 6 if ***endflag==1 this condition is not executed***
		{

			r = r + rinc;             //  increase the line size
			glVertex2f(z1, z2);
			glEnd();
		}
		else
		{

			if (obj1.result == 0)
			{
				obj1.hit = 1;
			}
			else if (obj2.result == 0)
			{
				obj2.hit = 1;
			}
			else if (obj3.result == 0)
			{
				obj3.hit = 1;
			}
			else if (obj4.result == 0)
			{
				obj4.hit = 1;
			}
			else if (obj5.result == 0)
			{
				obj5.hit = 1;
			}

			decline();    // decrease the line size


		}
		glutPostRedisplay();
		glutTimerFunc(t1delay, update, 0);

	}

}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w<h)
		gluOrtho2D(-10 * (GLfloat)h/w, 10 * (GLfloat)h/w, -10, 10);
	else
		gluOrtho2D(-10,10,-10 * (GLfloat)h / w, 10 * (GLfloat)h / w);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void time_fun(int val)
{
	tc++;
	initial_time = initial_time - 1;
	if (initial_time >= 0 && gameover_flag )
	{
		glutPostRedisplay();
		glutTimerFunc(t2delay, time_fun, 0);
	}
}

void display()
{
	if (startflag == 0)
	{
		startscreen();
	}
	else
	{
		if (initial_time > 0)   //do not enter when time is up
		{
			glClearColor(0.4, 1, 1, 0);
			glClear(GL_COLOR_BUFFER_BIT);
			glColor3f(0.682,0.258,0.0);
			glBegin(GL_POLYGON);
			glVertex2f(-10, 3);
			glVertex2f(10, 3);
			glVertex2f(10, -10);
			glVertex2f(-10, -10);
			glEnd();
			glColor3f(0.439,0.501, 0.564);
			glLineWidth(3);
			glBegin(GL_LINES);
			glVertex2f(cx, cy);
			glVertex2f(z1, z2);
			glEnd();
			glColor3f(0.96,0.972,0.862);
			glBegin(GL_LINE_STRIP);
			glVertex2f(z1 - 0.1, z2 - 0.1);
			glVertex2f(z1 - 0.1, z2);
			glVertex2f(z1 + 0.1, z2);
			glVertex2f(z1 + 0.1, z2 - 0.1);
			glEnd();
			char str3[7] = "TIME :";
			int n3 = strlen(str3);
			glColor3f(0, 0, 0);
			if (initial_time<10)
				glColor3f(1, 0, 0);
			glRasterPos2f(-8, 7);
			for (int i = 0; i < n3; i++)
				glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str3[i]);
			
			_itoa_s(initial_time, tn, 10);
			int n4 = strlen(tn);
			glRasterPos2f(-6, 7);
			for (int i = 0; i < n4; i++)
				glutBitmapCharacter(GLUT_BITMAP_8_BY_13, tn[i]);
			glColor3f(1,0,0);
			glBegin(GL_POLYGON);
				glVertex2f(-1, 3);
				glVertex2f(-1, 4);
				glVertex2f(1, 4);
				glVertex2f(1, 3);
			glEnd();

			
			if (obj1.hit == 0)
			{
				obj1.display_block();
			}
			if (obj2.hit == 0)
			{
				obj2.display_block();
			}
			if (obj3.hit == 0)
			{
				obj3.display_block();
			}
			if (obj4.hit == 0)
			{
				obj4.display_block();
			}
			if (obj5.hit == 0)
			{
				obj5.display_block();
			}
			if (obj1.hit && obj2.hit && obj3.hit && obj4.hit && obj5.hit)
			{
				gameover_flag = 0;
				glClearColor(0.4, 0.0, 0.0,0);
				glClear(GL_COLOR_BUFFER_BIT);
				glColor3f(0.25, 1.0, 0.5);
				glRasterPos2f(-2, 0);
				int n4 = strlen(str4);
				for (int i = 0; i < n4; i++)
					glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str4[i]);

			}


		}
		if (initial_time == 0)
		{
			gameover_flag = 0;
			glClearColor(0.4, 0.0, 0.0,0.0);
			glClear(GL_COLOR_BUFFER_BIT);
			glColor3f(0.25, 1.0, 0.5);
			glRasterPos2f(-3, 0);
			int n = strlen(str8);
			for (int i = 0; i < n; i++)
				glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str8[i]);

		}

	}
	glFlush();
}
void help_func()
{
	char str4[60] = { "Your aim is to collect all the gold blocks." };
	char str5[60] = { "Collect the gold blocks by LEFT clicking the mouse." };
	char str6[60] = { "BE QUICK!!...The clock is ticking." };
	char str7[60] = { "PRESS 'S' TO START." };
	glClearColor(0.4, 0.0, 0.0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(255,215,0);
	glLineWidth(10);
	glBegin(GL_LINES);
	glVertex2f(-8, 7);
	glVertex2f(-8, 5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7, 7);
	glVertex2f(-7, 5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-8, 6);
	glVertex2f(-7, 6);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(-5, 7);
	glVertex2f(-6, 7);
	glVertex2f(-6, 5);
	glVertex2f(-5, 5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-6, 6);
	glVertex2f(-5, 6);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(-4, 7);
	glVertex2f(-4, 5);
	glVertex2f(-3, 5);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(-2, 5);
	glVertex2f(-2, 7);
	glVertex2f(-1, 7);
	glVertex2f(-1, 6);
	glVertex2f(-2, 6);
	glEnd();
	int n5 = strlen(str4);
	glColor3f(0, 1, 1);
	glRasterPos2f(-7, 0);
	for (int i = 0; i < n5; i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str4[i]);

	int n6 = strlen(str5);
	glRasterPos2f(-7, -1);
	for (int i = 0; i < n6; i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str5[i]);
	int n7 = strlen(str6);
	glRasterPos2f(-7, -2);
	for (int i = 0; i < n7; i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str6[i]);
	int n8 = strlen(str7);
	glRasterPos2f(-7, -4);
	for (int i = 0; i < n8; i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str7[i]);
	glPointSize(15);
	glColor3f(0, 1, 0);
	glBegin(GL_POINTS);
	glVertex2f(-8, 0);
	glVertex2f(-8, -1);
	glVertex2f(-8, -2);
	glEnd();

	glFlush();

}

void mouse(int b, int s, int x, int y)
{
	if (b == GLUT_LEFT_BUTTON && s == GLUT_DOWN && gameover_flag)
	{

		bflag = 1; //when left button is pressed


	}
}
void key(unsigned char key, int x, int y)
{
	if (key == 's' && gameover_flag )
	{
		startflag = 1;
		if (count == 0)
			glutTimerFunc(t1delay, update, 0);
		count = 1;
		if (tc == 0)
			time_fun(0);
	}
	else if (key == 'h' && gameover_flag)
	{
		help_func();
	}
}

int main(int argc, char **argv)
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(w, h);
	glutInitWindowPosition(300, 50);
	glutCreateWindow("Gold Digger");
	init();
	glutMouseFunc(mouse);
	glutKeyboardFunc(key);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();


}

