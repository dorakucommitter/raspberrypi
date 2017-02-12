#!/usr/bin/env python
# -*- coding: utf-8 -*-
# RaspberryPiのカメラモジュールで、リアルタイムプレビュー映像を
# フルスクリーンで表示ます。
# 途中で止めたい場合は「Ctrl+c」で止められます。

import time
import picamera
 
if __name__ == "__main__":
  camera = picamera.PiCamera()
  try:
    camera.start_preview()
    time.sleep(600)
    camera.stop_preview()
  finally:
    camera.close()

