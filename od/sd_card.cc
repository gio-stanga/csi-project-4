#include "sd_card.h"

bool init_sd() {
    // Initialize SD card
    if(!SD.begin(21)){
        Serial.println("Card Mount Failed");
        return false;
    }
    uint8_t cardType = SD.cardType();

    // Determine if the type of SD card is available
    if(cardType == CARD_NONE){
        Serial.println("No SD card attached");
        return false;
    }

    return true;
}

void write_file(fs::FS &fs, const char *path, uint8_t * data, size_t len){
    File file = fs.open(path, FILE_WRITE);
    if(!file){
        Serial.println("Failed to open file for writing");
        return;
    }
    if(file.write(data, len) == len){
        Serial.println("File written");
    } else {
        Serial.println("Write failed");
    }
    file.close();
}

uint8_t *read_file(fs::FS &fs, const char *path, int *size){
    File file = fs.open(path);
    if(!file){
        Serial.println("Failed to open file for reading");
        return 0;
    }

    int file_size = file.size();
    uint8_t *buffer = (uint8_t *)ps_malloc(file_size);
    Serial.println("Reading...");
    file.read(buffer, file_size);
    Serial.println("Read");
    file.close();
    *size = file_size;
    return buffer;
}

void write_camera_fb(fs::FS &fs, camera_fb_t *image, const char *path) {
    size_t len = 0;
    /*uint8_t *buffer = 0;
    if (!frame2jpg(image, 63, &buffer, &len)){
        Serial.println("Failed to convert");
        return;
    }*/

    // Save photo to file
    write_file(SD, path, image->buf, image->len);
    // free(buffer);
}

void append_file(fs::FS &fs, const char * path, const char * message){
    File file = fs.open(path, FILE_APPEND);
    if(!file){
        Serial.println("Failed to open file for appending");
        return;
    }

    if(!file.print(message)){
        Serial.println("Append failed");
    }

    file.close();
}