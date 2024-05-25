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

    from sqlite3 import IntegrityError
from django.db import models
from django.contrib.auth.models import AbstractBaseUser, BaseUserManager, PermissionsMixin
from django.contrib.auth.models import Group, Permission
from django.http import JsonResponse
from django.utils import timezone
from django.contrib.auth import get_user_model
# Create your models here.

class UserManager(BaseUserManager):
    def create_user(self, email, password=None, **extra_fields):
        if not email:
            raise ValueError('El Email es obligatorio')
        email = self.normalize_email(email)
        user = self.model(email=email, **extra_fields)
        user.set_password(password)
        user.save(using=self._db)
        return user

    def create_superuser(self, email, password=None, **extra_fields):
        extra_fields.setdefault('is_staff', True)
        extra_fields.setdefault('is_superuser', True)
        return self.create_user(email, password, **extra_fields)

class User(AbstractBaseUser, PermissionsMixin):
    email = models.EmailField(unique=True)
    password = models.CharField(max_length=128)
    is_active = models.BooleanField(default=True)
    is_staff = models.BooleanField(default=False)
    perfil = models.OneToOneField('Perfil', on_delete=models.CASCADE, null=True, blank=True)

    # Agregar related_name personalizado para evitar conflictos
    groups = models.ManyToManyField(
        Group,
        verbose_name='groups',
        blank=True,
        related_name='custom_user_set',
    )
    user_permissions = models.ManyToManyField(
        Permission,
        verbose_name='user permissions',
        blank=True,
        related_name='custom_user_set',
    )

    USERNAME_FIELD = 'email'
    REQUIRED_FIELDS = []

    objects = UserManager()

def registrar_usuario(request):
    if request.method == 'POST':
        email = request.data.get('email')
        name = request.data.get('name')
        apellido = request.data.get('apellido')
        telefono = request.data.get('telefono')
        provincia = request.data.get('provincia')
        localidad = request.data.get('localidad')

        try:
            user = User.objects.create_user(email=email, password='password')
            perfil = Perfil.objects.create(
                usuario=user,
                nombrePerfil=name,
                apellidoPerfil=apellido,
                telefono=telefono,
                localidad=localidad
            )
            user.perfil = perfil  # Asignar el perfil al usuario
            user.save()  # Guardar el usuario con el perfil asignado
            return JsonResponse({'mensaje': 'Usuario registrado exitosamente'})
        except IntegrityError:
            return JsonResponse({'mensaje': 'Correo duplicado'}, status=400)
   
class Publicacion(models.Model):
    usuario = models.ForeignKey(User, on_delete=models.SET_NULL, null=True, blank=True) #Esto es lo que modifique para poder eliminar
    nombrePerro = models.CharField(max_length=30)
    fotoPerro = models.ImageField(upload_to='publicaciones',null=True, blank=True)
    edadPerro = models.CharField(max_length=20)
    SEXO_CHOICES = [
        ('Macho', 'Macho'),
        ('Hembra', 'Hembra'),
    ]
    sexoPerro = models.CharField(max_length=15, choices=SEXO_CHOICES)

    TAMANO_CHOICES = [
        ('Pequeño', 'Pequeño'),
        ('Mediano', 'Mediano'),
        ('Grande', 'Grande'),
    ]
    tamanioPerro = models.CharField(max_length=10, choices=TAMANO_CHOICES)

    BOOLEAN_CHOICES = [
        ('Si', 'Si'),
        ('No', 'No'),
    ]
    desparasitadoPerro = models.CharField(max_length=5, choices=BOOLEAN_CHOICES, default='No')
    castradoPerro = models.CharField(max_length=5, choices=BOOLEAN_CHOICES, default='No')
    libretaPerro = models.CharField(max_length=5, choices=BOOLEAN_CHOICES, default='No')
    vacunadoPerro = models.CharField(max_length=5, choices=BOOLEAN_CHOICES, default='No')

    #Funcion para retornar algo cuando llamo al objeto
    def __str__(self):
        return self.nombrePerro
    
class Perfil(models.Model):
    nombrePerfil = models.CharField(max_length=30)
    apellidoPerfil = models.CharField(max_length=30)
    localidad = models.CharField(max_length=30)
    telefono = models.IntegerField()
    biografia = models.CharField(max_length=200, null=True)
    fotoPerfil = models.ImageField(upload_to='perfiles',null=True, blank=True)
    def __str__(self):
        return f"Perfil de: {self.nombrePerfil}"

class Favorito(models.Model):
    usuario = models.ForeignKey(get_user_model(), on_delete=models.CASCADE)
    publicacion = models.ForeignKey(Publicacion, on_delete=models.CASCADE)