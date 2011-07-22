#include <iostream>
#include <stdlib.h>
using namespace std;
#include "debug.h"

int main()
{
	Debug::print("hello world!");
   printf("platform is %s\n",PLATFORM_NAME);
	return 0;
}


