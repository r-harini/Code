import numpy as np
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras.preprocessing.image import ImageDataGenerator

train_datagen=ImageDataGenerator(rescale=1./255)

train_generator=train_datagen.flow_from_directory(
    train_dir, 
    target_size=(300,300),
    batch_size=128,
    class_mode='binary') #binary classifier

validation_gen=validation_datagen.flow_from_directory(
    validation_dir, 
    target_size=(300,300),
    batch_size=128,
    class_mode='binary')

model=tf.keras.models.Sequential([
    tf.keras.layers.Conv2D(16, (3,3), activation='relu', 
                           input_shape=(300,300,3)),
    tf.keras.layers.MaxPooling2D(2,2),
    tf.keras.layers.Conv2D(32,(3,3), activation='relu'),
    tf.keras.layers.MaxPooling2D(2,2),
    tf.keras.layers.Conv2D(64, (3,3), activation='relu'),
    tf.keras.layers.Flatten(),
    tf.keras.layers.Dense(512, activation='relu'),
    tf.keras.layers.Dense(1,activation='sigmoid')]) 

from tensorflow.keras.optimizers import RMSprop
history=model.fit_generator(train_generator, #streams data form the dir
                            steps_per_epoch=8,
                            epochs=15,
                            validation_data=validation_generator,
                            validation_steps=8,
                            verbose=2) #how much to display while training is going on)
                            