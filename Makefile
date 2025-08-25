
all: Source/main.cpp Source/Print.cpp Source/Scan.cpp Source/Calculation.cpp Source/Float.cpp Source/Test.cpp Source/TestCreator.cpp
	@g++ Source/TestCreator.cpp Source/main.cpp Source/Print.cpp Source/Scan.cpp Source/Calculation.cpp Source/Float.cpp Source/Test.cpp -o Solver.out

	@echo "COMPILED SUCCESFULLY"

#@./Solver.out

clean:
	@rm -rf *.o Solver.out
	@echo "CLEANED SUCCESFULLY"

