
(cl:in-package :asdf)

(defsystem "kvaser-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "CANESR" :depends-on ("_package_CANESR"))
    (:file "_package_CANESR" :depends-on ("_package"))
  ))