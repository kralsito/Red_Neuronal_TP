import pygame
import sys

# Inicializar pygame
pygame.init()

# Configuración de la pantalla
screen_width = 800
screen_height = 600
screen = pygame.display.set_mode((screen_width, screen_height))
pygame.display.set_caption("Pong Game")

# Colores
black = (0, 0, 0)
white = (255, 255, 255)

# Bucle principal del juego
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill(black)
    # Lógica del juego y dibujo de objetos aquí

    pygame.display.flip()

# Salir del juego
pygame.quit()
sys.exit()
