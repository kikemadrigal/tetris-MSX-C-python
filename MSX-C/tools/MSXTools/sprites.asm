		 output sprites.bin
	db   #fe
	dw   INICIO 
	dw   FINAL
	dw   INICIO 
	org  #d000 
INICIO: 
; Setup video mode
	ld a,5
	call #005F ; CHGMOD equ #005F, change mode video to screen 5
; Setup sprite size
; Sprites no ampliados de 16x16
	ld b,#e2
	ld c,1
	call #0047;WRTVDP equ #0047, b data to write, c number register, escribe en los registros del VDP
	ld hl, sprites_definition
	ld de, 30720 ;&h7800, base(29) en sc5
	ld bc, 32*8
	call  #005C; #005C=LDIRVM 
	ld hl, sprites_colors
	ld de, 29696 ;&h7400, en sc5
	ld bc, 16*8
	call  #005C; #005C=LDIRVM 
	ld hl, sprites_atributes
	ld de, 30208 ;&h7600, base(28) en sc5
	ld bc, 4*8
	call  #005C; #005C=LDIRVM 
.bucle: 
	jr .bucle
sprites_definition:
;Definition sprite 0, name: Sprite-7
	db 0,0,0,0,0,0,0,0
	db 0,0,0,0,0,0,0,0
	db 0,0,0,0,0,0,0,0
	db 0,0,0,0,0,0,0,0
;Definition sprite 1, name: Sprite-0
	db 0,0,0,0,240,144,176,176
	db 240,144,176,176,255,153,187,255
	db 0,0,0,0,0,0,0,0
	db 0,0,0,0,0,0,0,0
;Definition sprite 2, name: Sprite-1
	db 0,0,0,0,0,0,0,0
	db 0,0,0,0,0,0,0,0
	db 0,0,0,0,15,9,13,15
	db 15,9,13,15,255,153,221,255
;Definition sprite 3, name: Sprite-2
	db 0,0,0,0,0,0,0,0
	db 15,9,13,15,0,0,0,0
	db 0,0,0,0,0,0,0,0
	db 240,144,208,240,255,153,221,255
;Definition sprite 4, name: Sprite-2
	db 0,0,0,0,0,0,0,0
	db 15,9,13,15,255,153,221,255
	db 0,0,0,0,0,0,0,0
	db 240,144,208,240,0,0,0,0
;Definition sprite 5, name: Sprite-4
	db 0,0,0,0,0,0,0,0
	db 3,2,3,3,63,38,55,63
	db 0,0,0,0,0,0,0,0
	db 192,64,64,192,252,100,116,252
;Definition sprite 6, name: Sprite-4
	db 0,0,0,0,0,0,0,0
	db 15,9,13,15,15,9,13,15
	db 0,0,0,0,0,0,0,0
	db 240,144,208,240,240,144,208,240
;Definition sprite 7, name: Sprite-4
	db 3,2,3,3,3,2,3,3
	db 3,2,3,3,3,2,3,3
	db 192,64,64,192,192,64,64,192
	db 192,64,64,192,192,64,64,192
sprites_colors: 
;Data colors sprite 0, name: Sprite-7
	db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
;Data colors sprite 1, name: Sprite-0
	db 0,0,0,0,9,9,9,9,9,9,9,9,9,9,9,9
;Data colors sprite 2, name: Sprite-1
	db 0,0,0,0,7,7,7,7,7,7,7,7,7,7,7,7
;Data colors sprite 3, name: Sprite-2
	db 0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8
;Data colors sprite 4, name: Sprite-2
	db 0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3
;Data colors sprite 5, name: Sprite-4
	db 0,0,0,0,0,0,0,0,13,13,13,13,13,13,13,13
;Data colors sprite 6, name: Sprite-4
	db 0,0,0,0,0,0,0,0,10,10,10,10,10,10,10,10
;Data colors sprite 7, name: Sprite-4
	db 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5
sprites_atributes: 
;Data atributes sprite (y,x,patron,color) 0, name: Sprite-7
	db 0,0,0, " "
;Data atributes sprite (y,x,patron,color) 1, name: Sprite-0
	db 0,33,4, " "
;Data atributes sprite (y,x,patron,color) 2, name: Sprite-1
	db 0,66,8, " "
;Data atributes sprite (y,x,patron,color) 3, name: Sprite-2
	db 0,99,12, " "
;Data atributes sprite (y,x,patron,color) 4, name: Sprite-2
	db 0,132,16, " "
;Data atributes sprite (y,x,patron,color) 5, name: Sprite-4
	db 0,165,20, " "
;Data atributes sprite (y,x,patron,color) 6, name: Sprite-4
	db 0,198,24, " "
;Data atributes sprite (y,x,patron,color) 7, name: Sprite-4
	db 0,231,28, " "
FINAL: 
