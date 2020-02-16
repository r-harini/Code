from django.conf.urls import url
from . import views #Look for views in the same directory

app_name='music'

urlpatterns=[
    #/music/
    url(r'^$', views.IndexView.as_view(), name='index'),

    #/music/<album_id>/
    url(r'^(?P<pk>[0-9]+)/$', views.DetailView.as_view(), name='detail'), #712 will be stored as album_id

    #/music/album/add
    url (r'album/add/$', views.AlbumCreate.as_view(), name='album-add'),
    

]