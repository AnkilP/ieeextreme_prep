package main

import (
	"fmt"
)

func solution(a []int) []int {
	var b []int
	num_ones := 0
	for _, x := range a {
		if x == 1 {
			num_ones++
		}
	}

	num_remove := len(a) / 2
	//cases
	if num_ones > num_remove {
		if num_ones%2 == 1 {
			for i := 0; i < num_ones-1; i++ {
				b = append(b, 1)
			}
		} else {
			for i := 0; i < num_ones; i++ {
				b = append(b, 1)
			}
		}
	} else {
		for i := 0; i < len(a)-num_ones; i++ {
			b = append(b, 0)
		}
	}

	return b
}

func main() {

	var test_cases int
	fmt.Scanf("%d\n", &test_cases)
	for i := 0; i < test_cases; i++ {
		var length int
		fmt.Scanf("%d\n", &length)
		line := make([]int, length)
		for i, _ := range line {
			fmt.Scanf("%d", &line[i])
		}

		// fmt.Println(line)
		ans := solution(line)
		fmt.Printf("%d\n", len(ans))
		for _, x := range ans {
			fmt.Printf("%d ", x)
		}
		fmt.Println()
	}
}
