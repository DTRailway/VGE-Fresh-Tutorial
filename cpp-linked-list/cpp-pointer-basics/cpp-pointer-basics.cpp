#include "cpp-pointer-basis.h"

// ======================================================================
// Section 1: Core Pointer Concepts
// ======================================================================

/**
 * @brief Demonstrates fundamental pointer mechanics including:
 *        - Pointer declaration/initialization
 *        - Address-of (&) and dereference (*) operators
 *        - Pointer size and memory layout
 *
 * @details Key Teaching Points:
 *          1. Pointers store memory addresses
 *          2. The relationship between variables, addresses and pointers
 *          3. Platform-dependent pointer characteristics
 *
 * @usage Should be called first to establish baseline understanding
 *
 * @output Visualizes:
 *         - Variable addresses and values
 *         - Pointer-to-variable relationships
 *         - Pointer size information
 */
void PointerDemo()
{
	// ------------------------------------------------------------------
	// Part 1: Variable Basics
	// ------------------------------------------------------------------
	int i = 3;  // Primitive variable declaration

	printf("[Variable Mechanics]\n");
	printf("|-- Value: %d\n", i);
	printf("|-- Address: %p\n", (void*)&i);  // %p requires void* cast

	// ------------------------------------------------------------------
	// Part 2: Pointer Fundamentals
	// ------------------------------------------------------------------
	int* p = nullptr;  // Always initialize pointers
	p = &i;            // Address-of assignment

	printf("\n[Pointer Mechanics]\n");
	printf("|-- Pointer address: %p (storage location)\n", (void*)&p);
	printf("|-- Pointer value: %p (points to i)\n", (void*)p);
	printf("|-- Dereferenced value: %d\n", *p);

	// ------------------------------------------------------------------
	// Part 3: System Characteristics
	// ------------------------------------------------------------------
	printf("\n[System Characteristics]\n");
	printf("|-- sizeof(pointer): %zu bytes\n", sizeof(p));
	printf("|-- sizeof(pointed): %zu bytes\n", sizeof(*p));

	// ------------------------------------------------------------------
	// Part 4: Modification Through Pointer
	// ------------------------------------------------------------------
	*p = 42;  // Dereference modification
	printf("\n[Modification Results]\n");
	printf("|-- New i: %d\n", i);
	printf("|-- New *p: %d\n", *p);
}

// ======================================================================
// Section 2: Parameter Passing Techniques
// ======================================================================

/**
 * @brief Demonstrates pass-by-value semantics
 *
 * @param val [IN] Integer value (copy)
 *
 * @teaching_points:
 *          - Creates independent copy
 *          - Original remains unchanged
 *          - Different memory address
 *
 * @output Shows:
 *         - Parameter address differs from original
 *         - Original remains unchanged post-call
 */
void ModifyValueByValue(int val) {
	cout << "\n[Pass-by-Value]\n";
	cout << "|-- Incoming value: " << val << endl;
	cout << "|-- Parameter address: " << &val << endl;

	val = 5;  // Only modifies local copy
	cout << "|-- Modified value: " << val << endl;
}

/**
 * @brief Demonstrates pass-by-pointer semantics
 *
 * @param ptr [IN/OUT] Pointer to integer
 *
 * @teaching_points:
 *          - Requires explicit dereferencing
 *          - Must check for nullptr
 *          - Modifies original variable
 *
 * @security:
 *          - Includes nullptr check
 *          - Shows safe access pattern
 */
void ModifyValueByPointer(int* ptr) {
	cout << "\n[Pass-by-Pointer]\n";
	cout << "|-- Received address: " << ptr << endl;

	if (ptr) {
		cout << "|-- Original value: " << *ptr << endl;
		*ptr = 5;  // Safe dereference
		cout << "|-- Modified value: " << *ptr << endl;
	}
	else {
		cerr << "|-- ERROR: Null pointer detected\n";
	}
}

/**
 * @brief Demonstrates pass-by-reference semantics
 *
 * @param ref [IN/OUT] Reference to integer
 *
 * @teaching_points:
 *          - No dereferencing needed
 *          - Impossible to be null
 *          - Modifies original directly
 *
 * @output Shows:
 *         - Reference binding address
 *         - Direct modification effects
 */
