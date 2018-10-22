
(cl:in-package :asdf)

(defsystem "assigment1-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Color" :depends-on ("_package_Color"))
    (:file "_package_Color" :depends-on ("_package"))
  ))