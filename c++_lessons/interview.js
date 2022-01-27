let arr1= [3, 5 ,-2];
let arr2 =  [9, 1, 0];

let sum=[]
for(let i=0;i<arr1.length;i++){
    sum[i] = arr1[i] + arr2[i];
}

// print elements in the sum 
for(let i=0;i<arr1.length;i++){
    console.log(sum[i])
}