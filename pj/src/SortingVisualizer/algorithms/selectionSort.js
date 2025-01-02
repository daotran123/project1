const selectionSort = (array) => {
    const animations = [];
    const arrCopy = [...array];

    for (let i = 0; i < arrCopy.length - 1; i++) {
        let minIndex = i;

        // Tìm chỉ số của phần tử nhỏ nhất trong mảng từ i đến cuối
        for (let j = i + 1; j < arrCopy.length; j++) {
            animations.push({ type: "compare", indices: [minIndex, j] });

            if (arrCopy[j] < arrCopy[minIndex]) {
                minIndex = j;
            }
        }

        // Nếu tìm thấy phần tử nhỏ hơn, hoán đổi nó với phần tử ở vị trí i
        if (minIndex !== i) {
            animations.push({ type: "swap", indices: [i, minIndex] });
            [arrCopy[i], arrCopy[minIndex]] = [arrCopy[minIndex], arrCopy[i]];
        }

        // Đánh dấu phần tử i là đã sắp xếp
        animations.push({ type: "final", index: i });
    }

    // Phần tử cuối cùng tự động được sắp xếp
    animations.push({ type: "final", index: arrCopy.length - 1 });
    return animations;
};

export default selectionSort;
