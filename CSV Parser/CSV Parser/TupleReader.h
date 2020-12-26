#pragma once

#include <tuple>

#include "ErrorHandler.h"

template<typename Ch, typename Tr, typename Head, typename... Tail>
class TupleReader {
public:
	static std::tuple<Head, Tail...> read(std::basic_istream<Ch, Tr>& inputStream, size_t lineNumber, size_t columnNumber = 1) {
		if (inputStream.eof()) {
			throw NotEnoughData{ lineNumber };
		}
		Head data;
		inputStream >> data;
		if (inputStream.fail()) {
			throw FailedToReadData{ lineNumber, columnNumber };
		}
		return std::tuple_cat(std::make_tuple(data), TupleReader<Ch, Tr, Tail...>::read(inputStream, lineNumber, columnNumber + 1));
	}
};

template<typename Ch, typename Tr, typename Head>
class TupleReader<Ch, Tr, Head> {
public:
	static std::tuple<Head> read(std::basic_istream<Ch, Tr>& inputStream, size_t lineNumber, size_t columnNumber = 1) {
		if (inputStream.eof()) {
			throw NotEnoughData{ lineNumber };
		}
		Head data;
		inputStream >> data;
		if (inputStream.fail()) {
			throw FailedToReadData{ lineNumber, columnNumber };
		}
		return std::make_tuple(data);
	}
};
