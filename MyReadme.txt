For keydown 


gcc -fPIC -DPIC -shared -rdynamic -o pfail.so pfail.c -framework ApplicationServices


https://danielbeard.wordpress.com/2010/10/29/listening-for-global-keypresses-in-osx/



gcc -fPIC -DPIC -shared -rdynamic -o pusb.so pusb.c
gcc -fPIC -DPIC -shared -rdynamic -o pfail.so pfail.c -framework ApplicationServices

gcc -fPIC -DPIC -shared -rdynamic -o pfail.so pfail.c 

gcc -fPIC -DPIC -shared -rdynamic -o pkeydown.so pkeydown.c 


sudo cp pkeydown.so /usr/local/lib/pam/pkeydown.so

auth       required    /usr/local/lib/pam/pkeydown.so


auth       sufficient    /usr/local/lib/pam/pkeydown.so






auth       sufficient     /usr/local/lib/pam/pkeydown.so
auth       sufficient     pam_rootok.so
auth       required       pam_opendirectory.so
account    required       pam_group.so no_warn group=admin,wheel ruser root_only fail_safe
account    required       pam_opendirectory.so no_check_shell
password   required       pam_opendirectory.so
session    required       pam_launchd.so









For fail

gcc -fPIC -DPIC -shared -rdynamic -o pfail.so pfail.c
sudo cp pfail.so /usr/local/lib/pam/pfail.so

MyReadme 

sudo cp pusb.so /usr/local/lib/pam/pusb.so

auth       sufficient    /usr/local/lib/pam/pusb.so

sudo cp pam_* /usr/local/bin

Changed all hashbangs to 
#!/usr/bin/python

add the auth line ot screensaver:



# screensaver: auth account
auth       optional       pam_krb5.so use_first_pass use_kcminit
auth       required       pam_opendirectory.so use_first_pass nullok
account    required       pam_opendirectory.so
account    sufficient     pam_self.so
account    required       pam_group.so no_warn group=admin,wheel fail_safe
account    required       pam_group.so no_warn deny group=admin,wheel ruser fail_safe


TO


# screensaver: auth account
auth       sufficient    /usr/local/lib/pam/pusb.so
auth       optional       pam_krb5.so use_first_pass use_kcminit
auth       required       pam_opendirectory.so use_first_pass nullok
account    required       pam_opendirectory.so
account    sufficient     pam_self.so
account    required       pam_group.so no_warn group=admin,wheel fail_safe
account    required       pam_group.so no_warn deny group=admin,wheel ruser fail_safe



pamd su


auth       sufficient     pam_rootok.so
auth       required       pam_opendirectory.so
account    required       pam_group.so no_warn group=admin,wheel ruser root_only fail_safe
account    required       pam_opendirectory.so no_check_shell
password   required       pam_opendirectory.so
session    required       pam_launchd.so


auth       sufficient    /usr/local/lib/pam/pusb.so
auth       required       pam_opendirectory.so
account    required       pam_group.so no_warn group=admin,wheel ruser root_only fail_safe
account    required       pam_opendirectory.so no_check_shell
password   required       pam_opendirectory.so
session    required       pam_launchd.so

