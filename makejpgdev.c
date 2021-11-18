#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int b;
	char buf[100];
	srand(time(NULL));

	printf("How many images do you want to create?\n");
	scanf("%d", &b);

	for (;b>0;b--)
	{
		unsigned int a = rand();

		sprintf(buf, "convert -size 4000x4000 xc:gray +noise gaussian %x.jpg\n", a/2);
		printf("Creating random JPEG image %x.jpg\n", a/2);
		system(buf);
		printf("%x.jpg created\n", a/2);
	}

	printf("\nCalculating sha512 hash\n");
	system("sha512sum *.jpg > sha512index");
	printf("\n\nsha512 values stored as sha512index\n\n");
	return 0;
}
