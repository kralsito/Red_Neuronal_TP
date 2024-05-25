import requests
from bs4 import BeautifulSoup

# URL objetivo
url = 'https://example.com'

# Obtener el contenido de la página
response = requests.get(url)
soup = BeautifulSoup(response.text, 'html.parser')

# Extraer y mostrar los títulos de los artículos
articles = soup.find_all('h2')
for index, article in enumerate(articles, start=1):
    print(f"{index}. {article.text.strip()}")

# Guardar los datos en un archivo de texto
with open('articles.txt', 'w') as file:
    for index, article in enumerate(articles, start=1):
        file.write(f"{index}. {article.text.strip()}\n")
