all: mcp4822_linux_test

upload: mcp4822_linux_test
	scp mcp4822_linux_test pi@192.168.0.172:/home/pi/mcp4822_linux_test

mcp4822_linux_test: test.o mcp4822.o
	@echo 'Building target: $@'
	arm-linux-gnueabihf-gcc -o mcp4822_linux_test test.o mcp4822.o -lm
	@echo 'Finished building target: $@'

test.o: test.c mcp4822.h
	arm-linux-gnueabihf-gcc -c test.c -Wall

mcp4822.o: mcp4822.c mcp4822.h
	arm-linux-gnueabihf-gcc -c mcp4822.c -Wall

clean:
	rm -rf test.o mcp4822.o mcp4822_linux_test
	