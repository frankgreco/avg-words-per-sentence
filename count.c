#include <string.h>
#include <stdlib.h>
#include "count.h" 

//DEFINITIONS

void count_sentences(char* buffer, int* total_sentences, int* total_words) {

	char** sentences = malloc(sizeof(char*) * 2048);

	char* tmp_sentence;
	tmp_sentence = strtok(buffer, ".?!");
	while( tmp_sentence != NULL ) {
		sentences[(*total_sentences)++] = strcpy((char*)malloc(sizeof(char) * (strlen(tmp_sentence) + 1)), tmp_sentence);
		tmp_sentence = strtok(NULL, ".?!");
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