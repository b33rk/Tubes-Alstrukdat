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

SRC_TESTS = tests
SRC_LIBS = libs

$(SRC_TESTS)/%.o: $(SRC_LIBS)/%.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(CFLAGS) -c $< -o $@

#DATETIME

SRC_DATETIME = libs/sederhana/datetime.c libs/sederhana/time1.c
SRC_DATETIME_TEST = tests/sederhana/mdatetime.c
OBJ_DATETIME = $(subst $(SRC_LIBS), $(SRC_TESTS), $(SRC_DATETIME:.c=.o))
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

# Matrix

SRC_MATRIKS = libs/matrix/matrixchar.c libs/sederhana/pcolor.c libs/machine/charmachine.c
SRC_MATRIKS_TEST = tests/matrix/mmatrix.c
OBJ_MATRIKS = $(subst $(SRC_LIBS), $(SRC_TESTS), $(SRC_MATRIKS:.c=.o))
OBJ_MATRIKS_TEST = $(SRC_MATRIKS_TEST:.c=.o)
EXEC_MATRIKS_TEST = $(basename $(SRC_MATRIKS_TEST))

MATRIKS_TEST_DIR = tests/matrix
MATRIKS_TEST_CASES = $(wildcard $(MATRIKS_TEST_DIR)/*.in)
MATRIKS_TEST_OUTPUTS = $(MATRIKS_TEST_CASES:.in=.out)
MATRIKS_TEST_RESULTS = $(MATRIKS_TEST_CASES:.in=.result)

mmatrix: $(OBJ_MATRIKS) $(OBJ_MATRIKS_TEST)
	$(CC) $(CFLAGS) -o $(EXEC_MATRIKS_TEST) $^

test_matrix: $(EXEC_MATRIKS_TEST) $(MATRIKS_TEST_RESULTS)
	@cat $(MATRIKS_TEST_RESULTS)

$(MATRIKS_TEST_RESULTS): $(MATRIKS_TEST_DIR)/%.result: $(MATRIKS_TEST_DIR)/%.in $(MATRIKS_TEST_DIR)/%.out $(EXEC_MATRIKS_TEST)
	@if $(EXEC_MATRIKS_TEST) < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

# Stack

SRC_STACK = libs/stack/stackdraft.c $(SRC_DATETIME)
SRC_STACK_TEST = tests/stack/mstackdraft.c
OBJ_STACK = $(subst $(SRC_LIBS), $(SRC_TESTS), $(SRC_STACK:.c=.o))
OBJ_STACK_TEST = $(SRC_STACK_TEST:.c=.o)
EXEC_STACK_TEST = $(basename $(SRC_STACK_TEST))

STACK_TEST_DIR = tests/stack
STACK_TEST_CASES = $(wildcard $(STACK_TEST_DIR)/*.in)
STACK_TEST_OUTPUTS = $(STACK_TEST_CASES:.in=.out)
STACK_TEST_RESULTS = $(STACK_TEST_CASES:.in=.result)

mstack: $(OBJ_STACK) $(OBJ_STACK_TEST)
	$(CC) $(CFLAGS) -o $(EXEC_STACK_TEST) $^

test_stack: $(EXEC_STACK_TEST) $(STACK_TEST_RESULTS)
	@cat $(STACK_TEST_RESULTS)

$(STACK_TEST_RESULTS): $(STACK_TEST_DIR)/%.result: $(STACK_TEST_DIR)/%.in $(STACK_TEST_DIR)/%.out $(EXEC_STACK_TEST)
	@if $(EXEC_STACK_TEST) < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

SRC_MESINIO = $(wildcard libs/machine/*.c) libs/list/listlinierchar.c
OBJ_MESINIO = $(subst libs, tests, $(SRC_MESINIO:.c=.o))

# BALASAN

SRC_BALASAN = $(wildcard libs/tree/*.c) $(SRC_DATETIME) $(SRC_MESINIO) libs/list/listdin.c
SRC_BALASAN_TEST = tests/tree/mtree.c
OBJ_BALASAN = $(subst $(SRC_LIBS), $(SRC_TESTS), $(SRC_BALASAN:.c=.o))
OBJ_BALASAN_TEST = $(SRC_BALASAN_TEST:.c=.o)
EXEC_BALASAN_TEST = $(basename $(SRC_BALASAN_TEST))

BALASAN_TEST_DIR = tests/tree
BALASAN_TEST_CASES = $(wildcard $(BALASAN_TEST_DIR)/*.in)
BALASAN_TEST_OUTPUTS = $(BALASAN_TEST_CASES:.in=.out)
BALASAN_TEST_RESULTS = $(BALASAN_TEST_CASES:.in=.result)

mtree: $(OBJ_BALASAN) $(OBJ_BALASAN_TEST)
	$(CC) $(CFLAGS) -o $(EXEC_BALASAN_TEST) $^

test_tree: $(EXEC_BALASAN_TEST) $(BALASAN_TEST_RESULTS)
	@cat $(BALASAN_TEST_RESULTS)

$(BALASAN_TEST_RESULTS): $(BALASAN_TEST_DIR)/%.result: $(BALASAN_TEST_DIR)/%.in $(BALASAN_TEST_DIR)/%.out $(EXEC_BALASAN_TEST)
	@if $(EXEC_BALASAN_TEST) < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

# ListDin

SRC_LISTDIN = libs/list/listdinkicau.c $(SRC_DATETIME) $(SRC_MESINIO) $(SRC_BALASAN)
SRC_LISTDIN_TEST = tests/list/mlistdin.c
OBJ_LISTDIN = $(subst $(SRC_LIBS), $(SRC_TESTS), $(SRC_LISTDIN:.c=.o))
OBJ_LISTDIN_TEST = $(SRC_LISTDIN_TEST:.c=.o)
EXEC_LISTDIN_TEST = $(basename $(SRC_LISTDIN_TEST))

LISTDIN_TEST_DIR = tests/list
LISTDIN_TEST_CASES = $(wildcard $(LISTDIN_TEST_DIR)/*.in)
LISTDIN_TEST_OUTPUTS = $(LISTDIN_TEST_CASES:.in=.out)
LISTDIN_TEST_RESULTS = $(LISTDIN_TEST_CASES:.in=.result)

mlistdin: $(OBJ_LISTDIN) $(OBJ_LISTDIN_TEST)
	$(CC) $(CFLAGS) -o $(EXEC_LISTDIN_TEST) $^

test_listdin: $(EXEC_LISTDIN_TEST) $(LISTDIN_TEST_RESULTS)
	@cat $(LISTDIN_TEST_RESULTS)

$(LISTDIN_TEST_RESULTS): $(LISTDIN_TEST_DIR)/%.result: $(LISTDIN_TEST_DIR)/%.in $(LISTDIN_TEST_DIR)/%.out $(EXEC_LISTDIN_TEST)
	@if $(EXEC_LISTDIN_TEST) < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

# Queue
SRC_QUEUE = libs/queue/prioqueuefriendreq.c
SRC_QUEUE_TEST = tests/queue/mqueue.c
OBJ_QUEUE = $(subst $(SRC_LIBS), $(SRC_TESTS), $(SRC_QUEUE:.c=.o))
OBJ_QUEUE_TEST = $(SRC_QUEUE_TEST:.c=.o)
EXEC_QUEUE_TEST = $(basename $(SRC_QUEUE_TEST))

QUEUE_TEST_DIR = tests/queue
QUEUE_TEST_CASES = $(wildcard $(QUEUE_TEST_DIR)/*.in)
QUEUE_TEST_OUTPUTS = $(QUEUE_TEST_CASES:.in=.out)
QUEUE_TEST_RESULTS = $(QUEUE_TEST_CASES:.in=.result)

mqueue: $(OBJ_QUEUE) $(OBJ_QUEUE_TEST)
	$(CC) $(CFLAGS) -o $(EXEC_QUEUE_TEST) $^

test_queue: $(EXEC_QUEUE_TEST) $(QUEUE_TEST_RESULTS)
	@cat $(QUEUE_TEST_RESULTS)

$(QUEUE_TEST_RESULTS): $(QUEUE_TEST_DIR)/%.result: $(QUEUE_TEST_DIR)/%.in $(QUEUE_TEST_DIR)/%.out $(EXEC_QUEUE_TEST)
	@if $(EXEC_QUEUE_TEST) < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@


# GRAF

SRC_GRAF = libs/graph/graphfriendship.c libs/matrix/matrixint.c libs/list/liststatikint.c
SRC_GRAF_TEST = tests/graph/mgraph.c
OBJ_GRAF = $(subst $(SRC_LIBS), $(SRC_TESTS), $(SRC_GRAF:.c=.o))
OBJ_GRAF_TEST = $(SRC_GRAF_TEST:.c=.o)
EXEC_GRAF_TEST = $(basename $(SRC_GRAF_TEST))

GRAF_TEST_DIR = tests/graph
GRAF_TEST_CASES = $(wildcard $(GRAF_TEST_DIR)/*.in)
GRAF_TEST_OUTPUTS = $(GRAF_TEST_CASES:.in=.out)
GRAF_TEST_RESULTS = $(GRAF_TEST_CASES:.in=.result)

mgraf: $(OBJ_GRAF) $(OBJ_GRAF_TEST)
	$(CC) $(CFLAGS) -o $(EXEC_GRAF_TEST) $^

test_graf: $(EXEC_GRAF_TEST) $(GRAF_TEST_RESULTS)
	@cat $(GRAF_TEST_RESULTS)

$(GRAF_TEST_RESULTS): $(GRAF_TEST_DIR)/%.result: $(GRAF_TEST_DIR)/%.in $(GRAF_TEST_DIR)/%.out $(EXEC_GRAF_TEST)
	@if $(EXEC_GRAF_TEST) < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

# UTAS

SRC_UTAS = libs/list/listlinierutas.c
SRC_UTAS_TEST = tests/list/mlistlinier.c
OBJ_UTAS = $(subst $(SRC_LIBS), $(SRC_TESTS), $(SRC_UTAS:.c=.o))
OBJ_UTAS_TEST = $(SRC_UTAS_TEST:.c=.o)
EXEC_UTAS_TEST = $(basename $(SRC_UTAS_TEST))

UTAS_TEST_DIR = tests/list/
UTAS_TEST_CASES = $(wildcard $(UTAS_TEST_DIR)/*.in)
UTAS_TEST_OUTPUTS = $(UTAS_TEST_CASES:.in=.out)
UTAS_TEST_RESULTS = $(UTAS_TEST_CASES:.in=.result)

mlistlinier: $(OBJ_UTAS) $(OBJ_UTAS_TEST)
	$(CC) $(CFLAGS) -o $(EXEC_UTAS_TEST) $^

test_listlinier: $(EXEC_UTAS_TEST) $(UTAS_TEST_RESULTS)
	@cat $(UTAS_TEST_RESULTS)

$(UTAS_TEST_RESULTS): $(UTAS_TEST_DIR)/%.result: $(UTAS_TEST_DIR)/%.in $(UTAS_TEST_DIR)/%.out $(EXEC_UTAS_TEST)
	@if $(EXEC_UTAS_TEST) < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

# USER

# SRC_USER = libs/sederhana/user.c libs/sederhana/profilepicture.c $(SRC_MATRIKS) $(SRC_STACK) $(SRC_MESINIO) $(SRC_QUEUE)
# SRC_USER_TEST = tests/sederhana/muser.c
# OBJ_USER = $(subst $(SRC_LIBS), $(SRC_TESTS), $(SRC_USER:.c=.o))
# OBJ_USER_TEST = $(SRC_USER_TEST:.c=.o)
# EXEC_USER_TEST = $(basename $(SRC_USER_TEST))

# USER_TEST_DIR = tests/sederhana
# USER_TEST_CASES = $(wildcard $(USER_TEST_DIR)/*.in)
# USER_TEST_OUTPUTS = $(USER_TEST_CASES:.in=.out)
# USER_TEST_RESULTS = $(USER_TEST_CASES:.in=.result)

# muser: $(OBJ_USER) $(OBJ_USER_TEST)
# 	$(CC) $(CFLAGS) -o $(EXEC_USER_TEST) $^

# test_user: $(EXEC_USER_TEST) $(USER_TEST_RESULTS)
# 	@cat $(USER_TEST_RESULTS)

# $(USER_TEST_RESULTS): $(USER_TEST_DIR)/%.result: $(USER_TEST_DIR)/%.in $(USER_TEST_DIR)/%.out $(EXEC_USER_TEST)
# 	@if $(EXEC_USER_TEST) < $< | diff - $(word 2,$^) > /dev/null; then \
# 		echo "$< $(word 2,$^): TRUE"; \
# 	else \
# 		echo "$< $(word 2,$^): WRONG"; \
# 	fi > $@