#include <stdio.h>

void function()
{
	static int count = 3;

	printf("count value: %d\n", count++);
}

int main()
{
	function();
	function();
	function();
	return (0);
}
