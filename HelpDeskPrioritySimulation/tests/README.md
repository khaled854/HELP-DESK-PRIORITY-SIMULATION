# TEST SUITE DIRECTORY

## Purpose
Contains all test files and test case documentation for the Help-Desk Priority Simulation project.

## Structure

```
tests/
├── README.md                 ← You are here
├── unit/                     ← Unit tests for each module
│   ├── stack/               ← EscalationStack tests (Member 1)
│   ├── queue/               ← PriorityRequestQueue tests (Member 2)
│   ├── linked_list/         ← AgentLinkedList tests (Member 3)
│   ├── bst/                 ← RequestBST tests (Member 4)
│   ├── services/            ← Service layer tests (All members)
│   └── algorithms/          ← Merge Sort tests (Member 6)
├── integration/              ← Cross-module workflow tests
└── test_cases/               ← Test case documentation
```

## Testing Guidelines

### Unit Tests
Each member creates test files for their owned module:
- Test all public functions
- Cover normal, empty, boundary, and invalid cases
- Document results in TESTING_PLAN.md

### Integration Tests
All members participate:
- Test workflows crossing multiple modules
- Verify data consistency
- Member 5 coordinates integration testing sessions

### Test File Naming
- Use descriptive names: `test_escalation_stack.cpp`
- Include test owner in comments
- Date test files

### Running Tests
Add instructions here after implementation:
```bash
# Compile test suite
# Run all tests
# Run specific module tests
```

## Test Documentation
- Document all tests in `docs/TESTING_PLAN.md`
- Record actual results (not fabricated)
- Include screenshots for key tests
- Report goes in `Report/` directory

## Test Case Format

```cpp
// Test: <Test Name>
// Owner: Member X
// Date: YYYY-MM-DD
// Purpose: <What this tests>
// Input: <Test input>
// Expected: <Expected output>
// Actual: <Actual output - TBD>
// Result: PASS/FAIL - TBD
```

## Important
✅ Test during implementation, not after  
✅ Every member tests their module  
✅ Document real results, not guesses  
✅ Integration tests are shared responsibility  

See `docs/TESTING_PLAN.md` for complete testing strategy.
