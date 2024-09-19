# UTAD-UI-FPS-Public

## HUD

### Health bar

- PlayerHealthBar with Health and MaxHealth params
- Progress bar has to show the value of Health
- If Player receives damage, Progress bar has to decrease
- If Health param is @ 25% of MaxHealth, the Progress bar has to oscillate between original color and red indifinitely

### Dynamic crosshair

- Already existing crosshair
- Animate crosshair when shooting
- If Player is aiming @ Enemy it has to change color

### Damage sign

- When Player is damaged by Enemy, Health decreases
- Implement new PlayerHitMarker showing damage received

* Screens

### Splash screen

- When Game is started, show Splash Screen, after a few seconds, disappears

### Ability tree

- Menu accesible from Game
- 3 Branches: movement speed, health, damage
- Each Branch has 2 Nodes
- Unlocking abilities requires unlocking previous ability from the same Branch
- Select ability and confirm unlocking
- Give Player points to unlock new abilities (either give them at the start or killing enemies gives points)
