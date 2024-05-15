from fastapi import FastAPI,Query,HTTPException
from pydantic import BaseModel
from typing import Optional
import json
app = FastAPI()

#libro va a ser siempre el constructor que paso para modificar luego el Json
#libros va a ser el nombre y variable del json con los datos
#Libro es el Objeto que adentro esta construido con los datos para cargar al Json

class Libro(BaseModel):
    id: Optional[int] = None
    nombre:str
    autor: str
    categoria: str
    resumen: str

with open('/code/app/libros.json','r') as f:
    libros= json.load(f)



@app.get("/libros")
def todos():
    return libros


@app.get('/libros/{l_id}')
def get_libros(l_id:int):
    libro= [l for l in libros if l['id'] == l_id]
    return libro[0] if len(libro) > 0 else {"No existe un libro con ese id"} 


@app.get("/buscar")
def buscar_categoria(categoria: str = Query(None, title="categoria", description="buscar por categoria categoria")):
    libro = [l for l in libros if l['categoria'] == categoria]
    return libro


@app.post('/addlibros')
def añadir_libro(libro: Libro):
    l_id= max([l['id'] for l in libros]) + 1 
    new_libro = {
"id": l_id,
"nombre": libro.nombre,
"autor": libro.autor,
"categoria": libro.categoria,
"resumen":libro.resumen

    }
    libros.append(new_libro)

    with open('/code/app/libros.json','w') as f:
        json.dump(libros,f)
    return new_libro


@app.put('/changeLibro')
def cambiar_libro(libro:Libro):
    new_libro = {
"id": libro.id,
"nombre": libro.nombre,
"autor": libro.autor,
"categoria": libro.categoria,
"resumen":libro.resumen
    }
    libro_lista = [l for l in libros if l['id'] == libro.id]
    if len(libro_lista) > 0:
        libros.remove(libro_lista[0])
        libros.append(new_libro)
        with open('/code/app/libros.json','w') as f:
            json.dump(libros,f)
        return new_libro
    else:
        return HTTPException(status_code=404, detail="no existe un libro con ese ID")



@app.delete("/libros")
def eliminar_libro(l_id:int):
    delete_libro = [l for l in libros if l['id'] ==l_id]
    if (len(delete_libro) >0):
        libros.remove(delete_libro[0])
        with open('/code/app/libros.json','w') as f:
            json.dump(libros,f)
        raise HTTPException(status_code=204, detail="Libro eliminado")
    else:
        raise HTTPException(status_code=404, detail="Id not found")
        


    