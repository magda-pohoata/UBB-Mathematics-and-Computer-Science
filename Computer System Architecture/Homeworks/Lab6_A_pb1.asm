bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start

; declare external functions needed by our program
extern exit, printf,scanf,gets               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

import printf msvcrt.dll
import scanf msvcrt.dll
import gets msvcrt.dll


; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

    ;1. Read a number in base 16. Compute the product of number with a constant k. Print the result on the screen in hexadecimal and in decimal in ;next format: The number is ... The result of ... * k is ....

    decimalformat db '%d', 0
    hexaformat db '%x', 0

    k dd 2
    nr dd 0
    mesaj db 'The number is %x. The result of %x * k is %x in hexa and %d in decimal.', 0

; our code starts here
segment code use32 class=code
    start:
        ; ...

        mov eax,0
        mov ebx,0
        mov ecx,0
        mov edx,0

      ;citire k
        push dword nr
        push dword hexaformat
        call [scanf]
        add esp, 4*2


        mov eax,[nr]
        imul dword [k]   ;edx:eax= k * nr
        mov ebx,1
        idiv ebx   ;eax= k * nr    edx= 0



        push eax
        push eax
        push dword [nr]
        push dword [nr]

        push dword mesaj
        call [printf]
        add esp, 4*5

        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
