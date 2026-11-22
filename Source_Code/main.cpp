/*
 * CS212 - Data Structures Project
 * Help Desk Priority Simulation
 * 
 * File: main.cpp
 * Main program file - Menu-driven interface
 * User interaction, input validation, and testing
 * 
 * Responsibilities:
 * - Display main menu
 * - Handle user input
 * - Call HelpDesk functions
 * - Validate all inputs
 * - Test all features
 * - Handle errors gracefully
 */

#include "HelpDesk.h"
#include <iostream>
#include <limits>
using namespace std;

// Function prototypes
void displayMainMenu();
void handleRequestManagement(HelpDesk& helpDesk);
void handleAgentManagement(HelpDesk& helpDesk);
void handleViewOperations(HelpDesk& helpDesk);
void handleSearchOperations(HelpDesk& helpDesk);
void runTests(HelpDesk& helpDesk);
void clearInputBuffer();
int getValidatedIntInput(const string& prompt, int min, int max);
string getValidatedStringInput(const string& prompt);

int main() {
    // TODO: Complete main function
    
    // 1. Display welcome message
    cout << "========================================" << endl;
    cout << "   Help Desk Priority Simulation" << endl;
    cout << "   CS212 - Data Structures Project" << endl;
    cout << "========================================" << endl;
    cout << endl;

    // 2. Create HelpDesk object
    HelpDesk helpDesk;

    // 3. Add some sample agents for testing (optional)
    // helpDesk.addAgent(101, "Ahmed Ali", "Hardware", "ahmed@email.com", "0123456789");
    // helpDesk.addAgent(102, "Sara Mohamed", "Software", "sara@email.com", "0123456788");
    // helpDesk.addAgent(103, "Omar Hassan", "Network", "omar@email.com", "0123456787");

    // 4. Main program loop
    int choice;
    bool running = true;

    while (running) {
        // TODO:
        // - Display main menu
        // - Get user choice (with validation)
        // - Use switch statement to handle choices
        // - Call appropriate handler functions
        // - Handle invalid input
        // - Provide exit option
        
        displayMainMenu();
        choice = getValidatedIntInput("Enter your choice: ", 0, 9);

        switch (choice) {
            case 1:
                // Request Management submenu
                handleRequestManagement(helpDesk);
                break;
            case 2:
                // Agent Management submenu
                handleAgentManagement(helpDesk);
                break;
            case 3:
                // View Operations submenu
                handleViewOperations(helpDesk);
                break;
            case 4:
                // Search Operations submenu
                handleSearchOperations(helpDesk);
                break;
            case 5:
                // Display Statistics
                helpDesk.displayStatistics();
                break;
            case 6:
                // Run Tests
                runTests(helpDesk);
                break;
            case 0:
                // Exit
                cout << "\nThank you for using Help Desk System!" << endl;
                running = false;
                break;
            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }

        if (running) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
    }

    return 0;
}

/*
 * Function: displayMainMenu
 * Purpose: Show main menu options to user
 */
void displayMainMenu() {
    // TODO: Display organized menu
    cout << "\n========================================" << endl;
    cout << "           MAIN MENU" << endl;
    cout << "========================================" << endl;
    cout << "1. Request Management" << endl;
    cout << "2. Agent Management" << endl;
    cout << "3. View Operations" << endl;
    cout << "4. Search Operations" << endl;
    cout << "5. Display Statistics" << endl;
    cout << "6. Run System Tests" << endl;
    cout << "0. Exit" << endl;
    cout << "========================================" << endl;
}

/*
 * Function: handleRequestManagement
 * Purpose: Submenu for request operations
 */
void handleRequestManagement(HelpDesk& helpDesk) {
    // TODO: Implement request management submenu
    // Options:
    // 1. Create New Request
    // 2. Process Next Request
    // 3. Escalate Request
    // 4. Resolve Request
    // 5. View Request Details
    // 0. Back to Main Menu
    //
    // For each option:
    // - Get required input with validation
    // - Call appropriate HelpDesk function
    // - Display result
}

/*
 * Function: handleAgentManagement
 * Purpose: Submenu for agent operations
 */
void handleAgentManagement(HelpDesk& helpDesk) {
    // TODO: Implement agent management submenu
    // Options:
    // 1. Add New Agent
    // 2. Remove Agent
    // 3. View All Agents
    // 4. Assign Agent to Request
    // 0. Back to Main Menu
    //
    // For each option:
    // - Get required input with validation
    // - Call appropriate HelpDesk function
    // - Display result
}

/*
 * Function: handleViewOperations
 * Purpose: Submenu for viewing data
 */
void handleViewOperations(HelpDesk& helpDesk) {
    // TODO: Implement view operations submenu
    // Options:
    // 1. View All Requests (BST Inorder)
    // 2. View Pending Requests (Queue)
    // 3. View Escalations (Stack)
    // 4. View All Agents (Linked List)
    // 5. View Specific Request
    // 0. Back to Main Menu
}

