MK_HOME=$(PWD)
CFLAGS=$(shell pkg-config --cflags gtk+-3.0)
LDFLAGS=$(shell pkg-config --libs gtk+-3.0)


all: clean 
	mkdir $(MK_HOME)/target
	gcc $(CFLAGS) $(LDFLAGS) $(MK_HOME)/src/*.c -o target/recursed
	cd $(MK_HOME)/src && doxygen $(MK_HOME)/dconfig 
	
clean: 
	rm -rf $(MK_HOME)/target
