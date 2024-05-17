import cv2

# Cargar el clasificador Haar Cascade preentrenado
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

# Leer una imagen
img = cv2.imread('path_to_image.jpg')
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# Detectar rostros
faces = face_cascade.detectMultiScale(gray, 1.1, 4)

# Dibujar rectángulos alrededor de los rostros
for (x, y, w, h) in faces:
    cv2.rectangle(img, (x, y), (x+w, y+h), (255, 0, 0), 2)

# Mostrar la imagen con los rostros detectados
cv2.imshow('img', img)
cv2.waitKey()
cv2.destroyAllWindows()
