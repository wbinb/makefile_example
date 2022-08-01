# make LIB=.so
# make LIB=.a
srcs := $(wildcard ./source/*.c)

objs := $(srcs:./source/%.c=./build/%.o)

ifeq ($(LIB), .so)
target := ./shared/libtestmath.so
else
target := ./static/libtestmath.a
endif

cflags := -Iinclude
cflags += -fPIC
ldflags := 

.PHONY : clean all

all: $(target)

$(target): $(objs)
ifeq ($(LIB), .so)
	cc  -shared -o $@ $^
else
	ar -cr $@ $^
endif

$(objs):./build/%.o:./source/%.c
	cc -c $(cflags) $< -o $@ 

clean:
	-rm -f $(objs) $(target)