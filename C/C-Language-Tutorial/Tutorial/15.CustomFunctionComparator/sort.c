#include "sort.h"
#include <stdlib.h>

// 跨平台问题
// 不同操作系统上的函数不同
// qsort_s(), qsort(), qsort_r()

// 包装器
static int compareWarpper(void* context, const void* a, const void* b) {
	CompareFunc compare = (CompareFunc)context;
	return compare(a, b, NULL);	// Adjusted to math expeected signature
}

void genericSort(void* array, size_t length, size_t size, CompareFunc compare, void* context) {
#ifdef _WIN32
	qsort_s(array, length, size, compareWarpper, (void*)compare);
#else
	qsort_r(array, length, size, compareWarpper, context);
#endif

}

