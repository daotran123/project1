import React from "react";
import "./SortingVisualizer.css";
import bubbleSort from "./algorithms/bubbleSort";
import mergeSort from "./algorithms/mergeSort";
import quickSort from "./algorithms/quickSort";
import selectionSort from "./algorithms/selectionSort";

export default class SortingVisualizer extends React.Component {
    constructor(props) {
        super(props);

        this.state = {
            array: [],
            speed: 50, // Mặc định tốc độ là 50
            arraySize: 10, // Mặc định số lượng phần tử là 10
            inputArray: "", // Chuỗi nhập vào từ người dùng
            isSorting: false, // Thêm flag kiểm tra trạng thái sắp xếp
        };
    }

    resetArray() {
        if (this.state.isSorting) return; // Nếu đang sắp xếp, không làm gì

        // Reset màu sắc của tất cả các thanh về màu mặc định
        const bars = document.getElementsByClassName("array-bar");
        for (let i = 0; i < bars.length; i++) {
            bars[i].style.backgroundColor = "blue"; // Đặt lại màu sắc của tất cả các thanh
        }

        const { arraySize } = this.state;
        const array = [];
        for (let i = 0; i < arraySize; i++) {
            array.push(randomIntFromInterval(5, 500));
        }
        this.setState({ array });
    }

    handleSort(sortAlgorithm) {
        if (this.state.isSorting) return; // Nếu đang sắp xếp, không làm gì
        this.setState({ isSorting: true }); // Đánh dấu bắt đầu sắp xếp
        const { array } = this.state;
        const animations = sortAlgorithm(array);
        this.animateSort(animations);
    }

    // Hàm điều chỉnh tốc độ
    handleSpeedChange = (event) => {
        this.setState({ speed: event.target.value });
    };

    // Hàm thay đổi số lượng phần tử mảng
    handleArraySizeChange = (event) => {
        const value = event.target.value; // Giới hạn trong phạm vi 10 đến 100
        this.setState({ arraySize: value }, () => this.resetArray()); // Cập nhật và reset lại mảng
    };

    // Hàm xử lý nhập mảng từ người dùng
    handleInputChange = (event) => {
        this.setState({ inputArray: event.target.value });
    };

    handleInputSubmit = () => {
        const { inputArray } = this.state;
        const array = inputArray
            .split(" ")
            .map((num) => parseInt(num.trim() * 10))
            .filter((num) => !isNaN(num));

        this.setState({ array });
        const bars = document.getElementsByClassName("array-bar");
        for (let i = 0; i < bars.length; i++) {
            bars[i].style.backgroundColor = "blue"; // Đặt lại màu sắc của tất cả các thanh
        }
    };

    async animateSort(animations) {
        const bars = document.getElementsByClassName("array-bar");

        for (let i = 0; i < animations.length; i++) {
            const { type, indices, height, index } = animations[i];

            // Xử lý từng loại animation
            if (type === "compare") {
                const [barOneIdx, barTwoIdx] = indices;
                const barOneStyle = bars[barOneIdx].style;
                const barTwoStyle = bars[barTwoIdx].style;

                barOneStyle.backgroundColor = "yellow";
                barTwoStyle.backgroundColor = "yellow";

                await this.sleep(this.state.speed);

                barOneStyle.backgroundColor = "blue";
                barTwoStyle.backgroundColor = "blue";
            } else if (type === "swap") {
                const [barOneIdx, barTwoIdx] = indices;
                const barOneStyle = bars[barOneIdx].style;
                const barTwoStyle = bars[barTwoIdx].style;

                const tempHeight = barOneStyle.height;
                barOneStyle.height = barTwoStyle.height;
                barTwoStyle.height = tempHeight;

                await this.sleep(this.state.speed);
            } else if (type === "overwrite") {
                bars[index].style.height = `${height}px`;
                await this.sleep(this.state.speed);
            } else if (type === "final") {
                bars[index].style.backgroundColor = "red";
                await this.sleep(this.state.speed);
            }
        }
        this.setState({ isSorting: false }); // Đánh dấu kết thúc sắp xếp
    }

    // Hàm sleep để tạo hiệu ứng chờ
    sleep(ms) {
        return new Promise((resolve) => setTimeout(resolve, ms));
    }


    render() {
        const { array, speed, arraySize, inputArray } = this.state;
        console.log(array);
        return (
            <div>

                <div className="array-container">
                    {array.map((value, idx) => (
                        <div
                            className="array-bar"
                            style={{
                                height: `${value}px`,
                                backgroundColor: "blue",
                                margin: "0 2px",
                                width: "20px", // Đặt chiều rộng cố định
                            }}
                        ></div>
                    ))}
                </div>


                <button onClick={() => this.resetArray()}>Generate New Array</button>
                <button onClick={() => this.handleSort(bubbleSort)}>Bubble Sort</button>
                <button onClick={() => this.handleSort(mergeSort)}>Merge Sort</button>
                <button onClick={() => this.handleSort(quickSort)}>Quick Sort</button>
                <button onClick={() => this.handleSort(selectionSort)}>Selection Sort</button>
                <div>
                    <label>Speed: {speed}ms</label>
                    <input
                        type="range"
                        min="10"
                        max="500"
                        value={speed}
                        onChange={this.handleSpeedChange}
                    />
                </div>

                <div>
                    <label>Array Size: {arraySize}</label>
                    <br />
                    <input
                        type="text"
                        value={arraySize}
                        onChange={this.handleArraySizeChange}
                    />
                </div>

                <div>
                    <label>Input Array:</label>
                    <br />
                    <input
                        type="text"
                        value={inputArray}
                        onChange={this.handleInputChange}
                    />
                    <button onClick={this.handleInputSubmit}>Submit</button>
                </div>
            </div>
        );
    }
}

function randomIntFromInterval(min, max) {
    return Math.floor(Math.random() * (max - min + 1) + min);
}
