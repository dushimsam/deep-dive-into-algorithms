
const getTotalComponents=(graph,visited,current)=>{
  if(visited.has(current)) return 0;
  visited.add(current);
 
  let size = 1;
  for(let neigbour of graph[current])
  {
     size += getTotalComponents(graph,visited,neigbour);
  }

  return size;
}
const traverseKeys=(graph)=>{
    let visited = new Set();
    let largest = 0;

    for(let key in graph){
        let total_elements =  getTotalComponents(graph,visited,key);
        
        if(total_elements > largest)
          largest = total_elements;
    }
    return largest;
}


console.log(traverseKeys({
    0: [8, 1, 5],
    1: [0],
    5: [0, 8],
    8: [0, 5],
    2: [3, 4],
    3: [2, 4],
    4: [3, 2]
  }) +" Components");