# make LINK=.so
# make LINK=.a
SRCS := main.c
target := test_main

cflags := -I../include
ifeq ($(LINK), .so)
cflags += -DLINK_SO
# cflags += -DLINK_SO1
cflags += -DLINK_SO2
ldflags := -L../shared
libs := -ldl
else
ldflags := -L../static
# libs := -lmainmath
libs := -lmainmath2
libs += -ldl
endif

.PHONY : clean all

all: $(target)

$(target): $(SRCS)
	gcc -o $(target) $(SRCS) $(cflags) $(ldflags) $(libs)

clean:
	-rm -f $(target) *.o 
