#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *DevUrandom= fopen("/dev/urandom", "r");
	int byyyte = getc(DevUrandom);
	int length = 40;
	if (argc > 1) {
		length = atoi(argv[1]);
	}
	int byyytes[length];

	for (; ;) {
		int i = 0;
		for (; ;) {
			if (byyyte >= 32 && byyyte <= 126){ /* Printable ASCII */
				byyytes[i++] = byyyte;
			}
			if (i == length) {
				i = 0;
				for (int j = 0; j < length; j++) {
					fprintf(stdout, "%c", byyytes[j]);
				}
				fprintf(stdout, "\n");	
				break;
			}
			byyyte = getc(DevUrandom);
		}
	}
return 0;
}
