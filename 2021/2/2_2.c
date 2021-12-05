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

  int xpos = 0;
  int ypos = 0;
  int aim = 0;

	while (fgets(line, MAX_LEN, fp)) {
		int actionIdx = strcspn(line, " ");
    int numStartIdx = actionIdx+1;
    line[strcspn(line, "\n")] = 0;

		int depth = atoi(line+numStartIdx);

    switch (line[0]) {
      case 'f':
        xpos += depth;
        ypos += aim * depth;
        break;
      case 'd':
        aim += depth;
        break;
      case 'u':
        aim -= depth;
    }
	}

	printf("%d\n", xpos * ypos);
	return 0;
}
