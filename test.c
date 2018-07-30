#include <termios.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int nonBlockingGetKeyLoop(int argc, char *argv[]) {
  char c;
  struct termios new_kbd_mode;
  struct termios g_old_kbd_mode;

  /* put keyboard (stdin) in raw, unbuffered mode */
  tcgetattr (0, &g_old_kbd_mode);
  memcpy (&new_kbd_mode, &g_old_kbd_mode, sizeof (struct termios));

  new_kbd_mode.c_lflag &= ~(ICANON | ECHO | ISIG);
  new_kbd_mode.c_cc[VTIME] = 0;
  new_kbd_mode.c_cc[VMIN] = 1;
  tcsetattr (0, TCSANOW, &new_kbd_mode);


  while(c != 'a')
  {
    c = getchar();
  }

  /* set back into old mode */
  tcsetattr (0, TCSANOW, &g_old_kbd_mode);

  return c;
}