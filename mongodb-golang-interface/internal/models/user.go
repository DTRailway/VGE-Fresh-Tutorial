package models

// CreateRequest defines the request structure for user creation
type CreateRequest struct {
	Name string `json:"name" binding:"required,min=2"` // Username (min 2 chars)
	Age  int    `json:"age" binding:"gte=0"`           // Age (non-negative integer)
}

// UserResponse defines the API response format for user data
type UserResponse struct {
	ID   string `json:"id"`   // Unique user identifier
	Name string `json:"name"` // User's display name
	Age  int    `json:"age"`  // User's age in years
}