#pragma once

#include <iostream>
#include <tuple>
#include <string>

#include "ErrorHandler.h"

template<typename Ch, typename Tr, typename Head, typename... Tail>
class TupleReader {
public:
	static std::tuple<Head, Tail...> read(std::basic_istream<Ch, Tr>& inputStream, size_t& columnNumber) {
		if (inputStream.eof()) {
			throw NotEnoughData{ columnNumber };
		}
		Head data;
		inputStream >> data;
		if (inputStream.fail()) {
			throw FailedToReadData{ columnNumber };
		}
		++columnNumber;
		return std::tuple_cat(std::make_tuple(data), TupleReader<Ch, Tr, Tail...>::read(inputStream, columnNumber));
	}
};

template<typename Ch, typename Tr, typename Head>
class TupleReader<Ch, Tr, Head> {
public:
	static std::tuple<Head> read(std::basic_istream<Ch, Tr>& inputStream, size_t& columnNumber) {
		if (inputStream.eof()) {
			throw NotEnoughData{ columnNumber };
		}
		Head data;
		inputStream >> data;
		if (inputStream.fail()) {
			throw FailedToReadData{ columnNumber };
		}
		return std::make_tuple(data);
	}
};

template<typename Ch, typename Tr, typename... Args>
std::basic_istream<Ch, Tr>& operator>>(std::basic_istream<Ch, Tr>& inputStream, std::tuple<Args...>& tuple) {
	size_t columnNumber{ 1 };
	tuple = TupleReader<Ch, Tr, Args...>::read(inputStream, columnNumber);
	return inputStream;
}