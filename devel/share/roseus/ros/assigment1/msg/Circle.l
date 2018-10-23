;; Auto-generated. Do not edit!


(when (boundp 'assigment1::Circle)
  (if (not (find-package "ASSIGMENT1"))
    (make-package "ASSIGMENT1"))
  (shadow 'Circle (find-package "ASSIGMENT1")))
(unless (find-package "ASSIGMENT1::CIRCLE")
  (make-package "ASSIGMENT1::CIRCLE"))

(in-package "ROS")
;;//! \htmlinclude Circle.msg.html


(defclass assigment1::Circle
  :super ros::object
  :slots (_x _y _radius ))

(defmethod assigment1::Circle
  (:init
   (&key
    ((:x __x) 0)
    ((:y __y) 0)
    ((:radius __radius) 0)
    )
   (send-super :init)
   (setq _x (round __x))
   (setq _y (round __y))
   (setq _radius (round __radius))
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:radius
   (&optional __radius)
   (if __radius (setq _radius __radius)) _radius)
  (:serialization-length
   ()
   (+
    ;; uint32 _x
    4
    ;; uint32 _y
    4
    ;; uint32 _radius
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _x
       (write-long _x s)
     ;; uint32 _y
       (write-long _y s)
     ;; uint32 _radius
       (write-long _radius s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _x
     (setq _x (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _y
     (setq _y (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _radius
     (setq _radius (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get assigment1::Circle :md5sum-) "9fe83ccd4927fa26ce122065a2ef1649")
(setf (get assigment1::Circle :datatype-) "assigment1/Circle")
(setf (get assigment1::Circle :definition-)
      "uint32 x
uint32 y
uint32 radius


")



(provide :assigment1/Circle "9fe83ccd4927fa26ce122065a2ef1649")


