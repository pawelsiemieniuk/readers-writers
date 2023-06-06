.PHONY = build-wstarv build-rstarv build-exclude

CC = gcc

BASENAME = readers-writers
FILENAME_1 = $(BASENAME)-wstarv
FILENAME_2 = $(BASENAME)-rstarv
FILENAME_3 = $(BASENAME)-exclude

BINDIR = bin/
BASEDIRS = . ./src
DIRS_1 = $(BASEDIRS) ./src/wstarv
DIRS_2 = $(BASEDIRS) ./src/rstarv
DIRS_3 = $(BASEDIRS) ./src/exclude

CFILES_1 = $(foreach D,$(DIRS_1),$(wildcard $(D)/*.c))
CFILES_2 = $(foreach D,$(DIRS_2),$(wildcard $(D)/*.c))
CFILES_3 = $(foreach D,$(DIRS_3),$(wildcard $(D)/*.c))

CFLAGS = -Wall -pthread


all: $(FILENAME_1) $(FILENAME_2) $(FILENAME_3)

build-wstarv: $(FILENAME_1)

$(FILENAME_1):$(CFILES_1)
	$(CC) $(CFLAGS) -o $(BINDIR)$@ $^

build-rstarv: $(FILENAME_2)

$(FILENAME_2):$(CFILES_2)
	$(CC) $(CFLAGS) -o $(BINDIR)$@ $^

build-exclude: $(FILENAME_3)

$(FILENAME_3):$(CFILES_3)
	$(CC) $(CFLAGS) -o $(BINDIR)$@ $^