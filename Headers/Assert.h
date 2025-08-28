#ifndef ASSERT_H
#define ASSERT_H
#include <stdio.h>

#ifndef DEBUG
#define ASSERT(X) \
if (!(X)) { printf("ERROR(" #X ") in %d line in file %s", __LINE__, __FILE__); exit(EXIT_FAILURE); }
#else
#define ASSERT(X)
#endif

#endif

