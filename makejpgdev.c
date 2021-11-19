/* makejpg_v0.1
 * Create random grayscale images for testing
 * 18 Nov 2021
 * Harzinn
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int b;
	char buf[100]; // buffer required for system call later
	srand(time(NULL)); // randomizer NOW outside of loop!...whoops

	printf("\nHow many images do you want to create?\n");
	scanf("%d", &b);
	printf("\n");

	for (;b>0;b--)
	{
		unsigned int a = rand();

		sprintf(buf, "convert -size 4000x4000 xc:gray +noise gaussian %x.jpg\n", a);
		printf("Creating random JPEG image %x.jpg\n", a);
		system(buf);
	}

	printf("\nCalculating sha512 hash\n");
	system("sha512sum *.jpg > sha512index");
	printf("sha512 values stored as sha512index\n\n");
	return 0;
}
