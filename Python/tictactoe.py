import Tkinter
import tkMessageBox


class TicTacToe:

    def __init__(self,window):
        self.buttons = [0 for i in range(9)]
        self.currentPlayer = 1      # multiply -1 to change the current player
        #button1 = Tkinter.Button(window,text=" ",font=('Times 20 bold'),bg='gray',fg='white',height=4,width=8,command=lambda:self.changeText(button1))
        #button1.grid(row=1, column=0)
        self.buttons[0] = Tkinter.Button(window,text=" ",font=('Times 20 bold'),bg='gray',fg='white',height=4,width=8,command=lambda:self.changeText(self.buttons[0]))
        self.buttons[0].grid(row=1, column =1)

        self.buttons[1] = Tkinter.Button(window,text=" ",font=('Times 20 bold'),bg='gray',fg='white',height=4,width=8,command=lambda:self.changeText(self.buttons[1]))
        self.buttons[1].grid(row=1, column =2)

        self.buttons[2] = Tkinter.Button(window,text=" ",font=('Times 20 bold'),bg='gray',fg='white',height=4,width=8,command=lambda:self.changeText(self.buttons[2]))
        self.buttons[2].grid(row=1, column =3)

        self.buttons[3] = Tkinter.Button(window,text=" ",font=('Times 20 bold'),bg='gray',fg='white',height=4,width=8,command=lambda:self.changeText(self.buttons[3]))
        self.buttons[3].grid(row=2, column =1)

        self.buttons[4] = Tkinter.Button(window,text=" ",font=('Times 20 bold'),bg='gray',fg='white',height=4,width=8,command=lambda:self.changeText(self.buttons[4]))
        self.buttons[4].grid(row=2, column =2)

        self.buttons[5] = Tkinter.Button(window,text=" ",font=('Times 20 bold'),bg='gray',fg='white',height=4,width=8,command=lambda:self.changeText(self.buttons[5]))
        self.buttons[5].grid(row=2, column =3)

        self.buttons[6] = Tkinter.Button(window,text=" ",font=('Times 20 bold'),bg='gray',fg='white',height=4,width=8,command=lambda:self.changeText(self.buttons[6]))
        self.buttons[6].grid(row=3, column =1)
        
        self.buttons[7] = Tkinter.Button(window,text=" ",font=('Times 20 bold'),bg='gray',fg='white',height=4,width=8,command=lambda:self.changeText(self.buttons[7]))
        self.buttons[7].grid(row=3, column =2)

        self.buttons[8] = Tkinter.Button(window,text=" ",font=('Times 20 bold'),bg='gray',fg='white',height=4,width=8,command=lambda:self.changeText(self.buttons[8]))
        self.buttons[8].grid(row=3, column =3)


    def changeText(self,button):
        
        if button["text"] != ' ':
            print 'skip'
        
        elif self.currentPlayer == 1:
            button["text"] = 'X'
            self.currentPlayer = self.currentPlayer * -1

        elif self.currentPlayer == -1:
            button["text"] = 'O'
            self.currentPlayer = self.currentPlayer * -1
        #tkMessageBox.showinfo("Alert!", "Time to fly")

    
        


window = Tkinter.Tk()
window.title("TicTacToe")

game = TicTacToe(window)
window.mainloop()