void ModifyValueByReference(int& ref) {
	cout << "\n[Pass-by-Reference]\n";
	cout << "|-- Reference address: " << &ref << endl;
	cout << "|-- Original value: " << ref << endl;
	ref = 5;
	cout << "|-- Modified value: " << ref << endl;
}

// ======================================================================
// Section 3: Multi-Return Techniques
// ======================================================================

/**
 * @brief Traditional multi-return via output parameters
 *
 * @param out_val1 [OUT] First return value
 * @param out_val2 [OUT] Second return value
 * @return bool True if successful
 *
 * @best_practices:
 *          - Clearly mark output parameters
 *          - Validate pointer parameters
 *          - Return status indicator
 *
 * @output Documents:
 *         - Parameter validation
 *         - Explicit output assignments
 */
bool ReturnByPointer(int* out_val1, int* out_val2) {
	cout << "\n[Multi-Return: Pointer Parameters]\n";

	// Parameter validation
	if (!out_val1 || !out_val2) {
		cerr << "|-- ERROR: Invalid output parameters\n";
		return false;
	}

	// Explicit output assignments
	*out_val1 = 1 + 1;
	*out_val2 = 1 + 2;

	cout << "|-- Set *out_val1 = " << *out_val1 << endl;
	cout << "|-- Set *out_val2 = " << *out_val2 << endl;

	return true;
}

// ======================================================================
// Section 4: Common Pointer Pitfalls
// ======================================================================

/**
 * @brief Demonstrates dangers of uninitialized pointers
 *
 * @teaching_points:
 *          - Shows undefined behavior
 *          - Contrasts with safe initialization
 *          - Teaches defensive programming
 *
 * @safety:
 *          - Dangerous code is commented out
 *          - Shows proper initialization
 *          - Includes null checks
 */
void WildPointerDemo() {
	cout << "\n[Uninitialized Pointers]\n";

	// DANGEROUS EXAMPLE (commented out)
	// int* dangerousPtr;
	// cout << *dangerousPtr << endl;  // CRASH!

	// SAFE PRACTICE
	int* safePtr = nullptr;
	if (safePtr) {
		cout << "|-- Value: " << *safePtr << endl;
	}
	else {
		cout << "|-- SAFETY: Null check passed\n";
	}
}

void DanglingPointerDemo() {
	cout << "\n[Dangling Pointers]\n";
	int* ptr = new int(42);
	cout << "|-- Allocated value: " << *ptr << endl;

	delete ptr;
	ptr = nullptr;  // Correct practice

	// DANGEROUS (commented out)
	// cout << "|-- Freed value: " << *ptr << endl;

	if (ptr) {
		cout << "|-- Value: " << *ptr << endl;
	}
	else {
		cout << "|-- SAFETY: Pointer nullified\n";
	}
}

// ======================================================================
// Section 5: Resource Management
// ======================================================================

/**
 * @brief Compares manual vs automatic memory management
 *
 * @teaching_points:
 *          - Shows delete pairing requirement
 *          - Introduces smart pointers
 *          - Demonstrates RAII principle
 *
 * @output Visualizes:
 *         - Memory addresses
 *         - Reference counts
 *         - Proper cleanup
 */
void MemoryLeakDemo() {
	cout << "\n[Memory Management]\n";

	// Manual management (risky)
	int* manualPtr = new int(100);
	cout << "|-- Manual allocation: " << manualPtr << endl;
	delete manualPtr;  // Must match new

	// Automatic management (recommended)
	auto smartPtr = make_shared<int>(200);
	cout << "|-- Smart pointer:\n";
	cout << "    |-- Address: " << smartPtr.get() << endl;
	cout << "    |-- References: " << smartPtr.use_count() << endl;
}

// ======================================================================
// Section 6: Comparison Demo
// ======================================================================

void CrossModifyDemo() {
	cout << "\n=== Parameter Passing Comparison ===\n";
	int original = 10;

	cout << "\n[Before Modification]\n";
	cout << "Original value: " << original << endl;
	cout << "Original address: " << &original << endl;

	// Value pass
	ModifyValueByValue(original);
	cout << "\nAfter pass-by-value: " << original << endl;

	// Pointer pass
	original = 10;
	ModifyValueByPointer(&original);
	cout << "\nAfter pass-by-pointer: " << original << endl;

	// Reference pass
	original = 10;
	ModifyValueByReference(original);
	cout << "\nAfter pass-by-reference: " << original << endl;
}