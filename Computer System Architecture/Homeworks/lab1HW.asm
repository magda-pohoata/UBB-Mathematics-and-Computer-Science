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
    b db 5
    c dw 6
    d db 3
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
    ;7. (3+b-a)-5+c-d
    
        mov eax,0
        mov ebx,0
        mov ecx,0
        mov edx,0 
        
        mov bl,[b]
        add bl,3
        mov bh,0  ; bx=3+b
        
        mov ax,[a]
        sub bx,ax  ; bx=3+b-a
        
        sub bx,5  ;bx=(3+b-a)-5
        
        mov cx,[c]
        mov dl,[d]
        mov dh,0  ;dx=d
        
        sub cx,dx ;cx=c-d
        
        add bx,cx
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
