--- cpp/build/support.mk
+++ cpp/build/support.mk
@@ -117,7 +117,7 @@ $(OBJDIR)/%.o : %.cpp
 	@$(SED) -e 's/.*://' -e 's/\\$$//' < $(DEPDIR)/$*.d.tmp | fmt -1 | \
 	  $(SED) -e 's/^ *//' -e 's/$$/:/' >> $(DEPDIR)/.$*.d;
 	@rm -f $(DEPDIR)/$*.d.tmp
-	@$(CXX) $(CFLAGS) $(ARCH) $(INCLUDES) -o $@ $<
+	@$(CXX) $(CFLAGS) $(TARCH) $(INCLUDES) -o $@ $<
 
 
 $(OBJDIR)/%.o : %.c
@@ -128,7 +128,7 @@ $(OBJDIR)/%.o : %.c
 	@$(SED) -e 's/.*://' -e 's/\\$$//' < $(DEPDIR)/$*.d.tmp | fmt -1 | \
 	  $(SED) -e 's/^ *//' -e 's/$$/:/' >> $(DEPDIR)/.$*.d;
 	@rm -f $(DEPDIR)/$*.d.tmp
-	@$(CC) $(CFLAGS) $(ARCH) $(INCLUDES) -o $@ $<
+	@$(CC) $(CFLAGS) $(TARCH) $(INCLUDES) -o $@ $<
 
 
 dummy := $(shell test -d $(OBJDIR) || mkdir -p $(OBJDIR))
