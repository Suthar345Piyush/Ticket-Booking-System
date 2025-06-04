CXX = g++
CXXFLAGS = -std=c++17 -Wall -I.
LDFLAGS = 


#source files 
SRCS = main.cpp \
       service/bookingService.cpp \
			 service/fileIO.cpp


#Object files 
OBJS = $(SRCS: .cpp=.0)

#Executable name 
TARGET = booking_system


#Default Target 
all : $(TARGET)


#Linking 
$(TARGET): $(OBJS)
       $(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)


#Compilation 
%.o: %.cpp 
       $(CXX) $(CXXFLAGS) -c $< -o $@


#Clean 
clean: 
        rm -f $(OBJS) $(TARGET)

.PHONY: all clean 


       