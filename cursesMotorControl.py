import curses
import serial
import time
 
ser = serial.Serial()
ser.baudrate = 19200
ser.port = '/dev/ttyUSB0'


# get the curses screen window
screen = curses.initscr()
 
# turn off input echoing
curses.noecho()
 
# respond to keys immediately (don't wait for enter)
curses.cbreak()
 
# map arrow keys to special values
screen.keypad(True)
ser.open()
try:
    while True:
        char = screen.getch()
        
        if char == ord('k'):
            break
        elif char == curses.KEY_RIGHT:
            ser.write(b'd')
            screen.addstr(0, 0, 'right')
        elif char == curses.KEY_LEFT:
            ser.write(b'a')
            screen.addstr(0, 0, 'left ')       
        elif char == curses.KEY_UP:
            ser.write(b'w')
            screen.addstr(0, 0, 'up   ')       
        elif char == curses.KEY_DOWN:
            ser.write(b's')
            screen.addstr(0, 0, 'down ')

        if char == ord('q'):
            ser.write(b'q')
            screen.addstr(0, 0, 'stop')
        if char == ord('p'):
            ser.write(b'p')
            screen.addstr(0, 0, 'faster!')
        if char == ord('m'):
            ser.write(b'm')
            screen.addstr(0, 0, 'slower..')
        if char == ord('b'):
            ser.write(b'b')
            screen.addstr(0, 0, 'beeeep')
finally:
    # shut down
    curses.nocbreak(); screen.keypad(0); curses.echo()
    curses.endwin(); ser.close()