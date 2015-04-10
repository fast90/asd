#Audio Switch Daemon

This circuit switches two audio sources, based on the status of a MPD-server running on a Raspberry Pi.

If MPD is playing the Raspberry Pi (INPUT 2) is switched to OUT.
When MPD stops playing OUT is switched back to INPUT 1.

# Library
Libbcm2835 is used for GPIO access. See http://www.airspayce.com/mikem/bcm2835/ for details.

# Schematic
![Schematic](https://github.com/fast90/asd/blob/master/schematics/schematic_small.png)

# Wiring
| Raspberry Pi Pin No. | Audioswitch Pin | Function |
|:--------------------:|:---------------:|:--------:|
| 8                    | SV2 - 3         | GPIO 14  |
| 2                    | SV2 - 2         | GND      |
| 6                    | SV2 - 1         | +5V      |

SV1 can be used to connect a manual switch.

# Setup
Install the Library see http://www.airspayce.com/mikem/bcm2835/ for details.

If you are using a Raspberry Pi 2 you need to enable device tree support!

```bash
sudo raspi-config
```
```bash
->Advanced Options -> enable Device Tree
sudo shutdown -r now
```
Then type
```bash
./configure
make
make install
```

# Configuration & Usage
|  Option   |   Argument   |          Function        |       Default      |
|:---------:|:------------:|:------------------------:|:-------------------|
|  h        |              |Show help                 |                    |
|  v        |              |Show version              |                    |
| no-daemon |              |Don't detach from console |                    |
|  p        | <PinNumber>  |Change Pin                | GPIO17             |
|  s        | <SocketPath> |Change Path to socket     |/home/pi/.mpd/socket|

```bash
asd -p 17 -s /home/user/.mpd/sock
```
