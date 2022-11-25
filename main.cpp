#include <windows.h>
#include <stdio.h>
#include "WAV.h"

int main() {
    wav_file input_1("severe_tire_damage.wav");
    input_1.Record();
    return 0;
}