#!/usr/bin/env python

import RPi.GPIO as GPIO
import time

from rpi_bp_pwm_bz1a_1 import *

if __name__ == ("__main__") :
  #start

  doremi = {"Do":220.0, "Re":246.9, "Mi":277.2, "Fa":293.7, "Sol":329.6, "La":370.0, "Si":415.3, "Do_":440.0 }

  cyocyo = ["Sol", "Mi", "Mi","Fa","Re","Re"]
  GPIO.setmode(GPIO.BCM) # use GPIO Number

  BZ1 = 13 # BZ1 --> GPIO13
  tone1=tone_init(BZ1)

  tone1.start(50)

  for scale in cyocyo:
    print(scale)
    freq = doremi[scale]
    tone1.ChangeFrequency(freq)
    time.sleep(1)

  tone1.stop() # stop tone

