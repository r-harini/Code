from django.conf.urls import url
from . import views #Look for views in the same directory

urlpatterns=[
    url(r'^$', views.index, name='index')
]