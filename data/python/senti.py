import nltk
from nltk.sentiment import SentimentIntensityAnalyzer

# Descargar recursos necesarios para NLTK (ejecutar solo una vez)
nltk.download('vader_lexicon')

# Texto de ejemplo
text = "Python is an amazing programming language with great libraries."

# Inicializar el analizador de sentimientos
sid = SentimentIntensityAnalyzer()

# Analizar sentimientos del texto
sentiment_scores = sid.polarity_scores(text)

# Imprimir resultados
print(sentiment_scores)
