--- cpp/src/platform/unix/LogImpl.cpp
+++ cpp/src/platform/unix/LogImpl.cpp
@@ -52,7 +52,8 @@ m_bConsoleOutput( _bConsoleOutput ),		// true to provide a copy of output to con
 m_bAppendLog( _bAppendLog ),				// true to append (and not overwrite) any existing log
 m_saveLevel( _saveLevel ),					// level of messages to log to file
 m_queueLevel( _queueLevel ),				// level of messages to log to queue
-m_dumpTrigger( _dumpTrigger )				// dump queued messages when this level is seen
+m_dumpTrigger( _dumpTrigger ),				// dump queued messages when this level is seen
+pFile( NULL )
 {
 	if (!m_filename.empty()) {
 		if ( !m_bAppendLog )
