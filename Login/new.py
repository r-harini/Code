import numpy as np 
from cv2 import cv2
import pickle
from flask import Flask, render_template,request
model=Flask(__name__)


#Face Recognition
def letsgo(username):
    face_cascade=cv2.CascadeClassifier('cascades/data/haarcascade_frontalface_alt2.xml')
    recognizer=cv2.face.LBPHFaceRecognizer_create()
    recognizer.read("trainer.yml")

    labels={"person":1}
    with open("labels.pickle", 'rb') as f:
        og_labels=pickle.load(f)
        labels={v:k for k,v in og_labels.items()}

    cap=cv2.VideoCapture(0)

    while(True):
        ret,frame=cap.read()
        gray=cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        faces=face_cascade.detectMultiScale(gray, scaleFactor=1.5, minNeighbors=5)  #Returns a list of rectangles
        for (x,y,w,h) in faces:
            #print(x,y,w,h)
            roi_gray=gray[y:y+h, x:x+w] #[ycord_start, ycord_end]
            roi_color=frame[y:y+h, x:x+w]

            #Deep learned model predict keras tensorflow pytorch scikit learn
            id_,conf=recognizer.predict(roi_gray)
            if conf>=45: # and conf<=85:
                print(id_)
                print(labels[id_])
                font=cv2.FONT_HERSHEY_SIMPLEX
                name=labels[id_]
                color=(255,255,255)
                stroke=2
                cv2.putText(frame, name, (x,y), font, 1, color, stroke, cv2.LINE_AA)


            color=(255,0,0) #BGR AND NOT RGB
            stroke=2
            xcord_end=x+w   #Width
            ycord_end=y+h   #Height
            cv2.rectangle(frame, (x,y), (xcord_end, ycord_end), color, stroke)

        #Display the resulting frame
        cv2.imshow('frame', frame)

        if name==username:
            cap.release()
            cv2.destroyAllWindows()
            return "Yes"
        elif cv2.waitKey(20)==ord('q'):
            break
        else:
            pass
        
    cap.release()
    cv2.destroyAllWindows()
    return "No"


    
    






@model.route('/')
def index():
    return render_template('index.html')

@model.route('/', methods=['POST'])
def getvalue():
    username=request.form['username']
    val=letsgo(username)
    return render_template('index.html', val=val)

if __name__=='__main__':
    model.run(debug=True)
