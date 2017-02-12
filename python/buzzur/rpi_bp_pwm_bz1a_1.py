#!/usr/bin/env python

import RPi.GPIO as GPIO
import time

def tone_init(bz):
  GPIO.setup(bz, GPIO.OUT) # set GPIO bz output
  buzzer = GPIO.PWM(bz, 1000) # set bz 1000 Hz
  return buzzer

if __name__ == ("__main__") :
  #start
  GPIO.setmode(GPIO.BCM) # use GPIO Number

  BZ1 = 13 # BZ1 --> GPIO13
  tone1=tone_init(BZ1)

  tone1.start(50)
  print(" buzzer 1000 Hz ,duty 50 %")
  time.sleep(5)

  tone1.ChangeFrequency(500) # change frequency 500 Hz
  print(" change 500 Hz ")
  time.sleep(5)

  tone1.ChangeDutyCycle(10) # change duty cycle 10 %
  print(" duty 10 % ")
  time.sleep(5)

  tone1.stop() # stop tone
  GPIO.cleanup()

