//Implementación de un algoritmo de búsqueda en amplitud (BFS) en un grafo:

class Grafo {
    constructor() {
      this.listaAdyacencia = {};
    }
  
    agregarVertice(vertice) {
      if (!this.listaAdyacencia[vertice]) {
        this.listaAdyacencia[vertice] = [];
      }
    }
  
    agregarArista(origen, destino) {
      this.listaAdyacencia[origen].push(destino);
      this.listaAdyacencia[destino].push(origen); // Considerando un grafo no dirigido
    }
  
    bfs(inicio) {
      const cola = [inicio];
      const visitados = {};
      const resultado = [];
  
      visitados[inicio] = true;
  
      while (cola.length) {
        const vertice = cola.shift();
        resultado.push(vertice);
  
        this.listaAdyacencia[vertice].forEach(vecino => {
          if (!visitados[vecino]) {
            visitados[vecino] = true;
            cola.push(vecino);
          }
        });
      }
  
      return resultado;
    }
  }
  
  // Ejemplo de uso
  const grafo = new Grafo();
  grafo.agregarVertice('A');
  grafo.agregarVertice('B');
  grafo.agregarVertice('C');
  grafo.agregarVertice('D');
  grafo.agregarVertice('E');
  grafo.agregarArista('A', 'B');
  grafo.agregarArista('A', 'C');
  grafo.agregarArista('B', 'D');
  grafo.agregarArista('C', 'E');
  console.log(grafo.bfs('A')); // Salida: ['A', 'B', 'C', 'D', 'E']
  