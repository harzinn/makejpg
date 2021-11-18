#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int b;
	char buf[100];

	printf("How many images do you want to create?\n");
	scanf("%d", &b);

	for (;b>0;b--)
	{
		srand(time(NULL));
		usleep(500000);
		unsigned int a = rand();

		sprintf(buf, "convert -size 4000x4000 xc:gray +noise gaussian %x.jpg\n", a);
		printf("Creating random JPEG image %x.jpg\n", a);
		system(buf);
		printf("%x.jpg created\n", a);
	}

	printf("\nCalculating sha512 hash\n");
	system("sha512sum *.jpg > sha512index");
	printf("\n\nsha512 values stored as sha512index\n\n");
	return 0;
}
