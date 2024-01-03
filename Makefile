CC=clang++
CFLAGS=--std=c++11

objects = Arrival.o Bursts.o CompleteCpu.o CompleteIO.o Event.o Exit.o ListItem.o Node.o PriorityQueue.o Process.o Queue.o Simulation.o StartCpu.o StartIO.o Timeout.o 

# this rule builds A2 as the executable from the object files
all: A2main.o $(objects)
	$(CC) $(CFLAGS) -o A2 $< $(objects)

# this will build objects file from .cpp file
Arrival.o: Arrival.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
Bursts.o: Bursts.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
CompleteCpu.o: CompleteCpu.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
CompleteIO.o: CompleteIO.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
Event.o: Event.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
Exit.o: Exit.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
ListItem.o: ListItem.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
Node.o: Node.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
PriorityQueue.o: PriorityQueue.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
Process.o: Process.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
Queue.o: Queue.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
Simulation.o: Simulation.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
StartCpu.o: StartCpu.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
StartIO.o: StartIO.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
Timeout.o: Timeout.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
Tests: Tests.cpp $(objects)
	clang++ --std=c++11 -c Tests.cpp -c
	clang++ --std=c++11 Tests.o $(objects) -o Tests
clean: 
	rm *.o
