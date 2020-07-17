src = $(wildcard *.cpp)
obj = $(src:.cpp=)

CFLAGS = -Wall -g

myprog: $(obj)
	$(GCC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) myprog