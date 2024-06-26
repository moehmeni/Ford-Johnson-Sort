# Ford-Johnson-Sort
Ford-Johnson (AKA) merge-insertion sort, designed to perform as few comparisons as possible to sort a collection.

## Usage
```
make
```
```
./PmergeMe 29 403 381 0 9
```

## Algorithm
1. **Pairing elements:** The algorithm first divides the array into pairs of elements.
2. **Selecting larger elements:** It then identifies the larger element within each pair.
3. **Sorting larger elements:** These larger elements are treated as a sub-array and sorted in ascending order.
4. **Inserting remaining elements:** Here's where the Jacobsthal sequence comes in. The Jacobsthal numbers determine the positions where the remaining elements (those not chosen as the larger elements in the pairs) are inserted into the sorted sub-array. The first remaining element is inserted at the beginning of the sorted sub-array.
Subsequent remaining elements are inserted at positions determined by the Jacobsthal sequence relative to the previously inserted elements. This ensures they are inserted in the correct sorted order.

<sub>This steps breakdown was generated by Google Gemini </sub>

**Note**: You can use other index checking serie other than Jacobsthal.
