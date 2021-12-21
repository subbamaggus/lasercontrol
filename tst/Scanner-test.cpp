#include "gtest/gtest.h"
#include "Scanner.h"

TEST(ScannerTest, test1) {
    EXPECT_EQ (Scanner::scan(),  0);
}
