class Grafo {
    constructor() {
      this.listaAdyacencia = {};
    }
  
    agregarVertice(vertice) {
      if (!this.listaAdyacencia[vertice]) {
        this.listaAdyacencia[vertice] = {};
      }
    }
  
    agregarArista(origen, destino, peso) {
      this.listaAdyacencia[origen][destino] = peso;
      this.listaAdyacencia[destino][origen] = peso; // Considerando un grafo no dirigido
    }
  
    dijkstra(inicio, fin) {
      const nodos = new PriorityQueue();
      const distancias = {};
      const nodosAnteriores = {};
      let camino = [fin];
      let nodoActual;
  
      // Inicialización
      for (let vertice in this.listaAdyacencia) {
        if (vertice === inicio) {
          distancias[vertice] = 0;
          nodos.enqueue(vertice, 0);
        } else {
          distancias[vertice] = Infinity;
          nodos.enqueue(vertice, Infinity);
        }
        nodosAnteriores[vertice] = null;
      }
  
      while (!nodos.isEmpty()) {
        nodoActual = nodos.dequeue().val;
  
        if (nodoActual === fin) {
          while (nodosAnteriores[nodoActual]) {
            camino.push(nodosAnteriores[nodoActual]);
            nodoActual = nodosAnteriores[nodoActual];
          }
          break;
        }
  
        if (nodoActual || distancias[nodoActual] !== Infinity) {
          for (let vecino in this.listaAdyacencia[nodoActual]) {
            let distanciaTotal = distancias[nodoActual] + this.listaAdyacencia[nodoActual][vecino];
            if (distanciaTotal < distancias[vecino]) {
              distancias[vecino] = distanciaTotal;
              nodosAnteriores[vecino] = nodoActual;
              nodos.enqueue(vecino, distanciaTotal);
            }
          }
        }
      }
  
      return camino.reverse();
    }
  }
  
  // Clase PriorityQueue (Cola de prioridad) necesaria para Dijkstra
  class Node {
    constructor(val, priority) {
      this.val = val;
      this.priority = priority;
    }
  }
  
  class PriorityQueue {
    constructor() {
      this.values = [];
    }
  
    enqueue(val, priority) {
      const newNode = new Node(val, priority);
      this.values.push(newNode);
      this.bubbleUp();
    }
  
    bubbleUp() {
      let idx = this.values.length - 1;
      const element = this.values[idx];
  
      while (idx > 0) {
        let parentIdx = Math.floor((idx - 1) / 2);
        let parent = this.values[parentIdx];
  
        if (element.priority >= parent.priority) break;
  
        this.values[parentIdx] = element;
        this.values[idx] = parent;
        idx = parentIdx;
      }
    }
  
    dequeue() {
      const min = this.values[0];
      const end = this.values.pop();
  
      if (this.values.length > 0) {
        this.values[0] = end;
        this.sinkDown();
      }
  
      return min;
    }
  
    sinkDown() {
      let idx = 0;
      const length = this.values.length;
      const element = this.values[0];
  
      while (true) {
        let leftChildIdx = 2 * idx + 1;
        let rightChildIdx = 2 * idx + 2;
        let leftChild, rightChild;
        let swap = null;
  
        if (leftChildIdx < length) {
          leftChild = this.values[leftChildIdx];
          if (leftChild.priority < element.priority) {
            swap = leftChildIdx;
          }
        }
        if (rightChildIdx < length) {
          rightChild = this.values[rightChildIdx];
          if (
            (swap === null && rightChild.priority < element.priority) ||
            (swap !== null && rightChild.priority < leftChild.priority)
          ) {
            swap = rightChildIdx;
          }
        }
  
        if (swap === null) break;
        this.values[idx] = this.values[swap];
        this.values[swap] = element;
        idx = swap;
      }
    }
  
    isEmpty() {
      return this.values.length === 0;
    }
  }
  
  // Ejemplo de uso
  const grafo = new Grafo();
  grafo.agregarVertice('A');
  grafo.agregarVertice('B');
  grafo.agregarVertice('C');
  grafo.agregarVertice('D');
  grafo.agregarVertice('E');
  grafo.agregarArista('A', 'B', 4);
  grafo.agregarArista('A', 'C', 2);
  grafo.agregarArista('B', 'E', 3);
  grafo.agregarArista('C', 'D', 2);
  grafo.agregarArista('D', 'E', 3);
  console.log(grafo.dijkstra('A', 'E')); // Salida: ['A', 'C', 'D', 'E']
  
        