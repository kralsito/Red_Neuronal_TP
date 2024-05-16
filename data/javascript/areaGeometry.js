function area(forma, ...args) {
    switch (forma.toLowerCase()) {
      case 'circulo':
        const [radio] = args;
        if (typeof radio !== 'number' || radio <= 0) {
          throw new Error('El radio debe ser un número positivo');
        }
        return Math.PI * radio * radio;
      case 'triangulo':
        const [base, altura] = args;
        if (typeof base !== 'number' || typeof altura !== 'number' || base <= 0 || altura <= 0) {
          throw new Error('La base y la altura deben ser números positivos');
        }
        return (base * altura) / 2;
      case 'rectangulo':
        const [baseR, alturaR] = args;
        if (typeof baseR !== 'number' || typeof alturaR !== 'number' || baseR <= 0 || alturaR <= 0) {
          throw new Error('La base y la altura deben ser números positivos');
        }
        return baseR * alturaR;
      // Agregar más casos para otras formas geométricas según sea necesario
      default:
        throw new Error('Forma geométrica no reconocida');
    }
  }