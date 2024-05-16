//Implementación de un algoritmo de búsqueda en profundidad (DFS) en un grafo:

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
  
    dfs(inicio) {
      const visitados = {};
      const resultado = [];
  
      const dfsRecursivo = (vertice) => {
        if (!vertice) return null;
        visitados[vertice] = true;
        resultado.push(vertice);
        this.listaAdyacencia[vertice].forEach(vecino => {
          if (!visitados[vecino]) {
            return dfsRecursivo(vecino);
          }
        });
      };
  
      dfsRecursivo(inicio);
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
  console.log(grafo.dfs('A')); // Salida: ['A', 'B', 'D', 'C', 'E']
  