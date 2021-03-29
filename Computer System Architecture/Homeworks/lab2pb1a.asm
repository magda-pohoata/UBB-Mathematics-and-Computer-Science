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
    
    a db -3
    b db 4
    c db -5
    d dw 2
    reza dd 0

; our code starts here
segment code use32 class=code
    start:
        ; ...
    
        ;1.a) ((a+b-c)*2 + d-5)*d       data types: a,b,c -byte, d -word
        
        mov eax,0
        mov ebx,0
        mov ecx,0
        mov edx,0
        
        mov al,[a]
        mov bl,[b]
        mov cl,[c]
        
        add al,bl  ;al=al+bl=a+b
        sub al,cl   ;al=al-cl=a+b-c
        
        mov bl,2
        
        imul bl   ;ax=al*bl=(a+b-c)*2
        
        mov dx,[d]
        
        add ax,dx  ; ax=ax+dx=(a+b-c)*2+d
        sub ax,5   ; ax=ax-5=(a+b-c)*2+d-5
        
        imul dx   ;ax:dx=ax*dx=((a+b-c)*2+d-5)*d
        
        push dx
        push ax
        pop eax
        
        
        mov [reza], eax
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
