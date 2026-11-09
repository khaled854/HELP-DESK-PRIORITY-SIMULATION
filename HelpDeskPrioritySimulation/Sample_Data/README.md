# SAMPLE DATA DIRECTORY

## Purpose
Store sample test data for demonstrating and testing the Help-Desk Priority Simulation system.

## Contents

### 1. Sample Requests
Example service requests with varied priorities and statuses for testing.

### 2. Sample Agents
Example agent profiles with different specializations and availability.

### 3. Test Scenarios
Predefined sequences of operations for consistent testing.

## Usage

Sample data helps with:
- Consistent demonstration during presentation
- Reproducible test cases
- Quick system population for testing
- Training new team members

## File Formats

- Plain text (.txt)
- CSV (.csv) if structured
- Instructions for manual entry

## Example Data Sets

### Sample Requests (sample_requests.txt)
```
Request 1:
ID: 1001
Requester: John Smith
Issue: Cannot access email
Category: Email
Priority: HIGH
Description: User unable to login to email since morning

Request 2:
ID: 1002
Requester: Jane Doe
Issue: Printer not working
Category: Hardware
Priority: MEDIUM
Description: Office printer shows error code 43

[Add 8-10 more sample requests]
```

### Sample Agents (sample_agents.txt)
```
Agent 1:
ID: 101
Name: Alice Johnson
Specialization: Email Systems
Availability: AVAILABLE

Agent 2:
ID: 102
Name: Bob Williams
Specialization: Hardware
Availability: AVAILABLE

[Add 3-5 more sample agents]
```

### Test Scenario 1: Complete Workflow
```
1. Create 3 requests (1 HIGH, 1 MEDIUM, 1 LOW)
2. Add 2 agents
3. Assign next request (should assign HIGH first)
4. Escalate MEDIUM request to HIGH
5. Assign next request
6. Resolve first request
7. Generate sorted report
8. Display escalation history
```

### Test Scenario 2: Edge Cases
```
1. Try to pop from empty Stack
2. Try to dequeue from empty Queue
3. Try to create duplicate request ID
4. Try to assign with no available agents
5. Try to escalate non-existent request
```

## Creating Sample Data

When implementing, team members can add:
- Representative test data
- Edge case inputs
- Realistic help-desk scenarios
- Data for demonstration

## Important Notes

✅ Sample data is optional but helpful  
✅ Do not hardcode data into application  
✅ Data should be entered via menu or loaded dynamically  
✅ Include varied priorities, statuses, and categories  

Sample data accelerates testing and demonstration preparation.
