# Python program that takes jpeg framse from the inout folder, draws a recrancle in the middle and saves the output in the output folder
import cv2
import os
import re

# Path to the input folder (located on the SD program)
input_folder = 'E:/video'
input_file = 'E:/boxes.txt'

# Path to the output folder
output_folder = './out'

# Get the list of files in the input folder
files = os.listdir(input_folder)

labels_file = open(input_file, 'r')
labels = []
for line in labels_file:
    match = re.search(r'([0-9]*) \[([a-z]*)-([0-9]*)-([0-9]*)-([0-9]*)-([0-9]*)\]', line)
    while int(match.group(1)) + 1 > len(labels):
        labels.append([])
    labels[int(match.group(1))].append([match.group(2), int(match.group(3)), int(match.group(4)), int(match.group(5)), int(match.group(6))])

# Loop through the files
i = 0
for file in files:
    # Read the image
    image = cv2.imread(os.path.join(input_folder, file))

    # Get the height and width of the image
    height, width = image.shape[:2]

    image = image[0:height, int(width/2 - height/2):int(width/2 + height/2)]
    image = cv2.resize(image, (320, 320))

    for parts in labels[i]:
        if parts[0] == "pedestrian":
            cv2.rectangle(image, (int(parts[1]), int(parts[2])), (int(parts[3] + parts[1]), int(parts[4] + parts[2])), (255, 0, 0), 3)
        else:
            cv2.rectangle(image, (int(parts[1]), int(parts[2])), (int(parts[3] + parts[1]), int(parts[4] + parts[2])), (0, 0, 255), 3)
    # Save the image
    cv2.imwrite(os.path.join(output_folder, file), image)
    i += 1

# Print a message
print('Images processed successfully')