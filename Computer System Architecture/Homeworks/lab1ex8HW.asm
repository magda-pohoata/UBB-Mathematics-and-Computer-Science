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

    a dw 4
    b db 1
    c dw 6
    d db 3
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
    
    ;8. a-b+7-(c+d)
    
        mov eax,0
        mov ebx,0
        mov ecx,0
        mov edx,0 
        
        mov ax,[a]  ;ax=a
        mov bl,[b]
        mov bh,0   ;bx=x
        
        sub ax,bx   ;ax=ax-bx=a-b
        
        add ax,7   ;ax=a-b+7
        
        mov cx,[c]   ;cx=c
        mov dl,[d]
        mov dh,0   ;dx=d
        
        add cx,dx   ;cx=cx+dx=c+d
        
        sub ax,cx   ; ax=ax-cx=a-b+7-(c+d)
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
