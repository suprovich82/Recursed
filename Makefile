all: clean
	mkdir target
	gcc $(CFLAGS) $(LDFLAGS) src/*.c -o target/recursed
	cd src
	doxygen ../dconfig 
	
clean:
	rm -rf target
	
