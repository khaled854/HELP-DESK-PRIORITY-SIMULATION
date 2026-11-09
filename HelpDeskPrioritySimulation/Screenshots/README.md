# SCREENSHOTS DIRECTORY

## Purpose
Store execution screenshots for project report documentation.

## Required Screenshots

### 1. Menu and Navigation
- Main menu display
- Menu choice selection
- Invalid menu input handling

### 2. Request Operations
- Create new request workflow
- Search request by ID
- Display all requests
- Display waiting requests by priority

### 3. Assignment Workflow
- Assign next request to agent
- Agent availability before assignment
- Agent status after assignment
- Assignment with no available agents (error case)

### 4. Escalation
- Escalate request priority
- Display escalation history (LIFO order from Stack)
- Multiple escalations

### 5. Data Structure Demonstrations
- **Stack:** Push escalation, pop, display history
- **Queue:** Enqueue requests, dequeue by priority, FIFO verification
- **LinkedList:** Display agents, search agent, update availability
- **BST:** Search request, display inorder traversal (sorted)

### 6. Sorting
- Generate sorted report (Merge Sort output)
- Before and after sorting comparison

### 7. Edge Cases
- Pop from empty Stack
- Dequeue from empty Queue
- Search in empty BST
- Duplicate ID rejection
- Invalid input handling

### 8. Integration Scenarios
- Complete workflow: Create → Assign → Resolve
- Escalation affecting queue membership
- Cancellation removing from both BST and Queue

## Screenshot Guidelines

### Capture
- Use clear, readable console window
- Maximize font size if needed for readability
- Capture full relevant output (not partial)
- Show command and output together

### Annotation
- Add arrows or highlights to important parts
- Add captions explaining what is shown
- Number screenshots sequentially

### Naming Convention
```
[Category]-[Number]-[Description].png

Examples:
Menu-01-MainMenuDisplay.png
Request-02-CreateNewRequest.png
Stack-01-PushEscalation.png
Integration-01-CompleteWorkflow.png
EdgeCase-01-EmptyStackPop.png
```

### Format
- PNG or JPG format
- High enough resolution to read text
- Not too large (< 2MB per image ideal)

## Organization

```
Screenshots/
├── README.md             ← You are here
├── Menu/                ← Menu screenshots
├── Request/             ← Request operation screenshots
├── Assignment/          ← Assignment workflow screenshots
├── Escalation/          ← Escalation and stack screenshots
├── DataStructures/      ← Individual structure demos
├── Sorting/             ← Merge sort output
├── EdgeCases/           ← Error handling screenshots
└── Integration/         ← End-to-end workflow screenshots
```

## Usage in Report

Screenshots will be embedded in Project Report Section 6 (Implementation) and Section 7 (Testing).

### Best Practices
- Select most informative screenshots (quality > quantity)
- Each screenshot should show something meaningful
- Caption every screenshot in report
- Reference screenshots in text: "Figure 3 shows..."

## Number of Screenshots

Recommended: 15-25 total screenshots covering:
- 3-4 menu/navigation
- 3-4 request operations
- 2-3 assignment
- 2-3 escalation
- 4-5 data structure operations
- 2-3 sorting
- 3-4 edge cases
- 2-3 integration workflows

## Taking Screenshots

### Windows
- Print Screen key (full screen)
- Alt + Print Screen (active window)
- Snipping Tool or Snip & Sketch
- Windows + Shift + S (screen region)

### macOS
- Cmd + Shift + 3 (full screen)
- Cmd + Shift + 4 (region)

### Linux
- Print Screen key
- gnome-screenshot
- Flameshot (recommended)

## Important

✅ Screenshots must show REAL execution, not mockups  
✅ Annotate to clarify what is being demonstrated  
✅ Use consistent naming convention  
✅ Store originals here, embed in report  

Screenshots are evidence of working implementation. Do not fabricate.
