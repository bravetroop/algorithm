#include <stdio.h>

extern int net_is_connected(char* ifr_name);

int main(int argc, char* argv[])
{
	int connect_status = -1;

	connect_status = net_is_connected("eth0");

	if(0 == connect_status)
	{
		printf("net connect success\n");
	}
	else
	{
		printf("net disconnect, %d", connect_status);
	}

	return 0;
}
