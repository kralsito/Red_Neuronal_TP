import nltk
from nltk.sentiment import SentimentIntensityAnalyzer
from nltk.tokenize import sent_tokenize

nltk.download('punkt')
nltk.download('vader_lexicon')

def analizar_sentimiento(texto):
    sia = SentimentIntensityAnalyzer()
    sentimientos = {'Positivo': 0, 'Negativo': 0, 'Neutral': 0}
    
    oraciones = sent_tokenize(texto)
    for oracion in oraciones:
        sentimiento = sia.polarity_scores(oracion)
        if sentimiento['compound'] >= 0.05:
            sentimientos['Positivo'] += 1
        elif sentimiento['compound'] <= -0.05:
            sentimientos['Negativo'] += 1
        else:
            sentimientos['Neutral'] += 1
    
    return sentimientos

texto_ejemplo = """
Me encanta esta película. La actuación es increíble y la historia es cautivadora. 
Sin embargo, el final me dejó un poco decepcionado. En general, es una gran experiencia cinematográfica.
"""

resultado_sentimientos = analizar_sentimiento(texto_ejemplo)
print("Análisis de Sentimientos por Oración:")
for sentimiento, cantidad in resultado_sentimientos.items():
    print(f"{sentimiento}: {cantidad} oraciones")
