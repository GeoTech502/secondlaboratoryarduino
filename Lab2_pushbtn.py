from tkinter.ttk import *
from tkinter import *
import serial,time
import os

arduino = serial.Serial("COM3", 9600)

def closeinterface():
  arduino.close()
  raiz.destroy()

def encenderLED():
  arduino.write(b'0')
  print("El LED ha sido encendido!")
  time.sleep(10)
  arduino.write(b'1')
  print("El LED ha sido apagado!")

def keylogger():
  LED1 = 0
  LED2 = 0
  while True:
    opcion = input("Ingrese la letra A y Y para encender los LEDS o X para salir: ").upper()
    if opcion == 'AY':
      if LED1 == 1 and LED2 == 1:
        LED1 = 0
        LED2 = 0
        print("Se APAGARON LEDS!")
      else:
        LED1 = 1
        LED2 = 1
        print("Se ENCENDIERON LEDS!")
      cad = str(LED1) + "," + str(LED2)
      arduino.write((cad.encode('ascii')))
    elif opcion == 'X':
      print("\nSaliendo del sistema...\n")
      os.system('pause')
      os.system('clear')
      exit(1)
    else:
      print("Opcion no valida...\n")

raiz = Tk()
ancho_ventana = 500
alto_ventana = 250

x_ventana = raiz.winfo_screenwidth() // 2 - ancho_ventana // 2
y_ventana = raiz.winfo_screenheight() // 2 - alto_ventana // 2

posicion = str(ancho_ventana) + "x" + str(alto_ventana) + "+" + str(x_ventana) + "+" + str(y_ventana)
raiz.geometry(posicion)
raiz.title("LAB2 - Arduino y Python")

titleFrame = Frame()
titleFrame.config(bg = "orange",width = "500", height = "110")
titleFrame.place(x = 0, y = 0)

lblTitulo = Label(titleFrame, text = "Encender LEDS con PushButtons", bg="orange", fg = "black", font = ("Times New Roman",15))
lblTitulo.place(x = 120, y = 20)

buttonsFrame = Frame()
buttonsFrame.config(bg = "gray", width= "500", height= "200")
buttonsFrame.place(x = 0, y = 80)

photo = PhotoImage(file = r"C:\Users\BEST COMPUTER\Desktop\Arquitectura de Computadora I\led_icon.png")
photoimage = photo.subsample(2,2)
btnEncender1 =  Button(buttonsFrame, text = ' Encender LED ', image = photoimage, compound=LEFT, command=encenderLED)
btnEncender1.place(x = 200, y = 40)

photo2 = PhotoImage(file = r"C:\Users\BEST COMPUTER\Desktop\Arquitectura de Computadora I\terminal_icon.png")
photoimage2 = photo2.subsample(2,2)
btnTerm =  Button(buttonsFrame, text = ' Modo Terminal ', image = photoimage2, compound=LEFT, command=keylogger)
btnTerm.place(x = 200, y = 80)

photo3 = PhotoImage(file = r"C:\Users\BEST COMPUTER\Desktop\Arquitectura de Computadora I\close_icon.png")
photoimage3 = photo3.subsample(2,2)
btnClose =  Button(buttonsFrame, text = ' Cerrar Interfaz ', image = photoimage3, compound=LEFT, command=closeinterface)
btnClose.place(x = 200, y = 120)

raiz.resizable(0,0)
raiz.mainloop()

