
#include "pch.h"
#include "framework.h"
#include "data_converter.h"

namespace data_converter {

	void data_converter::number_systems_converter(string data, string data_type) {
		try {

		
		if (data_type == "BIN") {
			std::stringstream data_stream; // if variables are not defined there, sometimes conversion throw an exception
			std::ostringstream output_data_stream;
			BIN = data;
			//converting to dec
			std::bitset<64> bits(BIN);
			DEC = std::to_string(bits.to_ulong());
			//converting to oct
			output_data_stream.str("");
			output_data_stream << std::oct << std::stoi(DEC);
			OCT = output_data_stream.str();
			//converting to hex
			output_data_stream.str("");
			output_data_stream << std::hex << std::stoi(DEC);
			HEX = output_data_stream.str();
		}
		if (data_type == "DEC") {
			std::stringstream data_stream;
			std::ostringstream output_data_stream;
			DEC = data;
			//converting to bin
			std::bitset<64> binaryValue(std::stoi(DEC));
			BIN = binaryValue.to_string();
			string::size_type location = BIN.find("1");
			if (location == string::npos)
				BIN = "0";
			else
				BIN = BIN.substr(location);
			//converting to oct
			output_data_stream.str("");
			output_data_stream << std::oct << std::stoi(DEC);
			OCT = output_data_stream.str();
			//converting to hex
			output_data_stream.str("");
			output_data_stream << std::hex << std::stoi(DEC);
			HEX = output_data_stream.str();
		}
		if (data_type == "OCT") {
			std::stringstream data_stream;
			std::ostringstream output_data_stream;
			OCT = data;
			//converting to dec
			data_stream.str(data);
			unsigned int decimal{};
			data_stream >> std::oct >> decimal;
			DEC = std::to_string(decimal);
			//converting to bin
			std::bitset<64> binaryValue(std::stoi(DEC));
			BIN = binaryValue.to_string();
			string::size_type location = BIN.find("1");
			if (location == string::npos)
				BIN = "0";
			else
				BIN = BIN.substr(location);
			//converting to hex
			output_data_stream.str("");
			output_data_stream << std::hex << std::stoi(DEC);
			HEX = output_data_stream.str();

		}
		if (data_type == "HEX") {
			std::stringstream data_stream;
			std::ostringstream output_data_stream;
			HEX = data;
			//converting to decimal
			data_stream.str(HEX);
			unsigned int decimal{};
			data_stream >> std::hex >> decimal;
			DEC = std::to_string(decimal);
			//converting to bin
			std::bitset<64> binaryValue(std::stoi(DEC));
			BIN = binaryValue.to_string();
			string::size_type location = BIN.find("1");
			if (location == string::npos)
				BIN = "0";
			else
				BIN = BIN.substr(location);
			//converting to oct
			output_data_stream.str("");
			output_data_stream << std::oct << 123;// std::stoi(DEC);
			OCT = output_data_stream.str();
		}
		OCT = "0o" + OCT;
		HEX = "0x" + HEX;
		BIN = "0b" + BIN;
		}
		catch (...) {
			// if error ocured program will not fail
		}
	}

	string data_converter::BIN_handler() {
		return  BIN;
	}

	string data_converter::DEC_handler() {
		return DEC;
	}

	string data_converter::OCT_handler() {
		return  OCT;
	}

	string data_converter::HEX_handler() {
		return HEX;
	}



	bool data_validation::validate_data(string data) {
		if (data == saved_data) return true;
		else saved_data = data;

		try {
			if (data.find("0x") == 0) {
				data.erase(0, 2);
				for (auto digit : data) {
					if (valid_HEX.find(digit) == string::npos) //check if valid_XXX contains every digit
						return false;
				}
				converter.number_systems_converter(data, "HEX");
				return true;
			}
			else if (data.find("0o") == 0) {
				data.erase(0, 2);
				for (auto digit : data) {
					if (valid_OCT.find(digit) == string::npos) //check if valid_XXX contains every digit
						return false;
				}
				converter.number_systems_converter(data, "OCT");
				return true;
			}
			else if (data.find("0b") == 0) {
				data.erase(0, 2);
				for (auto digit : data) {
					if (valid_BIN.find(digit) == string::npos) //check if valid_XXX contains every digit
						return false;
				}
				converter.number_systems_converter(data, "BIN");
				return true;
			}
		}
		catch (...) { // if data erasing go wrong
			return false;
		}
		for (auto digit : data) {
			if (valid_DEC.find(digit) == string::npos) //check if valid_XXX contains every digit (unsigned integer)
				return false;
		}
		converter.number_systems_converter(data, "DEC");
		return true;
	}


}