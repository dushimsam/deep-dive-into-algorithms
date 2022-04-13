 UDONE:

1. 2SAT problem about Graphs
2. Heirholzer algo.
3. De brujin sequences

TO DO:

1. DEVICE MORE PATH QUERIES
2. HIGHEST COMMON ANCESTOR USING THE
SUBTREE QUERIES / UNION FIND METHOD / DFS
3. FIND THE DISTANCE BETWEEN TWO NODES 
   (hint -> refer to LCA )

REMEMBER:
1. Most of the time if the program fails
you might be trying to access vector elements which are
not allocated space for.

INSIGHTS:

1. IF YOU WANT TO PARTICULAR INFORMATION ABOUT THE SUBTREE GIVEN THE PARENT
-> Use subtree query V_1 ( MATRIX With - NODE ID - NODE DEGREE - NODE VALUE) - no of nodes in a subtree.

2. iF YOU WANT INFORMATION ABOUT THE TWO NODES OF A TREE
-> Use subtree query V_2 ( MATRIX With - NODE ID - DEPTH ) eg: LCA 

3. IF YOU WANT INFORMATION ABOUT THE NODE WITH WITH IT'S PARENT
-> Use union-find approach. 

4. IF THERE'S A POSSIBILITY OF REPEATING THE SAME EDJE MORE THAN ONCE THEN THAT'S NOT A EURAL CIRCUIT.
WHEN TRYING TO COVER ALL THE EDGES.
   EURAL CIRCUIT:
          - ALL EDGES SHOULD BE VISITED EXACTLY ONCE.
          - THE STARTING VERTEX SHOULD BE THE ENDING VERTEX.

   other definition:
         - When i have a plan of visiting all the edges of the graph without retraversing the visited edge starting from a particular node , i will end up falling back on the node i started on before traversing the graph.