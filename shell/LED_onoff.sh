#!/bin/bash
# BCM5,6に接続したLEDを交互に点滅させるシェルです。

# BCM 5を使う
echo 5 > /sys/class/gpio/export
# BCM 6を使う
echo 6 > /sys/class/gpio/export

sleep 1    # このsleepが結構重要

# BCM 5を出力設定にする
echo out > /sys/class/gpio/gpio5/direction
echo out > /sys/class/gpio/gpio6/direction

for((i=0; i<15; i++)); do
  # BCM 5の出力をHighにする。⇒ LED点灯
  # BCM 6の出力をLow にする。⇒ LED消灯
  echo 1 > /sys/class/gpio/gpio5/value
  echo 0 > /sys/class/gpio/gpio6/value
  sleep 1

  # BCM 5の出力をLow にする。⇒ LED消灯
  # BCM 6の出力をHighにする。⇒ LED点灯
  echo 0 > /sys/class/gpio/gpio5/value
  echo 1 > /sys/class/gpio/gpio6/value
  sleep 1
done

# BCM 5を開放する
echo 5 > /sys/class/gpio/unexport
# BCM 6を開放する
echo 6 > /sys/class/gpio/unexport

