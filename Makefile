all: clean
	mkdir target
	gcc $(CFLAGS) $(LDFLAGS) src/*.c -o target/recursed
	
clean:
	rm -rf target
	
