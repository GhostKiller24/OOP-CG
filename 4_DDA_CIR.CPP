#include <graphics.h>
#include <iostream.h>
#include <math.h>
#include<dos.h>

class pixel {
public:
    void drawPixel(int x, int y, int color) {
	putpixel(x, y, color);
    }
    void drawCircle(int x1,int y1,int radius);


void drawPoints(int x1, int y1, int x, int y) {
        drawPixel(x + x1, y + y1, 15);
        drawPixel(-x + x1, y + y1, 15);
        drawPixel(x + x1, -y + y1, 15);
        drawPixel(-x + x1, -y + y1, 15);
        drawPixel(y + x1, x + y1, 15);
        drawPixel(-y + x1, x + y1, 15);
        drawPixel(y + x1, -x + y1, 15);
        drawPixel(-y + x1, -x + y1, 15);
    }

    float maxVal(float a, float b) {
        return (a > b) ? a : b;
    }
};
 void pixel :: drawCircle(int x1, int y1, int radius) {
        float x, y, dx, dy, steps;

        x = 0;
        y = radius;
        dx = 1;
        dy = 1;
        steps = maxVal(float(radius), -float(radius));

        while (x <= y) {
            drawPoints(x1, y1, int(x), int(y));
            
            if (steps >= 0) {
                y -= dy;
                steps -= 2 * radius;
            }
            x += dx;
            steps += 2 * x + 1;
        }
    }

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");

    pixel p;
    int x, y, radius;

    cout << "Enter the coordinates of the center of the circle: ";
    cin >> x >> y;
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    p.drawCircle(x, y, radius);

    delay(1000);
    closegraph();
    return 0;
}
