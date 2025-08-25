#ifndef ASSERT_H
#define ASSERT_H
    #ifndef DEBUG
        #define ASSERT(X) \
        if (X) { printf("ERROR(" #X ") in %d line in file %s", __LINE__, __FILE__); exit(1); } // abort()
    #else
        #define ASSERT(X)
    #endif
#endif
