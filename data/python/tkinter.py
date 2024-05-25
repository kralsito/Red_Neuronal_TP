import tkinter as tk
from tkinter import messagebox

def on_button_click():
    messagebox.showinfo("Information", "Button clicked!")

app = tk.Tk()
app.title("My Tkinter App")

label = tk.Label(app, text="Hello, Tkinter!")
label.pack()

button = tk.Button(app, text="Click Me", command=on_button_click)
button.pack()

app.mainloop()
