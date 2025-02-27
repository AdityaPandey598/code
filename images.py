from PIL import Image
mac=Image.open('Example.jpg')
mac.show()
mac.show(mac.crop((0,0,100,100))) 