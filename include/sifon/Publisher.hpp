#pragma once

#include "Types.hpp"

#include <charconv>
#include <string>
#include <string_view>
#include <stdio.h>

namespace sifon
{


class Publisher
{

public:	


Publisher(std::string_view outputName)
{
	fd = fopen(outputName.data(), "w");
}

~Publisher()
{
	flush();
	fclose(fd);
}

void flush()
{
	fwrite(buffer.data(), buffer.size(), 1, fd);
}


template <typename T>
Publisher& operator<<(const T&)
{
	return *this;
}

template <Serializable S>
Publisher& operator<<(const S& obj)
{
	writeObject(buffer, obj);
	return *this;
}

template <Integral T>
Publisher& operator<<(const T& obj)
{	
	if(auto [ptr, ec] = std::to_chars(buffer.data(), buffer.data() + buffer.size(), obj);
       ec == std::errc())
    {

    }
    return *this;
}

 private:
	Buffer buffer;
	FILE *fd;

};



}