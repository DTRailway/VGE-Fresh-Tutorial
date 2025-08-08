package main

import (
	"context"
	"github.com/DTRailway/VGE-Fresh-Tutorial/dbOperations"
	_ "github.com/DTRailway/VGE-Fresh-Tutorial/docs" // necessary
	"github.com/DTRailway/VGE-Fresh-Tutorial/routes"
	swaggerFiles "github.com/swaggo/files"
	ginSwagger "github.com/swaggo/gin-swagger"
	"log"
)

// @title           VGE团队·数据模型知识分布式组织管理引擎API文档
// @version         1.0
// @description     基于Golang和MongoDB构建的分布式系统核心接口\n\n**环境地址**\n- 项目地址：`https://github.com/DTRailway/VGE-Fresh-Tutorial`\n- 小组网站：`http://www.vrlab.org.cn/`
// @termsOfService  http://swagger.io/terms/
// @contact.name   API Support
// @contact.url    http://www.swagger.io/support
// @contact.email  support@swagger.io
// @license.name  Apache 2.0
// @license.url   http://www.apache.org/licenses/LICENSE-2.0.html
// @host      localhost:8080
// @BasePath  /vge
// @securityDefinitions.basic  BasicAuth
// @externalDocs.description  OpenAPI
// @externalDocs.url          https://swagger.io/resources/open-api/
func main() {
	// 1. Initialize database
	client, err := dbOperations.InitMongoDB("mongodb://admin:123456@localhost:27017")
	if err != nil {
		log.Fatal("DB connection failed: ", err)
	}
	defer func() {
		if err := client.Disconnect(context.Background()); err != nil {
			log.Println("DB disconnection warning:", err)
		}
	}()

	// 2. Setup routes
	r := routes.SetupRouter()

	// 3. Enable Swagger docs
	r.GET("/swagger/*any", ginSwagger.WrapHandler(swaggerFiles.Handler))

	// 4. Start server
	log.Println("Server running at http://localhost:8080")
	log.Fatal(r.Run(":8080"))
}
