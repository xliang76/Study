# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -lpthread --std=c++11
# the build target executable:
TARGET = TwoSum
#TARGET = addBinary
#TARGET = listNode
#TARGET = longestSub
#TARGET = sort
#TARGET = multithreading
#TARGET = asynctest
#TARGET = thread
#TARGET = socketServer
#TARGET = socketClient
#TARGET = testvirtual
#TARGET = testTree
#TARGET = mybinarytree
#TARGET = teststring
#TARGET = lru
#TARGET = revertString
#TARGET = revertInt
#TARGET = letterCompaination
#TARGET = runme
#TARGET = testVector
#TARGET = longestcommonsubstring
#TARGET = conductor
#TARGET = TCPServer
#TARGET = TCPClient
#TARGET = UDPServer
#TARGET = UDPClient
#TARGET = openfile
#TARGET = allCombination
#TARGET = my2D
#TARGET = UDPBroadcastClient
#TARGET = UDPBroadcastServer

#OBJ = binaryTree.o
OBJ = 


all: 
	$(CC) $(CFLAGS) -o obj/$(TARGET) $(OBJ) $(TARGET)/$(TARGET).cpp

#$(TARGET): $(TARGET)/$(TARGET).cpp 

%.o: %.cpp
	$(CC) -c $(CFLAGS) -o $@ $< 

clean:
	$(RM) $(TARGET)
	$(RM) $(OBJ)
