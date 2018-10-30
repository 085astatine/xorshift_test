#include "gtest/gtest.h"
#include "xorshift.hpp"

namespace xorshift {
TEST(Bits, Size) {
  EXPECT_EQ(Bits<uint32_t>::size, 32);
  EXPECT_EQ(Bits<uint64_t>::size, 64);
}
}  // namespace xorshift
