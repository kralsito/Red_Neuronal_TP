from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time

# Iniciar el navegador (por ejemplo, Chrome)
driver = webdriver.Chrome()

# Abrir una página web
driver.get("https://www.example.com")

# Interactuar con elementos de la página (por ejemplo, buscar en un campo de búsqueda)
search_box = driver.find_element_by_name("q")
search_box.send_keys("Python automation")
search_box.send_keys(Keys.RETURN)

# Esperar unos segundos para cargar los resultados
time.sleep(5)

# Capturar captura de pantalla de la página
driver.save_screenshot("screenshot.png")

# Cerrar el navegador
driver.quit()
