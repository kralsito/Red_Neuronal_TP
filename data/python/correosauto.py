import smtplib
from email.mime.text import MIMEText

def enviar_correo(asunto, mensaje, destinatario):
    remitente = "tu_email@example.com"
    password = "tu_password"

    msg = MIMEText(mensaje)
    msg['Subject'] = asunto
    msg['From'] = remitente
    msg['To'] = destinatario

    with smtplib.SMTP_SSL('smtp.example.com', 465) as server:
        server.login(remitente, password)
        server.sendmail(remitente, destinatario, msg.as_string())
        print("Correo enviado con éxito")

enviar_correo("Asunto del Correo", "Mensaje del correo", "destinatario@example.com")
