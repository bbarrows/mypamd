/* Define which PAM interfaces we provide */
#define PAM_SM_ACCOUNT
#define PAM_SM_AUTH
#define PAM_SM_PASSWORD
#define PAM_SM_SESSION

/* Include PAM headers */
#include <security/pam_appl.h>
#include <security/pam_modules.h>
#include <stdlib.h>

#include <termios.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int nonBlockingGetKey() {
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


  c = getchar();
  
  /* set back into old mode */
  tcsetattr (0, TCSANOW, &g_old_kbd_mode);

  if (c=='a') {
    return(PAM_SUCCESS);
  } else {
    return(PAM_AUTH_ERR);
  }

}


/* PAM entry point for session creation */
int pam_sm_open_session(pam_handle_t *pamh, int flags, int argc, const char **argv) {
	return nonBlockingGetKey();
}

/* PAM entry point for session cleanup */
int pam_sm_close_session(pam_handle_t *pamh, int flags, int argc, const char **argv) {
	return nonBlockingGetKey();
}

/* PAM entry point for accounting */
int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv) {
	return nonBlockingGetKey();
}

/* PAM entry point for authentication verification */
int pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char **argv) {
	return nonBlockingGetKey();
}

/*
 PAM entry point for setting user credentials (that is, to actually
 establish the authenticated user's credentials to the service provider)
*/
int pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char **argv) {
	return nonBlockingGetKey();
}

/* PAM entry point for authentication token (password) changes */
int pam_sm_chauthtok(pam_handle_t *pamh, int flags, int argc, const char **argv) {
	return nonBlockingGetKey();
}
