procedure SelectionSort(A: array of n elements)
    for i = 0 to n-2 do
        minIndex = i
        for j = i+1 to n-1 do
            if A[j] < A[minIndex] then
                minIndex = j
        end for
        swap A[i] and A[minIndex]
    end for
end procedure
