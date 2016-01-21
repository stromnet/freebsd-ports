--- cpp/hidapi/libusb/hid.c
+++ cpp/hidapi/libusb/hid.c
@@ -335,7 +335,7 @@ static wchar_t *get_usb_string(libusb_device_handle *dev, uint8_t idx)
 	size_t inbytes;
 	size_t outbytes;
 	size_t res;
-	const char *inptr;
+	char *inptr;
 	char *outptr;
 
 	/* Determine which language to use. */
