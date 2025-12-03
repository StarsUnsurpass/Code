#pragma once
#include "types.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
* 安全地分配内存
* 如果内存分配失败，将记录错误日志并返回NULL
* 
* @param size 需要分配的内存大小，使用size_t保证跨平台兼容性
* @return 指向需要分配内存的指针，如果分配失败则为NULL
*/
void* safe_malloc(size_t size);

/*
* 安全地重新分配内存...
* 如果内存分配失败，将记录错误日志并返回NULL
* @param prt 原内存指针
* @param newSize 新的内存大小
* @return 指向重新分配的内存指针，如果分配失败则NULL
*/
void* safe_remalloc(void* prt, size_t newSize);

/*
* 安全地释放内存，并将指针设置为NULL
* 避免释放后野指针
*/
void safe_free(void** ptr);