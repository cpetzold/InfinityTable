// draw 2x2 box on 4 x 90 grid
void drawBox(int row, int col, int color) {
  row = row % 4;
  col = col % (ledsPerStrip/2);
  for (int offset = -1; offset <= 0; offset++) {
    for (int x = 0; x <= 1; x++) {
      int actualRow = row * 2 + offset;
      if (actualRow >= 0 && actualRow < 6) {
        pixel(actualRow, col*2 + x, color);          
      }  
    }
  }  
}

void randomBlocks() {
  colorWipe(BLACK);
  int colors[] = {RED, GREEN, BLUE, WHITE};
  for(int step = 0; step < 100000; step++) {
    drawBox(random(4), random(ledsPerStrip/2), colors[random(4)]);
    leds.show();
    delayMicroseconds(2000);
    colorFade(BLACK, 0.95);
  }
}

void alternatingCheckerboard() {
  for(int step = 0; step < 1000000; step++) {
    colorWipe(BLACK);
    for(int i = 0; i < ledsPerStrip/12; i++) {
      drawBox(bounce(step, 4), step + i * 6, WHITE);
    }
    leds.show();
    delayMicroseconds(100000);
  }
}
