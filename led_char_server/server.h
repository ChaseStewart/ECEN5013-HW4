
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

/* general vars*/
#define INPUT_LEN 512
#define DRIVER_PATH "/dev/myledchar"

#define LED_SERVER_HOST "127.0.0.1"
#define LED_SERVER_PORT 50010
#define MAX_NUM_CONNS   5

#define STATE_RUNNING 1
#define STATE_STOPPED 0
#define STATE_ERROR   -1

/* commands */
#define LED_ON_STR  "on"
#define LED_OFF_STR "off"
#define ACK_MSG "ACK"
#define DELIM_STR ":\t\n"

#define VAR_ALL   1
#define VAR_STATE 2
#define VAR_FREQ  3
#define VAR_DUTY  4


/*prototypes*/
int main(void);

int read_driver_var(int fileptr, int var_id);

int read_all_driver_vars(int fileptr);

int set_led_state(int fileptr, int state);

int set_led_freq(int fileptr, int freq);

int set_led_duty(int fileptr, int duty);

