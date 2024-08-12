#include<GL/glut.h>
#include<math.h>

void linebreseham(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2-x1);
    int dy = abs(y2-y1);
    int sx = (x1 < x2) ? 1:-1;
    int sy = (y1 < y2) ? 1:-1;
    int err = (dx > dy ? dx: -dy)/2;
    int e2;

    while (true)
    {
        glBegin(GL_POINTS); 
        glVertex2i(x1,y1);
        glEnd();

        if (x1 == x2 && y1 == y2)
        {
            break;
        }
        e2 = 2 * err;

        if (e2 > -dx)
        {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dy)
        {
            err += dx;
            y1 += sy;
        }        
    }
}   

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Limpar buffer e preparar tela              
    linebreseham(200, 200, 200, 450);//1Chamar função para desenhar uma linha
    linebreseham(200, 450, 300, 450);//2v
    linebreseham(300, 450, 300, 650);//3v
    linebreseham(300, 650, 200, 650);//4v
    linebreseham(200, 650, 200, 800);//5v
    linebreseham(200, 800, 350, 800);//6v
    linebreseham(350, 800, 500, 650);//7v
    linebreseham(500, 650, 500, 800);//8v
    linebreseham(500, 800, 600, 800);//9v
    linebreseham(600, 800, 600, 650);//10v
    linebreseham(600, 650, 750, 650);//11v
    linebreseham(750, 650, 750, 500);//12v
    linebreseham(750, 500, 850, 500);//13v
    linebreseham(850, 500, 850, 200);//14v
    linebreseham(850, 200, 700, 200);//15v
    linebreseham(700, 200, 450, 350);//16v
    linebreseham(450, 350, 450, 200);//17v
    linebreseham(450, 200, 200, 200);//18v
    glFlush();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);//Define cor de fundo da janela(RGB)
    glColor3f(0.0, 0.0, 0.0); // Define cor dos pontos desenhados (preta)
    gluOrtho2D(0, 1920, 0, 1080); // Define projeção 2D de limites em x e y    
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Inicializa a GLUT e processa argumenntos da linha de comando
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Definne o modo de exibição para o buffer único e sistema de cores
    glutInitWindowSize(1920,1080); // Resolução da tela 
    glutInitWindowPosition(200,100); // Ponto de inicio da janela
    glutCreateWindow("Atividade Ativa- OpenGL - Adriano Reis");
    init();
    glutDisplayFunc(display); // Função display como a função de callback de exibição
    glutMainLoop(); // entra no loop principal do glut que processa eventos e chama função de exibição 
    return 0;
}