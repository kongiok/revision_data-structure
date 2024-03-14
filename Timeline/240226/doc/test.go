package main

import "fmt"

func calculateAddress(i, j, k, l int) int {
	baseAddress := 200
	d := 5                // 每個元素的儲存空間大小
	D1, D2, D3 := 5, 3, 4 // 每個維度的大小

	// 計算位址
	address := baseAddress + (((i+1)*D1+(j-2))*D2+(k-1))*D3 + (l+2)*d
	return address
}

func main() {
	i, j, k, l := 3, 2, 1, 0 // 要計算的元素索引
	address := calculateAddress(i, j, k, l)
	fmt.Printf("元素A[%d, %d, %d, %d]的位址是: %d\n", i, j, k, l, address)
}
