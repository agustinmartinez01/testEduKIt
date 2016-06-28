import serial
import conexionUSB
import holamundo
import sys
import os
def offleds_Click(a):
        #puerto="/dev/{0}".format +(os.system("tail  /var/log/syslog | grep 'ch341-uart converter now attached to ' | awk '{print $NF}'"))
        #print (puerto)
        #arduino = serial.Serial(puerto, 9600, timeout = 3.0)
        #for x in range(0, 5):
    if a.CheckLeds2.isChecked():
        arduino.write('Leds2\n')
    if a.CheckLeds3.isChecked():
        arduino.write('Leds3\n')
    if a.CheckLeds3_2.isChecked():
        arduino.write('Leds4\n')
    if a.CheckLeds7.isChecked():
        arduino.write('Leds7\n')
    if a.CheckLeds8.isChecked():
        arduino.write('Leds8\n')
    if a.CheckLeds9.isChecked():
        arduino.write('Leds9\n')
    #arduino.close()

def onleds_Click(self):
    if self.CheckLeds2.isChecked():
        arduino.write('OnLeds2\n')
    if self.CheckLeds3.isChecked():
        arduino.write('OnLeds3\n')
    if self.CheckLeds3_2.isChecked():
        arduino.write('OnLeds4\n')
    if self.CheckLeds7.isChecked():
        arduino.write('OnLeds7\n')
    if self.CheckLeds8.isChecked():
        arduino.write('OnLeds8\n')
    if self.CheckLeds9.isChecked():
        arduino.write('OnLeds9\n')

def obtenerValorLDR(self):
    arduino.write('LDR\n')
    #arduino.read(valor)
    self.lcdLdr.display('255\n')

def girarServo10(self):
    arduino.write('girarServo10\n')
    #arduino.write(self.gradosServo10.text())
    print(self.gradosServo10.text())

def girarServo11(self):
        arduino.write('girarServo11\n')
        #arduino.write(self.gradosServo11.text())
        print(self.gradosServo11.text())

def girarMotorI(self):
    arduino.write('GirarMotorIzqr\n')

def frenarMotorI(self):
    arduino.write('FrenarMotorIzq\n') 

def girarMotorD(self):
    arduino.write('GirarMotorDer\n')

def frenarMotorD(self):
    arduino.write('FrenarMotorDer\n')

def encenderBocina(self):
    print (self.lineEdit_Frecuencia.text())
    print (self.lineEdit_Time.text())
    arduino.write('Bocina\n')

def probarInterruptores(self):
    getSerial=arduino.write('Interruptores\n')
    i = 0
    while (i<=1000000):
        i=i+1
        inte = arduino.read()
        print (inte)
    print ('aaaa')