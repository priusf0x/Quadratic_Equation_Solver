SOURCES =  main.cpp Calculation.cpp Print.cpp Scan.cpp Test.cpp TestCreator.cpp Float.cpp


OBJ_DIR = obj
SOURCE_DIR = Source

OBJECTS := $(addprefix $(OBJ_DIR)/, $(SOURCES:.cpp=.o))
SOURCES :=$(addprefix $(SOURCE_DIR)/, $(SOURCES))


TARGET = Solver.out

CC = g++

CFLAGS =-D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr



$(TARGET): $(OBJECTS)
	@echo "Linking..."
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "Linked Successfully"

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	@echo "Compiling" $<
	@$(CC) -c $< -o $@
	@echo "Compiled Successfully" $<

clean:$(OBJECTS) $(TARGET)
	@rm -rf $(OBJECTS)
	@rm -rf $(TARGET)
	@echo "Cleaned Successfully"

