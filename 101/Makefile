CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		101.o

LIBS =

TARGET =	101.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
