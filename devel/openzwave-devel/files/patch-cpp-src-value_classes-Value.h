--- cpp/src/value_classes/Value.h	(revision 881)
+++ cpp/src/value_classes/Value.h	(working copy)
@@ -29,6 +29,9 @@
 #define _Value_H
 
 #include <string>
+#ifdef __FreeBSD__
+#include <time.h>
+#endif
 #include "Defs.h"
 #include "platform/Ref.h"
 #include "value_classes/ValueID.h"

