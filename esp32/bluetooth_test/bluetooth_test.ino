#include "AudioTools.h"
#include "BluetoothA2DPSink.h"

/*
 * Simple code for testing basic bluetooth functionality of ESP32.
 *
 * If you get an error for program memory, make sure you use a
 * partition scheme that uses more than 1.2MB program memory, 
 * which is the default. You can change it from Tools > Partition Scheme > Huge App 
 */

// I2S Pins
#define I2S_SCLK_PIN  1   // Data bit clock (SCK) pin
#define I2S_LRCLK_PIN 22  // Word Select (WS) pin
#define I2S_SDIN_PIN  3   // Data pin (to speakers)


// Audio-related objects
I2SStream i2s;
BluetoothA2DPSink a2dp_sink(i2s);

void setup() {
  // put your setup code here, to run once:
  auto cfg = i2s.defaultConfig();
  cfg.pin_bck = I2S_SCLK_PIN;
  cfg.pin_ws = I2S_LRCLK_PIN;
  cfg.pin_data = I2S_SDIN_PIN;
  i2s.begin(cfg);

  a2dp_sink.start("esp32_a2dp_test");
}

void loop() {
  // put your main code here, to run repeatedly:

}
