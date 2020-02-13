from django.conf.urls import url
from . import views #Look for views in the same directory

app_name='music'

urlpatterns=[
    #/music/
    url(r'^$', views.index, name='index'),

    #/music/712/
    url(r'^(?P<album_id>[0-9]+)/$', views.detail, name='detail'), #712 will be stored as album_id

]