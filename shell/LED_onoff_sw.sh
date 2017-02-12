#!/bin/bash
# スイッチのOn/OffでLEDを交互に点滅／同時に点滅を切り替えるシェルです。

# MCM 5を使う
echo 5 > /sys/class/gpio/export
# BCM 6を使う
echo 6 > /sys/class/gpio/export
# BCM26を使う
echo 26 > /sys/class/gpio/export

sleep 1    # このsleepが結構重要

# BCM 5,6を出力設定にする
# BCM 26を入力設定にする
echo out > /sys/class/gpio/gpio5/direction
echo out > /sys/class/gpio/gpio6/direction
echo in  > /sys/class/gpio/gpio26/direction

for((i=0; i<10; i++)); do

  if [ `cat /sys/class/gpio/gpio26/value` -eq 1 ]; then
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
  else
    echo 1 > /sys/class/gpio/gpio5/value
    echo 1 > /sys/class/gpio/gpio6/value
    sleep 1
    echo 0 > /sys/class/gpio/gpio5/value
    echo 0 > /sys/class/gpio/gpio6/value
    sleep 1
  fi

done

# BCM 5を開放する
echo 5 > /sys/class/gpio/unexport
# BCM 6を開放する
echo 6 > /sys/class/gpio/unexport
# BCM 26を開放する
echo 26 > /sys/class/gpio/unexport

