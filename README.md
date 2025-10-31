# 🎄 Arduino Christmas Tree

An Arduino-powered Christmas tree with blinking LED lights and "Merry Christmas" melody playback.

## Features

- **8 Independent LED Lights**: Each LED blinks at its own unique interval for a dynamic effect
- **Musical Buzzer**: Plays "We Wish You a Merry Christmas" melody
- **Button Control**: Single button to toggle the lights and music on/off
- **Non-blocking Code**: Uses `millis()` for timing to keep everything responsive

## Hardware Requirements

### Components
- Arduino board (Uno, Nano, or compatible)
- 8 LEDs
- 8 x 220Ω resistors (for LEDs)
- 1 x Piezo buzzer
- 1 x Push button
- 1 x 10kΩ resistor (for button pull-down)
- Breadboard and jumper wires

### Pin Configuration

| Component | Pin |
|-----------|-----|
| LEDs | 3, 5, 6, 7, 9, 10, 11, 12 |
| Button | 2 |
| Buzzer | 8 |
| Status LED (built-in) | 13 (LOW) |

## Circuit Diagram

```
Button -> Pin 2 (with pull-down resistor)
Buzzer -> Pin 8
LEDs:
  - Pin 12 -> LED 1 (600ms interval)
  - Pin 11 -> LED 2 (900ms interval)
  - Pin 10 -> LED 3 (700ms interval)
  - Pin 9  -> LED 4 (500ms interval)
  - Pin 7  -> LED 5 (800ms interval)
  - Pin 6  -> LED 6 (750ms interval)
  - Pin 5  -> LED 7 (950ms interval)
  - Pin 3  -> LED 8 (550ms interval)
```

## Installation

1. Clone this repository or download the files
2. Open `christmas-tree.ino` in the Arduino IDE
3. Connect your Arduino board to your computer
4. Select the correct board and port from Tools menu
5. Upload the sketch

## Usage

1. Power on your Arduino
2. Press the button to turn on the lights and music
3. Press again to turn everything off
4. The lights will blink independently at different rates
5. The "We Wish You a Merry Christmas" melody will play continuously when on

## Code Structure

### `christmas-tree.ino`
Main file containing:
- **`setup()`**: Initializes pins, serial communication, and plays a startup tone
- **`loop()`**: Handles button state and coordinates light and sound functions
- **`lightLoop()`**: Manages LED blinking with independent timing for each LED

### `sound.ino`
Sound module containing:
- Musical note definitions (NOTE_B0 to NOTE_DS8)
- "We Wish You a Merry Christmas" melody and timing arrays
- **`soundSetup()`**: Initializes buzzer pin
- **`soundLoop()`**: Non-blocking melody playback with restart capability

## How It Works

The project uses the **BlinkWithoutDelay** pattern to manage multiple LEDs and the buzzer without blocking code execution. Each LED has:
- Its own state (`ledState`)
- Independent timing (`previousMillis`)
- Unique blink interval (`interval`)

The melody plays note by note, checking the elapsed time before advancing to the next note. When the button toggles the state, the melody restarts from the beginning.

## Customization

### Change LED Blink Intervals
Edit the `interval` array in `christmas-tree.ino`:
```cpp
const long interval[] = { 600, 900, 700, 500, 800, 750, 950, 550 };
```

### Modify the Melody
Edit `melodyMerryChristmas` and `timeMerryChristmas` arrays in `sound.ino` to change the song.

### Add More LEDs
1. Add pin numbers to the `ledPins` array
2. Add corresponding values to `ledState`, `previousMillis`, and `interval` arrays

## Troubleshooting

- **No sound**: Check buzzer polarity and pin connection
- **LEDs not blinking**: Verify LED polarity (long leg = positive)
- **Button not responding**: Check pull-down resistor and connections
- **Upload errors**: Ensure correct board and port are selected

## License

This project is open source and available for personal and educational use.

## Author

Marco Visonà

---

*Happy Holidays! 🎅🎁✨*
