/**
 * @file Intersection_Approaches.h
 *
 * @brief For the intersection operation three approaches are available:
 *
 * 1. The simplest way: Two nested loops
 * 2. Data sorting (with QSort from the C lib) and a binary search
 * 3. Data sorting (with heap sort) and a binary search
 *
 * Plots with runtime comparisons are in the "Plots" folder.
 *
 * Summary of the tests: In normal cases (with datasets of a few hundred integers) the simplest way is faster, because
 * the sorting of the data needs most of the time. Only with a larger amount of data the approaches with a data sorting
 * are faster.
 *
 * @date 23.05.2022
 * @author Gyps
 */

#ifndef INTERSECTION_APPROACHES_H
#define INTERSECTION_APPROACHES_H ///< Include-Guard

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */



#include "Document_Word_List.h"



/**
 * @brief Determine intersections with a naive approach (Compare everyone with everyone -> to nested loops).
 *
 * Asserts:
 *      object != NULL
 *      data != NULL
 *      data_length = 0
 *
 * @param[in] object Document_Word_List
 * @param[in] data Data, that will be used for the intersection with the Document_Word_List object
 * @param[in] data_length Number of the elements in the data
 *
 * @return New dynamic object containing the intersection result to each subset of the word list
 */
extern struct Document_Word_List*
IntersectionApproach_TwoNestedLoops
(
    const struct Document_Word_List* const restrict object,
    const uint_fast32_t* const restrict data,
    const size_t data_length
);

/**
 * @brief Determine intersections with a previous ascending sort of the elements in the Document_Word_List. Afterwards
 * for the search process the binary search will be used.
 *
 * Algorithm for the sorting: QSort (https://en.wikipedia.org/wiki/Qsort)
 *
 * Asserts:
 *      object != NULL
 *      data != NULL
 *      data_length = 0
 *
 * @param[in] object Document_Word_List
 * @param[in] data Data, that will be used for the intersection with the Document_Word_List object
 * @param[in] data_length Number of the elements in the data
 *
 * @return New dynamic object containing the intersection result to each subset of the word list
 */
extern struct Document_Word_List*
IntersectionApproach_QSortAndBinarySearch
(
    const struct Document_Word_List* const restrict object,
    const uint_fast32_t* const restrict data,
    const size_t data_length
);

/**
 * @brief Determine intersections with a previous ascending sort of the elements in the Document_Word_List. Afterwards
 * for the search process the binary search will be used.
 *
 * Algorithm for the sorting: Heapsort (https://en.wikipedia.org/wiki/Heapsort)
 *
 * Asserts:
 *      object != NULL
 *      data != NULL
 *      data_length = 0
 *
 * @param[in] object Document_Word_List
 * @param[in] data Data, that will be used for the intersection with the Document_Word_List object
 * @param[in] data_length Number of the elements in the data
 *
 * @return New dynamic object containing the intersection result to each subset of the word list
 */
extern struct Document_Word_List*
IntersectionApproach_HeapSortAndBinarySearch
(
    const struct Document_Word_List* const restrict object,
    const uint_fast32_t* const restrict data,
    const size_t data_length
);

/**
 * @brief Determine intersections with a naive approach (Compare everyone with everyone -> to nested loops).
 *
 * ATTENTION: Here are two raw data arrays used. NO Document_Word_List as one of the input parameter.
 *
 * Asserts:
 *      data_1 != NULL
 *      data_1_length = 0
 *      data_2 != NULL
 *      data_2_length = 0
 *      char_offsets != NULL
 *      sentence_offsets != NULL
 *      word_offsets != NULL
 *
 * @param[in] data_1 Data, that will be used for the intersection with the second data array
 * @param[in] char_offsets Char offsets of the data focused on the source file, that was also the source for data_1
 * @param[in] sentence_offsets Sentence offsets of the data focused on the source file, that was also the source for data_1
 * @param[in] word_offset Offset of the words focused on the source file
 * @param[in] data_1_length Number of the elements in the first data array
 * @param[in] data_2 Data, that will be used for the intersection with the first data array
 * @param[in] data_2_length Number of the elements in the second data array
 *
 * @param[in] id_1 ID of the first data array
 * @param[in] id_2 ID of the second data array
 *
 * @return New dynamic object containing the intersection result
 */
extern struct Document_Word_List*
IntersectionApproach_TwoNestedLoopsWithTwoRawDataArrays
(
    const uint_fast32_t* const restrict data_1,
    const CHAR_OFFSET_TYPE* const restrict char_offsets,
    const SENTENCE_OFFSET_TYPE* const restrict sentence_offsets,
    const WORD_OFFSET_TYPE* const restrict word_offsets,
    const size_t data_1_length,
    const uint_fast32_t* const restrict data_2,
    const size_t data_2_length,

    const char* const restrict id_1,
    const char* const restrict id_2
);



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* INTERSECTION_APPROACHES_H */
