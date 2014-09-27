--- common/Event.h
+++ common/Event.h
@@ -32,7 +32,7 @@
 		virtual bool isValid() const;
 	};
 
-	typedef std::tr1::shared_ptr<EventData> EventDataRef;
+	typedef std::shared_ptr<EventData> EventDataRef;
 
 	class EventBase {
 	public:
@@ -74,7 +74,7 @@
 		friend class EventHandler;
 	};
 
-	typedef std::tr1::shared_ptr<Event> EventRef;
+	typedef std::shared_ptr<Event> EventRef;
 }
 
 #endif  // TELLDUS_CORE_COMMON_EVENT_H_
