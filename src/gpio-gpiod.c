#include <stdio.h>
#include <gpiod.h> // include gpiod library for LED control
#include <unistd.h>


int main() {
    struct gpiod_chip *chip;
    struct gpiod_line *line;
    int offset = 17; // Set GPIO pin number to 17

    chip = gpiod_chip_open("/dev/gpiochip4"); // open the gpiochip4 for pin control

    // Quit the program on failure of chip opening
    if (!chip) {
        perror("Open chip failed");
        return 1;
    }

    // Get the control of the designated pin(line)
    line = gpiod_chip_get_line(chip, offset);

    if (!line) {
        perror("Get line failed");
        gpiod_chip_close(chip);
        return 1;
    }

    // Request the line for output, set consumer name to "LED"
    if (gpiod_line_request_output(line, "LED", 0) < 0) {
	// If request failed, release the line, close the chip and quit
        perror("Request line as output failed");
        gpiod_line_release(line);
        gpiod_chip_close(chip);
        return 1;
    }

    while (1) { // Endless loop, quit with Ctrl-c
        gpiod_line_set_value(line, 1); // Set line to 1 (LED on)
	sleep(1); // Hold for 1 sec

        
        gpiod_line_set_value(line, 0); // Set line to 0 (LED off)

	sleep(1); // Hold for 1 sec
    }

    // Cleanup, release the line and close the chip access
    gpiod_line_release(line);
    gpiod_chip_close(chip);

    return 0;
}
