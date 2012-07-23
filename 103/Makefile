CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		103.o

LIBS =

TARGET =	103.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
