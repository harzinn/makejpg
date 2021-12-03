makejpgdev: 
	gcc -Wall -g -Og makejpgdev.c -o bin/debug/makejpg_debug

clean:
	rm *.jpg sha512index

run:
	./bin/debug/makejpg_debug
