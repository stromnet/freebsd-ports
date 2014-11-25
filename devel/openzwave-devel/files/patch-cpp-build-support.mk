--- cpp/build/support.mk	(revision 881)
+++ cpp/build/support.mk	(working copy)
@@ -15,6 +15,7 @@
 UNAME  := $(shell uname -s)
 #the location of Doxygen to generate our api documentation
 DOXYGEN := $(shell which doxygen)
+DOT := $(shell which dot)
 #the machine type we are building on (i686 or x86_64)
 MACHINE := $(shell uname -m)
 #the location of xmllink for checking our config files
@@ -38,9 +39,16 @@
 VERSION := $(VERSION_MAJ).$(VERSION_MIN)
 
 # support Cross Compiling options
+ifeq ($(UNAME),FreeBSD)
+# Actually hide behind c++ which works for both clang based 10.0 and earlier(?)
+CC     := $(CROSS_COMPILE)cc
+CXX    := $(CROSS_COMPILE)c++
+LD     := $(CROSS_COMPILE)c++
+else
 CC     := $(CROSS_COMPILE)gcc
 CXX    := $(CROSS_COMPILE)g++
 LD     := $(CROSS_COMPILE)g++
+endif
 ifeq ($(UNAME),Darwin)
 AR     := libtool -static -o 
 RANLIB := ranlib

