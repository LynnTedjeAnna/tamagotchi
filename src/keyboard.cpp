#include "keyboard.hpp"

#ifdef PC
#include <ncurses.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include "keyboard.hpp"

static int kbhit() {
    struct termios oldt, newt;
    int ch, oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

Keyboard::Keyboard(char s, char e, char c, char x) {
    select = s;
    execute = e;
    cancel = c;
    save = x;
    initscr();
    noecho();
}

void Keyboard::update() {
    if (!kbhit()) { return; }   // no key-presses
    ch = getch();               // save current keypress
}

bool Keyboard::get_select() {
    return ch == select;
}
bool Keyboard::get_execute() {
    return ch == execute;
}
bool Keyboard::get_cancel() {
    return ch == cancel;
}
bool Keyboard::get_save() {
    return ch == save;
}
#else
Keyboard::Keyboard(char s, char e, char c, char x) {}
void Keyboard::update() {};
bool Keyboard::get_select() {};
bool Keyboard::get_execute() { };
bool Keyboard::get_cancel() { };
bool Keyboard::get_save() { };

#endif
