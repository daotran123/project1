const bubbleSort = (array) => {
    const animations = [];
    const arrCopy = [...array];

    for (let i = 0; i < arrCopy.length - 1; i++) {
        for (let j = 0; j < arrCopy.length - i - 1; j++) {
            animations.push({ type: "compare", indices: [j, j + 1] });

            if (arrCopy[j] > arrCopy[j + 1]) {
                animations.push({ type: "swap", indices: [j, j + 1] });
                [arrCopy[j], arrCopy[j + 1]] = [arrCopy[j + 1], arrCopy[j]];
            }
        }
        // Đánh dấu phần tử cuối cùng trong vòng lặp này là đã sắp xếp
        animations.push({ type: "final", index: arrCopy.length - i - 1 });
    }
    // Phần tử đầu tiên cũng được sắp xếp sau vòng lặp cuối cùng
    animations.push({ type: "final", index: 0 });
    return animations;
};

export default bubbleSort;

