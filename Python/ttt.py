class TicTacToe:
    def __init__(self):
        self.currentplayer = 1
        self.filled = 0 
        self.board =  [[' ' for i in range(3) ] for j in range(3)]
        for i in range(3):
            for j in range(3):
                self.board[i][j] = str(3*i + j + 1) 


    def printboard(self):       #           gameboard
        
        print('   |   |')
        print(' ' + self.board[0][0] + ' | ' + self.board[0][1] + ' | ' + self.board[0][2])
        print('   |   |')
        print('-----------')

        print('   |   |')
        print(' ' + self.board[1][0] + ' | ' + self.board[1][1] + ' | ' + self.board[1][2])
        print('   |   |')
        print('-----------')

        print('   |   |')
        print(' ' + self.board[2][0] + ' | ' + self.board[2][1] + ' | ' + self.board[2][2])
        print('   |   |')

    def askformove(self):
        
        num = input("Choose between number 1-9\n")
        row = int((num-1)/3)
        col = (num%3)-1
        if self.board[row][col] == 'X' or self.board[row][col] == 'O':
            print "Position Already Taken, Try Again"
            return

        self.filled+=1
        if(self.currentplayer == 1):
            self.board[row][col] = 'X'
            self.currentplayer = self.currentplayer * -1
    
        elif(self.currentplayer == -1):
            self.board[row][col] = 'O'
            self.currentplayer = self.currentplayer * -1
    
    def startGame(self):
        self.printboard()
        while(self.filled <= 9):
            self.askformove()
            self.printboard()
            wincond = self.wincond()
            if wincond == 1 :
                break

    
    def wincond(self):      #           Checks whether someone has won already
        horizontalW = self.horizontalW()
        if horizontalW:
            print "Horizontal Win!"
            return 1
        verticalW = self.verticalW()
        if verticalW:
            print "Vertical Win"
            return 1
        diagonalW = self.diagonalW()
        if diagonalW:
            print "Diagonal Win"
            return 1
        else:
            return 0


    def horizontalW(self):      #           checks for any horizontal win
        for i in range(3):
            if self.board[i][0] == self.board[i][1] == self.board[i][2]:
                return self.board[i][0]
        return None

    def verticalW(self):        #           Vertical Win possibility
        for i in range(3):
            if self.board[0][i] == self.board[1][i] == self.board[2][i]:
                return self.board[0][i]
        return None
    
    def diagonalW(self):        #           Only 2 choices of diagonal win
        if self.board[0][0] == self.board[1][1] == self.board[2][2]:
            return self.board[0][0]
        elif self.board[0][2] == self.board[1][1] == self.board[2][0]:
            return self.board[0][2]
        return None
                


            






gameboard = TicTacToe()
gameboard.startGame()