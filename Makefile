CC = gcc
CFLAGS = -g -Werror -Wextra -Wall

LIB_SRCS = ./KatArrayLib/katarray_voidp_t.c ./KatArrayLib/katarray_helper.c
APP_SRCS = ./koreanTracker/koreanTracker.c

OUT = koreantrack


all: $(OUT)

$(OUT): $(APP_SRCS) $(LIB_SRCS)
	$(CC) $(CFLAGS) $(APP_SRCS) $(LIB_SRCS) -o $(OUT)

clean:
	rm -f $(OUT)