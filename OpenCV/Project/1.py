from cv2 import cv2

img=cv2.imread('lena.jpg', 0)   #(File name, flags for opening the image)

cv2.imshow('image', img)        #(window name, image variable)

cv2.waitKey(3000)               #Keyboard binding function (ms)
cv2.destroyAllWindows()         
"""
cv2.imwrite('lena_copy.jpg', img)   #Creates a new img (new img name, img var)

"""

"""k=cv2.waitKey(0)

if k==27:
    cv2.destroyAllWindows()
elif k==ord('s'):
    cv2.imwrite('lena_copy.png', img)
    cv2.destroyAllWindows()
"""