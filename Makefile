SRC_1 = Pthread_Synchronization.c
APP_1 = Pthread_NoSync
APP_2 = Pthread_WithSync
CC_1 = gcc
CC_2 = gcc-9
FLAGS_1 = -o
FLAGS_2 = -DPTHREAD_SYNC=1
PTHREAD = -lpthread
OPENMP = -fopenmp

.PHONY: all clean

all: $(APP_1) $(APP_2)

$(APP_1): $(SRC_1)
	$(CC_1) $(FLAGS_1) $(APP_1) $(SRC_1) $(PTHREAD)

$(APP_2): $(SRC_1)
	$(CC_1) $(FLAGS_2) $(FLAGS_1) $(APP_2) $(SRC_1) $(PTHREAD)

clean:
	$(RM) *.o *.out core *~
	$(RM) $(APP_1) $(APP_2)
