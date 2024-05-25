from django.shortcuts import render, redirect
from django.http import HttpResponse
from django.contrib.auth.decorators import login_required
from django.contrib.auth.models import User
from django.core.mail import send_mail
from .forms import ContactForm
from .models import Post

def home(request):
    posts = Post.objects.all()
    return render(request, 'blog/home.html', {'posts': posts})

@login_required
def profile(request):
    user = request.user
    return render(request, 'blog/profile.html', {'user': user})

def contact(request):
    if request.method == 'POST':
        form = ContactForm(request.POST)
        if form.is_valid():
            name = form.cleaned_data['name']
            email = form.cleaned_data['email']
            message = form.cleaned_data['message']
            send_mail('Contact Form Submission', message, email, ['admin@example.com'])
            return HttpResponse('Message sent successfully!')
    else:
        form = ContactForm()
    return render(request, 'blog/contact.html', {'form': form})

@login_required
def create_post(request):
    if request.method == 'POST':
        title = request.POST['title']
        content = request.POST['content']
        author = request.user
        Post.objects.create(title=title, content=content, author=author)
        return redirect('home')
    return render(request, 'blog/create_post.html')

@login_required
def edit_post(request, post_id):
    post = Post.objects.get(pk=post_id)
    if request.method == 'POST':
        post.title = request.POST['title']
        post.content = request.POST['content']
        post.save()
        return redirect('home')
    return render(request, 'blog/edit_post.html', {'post': post})

@login_required
def delete_post(request, post_id):
    post = Post.objects.get(pk=post_id)
    post.delete()
    return redirect('home')
