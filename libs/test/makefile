# make LINK=.so
# make LINK=.a
SRCS := main.c
target := test_math

cflags := -I../include
ifeq ($(LINK), .so)
cflags += -DLINK_SO
ldflags := -L../shared
libs := -ldl
else
ldflags := -L../static
libs := -ltestmath
endif

.PHONY : clean all

all: $(target)

$(target): $(SRCS)
	gcc -o $(target) $(SRCS) $(cflags) $(ldflags) $(libs)

clean:
	-rm -f $(target) *.o 
