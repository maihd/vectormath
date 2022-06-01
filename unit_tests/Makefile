# Inputs
CC=gcc
RUN_ALLS=false

# Build flags
CFLAGS=-Wall
LFLAGS=
ifneq ($(OS),Windows_NT)
LFLAGS+=-lm
endif

OUT_DIR=out

UNIT_TESTS_DIR=cases
UNIT_TESTS_SRC=$(wildcard $(UNIT_TESTS_DIR)/*.cpp)
UNIT_TESTS_EXE=$(patsubst $(UNIT_TESTS_DIR)/%.cpp,$(OUT_DIR)/%.exe,$(UNIT_TESTS_SRC))
UNIT_TESTS_CFLAGS=-DRUN_UNIT_TESTS

ifeq ($(RUN_ALLS),true)
UNIT_TESTS_CFLAGS+=-DCONTINUE_UNIT_TEST_ON_FAIL
endif

.PHONY: clean all

$(OUT_DIR)/%.exe: $(UNIT_TESTS_DIR)/%.cpp
	@echo "Execute unit test for '$(patsubst ../%.cpp,%,$<)'"
	@echo "===> COMPILING $<"
	@mkdir -p $(OUT_DIR)
	@$(CC) -o $@ $< -I$(INC_DIR) $(CFLAGS) $(LFLAGS) $(UNIT_TESTS_CFLAGS)
	@echo "===> RUNNING $@"
	@./$@ "===> [$@]"
	@echo "===> DONE!"
	@echo ""

all: 
ifeq ($(RUN_ALLS),true)
	@make clean --quiet
endif
	@make run --quiet
# @echo "============================================="
# @echo "Execute all unit tests complete successfully!"

run: $(UNIT_TESTS_EXE)

clean:
	rm -rf $(OUT_DIR)

autorun:
ifneq ($(OS),Windows_NT)
#@echo "Auto run unit tests is not supported on current platform!"
	@echo "Auto run unit tests can only run on Windows!"
else
	@mkdir -p $(OUT_DIR)
	@rm -f $(OUT_DIR)/test_auto_runner.exe
	@$(CC) -o $(OUT_DIR)/test_auto_runner.exe test_auto_runner.c $(CFLAGS)
	@./$(OUT_DIR)/test_auto_runner.exe $(CC)
endif