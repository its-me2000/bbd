{\rtf1\ansi\ansicpg1251\deff0\deflang1049{\fonttbl{\f0\fnil\fcharset0 System;}}
\viewkind4\uc1\pard\b\f0\fs18 .code 0100h
\par .data 1000h
\par .stack 4000h
\par .org 01000h
\par mov cx,0020h
\par metka:
\par sti
\par xchg ax,ax
\par xchg ax,ax
\par xchg ax,ax
\par cli
\par loop metka
\par hlt
\par 
\par db 00024h 00h 00h 00h 02h
\par .org 02000h
\par inb 60h
\par mov si,[0000h]
\par push ds
\par mov bx,1000h
\par mov ds,bx
\par mov [si],al
\par pop ds
\par iret
\par 
\par 
\par }
 