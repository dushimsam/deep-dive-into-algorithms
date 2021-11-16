const swap = (arr, i, j) => {
    let temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

const partition = (arr, low, high) => {
    let i = low - 1;
    let pivot = arr[high];
    for (let j = low; j <= high - 1; j++) {
        if (arr[j].market_rating_points < pivot.market_rating_points) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return (i + 1)
}

const quickSort = (arr, low, high) => {
    if (low < high) {
        let pivot_index = partition(arr, low, high);
        quickSort(arr, low, pivot_index - 1);
        quickSort(arr, pivot_index + 1, high);
    }
}

let possible_recommendations = [{product: "Galaxy S5", market_rating_points: 3}, {
    product: "Mobile Samsung S1",
    market_rating_points: 1
}, {product: "Special Speaker ", market_rating_points: 60}, {
    product: "Apple Computer",
    market_rating_points: 2
}, {product: "China HeadSets", market_rating_points: 5}, {
    product: "Wireless Mouse",
    market_rating_points: 10
}, {product: "Wired Headset", market_rating_points: 4}];

quickSort(possible_recommendations, 0, possible_recommendations.length - 1);

for (let i = 0; i < possible_recommendations.length; i++)
    console.log(possible_recommendations[i])