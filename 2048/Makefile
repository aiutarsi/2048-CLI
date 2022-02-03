CC = gcc

SRCDIR = src
PFMDIR = printFrontMenu

CFLAGS = -Wall

PFMOBJS = $(SRCDIR)/$(PFMDIR)/calculateDigitNumber.o $(SRCDIR)/$(PFMDIR)/printFrontMenu.o $(SRCDIR)/$(PFMDIR)/printFrontMenuHighScore.o $(SRCDIR)/$(PFMDIR)/printFrontMenuOrdinal.o $(SRCDIR)/$(PFMDIR)/readHighScoreSheet.o
OBJS = $(SRCDIR)/main.o $(PFMOBJS)
TARGET = 2048

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
