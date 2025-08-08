package main

import (
	"encoding/csv"
	"flag"
	"fmt"
	"github.com/DTRailway/VGE-Fresh-Tutorial/utils"
	"os"
	"path/filepath"
	"strconv"
	"strings"
)

func main() {
	// ==================== 启动说明 ====================
	utils.PrintHeader()
	utils.PrintSection("模型概述", []string{
		"一个基础的栅格数据分析模型，用于计算3x3数值矩阵的平均值",
		"演示了从文件读取数据、进行计算处理、结果输出的完整流程",
	})
	utils.PrintSection("主要功能", []string{
		"1. 从文本文件读取3x3栅格数据（空格或制表符分隔）",
		"2. 计算9个数值的平均值",
		"3. 将原始数据和结果输出为CSV格式文件",
	})
	utils.PrintSection("典型应用场景", []string{
		"- GIS栅格数据均值滤波（影像平滑）",
		"- GIS栅格数据分辨率降尺度",
	})
	utils.PrintFooter()
	fmt.Println()

	// ==================== 参数解析 ====================
	inputFile := flag.String("input", "input.txt", "输入文件路径（文本格式）")
	outputFile := flag.String("output", "output.csv", "输出文件路径（CSV格式）")
	flag.Parse()

	// 获取绝对路径以便更清晰地显示
	absInput, _ := filepath.Abs(*inputFile)
	absOutput, _ := filepath.Abs(*outputFile)
	utils.PrintConfig(absInput, absOutput)

	// ==================== 数据输入 ====================
	utils.PrintStepStart("正在读取输入文件")
	grid, err := readGridFromFile(*inputFile)
	if err != nil {
		utils.PrintStepError("读取输入文件失败", err)
		os.Exit(1)
	}
	utils.PrintStepSuccess(fmt.Sprintf("输入文件读取成功 (%dx%d 栅格)", len(grid), len(grid[0])))

	// ==================== 计算处理 ====================
	utils.PrintStepStart("正在计算平均值")
	average := calculateAverage(grid)
	utils.PrintStepSuccess(fmt.Sprintf("计算完成 - 平均值: %.2f", average))

	// ==================== 结果输出 ====================
	utils.PrintStepStart("正在写入结果文件")
	err = writeResultToCSV(*outputFile, grid, average)
	if err != nil {
		utils.PrintStepError("写入输出文件失败", err)
		os.Exit(1)
	}
	utils.PrintStepSuccess(fmt.Sprintf("结果文件写入成功 "))

	// ==================== 完成通知 ====================
	utils.PrintCompletion(*outputFile)
}

// Read 3x3 grid from text file
func readGridFromFile(filename string) ([3][3]float64, error) {
	var grid [3][3]float64

	content, err := os.ReadFile(filename)
	if err != nil {
		return grid, err
	}

	lines := strings.Split(string(content), "\n")
	for i := 0; i < 3; i++ {
		if i >= len(lines) {
			return grid, fmt.Errorf("input file requires 3 lines of data")
		}

		values := strings.Fields(lines[i])
		if len(values) < 3 {
			return grid, fmt.Errorf("each line requires at least 3 values")
		}

		for j := 0; j < 3; j++ {
			grid[i][j], err = strconv.ParseFloat(values[j], 64)
			if err != nil {
				return grid, fmt.Errorf("value parsing error: %v", err)
			}
		}
	}

	return grid, nil
}

// Calculate average of 3x3 grid
func calculateAverage(grid [3][3]float64) float64 {
	var sum float64
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			sum += grid[i][j]
		}
	}
	return sum / 9
}

// Write result to CSV file
func writeResultToCSV(filename string, grid [3][3]float64, average float64) error {
	file, err := os.Create(filename)
	if err != nil {
		return err
	}
	defer file.Close()

	writer := csv.NewWriter(file)
	defer writer.Flush()

	// Write grid data
	for i := 0; i < 3; i++ {
		record := make([]string, 3)
		for j := 0; j < 3; j++ {
			record[j] = fmt.Sprintf("%.1f", grid[i][j])
		}
		if err := writer.Write(record); err != nil {
			return err
		}
	}

	// Write average value
	if err := writer.Write([]string{"Average", fmt.Sprintf("%.2f", average)}); err != nil {
		return err
	}

	return nil
}
