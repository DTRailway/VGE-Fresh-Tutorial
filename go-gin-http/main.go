package main

import (
	"github.com/gin-gonic/gin"
	"net/http"
	"path/filepath"
)

func main() {
	r := gin.Default()

	// GET demo: Welcome endpoint with name parameter
	r.GET("/hello", func(c *gin.Context) {
		name := c.DefaultQuery("name", "FreshMan") // Default value handling
		c.JSON(http.StatusOK, gin.H{
			"message": "Welcome to VGE·Group, " + name + "!",
		})
	})

	// Image upload endpoint (multipart/form-data)
	r.POST("/upload", func(c *gin.Context) {
		file, err := c.FormFile("image") // Required form field
		if err != nil {
			c.AbortWithStatusJSON(http.StatusBadRequest, gin.H{"error": "Image file required"})
			return
		}

		filename := filepath.Base(file.Filename) // Secure filename handling
		dst := "uploads/" + filename
		if err := c.SaveUploadedFile(file, dst); err != nil {
			c.AbortWithStatusJSON(http.StatusInternalServerError, gin.H{"error": "File save failed"})
			return
		}

		// Return accessible URL
		c.JSON(http.StatusOK, gin.H{
			"image_url": "http://" + c.Request.Host + "/files/" + filename,
			"size":      file.Size,
		})
	})

	// Static file serving
	r.GET("/files/:filename", func(c *gin.Context) {
		c.File("uploads/" + c.Param("filename"))
	})

	// Unmatched routes redirect
	r.NoRoute(func(c *gin.Context) {
		c.Redirect(http.StatusFound, "https://www.vrlab.org.cn") // 302 redirect
	})

	r.Run() // Default listen on :8080
}
