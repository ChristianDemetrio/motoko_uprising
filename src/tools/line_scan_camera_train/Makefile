ELF = bin/network_train.elf

LIBS_PATH=$(HOME)/libs/rysy

INC+= -I.
INC+= -I$(LIBS_PATH)/libs_common
INC+= -I$(LIBS_PATH)/libs_dataset
INC+= -I$(LIBS_PATH)/libs_nn
INC+= -I$(LIBS_PATH)/libs_experiment
INC+= -I$(LIBS_PATH)/libs_preprocessing

LIBS+= $(LIBS_PATH)/libs_experiment/libs_experiment.a
LIBS+= $(LIBS_PATH)/libs_dataset/libs_dataset.a
LIBS+= $(LIBS_PATH)/libs_nn/libs_nn.a
LIBS+= $(LIBS_PATH)/libs_common/libs_common.a
LIBS+= $(LIBS_PATH)/libs_preprocessing/libs_preprocessing.a

CC = g++
CU = nvcc
LD = g++
OBJCOPY = objcopy
OBJDUMP = objdump
SIZE = size

# DEGUBFLAGS = -g -pg

CFLAGS = $(DEGUBFLAGS) -O2 -Os -s -Wall -Wextra -pedantic -std=c++11 $(INC)

LDFLAGS = $(DEGUBFLAGS) -lstdc++fs -lm -lpthread -pthread -std=c++11 -lglut -lGL -lGLU -lX11 -ljsoncpp -L/usr/local/cuda/lib64 -lcuda -lcudart


SRCS+= $(shell find -name '*.cpp')


OBJS = $(SRCS:.cpp=.o)

all: $(ELF)
	$(SIZE) $(ELF)

$(ELF): $(LIBS) $(OBJS)
	$(LD) -o $@ $(OBJS) $(LIBS) $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

%.oc: %.cu
	$(CU) -c $(CUDAFLAGS) $< -o $@

clean:
	rm $(OBJS) -rf
	rm $(ELF) -rf
