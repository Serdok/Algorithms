//
// Created on 3/26/20.
//

#ifndef USEFULALGORITHMS_HEAP_H
#define USEFULALGORITHMS_HEAP_H

#include <cstddef>

/**
 * Create a max-heap tree from an unsorted array
 * @tparam T Type of the array to modify (ie. int). Make sure that assigment, copy and < operators are implemented
 * @param array The array to heapify
 * @param size The number of elements in the array
 * @throws std::invalid_argument if the size is null
 */
template< typename T >
void build_max_heap( T array[], std::size_t size );

/**
 * Ensures that the max-heap tree rooted at index is correctly formed.
 * @tparam T The type of the max-heap tree (ie. int). Make sure that assigment, copy and < operators are implemented
 * @param root_index The index of the root of the tree
 * @param tree_array The max-heap tree
 * @param heap_size The number of elements in the tree
 * @throws std::invalid_argument if the heap_size is null
 */
template< typename T >
void max_heapify( std::size_t root_index, T* tree_array, std::size_t heap_size );

/**
 * Heap sort.
 * Efficient sorting algorithm. Works by creating a max-heap tree from the unordered values <br/>
 * Worst case performance: O(n*log(n)) <br/>
 * Worst case space complexity: O(1)
 * @tparam T The type of the array to sort (ie. int). Make sure that assigment, copy and < operators are implemented
 * @param array The array to sort. This array will be sorted
 * @param size The number of elements in the array
 * @return A copy of the sorted array
 * @throws std::invalid_argument if the size is null
 */
template< typename T >
T* heap_sort( T array[], std::size_t size ) {
    if (size == 0) throw std::invalid_argument( "Size is null" );

    // Build heap
    build_max_heap( array, size );

    for (std::size_t i = size - 1; i > 0; i -= 1) {
        // Move root at the end
        std::swap( array[0], array[i] );

        // Heapify the remaining array, root is at the front
        max_heapify( 0, array, i );
    }

    // Copy the array - Linear extra cost
    T* array_ = new T[ size ];
    std::copy( array, array + size, array_ );
    return array_;
}

/**
 * Heap sort.
 * Efficient sorting algorithm. Works by creating a max-heap tree from the unordered values <br/>
 * Worst case performance: O(n*log(n)) <br/>
 * Worst case space complexity: O(1)
 * @tparam T The type of the array to sort (ie. int). Make sure that assigment, copy and < operators are implemented
 * @param array The array to sort. This array will not be modified
 * @param size The number of elements in the array
 * @return The sorted array
 * @throws std::invalid_argument if the size is null
 */
template< typename T >
T* heap_sort( const T array[], std::size_t size ) {
    if (size == 0) throw std::invalid_argument( "Size is null" );

    // Copy the array - Linear extra cost
    T* array_ = new T[ size ];
    std::copy( array, array + size, array_ );

    // Build heap
    build_max_heap( array_, size );

    for (std::size_t i = size - 1; i > 0; i -= 1) {
        // Move root at the end
        std::swap( array_[0], array_[i] );

        // Heapify the remaining array, root is at the front
        max_heapify( 0, array_, i );
    }

    return array_;
}


// Functions called inside heap_sort()

/**
 * Get the position of the parent node in the max-heap tree_array
 * @param index The index of the current node
 * @return The position of the parent node in the max-heap tree_array
 */
std::size_t getParentIndex( std::size_t index ) {
    return (index - 1)/2;
}

/**
 * Get the position of the left child node in the max-heap tree_array
 * @param index The index of the current node
 * @return The position of the left child node in the max-heap tree_array
 * @warning The return value will be out of bounds if the current node does not have a left child
 */
std::size_t getLeftChildIndex( std::size_t index ) {
    return 2*index + 1;
}

/**
 * Get the position of the right child node in the max-heap tree_array
 * @param index The index of the current node
 * @return The position of the right child node in the max-heap tree_array
 * @warning The return value will be out of bounds if the current node does not have a right child
 */
std::size_t getRightChildIndex( std::size_t index ) {
    return 2*index + 2;
}

template< typename T >
void build_max_heap( T array[], std::size_t size ) {
    for (std::size_t i = size/2 - 1; i > 0; i -= 1) {
        max_heapify( i, array, size );
    }

    // When i == 0 in the loop, i - 1 goes to MAX_UNSIGNED_LONG...
    max_heapify( 0, array, size );
}

template< typename T >
void max_heapify( std::size_t root_index, T* tree_array, std::size_t heap_size ) {
    if (heap_size == 0) throw std::invalid_argument( "Heap size is null" );

    auto largest = root_index;
    auto left = getLeftChildIndex( root_index );
    auto right = getRightChildIndex( root_index );

    if (left < heap_size && tree_array[largest] < tree_array[left]) {
        // Left child greater than current value
        largest = left;
    }
    if (right < heap_size && tree_array[largest] < tree_array[right]) {
        // Right child greater than current value, higher priority over left child
        largest = right;
    }

    if (largest != root_index) {
        std::swap( tree_array[root_index], tree_array[largest] );
        max_heapify( largest, tree_array, heap_size );
    }
}



#endif //USEFULALGORITHMS_HEAP_H
