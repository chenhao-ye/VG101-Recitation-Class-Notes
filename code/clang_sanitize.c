#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int main()
{
	char hey[4] = "Hey!";
	char something_else[30] = " You shouldn't see this!\n";
	printf("%s", hey);
	printf("%p\n", (void*)hey);
	printf("%p\n", (void*)something_else);
	return 0;
}
