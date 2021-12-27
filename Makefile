run: clean compile link
	@echo "--> Run"
	@./build/main
	@echo "--> Finished!"

link:
	@echo "--> Link"
	@g++ build/pksocket.o build/main.o -o build/main -pthread

compile:
	@echo "--> Compile"
	@echo "   --> pksocket.cpp"
	@g++ -c src/pksocket.cpp -o build/pksocket.o
	@echo "   --> main.cpp"
	@g++ -c main.cpp -o build/main.o

clean:
	@echo "--> Clean"
	@rm -f build/*