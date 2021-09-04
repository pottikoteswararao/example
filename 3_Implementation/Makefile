PROJ_NAME = tracking
TEST_PROJ_NAME = Test_$(PROJ_NAME)
TEST_OUTPUT = Test_$(PROJ_NAME)
PROJECT_OUTPUT = $(PROJ_NAME)

CC = g++

INC = -Iinc

SRC =	src/tracking.cpp \
test/test_tracking.cpp \
src/Bill.cpp \
test/test_Bill.cpp
	
LIB = -lgtest -lgtest_main -lpthread

COV_SRC = test_tracking.cpp

#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
ifdef OS
   RM = rm 
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif
.PHONY: run clean test doc all

all:
	$(CC) $(SRC) $(INC) $(LIB) -o $(call FixPath,$(PROJECT_OUTPUT).$(EXEC))
	
run:
	./$(call FixPath,$(PROJECT_OUTPUT).$(EXEC))

coverage:
	#cp test_tracking.cpp .
	$(CC) -fprofile-arcs -ftest-coverage $(SRC) $(INC) $(LIB) -o $(call FixPath, $(TEST_OUTPUT).$(EXEC))
	$(call FixPath, ./$(TEST_OUTPUT).$(EXEC))
	gcov -a $(COV_SRC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov 
	$(RM) *.h.gcov 
	$(RM) *.tcc.gcov 
	$(RM) *.cpp.gcov
	$(RM) *.gcov
	$(RM) *.$(EXEC) 

cppcheck:
	cppcheck --enable=all $(SRC)

valgrind:
	$(CC) -fprofile-arcs -ftest-coverage $(SRC) $(INC) $(LIB) -o $(call FixPath, $(TEST_OUTPUT).$(EXEC))
	valgrind ./$(TEST_OUTPUT).$(EXEC)
	$(RM) *.gcda
	$(RM) *.tcc.gcov
	$(RM) *.gcda
	$(RM) *.gcno 
	$(RM) *.$(EXEC) 

debug:
	gcc -I $(INC) $(SRC) -g -o $(PROJ_NAME).$(EXEC)
	gdb $(PROJ_NAME).$(EXEC)

clean:
	$(RM) *.$(EXEC) 
	$(RM) $(OBJS)
	$(RM) *.DAT
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov	
