
const data ={
    a:['b','c'],
    b:['d'],
    c:['e'],
    d:['f'],
    e:[],
    f:[]
}
const visited = new Set([]);

const deepFirstTraversal =(graph,source)=>{
    console.log(source);
    // Traverse through the children as they are the one to be the sources now EACH BY EACH.
    for(let neighbour of graph[source])
       deepFirstTraversal(graph,neighbour);
}

const breadthFirstTraversal = (graph,source)=>{
      const queue = [source];

      while(queue.length > 0)
      {
          const current = queue.shift();
          console.log(current);

          // GO ON ADDING THE CHIDREN OF THE REMOVED ELEMENTS FROM THE QUEUE.
          for(let neighbour of graph[current]){
              queue.push(neighbour);
          }
      }
         
}

// n = # nodes
// e = # edges
// COMPLEXITY : O(e);
// SPACE TIME COMPLEXITY: O(n)
// WORST CASE O(n ^ 2);
// DOES NOT HANDLE THE CIRCULAR SENARIO

deepFirstTraversal(data,'a');
// breadthFirstTraversal(data,'a');
