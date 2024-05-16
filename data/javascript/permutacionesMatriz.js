function permutacionesUnicas(nums) {
    const result = [];
    nums.sort((a, b) => a - b);
    
    const backtrack = (temp, used) => {
      if (temp.length === nums.length) {
        result.push(temp.slice());
        return;
      }
      
      for (let i = 0; i < nums.length; i++) {
        if (used[i] || (i > 0 && nums[i] === nums[i - 1] && !used[i - 1])) continue;
        used[i] = true;
        temp.push(nums[i]);
        backtrack(temp, used);
        used[i] = false;
        temp.pop();
      }
    };
    
    backtrack([], []);
    return result;
  }
  
  // Ejemplo de uso
  const numeros = [1, 1, 2];
  console.log(permutacionesUnicas(numeros)); // Salida: [[1, 1, 2], [1, 2, 1], [2, 1, 1]]
  