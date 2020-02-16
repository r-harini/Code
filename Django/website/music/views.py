from django.views import generic
from django.views.generic.edit import CreateView, UpdateView, DeleteView
from .models import Album
from django.core.urlresolvers import reverse_lazy

class IndexView(generic.ListView):
    template_name='music/index.html'
    context_object_name= 'all_albums'
    def get_queryset(self):
        return Album.objects.all()

class DetailView(generic.DetailView):
    model=Album #What object you are trying to view
    template_name='music/detail.html'

class AlbumCreate(CreateView):
    model= Album #What object you are trying to create
    fields= ['artist', 'album_title', 'genre', 'album_logo']
        
