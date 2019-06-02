all:
	@mkdir -p ./bin/
	@g++ test.cpp ./lib/textformatpp.cpp -o ./bin/test
	@g++ performance.cpp -o ./bin/performance
run:
	@make all
	./bin/test
perf:
	@make all
	./bin/performance
clean:
	@rm -r ./bin
