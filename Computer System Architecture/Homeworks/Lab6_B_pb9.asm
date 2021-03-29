bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, scanf, gets,getchar              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
import gets msvcrt.dll
import getchar msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    
    
    
    ;9. Read a string and read one character S. Replace all occurrences of each small letters with S. Print on screen the resulted string. 
    ;  Ex:  s = Ana Are 7 Mere, c=S => d = ASSASS7MSSS 
    
    
    s resb 20
    char dd 0
    d resb 20
    strformat db '%s',0
    charformat db '%c',0
    newline db 10,0

; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        push dword s
        call [gets]
        add esp, 4*1
        
        
        push dword char
        push dword charformat
        call [scanf]
        add esp, 4*2
        
        call [getchar]
        
        
        push dword newline
        call [printf]
        add esp, 4*1
        
        
        mov eax, 0
        mov ebx, 0
        mov ecx, 0
        mov edx, 0
        mov esi, 0
        
        mov ecx, 20
        
        
        littleloop:
            mov al, [s+esi]
            cmp al, 'a'
            jge greater_or_equal_a
            jl not_small
            
            greater_or_equal_a:
                cmp al, 'z'
                jle small_letter
                jg not_small
            
            small_letter:
                mov ah, byte[char]
                mov [d+esi], ah
                add esi, 1
                jmp endl
            
            not_small:
                mov [d+esi], al
                add esi, 1
                jmp endl
                
            endl:
        
        loop littleloop
        
        push dword d
        push dword strformat
        
        call[printf]
        add esp, 4*2
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