/*
 * Function: handleSearchOperations
 * Purpose: Submenu for search and sort operations
 */
void handleSearchOperations(HelpDesk& helpDesk) {
    // TODO: Implement search operations submenu
    // Options:
    // 1. Search Request by ID (BST Search - O(log n))
    // 2. Search Agent by Name (Linear Search - O(n))
    // 3. Sort Requests by Priority (Sorting Algorithm)
    // 0. Back to Main Menu
    //
    // Display algorithm complexity for each operation
}

/*
 * Function: runTests
 * Purpose: Automated testing of all features
 */
void runTests(HelpDesk& helpDesk) {
    // TODO: Implement comprehensive tests
    cout << "\n========================================" << endl;
    cout << "         RUNNING SYSTEM TESTS" << endl;
    cout << "========================================" << endl;

    // Test 1: Stack Operations
    cout << "\n--- TEST 1: Stack (Escalations) ---" << endl;
    // - Create and escalate requests
    // - Test push, pop, peek
    // - Test empty and full conditions

    // Test 2: Queue Operations
    cout << "\n--- TEST 2: Queue (Priority Requests) ---" << endl;
    // - Create multiple requests with different priorities
    // - Test enqueue, dequeue
    // - Verify priority ordering
    // - Test empty and full conditions

    // Test 3: Linked List Operations
    cout << "\n--- TEST 3: Linked List (Agents) ---" << endl;
    // - Add multiple agents
    // - Test insert, delete, search
    // - Test update operations
    // - Test traversal

    // Test 4: BST Operations
    cout << "\n--- TEST 4: BST (Request Lookup) ---" << endl;
    // - Insert multiple requests
    // - Test search (found and not found)
    // - Test delete
    // - Test traversals (inorder, preorder)

    // Test 5: Integration Test
    cout << "\n--- TEST 5: Integration ---" << endl;
    // - Create request → goes to Queue and BST
    // - Process request → dequeue and assign agent
    // - Escalate request → goes to Stack
    // - Resolve request → update BST
    // Verify data consistency across structures

    // Test 6: Edge Cases
    cout << "\n--- TEST 6: Edge Cases ---" << endl;
    // - Empty structures
    // - Single element
    // - Full capacity
    // - Invalid IDs
    // - Duplicate IDs

    // Test 7: Searching Algorithm
    cout << "\n--- TEST 7: Search Algorithm ---" << endl;
    // - Test BST search (O(log n))
    // - Test linear search (O(n))
    // - Compare performance

    // Test 8: Sorting Algorithm
    cout << "\n--- TEST 8: Sort Algorithm ---" << endl;
    // - Create requests with random priorities
    // - Sort by priority
    // - Verify sorted order
    // - Display Big-O analysis

    cout << "\n========================================" << endl;
    cout << "         ALL TESTS COMPLETED" << endl;
    cout << "========================================" << endl;
}

/*
 * Function: clearInputBuffer
 * Purpose: Clear input buffer after invalid input
 */
void clearInputBuffer() {
    // TODO: Clear cin buffer
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/*
 * Function: getValidatedIntInput
 * Purpose: Get integer input with validation and range checking
 * Parameters:
 *   - prompt: Message to display
 *   - min: Minimum allowed value
 *   - max: Maximum allowed value
 * Returns: Validated integer
 */
int getValidatedIntInput(const string& prompt, int min, int max) {
    // TODO: Implement input validation
    // 1. Display prompt
    // 2. Get input
    // 3. Check if valid integer
    // 4. Check if in range [min, max]
    // 5. If invalid, display error and repeat
    // 6. Return valid value
    int value;
    bool valid = false;

    while (!valid) {
        cout << prompt;
        if (cin >> value) {
            if (value >= min && value <= max) {
                valid = true;
            } else {
                cout << "Error: Value must be between " << min << " and " << max << endl;
            }
        } else {
            cout << "Error: Please enter a valid number!" << endl;
            clearInputBuffer();
        }
    }
    
    clearInputBuffer(); // Clear remaining newline
    return value;
}

/*
 * Function: getValidatedStringInput
 * Purpose: Get non-empty string input
 * Parameters:
 *   - prompt: Message to display
 * Returns: Non-empty string
 */
string getValidatedStringInput(const string& prompt) {
    // TODO: Implement string validation
    // 1. Display prompt
    // 2. Get input
    // 3. Check if not empty
    // 4. If empty, display error and repeat
    // 5. Return valid string
    string value;
    bool valid = false;

    while (!valid) {
        cout << prompt;
        getline(cin, value);
        
        if (!value.empty()) {
            valid = true;
        } else {
            cout << "Error: Input cannot be empty!" << endl;
        }
    }

    return value;
}
