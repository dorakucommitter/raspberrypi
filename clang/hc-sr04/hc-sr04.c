/**
 * HC-SR04 for Raspberry Pi
 * to compile : cc main.c -o hc-sr04 -lwiringPi
 * wiringpiのライブラリが見つからない場合
 *   sudo apt-get install wiringpi
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <wiringPi.h>

#define    TRIG_PIN    17
#define    ECHO_PIN    27
#define    MEASURE_INTERVAL    1

long pulseIn(
    int pin,
    int level,
    int timeout
) {
    struct timeval tn, t0, t1;
    long micros;

    memset(&tn, 0, sizeof(struct timeval));
    memset(&t1, 0, sizeof(struct timeval));

    gettimeofday(&t0, NULL);
    micros = 0;
    while (digitalRead(pin) != level)
    {
        gettimeofday(&tn, NULL);
        if (tn.tv_sec > t0.tv_sec) {
            micros = 1000000L;
        } else {
            micros = 0;
        }
        micros += (tn.tv_usec - t0.tv_usec);
        if (micros > timeout) {
            return 0;
        }
    }

    gettimeofday(&t1, NULL);
    while (digitalRead(pin) == level)
    {
        gettimeofday(&tn, NULL);
        if (tn.tv_sec > t0.tv_sec) {
            micros = 1000000L;
        } else {
            micros = 0;
        }
        micros = micros + (tn.tv_usec - t0.tv_usec);
        if (micros > timeout) {
            return 0;
        }
    }

    if (tn.tv_sec > t1.tv_sec) {
        micros = 1000000L;
    } else {
        micros = 0;
    }
    micros = micros + (tn.tv_usec - t1.tv_usec);
    return micros;
}

void
measure_distance()
{
    long duration;
    double distance;

    /**
     * センサの初期化(たぶん)
     */
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    /* 距離の測定 */
    duration = pulseIn(ECHO_PIN, HIGH, 1000000);
//    printf("duration=%d\n",duration);
    /* 音速を343m/sとして計算 */
    distance = (duration / 2) * 34300.0 / 1000000;
    printf("distance=%.2f cm\n",distance);
}

int
main (
    int argc,
    char **argv
) {
    int i;

    if(wiringPiSetupGpio() == -1) {
        return 1;
    }
    pinMode(TRIG_PIN,OUTPUT);
    pinMode(ECHO_PIN,INPUT);

    for(i=0; i<10; i++) {
        measure_distance();
        sleep(MEASURE_INTERVAL);
    }
    return(EXIT_SUCCESS);
}

