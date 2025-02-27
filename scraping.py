import requests
import bs4
def FetchAndSave(url,path):
    r=requests.get(url)
    with open(path,"w",encoding="utf-8") as f:
        f.write(r.text)

from bs4 import BeautifulSoup
url="https://en.wikipedia.org/wiki/Grace_Hopper"
FetchAndSave(url,"practice.html")

with open("practice.html","r",encoding="utf-8") as x:
    doc=x.read()

soup=BeautifulSoup(doc,'html.parser')
#print(soup.prettify())
a=soup.title
print(a[0])