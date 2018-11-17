///////////////////////////////////////////////////////////////////////////////
// project2_test.cc
//
// Unit tests for project2.hh
//
///////////////////////////////////////////////////////////////////////////////

#include "rubrictest.hh"

#include "project2.hh"

#include <algorithm>
#include <random>
#include <sstream>
#include <vector>

using namespace std;

int main() {


  string_vector test0 = {  };

  string_vector test1 = { "titans" };

  string_vector test8 = {
    "horse", "mouse", "dog", "rat", "cat", "cow", "pig", "donkey" };

  string_vector words_txt;
  bool load_words_ok = load_words(words_txt, "words.txt");


  Rubric rubric;

  rubric.criterion("mergesort(...)", 3,
		   [&]() {
             string_vector orig1a = test1;
             string_vector orig1b = test1;
			 mergesort(orig1a);
			 sort(orig1b.begin(), orig1b.end());
		     TEST_TRUE("true: 1 word", orig1a == orig1b);

             string_vector orig8a = test8;
			 mergesort(orig8a);
             string_vector orig8b = test8;
			 sort(orig8b.begin(), orig8b.end());
		     TEST_TRUE("true: 8 words", orig8a == orig8b);

			 string_vector n_words(words_txt.begin(), words_txt.begin() + 10000);
             string_vector origa = n_words;
			 mergesort(origa);
             string_vector origb = n_words;
			 sort(origb.begin(), origb.end());
		     TEST_TRUE("true: 10,000 words", origa == origb);
		    });

  rubric.criterion("partition(...)", 2,
		   [&]() {
             string_vector orig1a = test1;
			 int p = hoare_partition(orig1a, 0, 0);
		     TEST_TRUE("true: 1 word", p == 0);

             string_vector orig8a = test8;
			 p = hoare_partition(orig8a, 0, 7);
		     TEST_TRUE("true: 8 words", p == 4);
		   });


  rubric.criterion("quicksort(...)", 3,
		   [&]() {
             string_vector orig1a = test1;
             string_vector orig1b = test1;
			 quicksort(orig1a);

			 sort(orig1b.begin(), orig1b.end());
		     TEST_TRUE("true: 1 word", orig1a == orig1b);

             string_vector orig8a = test8;
			 quicksort(orig8a);
             string_vector orig8b = test8;
			 sort(orig8b.begin(), orig8b.end());
		     TEST_TRUE("true: 8 words", orig8a == orig8b);

			 string_vector n_words(words_txt.begin(), words_txt.begin() + 10000);
             string_vector origa = n_words;
			 quicksort(origa);
             string_vector origb = n_words;
			 sort(origb.begin(), origb.end());
		     TEST_TRUE("true: 10,000 words", origa == origb);
		   });

  return rubric.run();
}
