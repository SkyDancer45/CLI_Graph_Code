#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stk[100][2]; // Array to hold coordinates
int top = -1;

void push(int coordinate[2]) {
  if (top < 99) {
    memcpy(stk[++top], coordinate, sizeof(int) * 2); // Copy coordinates to stack
  } else {
    printf("ERROR: Stack full.\n");
    exit(1);
  }
}

void coordinate_gen(int m, int b, int limit) {
  for (int i = 0; i < limit; i++) {
    int coordinate[2]; // Temporary array to hold coordinates
    coordinate[0] = i - 50; // Adjust origin to center (0, 0)
    coordinate[1] = coordinate[0] * m + b;
    push(coordinate); // Push the coordinates
  }
}

void printer() {
  char grid[100][100]; // Use a 2D array for efficiency
  memset(grid, ' ', sizeof(grid)); // Fill grid with spaces

  // Draw the X-axis
  for (int i = 0; i < 100; i++) {
    if (i == 50) {
      for (int j = 0; j < 100; j++) {
        grid[i][j] = '-';
      }
    } else {
      grid[50][i] = '-';
    }
  }

  // Draw the Y-axis
  for (int i = 0; i < 100; i++) {
    if (i == 50) {
      for (int j = 0; j < 100; j++) {
        grid[j][i] = '|';
      }
    } else {
      grid[i][50] = '|';
    }
  }

  // Plot the coordinates
  for (int i = 0; i <= top; i++) {
    int x = stk[i][0] + 50; // Adjust coordinates to range from 0 to 99
    int y = 99 - (stk[i][1] + 50); // Invert y-axis for readability
    grid[y][x] = 'X'; // Mark 'X' at the coordinate
  }

  // Print the grid with axis labels
  printf("    ");
  for (int i = 0; i < 100; i++) {
    printf("%d", i % 10);
  }
  printf("\n");

  for (int i = 0; i < 100; i++) {
    printf("%2d ", i);
    for (int j = 0; j < 100; j++) {
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }
}

int main() {
  coordinate_gen(2, 3, 100);
  printer();
  return 0;
}
