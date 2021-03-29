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

     

;1. Se da un sir de octeti S de lungime l. Sa se construiasca sirul D de lungime l-1 astfel incat elementele din D sa reprezinte produsul dintre fiecare 2 elemente consecutive S(i) si S(i+1) din S.  
;Exemplu: 

;S: 1, 2, 3, 4 
;D: 2, 6, 12 

    s db 1,2,3,4
    ls equ $-s-1
    d times ls dw 0
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        mov eax,0
        mov ebx,0
        mov ecx,ls
        
        mov esi,0
        mov edi,0
        
        repeta:
            mov al,[s+esi]
            mov bl,[s+esi+1]
            
            imul bl    ;ax=al*bl
            
            mov [d+edi],ax
            add edi,2
            inc esi
        loop repeta
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
