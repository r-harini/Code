def ruler(i,len):
    if i>len:
        return
    elif i==1:
        print('-')
        ruler(i+1, len)
    else:
        print('-')
        ruler(i+1, len)
        print('-')

ruler(1, 4)