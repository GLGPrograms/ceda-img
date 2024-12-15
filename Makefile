.PHONY: all
all: cedaimg cge.bin

cge.bin: genrom
	./genrom > cge.bin

.PHONY: clean
clean:
	rm -f cedaimg cge.bin genrom

