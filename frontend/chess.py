# chess_pyside6.py
import sys
from PySide6.QtWidgets import QApplication, QMainWindow, QWidget 
from PySide6.QtGui import QPainter, QColor
from PySide6.QtCore import QRect
from PySide6.QtSvg import QSvgRenderer

# ---------- DATA ----------

board = [
    "r",
    "n",
    "b",
    "q",
    "k",
    "b",
    "n",
    "r",
    "p",
    "p",
    "p",
    "p",
    "p",
    "p",
    "p",
    "p",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "P",
    "P",
    "P",
    "P",
    "P",
    "P",
    "P",
    "P",
    "R",
    "N",
    "B",
    "Q",
    "K",
    "B",
    "N",
    "R",
]

SVG = {
    "p": "data/pawn-b.svg",
    "P": "data/pawn-w.svg",
    "r": "data/rook-b.svg",
    "R": "data/rook-w.svg",
    "n": "data/knight-b.svg",
    "N": "data/knight-w.svg",
    "b": "data/bishop-b.svg",
    "B": "data/bishop-w.svg",
    "q": "data/queen-b.svg",
    "Q": "data/queen-w.svg",
    "k": "data/king-b.svg",
    "K": "data/king-w.svg",
}

class DrawBoard(QWidget):
    def __init__(self, board):
        super().__init__()

        self.board = board

    def drawboard(self, painter):
        x = 0
        y = 0

        newline = 0 

        boxHeight = self.height() // 8 
        boxWidth = self.width() // 8

        color = False 


        for i in self.board: 
            if color == False:
                painter.setBrush(QColor("#B58863"))
                painter.setPen(QColor("#B58863"))   # border color
            else:
                painter.setBrush(QColor("#EFD8B4"))
                painter.setPen(QColor("#EFD8B4"))   # border color
                

            painter.drawRect(x, y, boxWidth, boxWidth)
            x += boxWidth
            if color == False:
                color = True
            else:
                color = False  

        # painter.setBrush(QColor("red"))   # fill color
        # painter.setPen(QColor("black"))   # border color

        painter.drawRect(x, y, boxWidth, boxHeight)
    def paintEvent(self, event):
        painter = QPainter(self)
        self.drawboard(painter)




app = QApplication(sys.argv)
window = DrawBoard(board) 
# window.drawboard()

window.setWindowTitle("Chess")
window.resize(1000, 800)

window.show()
app.exec()
