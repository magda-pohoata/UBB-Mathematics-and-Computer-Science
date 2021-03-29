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

    
;1. Se da un sir de cuvinte s. Sa se construiasca sirul de octeti d, astfel incat d sa contina pentru fiecare pozitie din s: 

;- numarul de biti de 0, daca numarul este negativ 
;- numarul de biti de 1, daca numarul este pozitiv 

;Exemplu: 

;s: -22, 145, -48, 127 

;in binary:  
;1111111111101010, 10010001, 1111111111010000, 1111111 
;d: 3, 3, 5, 7 
    
    s dw -22,145,-48,127
    ls equ ($-s)/2
    d times ls db 0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
    
    
        mov eax,0
        mov ebx,0
        mov ecx,ls
        mov edx,0
        
        mov esi,0
        mov edi,0
        
        
        repeta:
            mov ax,word[s+esi]
            
            mov ebx,ecx   ;facem o copie a lui ecx
            
            mov ecx,16
            
            mov edx,0
            count:
                shl ax,1    ; shiftam ca sa numaram cati biti de 1 are 
                adc edx,0   ;adunare cu carry
            loop count
            
            mov ecx,ebx   ;readucem ecx la valoarea initiala
            mov ax,word[s+esi]
            cmp ax,0
            JL insert0
            JGE insert1
            
            insert0:
                mov ebx,16
                sub ebx,edx
                mov [d+edi],ebx
                jmp end_repeta
            
            insert1:
                mov [d+edi],edx
            
            end_repeta:
                inc edi
                add esi,2
        loop repeta
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
