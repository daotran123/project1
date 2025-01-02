const quickSort = (array) => {
    const animations = [];
    const arrCopy = [...array];
    quickSortHelper(arrCopy, 0, arrCopy.length - 1, animations);
    return animations;
}

function quickSortHelper(arr, low, high, animations) {
    if (low < high) {
        const pivotIdx = partition(arr, low, high, animations);
        quickSortHelper(arr, low, pivotIdx - 1, animations);
        quickSortHelper(arr, pivotIdx + 1, high, animations);
    }

    // Đánh dấu phần tử đã sắp xếp hoàn chỉnh sau khi quay lại từ recursive call
    for (let i = low; i <= high; i++) {
        animations.push({ type: "final", index: i });
    }
}

function partition(arr, low, high, animations) {
    const pivot = arr[high];
    let i = low - 1;

    for (let j = low; j < high; j++) {
        animations.push({ type: "compare", indices: [j, high] });

        if (arr[j] < pivot) {
            i++;
            animations.push({ type: "swap", indices: [i, j] });
            [arr[i], arr[j]] = [arr[j], arr[i]];
        }
    }

    animations.push({ type: "swap", indices: [i + 1, high] });
    [arr[i + 1], arr[high]] = [arr[high], arr[i + 1]];
    return i + 1;
}

export default quickSort;