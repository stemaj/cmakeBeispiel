#include "../ExampleLib.hpp"
#include <components/text/sprintf.hpp>

int ExampleLib::gibFive() const
{
  return 5;
}

std::string ExampleLib::gibFuenf() const
{
  return text::sprintf("Result is %d", gibFive());
}
