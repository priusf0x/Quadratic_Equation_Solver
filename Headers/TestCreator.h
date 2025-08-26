#ifndef TEST_CREATOR_H
#define TEST_CREATOR_H
    #include <time.h>
    /// @brief Generates Equation with solution
    /// @param [in] data pointer to *TestData* struct
    void GenerateEquation(struct TestData * data, time_t seed);
    /// @brief Struct for output of GenerateEquation() fuction
    struct TestData
    {
        int type = 0;
        double a = 0;
        double b = 0;
        double c = 0;
        double solution_1 = 0;
        double solution_2 = 0;
    };
    /// @brief Creates test in Test.txt file
    void CreateTest(void);
    /// @brief Limit of test number
    const int max_test_number = 100000;
    /// @brief function for random number
    double CreateCoefficient(time_t seed);

#endif
