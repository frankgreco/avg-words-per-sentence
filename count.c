#include <string.h>
#include <stdlib.h>
#include "count.h" 

//DEFINITIONS

void count_sentences(char* buffer, int* total_sentences, int* total_words) {

	//Current number of spaces we have allocated in our array or char arrays.
	int cur_allocated = 100;
	//Allocating memory for an array of char arrays. Initally guessing that 100 char arrays will be needed
	char** sentences = malloc(sizeof(char*) * cur_allocated);
	//Points to the current sentence
	char* tmp_sentence;
	//Attempt to grab the first sentece from the buffer.
	tmp_sentence = strtok(buffer, ".?!");

	while( tmp_sentence != NULL ) {
		if( (*total_sentences + 1) > cur_allocated ) {
			//double the size
			cur_allocated *= 2;
			//grow the size of the array
			sentences = realloc(sentences, sizeof(char*) * cur_allocated);
		}
		sentences[(*total_sentences)++] = strcpy((char*)malloc(sizeof(char) * (strlen(tmp_sentence) + 1)), tmp_sentence);
		tmp_sentence = strtok(NULL, ".?!");
	}

	//done reading from buffer. Shrink the array if necessary.
	if(*total_sentences > cur_allocated) {
		sentences = realloc(sentences, sizeof(char*) * *total_sentences);
	}

	int i = 0;
	while( *total_sentences > i ) {
		count_words(sentences[i], total_words);
		free(sentences[i]);
		sentences[i++] = NULL;
	}

	free(sentences);
	*sentences = NULL;
}

void count_words(char* sentence, int* total_words) {
	char* tmp_word;
	tmp_word = strtok(sentence, " ");
	while( tmp_word != NULL ) {
		++(*total_words);
		tmp_word = strtok(NULL, " ");
	}
}