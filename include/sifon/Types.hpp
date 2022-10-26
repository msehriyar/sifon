#pragma once

#include "Buffer.hpp"

#include <concepts>
#include <type_traits>

namespace sifon
{


template <typename T>
concept Flushable = requires(T obj)
{
	obj.flush();
};

template <typename T>
concept Serializable = requires(T obj, Buffer pub)
{
	 writeObject(pub, obj);
};

template < class T >
concept Integral = std::is_integral_v<T>;

}