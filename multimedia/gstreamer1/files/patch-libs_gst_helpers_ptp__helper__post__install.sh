--- libs/gst/helpers/ptp_helper_post_install.sh.orig	2017-12-09 13:25:34 UTC
+++ libs/gst/helpers/ptp_helper_post_install.sh
@@ -20,6 +20,9 @@ case "$with_ptp_helper_permissions" in
     echo "Calling $setcap cap_net_bind_service,cap_net_admin+ep $ptp_helper"
     $setcap cap_net_bind_service,cap_net_admin+ep "$ptp_helper" || true
     ;;
+  none)
+    echo "Skipping setting gst-ptp-helper permissions"
+    ;;
   *)
     echo "$0 ERROR: unexpected permissions value '$with_ptp_helper_permissions'";
     exit 2;
