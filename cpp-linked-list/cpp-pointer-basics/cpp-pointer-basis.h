#pragma once

#ifndef CPP_POINTER_BASIS
#define CPP_POINTER_BASIS

#include <iostream>
#include <memory>
using namespace std;

// ==================== Core Concepts Module ====================
/**
 * @brief Demonstrates fundamental pointer concepts including:
 *        - Memory addresses
 *        - Dereferencing
 *        - Pointer arithmetic
 *
 * @note Recommended as the first demonstration to establish foundation
 */
void PointerDemo();

/**
 * @brief Demonstrates pass-by-value semantics
 * @param val Integer value (copied)
 *
 * @note Shows how primitive types are passed by value
 * @see Compare with ModifyValueByPointer and ModifyValueByReference
 */
void ModifyValueByValue(int val);

/**
 * @brief Demonstrates pass-by-pointer semantics
 * @param ptr Pointer to integer value
 *
 * @note Requires explicit dereferencing
 * @warning Always validate pointer before use
 */
void ModifyValueByPointer(int* ptr);

/**
 * @brief Demonstrates pass-by-reference semantics
 * @param ref Reference to integer value
 *
 * @note C++ specific feature
 * @advantage Safer than pointers (cannot be null)
 */
void ModifyValueByReference(int& ref);

/**
 * @brief Comparative demonstration of all parameter passing techniques
 *
 * @note Recommended after individual demonstrations
 * @output Shows side-by-side comparison of value/pointer/reference
 */
void CrossModifyDemo();

// ==================== Multiple Returns Module ====================
/**
 * @brief Returns multiple values through pointer parameters
 * @param out_val1 [OUT] Pointer to first return value
 * @param out_val2 [OUT] Pointer to second return value
 * @return true if operation succeeded
 *
 * @warning Both output pointers must be valid
 * @legacy Traditional C-style multiple returns
 */
bool ReturnByPointer(int* out_val1, int* out_val2);

// ==================== Error Handling Module ====================
/**
 * @brief Demonstrates dangers of uninitialized pointers
 *
 * @note Dangerous operations are commented out
 * @best_practice Always initialize pointers
 */
void WildPointerDemo();

/**
 * @brief Demonstrates dangling pointer scenarios
 *
 * @note Shows proper memory deallocation practices
 * @critical Always nullify pointers after deletion
 */
void DanglingPointerDemo();

/**
 * @brief Demonstrates memory leaks and prevention techniques
 *
 * @note Contrasts manual vs smart pointer management
 * @recommended Use RAII principles for resource management
 */
void MemoryLeakDemo();

#endif // CPP_POINTER_BASIS