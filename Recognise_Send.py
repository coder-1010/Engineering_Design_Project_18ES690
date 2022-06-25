global s
def speechToText():
    try:
        with speech_recognition.Microphone() as mic:
            recognizer.adjust_for_ambient_noise(mic,duration=0.2)
            audio=recognizer.listen(mic)
            text=recognizer.recognize_google(audio)
            text=text.lower()
            if(text=='alarm of'):
                text='off'
            if(text=='led of'):
                text='led off'
            print(f"Recognized {text}")
            global s
            s=text
    except Exception as e:
        pass
import speech_recognition
import pyttsx3
recognizer=speech_recognition.Recognizer()
speechToText()

import time
import serial
serialcomm=serial.Serial('COM5',9600)
serialcomm.timeout=1
def sendData():
    i=s
    serialcomm.write(i.encode())
    time.sleep(0.5)
    print(serialcomm.readline().decode('ascii'))
sendData()
serialcomm.close()

