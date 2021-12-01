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

	int nums [NUM_INPUTS];

	char line[MAX_LEN];
	int i = 0;
	while (fgets(line, MAX_LEN, fp)) {
		line[strcspn(line, "\n")] = 0;
		int depth = atoi(line);
		nums[i] = depth;
		i++;
	}

	int increases = -1;

	for (int i = 0; i < NUM_INPUTS - 2; i++) {
		int window0 = nums[i] + nums[i+1] + nums[i+2];
		int window1 = nums[i+1] + nums[i+2] + nums[i+3];
		if (window1 > window0) {
			increases++;
		}
	}

	printf("Increases: %d\n", increases);
	return 0;
}
