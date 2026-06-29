#include <curses.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
} vec2;

int score = 0;
vec2 segments[256];
int main(){

    // Desenha a tela

    int screen_width = 20;
    int screen_height = 20;

    WINDOW *win = initscr();

    keypad(win, true);
    nodelay(win, true);
    curs_set(0);

    // Cria a cobrinha

    vec2 head = {0, 0};
    vec2 dir = {1, 0};

    // Cria a frutinha

    vec2 berry = {rand() % screen_width, rand() % screen_height};

    // Cria os inputs do usuario

    do
    {
        int pressed = wgetch(win);
        if (pressed == KEY_LEFT)
        {
            if (dir.x == 1) continue;
            dir.x = -1;
            dir.y = 0;

        }

        if (pressed == KEY_RIGHT)
        {
            if (dir.x == -1) continue;
            dir.x = 1;
            dir.y = 0;
            
        }

        if (pressed == KEY_UP)
        {
            if (dir.y == 1) continue;
            dir.x = 0;
            dir.y = -1;
            
        }

        if (pressed == KEY_DOWN)
        {
            if (dir.y == -1) continue;
            dir.x = 0;
            dir.y = 1;
            
        }
        
        if (pressed == '\e')
        {
            break;
        }
        
        // Atualiza
        // Atualizando segmentos
        for (int i = score; i > 0; i--)
        {
           segments[i] = segments[i - 1];
        }

        segments[0] = head;
        
        head.x += dir.x;
        head.y += dir.y;

        if (head.x == berry.x && head.y == berry.y)
        {
            score += 1;
            berry.x = rand() % screen_width;
            berry.y = rand() % screen_height;
        }
        

    // Desenha a cobrinha

    erase();

    for (int i = 0; i < score; i++)
    {
        mvaddch(segments[i].y, segments[i].x * 2, 'o');
    }
    

    mvaddch(berry.y, berry.x * 2, '@');
    mvaddch(head.y, head.x * 2, 'O');
    
    usleep(125000);
    } while (true);

    endwin();

    return 0;
}
