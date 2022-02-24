

const deepFirstTraversal =(graph,source,visited)=>{
   if(visited.has(source)) return false;
   visited.add(source);
 
   for(let neigbour of graph[source]){
       deepFirstTraversal(graph,neigbour,visited);
   }
   /// Having visited all nodes.
   
   return 1;
}

const traverseKeys=(graph)=>{
    let total_connected =0;
    const visited = new Set([]);

    for(let source in graph){
        total_connected += deepFirstTraversal(graph,source,visited);
    }

    return total_connected;
}



const buildGraph = (edges) => {
    let graph = {};

    for (let edge of edges) {
        let [a, b] = edge;
        if (!(a in graph)) graph[a] = [];
        if (!(b in graph)) graph[b] = [];
        graph[a].push(b)
        graph[b].push(a)
    }

    console.log(graph);
    return graph;
}

const edges = [
    ['i', 'j'],
    ['k', 'i'],
    ['m', 'k'],
    ['k', 'l'],
    ['o', 'n']
];

console.log(traverseKeys({
    0: [8, 1, 5],
    1: [0],
    5: [0, 8],
    8: [0, 5],
    2: [3, 4],
    3: [2, 4],
    4: [3, 2]
  }) +" Components");

