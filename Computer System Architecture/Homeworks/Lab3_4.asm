bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a DB 10101011b
    b DB 01001010b
    c DW 0

; our code starts here
segment code use32 class=code
    start:
    ;4. Given the bytes A and B, Compute the doubleword C as follows:  
    ;the bits 8-15 of C have the value 0 
    ;the bits 16-23 of C are the same as the bits of B 
    ;the bits 24-31 of C are the same as the bits of A 
    ;the bits 0-7 of C have the value 1 
    
    mov EAX, 0
    mov EBX, 0
    mov ECX, 0
    mov EDX, 0
    
    
    
    ;the bits 8-15 of C have the value 0 
    ; :)
    
    ;the bits 0-7 of C have the value 1
    mov CL, 11111111b
    
    ;the bits 24-31 of C are the same as the bits of A 
    mov AL, [a]
    ror EAX, 8
    or ECX, EAX
    
    ;the bits 16-23 of C are the same as the bits of B
    mov BL, [b]
    shl EBX, 16
    or ECX, EBX
    
    
    
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
