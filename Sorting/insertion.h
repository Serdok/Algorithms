//
// Created on 3/26/20.
//

#ifndef USEFULALGORITHMS_INSERTION_H
#define USEFULALGORITHMS_INSERTION_H

#include <cstddef>

/**
 * Insertion Sort. A simple, stable, in-place sorting algorithm efficient for small arrays <br/>
 * Worst case performance: O(n^2) <br/>
 * Worst case space complexity: O(1)
 * @tparam T Type of the array to sort (ie. int). Make sure that assigment, copy and < operators are implemented
 * @param array The array to sort. This array will be sorted
 * @param size The number of elements in the array
 * @return A copy of the sorted array
 * @throws std::invalid_argument if the size is 0
 */
template< typename T >
T* insertion_sort( T array[], std::size_t size ) {
    if (size == 0) throw std::invalid_argument( "Size is null" );

    std::size_t i = 1;
    while (i < size) {
        std::size_t j = i;
        while (j > 0 && array[j] < array[j - 1]) {
            std::swap( array[j], array[j - 1] );
            j -= 1;
        }
        i += 1;
    }

    // Copy the array - Linear extra cost
    T* array_ = new T[ size ];
    std::copy( array, array + size, array_ );
    return array_;
}

/**
 * Insertion Sort. A simple, stable, in-place sorting algorithm efficient for small arrays <br/>
 * Worst case performance: O(n^2) <br/>
 * Worst case space complexity: O(1)
 * @tparam T Type of the array to sort (ie. int). Make sure that assigment, copy and < operators are implemented
 * @param array The array to sort. This array will not be sorted
 * @param size The number of elements in the array
 * @return The sorted array
 * @throws std::invalid_argument if the size is 0
 */
template< typename T >
T* insertion_sort( const T array[], std::size_t size ) {
    if (size == 0) throw std::invalid_argument( "Size is null" );

    // Copy the array - Linear extra cost
    T* array_ = new T[ size ];
    std::copy( array, array + size, array_ );

    std::size_t i = 1;
    while (i < size) {
        std::size_t j = i;
        while (j > 0 && array_[j] < array_[j - 1]) {
            std::swap( array_[j], array_[j - 1] );
            j -= 1;
        }
        i += 1;
    }

    return array_;
}

#endif //USEFULALGORITHMS_INSERTION_H
