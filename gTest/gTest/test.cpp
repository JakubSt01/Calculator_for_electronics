#include "pch.h"
#include "gTest.h"


TEST(test_valid, test_validate_data) {
	data_converter::data_validation test_valid;


		EXPECT_EQ(true, test_valid.validate_data("0xff"));
		EXPECT_EQ(true, test_valid.validate_data("0xf"));
		EXPECT_EQ(true, test_valid.validate_data("0xf1f"));
		EXPECT_EQ(true, test_valid.validate_data("0xff213"));
		EXPECT_EQ(true, test_valid.validate_data("0xff2323"));
		EXPECT_EQ(true, test_valid.validate_data("0xff231"));
		EXPECT_EQ(true, test_valid.validate_data("0x"));
		EXPECT_EQ(true, test_valid.validate_data("0xff2312312"));
		EXPECT_EQ(true, test_valid.validate_data("0xf2312f"));
		EXPECT_EQ(false, test_valid.validate_data("0b123"));
		EXPECT_EQ(false, test_valid.validate_data("0b133333"));
		EXPECT_EQ(false, test_valid.validate_data("0o12345678"));
		EXPECT_EQ(false, test_valid.validate_data("0o77977"));
		EXPECT_EQ(false, test_valid.validate_data("0of12232"));
		EXPECT_EQ(false, test_valid.validate_data("R"));
		EXPECT_EQ(false, test_valid.validate_data("a"));
		EXPECT_EQ(false, test_valid.validate_data("ff"));
		EXPECT_EQ(false, test_valid.validate_data("GGGGG"));
		EXPECT_EQ(true, test_valid.validate_data("2123123"));



}


