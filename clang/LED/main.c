#include <stdio.h>
#include <wiringPi.h>

#define BCM5        5   /* RED LED */
#define BCM6        6   /* GRN LED */
#define BCM26       26  /* Switch  */

#define RED_LED     BCM5
#define GRN_LED     BCM6
#define SWITCH      BCM26
#define BLINK_CNT   10
#define BLINK_INT   1000

int
main(void)
{
    int i;

    if(wiringPiSetupGpio() == (-1)) {
        printf("error wiringPi setup\n");
        return(1);
    }
    pinMode (RED_LED, OUTPUT) ;
    pinMode (GRN_LED, OUTPUT) ;
    pinMode (SWITCH,  INPUT) ;

    for (i=0; i<BLINK_CNT; i++) {
        if(digitalRead(SWITCH) == 0) {
            digitalWrite(RED_LED, HIGH);  /* 点灯 */
            digitalWrite(GRN_LED, LOW);   /* 消灯 */
            delay(BLINK_INT);
            digitalWrite(GRN_LED, HIGH);  /* 点灯 */
            digitalWrite(RED_LED, LOW);   /* 消灯 */
            delay(BLINK_INT);
        } else {
            digitalWrite(RED_LED, HIGH);  /* 点灯 */
            digitalWrite(GRN_LED, HIGH);  /* 点灯 */
            delay(BLINK_INT);
            digitalWrite(RED_LED, LOW);   /* 消灯 */
            digitalWrite(GRN_LED, LOW);   /* 消灯 */
            delay(BLINK_INT);
        }
    }
    digitalWrite(RED_LED, LOW);   /* 消灯 */
    digitalWrite(GRN_LED, LOW);   /* 消灯 */
    return(0);
}
