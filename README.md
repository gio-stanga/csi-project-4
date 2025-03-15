# csi-project-4

# Object detection
For the counting of cars and pedestrians, we decided to us the [FOMO model](https://docs.edgeimpulse.com/docs/edge-impulse-studio/learning-blocks/object-detection/fomo-object-detection-for-constrained-devices) by [Edge Impulse](https://edgeimpulse.com/), training it on their platform. We wrote a sketch that takes a picture from the camera, recognizes the cars that are queued and then saves the image to an SD card, embedding the object detection information in the name of the file. This way, if one were to want to view the results of the inference, they could connect the SD card to a computer and run the `converter.py` script to render bounding boxes on the images.

To run our code you can simply install the Arduino library `cars_ultimo_inferencing.zip` and upload the `od.ino` project to your ESP32. Be careful to enable OPI SRAM in the settings of the Arduino project!
