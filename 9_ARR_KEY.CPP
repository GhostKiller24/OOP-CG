#include <graphics.h>
#include <conio.h>
#include<dos.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");

    int x = getmaxx() / 2; // Starting x-coordinate of the ball
    int y = getmaxy() / 2; // Starting y-coordinate of the ball
    int radius = 20; // Radius of the ball
    int speed = 5; // Speed of movement

    int key;
    int running = 1;

    while (running) {
        if (kbhit()) {
            key = getch();

            switch (key) {
                case 72: // Up arrow key
                    y -= speed;
                    break;
                case 80: // Down arrow key
                    y += speed;
                    break;
                case 75: // Left arrow key
                    x -= speed;
                    break;
                case 77: // Right arrow key
                    x += speed;
                    break;
                case 27: // ESC key to exit
		    running = 0;
                    break;
            }
        }

        cleardevice(); // Clear the screen

        // Draw the ball at the updated position
        setcolor(YELLOW);
        circle(x, y, radius);
	floodfill(x, y, YELLOW);

        delay(100); // Delay to control speed of movement
    }

    closegraph();
    return 0;
}
