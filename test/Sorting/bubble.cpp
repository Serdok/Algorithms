//
// Created on 3/26/20.
//

#include "gtest/gtest.h"

#include "bubble.h"

// Testing bubble sort
TEST( BubbleSort, HandleInvalidSize ) {
    int array[] = { 8, 3, 5, 1, 6, 4, 9, 0, 2, 7 };

    ASSERT_THROW( bubble_sort( array, 0 ), std::invalid_argument );
}

TEST( BubbleSort, CorrectSortInPlace ) {
    int array[] = { 8, 3, 5, 1, 6, 4, 9, 0, 2, 7 };
    std::size_t size = 10;

    int sorted[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    ASSERT_NO_THROW( bubble_sort( array, size ) );
    for (std::size_t i = 0; i < size; i += 1) {
        EXPECT_EQ( array[i], sorted[i] ) << "Failed at index " << i;
    }
}

TEST( BubbleSort, CorrectSortAndCopy ) {
    int array[] = { 8, 3, 5, 1, 6, 4, 9, 0, 2, 7 };
    std::size_t size = 10;

    int sorted[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int* result;
    ASSERT_NO_THROW( result = bubble_sort( array, size ) );
    ASSERT_NE( array, result );
    for (std::size_t i = 0; i < size; i += 1) {
        EXPECT_EQ( array[i], sorted[i] ) << "Sort - Failed at index " << i;
    }
    for (std::size_t i = 0; i < size; i += 1) {
        EXPECT_EQ( result[i], sorted[i] ) << "Copy - Failed at index " << i;
    }
}

TEST( BubbleSort, CorrectCopyAndNoChangeInPlace ) {
    const int array[] = { 8, 3, 5, 1, 6, 4, 9, 0, 2, 7 };
    std::size_t size = 10;

    int array_[] = { 8, 3, 5, 1, 6, 4, 9, 0, 2, 7 };
    int sorted[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int* result;
    ASSERT_NO_THROW( result = bubble_sort( array, size ) );
    ASSERT_NE( array, result );
    for (std::size_t i = 0; i < size; i += 1) {
        EXPECT_EQ( array[i], array_[i] ) << "No change - Failed at index " << i;
    }
    for (std::size_t i = 0; i < size; i += 1) {
        EXPECT_EQ( result[i], sorted[i] ) << "Sorting - Failed at index " << i;
    }
}

TEST( BubbleSort, CorrectCopyAndNoChangeInPlaceWithCast ) {
    int array[] = { 8, 3, 5, 1, 6, 4, 9, 0, 2, 7 };
    std::size_t size = 10;

    int array_[] = { 8, 3, 5, 1, 6, 4, 9, 0, 2, 7 };
    int sorted[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int* result;
    ASSERT_NO_THROW( result = bubble_sort( const_cast<const int*>(array), size ) );
    ASSERT_NE( array, result );
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