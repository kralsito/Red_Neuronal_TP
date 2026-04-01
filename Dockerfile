# 1. Usar una imagen de Python oficial (versión slim para que no pese tanto)
FROM python:3.10-slim

# 2. Configurar el directorio de trabajo dentro del contenedor
WORKDIR /code

# 3. Copiar el archivo de requerimientos e instalar dependencias
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

# 4. Copiar el resto de los archivos del proyecto al contenedor
COPY . .

# 5. Crear la carpeta model si no existe (Hugging Face necesita los archivos ahí)
RUN mkdir -p model

# 6. Exponer el puerto que usa Hugging Face (7860 por defecto)
EXPOSE 7860

# 7. Comando para arrancar la aplicación
CMD ["python", "web_app.py"]
