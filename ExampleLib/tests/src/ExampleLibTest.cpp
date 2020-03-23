#include <cassert>
#include <iostream>
#include "ExampleLib.hpp"

void testBasic()
{
  ExampleLib l;
  assert("Result is 5" == l.gibFuenf());
}

void testAdvanced()
{
  ExampleLib l;
  assert("Result is 5" == l.gibFuenf());
}

int main(int, char**)
{
  testBasic();
  testAdvanced();
}
