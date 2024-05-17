import spacy

# Cargar el modelo de lenguaje de spaCy en inglés
nlp = spacy.load("en_core_web_sm")

# Texto de ejemplo
text = "Apple is looking at buying U.K. startup for $1 billion"

# Procesar el texto
doc = nlp(text)

# Mostrar entidades nombradas
for entity in doc.ents:
    print(entity.text, entity.label_)
