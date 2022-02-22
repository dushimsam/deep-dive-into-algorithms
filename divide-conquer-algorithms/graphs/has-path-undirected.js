

const hasPath = (graph, src, dst, visited) => {
    if (src === dst) return true
    if (visited.has(src)) return false

    visited.add(src);
    for (let neigbour of graph[src])
        if (hasPath(graph, neigbour, dst)) return true;

    return false;
}

const undirectedPath = (edges, nodeA, nodeB) => {
    const graph = buildGraph(edges);
    const visited = new Set([]);
    return hasPath(graph, nodeA, nodeB,visited);
};

const buildGraph = (edges) => {
    let graph = {};

    for (let edge of edges) {
        let [a, b] = edge;
        if (!(a in graph)) graph[a] = [];
        if (!(b in graph)) graph[b] = [];
        graph[a].push(b)
        graph[b].push(a)
    }

    return graph;
}

const edges = [
    ['i', 'j'],
    ['k', 'i'],
    ['m', 'k'],
    ['k', 'l'],
    ['o', 'n']
];


console.log(undirectedPath(edges, 'i', 'k'));


