import pygame
import random

# Inicializar Pygame
pygame.init()

# Configurar la pantalla
screen_width = 800
screen_height = 600
screen = pygame.display.set_mode((screen_width, screen_height))

# Configurar el reloj para controlar la velocidad de fotogramas
clock = pygame.time.Clock()

# Crear el jugador
player_width = 50
player_height = 60
player = pygame.Rect(screen_width // 2, screen_height - player_height - 10, player_width, player_height)

# Crear enemigos
enemigo_width = 50
enemigo_height = 60
num_enemigos = 5
enemigos = [pygame.Rect(random.randint(0, screen_width - enemigo_width), random.randint(-100, -40), enemigo_width, enemigo_height) for _ in range(num_enemigos)]

# Función para mover el jugador
def mover_jugador(keys):
    velocidad = 5
    if keys[pygame.K_LEFT] and player.left > 0:
        player.x -= velocidad
    if keys[pygame.K_RIGHT] and player.right < screen_width:
        player.x += velocidad
    if keys[pygame.K_UP] and player.top > 0:
        player.y -= velocidad
    if keys[pygame.K_DOWN] and player.bottom < screen_height:
        player.y += velocidad

# Función para mover los enemigos
def mover_enemigos():
    velocidad = 3
    for enemigo in enemigos:
        enemigo.y += velocidad
        if enemigo.top > screen_height:
            enemigo.x = random.randint(0, screen_width - enemigo_width)
            enemigo.y = random.randint(-100, -40)

# Función para detectar colisiones
def detectar_colisiones():
    for enemigo in enemigos:
        if player.colliderect(enemigo):
            return True
    return False

# Bucle principal del juego
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    keys = pygame.key.get_pressed()
    mover_jugador(keys)
    mover_enemigos()
    if detectar_colisiones():
        print("¡Colisión detectada! El juego ha terminado.")
        running = False

    screen.fill((0, 0, 0))
    pygame.draw.rect(screen, (0, 128, 255), player)
    for enemigo in enemigos:
        pygame.draw.rect(screen, (255, 0, 0), enemigo)
    
    pygame.display.flip()
    clock.tick(30)

pygame.quit()
