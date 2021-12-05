#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 128
#define NUM_INPUTS 2000

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Pass the filename as an argument\n");
		return 1;
	}

	FILE *fp;
	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror("Failed: ");
		return 1;
	}

	char line[MAX_LEN];

  int forward = 0;
  int down = 0;

	while (fgets(line, MAX_LEN, fp)) {
		int actionIdx = strcspn(line, " ");
    int numStartIdx = actionIdx+1;
    line[strcspn(line, "\n")] = 0;

		int depth = atoi(line+numStartIdx);

    switch (line[0]) {
      case 'f':
        forward += depth;
        break;
      case 'd':
        down += depth;
        break;
      case 'u':
        down -= depth;
    }
	}

	printf("%d\n", down * forward);
	return 0;
}
