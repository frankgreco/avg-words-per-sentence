#include <string.h>
#include <stdlib.h>
#include "count.h" 

//DEFINITIONS

void count_sentences(char* buffer, int* total_sentences, int* total_words) {

	char* tmp_sentence;
	char* save_sentence;
	tmp_sentence = strtok_r(buffer, ".?!", &save_sentence);

	while( tmp_sentence != NULL ) {
		++(*total_sentences);
		count_words(tmp_sentence, total_words);
		tmp_sentence = strtok_r(NULL, ".?!", &save_sentence);
	}
}

void count_words(char* sentence, int* total_words) {
	char* tmp_word;
	char* save_word;
	tmp_word = strtok_r(sentence, " ", &save_word);
	while( tmp_word != NULL ) {
		++(*total_words);
		tmp_word = strtok_r(NULL, " ", &save_word);
	}
}