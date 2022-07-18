
(cl:in-package :asdf)

(defsystem "microstrain_inertial_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "FilterAidingMeasurementSummary" :depends-on ("_package_FilterAidingMeasurementSummary"))
    (:file "_package_FilterAidingMeasurementSummary" :depends-on ("_package"))
    (:file "FilterAidingMeasurementSummaryIndicator" :depends-on ("_package_FilterAidingMeasurementSummaryIndicator"))
    (:file "_package_FilterAidingMeasurementSummaryIndicator" :depends-on ("_package"))
    (:file "FilterHeading" :depends-on ("_package_FilterHeading"))
    (:file "_package_FilterHeading" :depends-on ("_package"))
    (:file "FilterHeadingState" :depends-on ("_package_FilterHeadingState"))
    (:file "_package_FilterHeadingState" :depends-on ("_package"))
    (:file "FilterStatus" :depends-on ("_package_FilterStatus"))
    (:file "_package_FilterStatus" :depends-on ("_package"))
    (:file "GNSSAidingStatus" :depends-on ("_package_GNSSAidingStatus"))
    (:file "_package_GNSSAidingStatus" :depends-on ("_package"))
    (:file "GNSSDualAntennaStatus" :depends-on ("_package_GNSSDualAntennaStatus"))
    (:file "_package_GNSSDualAntennaStatus" :depends-on ("_package"))
    (:file "GNSSFixInfo" :depends-on ("_package_GNSSFixInfo"))
    (:file "_package_GNSSFixInfo" :depends-on ("_package"))
    (:file "GPSCorrelationTimestamp" :depends-on ("_package_GPSCorrelationTimestamp"))
    (:file "_package_GPSCorrelationTimestamp" :depends-on ("_package"))
    (:file "GPSCorrelationTimestampStamped" :depends-on ("_package_GPSCorrelationTimestampStamped"))
    (:file "_package_GPSCorrelationTimestampStamped" :depends-on ("_package"))
    (:file "InputSpeedMeasurement" :depends-on ("_package_InputSpeedMeasurement"))
    (:file "_package_InputSpeedMeasurement" :depends-on ("_package"))
    (:file "RTKStatus" :depends-on ("_package_RTKStatus"))
    (:file "_package_RTKStatus" :depends-on ("_package"))
    (:file "RTKStatusV1" :depends-on ("_package_RTKStatusV1"))
    (:file "_package_RTKStatusV1" :depends-on ("_package"))
    (:file "Status" :depends-on ("_package_Status"))
    (:file "_package_Status" :depends-on ("_package"))
  ))