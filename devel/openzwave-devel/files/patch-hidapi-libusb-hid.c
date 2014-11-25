--- cpp/hidapi/libusb/hid.c	(revision 881)
+++ cpp/hidapi/libusb/hid.c	(working copy)
@@ -61,6 +61,9 @@
 
 #ifndef __FreeBSD__
 #define DETACH_KERNEL_DRIVER
+#else
+/* Get __FreeBSD_version */
+#include <sys/param.h>
 #endif
 
 /* Uncomment to enable the retrieval of Usage and Usage Page in
@@ -249,7 +252,7 @@
 }
 #endif /* INVASIVE_GET_USAGE */
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) && __FreeBSD_version < 1000000
 /* The FreeBSD version of libusb doesn't have this funciton. In mainline
    libusb, it's inlined in libusb.h. This function will bear a striking
    resemblence to that one, because there's about one way to code it.

