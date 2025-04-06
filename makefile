CC = g++
CFLAGS = -std=c++23
SRC = main.cpp
LIB = -I ac-library/.
PROGRAM = a.out
DATE=`TZ='Asia/Tokyo' date`
ERR_TOL =

$(PROGRAM): $(SRC)
	$(CC) $(SRC) $(CFLAGS) $(LIB) && \
	oj t --ignore-spaces $(if $(ERR_TOL),-e $(ERR_TOL)) && \
	echo "\e[33m[WARN] 公式提供のテストケースは完全ではありません。\e[m" && \
	oj s $(SRC)

# Add a special target for error tolerance
e:
	@if [ -z "$(filter-out $@,$(MAKECMDGOALS))" ]; then \
		echo "\e[31m[ERROR] 許容誤差を指定してください。例: make e 1e-6\e[m"; \
		exit 1; \
	fi
	$(MAKE) ERR_TOL=$(filter-out $@,$(MAKECMDGOALS))

# Catch-all target to allow the syntax "make e VALUE"
%:
	@:

heuristic:
ifeq ($(strip $(URL)),)
	@echo "\e[31m[ERROR] URLが指定されていません。以下のように指定してください：\e[m"
	@echo "    make heuristic URL=<提出先のURL>"
	@exit 1
endif
	$(CC) $(SRC) $(CFLAGS) $(LIB) && \
	./$(PROGRAM) < self_testcases/case_1.txt && \
	oj s $(URL) $(SRC) 
	printf "\e[33m$(DATE)\e[m"

self:
	$(CC) $(SRC) $(CFLAGS) $(LIB)
	if [ -z "$(wildcard self_testcases/*.txt)" ]; then \
		echo "\e[33m[WARN] No test cases found in self_testcases directory\e[m"; \
	else \
		for TEST_CASE in self_testcases/*.txt; do \
			echo "--- Test Case: $$(basename $$TEST_CASE) ---"; \
			./$(PROGRAM) < "$$TEST_CASE"; \
			echo "--- Exit code: $$? ---\n"; \
		done; \
	fi

init:
	@printf "\033[33m[WARN] main.cppがリセットされます。よろしいですか？ (y/n)\033[0m\n"
	@read -r REPLY; \
	if [ "$$REPLY" = "y" ] || [ "$$REPLY" = "Y" ]; then \
		cp template.cpp $(SRC); \
		if [ -d "test/" ]; then rm -r test/; fi; \
		if [ -f "$(PROGRAM)" ]; then rm $(PROGRAM); fi; \
		printf "\033[32mmain.cppをリセットしました。\033[0m\n"; \
	else \
		printf "\033[31m操作をキャンセルしました。\033[0m\n"; \
	fi

login:
	oj login https://atcoder.jp/