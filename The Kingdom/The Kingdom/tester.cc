/// \file
/// Main program to run test suites
#include <cppunit/TextTestRunner.h>
using namespace CppUnit;

#include "IntVectorTest.h"

/// \fn	int main()
///
/// \brief	Main entry-point for this application
///
/// \author	Jordan Pickett
/// \date	11/2/2017
///
/// \return	Exit-code for the process - 0 for success, else an error code.
int main()
{
   TextTestRunner runner;
   runner.addTest(IntVectorTest::suite());
   runner.run();

   return 0;
}
