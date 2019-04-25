The GStreamer headers #define a version of gst_caps_copy() with the
internal implementation. This prevents the normal C++ type conversion
that would happen when the gst_caps_copy() function is called normally.
Explicitly get the inner pointer (*caps2 doesn't work) to match
the implementation API that is now exposed by the #define.

--- src/QGst/caps.cpp.orig	2019-04-25 23:22:20.063488000 +0200
+++ src/QGst/caps.cpp	2019-04-25 23:22:50.273087000 +0200
@@ -54,7 +54,7 @@
 
 void Caps::append(const CapsPtr & caps2)
 {
-    gst_caps_append(object<GstCaps>(), gst_caps_copy(caps2));
+    gst_caps_append(object<GstCaps>(), gst_caps_copy(caps2.operator->()));
 }
 
 CapsPtr Caps::merge(CapsPtr & caps2)
