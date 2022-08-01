prog1_srcs := $(wildcard ./prog1/*.c)
prog2_srcs := $(wildcard ./prog2/*.c)

# 表示把 变量 prog1_srcs 中的每个.c 替换为.o
# 例：prog1/build/command.c ==> prog1/build/command.c
# 1
# objs1 := $(prog1_srcs:./prog1/%.c=./prog1/build/%.o)
# objs2 := $(prog2_srcs:./prog2/%.c=./prog2/build/%.o)

# 2
objs1 := $(patsubst ./prog1/%.c, ./prog1/build/%.o, $(prog1_srcs))
objs2 := $(patsubst ./prog2/%.c, ./prog2/build/%.o, $(prog2_srcs))


TARGET1 := ./prog1/edit
TARGET2 := ./prog2/edit

CFLAGS := -Iinclude

all: $(TARGET1) $(TARGET2)

# # $@  表示目标文件
# # $^  表示所有的依赖文件
# # $<  表示第一个依赖文件
${TARGET1}:$(objs1)
	cc -o $@ $^

${TARGET2}:$(objs2)
	cc -o $@ $^

# 静态模式规则
# <targets ...> : <target-pattern> : <prereq-patterns ...>
$(objs1):./prog1/build/%.o:./prog1/%.c
	cc -c $(CFLAGS) $< -o $@ 

$(objs2):./prog2/build/%.o:./prog2/%.c
	cc -c $(CFLAGS) $< -o $@ 

# objs := main_test.o
# $(objs):%.o:%.c
# 	@echo $^
# 	cc -c $< -o $@

.PHONY: clean all
clean:
	-rm -f $(TARGET1) $(TARGET2) $(objs1) $(objs2)
