.PHONY: all clean rebuild

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
	@echo "" > *.o
	@rm *.o # created file *.o so if no .o files met, will not be any error.
	@echo "Cleaned!"

rebuild: clean all
