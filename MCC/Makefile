# The compiler to use.
CC = g++

# Directories for Includes and Common clases
IDIR =../include/
CDIR =../commons/

# Compiler options
CFLAGS= -Wall -O2 -I$(IDIR) -fPIC -g -std=c++11
LDFLAGS= -shared

# Sources and Common clases sources
SOURCES= main.cpp py_mcc.cpp MCC.cpp Cylinder.cpp
CSOURCES= $(CDIR)Fingerprint.cpp $(CDIR)Functions.cpp $(CDIR)Minutia.cpp $(CDIR)GrahamScanConvexHull.cpp $(CDIR)File19794.cpp $(CDIR)Munkres.cpp

# Objects
OBJECTS=$(SOURCES:.cpp=.o)
COBJECTS=$(CSOURCES:.cpp=.o)

# Name of the executable
EXECUTABLE=py_mcc.so

all: $(SOURCES) $(CSOURCES) $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS) $(COBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) $(COBJECTS) -o $@

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(COBJECTS) $(EXECUTABLE)
