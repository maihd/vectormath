# Contributing guide for VectorMath project

## Add examples
- Example should be simple enough to explore the source code
- Should be generatable project with premake5, GENie is not required
- Add third party if needed


## Add API docs
- Simplicity is prefer
- Decribe what its does, purpose


## Add functions implementation
- Only theses features are accepted: NEON (or other simd intrinsics set), handedness, reverse z-order, turns
- The function API and implementation must be met the coding_standards.md requirement
- Add an explainment to docs/decision_making.md if the implementation, used features are hard to understand
- Please add unit tests


## Reporting and fixing bugs
- As minimum requirement, just open an issue
- Feel free to send a pull request
- Please add or update unit tests


## Reporting and fixing typo
- As minimum requirement, just open an issue
- Feel free to send a pull request