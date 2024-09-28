#ifndef MERGE_SORT_H
#define MERGE_SORT_H

/**
 * @file merge_sort.h
 * @brief This file implements my version of Merge Sort
 */

/**
 * @brief Merges two sorted arrays together into one sorted array
 * 
 * This function implements merge, an important function for merge sort,
 * combining two sorted arrays together into one larger sorted array. This is
 * the conquer part of Merge Sort
 * 
 * @param arr1 A pointer to the first array to merge
 * @param len1 The length of the first array to merge
 * @param arr2 A pointer to the second array to merge
 * @param len2 The length of the second array to merge
 * @return A pointer to the merged array
 */
int *merge(int *arr1, int len1, int *arr2, int len2);

/**
 * @brief Sorts given array using Merge Sort
 * 
 * This function implements Merge Sort, a very popular
 * divide and conquer, recursive algorithm to sort
 * arrays
 * 
 * @param arr A pointer to the array to sort
 * @param len The length of the array to sort
 */
void merge_sort(int *arr, int len);

#endif /* MERGE_SORT_H */
