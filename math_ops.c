// math_ops.c
#include "math_ops.h"

int helper_function(int x) {
    return x + 1;  // real implementation (to be mocked)
}

int compute_square_plus_helper(int x) {
    int squared = x * x;
    return squared + helper_function(x);
}
