#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 128

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

	int increases = -1;
	int last = 0;

	char line[MAX_LEN];
	while (fgets(line, MAX_LEN, fp)) {
		line[strcspn(line, "\n")] = 0;
		int depth = atoi(line);
		if (depth > last) {
			increases++;
		}
		last = depth;
	}
	printf("Increases: %d\n", increases);
	return 0;
}
