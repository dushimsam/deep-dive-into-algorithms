

const data ={
    a:['b','c'],
    b:['d'],
    c:['e'],
    d:['f'],
    e:[],
    f:[]
}




const hasPath = (graph, src, dst) => {
    if(src === dst) return true;
    
    for(let neighbour of graph[src]){
        if(hasPath(graph,neighbour,dst))
          return true;
      }
    return false;
  };

  // DOES NOT HANDLE THE CIRCULAR SENARIO

  const graph = {
    f: ['g', 'i'],
    g: ['h'],
    h: [],
    i: ['g', 'k'],
    j: ['i'],
    k: []
  };
  
  console.log(hasPath(graph, 'i', 'h')); // true
  