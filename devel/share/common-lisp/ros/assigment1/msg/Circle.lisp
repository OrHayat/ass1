; Auto-generated. Do not edit!


(cl:in-package assigment1-msg)


;//! \htmlinclude Circle.msg.html

(cl:defclass <Circle> (roslisp-msg-protocol:ros-message)
  ((x
    :reader x
    :initarg :x
    :type cl:integer
    :initform 0)
   (y
    :reader y
    :initarg :y
    :type cl:integer
    :initform 0)
   (radius
    :reader radius
    :initarg :radius
    :type cl:integer
    :initform 0))
)

(cl:defclass Circle (<Circle>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Circle>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Circle)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name assigment1-msg:<Circle> is deprecated: use assigment1-msg:Circle instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <Circle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader assigment1-msg:x-val is deprecated.  Use assigment1-msg:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <Circle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader assigment1-msg:y-val is deprecated.  Use assigment1-msg:y instead.")
  (y m))

(cl:ensure-generic-function 'radius-val :lambda-list '(m))
(cl:defmethod radius-val ((m <Circle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader assigment1-msg:radius-val is deprecated.  Use assigment1-msg:radius instead.")
  (radius m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Circle>) ostream)
  "Serializes a message object of type '<Circle>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'x)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'x)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'x)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'x)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'y)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'y)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'y)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'y)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'radius)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'radius)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'radius)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'radius)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Circle>) istream)
  "Deserializes a message object of type '<Circle>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'x)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'x)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'x)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'x)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'y)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'y)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'y)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'y)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'radius)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'radius)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'radius)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'radius)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Circle>)))
  "Returns string type for a message object of type '<Circle>"
  "assigment1/Circle")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Circle)))
  "Returns string type for a message object of type 'Circle"
  "assigment1/Circle")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Circle>)))
  "Returns md5sum for a message object of type '<Circle>"
  "9fe83ccd4927fa26ce122065a2ef1649")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Circle)))
  "Returns md5sum for a message object of type 'Circle"
  "9fe83ccd4927fa26ce122065a2ef1649")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Circle>)))
  "Returns full string definition for message of type '<Circle>"
  (cl:format cl:nil "uint32 x~%uint32 y~%uint32 radius~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Circle)))
  "Returns full string definition for message of type 'Circle"
  (cl:format cl:nil "uint32 x~%uint32 y~%uint32 radius~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Circle>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Circle>))
  "Converts a ROS message object to a list"
  (cl:list 'Circle
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
    (cl:cons ':radius (radius msg))
))
