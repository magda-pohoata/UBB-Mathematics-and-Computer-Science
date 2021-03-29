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

    
    
    ;15. Se dau 2 siruri de octeti S1 si S2 de aceeasi lungime. Sa se construiasca sirul D astfel incat fiecare element din D sa reprezinte minumul ;dintre elementele de pe pozitiile corespunzatoare din S1 si S2.  
;Exemplu: 

;S1: 1, 3, 6, 2, 3, 7 

;S2: 6, 3, 8, 1, 2, 5 

;D: 1, 3, 6, 1, 2, 5 

    s1 db 1h,3h,6h,2h,3h,7h
    ls1 equ $-s1
    s2 db 6h,3h,8h,1h,2h,5h
  
    d times ls1 db 0h

; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov eax,0
        mov ebx,0
        
        mov esi,0
        
        mov ecx,ls1
        
        repeta:
            mov al,[s1+esi]
            mov bl,[s2+esi]
            cmp al,bl
            JL inserta
            JGE insertb
            
        inserta:
            mov [d+esi],al
            inc esi
            jmp end_repeta
            
        insertb:
            mov [d+esi],bl
            inc esi
            
        end_repeta:
        loop repeta
        
        
    
    
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
