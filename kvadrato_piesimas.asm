{\rtf1\ansi\ansicpg1251\deff0\deflang1049{\fonttbl{\f0\fnil\fcharset0 System;}}
\viewkind4\uc1\pard\b\f0\fs18 .stack 0100h
\par .data 1000h
\par 
\par mov al,10h         ; x1
\par mov ah, 12h       ; y1
\par mov bl, 30h        ; x2
\par mov bh,3fh         ; y2
\par 
\par 
\par push bx              ; issaugojame parametrus steke
\par push ax
\par 
\par mov cl, bl
\par sub cl, al               ; apskaiciuojame krastines ilgi
\par push cx
\par mov bh,00h
\par mov bl, ah              ; perkeliame y1 reiksme i bl registra
\par mov ax, 0140h    ; i ax ikeliame daugikli
\par mulw bx                ; apskaiciuojame atminties adresa kuriame prasideda y1 eilute
\par pop dx
\par pop bx
\par push bx                    ; i bx irasome x1 reiksme
\par mov bh, 00h
\par add ax,bx             ; apskaiciuojame virsunes adresa
\par mov si, ax            ; isaugome virsunes reiksme i si registra
\par 
\par zyme1:
\par mov [si],FFh
\par incw si
\par loop zyme1
\par 
\par pop bx
\par pop cx
\par push cx
\par push bx
\par 
\par mov cl, ch
\par mov ch,00h
\par sub cl,bh
\par mov dh, cl
\par 
\par zyme2:
\par mov [si],FFh
\par add si, 0140h
\par loop zyme2
\par 
\par mov cl,dl
\par 
\par zyme3:
\par mov [si],FFh
\par decw si
\par loop zyme3
\par 
\par mov cl,dh
\par 
\par zyme4:
\par mov [si],FFh
\par sub si, 0140h
\par loop zyme4
\par 
\par hlt
\par 
\par }
 