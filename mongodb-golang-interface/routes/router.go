package routes

import (
	"github.com/DTRailway/VGE-Fresh-Tutorial/internal/controllers"
	"github.com/gin-gonic/gin"
)

func SetupRouter() *gin.Engine {
	r := gin.Default()

	// API routes
	userRoutes := r.Group("/vge")
	{
		userRoutes.POST("/users", controllers.CreateUser)
	}

	return r
}
