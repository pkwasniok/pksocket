run: clean compile link
	@echo "--> Finished!"

link:
	@echo "--> Link"
	@g++ build/pksocket.o build/pksocket-term.o -o build/term -pthread

compile:
	@echo "--> Compile"
	@echo "   --> pksocket.cpp"
	@g++ -c src/pksocket.cpp -o build/pksocket.o
	@echo "   --> pksocket-term.cpp"
	@g++ -c pksocket-term.cpp -o build/pksocket-term.o

clean:
	@echo "--> Clean"
	@rm -f build/*