#ifndef TEST_CREATOR_H

    #ifndef random
        #include <stdlib.h>
    #endif

    #ifndef fprintf
        #include <stdio.h>
    #endif

    #define TEST_CREATOR_H

    void GenerateEquation(struct TestData * data);

    struct TestData
    {
        int type = 0;
        double a = 0;
        double b = 0;
        double c = 0;
        double solution_1 = 0;
        double solution_2 = 0;
    };

    void CreateTest(void);

    const int max_test_number = 10000;

#endif
