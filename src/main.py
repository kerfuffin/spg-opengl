import display
import pynput
from threading import Thread
from pynput.keyboard import Key, Listener

key_states = {}

def main():
    gui = Thread(target=display.start_draw_thread, args=()).start()

    print("Display thread started")

    # Collect events until released
    with Listener(
            on_press=on_press,
            on_release=on_release) as listener:
        listener.join()


def on_press(key):
    if key not in key_states.keys():
        key_states[key] = True
        display.handle_key_down(ord(key.char))
        print('{0} pressed'.format(
            key))
    if key_states[key] is False:
        display.handle_key_down(ord(key.char))
        print('{0} pressed'.format(
            key))
    key_states[key] = True


def on_release(key):
    key_states[key] = False
    display.handle_key_up(ord(key.char))
    print('{0} release'.format(
        key))
    if key == Key.esc:
        # Stop listener
        return False


main()
