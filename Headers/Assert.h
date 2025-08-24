#ifndef printf
    #include <stdio.h>
#endif

#ifndef exit
    #include <stdlib.h>
#endif

#ifndef DEBUG
    #define ASSERT(X) \
    if (X) { printf("ERROR(" #X ") in %d line in file %s", __LINE__, __FILE__); exit(0); } // abort()
#else
    #define ASSERT(X)
#endif
