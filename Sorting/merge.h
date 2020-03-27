//
// Created on 3/26/20.
//

#ifndef USEFULALGORITHMS_MERGE_H
#define USEFULALGORITHMS_MERGE_H

/**
 * Merge two sub arrays into a sorted one. The ranges for those sub arrays are [start, pivot) and [pivot, end)
 * @tparam T Type of the array to merge (ie. int). make sure that assigment, copy and < operators are implemented
 * @param array The original array which will be modified
 * @param start The index of the first sub array to merge
 * @param pivot The pivot index, marking the end of the first array and the beginning of the second one
 * @param end The index of one past the last element of the second array
 */
template< typename T >
void merge( T* array, std::size_t start, std::size_t pivot, std::size_t end );

/**
 * Merge Sort. An efficient sorting algorithm using divide and conquer <br/>
 * Worst case performance: O(n*log(n)) <br/>
 * Worst case space complexity: O(n) <br/>
 * This implementation sorts array in the range [start, end)
 * @tparam T Type of the array to sort (ie. int). Make sure that assigment, copy and < operators are implemented
 * @param array The array to sort. This array will be sorted
 * @param start The index of the first element to sort
 * @param end The index of the last element to sort
 */
template< typename T >
void merge_sort( T array[], std::size_t start, std::size_t end );

/**
 * Merge Sort. An efficient sorting algorithm using divide and conquer <br/>
 * Worst case performance: O(n*log(n)) <br/>
 * Worst case space complexity: O(n) <br/>
 * @tparam T Type of the array to sort (ie. int). Make sure that assigment, copy and < operators are implemented
 * @param array The array to sort. This array will be sorted
 * @param size The number of elements in the array
 * @return A copy of the sorted array
 */
template< typename T >
T* merge_sort( T array[], std::size_t size ) {
    merge_sort( array, 0, size );

    T* array_ = new T[ size ];
    std::copy( array, array + size, array_ );
    return array_;
}

/**
 * Merge Sort. An efficient sorting algorithm using divide and conquer <br/>
 * Worst case performance: O(n*log(n)) <br/>
 * Worst case space complexity: O(n) <br/>
 * @tparam T Type of the array to sort (ie. int). Make sure that assigment, copy and < operators are implemented
 * @param array The array to sort. This array will not be sorted
 * @param size The number of elements in the array
 * @return The sorted array
 */
template< typename T >
T* merge_sort( const T array[], std::size_t size ) {
    T* array_ = new T[ size ];
    std::copy( array, array + size, array_ );

    merge_sort( array_, 0, size );

    return array_;
}

// Functions used inside merge_sort()

template< typename T >
void merge_sort( T array[], std::size_t start, std::size_t end ) {
    if (end < start) throw std::invalid_argument( "end < start!" );

    // End of recursion - size is 1 so the element is sorted
    if (end - start == 1) return;

    std::size_t half = (start + end)/2;
    merge_sort( array, start, half );
    merge_sort( array, half, end );
    merge( array, start, half, end );
}

template< typename T >
void merge( T* array, std::size_t start, std::size_t pivot, std::size_t end ) {
    // Avoid 0 sized work arrays
    if (end <= start) throw std::invalid_argument( "end <= start" );
    if (pivot <= start) throw std::invalid_argument( "pivot <= start" );

    std::size_t size_1 = pivot - start;
    std::size_t size_2 = end - pivot;

    T left[ size_1 ], right[ size_2 ];
    std::copy( array + start, array + (start + size_1), left );
    std::copy( array + pivot, array + (pivot + size_2), right );

    std::size_t i = 0, j = 0, index = start;
    while (true) {
        if (i == size_1 || j == size_2) break;

        if (left[i] < right[j]) {
            array[index] = left[i];
            i += 1;
        } else {
            array[index] = right[j];
            j += 1;
        }
        index += 1;
    }
    // Either i == size_1 or j == size_2 at that point

    while (i != size_1) {
        // Right array emptied, but we still have elements in the left array
        array[index] = left[i];
        index += 1; i += 1;
    }

    while (j != size_2) {
        // Left array emptied, but we still have elements in the right array
        array[index] = right[j];
        index += 1; j += 1;
    }
}

#endif //USEFULALGORITHMS_MERGE_H
