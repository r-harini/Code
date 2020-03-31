import cv2

img=cv2.imread('lena.jpg', 0)   #(File name, flags for opening the image)

print(img)

cv2.imshow('image', img)        #(window name, image variable)
cv2.waitKey(3000)               #Keyboard binding function (ms)
cv2.destroyAllWindows()         

cv2.imwrite('lena_copy.jpg', img)   #Creates a new img (new img name, img var)

