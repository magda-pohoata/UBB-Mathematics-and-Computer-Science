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

    
    
    ;2. Se da un sir de dublucuvinte. Sa se obtina sirul format din octetii superiori ai  
;cuvitelor superioare din elementele sirului de dublucuvinte care sunt divizibili cu 3. 

;Exemplu: 

;Se da sirul de dublucuvinte:  
;s DD 12345678h, 1A2B3C4Dh, FE98DC76h 

;Sa se obtina sirul  
;d DB 12h. 
    
    s DD 12345678h, 1A2B3C4Dh, 0FE98DC76h
    ls equ ($-s)/4
    d times ls db 0
    
    
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
            mov ebx,3
            mov eax,dword[s+esi]
            
            cdq
            idiv ebx   ;eax=edx:eax/ebx   edx=restul
            
            cmp edx,0
            jg eticheta
            je insert
            
            insert:
                mov eax,dword[s+esi]
                shr eax,24   ;shifteaza octetii superiori ai wordurilor superioare pana in al
                mov [d+edi],eax
                inc edi
                                   ;nu facem add la esi aici si nici nu punem jmp pentru ca intra automat pe eticheta, unde facem add
            eticheta:
                add esi,4
            
            loop repeta
            
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
