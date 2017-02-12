#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <mosquitto.h>

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

char *g_topic   = "measure";
char *g_message = NULL;
int g_connect_desire = TRUE; 
/* debug mode flag */
int g_is_debug = FALSE;

/**
 * Brokerとの接続成功時に実行されるcallback関数
 */
void on_connect(struct mosquitto *mosq, void *obj, int result)
{
    if(g_is_debug) {
        printf("%s(%d)\n", __FUNCTION__, __LINE__);
    }
    mosquitto_publish(mosq, NULL, g_topic, strlen(g_message), g_message, 0, false);
}

/**
 * Brokerとの接続を切断した時に実行されるcallback関数
 */
void on_disconnect(struct mosquitto *mosq, void *obj, int rc)
{
    if(g_is_debug) {
        printf("%s(%d)\n", __FUNCTION__, __LINE__);
    }
}

/**
 * BrokerにMQTTメッセージ送信後に実行されるcallback関数
 */
static void on_publish(struct mosquitto *mosq, void *userdata, int mid)
{
    g_connect_desire = FALSE;
    mosquitto_disconnect(mosq);
}

int mqtt_message_send(char *msg)
{
    int   ret           = 0;
    char *id            = "mqtt/pub";
    char *host          = "127.0.0.1";
    int   port          = 1883;
    int   keepalive     = 60;
    bool  clean_session = true;
    struct mosquitto *mosq = NULL;

    mosquitto_lib_init();
    mosq = mosquitto_new(id, clean_session, NULL);
    if(mosq == NULL) {
        fprintf(stderr, "Cannot create mosquitto object\n");
        mosquitto_lib_cleanup();
        return(FALSE);
    }
    mosquitto_connect_callback_set(mosq, on_connect);
    mosquitto_disconnect_callback_set(mosq, on_disconnect);
    mosquitto_publish_callback_set(mosq, on_publish);
    g_message = msg;

    if(mosquitto_connect_bind(mosq, host, port, keepalive, NULL)) {
        fprintf(stderr, "failed to connect broker.\n");
        mosquitto_lib_cleanup();
        return(FALSE);
    }

    do {
        ret = mosquitto_loop_forever(mosq, -1, 1);
    } while((ret == MOSQ_ERR_SUCCESS) && (g_connect_desire != FALSE));

    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();

    return(TRUE);
}
