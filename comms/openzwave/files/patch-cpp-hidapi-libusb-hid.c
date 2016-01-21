--- cpp/hidapi/libusb/hid.c.orig	2016-01-10 14:59:53 UTC
+++ cpp/hidapi/libusb/hid.c
@@ -335,7 +335,7 @@ static wchar_t *get_usb_string(libusb_de
 	size_t inbytes;
 	size_t outbytes;
 	size_t res;
-	const char *inptr;
+	char *inptr;
 	char *outptr;
 
 	/* Determine which language to use. */
