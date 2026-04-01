# Red_Neuronal_TP

## Tecnologías necesarias
```
pip install tensorflow
pip install keras
pip install scikit-learn
```
## 👋 Integrantes
- Franco Kral
- Leo Sebastian Gonzales Tello
- Manuel Morullo
- Dolores Domínguez
- Milagros Soberon
- Juan Ignacio Frangolini
- Nuria Robledo  

## Instalación y uso

### 1. Clonar el repositorio
```bash
git clone https://github.com/kralsito/Red_Neuronal_TP.git
cd Red_Neuronal_TP
```

### 2. Crear entorno virtual e instalar dependencias
```bash
python -m venv .venv
.venv\Scripts\activate       # Windows
# source .venv/bin/activate  # Mac/Linux

pip install -r requirements.txt
```

### 3. Entrenar el modelo
```bash
python training.py
```

Esto genera los archivos en `model/`:
- `language_model.h5`
- `tokenizer.pickle`
- `label_to_index.pickle`
- `index_to_label.pickle`
- `max_length.pickle`

### 4. Iniciar la aplicación web
```bash
python web_app.py
```

Abrí tu navegador en: [http://localhost:5000](http://localhost:5000)

---

## Estructura del proyecto

```
Red_Neuronal_TP/
├── data/                  # Dataset de entrenamiento
├── model/                 # Modelo entrenado
├── static/
│   ├── css/main.css       # Estilos
│   └── js/main.js         # Lógica frontend
├── templates/
│   ├── index.html         # Página principal
│   └── footer.html        # Componente de créditos (Jinja2)
├── app.py                 # Inferencia por línea de comandos (legacy)
├── training.py            # Entrenamiento del modelo
├── web_app.py             # Servidor Flask
├── requirements.txt       # Dependencias Python
└── README.md
```

---

## Dataset

- **50 fragmentos por lenguaje** (250 en total)
- Lenguajes: C, C#, Java, JavaScript, Python

---


## 🚀 Cantidad de patrones por lenguaje

```
C = 50
C# = 50
JAVA = 50
JAVASCRIPT = 50
PYTHON = 50
```

### (Get-ChildItem -File | Measure-Object).Count