# chess_buttons_inline.py
import sys
from PySide6.QtWidgets import QApplication, QWidget, QPushButton
from PySide6.QtGui import QIcon
from PySide6.QtCore import QRect, QSize

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
        self.buttons = []

    def drawboard(self):
        boxHeight = self.height() // 8
        boxWidth = self.width() // 8

        x = 0
        y = 0
        newline = 0
        color = True

        for index, i in enumerate(self.board):
            btn = QPushButton(self)
            btn.setGeometry(x, y, boxWidth, boxHeight)

            # Set color
            if color:
                btn.setStyleSheet("background-color: #EFD8B4;")
            else:
                btn.setStyleSheet("background-color: #B58863;")

            # Set piece icon
            if i != "0":
                btn.setIcon(QIcon(SVG[i]))
                btn.setIconSize(QSize(boxWidth - 10, boxHeight - 10))

            self.buttons.append(btn)

            newline += 1
            x += boxWidth
            color = not color

            if newline in {8, 16, 24, 32, 40, 48, 56, 64}:
                y += boxHeight
                x = 0
                color = not color

            btn.clicked.connect(lambda checked, idx=index: self.on_button_click(index))

    def on_button_click(self, index):
         piece = self.board[index]
         print(f"Button {index} clicked, piece: {piece}")

    def resizeEvent(self, event):
        # Redraw buttons on resize
        for btn in self.buttons:
            btn.setParent(None)
        self.buttons = []
        self.drawboard()


app = QApplication(sys.argv)
window = DrawBoard(board)
window.setWindowTitle("Chess")
window.resize(800, 800)
window.show()
window.drawboard()
app.exec()
