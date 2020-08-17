import tensorflow as tf
from tensorflow import keras

mnist=keras.datasets.mnist


# the data, split between train and test sets
(x_train, y_train), (x_test, y_test) = mnist.load_data()
print(x_train.shape, y_train.shape)
