const mergeSort = (array) => {
    const animations = [];
    const arrCopy = [...array];
    mergeSortHelper(arrCopy, 0, arrCopy.length - 1, animations);
    return animations;
}

function mergeSortHelper(arr, start, end, animations) {
    if (start >= end) return;
    const mid = Math.floor((start + end) / 2);
    mergeSortHelper(arr, start, mid, animations);
    mergeSortHelper(arr, mid + 1, end, animations);
    merge(arr, start, mid, end, animations);

    // Đánh dấu phần tử đã sắp xếp hoàn chỉnh
    for (let i = start; i <= end; i++) {
        animations.push({ type: "final", index: i });
    }
}

function merge(arr, start, mid, end, animations) {
    let left = start;
    let right = mid + 1;
    const temp = [];

    while (left <= mid && right <= end) {
        animations.push({ type: "compare", indices: [left, right] });
        if (arr[left] <= arr[right]) {
            temp.push(arr[left++]);
        } else {
            temp.push(arr[right++]);
        }
    }

    while (left <= mid) temp.push(arr[left++]);
    while (right <= end) temp.push(arr[right++]);


    for (let i = 0; i < temp.length; i++) {
        animations.push({ type: "overwrite", index: start + i, height: temp[i] });
        arr[start + i] = temp[i];
    }
}

export default mergeSort;
