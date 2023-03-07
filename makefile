.PHONY: all clean rebuild call_unit_tests

SRCS_DIR = sources

SRCS = ${SRCS_DIR}/main.cpp ${SRCS_DIR}/TList.cpp ${SRCS_DIR}/Tests.cpp ${SRCS_DIR}/Task.cpp
OBJS = $(SRCS:.cpp=.o)

COMPILER_FLAGS = -g

all: ${OBJS}
	@echo "Building..."
	@g++ ${COMPILER_FLAGS} $^ -o out
	@echo "Done!"

%.o: %.cpp
	@echo "Building file: "$<"..."
	@g++ -c $< ${COMPILER_FLAGS} -o $@

clean:
	@echo "" > ${SRCS_DIR}/*.o
	@rm ${SRCS_DIR}/*.o # created file *.o so if no .o files met, will not be any error.
	@echo "Cleaned!"

call_unit_tests:
	./out --test

rebuild: clean all call_unit_tests
