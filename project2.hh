///////////////////////////////////////////////////////////////////////////////
// project2.hh
//
// The three algorithms specified in the project 1 requirements
// document, plus helper functions.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <vector>


// Convenient typedef for a vector of strings.
typedef std::vector<std::string> string_vector;

// Load words from the file at the given path. The words vector is
// cleared, and then each word from the file is added to the
// vector. Returns true on success or fale on I/O error.
bool load_words(string_vector& words, const std::string& path);

// Randomize the order of all items in the list
// Should always return true.
void randomize_list(string_vector & strings);

// Sort the given list using the merge sort algorithm.
// This method is simply a helper to make the initial 
// call the recursive merge_sort() method below that requires
// first and last indexes for sorting range
void mergesort(string_vector & strings);

// Partition a portion of a list (from start to end)
// using the Hoare Partition algorithm 
int hoare_partition(string_vector & strings, int start, int end);

// Sort the given list using the quicksort algorithm.
// This method is simply a helper to make the initial 
// call the recursive merge_sort() method below that requires
// first and last indexes for sorting range
void quicksort(string_vector & strings);

