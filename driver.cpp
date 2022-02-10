/***************************************
* APOLLO 11 SIMULATOR
* Journey Curtis and Olivia Seymour
*
* Simulator for the Apollo 11 mission.
* Use arrow keys to rotate and apply
* thrusters. Space to reset.
***************************************/

#include "simulator.h"
#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
using namespace std;

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
   Thrust t;

   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL.
   Simulator *sim = (Simulator*)p;

   // move the ship around
   sim->input(*pUI);
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
   Simulator sim(ptUpperRight);

   // set everything into action
   ui.run(callBack, &sim);

   return 0;
}
