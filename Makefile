run: clean compile lib
	@echo "--> Finished!"

lib:
	@echo "--> Generating static library"
	@ar rcs pksocket.a build/pksocket.o

compile:
	@echo "--> Compile"
	@echo "   --> pksocket.cpp"
	@g++ -c src/pksocket.cpp -o build/pksocket.o

clean:
	@echo "--> Clean"
	@rm -f build/*

test: run
	@echo "--> Test"
	@g++ -c test.cpp -o build/test.o
	@g++ build/test.o pksocket.a -o build/test
	@./build/test