# 1. Imagen base oficial
FROM python:3.12-slim

# 2. Instalación de dependencias de sistema necesarias para Git LFS/Xet
RUN apt-get update && apt-get install -y \
    git \
    git-lfs \
    curl \
    && git lfs install \
    && rm -rf /var/lib/apt/lists/*

# 3. Configurar el directorio de trabajo
WORKDIR /code

# 4. Crear un usuario para cumplir con las políticas de seguridad de HF
RUN useradd -m -u 1000 user
USER user
ENV HOME=/home/user \
    PATH=/home/user/.local/bin:$PATH

# 5. Configurar el directorio de trabajo con los permisos del usuario
WORKDIR $HOME/app

# 6. Copiar requerimientos e instalar dependencias
# Instalamos como el usuario 'user'
COPY --chown=user requirements.txt .
RUN pip install --no-cache-dir --upgrade pip && \
    pip install --no-cache-dir -r requirements.txt

# 7. Copiar el resto del proyecto
COPY --chown=user . .

# 8. Asegurar que la carpeta model existe
RUN mkdir -p model

# 9. Puerto oficial de Hugging Face Spaces
EXPOSE 7860

# 10. Arrancar la aplicación
# Usamos el host 0.0.0.0 para que sea accesible desde el proxy de HF
CMD ["python", "web_app.py"]