#pragma once

#include <stdlib.h>

#if defined(__linux__)
#define cls() system("clear")
#elif defined(_WIN32)
#define cls() system("cls")
#else
#define cls()
#endif