running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    keys = pygame.key.get_pressed()
    mover_jugador(keys)
    mover_enemigos()
    detectar_colisiones()

    screen.fill((0, 0, 0))
    pygame.draw.rect(screen, (0, 128, 255), player)
    for enemigo in enemigos:
        pygame.draw.rect(screen, (255, 0, 0), enemigo)
    
    pygame.display.flip()
    clock.tick(30)

pygame.quit()
