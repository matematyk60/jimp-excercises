//
// Created by mwypych on 01.06.17.
//


#include <gtest/gtest.h>
#include <ArabicRoman.h>

using namespace translator;


TEST(ArabicToRoman, NumberOutOfRangeThrowsException){
    EXPECT_THROW(ArabicToRoman(4000),std::runtime_error);
    EXPECT_THROW(ArabicToRoman(-200),std::runtime_error);

}

TEST(ArabicToRoman, GetsInRangeIntegerAndReturnsValidRoman) {
    EXPECT_EQ("I", ArabicToRoman(1));
    EXPECT_EQ("MCMXCIX", ArabicToRoman(1999));
    EXPECT_EQ("MMDCLXXV", ArabicToRoman(2675));
    EXPECT_EQ("MCCCXXII", ArabicToRoman(1322));
    EXPECT_EQ("CCXXXIII", ArabicToRoman(233));
}
