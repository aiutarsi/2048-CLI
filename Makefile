CC = gcc

SRC-DIR = src

PFM-DIR = printFrontMenu
PFM-R-DIR = reset

P2-DIR = process2048
P2-GNR-DIR = generateNumberRandomly
P2-PB-DIR = printBoard
P2-PB-L-DIR = printBoardLeftSide
P2-PB-R-DIR = printBoardRightSide
P2-S-DIR = shift
P2-J-DIR = judge
P2-CSD-DIR = confirmSaveData
P2-H-DIR = history

MATH-DIR = math

RS-DIR = readSheet

WS-DIR = writeSheet

WHS-DIR = whichStart

CFLAGS = -Wall


PFM-R-OBJS = $(SRC-DIR)/$(PFM-DIR)/$(PFM-R-DIR)/resetAllData.o $(SRC-DIR)/$(PFM-DIR)/$(PFM-R-DIR)/resetInput.o

PFM-OBJS = $(SRC-DIR)/$(PFM-DIR)/printFrontMenu.o $(SRC-DIR)/$(PFM-DIR)/printFrontMenuHighScore.o $(SRC-DIR)/$(PFM-DIR)/printFrontMenuOrdinal.o $(SRC-DIR)/$(PFM-DIR)/printFrontMenuBoardSize.o $(PFM-R-OBJS)


P2-GNR-OBJS = $(SRC-DIR)/$(P2-DIR)/$(P2-GNR-DIR)/generateNumberRandomly.o $(SRC-DIR)/$(P2-DIR)/$(P2-GNR-DIR)/generateNumberRandomlyAtFirst.o

P2-PB-L-OBJS = $(SRC-DIR)/$(P2-DIR)/$(P2-PB-DIR)/$(P2-PB-L-DIR)/printBoxes.o $(SRC-DIR)/$(P2-DIR)/$(P2-PB-DIR)/$(P2-PB-L-DIR)/printFillSpace.o

P2-PB-R-OBJS = $(SRC-DIR)/$(P2-DIR)/$(P2-PB-DIR)/$(P2-PB-R-DIR)/printBoardRightSide.o $(SRC-DIR)/$(P2-DIR)/$(P2-PB-DIR)/$(P2-PB-R-DIR)/printBoardRightSideOrdinal.o $(SRC-DIR)/$(P2-DIR)/$(P2-PB-DIR)/$(P2-PB-R-DIR)/printBoardRightSideShiftArrow.o $(SRC-DIR)/$(P2-DIR)/$(P2-PB-DIR)/$(P2-PB-R-DIR)/printBoardRightSideScore.o $(SRC-DIR)/$(P2-DIR)/$(P2-PB-DIR)/$(P2-PB-R-DIR)/printBoardRightSideGoBack.o $(SRC-DIR)/$(P2-DIR)/$(P2-PB-DIR)/$(P2-PB-R-DIR)/printBoardRightSideUndoArrow.o

P2-PB-OBJS = $(SRC-DIR)/$(P2-DIR)/$(P2-PB-DIR)/printBoard.o $(SRC-DIR)/$(P2-DIR)/$(P2-PB-DIR)/printBoardMessage.o $(P2-PB-L-OBJS) $(P2-PB-R-OBJS)

P2-S-OBJS = $(SRC-DIR)/$(P2-DIR)/$(P2-S-DIR)/shiftUp.o $(SRC-DIR)/$(P2-DIR)/$(P2-S-DIR)/shiftDown.o $(SRC-DIR)/$(P2-DIR)/$(P2-S-DIR)/shiftLeft.o $(SRC-DIR)/$(P2-DIR)/$(P2-S-DIR)/shiftRight.o

P2-J-OBJS = $(SRC-DIR)/$(P2-DIR)/$(P2-J-DIR)/judgeShiftUp.o $(SRC-DIR)/$(P2-DIR)/$(P2-J-DIR)/judgeShiftDown.o $(SRC-DIR)/$(P2-DIR)/$(P2-J-DIR)/judgeShiftLeft.o $(SRC-DIR)/$(P2-DIR)/$(P2-J-DIR)/judgeShiftRight.o $(SRC-DIR)/$(P2-DIR)/$(P2-J-DIR)/judgeExist2048.o $(SRC-DIR)/$(P2-DIR)/$(P2-J-DIR)/judgeGameOver.o $(SRC-DIR)/$(P2-DIR)/$(P2-J-DIR)/judgeOverFlow.o

P2-CSD-OBJS = $(SRC-DIR)/$(P2-DIR)/$(P2-CSD-DIR)/confirmSaveData.o $(SRC-DIR)/$(P2-DIR)/$(P2-CSD-DIR)/printConfirmSaveData.o

P2-H-OBJS = $(SRC-DIR)/$(P2-DIR)/$(P2-H-DIR)/fetchHistory.o $(SRC-DIR)/$(P2-DIR)/$(P2-H-DIR)/recordHistory.o

P2-OBJS = $(SRC-DIR)/$(P2-DIR)/process2048.o $(P2-GNR-OBJS) $(P2-PB-OBJS) $(P2-S-OBJS) $(P2-CSD-OBJS) $(P2-H-OBJS) $(P2-J-OBJS)

MATH-OBJS = $(SRC-DIR)/$(MATH-DIR)/calculateDigitNumber.o $(SRC-DIR)/$(MATH-DIR)/decimalToBinary.o

RS-OBJS = $(SRC-DIR)/$(RS-DIR)/readBoardSideSheet.o $(SRC-DIR)/$(RS-DIR)/readHighScoreSheet.o $(SRC-DIR)/$(RS-DIR)/existSaveData.o $(SRC-DIR)/$(RS-DIR)/readSaveData.o $(SRC-DIR)/$(RS-DIR)/readHistorySaveData.o

WS-OBJS = $(SRC-DIR)/$(WS-DIR)/writeHighScoreSheet.o $(SRC-DIR)/$(WS-DIR)/writeSaveData.o $(SRC-DIR)/$(WS-DIR)/writeHistorySaveData.o

WHS-OBJS = $(SRC-DIR)/$(WHS-DIR)/whichStart.o $(SRC-DIR)/$(WHS-DIR)/printWhichStart.o

OBJS = $(SRC-DIR)/main.o $(PFM-OBJS) $(P2-OBJS) $(MATH-OBJS) $(RS-OBJS) $(WS-OBJS) $(WHS-OBJS)

TARGET = 2048

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
