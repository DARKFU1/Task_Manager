.PHONY: all clean rebuild call_unit_tests

SRCS_DIR = sources

SRCS = ${SRCS_DIR}/main.cpp
OBJS = $(SRCS:.cpp=.o)

all: ${OBJS}
	@echo "Building..."
	@g++ $^ -o out
	@echo "Done!"

%.o: %.cpp
	@echo "Building file: "$<"..."
	@g++ -c $< -o $@

clean:
	@echo "" > ${SRCS_DIR}/*.o
	@rm ${SRCS_DIR}/*.o # created file *.o so if no .o files met, will not be any error.
	@echo "Cleaned!"

call_unit_tests:
	./out --test

rebuild: clean all call_unit_tests
