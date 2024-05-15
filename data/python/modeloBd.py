from django.db import models
from django.contrib.auth.models import User

# Create your models here.


class Post(models.Model):
    titulo= models.CharField(max_length=50)
    descripcion= models.CharField(max_length=180)
    publisher = models.ForeignKey(to=User, on_delete=models.CASCADE, related_name="publisher")
    creado_el = models.DateTimeField(auto_now_add=True)
    image = models.ImageField(upload_to="posts", null=True, blank=True)

    @property
    def image_url(self):
        return self.image.url if self.image else ''

    def __str__(self):
        return f"{self.id} - {self.titulo}"

class Profile(models.Model):
    user = models.OneToOneField(User, on_delete=models.CASCADE, related_name="profile")
    nombre = models.CharField(max_length=20)
    avatar = models.ImageField(upload_to="avatares", null=True, blank=True)

    @property
    def avatar_url(self):
        return self.avatar.url if self.avatar else ''
    
class Mensaje(models.Model):
    mensaje = models.TextField(max_length=1000)
    email = models.EmailField()
    creado_el = models.DateTimeField(auto_now_add=True) 
    destinatario = models.ForeignKey(User, on_delete=models.CASCADE, related_name="mensajes")

class Comentario(models.Model):
    autor=models.ForeignKey(to=User, on_delete=models.CASCADE, related_name="autor")
    descripcion = models.TextField(max_length=100)
    creado_el = models.DateTimeField(auto_now_add=True) 
    posteo= models.ForeignKey(Post,on_delete=models.CASCADE, null=False, blank=False, related_name="comentarios")