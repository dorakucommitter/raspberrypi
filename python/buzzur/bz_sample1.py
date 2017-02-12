#!/usr/bin/env python

import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM) # use GPIO Number

BZ1 = 13 # BZ1 --> GPIO13
GPIO.setup(BZ1, GPIO.OUT) # set GPIO13 output

buzzer = GPIO.PWM(BZ1, 1000) # set BZ1 1000 Hz

buzzer.start(50) # start BZ1 duty 50%
print(" buzzer 1000 Hz ,duty 50 %")
time.sleep(3)

buzzer.ChangeFrequency(500) # change frequency 500 Hz
print(" change 500 Hz ")
time.sleep(3)

buzzer.ChangeDutyCycle(10) # change duty cycle 10 %
print(" duty 10 % ")
time.sleep(3)

buzzer.stop() # stop buzzer
GPIO.cleanup()

