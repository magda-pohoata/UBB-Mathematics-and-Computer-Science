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
    c dw 6
    d db 2
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
    
    ;9. (-d+3-a+4) + c
    
        mov eax,0
        mov ebx,0
        mov ecx,0
        mov edx,0 
    
        mov bl,[d]
        mov bh,0   ;bx=d
        
        mov dx,3
        sub dx,bx   ;dx=dx-bx=-d+3
        
        mov ax,[a]  ;ax=a
        sub dx,ax  ;dx=dx-ax=-d+3-a
        
        add dx,4  ;dx=dx+4=-d+3-a+4
        
        mov cx,[c]  ;cx=c
        add dx,cx   ;dx=dx+cx=(-d+3-a+4)+c
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
