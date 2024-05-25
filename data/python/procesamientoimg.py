import cv2
import numpy as np

# Cargar la imagen
image = cv2.imread('input_image.jpg')
cv2.imshow('Original', image)

# Convertir a escala de grises
gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
cv2.imshow('Grayscale', gray_image)

# Aplicar desenfoque gaussiano
blurred_image = cv2.GaussianBlur(gray_image, (7, 7), 0)
cv2.imshow('Blurred', blurred_image)

# Detectar bordes usando Canny
edges = cv2.Canny(blurred_image, 50, 150)
cv2.imshow('Edges', edges)

# Encontrar y dibujar contornos
contours, _ = cv2.findContours(edges, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
cv2.drawContours(image, contours, -1, (0, 255, 0), 2)
cv2.imshow('Contours', image)

# Esperar a que se presione una tecla y cerrar ventanas
cv2.waitKey(0)
cv2.destroyAllWindows()
