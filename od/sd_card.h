#pragma once
#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include "esp_dsp.h"
#include "esp_camera.h"
#include <Arduino.h>

bool init_sd();
void write_file(fs::FS &fs, const char * path, uint8_t * data, size_t len);
uint8_t *read_file(fs::FS &fs, const char *path, int *size);
void write_camera_fb(fs::FS &fs, camera_fb_t *image, const char *path);
void append_file(fs::FS &fs, const char * path, const char * message);