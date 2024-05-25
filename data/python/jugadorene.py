player = pygame.Rect(400, 300, 50, 50)
player_speed = 5

def mover_jugador(keys):
    if keys[pygame.K_LEFT]:
        player.x -= player_speed
    if keys[pygame.K_RIGHT]:
        player.x += player_speed
    if keys[pygame.K_UP]:
        player.y -= player_speed
    if keys[pygame.K_DOWN]:
        player.y += player_speed

enemigos = [pygame.Rect(random.randint(0, 750), random.randint(0, 550), 50, 50) for _ in range(5)]

def mover_enemigos():
    for enemigo in enemigos:
        enemigo.y += 1
        if enemigo.y > 600:
            enemigo.y = 0
            enemigo.x = random.randint(0, 750)

def detectar_colisiones():
    for enemigo in enemigos:
        if player.colliderect(enemigo):
            print("Juego Terminado")
            pygame.quit()
            exit()
