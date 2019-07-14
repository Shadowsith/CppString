all:
	@mkdir -p ./bin/
	@g++ unit.cpp -o ./bin/unit
	@g++ performance.cpp -o ./bin/performance
run:
	@make all
	./bin/unit
perf:
	@make all
	./bin/performance
clean:
	@rm -r ./bin
