import struct

class Livro:
    def __init__(self, id, titulo, autor):
        self.id = id
        self.titulo = titulo
        self.autor = autor

livros = []

n = int(input());
for i in range(n):
    id = int(input())
    titulo = input()
    autor = input()
    livros.append(Livro(id, titulo, autor))

with open("save", "wb") as arq:
    for livro in livros:
        autor_bytes = livro.autor.encode()
        data = struct.pack("iii", livro.id, len(livro.titulo), autor_bytes + len(livro.autor))
        arq.write(data)
        arq.write(livro.titulo.encode())
        arq.write(b"|")
        arq.write(livro.autor.encode())
        arq.write(b"#")

m = int(input())

livros = []
with open("save", "rb") as arq:
    while True:
        data = arq.read(12)
        if not data:
            break
        id, titulo_len, autor_len = struct.unpack("iii", data)
        titulo = arq.read(titulo_len).decode()
        autor = arq.read(autor_len).decode()
        livro = Livro(id, titulo, autor)
        livro.byteoffset = arq.tell() - 12
        livros.append(livro)
