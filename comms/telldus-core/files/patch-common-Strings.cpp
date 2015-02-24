--- common/Strings.cpp
+++ common/Strings.cpp
@@ -19,7 +19,7 @@
 #include <string>
 
 
-#ifdef _MACOSX
+#if defined(_MACOSX) || defined(_FREEBSD)
 #define WCHAR_T_ENCODING "UCS-4-INTERNAL"
 #else
 #define WCHAR_T_ENCODING "WCHAR_T"
