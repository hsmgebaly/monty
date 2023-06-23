++++++++++++++++++++++++++++++ ; Initialize the memory to 256 cells
[
    >>++ ; Read the first digit from stdin
    >   ; Move the pointer to the next cell
    >++ ; Read the second digit from stdin
    --  ; Decrement the pointer by 2

    ; Add the two digits
    [
        >+ ; Add the digits
        <- ; Subtract the carry
    ]

    ; Print the result
    .   ; Print the digit at the pointer
]
