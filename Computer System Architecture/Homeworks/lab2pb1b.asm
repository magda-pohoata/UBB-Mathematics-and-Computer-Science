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
    b dd 4
    c dq -5
    rezb dq 0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;1.b)  c+(a*a-b+7)/(2+a),     a-byte; b-doubleword; c-qword
        
        mov eax,0
        mov ebx,0
        mov ecx,0
        
        mov al,[a]
        
        imul byte[a]   ;ax=a*a
        
        mov ebx,[b]    ;ebx=b
        
        cwde     ;eax=a*a
        
        sub eax,ebx  ;eax=a*a-b 
        add eax,7
        
        mov ecx,eax  ;ecx=eax
        
        mov eax,0
        mov al,[a]
        add al,2    ;al=a+2
        
        cbw
        mov bx,ax
        
        mov eax,ecx
        
        push eax
        pop ax
        pop dx        ;dx:ax=a*a-b+7
        
        idiv bx      ;ax= (a*a-b+7)/(a+2)
        
        mov edx,0    ;curatam edx
        
        cwde    ;eax=ax
        cdq     ;edx:eax=ax
        clc
        add eax,dword[c+0]
        adc edx,dword[c+4]
        
        mov dword[rezb+0],eax
        mov dword[rezb+4],edx
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
