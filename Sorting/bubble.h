//
// Created on 3/26/20.
//

#ifndef USEFULALGORITHMS_BUBBLE_H
#define USEFULALGORITHMS_BUBBLE_H

#include <cstddef>

/**
 * Bubble Sort.
 * Popular but inefficient sorting algorithm. Works by swapping adjacent elements that are out of order <br/>
 * Worst case performance: O(n^2) <br/>
 * Worst case space complexity: O(1)
 * @tparam T Type of the array to sort (ie. int). Make sure that assigment, copy and < operators are implemented
 * @param array The array to sort. This array will be sorted
 * @param size The number of elements in the array
 * @return A copy of the sorted array
 * @throws std::invalid_argument if the size is 0
 */
template< typename T >
T* bubble_sort( T array[], const std::size_t size ) {
    if (size == 0) throw std::invalid_argument( "Size is null!" );

    for (std::size_t i = 0; i < size; i += 1) {
        for (std::size_t j = size - 1; j > i; j -= 1) {
            if (array[j] < array[j - 1]) {
                std::swap( array[j], array[j - 1] );
            }
        }
    }

    // Copy the array - Linear extra cost
    T* array_ = new T[ size ];
    std::copy( array, array + size, array_ );
    return array_;
}


/**
 * Bubble Sort.
 * Popular but inefficient sorting algorithm. Works by swapping adjacent elements that are out of order <br/>
 * Worst case performance: O(n^2) <br/>
 * Worst case space complexity: O(1)
 * @tparam T Type of the array to sort (ie. int). Make sure that assigment, copy and < operators are implemented
 * @param array The array to sort. This array will not be sorted
 * @param size The number of the elements in the array
 * @return The sorted array
 * @throws std::invalid_argument if the size is 0
 */
template< typename T >
T* bubble_sort( const T array[], const std::size_t size ) {
    if (size == 0) throw std::invalid_argument( "Size is null" );

    // Copy the array - Linear extra cost
    T* array_ = new T[ size ];
    std::copy( array, array + size, array_ );

    for (std::size_t i = 0; i < size; i += 1) {
        for (std::size_t j = size - 1; j > i; j -= 1) {
            if (array_[j] < array_[j - 1]) {
                std::swap( array_[j], array_[j - 1] );
            }
        }
    }

    return array_;
}

#endif //USEFULALGORITHMS_BUBBLE_H
