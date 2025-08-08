package dbOperations

import (
	"context"
	"log"

	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
)

var Client *mongo.Client

// InitMongoDB Initialize MongoDB connection
func InitMongoDB(uri string) (*mongo.Client, error) {
	client, err := mongo.Connect(context.Background(), options.Client().ApplyURI(uri))
	if err != nil {
		return nil, err
	}

	// Verify connection
	err = client.Ping(context.Background(), nil)
	if err != nil {
		return nil, err
	}

	Client = client
	log.Println("MongoDB connected successfully")
	return client, nil
}

// InsertUser 插入用户文档
func InsertUser(doc map[string]interface{}) (interface{}, error) {
	collection := Client.Database("vge").Collection("users")
	result, err := collection.InsertOne(context.Background(), doc)
	return result.InsertedID, err
}
