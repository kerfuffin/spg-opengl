import display
import pynput
from threading import Thread

from pynput import keyboard
from pynput.keyboard import Key, Listener


keys_to_ascii = {
    keyboard.Key.space: 32,
    keyboard.Key.enter: 13,
    keyboard.Key.esc: 27,
    keyboard.Key.backspace: 8,
    keyboard.Key.tab: 9,
    keyboard.Key.shift: 16,
    keyboard.Key.alt: 18,
    keyboard.Key.ctrl: 17,
    keyboard.Key.caps_lock: 20,
    keyboard.Key.num_lock: 144,
    keyboard.Key.scroll_lock: 145,
    keyboard.Key.left: 37,
    keyboard.Key.up: 38,
    keyboard.Key.right: 39,
    keyboard.Key.down: 40
}

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
    if key in keys_to_ascii.keys():
        key = keys_to_ascii[key]
    if key not in key_states.keys():
        key_states[key] = True
        if type(key) == int :
            display.handle_key_down(key)
        else:
            display.handle_key_down(ord(key.char))
        print('{0} pressed'.format(
            key))
    if key_states[key] is False:
        if type(key) == int :
            display.handle_key_down(key)
        else:
            display.handle_key_down(ord(key.char))
        print('{0} pressed'.format(
            key))
    key_states[key] = True


def on_release(key):
    if key in keys_to_ascii.keys():
        key = keys_to_ascii[key]
    key_states[key] = False
    if type(key) == int :
        display.handle_key_up(key)
    else:
        display.handle_key_up(ord(key.char))
    print('{0} release'.format(
        key))
    if key == Key.esc:
        # Stop listener
        return False


main()
