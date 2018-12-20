import Tkinter

class GeeksBro:

    def __init__(self, window):

        self.text_btn = Tkinter.Button(window, text = "Click Me!", command = self.say_hi) # create a button to call a function called 'say_hi'
        self.text_btn.pack()

        self.close_btn = Tkinter.Button(window, text = "Close", command = window.quit) # closing the 'window' when you click the button
        self.close_btn.pack()

    def say_hi(self):
        Tkinter.Label(window, text = "Hi").pack()

window = Tkinter.Tk()
window.title("GUI")

geeks_bro = GeeksBro(window)

window.mainloop()