SRC_1 = Pthread_NoSynchronization.c
APP_1 = Pthread_NoSync
CC_1 = gcc
CC_2 = gcc-9
FLAGS_1 = -o
PTHREAD = -lpthread
OPENMP = -fopenmp

.PHONY: all clean

all: $(APP_1)

$(APP_1): $(SRC_1)
	$(CC_1) $(FLAGS_1) $(APP_1) $(SRC_1) $(PTHREAD)

clean:
	$(RM) *.o *.out core *~
	$(RM) $(APP_1)
