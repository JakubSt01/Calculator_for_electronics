#pragma once

#include "pch.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <bitset>

using std::vector;
using std::string;

namespace data_converter {
	class data_converter {

	public:
		// handlers for user interface - when user change one of values below - all else values would change imidietly
		data_converter() :
			DEC(""),
			BIN(""),
			OCT(""),
			HEX(""){

		}

		void number_systems_converter(string data, string data_type);

		//functions for geting converted data
		string BIN_handler();
		string DEC_handler();
		string OCT_handler();
		string HEX_handler();

	private:
		


		string DEC;
		string BIN;
		string OCT;
		string HEX;
	};

	class data_validation {
	public:

		data_validation() :
			valid_BIN("01"),
			valid_OCT("01234567"),
			valid_DEC("0123456789"),
			valid_HEX("0123456789abcdef"),
			converter(),
			saved_data("")
		{};

		// data validation is needed for number inputs
		// BIN - 0 1 - 0b
		// OCT - 0 1 2 3 4 5 6 7 - 0o
		// DEC - 0 1 2 3 4 5 6 7 8 9
		// HEX - 0 1 2 3 4 5 6 7 8 9 a b c d e f -0x
		// !only unsigned integers for data conversion
		bool validate_data(string data);

		data_converter converter;
		friend class converter;

	private:

		string saved_data;

		const string valid_BIN;
		const string valid_OCT;
		const string valid_DEC;
		const string valid_HEX;
	};


	
}
