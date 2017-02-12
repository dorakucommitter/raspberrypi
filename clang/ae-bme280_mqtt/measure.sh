#!/bin/bash

for((i=0; i<10; i++)); do
  ./ae-bme280_mqtt
  sleep 5
done

