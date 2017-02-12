#!/usr/bin/python
# -*- coding: utf-8 -*-

import paho.mqtt.client as mqtt
import json
import MySQLdb
from datetime import *
#import ssl

host = 'localhost'
port = 1883
### パスワード認証を使用する時に使用する
#username = 'mqtt'
#password = 'mqtt'
# SSL
#port = 8883
#cacert = './cert/ca.crt'
#clientCert = './cert/client.crt'
#clientKey = './cert/client_nopass.key'

topic = 'measure'

def mysql_insert(epoch_time, temperature, humid, pressure):
    connection = MySQLdb.connect(host='localhost', db='testdb', user='test', passwd='test', charset="utf8")
    cursor = connection.cursor()

    sql = "INSERT INTO measure_data ( epoch_time, temperature, humid, pressure, create_at ) VALUES ( " + str(epoch_time) + ", " + str(temperature) + ", "+ str(humid) + ", " + str(pressure) + ", '" + datetime.now().strftime('%Y-%m-%d %H:%M:%S') + "' )"
    #print(sql)
    cursor.execute(sql)
    connection.commit()

    cursor.close()
    connection.close()

def on_connect(client, userdata, flags, respons_code):
    """broker接続時のcallback関数
    """
    #print('status {0}'.format(respons_code))
    client.subscribe(topic)

def on_message(client, userdata, msg):
    """メッセージ受信時のcallback関数
    """
    #print(msg.topic + ' ' + str(msg.payload))
    json_data = json.loads(str(msg.payload))
    #print(json_data)
    #print(json_data["humid"])
    mysql_insert(json_data["epoch_time"], json_data["temperature"], json_data["humid"], json_data["pressure"])

if __name__ == '__main__':
    ### インスタンス作成時にprotocol v3.1.1を指定
    client = mqtt.Client(protocol=mqtt.MQTTv311)

    ### パスワード認証を使用する時に使用する
    #client.username_pw_set(username, password=password)
    ### SSL
    #client.tls_set(cacert,
    #    certfile = clientCert,
    #    keyfile = clientKey,
    #    tls_version = ssl.PROTOCOL_TLSv1_2)
    #client.tls_insecure_set(True)

    ### callback function
    client.on_connect = on_connect
    client.on_message = on_message

    client.connect(host, port=port, keepalive=60)
    client.loop_forever()

