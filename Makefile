TARGET_EXEC := main

BUILD_DIR := ./build
SRC_DIRS := ./libs ./database

SRCS := $(shell find $(SRC_DIRS) -name '*.c') main.c

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

FLAGS := $(INC_FLAGS) -MMD -MP

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

-include $(DEPS)

# UNIT TESTS

SRC_DATETIME = libs/sederhana/datetime.c libs/sederhana/time1.c
SRC_DATETIME_TEST = tests/sederhana/mdatetime.c
OBJ_DATETIME = $(SRC_DATETIME:.c=.o)
OBJ_DATETIME_TEST = $(SRC_DATETIME_TEST:.c=.o)
EXEC_DATETIME_TEST = $(basename $(SRC_DATETIME_TEST))

DATETIME_TEST_DIR = tests/sederhana
DATETIME_TEST_CASES = $(wildcard $(DATETIME_TEST_DIR)/*.in)
DATETIME_TEST_OUTPUTS = $(DATETIME_TEST_CASES:.in=.out)
DATETIME_TEST_RESULTS = $(DATETIME_TEST_CASES:.in=.result)

mdatetime: $(OBJ_DATETIME) $(OBJ_DATETIME_TEST)
	$(CC) $(CFLAGS) -o $(EXEC_DATETIME_TEST) $^

test_datetime: $(EXEC_DATETIME_TEST) $(DATETIME_TEST_RESULTS)
	@cat $(DATETIME_TEST_RESULTS)

$(DATETIME_TEST_RESULTS): $(DATETIME_TEST_DIR)/%.result: $(DATETIME_TEST_DIR)/%.in $(DATETIME_TEST_DIR)/%.out $(EXEC_DATETIME_TEST)
	@if $(EXEC_DATETIME_TEST) < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@
