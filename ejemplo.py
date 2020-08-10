print ("hello \tworld")
#longitud cadena
print(len("hello"))
#caracteres
micadena = "abcdefghijk"
print(micadena)
print(micadena[2:])
print(micadena[:3])
print(micadena[3:6])
print(micadena[1:3])
print(micadena[::])
print(micadena[::2])
print(micadena[::3])
print(micadena[2:7:2])
#reverso
print(micadena[::-1])
#cadenas metodos
nombre = "sam"
#nombre[0] = "p"
last_letters = nombre[1:]
print(last_letters)
print("p"+last_letters)
x= "hola mundo"
print(x + " edison")
print(2+3)
print("2"+"3")
x="hola mundo"
print(x.upper())
print(x)
print(x.lower())
print(x.split())
y= "esto es una cadena"
print(y.split("a"))
print("hola")
#formateo cadenas
print(" esto es una cadena{}".format(" INSERTED"))
print("karina {} {} {}".format("elizabeth","robalino","ulcuango"))
print("karina {1} {0} {2}".format("elizabeth","robalino","ulcuango"))
print("karina {0} {0} {0}".format("elizabeth","robalino","ulcuango"))
print("karina {e} {r} {u}".format(e="elizabeth",r="robalino",u="ulcuango"))
#ajuste de punto flotante
resultado = 100/777
print(resultado)
print("el resultado es: {}".format(resultado))
print("el resultado es: {r:1.3f}".format(r=resultado))
#valor a que te refieres:espacio.presicion
print("el resultado es: {r:10.3f}".format(r=resultado))
k = "karina"
e = "edison"
#imprimir cadenas con f
print(f"{k} y {e}")
print("Python {}".format("rules!"))
