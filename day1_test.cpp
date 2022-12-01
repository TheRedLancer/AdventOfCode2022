//----------------------------------------------------------------------
// FILE: day1test.cpp
// NAME: Zach Burnaby
// DATE: Dec 1, 2022
// DESC: Tests forAdvent of Code Day 1 
//----------------------------------------------------------------------

#include <iostream>
#include <gtest/gtest.h>
#include "day1.h"

TEST(FeelGood, TrueIsTrue) {
  ASSERT_EQUALS(5, five());
}