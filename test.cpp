#include "board.h"

//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include<crtdbg.h>

#include <iostream>
using namespace std;

int main()
{
  board b(3,4);
  b.solve();
  //_CrtDumpMemoryLeaks();
  return 0;
}