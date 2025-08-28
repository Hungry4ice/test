#include <gtest/gtest.h>

// Need C linkage for the C file
extern "C" {
    #include "math_ops.h"
}

// ----- Mock Section -----
// We'll override helper_function() at link time.
// This mock replaces the real helper_function defined in math_ops.c.
int mock_helper_return_value = 0;  // global for test control

extern "C" int helper_function(int x) {
    (void)x; // ignore input for now
    return mock_helper_return_value;
}

// ----- Tests -----
TEST(MathOpsTest, ComputeWithMockedHelper) {
    mock_helper_return_value = 5;
    int result = compute_square_plus_helper(3);
    // compute_square_plus_helper: (3*3) + mock_helper(3)
    EXPECT_EQ(result, 9 + 5);

    mock_helper_return_value = -2;
    result = compute_square_plus_helper(4);
    EXPECT_EQ(result, 16 - 2);
}
