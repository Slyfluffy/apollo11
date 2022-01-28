/**********************************************************************
 * GL Demo
 * Just a simple program to demonstrate how to create an Open GL window, 
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(const Point& ptUpperRight) :
          angle(0.0),
          ptLM(ptUpperRight.getX() / 2.0, ptUpperRight.getY() / 2.0),
          ground(ptUpperRight)
   { 
       // generate 50 phases for 50 stars
       for (int i = 0; i < 50; i++) {
           phase[i] = random(0, 255);
    }
       // set points for the stars
       for (int i = 0; i < 50; i++) {
           // keep trying until the star is in the sky
           do {
               ptStar[i] = * new Point(random(0, 400), random(0, 400));
           } while (ground.getElevation(ptStar[i]) < 1);
       }
      
   }

   // this is just for test purposes.  Don't make member variables public!
   Point ptLM;           // location of the LM on the screen
   Point ptUpperRight;   // size of the screen
   double angle;         // angle the LM is pointing
   unsigned char phase[50];  // phase of the star's blinking
   Ground ground;
   Point ptStar[50];
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
    ogstream gout;

    // the first step is to cast the void pointer into a game object. This
    // is the first step of every single callback function in OpenGL. 
    Demo* pDemo = (Demo*)p;

    // move the ship around
    if (pUI->isRight())
        pDemo->angle -= 0.1;
    if (pUI->isLeft())
        pDemo->angle += 0.1;
    if (pUI->isUp())
        pDemo->ptLM.addY(-1.0);
    if (pUI->isDown())
        pDemo->ptLM.addY(1.0);

    // draw the ground
    pDemo->ground.draw(gout);

    // draw the lander and its flames
    gout.drawLander(pDemo->ptLM /*position*/, pDemo->angle /*angle*/);
    gout.drawLanderFlames(pDemo->ptLM, pDemo->angle, /*angle*/
        pUI->isDown(), pUI->isLeft(), pUI->isRight());

    // put some text on the screen
    gout.setPosition(Point(20.0, 380.0));
    
    // TODO: Line these up somehow ???
    gout << "Fuel:      " << 0 << " lbs" << "\n"
         << "Altitude:  " << round(pDemo->ground.getElevation(pDemo->ptLM)) << " meters\n"
         << "Speed:   " << 0 << " m/s\n";

    // draw our little stars
    for (int i = 0; i < 50; i++) {
        pDemo->phase[i]++;
        gout.drawStar(pDemo->ptStar[i], pDemo->phase[i]);
    }
    
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance, 
   _In_opt_ HINSTANCE hPrevInstance, 
   _In_ PWSTR pCmdLine, 
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char ** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Point ptUpperRight(400.0, 400.0);
   Interface ui(0, NULL, 
                "Open GL Demo", 
                 ptUpperRight);

   // Initialize the game class
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);             

   return 0;
}
