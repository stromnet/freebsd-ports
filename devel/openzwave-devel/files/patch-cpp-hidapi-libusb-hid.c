--- cpp/hidapi/libusb/hid.c
+++ cpp/hidapi/libusb/hid.c
@@ -335,11 +335,7 @@ static wchar_t *get_usb_string(libusb_device_handle *dev, uint8_t idx)
 	size_t inbytes;
 	size_t outbytes;
 	size_t res;
-#ifdef __FreeBSD__
-	const char *inptr;
-#else
 	char *inptr;
-#endif
 	char *outptr;
 
 	/* Determine which language to use. */
