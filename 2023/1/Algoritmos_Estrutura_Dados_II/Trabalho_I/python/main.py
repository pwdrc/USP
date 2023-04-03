import pickle
import struct
import os

class Livro:
    def __init__(self, id, titulo, autor):
        self.id = id
        self.titulo = titulo
        self.autor = autor

n = int(input());
for i in range(n):
    id = input()
    titulo = input()
    autor = input()
    l = Livro(id, titulo, autor)
    with open("livros.bin", "wb") as arquivo:
        pickle.dump(l, arquivo)

m = int(input())
print(ler_m_ultimos_livros("livros.bin", m))
