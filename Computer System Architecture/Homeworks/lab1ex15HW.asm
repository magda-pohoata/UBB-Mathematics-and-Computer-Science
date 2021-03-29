bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    
    a dw 1
    b db 1
    c dw 5
    d db 2

; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;15.(4-b-a)+5+c-d
        
        mov eax,0
        mov ebx,0
        mov ecx,0
        mov edx,0
        
        mov bx,4   ;bx=4
        mov cl,[b]
        mov ch,0   ;cx=b
        
        sub bx,cx   ;bx=bx-cx=4-b
        
        mov ax,[a]   ;ax=a
        
        sub bx,ax   ;bx=bx-ax=4-b-a
        
        add bx,5
        
        mov cx,[c]
        mov dl,[d]
        mov dh,0
        
        add bx,cx
        sub bx,dx
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
