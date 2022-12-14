#include "board.h"

#include <iostream>
using namespace std;

int main()
{
  board a(5,5);
  a.solve(500);
  
  /*board a(5,5);
  for (int i = 10; i <= 100; i+=10) {
    a.solve(i);
  }
  board b(10,10);
  for (int i = 10; i <= 100; i+=10) {
    b.solve(i);
  }
  board c(15,15);
  for (int i = 10; i <= 100; i+=10) {
    c.solve(i);
  }
  board d(20,20);
  for (int i = 10; i <= 100; i+=10) {
    d.solve(i);
  }
  board e(25,25);
  for (int i = 10; i <= 100; i+=10) {
    e.solve(i);
  }*/
  
  return 0;
}