#!/usr/bin/env python
# -*- coding: utf-8 -*-
# RaspberryPiのカメラモジュールで、リアルタイムプレビュー映像を
# 800x600サイズの窓で表示ます。
# 途中で止めたい場合は「Ctrl+c」で止められます。

import time
import picamera
 
if __name__ == "__main__":
  camera = picamera.PiCamera()
  try:
    camera.resolution = (1024, 768)
    camera.start_preview(fullscreen=False, window=(0,0,800,600))
    time.sleep(600)
    camera.stop_preview()
  finally:
    camera.close()

