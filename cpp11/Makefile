CXXFLAGS = -std=gnu++0x -Wall
LDLIBS = -lstdc++
.PHONY: all clean
all:
	make clean
	g++ -std=gnu++0x -c lib/easywsclient/easywsclient.cpp -o easywsclient.o
	g++ -std=gnu++0x -c codenjoy_client.cpp -o codenjoy_client.o
	g++ codenjoy_client.o easywsclient.o -o codenjoy_client
clean:
	-rm  codenjoy_client *.o
