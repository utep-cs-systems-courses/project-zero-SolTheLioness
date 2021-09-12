#include <stdio.h>
#include "draw.h"

int main() 
{
  puts("Welcome!");

  while (1) { // Infinite while loop

    fputs("Select which shape you want to print (Arrow = a, Triangle = t, Square = s, Chars = c, Custom Font Chars = C, Compare chars = x) or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;

    // Given the user answer, select which method to call
    switch (c) {
    case 'a':
      puts ("You selected arrow:");
      print_arrow ();
      break;
    case 't':
      puts("You selected triangle:");
      print_triangle(5, 7);
      break;
    case 's':
      puts("You selected square:");
      print_square(5, 5);
      break;
    case 'c':
      puts("You selected chars:");
      for (char c = 'A'; c < 'G'; c++)
	print_char_11x16(c);
      break;
    case 'C':
      puts("You selected custom font chars:");
      for (char c = 'A'; c <= 'Z'; c++)
	print_char_5x7(c);
      break;
    case 'x':
      puts("You selected to compare fonts:");
      for (char c = 'A'; c <= 'Z'; c++) {
	if (c % 2)
	  print_char_11x16(c);
	else
	  print_char_5x7(c);
      }
      break;
    case 'q':
      puts("Bye!");
      goto done; 		/* terminate */
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  return 0;
}
