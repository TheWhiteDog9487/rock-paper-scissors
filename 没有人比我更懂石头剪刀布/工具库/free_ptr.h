#pragma once
#include "./include.h"

namespace thewhitedog9487_free_ptr {

	template<typename T>auto free_ptr(T* ptr)->void;
	template<typename T>auto free_ptr_array(T* ptr)->void;
	
}