--- cpp/hidapi/libusb/hid.c.orig	2015-11-25 07:33:13.805753000 +0000
+++ cpp/hidapi/libusb/hid.c	2015-11-25 07:33:38.030362000 +0000
@@ -373,7 +373,7 @@
 	inbytes = len-2;
 	outptr = (char*) wbuf;
 	outbytes = sizeof(wbuf);
-	res = iconv(ic, &inptr, &inbytes, &outptr, &outbytes);
+	res = iconv(ic, (char**)&inptr, &inbytes, &outptr, &outbytes);
 	if (res == (size_t)-1) {
 		LOG("iconv() failed\n");
 		goto err;
