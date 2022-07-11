
(cl:in-package :asdf)

(defsystem "pxrf-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "PxrfMsg" :depends-on ("_package_PxrfMsg"))
    (:file "_package_PxrfMsg" :depends-on ("_package"))
  ))