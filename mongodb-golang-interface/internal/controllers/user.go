package controllers

import (
	"go.mongodb.org/mongo-driver/bson/primitive"
	"net/http"

	"github.com/DTRailway/VGE-Fresh-Tutorial/dbOperations"
	"github.com/DTRailway/VGE-Fresh-Tutorial/internal/models"
	"github.com/gin-gonic/gin"
)

// CreateUser godoc
// @Summary      创建用户
// @Description  接收JSON数据创建新用户
// @Tags         users
// @Accept       json
// @Produce      json
// @Param        user body models.CreateRequest true "用户信息"
// @Success      201  {object}  models.UserResponse
// @Router       /users [post]
func CreateUser(c *gin.Context) {
	var req models.CreateRequest

	// Step 1: Bind and validate request data
	if err := c.ShouldBindJSON(&req); err != nil {
		c.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
		return
	}

	// Step 2: Process data through database layer
	insertResult, err := dbOperations.InsertUser(map[string]interface{}{
		"name": req.Name,
		"age":  req.Age,
	})
	if err != nil {
		c.JSON(http.StatusInternalServerError, gin.H{"error": err.Error()})
		return
	}

	// Safely convert ObjectID to string
	objectID := insertResult.(primitive.ObjectID)
	hexID := objectID.Hex() // Convert to a 24-digit hexadecimal string

	// Step 3: Return formatted response
	c.JSON(http.StatusCreated, models.UserResponse{
		ID:   hexID,
		Name: req.Name,
		Age:  req.Age,
	})
}
