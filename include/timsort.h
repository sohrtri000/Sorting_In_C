#ifndef TIMSORT_H
#define TIMSORT_H

/**
 * @file timsort.h
 * @brief This file implements my version of an efficient imlimentation of timsort
 */

/**
 * @brief Sorts given array using timsort
 * 
 * This function implements Timsort, a sorting method that is a mashup
 * of the insertion and merge sort algorithms for the sake of space
 * and time efficiency, sorting partially in place and making use of CPU caches
 * 
 * @param arr A pointer to the array to sort
 * @param len The length of the array to sort
 */
void timsort(int *arr, int len);

#endif /* TIMSORT_H */
