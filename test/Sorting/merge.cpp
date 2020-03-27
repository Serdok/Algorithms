//
// Created on 3/26/20.
//

#include "gtest/gtest.h"

#include "merge.h"

TEST( MergeSort, HandleInvalidSize ) {
    int array[] = { 8, 3, 5, 1, 6, 4, 9, 0, 2, 7 };
    
    ASSERT_THROW( merge_sort( array, 3, 1 ), std::invalid_argument );
    ASSERT_THROW( merge( array, 3, 1, 0 ), std::invalid_argument );
    ASSERT_THROW( merge( array, 4, 1, 7 ), std::invalid_argument );
    ASSERT_THROW( merge( array, 4, 6, 1 ), std::invalid_argument );
}

TEST( MergeSort, CorrectPartialMerging ) {
    int array[] = { 3, 8, 1, 5, 6, 4, 9, 0, 2, 7 };
    std::size_t start = 0, half = 2, end = 4, size = 10;
    
    int expected[] = { 1, 3, 5, 8, 6, 4, 9, 0, 2, 7 };
    ASSERT_NO_THROW( merge( array, start, half, end ) );
    for (std::size_t i = 0; i < size; i += 1) {
        EXPECT_EQ( array[i], expected[i] ) << "Failed at index " << i;
    }
}

TEST( MergeSort, CorrectMerging ) {
    int array[] = { 1, 3, 6, 8, 9, 0, 2, 4, 5, 7 };
    std::size_t start = 0, half = 5, end = 10, size = 10;

    int expected[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    ASSERT_NO_THROW( merge( array, start, half, end ) );
    for (std::size_t i = 0; i < size; i += 1) {
        EXPECT_EQ( array[i], expected[i] ) << "Failed at index " << i;
    }
}

TEST( MergeSort, CorrectPartialSort ) {
    int array[] = { 8, 3, 5, 1, 6, 4, 9, 0, 2, 7 };
    std::size_t start = 1, end = 6, size = 10;

    int sorted[] = { 8, 1, 3, 4, 5, 6, 9, 0, 2, 7 };

    ASSERT_NO_THROW( merge_sort( array, start, end ) );
    for (std::size_t i = 0; i < size; i += 1) {
        EXPECT_EQ( array[i], sorted[i] ) << "Failed at index " << i;
    }
}

TEST( MergeSort, CorrectExplicitSort ) {
    int array[] = { 8, 3, 5, 1, 6, 4, 9, 0, 2, 7 };
    std::size_t start = 0, end = 10, size = 10;

    int sorted[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    ASSERT_NO_THROW( merge_sort( array, start, end ) );
    for (std::size_t i = 0; i < size; i += 1) {
        EXPECT_EQ( array[i], sorted[i] ) << "Failed at index " << i;
    }
}

TEST( MergeSort, CorrectSortInPlace ) {
    int array[] = { 8, 3, 5, 1, 6, 4, 9, 0, 2, 7 };
    std::size_t size = 10;

    int sorted[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    ASSERT_NO_THROW( merge_sort( array, size ) );
    for (std::size_t i = 0; i < size; i += 1) {
        EXPECT_EQ( array[i], sorted[i] ) << "Failed at index " << i;
    }
}

TEST( MergeSort, CorrectSortAndCopy ) {
    int array[] = { 8, 3, 5, 1, 6, 4, 9, 0, 2, 7 };
    std::size_t size = 10;

    int sorted[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int* result;
    ASSERT_NO_THROW( result = merge_sort( array, size ) );
    for (std::size_t i = 0; i < size; i += 1) {
        EXPECT_EQ( result[i], sorted[i] ) << "Failed at index " << i;
    }
}

TEST( MergeSort, CorrectCopyAndNoChangeInPlace ) {
    const int array[] = { 8, 3, 5, 1, 6, 4, 9, 0, 2, 7 };
    std::size_t size = 10;

    int array_[] = { 8, 3, 5, 1, 6, 4, 9, 0, 2, 7 };
    int sorted[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int* result;
    ASSERT_NO_THROW( result = merge_sort( array, size ) );
    for (std::size_t i = 0; i < size; i += 1) {
        EXPECT_EQ( array[i], array_[i] ) << "No change - Failed at index " << i;
    }
    for (std::size_t i = 0; i < size; i += 1) {
        EXPECT_EQ( result[i], sorted[i] ) << "Sorting - Failed at index " << i;
    }
}

TEST( MergeSort, CorrectCopyAndNoChangeInPlaceWithCast ) {
    int array[] = { 8, 3, 5, 1, 6, 4, 9, 0, 2, 7 };
    std::size_t size = 10;

    int array_[] = { 8, 3, 5, 1, 6, 4, 9, 0, 2, 7 };
    int sorted[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int* result;
    ASSERT_NO_THROW( result = merge_sort( const_cast<const int*>(array), size ) );
    for (std::size_t i = 0; i < size; i += 1) {
        EXPECT_EQ( array[i], array_[i] ) << "No change - Failed at index " << i;
    }
    for (std::size_t i = 0; i < size; i += 1) {
        EXPECT_EQ( result[i], sorted[i] ) << "Sorting - Failed at index " << i;
    }
}

int main( int argc, char* argv[] ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}