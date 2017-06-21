//
// Created by mwypych on 01.06.17.
//
#include <gtest/gtest.h>
#include "ArabicRoman.h"

using namespace translator;


TEST(RomanToArabic, NumberOutOfRangeThrowsException){
EXPECT_THROW(RomanToArabic(4000),std::runtime_error);
EXPECT_THROW(RomanToArabic(-200),std::runtime_error);

}

TEST(RomanToArabic, GetsInRangeIntegerAndReturnsValidRoman) {
EXPECT_EQ("I", RomanToArabic(1));
EXPECT_EQ("MCMXCIX", RomanToArabic(1999));
EXPECT_EQ("MMDCLXXV", RomanToArabic(2675));
EXPECT_EQ("MCCCXXII", RomanToArabic(1322));
EXPECT_EQ("CCXXXIII", RomanToArabic(233));
}