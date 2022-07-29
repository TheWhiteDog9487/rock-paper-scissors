#include "free_ptr.h"

namespace thewhitedog9487_free_ptr {

	template<typename T>auto free_ptr(T* ptr)->void {
		if (ptr != nullptr) {
			delete ptr;
			ptr = nullptr;}}

	template<typename T>auto free_ptr_array(T* ptr)->void {
		if (ptr != nullptr) {
			delete[] ptr;
			ptr = nullptr;}}

}