#include <stdlib.h>
#include <stdio.h>
#include "average.h"

int main(int argc, char* argv[]){

	if(argc != 2) {
		printf("Please enter exactly one program argument in the form [filename].[ext]\n");
		exit(1);
	}

    int num_sentences = 0;
    int num_words = 0;

    char* buffer = 0;
	long length;
	FILE* file = fopen (argv[1], "rb");

	if (file) {
	  fseek(file, 0, SEEK_END);
	  length = ftell(file);
	  fseek(file, 0, SEEK_SET);
	  buffer = malloc(length);
	  if(buffer) {
	    fread(buffer, 1, length, file);
	  }
	  fclose (file);
	} else {
		printf("There was an error processing your file...\nMake sure your program argument is in the form [filename].[ext]\n");
		exit(1);
	}

	if (buffer) {
		compute_average(buffer, &num_sentences, &num_words);

		printf("Your body of text contains %d words and %d sentences resulting in an average of %.2f words per sentence\n", num_words, num_sentences, do_average(num_words, num_sentences));
	}

	return 0;

}
