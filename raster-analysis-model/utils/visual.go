// Package utils provides command line interface visualization tools
// Includes functions for formatted output, color highlighting, timestamps, etc.
package utils

import (
	"fmt"
	"strings"
	"time"
)

// ANSI color control codes
const (
	colorReset  = "\033[0m"  // Reset all styles
	colorRed    = "\033[31m" // Red text
	colorGreen  = "\033[32m" // Green text
	colorYellow = "\033[33m" // Yellow text
	colorBlue   = "\033[34m" // Blue text
	colorCyan   = "\033[36m" // Cyan text
)

// PrintHeader prints the program header
// Displays team information and model name with double-line border
func PrintHeader() {
	fmt.Println(colorCyan + strings.Repeat("═", 90))
	fmt.Printf("%-5sVGE团队暑期培训分析模型演示案例(2025)-3x3栅格平均值计算模型\n", "║")
	fmt.Println(strings.Repeat("═", 90) + colorReset)
}

// PrintSection prints an information block
// Parameters:
//
//	title: Block title
//	lines: Array of content lines
func PrintSection(title string, lines []string) {
	fmt.Printf(colorYellow+"┌ %s "+colorReset+"\n", title)
	for _, line := range lines {
		fmt.Printf(colorYellow+"│ "+colorReset+" %s\n", line)
	}
	fmt.Println(colorYellow + "└" + strings.Repeat("─", 90) + colorReset)
}

// PrintFooter prints the bottom border line
func PrintFooter() {
	fmt.Println(colorCyan + strings.Repeat("═", 90) + colorReset)
}

// PrintConfig prints the configuration parameters table
// Parameters:
//
//	inputFile: Input file path
//	outputFile: Output file path
func PrintConfig(inputFile, outputFile string) {
	fmt.Println(colorBlue + "╔" + strings.Repeat("═", 90) + "╗")
	fmt.Println("║" + colorGreen + "                    配置参数                    " + colorBlue)
	fmt.Println("╠" + strings.Repeat("═", 90) + "╣")
	fmt.Printf("║ %s%s\n", "输入文件:", inputFile)
	fmt.Printf("║ %s%s\n", "输出文件:", outputFile)
	fmt.Println("╚" + strings.Repeat("═", 90) + "╝" + colorReset)
	fmt.Println()
}

// PrintStepStart prints step start information
// Parameters:
//
//	message: Step description
func PrintStepStart(message string) {
	fmt.Printf(colorBlue+"[%s] "+colorCyan+"%s..."+colorReset+"\n", Timestamp(), message)
}

// PrintStepSuccess prints step success information
// Parameters:
//
//	message: Success message
func PrintStepSuccess(message string) {
	fmt.Printf(colorBlue+"[%s] "+colorGreen+"✓ %s"+colorReset+"\n", Timestamp(), message)
}

// PrintStepError prints step error information
// Parameters:
//
//	message: Error description
//	err: Error object
func PrintStepError(message string, err error) {
	fmt.Printf(colorBlue+"[%s] "+colorRed+"✗ %s: %v"+colorReset+"\n", Timestamp(), message, err)
}

// PrintCompletion prints program completion information
// Parameters:
//
//	outputFile: Output file path
func PrintCompletion(outputFile string) {
	fmt.Println()
	fmt.Println(colorGreen + strings.Repeat("━", 90))
	fmt.Printf("  处理完成! \n  结果已保存到: %s\n", outputFile)
	fmt.Println(strings.Repeat("━", 90))
	fmt.Println("  感谢使用3x3栅格平均值计算模型")
	fmt.Println("  VGE团队 © 2025 暑期培训")
	fmt.Println(strings.Repeat("━", 90) + colorReset)
}

// Timestamp generates formatted current time string
// Returns current time string in HH:MM:SS format
func Timestamp() string {
	now := time.Now()
	return fmt.Sprintf("%02d:%02d:%02d", now.Hour(), now.Minute(), now.Second())
}
