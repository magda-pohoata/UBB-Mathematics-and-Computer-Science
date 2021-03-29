bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use 32 class=data
    a DW 1011011010100101b
    b DB 11010010b
    c DD 0
    
; our code starts here    
segment code use 32 class=code
    start:
    ;12. Given the word A and the byte B, compute the doubleword C:  
    ;the bits 0-3 of C have the value 1 
    ;the bits 4-7 of C are the same as the bits 0-3 of A 
    ;the bits 8-13 of C have the value 0 
    ;the bits 14-23 of C are the same as the bits 4-13 of A 
    ;the bits 24-29 of C are the same as the bits 2-7 of B 
    ;the bits 30-31 have the value 1 

    mov EAX, 0
    mov EBX, 0
    mov ECX, 0
    mov EDX, 0

    
    
    ;the bits 0-3 of C have the value 1 
    mov CL, 00001111b
    
    ;the bits 4-7 of C are the same as the bits 0-3 of A 
    mov AX, [a]
    and AX, 00001111b
    shl AX, 4
    or CX, AX
    
    ;the bits 8-13 of C have the value 0 
    ; :)
    
    ;the bits 14-23 of C are the same as the bits 4-13 of A 
    mov AX, [a]
    and AX, 0011111111110000b
    shl EAX, 10
    or ECX, EAX
    
    ;the bits 24-29 of C are the same as the bits 2-7 of B 
    mov BL, [b]
    and BL, 11111100b
    shl EBX, 22
    or ECX, EBX
    
    ;the bits 30-31 have the value 1 
    mov EBX, 0
    mov BL, 00000011b
    ror EBX, 2
    or ECX, EBX
    
    
    
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program