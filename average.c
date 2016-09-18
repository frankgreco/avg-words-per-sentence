#include "average.h"
#include "count.h"

//DEFINITIONS

void compute_average(char* buffer, int* num_sentences, int* num_words) {
	count_sentences(buffer, num_sentences, num_words);
}

double do_average(int num_words, int num_sentences) {
	return ( (double)num_words ) / num_sentences;
}