{\rtf1\ansi\ansicpg1251\deff0\deflang1049{\fonttbl{\f0\fnil\fcharset0 System;}}
\viewkind4\uc1\pard\b\f0\fs18 .data 1000h
\par .code 0100h
\par 
\par 
\par db 11000h 20h 31h 32h 33h 34h 35h 36h 37h 38h 39h 30h 2dh 3dh 20h 20h 51h
\par db 11010h 57h 45h 52h 54h 59h 55h 49h 4fh 50h 5bh 5dh 20h 20h 41h 53h 44h
\par db 11020h 46h 47h 48h 4ah 4bh 4ch 3bh 60h 27h 20h 5ch 5ah 58h 43h 56h 42h
\par db 11030h 4eh 4dh 2ch 2eh 2fh 20h 20h 20h 20h  20h  20h  20h 20h 20h 20h 20h
\par db 11040h 20h 20h 20h 20h 20h 20h 20h 20h 20h 29h  20h 20h 20h 2bh 20h 20h
\par db 11050h 20h 20h 20h
\par 
\par db 00024h 00h 01h 00h 01h
\par 
\par .org 01000h
\par mov bx,0FFFh
\par zyme:
\par sti
\par xchg ax,ax
\par xchg ax, ax
\par xchg ax,ax
\par cli
\par jmp zyme
\par 
\par .org 01100h
\par inb 60h
\par xlat
\par mov [si],al
\par incw si
\par iret
\par }
 