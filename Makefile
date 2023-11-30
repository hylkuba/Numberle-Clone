#   /**
#    * @author Jakub Hýl <hylkuba@gmail.com>
#    * @date 30.11.2023
#   */

NAME = wordle

ifeq ($(shell uname),Linux)
    CXX = g++
    LD = g++
    CXXFLAGS = -Wall -pedantic -std=c++17 -g -O2 -fsanitize=address
    LDFLAGS = -fsanitize=address
    TARGET = $(NAME)
else
    CXX = g++
    LD = g++ -mconsole
    CXXFLAGS = -Wall -pedantic -Wextra -std=c++17 -g -O2 -mconsole
    LDFLAGS = -m64
    TARGET = $(NAME).exe
endif

HEADERS = $(wildcard src/*.h)

DIR_NAME = bin

OBJS = $(DIR_NAME)/main.o $(DIR_NAME)/application.o  $(DIR_NAME)/controls.o $(DIR_NAME)/ui.o

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

#-----------------------------------------------------------------------
# All .o objects stored in folder
run: | $(DIR_NAME) compile
	./$(TARGET)

$(DIR_NAME):
	mkdir -p $(DIR_NAME)

compile: $(DIR_NAME) $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(NAME)

doc: Doxyfile $(HEADERS)
	doxygen Doxyfile

.PHONY: clean
clean:
	rm -rf $(DIR_NAME) $(TARGET) doc/ 2>/dev/null

$(DIR_NAME)/%.o: src/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all
all: doc run clean

#-----------------------------------------------------------------------
l:
	cat Makefile src/*.h src/*.cpp | wc -l

la:
	cat Makefile src/* | wc -l
#-----------------------------------------------------------------------
# Object files dependencies
$(DIR_NAME)/main.o: src/main.cpp src/application.h src/ui.h \
 src/controls.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DIR_NAME)/application.o: src/application.cpp src/application.h src/ui.h \
 src/controls.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DIR_NAME)/controls.o: src/controls.cpp src/controls.h src/ui.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DIR_NAME)/ui.o: src/ui.cpp src/ui.h
	$(CXX) $(CXXFLAGS) -c $< -o $@