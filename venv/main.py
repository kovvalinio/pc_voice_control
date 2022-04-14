import os
import inp
import speech_recognition as sr
import pyttsx3 as tts
import re
import subprocess
import sys


r = sr.Recognizer()
engine = tts.init()
engine.setProperty('rate', 100);
voices = engine.getProperty('voices')
engine.setProperty('voice',voices[2].id)
def mow(text):
    engine.say(text)
    engine.runAndWait()

def small_letters(text):
    for i in range(len(text)):
        if ord(text[i]) <= 90 and ord(text[i]) >= 65:
           text=  text[:i] + chr(ord(text[i]) +32) + text[i+1:]
    return text

def getText():
    with sr.Microphone() as source:
        try:
            print("słucham...")
            audio = r.listen(source)
            text =r.recognize_google(audio, language='pl-PL')
            if text != "":
                return text
            return 0
        except:
            return 0

def fing_pattern_naive_algorithm(text, pattern):
    text_len = len(text)
    pattern_len = len(pattern)
    i =0
    j =0
    for i in range(text_len - pattern_len+1):
        variable = range(text_len - pattern_len)
        pattern_match = True
        for j in range(len(pattern)):
            if text[i + j] != pattern[j]:
                pattern_match = False
                break
        if pattern_match:
            return i
    return -1

def identify_command(text):
    komputer_p = "komputer"

    text = small_letters(text)

    if fing_pattern_naive_algorithm(text, komputer_p) != -1:

        file_buff = open("C:/Users/Michal/OneDrive/Documents/voice_control/config.txt",encoding='UTF-8')


        while True:

            file_line = file_buff.readline()
            path=get_p(file_line)
            command = get_c(file_line)

            if not file_line:
                print("niewłaściwa komenda")
                break
            if fing_pattern_naive_algorithm(text, command) != -1:

                os.startfile(path)
                break



def get_p(line):

    for i in range(len(line)):
        if line[i] == ";":

            path = line[i+1:len(line)-1]

            return path


def get_c(line):
    for i in range(len(line)):
        if line[i] == ";":
            command = line[:i]

            return command








while True:
    txt = getText()
    if not txt == 0:

        identify_command(txt)
#        print(txt)
        print("okej")

    else:
        print("nie udalo sie rozpoznac textu")
        continue



