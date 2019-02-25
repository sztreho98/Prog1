#include <stdio.h>
#include <curses.h>
#include <unistd.h>

int
main ( void )
{
	WINDOW *wind;
	wind = initscr ();
	
	int x = 1;
	int y = 1;
	int xmove = 1;
	int ymove = 1;
	int mx;
	int my;

	for ( ;; ) {

		getmaxyx (wind, my, mx );
		
			for (int i = 0; i < my; ++i)mvprintw ( i, mx-1, "|" );
       			for (int i = 0; i < mx; ++i)mvprintw ( my-1, i, "_" );  	
        		for (int i = 0; i < my; ++i)mvprintw ( i, 0, "|" );
        		for (int i = 0; i < mx; ++i)mvprintw ( 0, i, "_" );
			
		mvprintw (y, x, "§" );

		refresh();
		usleep (50000);

		clear();

		x = x + xmove;
		y = y + ymove;

		if (x>=mx-1) {
			xmove = xmove * -1;
		}
		if (x<=1) {
			xmove = xmove * -1;
		}
        	if ( y<=1 ) {
         	   	ymove = ymove * -1;
        	}
        	if ( y>=my-2 ) {
            		ymove = ymove * -1;
        	}

    }

    return 0;
}
