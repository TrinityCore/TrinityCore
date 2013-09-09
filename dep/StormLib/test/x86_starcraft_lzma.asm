;
;  LZMA compression code ripped from Starctaft II BEta
;  Used while StormLib's LZMA implementation was tested against Starcraft compression
;  Not used in StormLib.
;

.686P
.MODEL FLAT
ASSUME FS: NOTHING

.DATA

;---------------------------------------------------------------------------
; Data

byte_4CB248     db      0,   0Bh,   0Bh,   0Bh ; indirect table for switch statement
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db      1,     2,     3,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db      4,     5,     6,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db      7,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db      8,     9,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Bh,   0Bh,   0Bh,   0Bh
                db    0Ah
                align 10h

dword_544960    dd 0BB40E64Eh           ; DATA XREF: sub_401C72+B
dword_553598    dd ?                    ; DATA XREF: sub_4CB8A0+9

off_50CD3C      dd offset sub_4A0605    ; DATA XREF: sub_4A05F7+1o
                                        ; .data:off_52A004o ...
dword_50CD40    dd 0E06D7363h           ; DATA XREF: _CxxThrowException(x,x)+Eo
                dd 1
                dd 0
                dd 0
                dd 3
                dd 19930520h
                dd 0
                dd 0

; ---------------------------------------------------------------------------

off_546E20      dd offset sub_4CDD70    ; DATA XREF: sub_4D0270:loc_4D0324o
off_546E24      dd offset sub_4CDD90    ; DATA XREF: sub_4CF810+53r
off_546E28      dd offset off_50CD3C    ; DATA XREF: .rdata:off_51B888o
                dd 0
                db '.?AUISequentialInStream@@',0
                db 0
                db    0
off_546E4C      dd offset off_50CD3C    ; DATA XREF: .rdata:off_51B8C0o
                dd 0
                db '.?AUISequentialOutStream@@',0
                db    0
off_546E70      dd offset off_50CD3C    ; DATA XREF: .rdata:off_51B8F8o
                dd 0
                db '.?AUICompressCoder@@',0
                db    0
                db    0
                db    0
off_546E90      dd offset off_50CD3C    ; DATA XREF: .rdata:off_51B944o
                dd 0
                db '.?AUICompressSetOutStream@@',0
off_546EB4      dd offset off_50CD3C    ; DATA XREF: .rdata:0051B96Co
                dd 0
                db '.?AUICompressSetCoderProperties@@',0
                db    0
                db    0
off_546EE0      dd offset off_50CD3C    ; DATA XREF: .rdata:0051B9B8o
                dd 0
                db '.?AUICompressWriteCoderProperties@@',0
                dd offset off_50CD3C
                dd 0
                db '.?AUCSystemException@@',0
                db 0
                dd offset off_50CD3C
                dd 0
                db '.?AUCOutBufferException@@',0
                db    0
                db    0
off_546F50      dd offset off_50CD3C    ; DATA XREF: .rdata:0051BA04o
                dd 0
                db '.?AVCInStreamMemory@@',0
                db    0
                db    0
off_546F70      dd offset off_50CD3C    ; DATA XREF: .rdata:off_51BA4Co
                dd 0
                db '.?AVCMyUnknownImp@@',0
off_546F8C      dd offset off_50CD3C    ; DATA XREF: .rdata:0051BAA8o
                dd 0
                db '.?AVCOutStreamMemory@@',0
                db    0
off_546FAC      dd offset off_50CD3C    ; DATA XREF: .rdata:0051BAFCo
                dd 0
                db '.?AVCEncoder@NLZMA@NCompress@@',0
                db    0
off_546FD4      dd offset off_50CD3C    ; DATA XREF: .rdata:off_51BBECo
                dd 0
                db '.?AVCBaseState@NLZMA@NCompress@@',0
                db    0
                db    0
                db    0

; ---------------------------------------------------------------------------

dword_51B960    dd 0                    ; DATA XREF: .rdata:00517A64o
                dd 0
                dd 0
                dd offset off_546EB4
                dd 0    ; offset dword_51B974

dword_51B9AC    dd 0                    ; DATA XREF: .rdata:00517A78o
                dd 0
                dd 0
                dd offset off_546EE0
                dd 0    ;offset dword_51B9C0

dword_51B9F8    dd 0                    ; DATA XREF: .rdata:00517A8Co
                dd 0
                dd 0
                dd offset off_546F50
                dd 0    ; offset dword_51BA0C

dword_51BA9C    dd 0                    ; DATA XREF: .rdata:00517AA0o
                dd 0
                dd 0
                dd offset off_546F8C
                dd 0    ; offset dword_51BAB0

dword_51BAF0    dd 0                    ; DATA XREF: .rdata:00517AF8o
                dd 0
                dd 0
                dd offset off_546FAC
                dd 0    ; offset dword_51BB04

dword_51BC58    dd 0                    ; DATA XREF: .rdata:00517AE0o
                dd 4
                dd 0
                dd offset off_546FAC
                dd 0    ; offset dword_51BB04

dword_51BC6C    dd 0                    ; DATA XREF: .rdata:00517ACCo
                dd 8
                dd 0
                dd offset off_546FAC
                dd 0    ; offset dword_51BB04

dword_51BC80    dd 0                    ; DATA XREF: .rdata:00517AB8o
                dd 0Ch
                dd 0
                dd offset off_546FAC
                dd 0    ; offset dword_51BB04

; ---------------------------------------------------------------------------

dword_512730    dd 0                    ; DATA XREF: sub_48DB4D+B9o
dword_512734    dd 0                    ; DATA XREF: CCmdTarget::GetInterface(void const *)+2Dr
dword_512738    dd 0C0h                 ; DATA XREF: CCmdTarget::GetInterface(void const *)+38r
dword_51273C    dd 46000000h            ; DATA XREF: CCmdTarget::GetInterface(void const *)+43r

dword_5535A0    dd ?                    ; DATA XREF: sub_4CF900:loc_4CF94Co
dword_5535A4    dd ?                    ; DATA XREF: .text:004DAF37w
dword_5535A8    dd ?                    ; DATA XREF: .text:004DAF3Cw
dword_5535AC    dd ?                    ; DATA XREF: .text:004DAF41w

dword_5535B0    dd ?                    ; DATA XREF: sub_4CF900+5Eo
dword_5535B4    dd ?                    ; DATA XREF: .text:004DAF17w
dword_5535B8    dd ?                    ; DATA XREF: .text:004DAF1Cw
dword_5535BC    dd ?                    ; DATA XREF: .text:004DAF21w

dword_5535C0    dd ?                    ; DATA XREF: sub_4CF900:loc_4CF98Fo
dword_5535C4    dd ?                    ; DATA XREF: .text:004DAEF7w
dword_5535C8    dd ?                    ; DATA XREF: .text:004DAEFCw
dword_5535CC    dd ?                    ; DATA XREF: .text:004DAF01w


dword_526DD0    dd 0                    ; DATA XREF: .text:loc_4CF6CBo
                dd 0
                dd 0
                dd 0    ; offset dword_526DE0

kLiteralNextStates db 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 4, 5
kMatchNextStates db 7, 7, 7, 7, 7, 7, 7, 0Ah, 0Ah, 0Ah, 0Ah, 0Ah
kRepNextStates  db 8, 8, 8, 8, 8, 8, 8, 0Bh, 0Bh, 0Bh, 0Bh, 0Bh
kShortRepNextStates db 9, 9, 9, 9, 9, 9, 9, 0Bh, 0Bh, 0Bh, 0Bh, 0Bh

dword_550998    dd 200h dup(?)
dword_551198    dd 800h dup(?)
dword_553198    dd 100h dup(?)

ICompressSetOutStream_vftable      dd offset __purecall    ; DATA XREF: NCompress_NLZMA_CEncoder_CEncoder+2o
                dd offset __purecall
                dd offset __purecall
                dd offset __purecall
                dd offset __purecall
                dd offset dword_51B960
ICompressSetCoderProperties_vftable   dd offset __purecall    ; DATA XREF: NCompress_NLZMA_CEncoder_CEncoder+9o
                dd offset __purecall
                dd offset __purecall
                dd offset __purecall
                dd offset dword_51B9AC
ICompressWriteCoderProperties_vftable      dd offset __purecall    ; DATA XREF: NCompress_NLZMA_CEncoder_CEncoder+10o
                dd offset __purecall
                dd offset __purecall
                dd offset __purecall
                dd offset dword_51B9F8
off_517A90      dd offset Interface1_QueryInterface
                dd offset Interface1_AddRef
                dd offset Interface1_Release
                dd offset sub_4CCB20
                dd offset dword_51BA9C
off_517AA4      dd offset Interface1_QueryInterface ; DATA XREF: sub_4CF610+Eo
                dd offset Interface1_AddRef
                dd offset Interface2_Release
                dd offset sub_4CCB90
                dd offset sub_4CF590
                dd offset dword_51BC80
NCompress_NLZMA_CEncoder_vftable_ICompressWriteCoderProperties      dd offset sub_4CFA50    ; DATA XREF: sub_4CF810+3Do
                dd offset sub_4CFA10
                dd offset sub_4CFA70
                dd offset sub_4CDDB0
                dd offset dword_51BC6C
NCompress_NLZMA_CEncoder_vftable_ICompressSetCoderProperties      dd offset ICompressSetCoderProperties_QueryInterface    ; DATA XREF: sub_4CF810+36o
                dd offset ICompressSetCoderProperties_AddRef
                dd offset ICompressSetCoderProperties_Release
                dd offset ICompressSetCoderProperties_SetCoderProperties
                dd offset dword_51BC58
NCompress_NLZMA_CEncoder_vftable_ICompressSetOutStream      dd offset sub_4CFA20    ; DATA XREF: sub_4CF810+2Fo
                dd offset sub_4CFA80
                dd offset sub_4CFA40
                dd offset sub_4CFA90
                dd offset sub_4CDE70
                dd offset dword_51BAF0
NCompress_NLZMA_CEncoder_vftable      dd offset sub_4CF900    ; DATA XREF: sub_4CF810+29o
                dd offset sub_4CF9D0
                dd offset sub_4CF9E0
                dd offset CEncoder_Code
                dd offset sub_4D0250

.CODE

extrn _operator_new:PROC
extrn __allshr: PROC
extrn _free: PROC
extrn _memcmp: PROC
extrn _memcpy: PROC
extrn _memset: PROC
extrn ___report_gsfailure: PROC
extrn __purecall: PROC
VirtualAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
VirtualFree PROTO STDCALL :DWORD,:DWORD,:DWORD

; ---------------------------------------------------------------------------

; void __cdecl j__free(void *Memory)
; 004843B8
j__free         proc near               ; CODE XREF: sub_401048+16p
                                        ; .text:004010CFp ...
                jmp     _free
j__free         endp


; ---------------------------------------------------------------------------

; int __cdecl unknown_libname_324(void *Buf1, void *Buf2)
unknown_libname_324 proc near
; sub_48B7BA

Buf1            = dword ptr  4
Buf2            = dword ptr  8

                push    10h             ; Size
                push    [esp+4+Buf2]    ; Buf2
                push    [esp+8+Buf1]    ; Buf1
                call    _memcmp
                add     esp, 0Ch
                neg     eax
                sbb     eax, eax
                inc     eax
                retn
unknown_libname_324 endp

; ---------------------------------------------------------------------------

sub_4A05F7      proc near               ; CODE XREF: sub_4A0605+3p
                push    ecx
                mov     dword ptr [ecx], offset off_50CD3C
                call    sub_4A98B8
                pop     ecx
                retn
sub_4A05F7      endp

; ---------------------------------------------------------------------------

; int __thiscall sub_4A0605(void *Memory, char)
sub_4A0605      proc near               ; DATA XREF: .rdata:off_50CD3Co

arg_0           = byte ptr  4

                push    esi
                mov     esi, ecx
                call    sub_4A05F7
                test    [esp+4+arg_0], 1
                jz      short loc_4A061B
                push    esi             ; Memory
                call    j__free
                pop     ecx

loc_4A061B:                             ; CODE XREF: sub_4A0605+Dj
                mov     eax, esi
                pop     esi
                retn    4
sub_4A0605      endp

; ---------------------------------------------------------------------------

sub_4A0686      proc near               ; CODE XREF: sub_401C72+49p
                                        ; sub_40222F+15Cp ...
                cmp     ecx, dword_544960
                jnz     short loc_4A0690
                retn
loc_4A0690:                             ; CODE XREF: sub_4A0686+6j
                jmp     ___report_gsfailure
sub_4A0686      endp

; ---------------------------------------------------------------------------

sub_4A98B8      proc near               ; CODE XREF: sub_4A05F7+7p

                int     3
                retn
sub_4A98B8      endp

; =============== S U B R O U T I N E =======================================


sub_4CAEC0      proc near               ; CODE XREF: CEncoder_GetOptimum+514p

arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch

                push    esi
                push    edi
                mov     edi, [esp+8+arg_4]
                lea     eax, [edi-2]
                cmp     eax, 4
                mov     esi, ecx
                jb      short loc_4CAED5
                mov     eax, 3

loc_4CAED5:                             ; CODE XREF: sub_4CAEC0+Ej
                mov     edx, [esp+8+arg_0]
                cmp     edx, 80h
                jnb     short loc_4CAEEF
                shl     eax, 7
                add     eax, edx
                mov     ecx, [esi+eax*4+33314h]
                jmp     short loc_4CAF25
; ---------------------------------------------------------------------------

loc_4CAEEF:                             ; CODE XREF: sub_4CAEC0+1Fj
                mov     ecx, 7FFFFh
                sub     ecx, edx
                sar     ecx, 1Fh
                push    ebx
                and     ecx, 0Ch
                add     ecx, 6
                mov     ebx, edx
                shr     ebx, cl
                shl     eax, 5
                add     eax, ecx
                and     edx, 0Fh
                movzx   ebx, byte ptr dword_551198[ebx]
                lea     eax, [ebx+eax*2]
                mov     ecx, [esi+eax*4+32F14h]
                add     ecx, [esi+edx*4+33B14h]
                pop     ebx

loc_4CAF25:                             ; CODE XREF: sub_4CAEC0+2Dj
                mov     edx, [esp+8+arg_8]
                imul    edx, 110h
                add     edx, edi
                mov     eax, [esi+edx*4+295B8h]
                pop     edi
                add     eax, ecx
                pop     esi
                retn    0Ch
sub_4CAEC0      endp

; ---------------------------------------------------------------------------
                align 10h

loc_4CAF40:                             ; CODE XREF: .text:004DAED5j
                push    ecx
                push    ebx
                push    ebp
                push    esi
                mov     ebp, 2
                mov     bl, 2
                push    edi
                mov     byte ptr dword_551198, 0
                mov     byte ptr dword_551198+1, 1
                mov     [esp+10h], bl
                mov     edi, ebp

loc_4CAF60:                             ; CODE XREF: .text:004CAF96j
                mov     ecx, edi
                shr     ecx, 1
                sub     ecx, 1
                mov     esi, 1
                shl     esi, cl
                test    esi, esi
                jbe     short loc_4CAF89
                mov     ecx, [esp+10h]
                push    esi
                lea     eax, dword_551198[ebp]
                push    ecx
                push    eax
                call    _memset
                add     esp, 0Ch
                add     ebp, esi

loc_4CAF89:                             ; CODE XREF: .text:004CAF70j
                add     bl, 1
                add     edi, 1
                cmp     bl, 1Ah
                mov     [esp+10h], bl
                jb      short loc_4CAF60
                pop     edi
                pop     esi
                pop     ebp
                pop     ebx
                pop     ecx
                retn
; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CAFA0      proc near               ; CODE XREF: sub_4CAFC0+90p

arg_0           = dword ptr  4

                mov     eax, [esp+arg_0]
                lea     ecx, [eax-61h]
                cmp     cx, 19h
                ja      short locret_4CAFB2
                add     eax, 0FFE0h

locret_4CAFB2:                          ; CODE XREF: sub_4CAFA0+Bj
                retn
sub_4CAFA0      endp

; ---------------------------------------------------------------------------
                align 10h

; =============== S U B R O U T I N E =======================================

sub_4CAFC0      proc near               ; CODE XREF: ICompressSetCoderProperties_SetCoderProperties+A5p
                movzx   ecx, word ptr [eax]
                lea     edx, [ecx-61h]
                cmp     dx, 19h
                ja      short loc_4CAFD2
                add     ecx, 0FFE0h

loc_4CAFD2:                             ; CODE XREF: sub_4CAFC0+Aj
                add     eax, 2
                cmp     cx, 48h
                jnz     short loc_4CB01B
                movzx   ecx, word ptr [eax]
                lea     edx, [ecx-61h]
                cmp     dx, 19h
                ja      short loc_4CAFED
                add     ecx, 0FFE0h

loc_4CAFED:                             ; CODE XREF: sub_4CAFC0+25j
                add     eax, 2
                cmp     cx, 43h
                jz      short loc_4CAFF9

loc_4CAFF6:                             ; CODE XREF: sub_4CAFC0+44j
                                        ; sub_4CAFC0+4Bj ...
                xor     eax, eax
                retn
; ---------------------------------------------------------------------------

loc_4CAFF9:                             ; CODE XREF: sub_4CAFC0+34j
                movzx   ecx, word ptr [eax]
                sub     ecx, 30h
                lea     edx, [ecx-4]
                test    edx, edx
                ja      short loc_4CAFF6
                cmp     word ptr [eax+2], 0
                jnz     short loc_4CAFF6
                mov     dword ptr [ebx], 0
                mov     [edi], ecx
                mov     eax, 1
                retn
; ---------------------------------------------------------------------------

loc_4CB01B:                             ; CODE XREF: sub_4CAFC0+19j
                cmp     cx, 42h
                jnz     short loc_4CAFF6
                movzx   ecx, word ptr [eax]
                lea     edx, [ecx-61h]
                cmp     dx, 19h
                ja      short loc_4CB033
                add     ecx, 0FFE0h

loc_4CB033:                             ; CODE XREF: sub_4CAFC0+6Bj
                add     eax, 2
                cmp     cx, 54h
                jnz     short loc_4CAFF6
                push    esi
                movzx   esi, word ptr [eax]
                sub     esi, 30h
                lea     ecx, [esi-2]
                cmp     ecx, 2
                ja      short loc_4CB06C
                movzx   eax, word ptr [eax+2]
                push    eax
                call    sub_4CAFA0
                add     esp, 4
                test    ax, ax
                jnz     short loc_4CB06C
                mov     dword ptr [ebx], 1
                mov     [edi], esi
                mov     eax, 1
                pop     esi
                retn
; ---------------------------------------------------------------------------

loc_4CB06C:                             ; CODE XREF: sub_4CAFC0+89j
                                        ; sub_4CAFC0+9Bj
                xor     eax, eax
                pop     esi
                retn
sub_4CAFC0      endp


ICompressSetCoderProperties_SetCoderProperties      proc near               ; DATA XREF: .rdata:00517ADCo

var_4           = dword ptr -4
pThis           = dword ptr  4
propIDs         = dword ptr  8
properties      = dword ptr  0Ch
numProperties   = dword ptr  10h

                push    ecx
                push    ebx
                push    ebp
                xor     edx, edx
                cmp     [esp+0Ch+numProperties], edx
                push    esi
                push    edi
                mov     [esp+14h+var_4], edx
                jbe     loc_4CB20D
                mov     esi, [esp+14h+properties]
                mov     ebp, [esp+14h+pThis]
                lea     ecx, [ecx+0]

loc_4CB090:                             ; CODE XREF: sub_4CB070+197j
                mov     eax, [esp+14h+propIDs]
                mov     eax, [eax+edx*4]
                add     eax, 0FFFFFC00h
                cmp     eax, 90h        ; switch 145 cases
                ja      loc_4CB131      ; default
                                        ; jumptable 004CB0AE cases 1-63,67-79,83-111,113-127,130-143
                movzx   ecx, ds:byte_4CB248[eax]
                jmp     ds:off_4CB218[ecx*4] ; switch jump

loc_4CB0B5:                             ; DATA XREF: .text:off_4CB218o
                cmp     word ptr [esi], 13h ; jumptable 004CB0AE case 80
                jnz     short loc_4CB131 ; default
                                        ; jumptable 004CB0AE cases 1-63,67-79,83-111,113-127,130-143
                mov     eax, [esi+8]
                lea     ecx, [eax-5]
                cmp     ecx, 10Ch
                ja      short loc_4CB131 ; default
                                        ; jumptable 004CB0AE cases 1-63,67-79,83-111,113-127,130-143
                mov     [ebp+32EF0h], eax
                jmp     loc_4CB1F9
; ---------------------------------------------------------------------------

loc_4CB0D4:                             ; CODE XREF: sub_4CB070+3Ej
                                        ; DATA XREF: .text:off_4CB218o
                cmp     word ptr [esi], 13h ; jumptable 004CB0AE case 82
                jnz     short loc_4CB131 ; default
                                        ; jumptable 004CB0AE cases 1-63,67-79,83-111,113-127,130-143
                mov     eax, [esi+8]
                mov     [ebp+33B88h], eax
                jmp     loc_4CB1F9
; ---------------------------------------------------------------------------

loc_4CB0E8:                             ; CODE XREF: sub_4CB070+3Ej
                                        ; DATA XREF: .text:off_4CB218o
                cmp     word ptr [esi], 13h ; jumptable 004CB0AE case 112
                jnz     short loc_4CB131 ; default
                                        ; jumptable 004CB0AE cases 1-63,67-79,83-111,113-127,130-143
                cmp     dword ptr [esi+8], 0
                setz    cl
                mov     [ebp+32EECh], cl
                jmp     loc_4CB1F9
; ---------------------------------------------------------------------------

loc_4CB100:                             ; CODE XREF: sub_4CB070+3Ej
                                        ; DATA XREF: .text:off_4CB218o
                cmp     word ptr [esi], 8 ; jumptable 004CB0AE case 81
                jnz     short loc_4CB131 ; default
                                        ; jumptable 004CB0AE cases 1-63,67-79,83-111,113-127,130-143
                mov     eax, [esi+8]
                lea     edi, [ebp+0C4h]
                lea     ebx, [ebp+0CCh]
                call    sub_4CAFC0
                test    eax, eax
                jz      short loc_4CB131 ; default
                                        ; jumptable 004CB0AE cases 1-63,67-79,83-111,113-127,130-143
                mov     edx, [esp+14h+var_4]
                jmp     loc_4CB1F9
; ---------------------------------------------------------------------------

loc_4CB127:                             ; CODE XREF: sub_4CB070+3Ej
                                        ; DATA XREF: .text:off_4CB218o
                cmp     word ptr [esi], 0Bh ; jumptable 004CB0AE case 128
                jz      loc_4CB1F9

loc_4CB131:                             ; CODE XREF: sub_4CB070+31j
                                        ; sub_4CB070+3Ej ...
                pop     edi             ; default
                                        ; jumptable 004CB0AE cases 1-63,67-79,83-111,113-127,130-143
                pop     esi
                pop     ebp
                mov     eax, 80070057h
                pop     ebx
                pop     ecx
                retn    10h
; ---------------------------------------------------------------------------

loc_4CB13E:                             ; CODE XREF: sub_4CB070+3Ej
                                        ; DATA XREF: .text:off_4CB218o
                cmp     word ptr [esi], 13h ; jumptable 004CB0AE case 129
                jnz     short loc_4CB131 ; default
                                        ; jumptable 004CB0AE cases 1-63,67-79,83-111,113-127,130-143
                jmp     loc_4CB1F9
; ---------------------------------------------------------------------------

loc_4CB149:                             ; CODE XREF: sub_4CB070+3Ej
                                        ; DATA XREF: .text:off_4CB218o
                cmp     word ptr [esi], 13h ; jumptable 004CB0AE case 0
                jnz     short loc_4CB131 ; default
                                        ; jumptable 004CB0AE cases 1-63,67-79,83-111,113-127,130-143
                mov     eax, [esi+8]
                lea     ecx, [eax-1]
                cmp     ecx, 3FFFFFFFh
                ja      short loc_4CB131 ; default
                                        ; jumptable 004CB0AE cases 1-63,67-79,83-111,113-127,130-143
                mov     [ebp+33B64h], eax
                xor     ecx, ecx

loc_4CB165:                             ; CODE XREF: sub_4CB070+106j
                mov     edi, 1
                shl     edi, cl
                cmp     eax, edi
                jbe     short loc_4CB178
                add     ecx, 1
                cmp     ecx, 1Eh
                jb      short loc_4CB165

loc_4CB178:                             ; CODE XREF: sub_4CB070+FEj
                lea     eax, [ecx+ecx]
                mov     [ebp+33B50h], eax
                jmp     short loc_4CB1F9
; ---------------------------------------------------------------------------

loc_4CB183:                             ; CODE XREF: sub_4CB070+3Ej
                                        ; DATA XREF: .text:off_4CB218o
                cmp     word ptr [esi], 13h ; jumptable 004CB0AE case 64
                jnz     short loc_4CB131 ; default
                                        ; jumptable 004CB0AE cases 1-63,67-79,83-111,113-127,130-143
                mov     ecx, [esi+8]
                cmp     ecx, 4
                ja      short loc_4CB131 ; default
                                        ; jumptable 004CB0AE cases 1-63,67-79,83-111,113-127,130-143
                mov     eax, 1
                shl     eax, cl
                mov     [ebp+33B54h], ecx
                sub     eax, 1
                mov     [ebp+33B58h], eax
                jmp     short loc_4CB1F9
; ---------------------------------------------------------------------------

loc_4CB1A9:                             ; CODE XREF: sub_4CB070+3Ej
                                        ; DATA XREF: .text:off_4CB218o
                cmp     word ptr [esi], 13h ; jumptable 004CB0AE case 66
                jnz     short loc_4CB131 ; default
                                        ; jumptable 004CB0AE cases 1-63,67-79,83-111,113-127,130-143
                mov     eax, [esi+8]
                cmp     eax, 4
                ja      loc_4CB131      ; default
                                        ; jumptable 004CB0AE cases 1-63,67-79,83-111,113-127,130-143
                mov     [ebp+33B5Ch], eax
                jmp     short loc_4CB1F9
; ---------------------------------------------------------------------------

loc_4CB1C3:                             ; CODE XREF: sub_4CB070+3Ej
                                        ; DATA XREF: .text:off_4CB218o
                cmp     word ptr [esi], 13h ; jumptable 004CB0AE case 65
                jnz     loc_4CB131      ; default
                                        ; jumptable 004CB0AE cases 1-63,67-79,83-111,113-127,130-143
                mov     eax, [esi+8]
                cmp     eax, 8
                ja      loc_4CB131      ; default
                                        ; jumptable 004CB0AE cases 1-63,67-79,83-111,113-127,130-143
                mov     [ebp+33B60h], eax
                jmp     short loc_4CB1F9
; ---------------------------------------------------------------------------

loc_4CB1E1:                             ; CODE XREF: sub_4CB070+3Ej
                                        ; DATA XREF: .text:off_4CB218o
                cmp     word ptr [esi], 0Bh ; jumptable 004CB0AE case 144
                jnz     loc_4CB131      ; default
                                        ; jumptable 004CB0AE cases 1-63,67-79,83-111,113-127,130-143
                cmp     word ptr [esi+8], 0FFFFh
                setz    cl
                mov     [ebp+33B8Ch], cl

loc_4CB1F9:                             ; CODE XREF: sub_4CB070+5Fj
                                        ; sub_4CB070+73j ...
                add     edx, 1
                add     esi, 10h
                cmp     edx, [esp+14h+numProperties]
                mov     [esp+14h+var_4], edx
                jb      loc_4CB090

loc_4CB20D:                             ; CODE XREF: sub_4CB070+Fj
                pop     edi
                pop     esi
                pop     ebp
                xor     eax, eax
                pop     ebx
                pop     ecx
                retn    10h

off_4CB218      dd offset loc_4CB149, offset loc_4CB183, offset loc_4CB1C3
                dd offset loc_4CB1A9, offset loc_4CB0B5, offset loc_4CB100 ; jump table for switch statement
                dd offset loc_4CB0D4, offset loc_4CB0E8, offset loc_4CB127
                dd offset loc_4CB13E, offset loc_4CB1E1, offset loc_4CB131

ICompressSetCoderProperties_SetCoderProperties      endp

; =============== S U B R O U T I N E =======================================

sub_4CB2E0      proc near               ; CODE XREF: CEncoder_GetOptimum+1199p

arg_0           = dword ptr  4
arg_4           = dword ptr  8

                push    ebx
                push    ebp
                push    esi
                mov     esi, [esp+0Ch+arg_4]
                lea     eax, [esi+esi*4]
                lea     edx, [ecx+eax*8]
                mov     [ecx+32F08h], esi
                mov     eax, [edx+100h]
                mov     ebx, [edx+104h]
                push    edi

loc_4CB300:                             ; CODE XREF: sub_4CB2E0+A6j
                lea     edx, [esi+esi*4]
                cmp     byte ptr [ecx+edx*8+0F1h], 0
                lea     edi, [ecx+edx*8]
                jz      short loc_4CB359
                lea     edx, [eax+eax*4+1Eh]
                lea     edx, [ecx+edx*8]
                mov     dword ptr [edx+14h], 0FFFFFFFFh
                mov     byte ptr [edx+1], 0
                lea     edx, [eax+eax*4]
                lea     edx, [ecx+edx*8]
                lea     ebp, [eax-1]
                mov     [edx+100h], ebp
                cmp     byte ptr [edi+0F2h], 0
                jz      short loc_4CB359
                mov     byte ptr [edx+0C9h], 0
                mov     ebp, [edi+0F4h]
                mov     [edx+0D8h], ebp
                mov     edi, [edi+0F8h]
                mov     [edx+0DCh], edi

loc_4CB359:                             ; CODE XREF: sub_4CB2E0+2Ej
                                        ; sub_4CB2E0+58j
                lea     edx, [eax+eax*4]
                add     edx, edx
                add     edx, edx
                add     edx, edx
                mov     edi, eax
                test    edi, edi
                mov     eax, [edx+ecx+100h]
                mov     ebp, ebx
                mov     ebx, [edx+ecx+104h]
                mov     [edx+ecx+100h], esi
                mov     [edx+ecx+104h], ebp
                mov     esi, edi
                jnz     loc_4CB300
                mov     eax, [ecx+104h]
                mov     edx, [esp+10h+arg_0]
                pop     edi
                pop     esi
                mov     [edx], eax
                mov     eax, [ecx+100h]
                pop     ebp
                mov     [ecx+32F0Ch], eax
                pop     ebx
                retn    8
sub_4CB2E0      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CB3B0      proc near               ; CODE XREF: CEncoder_GetOptimumFast+2Dp
                                        ; CEncoder_GetOptimumFast+28Fp ...

arg_0           = dword ptr  4

                push    ebx
                push    ebp
                push    esi
                mov     esi, ecx
                mov     ecx, [esi+80h]
                mov     edx, [esi+78h]
                lea     eax, [esi+32660h]
                push    eax
                push    ecx
                xor     ebx, ebx
                call    edx
                mov     ebp, [esp+14h+arg_0]
                add     esp, 8
                test    eax, eax
                mov     [ebp+0], eax
                jbe     short loc_4CB446
                mov     ebx, [esi+eax*4+32658h]
                cmp     ebx, [esi+32EF8h]
                jnz     short loc_4CB446
                mov     eax, [esi+80h]
                mov     ecx, [esi+70h]
                push    edi
                push    eax
                call    ecx
                mov     edx, [esi+80h]
                mov     edi, eax
                mov     eax, [esi+74h]
                push    edx
                add     edi, 1
                call    eax
                mov     ecx, [ebp+0]
                mov     ecx, [esi+ecx*4+3265Ch]
                add     esp, 8
                sub     eax, 1
                add     ecx, 1
                cmp     edi, 111h
                jbe     short loc_4CB425
                mov     edi, 111h

loc_4CB425:                             ; CODE XREF: sub_4CB3B0+6Ej
                mov     edx, eax
                sub     edx, ecx
                cmp     ebx, edi
                jnb     short loc_4CB445
                mov     ebp, edx
                lea     ecx, [eax+ebx]
                sub     ebp, eax

loc_4CB434:                             ; CODE XREF: sub_4CB3B0+93j
                mov     dl, [ecx]
                cmp     dl, [ecx+ebp]
                jnz     short loc_4CB445
                add     ebx, 1
                add     ecx, 1
                cmp     ebx, edi
                jb      short loc_4CB434

loc_4CB445:                             ; CODE XREF: sub_4CB3B0+7Bj
                                        ; sub_4CB3B0+89j
                pop     edi

loc_4CB446:                             ; CODE XREF: sub_4CB3B0+26j
                                        ; sub_4CB3B0+35j
                add     dword ptr [esi+32F04h], 1
                pop     esi
                pop     ebp
                mov     eax, ebx
                pop     ebx
                retn    4
sub_4CB3B0      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

CEncoder_GetOptimumFast proc near       ; CODE XREF: CEncoder_CodeOneBlock+1F4p

var_28          = dword ptr -28h
var_24          = dword ptr -24h
var_20          = dword ptr -20h
var_1C          = dword ptr -1Ch
var_18          = dword ptr -18h
var_14          = dword ptr -14h
var_10          = dword ptr -10h
arg_0           = dword ptr  4

                sub     esp, 28h
                push    ebx
                push    esi
                push    edi
                mov     edi, ecx
                mov     eax, [edi+80h]
                mov     ecx, [edi+70h]
                push    eax
                call    ecx
                add     esp, 4
                cmp     byte ptr [edi+32F10h], 0
                mov     esi, eax
                mov     [esp+34h+var_24], esi
                jnz     short loc_4CB498
                lea     edx, [esp+34h+var_20]
                push    edx
                mov     ecx, edi
                call    sub_4CB3B0
                mov     ebx, [esp+34h+var_20]
                jmp     short loc_4CB4AF
; ---------------------------------------------------------------------------

loc_4CB498:                             ; CODE XREF: CEncoder_GetOptimumFast+24j
                mov     ebx, [edi+32F00h]
                mov     eax, [edi+32EFCh]
                mov     [esp+34h+var_20], ebx
                mov     byte ptr [edi+32F10h], 0

loc_4CB4AF:                             ; CODE XREF: CEncoder_GetOptimumFast+36j
                mov     ecx, [edi+80h]
                mov     edx, [edi+74h]
                push    ecx
                mov     [esp+38h+var_28], eax
                call    edx
                add     esp, 4
                sub     eax, 1
                cmp     esi, 111h
                jbe     loc_4CB55E
                mov     [esp+34h+var_24], 111h

loc_4CB4D9:                             ; CODE XREF: CEncoder_GetOptimumFast+101j
                push    ebp
                xor     ebp, ebp
                lea     ecx, [edi+14h]
                mov     [esp+38h+var_18], ebp
                mov     [esp+38h+var_14], ebp
                mov     [esp+38h+var_1C], ecx
                jmp     short loc_4CB4F0
; ---------------------------------------------------------------------------
                align 10h

loc_4CB4F0:                             ; CODE XREF: CEncoder_GetOptimumFast+8Bj
                                        ; CEncoder_GetOptimumFast+132j
                mov     edx, [esp+38h+var_1C]
                mov     ecx, eax
                sub     ecx, [edx]
                mov     dl, [eax]
                sub     ecx, 1
                cmp     dl, [ecx]
                jnz     short loc_4CB57F
                mov     dl, [eax+1]
                cmp     dl, [ecx+1]
                jnz     short loc_4CB57F
                mov     esi, 2
                cmp     [esp+38h+var_24], esi
                jbe     short loc_4CB537
                lea     edx, [eax+2]
                sub     ecx, eax
                lea     esp, [esp+0]

loc_4CB520:                             ; CODE XREF: CEncoder_GetOptimumFast+D1j
                mov     bl, [edx]
                cmp     bl, [ecx+edx]
                jnz     short loc_4CB533
                add     esi, 1
                add     edx, 1
                cmp     esi, [esp+38h+var_24]
                jb      short loc_4CB520

loc_4CB533:                             ; CODE XREF: CEncoder_GetOptimumFast+C5j
                mov     ebx, [esp+38h+var_20]

loc_4CB537:                             ; CODE XREF: CEncoder_GetOptimumFast+B2j
                cmp     esi, [edi+32EF8h]
                jnb     short loc_4CB5B9
                mov     edx, [esp+38h+var_14]
                lea     ecx, ds:0[ebp*4]
                mov     [esp+ecx+38h+var_10], esi
                cmp     esi, [esp+edx+38h+var_10]
                jbe     short loc_4CB587
                mov     [esp+38h+var_18], ebp
                mov     [esp+38h+var_14], ecx
                jmp     short loc_4CB587
; ---------------------------------------------------------------------------

loc_4CB55E:                             ; CODE XREF: CEncoder_GetOptimumFast+6Bj
                cmp     esi, 2
                jnb     loc_4CB4D9
                mov     eax, [esp+34h+arg_0]
                pop     edi
                pop     esi
                mov     dword ptr [eax], 0FFFFFFFFh
                mov     eax, 1
                pop     ebx
                add     esp, 28h
                retn    4
; ---------------------------------------------------------------------------

loc_4CB57F:                             ; CODE XREF: CEncoder_GetOptimumFast+9Fj
                                        ; CEncoder_GetOptimumFast+A7j
                mov     [esp+ebp*4+38h+var_10], 0

loc_4CB587:                             ; CODE XREF: CEncoder_GetOptimumFast+F2j
                                        ; CEncoder_GetOptimumFast+FCj
                add     [esp+38h+var_1C], 4
                add     ebp, 1
                cmp     ebp, 4
                jb      loc_4CB4F0
                mov     esi, [esp+38h+var_28]
                cmp     esi, [edi+32EF8h]
                jb      short loc_4CB5EC
                mov     eax, [edi+ebx*4+3265Ch]
                mov     ecx, [esp+38h+arg_0]
                add     eax, 4
                mov     [ecx], eax
                jmp     loc_4CB69A
; ---------------------------------------------------------------------------

loc_4CB5B9:                             ; CODE XREF: CEncoder_GetOptimumFast+DDj
                mov     eax, [esp+38h+arg_0]
                mov     [eax], ebp
                lea     eax, [esi-1]
                test    eax, eax
                jz      loc_4CB82E
                mov     ecx, [edi+80h]
                mov     edx, [edi+7Ch]
                add     [edi+32F04h], eax
                push    eax
                push    ecx
                call    edx
                add     esp, 8
                pop     ebp
                pop     edi
                mov     eax, esi
                pop     esi
                pop     ebx
                add     esp, 28h
                retn    4
; ---------------------------------------------------------------------------

loc_4CB5EC:                             ; CODE XREF: CEncoder_GetOptimumFast+142j
                xor     ebp, ebp
                cmp     esi, 2
                mov     [esp+38h+var_20], ebp
                jb      short loc_4CB65A
                cmp     ebx, 2
                mov     ecx, [edi+ebx*4+3265Ch]
                mov     [esp+38h+var_20], ecx
                jbe     short loc_4CB63F
                lea     eax, [edi+ebx*4+32654h]
                mov     edi, edi

loc_4CB610:                             ; CODE XREF: CEncoder_GetOptimumFast+1DDj
                mov     edx, [eax-4]
                add     edx, 1
                cmp     esi, edx
                jnz     short loc_4CB63F
                mov     ecx, [esp+38h+var_20]
                shr     ecx, 7
                cmp     ecx, [eax]
                jbe     short loc_4CB63F
                mov     edx, [eax-4]
                mov     ecx, [eax]
                sub     eax, 8
                sub     ebx, 2
                cmp     ebx, 2
                mov     [esp+38h+var_28], edx
                mov     [esp+38h+var_20], ecx
                mov     esi, edx
                ja      short loc_4CB610

loc_4CB63F:                             ; CODE XREF: CEncoder_GetOptimumFast+1A5j
                                        ; CEncoder_GetOptimumFast+1B8j ...
                cmp     esi, 2
                jnz     short loc_4CB656
                cmp     [esp+38h+var_20], 80h
                jb      short loc_4CB656
                mov     [esp+38h+var_28], 1

loc_4CB656:                             ; CODE XREF: CEncoder_GetOptimumFast+1E2j
                                        ; CEncoder_GetOptimumFast+1ECj
                mov     ebp, [esp+38h+var_20]

loc_4CB65A:                             ; CODE XREF: CEncoder_GetOptimumFast+195j
                mov     edx, [esp+38h+var_18]
                mov     esi, [esp+edx*4+38h+var_10]
                cmp     esi, 2
                mov     ebx, [esp+38h+var_28]
                jb      short loc_4CB6C7
                lea     eax, [esi+1]
                cmp     eax, ebx
                jnb     short loc_4CB690
                lea     ecx, [esi+2]
                cmp     ecx, ebx
                jb      short loc_4CB681
                cmp     ebp, 200h
                ja      short loc_4CB690

loc_4CB681:                             ; CODE XREF: CEncoder_GetOptimumFast+217j
                lea     edx, [esi+3]
                cmp     edx, ebx
                jb      short loc_4CB6C7
                cmp     ebp, 8000h
                jbe     short loc_4CB6C7

loc_4CB690:                             ; CODE XREF: CEncoder_GetOptimumFast+210j
                                        ; CEncoder_GetOptimumFast+21Fj
                mov     eax, [esp+38h+arg_0]
                mov     ecx, [esp+38h+var_18]
                mov     [eax], ecx

loc_4CB69A:                             ; CODE XREF: CEncoder_GetOptimumFast+154j
                lea     eax, [esi-1]
                test    eax, eax
                jz      loc_4CB82E
                mov     edx, [edi+80h]
                add     [edi+32F04h], eax
                push    eax
                mov     eax, [edi+7Ch]
                push    edx
                call    eax
                add     esp, 8
                pop     ebp
                pop     edi
                mov     eax, esi
                pop     esi
                pop     ebx
                add     esp, 28h
                retn    4
; ---------------------------------------------------------------------------

loc_4CB6C7:                             ; CODE XREF: CEncoder_GetOptimumFast+209j
                                        ; CEncoder_GetOptimumFast+226j ...
                cmp     ebx, 2
                jb      short loc_4CB73E
                cmp     [esp+38h+var_24], 2
                jbe     short loc_4CB73E
                mov     ecx, [edi+80h]
                mov     edx, [edi+70h]
                push    ecx
                call    edx
                add     esp, 4
                lea     esi, [edi+32F00h]
                push    esi
                mov     ecx, edi
                mov     [esp+3Ch+var_24], eax
                call    sub_4CB3B0
                cmp     eax, 2
                mov     [edi+32EFCh], eax
                jb      short loc_4CB757
                cmp     eax, ebx
                mov     ecx, [esi]
                mov     edx, [edi+ecx*4+3265Ch]
                jb      short loc_4CB710
                cmp     edx, ebp
                jb      short loc_4CB737

loc_4CB710:                             ; CODE XREF: CEncoder_GetOptimumFast+2AAj
                lea     ecx, [ebx+1]
                cmp     eax, ecx
                jnz     short loc_4CB722
                mov     esi, edx
                shr     esi, 7
                cmp     esi, ebp
                jbe     short loc_4CB737
                cmp     eax, ecx

loc_4CB722:                             ; CODE XREF: CEncoder_GetOptimumFast+2B5j
                ja      short loc_4CB737
                add     eax, 1
                cmp     eax, ebx
                jb      short loc_4CB757
                cmp     ebx, 3
                jb      short loc_4CB757
                shr     ebp, 7
                cmp     ebp, edx
                jbe     short loc_4CB757

loc_4CB737:                             ; CODE XREF: CEncoder_GetOptimumFast+2AEj
                                        ; CEncoder_GetOptimumFast+2BEj ...
                mov     byte ptr [edi+32F10h], 1

loc_4CB73E:                             ; CODE XREF: CEncoder_GetOptimumFast+26Aj
                                        ; CEncoder_GetOptimumFast+271j
                mov     edx, [esp+38h+arg_0]
                pop     ebp
                pop     edi
                pop     esi
                mov     dword ptr [edx], 0FFFFFFFFh
                mov     eax, 1
                pop     ebx
                add     esp, 28h
                retn    4
; ---------------------------------------------------------------------------

loc_4CB757:                             ; CODE XREF: CEncoder_GetOptimumFast+29Dj
                                        ; CEncoder_GetOptimumFast+2C9j ...
                mov     eax, [edi+80h]
                mov     ecx, [edi+74h]
                push    eax
                call    ecx
                lea     ecx, [edi+14h]
                add     esp, 4
                sub     eax, 1
                mov     [esp+38h+var_18], 0
                mov     ebx, ecx

loc_4CB776:                             ; CODE XREF: CEncoder_GetOptimumFast+39Aj
                mov     dl, [eax+1]
                mov     ecx, eax
                sub     ecx, [ebx]
                sub     ecx, 1
                cmp     dl, [ecx+1]
                jnz     short loc_4CB7DD
                mov     dl, [eax+2]
                cmp     dl, [ecx+2]
                lea     ebp, [eax+2]
                jnz     short loc_4CB7DD
                mov     esi, 2
                cmp     [esp+38h+var_24], esi
                jbe     short loc_4CB7B4
                mov     edx, ebp
                mov     ebp, ecx
                sub     ebp, eax

loc_4CB7A1:                             ; CODE XREF: CEncoder_GetOptimumFast+352j
                mov     cl, [edx]
                cmp     cl, [edx+ebp]
                jnz     short loc_4CB7B4
                add     esi, 1
                add     edx, 1
                cmp     esi, [esp+38h+var_24]
                jb      short loc_4CB7A1

loc_4CB7B4:                             ; CODE XREF: CEncoder_GetOptimumFast+339j
                                        ; CEncoder_GetOptimumFast+346j
                add     esi, 1
                cmp     esi, [esp+38h+var_28]
                jb      short loc_4CB7E9
                mov     eax, [esp+38h+arg_0]
                pop     ebp
                mov     byte ptr [edi+32F10h], 1
                pop     edi
                pop     esi
                mov     dword ptr [eax], 0FFFFFFFFh
                mov     eax, 1
                pop     ebx
                add     esp, 28h
                retn    4
; ---------------------------------------------------------------------------

loc_4CB7DD:                             ; CODE XREF: CEncoder_GetOptimumFast+323j
                                        ; CEncoder_GetOptimumFast+32Ej
                mov     edx, [esp+38h+var_18]
                mov     [esp+edx*4+38h+var_10], 0

loc_4CB7E9:                             ; CODE XREF: CEncoder_GetOptimumFast+35Bj
                mov     ecx, [esp+38h+var_18]
                add     ecx, 1
                add     ebx, 4
                cmp     ecx, 4
                mov     [esp+38h+var_18], ecx
                jb      loc_4CB776
                mov     esi, [esp+38h+var_28]
                mov     ecx, [esp+38h+var_20]
                mov     edx, [esp+38h+arg_0]
                add     ecx, 4
                lea     eax, [esi-2]
                test    eax, eax
                mov     [edx], ecx
                jz      short loc_4CB82E
                add     [edi+32F04h], eax
                mov     ecx, [edi+7Ch]
                push    eax
                mov     eax, [edi+80h]
                push    eax
                call    ecx
                add     esp, 8

loc_4CB82E:                             ; CODE XREF: CEncoder_GetOptimumFast+164j
                                        ; CEncoder_GetOptimumFast+23Fj ...
                pop     ebp
                pop     edi
                mov     eax, esi
                pop     esi
                pop     ebx
                add     esp, 28h
                retn    4
CEncoder_GetOptimumFast endp

; =============== S U B R O U T I N E =======================================

sub_4CB8A0      proc near               ; CODE XREF: sub_4CD940+37p

arg_0           = dword ptr  4

                push    edi
                mov     edi, [esp+4+arg_0]
                test    edi, edi
                jz      short loc_4CB8EB
                mov     eax, dword_553598
                test    eax, eax
                jnz     short loc_4CB8DD
                push    0Ch             ; Size
                call    _operator_new    ; operator new(uint)
                add     esp, 4
                test    eax, eax
                jz      short loc_4CB8D6
                mov     dword ptr [eax], 0
                mov     dword ptr [eax+4], 0
                mov     dword ptr [eax+8], 0
                jmp     short loc_4CB8D8
; ---------------------------------------------------------------------------

loc_4CB8D6:                             ; CODE XREF: sub_4CB8A0+1Ej
                xor     eax, eax

loc_4CB8D8:                             ; CODE XREF: sub_4CB8A0+34j
                mov     dword_553598, eax

loc_4CB8DD:                             ; CODE XREF: sub_4CB8A0+10j
                mov     eax, [eax]
                test    eax, eax
                jz      short loc_4CB8EB
                push    edi
                call    eax
                add     esp, 4
                pop     edi
                retn
; ---------------------------------------------------------------------------

loc_4CB8EB:                             ; CODE XREF: sub_4CB8A0+7j
                                        ; sub_4CB8A0+41j
                xor     eax, eax
                pop     edi
                retn
sub_4CB8A0      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CB8F0      proc near               ; CODE XREF: sub_4CBA60+85p

arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch

                push    esi
                mov     esi, [esp+4+arg_0]
                push    edi
                mov     edi, [esi+44h]
                add     edi, [esi+40h]
                add     edi, [esp+8+arg_4]
                cmp     dword ptr [esi+4Ch], 0
                jz      short loc_4CB911
                mov     [esi+3Ch], edi
                pop     edi
                mov     eax, 1
                pop     esi
                retn
; ---------------------------------------------------------------------------

loc_4CB911:                             ; CODE XREF: sub_4CB8F0+14j
                mov     eax, [esi+30h]
                test    eax, eax
                jz      short loc_4CB91D
                cmp     [esi+3Ch], edi
                jz      short loc_4CB93E

loc_4CB91D:                             ; CODE XREF: sub_4CB8F0+26j
                push    ebx
                mov     ebx, [esp+0Ch+arg_8]
                push    eax
                mov     eax, [ebx+4]
                call    eax
                mov     dword ptr [esi+30h], 0
                mov     [esi+3Ch], edi
                mov     ecx, [ebx]
                push    edi
                call    ecx
                add     esp, 8
                mov     [esi+30h], eax
                pop     ebx

loc_4CB93E:                             ; CODE XREF: sub_4CB8F0+2Bj
                xor     eax, eax
                cmp     [esi+30h], eax
                pop     edi
                setnz   al
                pop     esi
                retn
sub_4CB8F0      endp

; ---------------------------------------------------------------------------
                align 10h

loc_4CB950:                             ; DATA XREF: sub_4CCAA0+1Co
                mov     eax, [esp+4]
                mov     eax, [eax]
                retn
; ---------------------------------------------------------------------------
                align 10h

loc_4CB960:                             ; DATA XREF: sub_4CCAA0+Eo
                mov     eax, [esp+4]
                mov     ecx, [eax]
                mov     edx, [esp+8]
                mov     al, [edx+ecx]
                retn
; ---------------------------------------------------------------------------
                align 10h
loc_4CB970:                             ; DATA XREF: sub_4CCAA0+15o
                mov     ecx, [esp+4]

; =============== S U B R O U T I N E =======================================

; Attributes: library function

; public: int __thiscall CRect::Height(void)const
?Height@CRect@@QBEHXZ proc near
                mov     eax, [ecx+0Ch]
                sub     eax, [ecx+4]
                retn
?Height@CRect@@QBEHXZ endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CB980      proc near               ; CODE XREF: sub_4CBC80+46p
                                        ; sub_4CBD50+61p

arg_0           = dword ptr  4

                push    esi
                mov     esi, [esp+4+arg_0]
                cmp     dword ptr [esi+38h], 0
                jnz     short loc_4CB9F0
                cmp     dword ptr [esi+68h], 0
                jnz     short loc_4CB9F0
                mov     eax, [esi]
                sub     eax, [esi+4]
                mov     ecx, [esi+30h]
                add     eax, [esi+0Ch]
                sub     ecx, eax
                add     ecx, [esi+3Ch]
                jz      short loc_4CB9F0
                push    edi

loc_4CB9A4:                             ; CODE XREF: sub_4CB980+63j
                mov     edx, [esi+34h]
                lea     edi, [esp+8+arg_0]
                push    edi
                push    ecx
                push    eax
                mov     eax, [edx]
                push    edx
                call    eax
                add     esp, 10h
                test    eax, eax
                mov     [esi+68h], eax
                jnz     short loc_4CB9EF
                mov     eax, [esp+8+arg_0]
                test    eax, eax
                jz      short loc_4CB9E8
                add     [esi+0Ch], eax
                mov     eax, [esi+0Ch]
                sub     eax, [esi+4]
                cmp     eax, [esi+44h]
                ja      short loc_4CB9EF
                mov     eax, [esi]
                sub     eax, [esi+4]
                mov     ecx, [esi+30h]
                add     eax, [esi+0Ch]
                sub     ecx, eax
                add     ecx, [esi+3Ch]
                jnz     short loc_4CB9A4
                pop     edi
                pop     esi
                retn
; ---------------------------------------------------------------------------

loc_4CB9E8:                             ; CODE XREF: sub_4CB980+43j
                mov     dword ptr [esi+38h], 1

loc_4CB9EF:                             ; CODE XREF: sub_4CB980+3Bj
                                        ; sub_4CB980+51j
                pop     edi

loc_4CB9F0:                             ; CODE XREF: sub_4CB980+9j
                                        ; sub_4CB980+Fj ...
                pop     esi
                retn
sub_4CB980      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CBA00      proc near               ; CODE XREF: sub_4CBD50+58p

arg_0           = dword ptr  4

                push    ebx
                push    ebp
                push    esi
                push    edi
                mov     edi, [esp+10h+arg_0]
                mov     esi, [edi+0Ch]
                mov     eax, [edi+40h]
                sub     esi, [edi+4]
                mov     ebx, [edi]
                mov     ebp, [edi+30h]
                add     esi, eax
                sub     ebx, eax
                mov     eax, dword_553598
                test    eax, eax
                jnz     short loc_4CBA44
                push    0Ch             ; Size
                call    _operator_new  ; operator new(uint)
                xor     ecx, ecx
                add     esp, 4
                cmp     eax, ecx
                jz      short loc_4CBA3D
                mov     [eax], ecx
                mov     [eax+4], ecx
                mov     [eax+8], ecx
                jmp     short loc_4CBA3F
; ---------------------------------------------------------------------------

loc_4CBA3D:                             ; CODE XREF: sub_4CBA00+31j
                xor     eax, eax

loc_4CBA3F:                             ; CODE XREF: sub_4CBA00+3Bj
                mov     dword_553598, eax

loc_4CBA44:                             ; CODE XREF: sub_4CBA00+21j
                mov     eax, [eax+8]
                test    eax, eax
                jz      short loc_4CBA53
                push    esi
                push    ebx
                push    ebp
                call    eax
                add     esp, 0Ch

loc_4CBA53:                             ; CODE XREF: sub_4CBA00+49j
                mov     eax, [edi+30h]
                add     eax, [edi+40h]
                mov     [edi], eax
                pop     edi
                pop     esi
                pop     ebp
                pop     ebx
                retn
sub_4CBA00      endp

; =============== S U B R O U T I N E =======================================

sub_4CBA60      proc near               ; CODE XREF: sub_4D0270+D2p

arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch
arg_C           = dword ptr  10h
arg_10          = dword ptr  14h
arg_14          = dword ptr  18h

                push    ebx
                push    esi
                push    edi
                mov     edi, [esp+0Ch+arg_4]
                cmp     edi, 0C0000000h
                jbe     short loc_4CBAA2
                mov     esi, [esp+0Ch+arg_0]
                mov     eax, [esi+20h]
                mov     edi, [esp+0Ch+arg_14]
                mov     ecx, [edi+4]
                push    eax
                call    ecx
                xor     ebx, ebx
                add     esp, 4
                cmp     [esi+4Ch], ebx
                mov     [esi+20h], ebx
                jnz     short loc_4CBA9C
                mov     edx, [esi+30h]
                mov     eax, [edi+4]
                push    edx
                call    eax
                add     esp, 4
                mov     [esi+30h], ebx

loc_4CBA9C:                             ; CODE XREF: sub_4CBA60+2Bj
                pop     edi
                pop     esi
                xor     eax, eax
                pop     ebx
                retn
; ---------------------------------------------------------------------------

loc_4CBAA2:                             ; CODE XREF: sub_4CBA60+Dj
                mov     eax, edi
                shr     eax, 1
                cmp     edi, 80000000h
                jbe     short loc_4CBAB3
                mov     eax, edi
                shr     eax, 2

loc_4CBAB3:                             ; CODE XREF: sub_4CBA60+4Cj
                mov     ecx, [esp+0Ch+arg_8]
                mov     esi, [esp+0Ch+arg_0]
                mov     ebx, [esp+0Ch+arg_C]
                lea     edx, [edi+ecx+1]
                push    ebp
                mov     [esi+40h], edx
                mov     edx, [esp+10h+arg_10]
                add     ecx, ebx
                lea     ebp, [ebx+edx]
                add     ecx, edx
                mov     [esi+44h], ebp
                mov     ebp, [esp+10h+arg_14]
                shr     ecx, 1
                push    ebp
                lea     eax, [ecx+eax+80000h]
                push    eax
                push    esi
                call    sub_4CB8F0
                add     esp, 0Ch
                test    eax, eax
                jz      loc_4CBBEA
                mov     edx, [esi+48h]
                mov     [esi+1Ch], ebx
                xor     ebx, ebx
                cmp     edx, 2
                lea     ebp, [edi+1]
                mov     [esi+5Ch], ebx
                jnz     short loc_4CBB0F
                mov     eax, 0FFFFh
                jmp     short loc_4CBB49
; ---------------------------------------------------------------------------

loc_4CBB0F:                             ; CODE XREF: sub_4CBA60+A6j
                lea     ecx, [edi-1]
                mov     eax, ecx
                shr     eax, 1
                or      ecx, eax
                mov     eax, ecx
                shr     eax, 2
                or      ecx, eax
                mov     eax, ecx
                shr     eax, 4
                or      ecx, eax
                mov     eax, ecx
                or      eax, 1FFFE00h
                shr     eax, 8
                or      eax, ecx
                shr     eax, 1
                cmp     eax, 1000000h
                jbe     short loc_4CBB49
                cmp     edx, 3
                jnz     short loc_4CBB47
                mov     eax, 0FFFFFFh
                jmp     short loc_4CBB49
; ---------------------------------------------------------------------------

loc_4CBB47:                             ; CODE XREF: sub_4CBA60+DEj
                shr     eax, 1

loc_4CBB49:                             ; CODE XREF: sub_4CBA60+ADj
                                        ; sub_4CBA60+D9j ...
                mov     [esi+28h], eax
                add     eax, 1
                cmp     edx, 2
                jbe     short loc_4CBB5B
                mov     dword ptr [esi+5Ch], 400h

loc_4CBB5B:                             ; CODE XREF: sub_4CBA60+F2j
                cmp     edx, 3
                jbe     short loc_4CBB67
                add     dword ptr [esi+5Ch], 10000h

loc_4CBB67:                             ; CODE XREF: sub_4CBA60+FEj
                cmp     edx, 4
                jbe     short loc_4CBB73
                add     dword ptr [esi+5Ch], 100000h

loc_4CBB73:                             ; CODE XREF: sub_4CBA60+10Aj
                mov     ecx, [esi+60h]
                mov     edx, [esi+5Ch]
                add     ecx, [esi+64h]
                add     eax, edx
                cmp     [esi+50h], ebx
                mov     [esi+58h], edi
                mov     [esi+60h], eax
                mov     [esi+18h], ebp
                lea     edx, [ebp+ebp+0]
                jnz     short loc_4CBB92
                mov     edx, ebp

loc_4CBB92:                             ; CODE XREF: sub_4CBA60+12Ej
                lea     edi, [eax+edx]
                mov     eax, [esi+20h]
                cmp     eax, ebx
                mov     [esi+64h], edx
                jz      short loc_4CBBA3
                cmp     ecx, edi
                jz      short loc_4CBBE0

loc_4CBBA3:                             ; CODE XREF: sub_4CBA60+13Dj
                mov     ebp, [esp+10h+arg_14]
                push    eax
                mov     eax, [ebp+4]
                call    eax
                lea     eax, ds:0[edi*4]
                mov     ecx, eax
                shr     ecx, 2
                add     esp, 4
                cmp     ecx, edi
                mov     [esi+20h], ebx
                jz      short loc_4CBBC7
                xor     eax, eax
                jmp     short loc_4CBBD0
; ---------------------------------------------------------------------------

loc_4CBBC7:                             ; CODE XREF: sub_4CBA60+161j
                mov     edx, [ebp+0]
                push    eax
                call    edx
                add     esp, 4

loc_4CBBD0:                             ; CODE XREF: sub_4CBA60+165j
                cmp     eax, ebx
                mov     [esi+20h], eax
                jz      short loc_4CBBEC
                mov     ecx, [esi+60h]
                lea     edx, [eax+ecx*4]
                mov     [esi+24h], edx

loc_4CBBE0:                             ; CODE XREF: sub_4CBA60+141j
                pop     ebp
                pop     edi
                pop     esi
                mov     eax, 1
                pop     ebx
                retn
; ---------------------------------------------------------------------------

loc_4CBBEA:                             ; CODE XREF: sub_4CBA60+8Fj
                xor     ebx, ebx

loc_4CBBEC:                             ; CODE XREF: sub_4CBA60+175j
                mov     eax, [esi+20h]
                mov     ecx, [ebp+4]
                push    eax
                call    ecx
                add     esp, 4
                cmp     [esi+4Ch], ebx
                mov     [esi+20h], ebx
                jnz     short loc_4CBC0F
                mov     edx, [esi+30h]
                mov     eax, [ebp+4]
                push    edx
                call    eax
                add     esp, 4
                mov     [esi+30h], ebx

loc_4CBC0F:                             ; CODE XREF: sub_4CBA60+19Ej
                pop     ebp
                pop     edi
                pop     esi
                xor     eax, eax
                pop     ebx
                retn
sub_4CBA60      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CBC20      proc near               ; CODE XREF: sub_4CBD50+79p

arg_0           = dword ptr  4

                mov     eax, [esp+arg_0]
                mov     edx, [eax+18h]
                sub     edx, [eax+14h]
                push    ebx
                mov     ebx, [eax+4]
                or      ecx, 0FFFFFFFFh
                sub     ecx, ebx
                cmp     edx, ecx
                push    esi
                jnb     short loc_4CBC3A
                mov     ecx, edx

loc_4CBC3A:                             ; CODE XREF: sub_4CBC20+16j
                mov     esi, [eax+0Ch]
                sub     esi, ebx
                push    edi
                mov     edi, [eax+44h]
                mov     edx, esi
                cmp     edx, edi
                ja      short loc_4CBC54
                test    edx, edx
                jbe     short loc_4CBC56
                mov     edx, 1
                jmp     short loc_4CBC56
; ---------------------------------------------------------------------------

loc_4CBC54:                             ; CODE XREF: sub_4CBC20+27j
                sub     edx, edi

loc_4CBC56:                             ; CODE XREF: sub_4CBC20+2Bj
                                        ; sub_4CBC20+32j
                cmp     edx, ecx
                pop     edi
                jnb     short loc_4CBC5D
                mov     ecx, edx

loc_4CBC5D:                             ; CODE XREF: sub_4CBC20+39j
                mov     edx, [eax+1Ch]
                cmp     esi, edx
                jbe     short loc_4CBC66
                mov     esi, edx

loc_4CBC66:                             ; CODE XREF: sub_4CBC20+42j
                add     ebx, ecx
                mov     [eax+10h], esi
                pop     esi
                mov     [eax+8], ebx
                pop     ebx
                retn
sub_4CBC20      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CBC80      proc near               ; DATA XREF: sub_4CCAA0+8o

arg_0           = dword ptr  4

                push    ebx
                push    esi
                mov     esi, [esp+8+arg_0]
                xor     eax, eax
                cmp     [esi+60h], eax
                jbe     short loc_4CBCA2
                lea     ecx, [ecx+0]

loc_4CBC90:                             ; CODE XREF: sub_4CBC80+20j
                mov     ecx, [esi+20h]
                mov     dword ptr [ecx+eax*4], 0
                add     eax, 1
                cmp     eax, [esi+60h]
                jb      short loc_4CBC90

loc_4CBCA2:                             ; CODE XREF: sub_4CBC80+Bj
                mov     eax, [esi+18h]
                mov     edx, [esi+30h]
                push    esi
                mov     dword ptr [esi+14h], 0
                mov     [esi], edx
                mov     [esi+0Ch], eax
                mov     [esi+4], eax
                mov     dword ptr [esi+68h], 0
                mov     dword ptr [esi+38h], 0
                call    sub_4CB980
                mov     eax, [esi+18h]
                mov     ebx, [esi+4]
                sub     eax, [esi+14h]
                or      ecx, 0FFFFFFFFh
                sub     ecx, ebx
                add     esp, 4
                cmp     eax, ecx
                jnb     short loc_4CBCE2
                mov     ecx, eax

loc_4CBCE2:                             ; CODE XREF: sub_4CBC80+5Ej
                mov     edx, [esi+0Ch]
                sub     edx, ebx
                push    edi
                mov     edi, [esi+44h]
                mov     eax, edx
                cmp     eax, edi
                ja      short loc_4CBCFC
                test    eax, eax
                jbe     short loc_4CBCFE
                mov     eax, 1
                jmp     short loc_4CBCFE
; ---------------------------------------------------------------------------

loc_4CBCFC:                             ; CODE XREF: sub_4CBC80+6Fj
                sub     eax, edi

loc_4CBCFE:                             ; CODE XREF: sub_4CBC80+73j
                                        ; sub_4CBC80+7Aj
                cmp     eax, ecx
                pop     edi
                jnb     short loc_4CBD05
                mov     ecx, eax

loc_4CBD05:                             ; CODE XREF: sub_4CBC80+81j
                mov     eax, edx
                mov     edx, [esi+1Ch]
                cmp     eax, edx
                jbe     short loc_4CBD10
                mov     eax, edx

loc_4CBD10:                             ; CODE XREF: sub_4CBC80+8Cj
                add     ebx, ecx
                mov     [esi+8], ebx
                mov     [esi+10h], eax
                pop     esi
                pop     ebx
                retn
sub_4CBC80      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================


sub_4CBD20      proc near               ; CODE XREF: sub_4CBD50+26p

arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch

                push    edi
                mov     edi, [esp+4+arg_8]
                xor     eax, eax
                test    edi, edi
                jbe     short loc_4CBD4C
                mov     edx, [esp+4+arg_4]
                push    esi
                mov     esi, [esp+8+arg_0]

loc_4CBD34:                             ; CODE XREF: sub_4CBD20+29j
                mov     ecx, [edx+eax*4]
                cmp     ecx, esi
                ja      short loc_4CBD3F
                xor     ecx, ecx
                jmp     short loc_4CBD41
; ---------------------------------------------------------------------------

loc_4CBD3F:                             ; CODE XREF: sub_4CBD20+19j
                sub     ecx, esi

loc_4CBD41:                             ; CODE XREF: sub_4CBD20+1Dj
                mov     [edx+eax*4], ecx
                add     eax, 1
                cmp     eax, edi
                jb      short loc_4CBD34
                pop     esi

loc_4CBD4C:                             ; CODE XREF: sub_4CBD20+9j
                pop     edi
                retn
sub_4CBD20      endp

; ---------------------------------------------------------------------------
                align 10h

; =============== S U B R O U T I N E =======================================

sub_4CBD50      proc near               ; CODE XREF: .text:004CC1A1p
                                        ; .text:004CC20Ap ...

arg_0           = dword ptr  4

                push    esi
                mov     esi, [esp+4+arg_0]
                cmp     dword ptr [esi+4], 0FFFFFFFFh
                jnz     short loc_4CBD88
                mov     eax, [esi+64h]
                add     eax, [esi+60h]
                mov     ecx, [esi+20h]
                push    edi
                mov     edi, 0FFFFFFFEh
                sub     edi, [esi+58h]
                push    eax
                push    ecx
                and     edi, 0FFFFFC00h
                push    edi
                call    sub_4CBD20
                sub     [esi+8], edi
                sub     [esi+4], edi
                add     esp, 0Ch
                sub     [esi+0Ch], edi
                pop     edi

loc_4CBD88:                             ; CODE XREF: sub_4CBD50+9j
                cmp     dword ptr [esi+38h], 0
                jnz     short loc_4CBDB9
                mov     edx, [esi+0Ch]
                sub     edx, [esi+4]
                mov     eax, [esi+44h]
                cmp     eax, edx
                jnz     short loc_4CBDB9
                mov     ecx, [esi+3Ch]
                add     ecx, [esi+30h]
                sub     ecx, [esi]
                cmp     ecx, eax
                ja      short loc_4CBDB0
                push    esi
                call    sub_4CBA00
                add     esp, 4

loc_4CBDB0:                             ; CODE XREF: sub_4CBD50+55j
                push    esi
                call    sub_4CB980
                add     esp, 4

loc_4CBDB9:                             ; CODE XREF: sub_4CBD50+3Cj
                                        ; sub_4CBD50+49j
                mov     edx, [esi+14h]
                cmp     edx, [esi+18h]
                jnz     short loc_4CBDC8
                mov     dword ptr [esi+14h], 0

loc_4CBDC8:                             ; CODE XREF: sub_4CBD50+6Fj
                push    esi
                call    sub_4CBC20
                add     esp, 4
                pop     esi
                retn
sub_4CBD50      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CBDE0      proc near               ; CODE XREF: sub_4CC5C0+1B7p

var_4           = dword ptr -4
arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch
arg_C           = dword ptr  10h
arg_10          = dword ptr  14h
arg_14          = dword ptr  18h
arg_18          = dword ptr  1Ch
arg_1C          = dword ptr  20h
arg_20          = dword ptr  24h
arg_24          = dword ptr  28h

                push    ecx
                mov     edx, [esp+4+arg_4]
                mov     ecx, [esp+4+arg_10]
                mov     eax, [esp+4+arg_14]
                push    ebx
                mov     [ecx+eax*4], edx
                mov     ecx, [esp+8+arg_8]
                push    ebp
                push    esi
                sub     ecx, edx
                cmp     [esp+10h+arg_1C], 0
                push    edi
                jz      loc_4CBEAC
                mov     ebp, [esp+14h+arg_C]
                mov     ebx, [esp+14h+arg_24]
                jmp     short loc_4CBE14
; ---------------------------------------------------------------------------
                align 10h

loc_4CBE10:                             ; CODE XREF: sub_4CBDE0+C6j
                mov     eax, [esp+14h+arg_14]

loc_4CBE14:                             ; CODE XREF: sub_4CBDE0+2Dj
                mov     esi, [esp+14h+arg_18]
                sub     [esp+14h+arg_1C], 1
                cmp     ecx, esi
                jnb     loc_4CBEAC
                mov     edx, ebp
                sub     edx, ecx
                cmp     eax, ecx
                sbb     edi, edi
                and     edi, esi
                sub     edi, ecx
                add     edi, eax
                mov     eax, [esp+14h+arg_10]
                mov     eax, [eax+edi*4]
                mov     [esp+14h+arg_4], eax
                mov     al, [edx+ebx]
                cmp     al, [ebx+ebp]
                jnz     short loc_4CBE99
                mov     al, [edx]
                cmp     al, [ebp+0]
                jnz     short loc_4CBE99
                mov     eax, [esp+14h+arg_0]
                mov     esi, 1
                cmp     eax, esi
                jz      short loc_4CBE7A
                sub     edx, ebp
                lea     edi, [ebp+1]
                mov     [esp+14h+var_4], edx
                jmp     short loc_4CBE69
; ---------------------------------------------------------------------------

loc_4CBE65:                             ; CODE XREF: sub_4CBDE0+98j
                mov     edx, [esp+14h+var_4]

loc_4CBE69:                             ; CODE XREF: sub_4CBDE0+83j
                mov     dl, [edx+edi]
                cmp     dl, [edi]
                jnz     short loc_4CBE7A
                add     esi, 1
                add     edi, 1
                cmp     esi, eax
                jnz     short loc_4CBE65

loc_4CBE7A:                             ; CODE XREF: sub_4CBDE0+78j
                                        ; sub_4CBDE0+8Ej
                cmp     ebx, esi
                jnb     short loc_4CBE99
                mov     edx, [esp+14h+arg_20]
                mov     [edx], esi
                add     edx, 4
                add     ecx, 0FFFFFFFFh
                mov     [edx], ecx
                add     edx, 4
                cmp     esi, eax
                mov     ebx, esi
                mov     [esp+14h+arg_20], edx
                jz      short loc_4CBEB6

loc_4CBE99:                             ; CODE XREF: sub_4CBDE0+64j
                                        ; sub_4CBDE0+6Bj ...
                mov     ecx, [esp+14h+arg_8]
                sub     ecx, [esp+14h+arg_4]
                cmp     [esp+14h+arg_1C], 0
                jnz     loc_4CBE10

loc_4CBEAC:                             ; CODE XREF: sub_4CBDE0+1Fj
                                        ; sub_4CBDE0+3Fj
                mov     eax, [esp+14h+arg_20]
                pop     edi
                pop     esi
                pop     ebp
                pop     ebx
                pop     ecx
                retn
; ---------------------------------------------------------------------------

loc_4CBEB6:                             ; CODE XREF: sub_4CBDE0+B7j
                pop     edi
                pop     esi
                pop     ebp
                mov     eax, edx
                pop     ebx
                pop     ecx
                retn
sub_4CBDE0      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CBEC0      proc near               ; CODE XREF: .text:004CC1E7p
                                        ; sub_4CC220+14Ep ...

var_10          = dword ptr -10h
var_C           = dword ptr -0Ch
var_8           = dword ptr -8
var_4           = dword ptr -4
arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch
arg_C           = dword ptr  10h
arg_10          = dword ptr  14h
arg_14          = dword ptr  18h
arg_18          = dword ptr  1Ch
arg_1C          = dword ptr  20h
arg_20          = dword ptr  24h
arg_24          = dword ptr  28h

                sub     esp, 10h
                mov     eax, [esp+10h+arg_10]
                mov     edx, [esp+10h+arg_8]
                sub     edx, [esp+10h+arg_4]
                push    ebx
                push    ebp
                push    esi
                push    edi
                mov     edi, [esp+20h+arg_14]
                lea     eax, [eax+edi*8]
                lea     ecx, [eax+4]
                mov     [esp+20h+var_C], ecx
                xor     ecx, ecx
                xor     ebx, ebx
                cmp     [esp+20h+arg_1C], ecx
                mov     ebp, eax
                mov     [esp+20h+var_10], ebp
                mov     [esp+20h+var_8], ecx
                mov     [esp+20h+var_4], ebx
                jnz     short loc_4CBF24

loc_4CBEF9:                             ; CODE XREF: sub_4CBEC0+6Fj
                                        ; sub_4CBEC0+151j
                mov     edx, [esp+20h+var_C]
                mov     eax, [esp+20h+arg_20]
                pop     edi
                pop     esi
                mov     dword ptr [ebp+0], 0
                pop     ebp
                mov     dword ptr [edx], 0
                pop     ebx
                add     esp, 10h
                retn
; ---------------------------------------------------------------------------
                jmp     short loc_4CBF20
; ---------------------------------------------------------------------------
                align 10h

loc_4CBF20:                             ; CODE XREF: sub_4CBEC0+56j
                                        ; sub_4CBEC0+14Bj
                mov     edi, [esp+20h+arg_14]

loc_4CBF24:                             ; CODE XREF: sub_4CBEC0+37j
                mov     eax, [esp+20h+arg_18]
                sub     [esp+20h+arg_1C], 1
                cmp     edx, eax
                jnb     short loc_4CBEF9
                cmp     edi, edx
                sbb     esi, esi
                and     esi, eax
                mov     eax, [esp+20h+arg_10]
                sub     esi, edx
                add     esi, edi
                lea     eax, [eax+esi*8]
                mov     esi, [esp+20h+arg_C]
                sub     esi, edx
                cmp     ecx, ebx
                jb      short loc_4CBF4E
                mov     ecx, ebx

loc_4CBF4E:                             ; CODE XREF: sub_4CBEC0+8Aj
                mov     bl, [ecx+esi]
                mov     edi, [esp+20h+arg_C]
                cmp     bl, [ecx+edi]
                jnz     short loc_4CBFB8
                add     ecx, 1
                cmp     ecx, [esp+20h+arg_0]
                jz      short loc_4CBF93
                mov     bl, [ecx+esi]
                cmp     bl, [ecx+edi]
                jnz     short loc_4CBF93
                add     ecx, 1
                cmp     ecx, [esp+20h+arg_0]
                jz      short loc_4CBF93
                mov     ebx, edi
                mov     ebp, esi
                lea     edi, [ecx+ebx]
                sub     ebp, ebx
                lea     ecx, [ecx+0]

loc_4CBF80:                             ; CODE XREF: sub_4CBEC0+D1j
                mov     bl, [edi+ebp]
                cmp     bl, [edi]
                jnz     short loc_4CBF93
                add     ecx, 1
                add     edi, 1
                cmp     ecx, [esp+20h+arg_0]
                jnz     short loc_4CBF80

loc_4CBF93:                             ; CODE XREF: sub_4CBEC0+A1j
                                        ; sub_4CBEC0+A9j ...
                cmp     [esp+20h+arg_24], ecx
                jnb     short loc_4CBFB8
                mov     edi, [esp+20h+arg_20]
                mov     [edi], ecx
                add     edi, 4
                add     edx, 0FFFFFFFFh
                mov     [edi], edx
                add     edi, 4
                cmp     ecx, [esp+20h+arg_0]
                mov     [esp+20h+arg_24], ecx
                mov     [esp+20h+arg_20], edi
                jz      short loc_4CC016

loc_4CBFB8:                             ; CODE XREF: sub_4CBEC0+98j
                                        ; sub_4CBEC0+D7j
                mov     dl, [ecx+esi]
                mov     esi, [esp+20h+arg_C]
                cmp     dl, [ecx+esi]
                mov     edx, [esp+20h+arg_4]
                jnb     short loc_4CBFE4
                mov     esi, [esp+20h+var_10]
                lea     ebp, [eax+4]
                mov     ebx, ecx
                mov     ecx, [esp+20h+var_8]
                mov     [esi], edx
                mov     eax, [ebp+0]
                mov     [esp+20h+var_10], ebp
                mov     [esp+20h+var_4], ebx
                jmp     short loc_4CBFFC
; ---------------------------------------------------------------------------

loc_4CBFE4:                             ; CODE XREF: sub_4CBEC0+106j
                mov     esi, [esp+20h+var_C]
                mov     ebp, [esp+20h+var_10]
                mov     ebx, [esp+20h+var_4]
                mov     [esi], edx
                mov     [esp+20h+var_C], eax
                mov     eax, [eax]
                mov     [esp+20h+var_8], ecx

loc_4CBFFC:                             ; CODE XREF: sub_4CBEC0+122j
                mov     edx, [esp+20h+arg_8]
                sub     edx, eax
                cmp     [esp+20h+arg_1C], 0
                mov     [esp+20h+arg_4], eax
                jnz     loc_4CBF20
                jmp     loc_4CBEF9
; ---------------------------------------------------------------------------

loc_4CC016:                             ; CODE XREF: sub_4CBEC0+F6j
                mov     ecx, [eax]
                mov     edx, [esp+20h+var_10]
                mov     [edx], ecx
                mov     eax, [eax+4]
                mov     ecx, [esp+20h+var_C]
                mov     [ecx], eax
                mov     eax, edi
                pop     edi
                pop     esi
                pop     ebp
                pop     ebx
                add     esp, 10h
                retn
sub_4CBEC0      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================


sub_4CC040      proc near               ; CODE XREF: sub_4CC220+F8p
                                        ; sub_4CC3B0+173p ...

var_10          = dword ptr -10h
var_C           = dword ptr -0Ch
var_8           = dword ptr -8
var_4           = dword ptr -4
arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch
arg_C           = dword ptr  10h
arg_10          = dword ptr  14h
arg_14          = dword ptr  18h
arg_18          = dword ptr  1Ch
arg_1C          = dword ptr  20h

                sub     esp, 10h
                mov     eax, [esp+10h+arg_10]
                mov     edx, [esp+10h+arg_4]
                push    ebx
                push    ebp
                push    esi
                mov     esi, [esp+1Ch+arg_14]
                lea     eax, [eax+esi*8]
                lea     ecx, [eax+4]
                push    edi
                mov     edi, eax
                mov     eax, [esp+20h+arg_8]
                xor     ebx, ebx
                xor     ebp, ebp
                sub     eax, edx
                cmp     [esp+20h+arg_1C], ebx
                mov     [esp+20h+var_C], ecx
                mov     [esp+20h+var_10], edi
                mov     [esp+20h+var_8], ebx
                mov     [esp+20h+var_4], ebp
                jz      loc_4CC159
                nop

loc_4CC080:                             ; CODE XREF: sub_4CC040+114j
                sub     [esp+20h+arg_1C], 1
                cmp     eax, [esp+20h+arg_18]
                jnb     loc_4CC159
                cmp     esi, eax
                sbb     ecx, ecx
                and     ecx, [esp+20h+arg_18]
                sub     ecx, eax
                add     ecx, esi
                mov     esi, [esp+20h+arg_10]
                lea     edi, [esi+ecx*8]
                mov     ecx, [esp+20h+arg_C]
                sub     ecx, eax
                cmp     ebx, ebp
                mov     eax, ebx
                jb      short loc_4CC0B0
                mov     eax, ebp

loc_4CC0B0:                             ; CODE XREF: sub_4CC040+6Cj
                mov     bl, [eax+ecx]
                mov     esi, [esp+20h+arg_C]
                cmp     bl, [eax+esi]
                jnz     short loc_4CC102
                add     eax, 1
                cmp     eax, [esp+20h+arg_0]
                jz      short loc_4CC0E3
                mov     ebx, esi
                mov     ebp, ecx
                lea     esi, [eax+ebx]
                sub     ebp, ebx
                mov     edi, edi

loc_4CC0D0:                             ; CODE XREF: sub_4CC040+A1j
                mov     bl, [esi+ebp]
                cmp     bl, [esi]
                jnz     short loc_4CC0FC
                add     eax, 1
                add     esi, 1
                cmp     eax, [esp+20h+arg_0]
                jnz     short loc_4CC0D0

loc_4CC0E3:                             ; CODE XREF: sub_4CC040+83j
                                        ; sub_4CC040+C0j
                mov     edx, [edi]
                mov     eax, [esp+20h+var_10]
                mov     [eax], edx
                mov     ecx, [edi+4]
                mov     edx, [esp+20h+var_C]
                pop     edi
                pop     esi
                pop     ebp
                mov     [edx], ecx
                pop     ebx
                add     esp, 10h
                retn
; ---------------------------------------------------------------------------

loc_4CC0FC:                             ; CODE XREF: sub_4CC040+95j
                cmp     eax, [esp+20h+arg_0]
                jz      short loc_4CC0E3

loc_4CC102:                             ; CODE XREF: sub_4CC040+7Aj
                mov     cl, [eax+ecx]
                mov     esi, [esp+20h+arg_C]
                cmp     cl, [eax+esi]
                jnb     short loc_4CC129
                mov     ecx, [esp+20h+var_10]
                mov     ebx, [esp+20h+var_8]
                add     edi, 4
                mov     ebp, eax
                mov     [ecx], edx
                mov     edx, [edi]
                mov     [esp+20h+var_10], edi
                mov     [esp+20h+var_4], ebp
                jmp     short loc_4CC143
; ---------------------------------------------------------------------------

loc_4CC129:                             ; CODE XREF: sub_4CC040+CCj
                mov     ecx, [esp+20h+var_C]
                mov     ebp, [esp+20h+var_4]
                mov     [ecx], edx
                mov     edx, [edi]
                mov     ebx, eax
                mov     [esp+20h+var_C], edi
                mov     edi, [esp+20h+var_10]
                mov     [esp+20h+var_8], ebx

loc_4CC143:                             ; CODE XREF: sub_4CC040+E7j
                mov     eax, [esp+20h+arg_8]
                sub     eax, edx
                cmp     [esp+20h+arg_1C], 0
                jz      short loc_4CC159
                mov     esi, [esp+20h+arg_14]
                jmp     loc_4CC080
; ---------------------------------------------------------------------------

loc_4CC159:                             ; CODE XREF: sub_4CC040+39j
                                        ; sub_4CC040+49j ...
                mov     eax, [esp+20h+var_C]
                mov     dword ptr [edi], 0
                pop     edi
                pop     esi
                pop     ebp
                mov     dword ptr [eax], 0
                pop     ebx
                add     esp, 10h
                retn
sub_4CC040      endp

; ---------------------------------------------------------------------------
                align 10h

loc_4CC180:                             ; DATA XREF: sub_4CCAA0+40o
                push    esi
                mov     esi, [esp+8]
                mov     edx, [esi+10h]
                cmp     edx, 2
                jnb     short loc_4CC1AD
                add     dword ptr [esi+4], 1
                mov     eax, [esi+4]
                add     dword ptr [esi+14h], 1
                add     dword ptr [esi], 1
                cmp     eax, [esi+8]
                jnz     short loc_4CC1A9
                push    esi
                call    sub_4CBD50
                add     esp, 4

loc_4CC1A9:                             ; CODE XREF: .text:004CC19Ej
                xor     eax, eax
                pop     esi
                retn
; ---------------------------------------------------------------------------

loc_4CC1AD:                             ; CODE XREF: .text:004CC18Bj
                mov     eax, [esi]
                xor     ecx, ecx
                mov     ch, [eax+1]
                push    ebx
                mov     ebx, [esp+10h]
                push    edi
                mov     edi, [esi+4]
                push    1
                push    ebx
                mov     cl, [eax]
                mov     eax, ecx
                mov     ecx, [esi+20h]
                lea     eax, [ecx+eax*4]
                mov     ecx, [eax]
                mov     [eax], edi
                mov     eax, [esi+2Ch]
                push    eax
                mov     eax, [esi+18h]
                push    eax
                mov     eax, [esi+14h]
                push    eax
                mov     eax, [esi+24h]
                push    eax
                mov     eax, [esi]
                push    eax
                mov     eax, [esi+4]
                push    eax
                push    ecx
                push    edx
                call    sub_4CBEC0
                add     dword ptr [esi+4], 1
                add     dword ptr [esi+14h], 1
                add     dword ptr [esi], 1
                mov     edi, eax
                mov     eax, [esi+4]
                sub     edi, ebx
                add     esp, 28h
                sar     edi, 2
                cmp     eax, [esi+8]
                jnz     short loc_4CC212
                push    esi
                call    sub_4CBD50
                add     esp, 4

loc_4CC212:                             ; CODE XREF: .text:004CC207j
                mov     eax, edi
                pop     edi
                pop     ebx
                pop     esi
                retn

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CC220      proc near               ; DATA XREF: sub_4CCAA0+54o

var_8           = dword ptr -8
var_4           = dword ptr -4
arg_0           = dword ptr  4
arg_4           = dword ptr  8

                sub     esp, 8
                push    esi
                mov     esi, [esp+0Ch+arg_0]
                mov     eax, [esi+10h]
                cmp     eax, 3
                mov     [esp+0Ch+arg_0], eax
                jnb     short loc_4CC259
                mov     eax, 1
                add     [esi+14h], eax
                add     [esi], eax
                add     [esi+4], eax
                mov     eax, [esi+4]
                cmp     eax, [esi+8]
                jnz     short loc_4CC252
                push    esi
                call    sub_4CBD50
                add     esp, 4

loc_4CC252:                             ; CODE XREF: sub_4CC220+27j
                xor     eax, eax
                pop     esi
                add     esp, 8
                retn
; ---------------------------------------------------------------------------

loc_4CC259:                             ; CODE XREF: sub_4CC220+12j
                push    ebx
                mov     ebx, [esi+20h]
                push    ebp
                xor     edx, edx
                push    edi
                mov     edi, [esi]
                mov     dh, [edi+2]
                movzx   ecx, byte ptr [edi]
                movzx   eax, byte ptr [edi+1]
                xor     eax, dword_553198[ecx*4]
                xor     edx, eax
                and     edx, [esi+28h]
                mov     ecx, eax
                mov     ebp, [ebx+edx*4+1000h]
                mov     eax, [esi+4]
                and     ecx, 3FFh
                sub     eax, [ebx+ecx*4]
                mov     [esp+18h+var_8], ebp
                mov     ebp, [esi+4]
                mov     [ebx+edx*4+1000h], ebp
                mov     ebx, [esi+20h]
                mov     edx, [ebx+edx*4+1000h]
                mov     [ebx+ecx*4], edx
                mov     ebx, [esp+18h+arg_4]
                xor     ebp, ebp
                cmp     eax, [esi+18h]
                mov     ecx, 2
                jnb     loc_4CC348
                mov     edx, edi
                sub     edx, eax
                mov     [esp+18h+var_4], edx
                mov     dl, [edx]
                cmp     dl, [edi]
                jnz     short loc_4CC348
                mov     edx, [esp+18h+arg_0]
                cmp     edx, ecx
                jz      short loc_4CC2EA

loc_4CC2D3:                             ; CODE XREF: sub_4CC220+C4j
                mov     ebx, [esp+18h+var_4]
                mov     bl, [ebx+ecx]
                cmp     bl, [ecx+edi]
                jnz     short loc_4CC2E6
                add     ecx, 1
                cmp     ecx, edx
                jnz     short loc_4CC2D3

loc_4CC2E6:                             ; CODE XREF: sub_4CC220+BDj
                mov     ebx, [esp+18h+arg_4]

loc_4CC2EA:                             ; CODE XREF: sub_4CC220+B1j
                add     eax, 0FFFFFFFFh
                cmp     ecx, edx
                mov     [ebx], ecx
                mov     [ebx+4], eax
                mov     ebp, 2
                jnz     short loc_4CC34C
                mov     eax, [esi+2Ch]
                mov     ecx, [esi+18h]
                push    eax
                mov     eax, [esi+14h]
                push    ecx
                mov     ecx, [esi+24h]
                push    eax
                mov     eax, [esi]
                push    ecx
                mov     ecx, [esi+4]
                push    eax
                mov     eax, [esp+2Ch+var_8]
                push    ecx
                push    eax
                push    edx
                call    sub_4CC040
                mov     eax, 1
                add     [esi+14h], eax
                add     [esi], eax
                add     [esi+4], eax
                mov     eax, [esi+4]
                add     esp, 20h
                cmp     eax, [esi+8]
                jnz     short loc_4CC33E
                push    esi
                call    sub_4CBD50
                add     esp, 4

loc_4CC33E:                             ; CODE XREF: sub_4CC220+113j
                pop     edi
                mov     eax, ebp
                pop     ebp
                pop     ebx
                pop     esi
                add     esp, 8
                retn
; ---------------------------------------------------------------------------

loc_4CC348:                             ; CODE XREF: sub_4CC220+97j
                                        ; sub_4CC220+A9j
                mov     edx, [esp+18h+arg_0]

loc_4CC34C:                             ; CODE XREF: sub_4CC220+D9j
                mov     eax, [esi+2Ch]
                push    ecx
                lea     ecx, [ebx+ebp*4]
                push    ecx
                mov     ecx, [esi+18h]
                push    eax
                mov     eax, [esi+14h]
                push    ecx
                mov     ecx, [esi+24h]
                push    eax
                mov     eax, [esi]
                push    ecx
                mov     ecx, [esi+4]
                push    eax
                mov     eax, [esp+34h+var_8]
                push    ecx
                push    eax
                push    edx
                call    sub_4CBEC0
                mov     edi, eax
                mov     eax, 1
                add     [esi+14h], eax
                add     [esi], eax
                add     [esi+4], eax
                mov     eax, [esi+4]
                sub     edi, ebx
                add     esp, 28h
                sar     edi, 2
                cmp     eax, [esi+8]
                jnz     short loc_4CC39B
                push    esi
                call    sub_4CBD50
                add     esp, 4

loc_4CC39B:                             ; CODE XREF: sub_4CC220+170j
                mov     eax, edi
                pop     edi
                pop     ebp
                pop     ebx
                pop     esi
                add     esp, 8
                retn
sub_4CC220      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CC3B0      proc near               ; DATA XREF: sub_4CCAA0:loc_4CCB03o

var_10          = dword ptr -10h
var_8           = dword ptr -8
var_4           = dword ptr -4
arg_0           = dword ptr  4
arg_4           = dword ptr  8

                sub     esp, 10h
                push    esi
                mov     esi, [esp+14h+arg_0]
                mov     eax, [esi+10h]
                cmp     eax, 4
                mov     [esp+14h+arg_0], eax
                jnb     short loc_4CC3E9
                mov     eax, 1
                add     [esi+14h], eax
                add     [esi], eax
                add     [esi+4], eax
                mov     eax, [esi+4]
                cmp     eax, [esi+8]
                jnz     short loc_4CC3E2
                push    esi
                call    sub_4CBD50
                add     esp, 4

loc_4CC3E2:                             ; CODE XREF: sub_4CC3B0+27j
                xor     eax, eax
                pop     esi
                add     esp, 10h
                retn
; ---------------------------------------------------------------------------

loc_4CC3E9:                             ; CODE XREF: sub_4CC3B0+12j
                push    ebx
                push    ebp
                push    edi
                mov     edi, [esi]
                movzx   eax, byte ptr [edi]
                movzx   edx, byte ptr [edi+1]
                xor     edx, dword_553198[eax*4]
                movzx   eax, byte ptr [edi+2]
                movzx   ebp, byte ptr [edi+3]
                mov     ecx, eax
                add     eax, eax
                add     eax, eax
                add     eax, eax
                xor     eax, dword_553198[ebp*4]
                mov     ebp, [esi+4]
                shl     eax, 5
                shl     ecx, 8
                xor     eax, edx
                and     eax, [esi+28h]
                xor     ecx, edx
                mov     ebx, edx
                mov     edx, [esi+20h]
                and     ebx, 3FFh
                sub     ebp, [edx+ebx*4]
                and     ecx, 0FFFFh
                mov     [esp+20h+var_4], ebp
                mov     ebp, [esi+4]
                sub     ebp, [edx+ecx*4+1000h]
                mov     [esp+20h+var_10], ebp
                mov     ebp, [edx+eax*4+41000h]
                mov     [esp+20h+var_8], ebp
                mov     ebp, [esi+4]
                mov     [edx+eax*4+41000h], ebp
                mov     edx, [esi+20h]
                mov     eax, [edx+eax*4+41000h]
                mov     [edx+ecx*4+1000h], eax
                mov     eax, [esi+20h]
                mov     ecx, [eax+ecx*4+1000h]
                mov     [eax+ebx*4], ecx
                mov     ecx, [esp+20h+var_4]
                mov     ebx, [esp+20h+arg_4]
                xor     ebp, ebp
                cmp     ecx, [esi+18h]
                mov     eax, 1
                jnb     short loc_4CC4A9
                mov     edx, edi
                sub     edx, ecx
                mov     dl, [edx]
                cmp     dl, [edi]
                jnz     short loc_4CC4A9
                mov     eax, 2
                lea     edx, [ecx-1]
                mov     [ebx], eax
                mov     [ebx+4], edx
                mov     ebp, eax

loc_4CC4A9:                             ; CODE XREF: sub_4CC3B0+DEj
                                        ; sub_4CC3B0+E8j
                mov     edx, [esp+20h+var_10]
                cmp     ecx, edx
                jz      short loc_4CC4D5
                cmp     edx, [esi+18h]
                jnb     short loc_4CC4D5
                mov     edx, edi
                sub     edx, [esp+20h+var_10]
                mov     dl, [edx]
                cmp     dl, [edi]
                jnz     short loc_4CC4D5
                mov     ecx, [esp+20h+var_10]
                lea     edx, [ecx-1]
                mov     [ebx+ebp*4+4], edx
                mov     eax, 3
                add     ebp, 2

loc_4CC4D5:                             ; CODE XREF: sub_4CC3B0+FFj
                                        ; sub_4CC3B0+104j ...
                test    ebp, ebp
                mov     edx, [esp+20h+arg_0]
                jz      short loc_4CC553
                cmp     eax, edx
                jz      short loc_4CC4FE
                mov     edx, eax
                sub     edx, ecx
                add     edx, edi

loc_4CC4E7:                             ; CODE XREF: sub_4CC3B0+148j
                mov     cl, [edx]
                cmp     cl, [eax+edi]
                jnz     short loc_4CC4FA
                add     eax, 1
                add     edx, 1
                cmp     eax, [esp+20h+arg_0]
                jnz     short loc_4CC4E7

loc_4CC4FA:                             ; CODE XREF: sub_4CC3B0+13Cj
                mov     edx, [esp+20h+arg_0]

loc_4CC4FE:                             ; CODE XREF: sub_4CC3B0+12Fj
                cmp     eax, edx
                mov     [ebx+ebp*4-8], eax
                jnz     short loc_4CC553
                mov     eax, [esi+2Ch]
                mov     ecx, [esi+18h]
                push    eax
                mov     eax, [esi+14h]
                push    ecx
                mov     ecx, [esi+24h]
                push    eax
                mov     eax, [esi]
                push    ecx
                mov     ecx, [esi+4]
                push    eax
                mov     eax, [esp+34h+var_8]
                push    ecx
                push    eax
                push    edx
                call    sub_4CC040
                mov     eax, 1
                add     [esi+14h], eax
                add     [esi], eax
                add     [esi+4], eax
                mov     eax, [esi+4]
                add     esp, 20h
                cmp     eax, [esi+8]
                jnz     short loc_4CC549
                push    esi
                call    sub_4CBD50
                add     esp, 4

loc_4CC549:                             ; CODE XREF: sub_4CC3B0+18Ej
                pop     edi
                mov     eax, ebp
                pop     ebp
                pop     ebx
                pop     esi
                add     esp, 10h
                retn
; ---------------------------------------------------------------------------

loc_4CC553:                             ; CODE XREF: sub_4CC3B0+12Bj
                                        ; sub_4CC3B0+154j
                cmp     eax, 3
                jnb     short loc_4CC55D
                mov     eax, 3

loc_4CC55D:                             ; CODE XREF: sub_4CC3B0+1A6j
                push    eax
                mov     eax, [esi+2Ch]
                lea     ecx, [ebx+ebp*4]
                push    ecx
                mov     ecx, [esi+18h]
                push    eax
                mov     eax, [esi+14h]
                push    ecx
                mov     ecx, [esi+24h]
                push    eax
                mov     eax, [esi]
                push    ecx
                mov     ecx, [esi+4]
                push    eax
                mov     eax, [esp+3Ch+var_8]
                push    ecx
                push    eax
                push    edx
                call    sub_4CBEC0
                mov     edi, eax
                mov     eax, 1
                add     [esi+14h], eax
                add     [esi], eax
                add     [esi+4], eax
                mov     eax, [esi+4]
                sub     edi, ebx
                add     esp, 28h
                sar     edi, 2
                cmp     eax, [esi+8]
                jnz     short loc_4CC5AC
                push    esi
                call    sub_4CBD50
                add     esp, 4

loc_4CC5AC:                             ; CODE XREF: sub_4CC3B0+1F1j
                mov     eax, edi
                pop     edi
                pop     ebp
                pop     ebx
                pop     esi
                add     esp, 10h
                retn
sub_4CC3B0      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CC5C0      proc near               ; DATA XREF: sub_4CCAA0+29o

var_10          = dword ptr -10h
var_8           = dword ptr -8
var_4           = dword ptr -4
arg_0           = dword ptr  4
arg_4           = dword ptr  8

                sub     esp, 10h
                push    esi
                mov     esi, [esp+14h+arg_0]
                mov     eax, [esi+10h]
                cmp     eax, 4
                mov     [esp+14h+arg_0], eax
                jnb     short loc_4CC5F9
                mov     eax, 1
                add     [esi+14h], eax
                add     [esi], eax
                add     [esi+4], eax
                mov     eax, [esi+4]
                cmp     eax, [esi+8]
                jnz     short loc_4CC5F2
                push    esi
                call    sub_4CBD50
                add     esp, 4

loc_4CC5F2:                             ; CODE XREF: sub_4CC5C0+27j
                xor     eax, eax
                pop     esi
                add     esp, 10h
                retn
; ---------------------------------------------------------------------------

loc_4CC5F9:                             ; CODE XREF: sub_4CC5C0+12j
                push    ebx
                push    ebp
                push    edi
                mov     edi, [esi]
                movzx   eax, byte ptr [edi]
                movzx   edx, byte ptr [edi+1]
                xor     edx, dword_553198[eax*4]
                movzx   eax, byte ptr [edi+2]
                movzx   ebp, byte ptr [edi+3]
                mov     ecx, eax
                add     eax, eax
                add     eax, eax
                add     eax, eax
                xor     eax, dword_553198[ebp*4]
                mov     ebp, [esi+4]
                shl     eax, 5
                shl     ecx, 8
                xor     eax, edx
                and     eax, [esi+28h]
                xor     ecx, edx
                mov     ebx, edx
                mov     edx, [esi+20h]
                and     ebx, 3FFh
                sub     ebp, [edx+ebx*4]
                and     ecx, 0FFFFh
                mov     [esp+20h+var_4], ebp
                mov     ebp, [esi+4]
                sub     ebp, [edx+ecx*4+1000h]
                mov     [esp+20h+var_10], ebp
                mov     ebp, [edx+eax*4+41000h]
                mov     [esp+20h+var_8], ebp
                mov     ebp, [esi+4]
                mov     [edx+eax*4+41000h], ebp
                mov     edx, [esi+20h]
                mov     eax, [edx+eax*4+41000h]
                mov     [edx+ecx*4+1000h], eax
                mov     eax, [esi+20h]
                mov     ecx, [eax+ecx*4+1000h]
                mov     [eax+ebx*4], ecx
                mov     ecx, [esp+20h+var_4]
                mov     ebx, [esp+20h+arg_4]
                xor     ebp, ebp
                cmp     ecx, [esi+18h]
                mov     eax, 1
                jnb     short loc_4CC6B9
                mov     edx, edi
                sub     edx, ecx
                mov     dl, [edx]
                cmp     dl, [edi]
                jnz     short loc_4CC6B9
                mov     eax, 2
                lea     edx, [ecx-1]
                mov     [ebx], eax
                mov     [ebx+4], edx
                mov     ebp, eax

loc_4CC6B9:                             ; CODE XREF: sub_4CC5C0+DEj
                                        ; sub_4CC5C0+E8j
                mov     edx, [esp+20h+var_10]
                cmp     ecx, edx
                jz      short loc_4CC6E5
                cmp     edx, [esi+18h]
                jnb     short loc_4CC6E5
                mov     edx, edi
                sub     edx, [esp+20h+var_10]
                mov     dl, [edx]
                cmp     dl, [edi]
                jnz     short loc_4CC6E5
                mov     ecx, [esp+20h+var_10]
                lea     edx, [ecx-1]
                mov     [ebx+ebp*4+4], edx
                mov     eax, 3
                add     ebp, 2

loc_4CC6E5:                             ; CODE XREF: sub_4CC5C0+FFj
                                        ; sub_4CC5C0+104j ...
                test    ebp, ebp
                jz      short loc_4CC747
                cmp     eax, [esp+20h+arg_0]
                jz      short loc_4CC708
                mov     edx, eax
                sub     edx, ecx
                add     edx, edi

loc_4CC6F5:                             ; CODE XREF: sub_4CC5C0+146j
                mov     cl, [edx]
                cmp     cl, [eax+edi]
                jnz     short loc_4CC708
                add     eax, 1
                add     edx, 1
                cmp     eax, [esp+20h+arg_0]
                jnz     short loc_4CC6F5

loc_4CC708:                             ; CODE XREF: sub_4CC5C0+12Dj
                                        ; sub_4CC5C0+13Aj
                cmp     eax, [esp+20h+arg_0]
                mov     [ebx+ebp*4-8], eax
                jnz     short loc_4CC747
                mov     edx, [esi+14h]
                mov     eax, [esi+24h]
                mov     ecx, [esp+20h+var_8]
                mov     [eax+edx*4], ecx
                mov     eax, 1
                add     [esi+14h], eax
                add     [esi], eax
                add     [esi+4], eax
                mov     eax, [esi+4]
                cmp     eax, [esi+8]
                jnz     short loc_4CC73D
                push    esi
                call    sub_4CBD50
                add     esp, 4

loc_4CC73D:                             ; CODE XREF: sub_4CC5C0+172j
                pop     edi
                mov     eax, ebp
                pop     ebp
                pop     ebx
                pop     esi
                add     esp, 10h
                retn
; ---------------------------------------------------------------------------

loc_4CC747:                             ; CODE XREF: sub_4CC5C0+127j
                                        ; sub_4CC5C0+150j
                cmp     eax, 3
                jnb     short loc_4CC751
                mov     eax, 3

loc_4CC751:                             ; CODE XREF: sub_4CC5C0+18Aj
                mov     ecx, [esi+18h]
                push    eax
                mov     eax, [esi+2Ch]
                lea     edx, [ebx+ebp*4]
                push    edx
                mov     edx, [esi+14h]
                push    eax
                mov     eax, [esi+24h]
                push    ecx
                mov     ecx, [esi]
                push    edx
                mov     edx, [esi+4]
                push    eax
                mov     eax, [esp+38h+var_8]
                push    ecx
                mov     ecx, [esp+3Ch+arg_0]
                push    edx
                push    eax
                push    ecx
                call    sub_4CBDE0
                mov     edi, eax
                mov     eax, 1
                add     [esi+14h], eax
                add     [esi], eax
                add     [esi+4], eax
                mov     eax, [esi+4]
                sub     edi, ebx
                add     esp, 28h
                sar     edi, 2
                cmp     eax, [esi+8]
                jnz     short loc_4CC7A4
                push    esi
                call    sub_4CBD50
                add     esp, 4

loc_4CC7A4:                             ; CODE XREF: sub_4CC5C0+1D9j
                mov     eax, edi
                pop     edi
                pop     ebp
                pop     ebx
                pop     esi
                add     esp, 10h
                retn
sub_4CC5C0      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CC7B0      proc near               ; DATA XREF: sub_4CCAA0+47o

arg_0           = dword ptr  4
arg_4           = dword ptr  8

                push    ebx
                push    ebp
                mov     ebp, [esp+8+arg_4]
                push    esi
                mov     esi, [esp+0Ch+arg_0]
                push    edi
                mov     edi, 1

loc_4CC7C1:                             ; CODE XREF: sub_4CC7B0+6Dj
                mov     edx, [esi+10h]
                cmp     edx, 2
                jb      short loc_4CC802
                mov     eax, [esi]
                mov     ebx, [esi+4]
                xor     ecx, ecx
                mov     ch, [eax+1]
                mov     cl, [eax]
                mov     eax, ecx
                mov     ecx, [esi+20h]
                lea     eax, [ecx+eax*4]
                mov     ecx, [eax]
                mov     [eax], ebx
                mov     eax, [esi+2Ch]
                push    eax
                mov     eax, [esi+18h]
                push    eax
                mov     eax, [esi+14h]
                push    eax
                mov     eax, [esi+24h]
                push    eax
                mov     eax, [esi]
                push    eax
                mov     eax, [esi+4]
                push    eax
                push    ecx
                push    edx
                call    sub_4CC040
                add     esp, 20h

loc_4CC802:                             ; CODE XREF: sub_4CC7B0+17j
                add     [esi+4], edi
                mov     eax, [esi+4]
                add     [esi+14h], edi
                add     [esi], edi
                cmp     eax, [esi+8]
                jnz     short loc_4CC81B
                push    esi
                call    sub_4CBD50
                add     esp, 4

loc_4CC81B:                             ; CODE XREF: sub_4CC7B0+60j
                sub     ebp, edi
                jnz     short loc_4CC7C1
                pop     edi
                pop     esi
                pop     ebp
                pop     ebx
                retn
sub_4CC7B0      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CC830      proc near               ; DATA XREF: sub_4CCAA0+5Bo

arg_0           = dword ptr  4
arg_4           = dword ptr  8

                push    ebx
                push    ebp
                push    esi
                mov     esi, [esp+0Ch+arg_0]
                push    edi
                mov     edi, 1
                lea     ecx, [ecx+0]

loc_4CC840:                             ; CODE XREF: sub_4CC830+9Fj
                mov     ebp, [esi+10h]
                cmp     ebp, 3
                jb      short loc_4CC8B2
                mov     ecx, [esi]
                movzx   edx, byte ptr [ecx]
                movzx   eax, byte ptr [ecx+1]
                xor     eax, dword_553198[edx*4]
                mov     ebx, [esi+4]
                xor     edx, edx
                mov     dh, [ecx+2]
                xor     edx, eax
                and     edx, [esi+28h]
                and     eax, 3FFh
                mov     ecx, edx
                mov     edx, [esi+20h]
                mov     edi, [edx+ecx*4+1000h]
                lea     edx, [edx+ecx*4+1000h]
                mov     [edx], ebx
                mov     edx, [esi+20h]
                mov     ecx, [edx+ecx*4+1000h]
                mov     [edx+eax*4], ecx
                mov     edx, [esi+2Ch]
                mov     eax, [esi+18h]
                mov     ecx, [esi+14h]
                push    edx
                mov     edx, [esi+24h]
                push    eax
                mov     eax, [esi]
                push    ecx
                mov     ecx, [esi+4]
                push    edx
                push    eax
                push    ecx
                push    edi
                push    ebp
                call    sub_4CC040
                add     esp, 20h
                mov     edi, 1

loc_4CC8B2:                             ; CODE XREF: sub_4CC830+16j
                add     [esi+4], edi
                mov     eax, [esi+4]
                add     [esi+14h], edi
                add     [esi], edi
                cmp     eax, [esi+8]
                jnz     short loc_4CC8CB
                push    esi
                call    sub_4CBD50
                add     esp, 4

loc_4CC8CB:                             ; CODE XREF: sub_4CC830+90j
                sub     [esp+10h+arg_4], edi
                jnz     loc_4CC840
                pop     edi
                pop     esi
                pop     ebp
                pop     ebx
                retn
sub_4CC830      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CC8E0      proc near               ; DATA XREF: sub_4CCAA0+6Ao

arg_0           = dword ptr  4
arg_4           = dword ptr  8

                push    ebx
                push    ebp
                push    esi
                mov     esi, [esp+0Ch+arg_0]
                push    edi
                mov     edi, 1
                lea     ecx, [ecx+0]

loc_4CC8F0:                             ; CODE XREF: sub_4CC8E0+D6j
                mov     eax, [esi+10h]
                cmp     eax, 4
                mov     [esp+10h+arg_0], eax
                jb      loc_4CC999
                mov     eax, [esi]
                movzx   edi, byte ptr [eax+2]
                movzx   edx, byte ptr [eax]
                movzx   ebx, byte ptr [eax+3]
                movzx   ecx, byte ptr [eax+1]
                xor     ecx, dword_553198[edx*4]
                mov     ebp, [esi+4]
                lea     eax, ds:0[edi*8]
                xor     eax, dword_553198[ebx*4]
                mov     edx, edi
                mov     edi, [esi+20h]
                shl     eax, 5
                xor     eax, ecx
                and     eax, [esi+28h]
                shl     edx, 8
                mov     ebx, [edi+eax*4+41000h]
                xor     edx, ecx
                and     edx, 0FFFFh
                mov     [edi+edx*4+1000h], ebp
                mov     edi, [esi+20h]
                mov     edx, [edi+edx*4+1000h]
                and     ecx, 3FFh
                mov     [edi+ecx*4], edx
                mov     ecx, [esi+20h]
                mov     edx, [esi+4]
                mov     [ecx+eax*4+41000h], edx
                mov     eax, [esi+2Ch]
                mov     ecx, [esi+18h]
                mov     edx, [esi+14h]
                push    eax
                mov     eax, [esi+24h]
                push    ecx
                mov     ecx, [esi]
                push    edx
                mov     edx, [esi+4]
                push    eax
                mov     eax, [esp+20h+arg_0]
                push    ecx
                push    edx
                push    ebx
                push    eax
                call    sub_4CC040
                add     esp, 20h
                mov     edi, 1

loc_4CC999:                             ; CODE XREF: sub_4CC8E0+1Aj
                add     [esi+4], edi
                mov     eax, [esi+4]
                add     [esi+14h], edi
                add     [esi], edi
                cmp     eax, [esi+8]
                jnz     short loc_4CC9B2
                push    esi
                call    sub_4CBD50
                add     esp, 4

loc_4CC9B2:                             ; CODE XREF: sub_4CC8E0+C7j
                sub     [esp+10h+arg_4], edi
                jnz     loc_4CC8F0
                pop     edi
                pop     esi
                pop     ebp
                pop     ebx
                retn
sub_4CC8E0      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CC9D0      proc near               ; DATA XREF: sub_4CCAA0+30o

arg_0           = dword ptr  4
arg_4           = dword ptr  8

                push    ebx
                push    ebp
                push    esi
                mov     esi, [esp+0Ch+arg_0]
                push    edi
                mov     edi, 1
                lea     ecx, [ecx+0]

loc_4CC9E0:                             ; CODE XREF: sub_4CC9D0+BAj
                cmp     dword ptr [esi+10h], 4
                jb      loc_4CCA6D
                mov     eax, [esi]
                movzx   edi, byte ptr [eax+2]
                movzx   edx, byte ptr [eax]
                movzx   ebx, byte ptr [eax+3]
                movzx   ecx, byte ptr [eax+1]
                xor     ecx, dword_553198[edx*4]
                mov     ebp, [esi+4]
                lea     eax, ds:0[edi*8]
                xor     eax, dword_553198[ebx*4]
                mov     edx, edi
                mov     edi, [esi+20h]
                shl     eax, 5
                xor     eax, ecx
                and     eax, [esi+28h]
                mov     ebx, [edi+eax*4+41000h]
                lea     edi, [edi+eax*4+41000h]
                mov     [edi], ebp
                mov     edi, [esi+20h]
                mov     eax, [edi+eax*4+41000h]
                shl     edx, 8
                xor     edx, ecx
                and     edx, 0FFFFh
                mov     [edi+edx*4+1000h], eax
                mov     eax, [esi+20h]
                mov     edx, [eax+edx*4+1000h]
                and     ecx, 3FFh
                mov     [eax+ecx*4], edx
                mov     eax, [esi+14h]
                mov     ecx, [esi+24h]
                mov     [ecx+eax*4], ebx
                mov     edi, 1

loc_4CCA6D:                             ; CODE XREF: sub_4CC9D0+14j
                add     [esi+4], edi
                mov     eax, [esi+4]
                add     [esi+14h], edi
                add     [esi], edi
                cmp     eax, [esi+8]
                jnz     short loc_4CCA86
                push    esi
                call    sub_4CBD50
                add     esp, 4

loc_4CCA86:                             ; CODE XREF: sub_4CC9D0+ABj
                sub     [esp+10h+arg_4], edi
                jnz     loc_4CC9E0
                pop     edi
                pop     esi
                pop     ebp
                pop     ebx
                retn
sub_4CC9D0      endp

; =============== S U B R O U T I N E =======================================

sub_4CCAA0      proc near               ; CODE XREF: sub_4D0270+F3p

arg_0           = dword ptr  4
arg_4           = dword ptr  8

                mov     eax, [esp+arg_4]
                mov     ecx, [esp+arg_0]
                mov     dword ptr [eax], offset sub_4CBC80
                mov     dword ptr [eax+4], offset loc_4CB960
                mov     dword ptr [eax+8], offset loc_4CB970
                mov     dword ptr [eax+0Ch], offset loc_4CB950
                cmp     dword ptr [ecx+50h], 0
                jnz     short loc_4CCAD8
                mov     dword ptr [eax+10h], offset sub_4CC5C0
                mov     dword ptr [eax+14h], offset sub_4CC9D0
                retn
; ---------------------------------------------------------------------------

loc_4CCAD8:                             ; CODE XREF: sub_4CCAA0+27j
                mov     ecx, [ecx+48h]
                cmp     ecx, 2
                jnz     short loc_4CCAEF
                mov     dword ptr [eax+10h], offset loc_4CC180
                mov     dword ptr [eax+14h], offset sub_4CC7B0
                retn
; ---------------------------------------------------------------------------

loc_4CCAEF:                             ; CODE XREF: sub_4CCAA0+3Ej
                cmp     ecx, 3
                jnz     short loc_4CCB03
                mov     dword ptr [eax+10h], offset sub_4CC220
                mov     dword ptr [eax+14h], offset sub_4CC830
                retn
; ---------------------------------------------------------------------------

loc_4CCB03:                             ; CODE XREF: sub_4CCAA0+52j
                mov     dword ptr [eax+10h], offset sub_4CC3B0
                mov     dword ptr [eax+14h], offset sub_4CC8E0
                retn
sub_4CCAA0      endp

; ---------------------------------------------------------------------------

Interface1_AddRef      proc near               ; DATA XREF: .rdata:00517A94o
;sub_4CCB80

arg_0           = dword ptr  4
                mov     eax, [esp+arg_0]
                add     dword ptr [eax+4], 1
                mov     eax, [eax+4]
                retn    4
Interface1_AddRef      endp

; ---------------------------------------------------------------------------

sub_4CCB20      proc near               ; DATA XREF: .rdata:00517A9Co

arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch
arg_C           = dword ptr  10h

                push    esi
                mov     esi, [esp+4+arg_0]
                mov     ecx, [esi+10h]
                sub     ecx, [esi+18h]
                mov     eax, [esi+14h]
                sbb     eax, [esi+1Ch]
                xor     edx, edx
                cmp     edx, eax
                push    edi
                mov     edi, [esp+8+arg_8]
                jb      short loc_4CCB48
                ja      short loc_4CCB42
                cmp     edi, ecx
                jbe     short loc_4CCB48

loc_4CCB42:                             ; CODE XREF: sub_4CCB20+1Cj
                mov     edi, [esi+10h]
                sub     edi, [esi+18h]

loc_4CCB48:                             ; CODE XREF: sub_4CCB20+1Aj
                                        ; sub_4CCB20+20j
                mov     eax, [esp+8+arg_C]
                test    eax, eax
                jz      short loc_4CCB52
                mov     [eax], edi

loc_4CCB52:                             ; CODE XREF: sub_4CCB20+2Ej
                test    edi, edi
                jz      short loc_4CCB72
                mov     eax, [esi+8]
                add     eax, [esi+18h]
                mov     ecx, [esp+8+arg_4]
                push    edi             ; size_t
                push    eax             ; void *
                push    ecx             ; void *
                call    _memcpy         ; Microsoft VisualC 2-8/net runtime
                add     esp, 0Ch
                add     [esi+18h], edi
                adc     dword ptr [esi+1Ch], 0

loc_4CCB72:                             ; CODE XREF: sub_4CCB20+34j
                pop     edi
                xor     eax, eax
                pop     esi
                retn    10h
sub_4CCB20      endp

; ---------------------------------------------------------------------------

sub_4CCB90      proc near               ; DATA XREF: .rdata:00517AB0o

arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch
arg_C           = dword ptr  10h

                push    ebx
                mov     ebx, [esp+4+arg_8]
                push    esi
                mov     esi, [esp+8+arg_0]
                mov     ecx, [esi+10h]
                mov     eax, [esi+14h]
                push    edi
                xor     edi, edi
                sub     ecx, [esi+18h]
                sbb     eax, [esi+1Ch]
                cmp     edi, eax
                jb      short loc_4CCBC2
                ja      short loc_4CCBB3
                cmp     ebx, ecx
                jbe     short loc_4CCBC2

loc_4CCBB3:                             ; CODE XREF: sub_4CCB90+1Dj
                pop     edi
                mov     byte ptr [esi+20h], 1
                pop     esi
                mov     eax, 80004005h
                pop     ebx
                retn    10h

loc_4CCBC2:                             ; CODE XREF: sub_4CCB90+1Bj
                                        ; sub_4CCB90+21j
                mov     ecx, [esi+8]
                mov     eax, [esp+0Ch+arg_4]
                add     ecx, [esi+18h]
                push    ebx             ; size_t
                push    eax             ; void *
                push    ecx             ; void *
                call    _memcpy         ; Microsoft VisualC 2-8/net runtime
                mov     eax, [esp+18h+arg_C]
                add     esp, 0Ch
                add     [esi+18h], ebx
                adc     [esi+1Ch], edi
                test    eax, eax
                jz      short loc_4CCBE7
                mov     [eax], ebx

loc_4CCBE7:                             ; CODE XREF: sub_4CCB90+53j
                pop     edi
                pop     esi
                xor     eax, eax
                pop     ebx
                retn    10h
sub_4CCB90      endp

; ---------------------------------------------------------------------------
                align 10h
; ---------------------------------------------------------------------------

LzmaProps_Decode proc near              ; CODE XREF: Decompress_lzma_internal+35p
;sub_4CCBF0

propsRes        = dword ptr  4
propsData       = dword ptr  8
propsSize       = dword ptr  0Ch

                cmp     [esp+propsSize], 5   ; LZMA_PROPS_SIZE
                jge     short loc_4CCBFD

loc_4CCBF7:                             ; CODE XREF: LzmaProps_Decode+16j
                mov     eax, 1
                retn
; ---------------------------------------------------------------------------

loc_4CCBFD:                             ; CODE XREF: LzmaProps_Decode+5j
                mov     eax, [esp+propsData]
                mov     cl, [eax]
                cmp     cl, 0E1h        ; 9 * 5 * 5
                jnb     short loc_4CCBF7
                cmp     cl, 2Dh
                push    edi
                mov     edi, [esp+4+propsRes]
                mov     dword ptr [edi+8], 0
                jb      short loc_4CCC40
                push    esi
                movzx   esi, cl
                mov     eax, 6C16C16Dh
                mul     esi
                mov     eax, esi
                sub     eax, edx
                shr     eax, 1
                add     eax, edx
                shr     eax, 5
                movzx   eax, al
                mov     edx, eax
                pop     esi

loc_4CCC35:                             ; CODE XREF: LzmaProps_Decode+4Bj
                add     cl, 0D3h
                sub     eax, 1
                jnz     short loc_4CCC35
                mov     [edi+8], edx

loc_4CCC40:                             ; CODE XREF: LzmaProps_Decode+27j
                cmp     cl, 9
                mov     dword ptr [edi+4], 0
                jb      short loc_4CCC6B
                movzx   edx, cl
                mov     eax, 38E38E39h
                mul     edx
                shr     edx, 1
                movzx   eax, dl
                mov     edx, eax
                lea     ecx, [ecx+0]

loc_4CCC60:                             ; CODE XREF: LzmaProps_Decode+76j
                add     cl, 0F7h
                sub     eax, 1
                jnz     short loc_4CCC60
                mov     [edi+4], edx

loc_4CCC6B:                             ; CODE XREF: LzmaProps_Decode+5Aj
                movzx   eax, cl
                mov     [edi], eax
                xor     eax, eax
                pop     edi
                retn
LzmaProps_Decode endp

sub_4CCC80      proc near               ; CODE XREF: Decompress_lzma_internal+97p

var_3C          = dword ptr -3Ch
var_38          = dword ptr -38h
var_34          = dword ptr -34h
var_30          = dword ptr -30h
var_2C          = dword ptr -2Ch
var_28          = dword ptr -28h
var_24          = dword ptr -24h
var_20          = dword ptr -20h
var_1C          = dword ptr -1Ch
var_18          = dword ptr -18h
var_14          = dword ptr -14h
var_10          = dword ptr -10h
var_C           = dword ptr -0Ch
var_8           = dword ptr -8
var_4           = dword ptr -4
arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch
arg_C           = dword ptr  10h
arg_10          = dword ptr  14h
arg_14          = dword ptr  18h
arg_18          = dword ptr  1Ch

                sub     esp, 3Ch
                mov     eax, [esp+3Ch+arg_0]
                mov     ecx, [eax+8]
                push    ebx
                push    ebp
                mov     ebp, 1
                mov     edx, ebp
                shl     edx, cl
                mov     ecx, [eax+4]
                xor     ebx, ebx
                push    esi
                sub     edx, ebp
                mov     [esp+48h+var_C], edx
                mov     edx, ebp
                shl     edx, cl
                mov     ecx, [esp+48h+arg_C]
                push    edi
                mov     edi, [eax+0Ch]
                sub     edx, ebp
                mov     [esp+4Ch+var_8], edx
                mov     edx, [eax]
                mov     [ecx], ebx
                mov     ecx, [esp+4Ch+arg_18]
                mov     [ecx], ebx
                mov     ecx, [eax+4]
                add     ecx, edx
                mov     eax, 300h
                shl     eax, cl
                mov     [esp+4Ch+var_20], edi
                mov     [esp+4Ch+var_2C], ebx
                mov     byte ptr [esp+4Ch+arg_0], bl
                add     eax, 736h
                mov     [esp+4Ch+var_14], edx
                mov     [esp+4Ch+var_34], ebx
                mov     [esp+4Ch+var_38], ebp
                mov     [esp+4Ch+var_24], ebp
                mov     [esp+4Ch+var_28], ebp
                mov     [esp+4Ch+var_18], ebp
                jz      short loc_4CCD04
                mov     ecx, eax
                shr     ecx, 1
                mov     eax, 4000400h
                rep stosd
                adc     ecx, ecx
                rep stosw

loc_4CCD04:                             ; CODE XREF: sub_4CCC80+72j
                mov     edx, [esp+4Ch+arg_8]
                mov     ecx, [esp+4Ch+arg_4]
                lea     edi, [ecx+edx]
                xor     esi, esi
                or      eax, 0FFFFFFFFh
                mov     [esp+4Ch+var_3C], edi
                xor     edx, edx
                lea     ebx, [ebx+0]

loc_4CCD20:                             ; CODE XREF: sub_4CCC80+BCj
                cmp     ecx, edi
                jz      loc_4CCF0B
                movzx   ebp, byte ptr [ecx]
                shl     esi, 8
                or      esi, ebp
                mov     ebp, 1
                add     edx, ebp
                add     ecx, ebp
                cmp     edx, 5
                jl      short loc_4CCD20
                cmp     [esp+4Ch+arg_14], ebx
                mov     [esp+4Ch+arg_8], ecx
                jbe     loc_4CCFCD
                lea     esp, [esp+0]

loc_4CCD50:                             ; CODE XREF: sub_4CCC80+32Dj
                mov     edx, [esp+4Ch+var_34]
                mov     ecx, [esp+4Ch+var_C]
                and     ecx, [esp+4Ch+var_2C]
                mov     edi, [esp+4Ch+var_20]
                mov     ebx, edx
                shl     ebx, 4
                add     ebx, ecx
                cmp     eax, 1000000h
                lea     ebx, [edi+ebx*2]
                mov     [esp+4Ch+var_1C], ecx
                mov     [esp+4Ch+var_30], ebx
                jnb     short loc_4CCD99
                mov     ecx, [esp+4Ch+arg_8]
                cmp     ecx, [esp+4Ch+var_3C]
                jz      loc_4CD6E2
                movzx   ebp, byte ptr [ecx]
                shl     esi, 8
                shl     eax, 8
                or      esi, ebp
                add     ecx, 1
                mov     [esp+4Ch+arg_8], ecx

loc_4CCD99:                             ; CODE XREF: sub_4CCC80+F7j
                movzx   ebx, word ptr [ebx]
                movzx   ebp, bx
                mov     ecx, eax
                shr     ecx, 0Bh
                imul    ecx, ebp
                cmp     esi, ecx
                jnb     loc_4CCFF4
                mov     edi, [esp+4Ch+var_30]
                mov     eax, ecx
                mov     ecx, 800h
                sub     ecx, ebp
                mov     ebp, [esp+4Ch+var_8]
                sar     ecx, 5
                add     ecx, ebx
                movzx   ebx, byte ptr [esp+4Ch+arg_0]
                mov     [edi], cx
                mov     edi, [esp+4Ch+var_2C]
                mov     ecx, 8
                sub     cl, byte ptr [esp+4Ch+var_14]
                and     ebp, edi
                shr     ebx, cl
                mov     ecx, [esp+4Ch+var_14]
                shl     ebp, cl
                mov     ecx, [esp+4Ch+var_20]
                mov     edx, 1
                add     ebx, ebp
                imul    ebx, 600h
                cmp     [esp+4Ch+var_34], 7
                lea     ebp, [ebx+ecx+0E6Ch]
                mov     [esp+4Ch+var_30], ebp
                jl      loc_4CCEB0
                sub     edi, [esp+4Ch+var_38]
                mov     ecx, [esp+4Ch+arg_10]
                movzx   ebx, byte ptr [edi+ecx]
                jmp     short loc_4CCE20
; ---------------------------------------------------------------------------
                align 10h

loc_4CCE20:                             ; CODE XREF: sub_4CCC80+197j
                                        ; sub_4CCC80+2C6j
                add     ebx, ebx
                mov     [esp+4Ch+var_10], ebx
                and     ebx, 100h
                cmp     eax, 1000000h
                lea     ecx, [ebx+edx]
                lea     ebp, [ebp+ecx*2+200h]
                mov     [esp+4Ch+arg_0], ebp
                jnb     short loc_4CCE61
                mov     ecx, [esp+4Ch+arg_8]
                cmp     ecx, [esp+4Ch+var_3C]
                jz      loc_4CD6E2
                movzx   edi, byte ptr [ecx]
                shl     esi, 8
                shl     eax, 8
                or      esi, edi
                add     ecx, 1
                mov     [esp+4Ch+arg_8], ecx

loc_4CCE61:                             ; CODE XREF: sub_4CCC80+1BFj
                movzx   edi, word ptr [ebp+0]
                movzx   ebp, di
                mov     ecx, eax
                shr     ecx, 0Bh
                imul    ecx, ebp
                cmp     esi, ecx
                jnb     loc_4CCF15
                mov     eax, ecx
                mov     ecx, 800h
                sub     ecx, ebp
                sar     ecx, 5
                add     ecx, edi
                mov     edi, [esp+4Ch+arg_0]
                add     edx, edx
                test    ebx, ebx
                mov     [edi], cx
                jz      loc_4CCF36

loc_4CCE97:                             ; CODE XREF: sub_4CCC80+2B0j
                cmp     edx, 100h
                jge     loc_4CCF70
                mov     ebp, [esp+4Ch+var_30]
                jmp     short loc_4CCEB0
; ---------------------------------------------------------------------------
                align 10h

loc_4CCEB0:                             ; CODE XREF: sub_4CCC80+185j
                                        ; sub_4CCC80+227j ...
                cmp     eax, 1000000h
                lea     ecx, [edx+edx]
                mov     [esp+4Ch+arg_0], ecx
                jnb     short loc_4CCEDE
                mov     edi, [esp+4Ch+arg_8]
                cmp     edi, [esp+4Ch+var_3C]
                jz      loc_4CD6E2
                movzx   ebx, byte ptr [edi]
                shl     esi, 8
                shl     eax, 8
                or      esi, ebx
                add     edi, 1
                mov     [esp+4Ch+arg_8], edi

loc_4CCEDE:                             ; CODE XREF: sub_4CCC80+23Cj
                movzx   edi, word ptr [ecx+ebp]
                movzx   ebx, di
                mov     ecx, eax
                shr     ecx, 0Bh
                imul    ecx, ebx
                cmp     esi, ecx
                jnb     short loc_4CCF4B
                mov     eax, ecx
                mov     ecx, 800h
                sub     ecx, ebx
                sar     ecx, 5
                add     ecx, edi
                mov     edi, [esp+4Ch+arg_0]
                mov     [edi+ebp], cx
                add     edx, edx
                jmp     short loc_4CCF64
; ---------------------------------------------------------------------------

loc_4CCF0B:                             ; CODE XREF: sub_4CCC80+A2j
                pop     edi
                pop     esi
                mov     eax, ebp
                pop     ebp
                pop     ebx
                add     esp, 3Ch
                retn
; ---------------------------------------------------------------------------

loc_4CCF15:                             ; CODE XREF: sub_4CCC80+1F2j
                sub     eax, ecx
                sub     esi, ecx
                mov     cx, di
                shr     cx, 5
                sub     di, cx
                test    ebx, ebx
                mov     ecx, [esp+4Ch+arg_0]
                mov     [ecx], di
                lea     edx, [edx+edx+1]
                jz      loc_4CCE97

loc_4CCF36:                             ; CODE XREF: sub_4CCC80+211j
                cmp     edx, 100h
                jge     short loc_4CCF70
                mov     ebp, [esp+4Ch+var_30]
                mov     ebx, [esp+4Ch+var_10]
                jmp     loc_4CCE20
; ---------------------------------------------------------------------------

loc_4CCF4B:                             ; CODE XREF: sub_4CCC80+26Fj
                mov     dx, di
                shr     dx, 5
                sub     di, dx
                mov     edx, [esp+4Ch+arg_0]
                sub     eax, ecx
                sub     esi, ecx
                mov     [edx+ebp], di
                add     edx, 1

loc_4CCF64:                             ; CODE XREF: sub_4CCC80+289j
                cmp     edx, 100h
                jl      loc_4CCEB0

loc_4CCF70:                             ; CODE XREF: sub_4CCC80+21Dj
                                        ; sub_4CCC80+2BCj
                mov     ecx, [esp+4Ch+var_2C]
                mov     edi, [esp+4Ch+arg_10]
                mov     [ecx+edi], dl
                add     ecx, 1
                mov     [esp+4Ch+var_2C], ecx
                mov     ecx, [esp+4Ch+var_34]
                cmp     ecx, 4
                mov     byte ptr [esp+4Ch+arg_0], dl
                jge     short loc_4CCF99
                mov     [esp+4Ch+var_34], 0
                jmp     short loc_4CCFA5
; ---------------------------------------------------------------------------

loc_4CCF99:                             ; CODE XREF: sub_4CCC80+30Dj
                cmp     ecx, 0Ah
                jge     short loc_4CCFEF
                sub     ecx, 3

loc_4CCFA1:                             ; CODE XREF: sub_4CCC80+372j
                mov     [esp+4Ch+var_34], ecx

loc_4CCFA5:                             ; CODE XREF: sub_4CCC80+317j
                                        ; sub_4CCC80+530j ...
                mov     ecx, [esp+4Ch+var_2C]
                cmp     ecx, [esp+4Ch+arg_14]
                jb      loc_4CCD50

loc_4CCFB3:                             ; CODE XREF: sub_4CCC80+A13j
                                        ; sub_4CCC80+A5Aj
                cmp     eax, 1000000h
                jnb     short loc_4CCFCD
                mov     edx, [esp+4Ch+arg_8]
                cmp     edx, [esp+4Ch+var_3C]
                jz      loc_4CD6E2
                add     [esp+4Ch+arg_8], 1

loc_4CCFCD:                             ; CODE XREF: sub_4CCC80+C6j
                                        ; sub_4CCC80+338j
                mov     eax, [esp+4Ch+arg_8]
                sub     eax, [esp+4Ch+arg_4]
                mov     ecx, [esp+4Ch+arg_C]
                mov     edx, [esp+4Ch+var_2C]
                pop     edi
                mov     [ecx], eax
                mov     eax, [esp+48h+arg_18]
                pop     esi
                pop     ebp
                mov     [eax], edx
                xor     eax, eax
                pop     ebx
                add     esp, 3Ch
                retn
; ---------------------------------------------------------------------------

loc_4CCFEF:                             ; CODE XREF: sub_4CCC80+31Cj
                sub     ecx, 6
                jmp     short loc_4CCFA1
; ---------------------------------------------------------------------------

loc_4CCFF4:                             ; CODE XREF: sub_4CCC80+129j
                sub     eax, ecx
                sub     esi, ecx
                mov     cx, bx
                shr     cx, 5
                sub     bx, cx
                cmp     eax, 1000000h
                mov     ecx, [esp+4Ch+var_30]
                mov     [ecx], bx
                jnb     short loc_4CD030
                mov     ecx, [esp+4Ch+arg_8]
                cmp     ecx, [esp+4Ch+var_3C]
                jz      loc_4CD6E2
                movzx   ebx, byte ptr [ecx]
                shl     esi, 8
                shl     eax, 8
                or      esi, ebx
                add     ecx, 1
                mov     [esp+4Ch+arg_8], ecx

loc_4CD030:                             ; CODE XREF: sub_4CCC80+38Ej
                movzx   ebx, word ptr [edi+edx*2+180h]
                movzx   ebp, bx
                mov     ecx, eax
                shr     ecx, 0Bh
                imul    ecx, ebp
                cmp     esi, ecx
                jnb     short loc_4CD096
                mov     eax, ecx
                mov     ecx, 800h
                sub     ecx, ebp
                sar     ecx, 5
                add     ecx, ebx
                mov     [edi+edx*2+180h], cx
                mov     ecx, [esp+4Ch+var_28]
                mov     ebp, [esp+4Ch+var_1C]
                mov     [esp+4Ch+var_18], ecx
                mov     ecx, [esp+4Ch+var_24]
                mov     [esp+4Ch+var_28], ecx
                mov     ecx, [esp+4Ch+var_38]
                mov     [esp+4Ch+var_24], ecx
                xor     ecx, ecx
                cmp     edx, 7
                setl    cl
                sub     ecx, 1
                and     ecx, 3
                mov     [esp+4Ch+var_34], ecx
                lea     ecx, [edi+664h]
                jmp     loc_4CD30B
; ---------------------------------------------------------------------------

loc_4CD096:                             ; CODE XREF: sub_4CCC80+3C5j
                sub     eax, ecx
                sub     esi, ecx
                mov     cx, bx
                shr     cx, 5
                sub     bx, cx
                cmp     eax, 1000000h
                mov     [edi+edx*2+180h], bx
                jnb     short loc_4CD0D3
                mov     ecx, [esp+4Ch+arg_8]
                cmp     ecx, [esp+4Ch+var_3C]
                jz      loc_4CD6E2
                movzx   ebx, byte ptr [ecx]
                shl     esi, 8
                shl     eax, 8
                or      esi, ebx
                add     ecx, 1
                mov     [esp+4Ch+arg_8], ecx

loc_4CD0D3:                             ; CODE XREF: sub_4CCC80+431j
                movzx   ebx, word ptr [edi+edx*2+198h]
                movzx   ebp, bx
                mov     ecx, eax
                shr     ecx, 0Bh
                imul    ecx, ebp
                cmp     esi, ecx
                mov     [esp+4Ch+arg_0], ebx
                jnb     loc_4CD1D3
                mov     ebx, 800h
                sub     ebx, ebp
                mov     ebp, [esp+4Ch+var_1C]
                sar     ebx, 5
                add     ebx, [esp+4Ch+arg_0]
                mov     eax, ecx
                mov     [edi+edx*2+198h], bx
                lea     ebx, [edx+0Fh]
                shl     ebx, 4
                add     ebx, ebp
                cmp     ecx, 1000000h
                lea     ebx, [edi+ebx*2]
                mov     [esp+4Ch+var_30], ebx
                jnb     short loc_4CD147
                mov     ebx, [esp+4Ch+arg_8]
                cmp     ebx, [esp+4Ch+var_3C]
                jz      loc_4CD6E2
                shl     ecx, 8
                mov     eax, ecx
                movzx   ecx, byte ptr [ebx]
                shl     esi, 8
                or      esi, ecx
                add     ebx, 1
                mov     [esp+4Ch+arg_8], ebx

loc_4CD147:                             ; CODE XREF: sub_4CCC80+4A3j
                mov     ecx, [esp+4Ch+var_30]
                movzx   ecx, word ptr [ecx]
                mov     [esp+4Ch+arg_0], ecx
                movzx   ebx, cx
                mov     ecx, eax
                shr     ecx, 0Bh
                imul    ecx, ebx
                cmp     esi, ecx
                jnb     short loc_4CD1B5
                mov     edi, [esp+4Ch+var_30]
                mov     eax, ecx
                mov     ecx, 800h
                sub     ecx, ebx
                sar     ecx, 5
                add     ecx, [esp+4Ch+arg_0]
                mov     [edi], cx
                mov     edi, [esp+4Ch+var_2C]
                test    edi, edi
                jz      loc_4CD6E2
                xor     ecx, ecx
                cmp     edx, 7
                mov     edx, [esp+4Ch+arg_10]
                setnl   cl
                lea     ecx, [ecx+ecx+9]
                mov     [esp+4Ch+var_34], ecx
                mov     ecx, edi
                sub     ecx, [esp+4Ch+var_38]
                add     edi, 1
                mov     cl, [ecx+edx]
                mov     [edi+edx-1], cl
                mov     byte ptr [esp+4Ch+arg_0], cl
                mov     [esp+4Ch+var_2C], edi
                jmp     loc_4CCFA5
; ---------------------------------------------------------------------------

loc_4CD1B5:                             ; CODE XREF: sub_4CCC80+4DFj
                sub     eax, ecx
                sub     esi, ecx
                mov     ecx, [esp+4Ch+arg_0]
                mov     bx, cx
                shr     bx, 5
                sub     cx, bx
                mov     ebx, [esp+4Ch+var_30]
                mov     [ebx], cx
                jmp     loc_4CD2F0
; ---------------------------------------------------------------------------

loc_4CD1D3:                             ; CODE XREF: sub_4CCC80+46Cj
                sub     eax, ecx
                sub     esi, ecx
                mov     cx, bx
                shr     cx, 5
                sub     bx, cx
                cmp     eax, 1000000h
                mov     [edi+edx*2+198h], bx
                jnb     short loc_4CD210
                mov     ecx, [esp+4Ch+arg_8]
                cmp     ecx, [esp+4Ch+var_3C]
                jz      loc_4CD6E2
                movzx   ebx, byte ptr [ecx]
                shl     esi, 8
                shl     eax, 8
                or      esi, ebx
                add     ecx, 1
                mov     [esp+4Ch+arg_8], ecx

loc_4CD210:                             ; CODE XREF: sub_4CCC80+56Ej
                movzx   ebx, word ptr [edi+edx*2+1B0h]
                movzx   ebp, bx
                mov     ecx, eax
                shr     ecx, 0Bh
                imul    ecx, ebp
                cmp     esi, ecx
                jnb     short loc_4CD246
                mov     eax, ecx
                mov     ecx, 800h
                sub     ecx, ebp
                sar     ecx, 5
                add     ecx, ebx
                mov     [edi+edx*2+1B0h], cx
                mov     ecx, [esp+4Ch+var_24]
                jmp     loc_4CD2E0
; ---------------------------------------------------------------------------

loc_4CD246:                             ; CODE XREF: sub_4CCC80+5A5j
                sub     eax, ecx
                sub     esi, ecx
                mov     cx, bx
                shr     cx, 5
                sub     bx, cx
                cmp     eax, 1000000h
                mov     [edi+edx*2+1B0h], bx
                jnb     short loc_4CD283
                mov     ecx, [esp+4Ch+arg_8]
                cmp     ecx, [esp+4Ch+var_3C]
                jz      loc_4CD6E2
                movzx   ebx, byte ptr [ecx]
                shl     esi, 8
                shl     eax, 8
                or      esi, ebx
                add     ecx, 1
                mov     [esp+4Ch+arg_8], ecx

loc_4CD283:                             ; CODE XREF: sub_4CCC80+5E1j
                movzx   ebx, word ptr [edi+edx*2+1C8h]
                movzx   ebp, bx
                mov     ecx, eax
                shr     ecx, 0Bh
                imul    ecx, ebp
                cmp     esi, ecx
                jnb     short loc_4CD2B6
                mov     eax, ecx
                mov     ecx, 800h
                sub     ecx, ebp
                sar     ecx, 5
                add     ecx, ebx
                mov     [edi+edx*2+1C8h], cx
                mov     ecx, [esp+4Ch+var_28]
                jmp     short loc_4CD2D8
; ---------------------------------------------------------------------------

loc_4CD2B6:                             ; CODE XREF: sub_4CCC80+618j
                sub     eax, ecx
                sub     esi, ecx
                mov     cx, bx
                shr     cx, 5
                sub     bx, cx
                mov     ecx, [esp+4Ch+var_18]
                mov     [edi+edx*2+1C8h], bx
                mov     ebx, [esp+4Ch+var_28]
                mov     [esp+4Ch+var_18], ebx

loc_4CD2D8:                             ; CODE XREF: sub_4CCC80+634j
                mov     ebx, [esp+4Ch+var_24]
                mov     [esp+4Ch+var_28], ebx

loc_4CD2E0:                             ; CODE XREF: sub_4CCC80+5C1j
                mov     ebx, [esp+4Ch+var_38]
                mov     ebp, [esp+4Ch+var_1C]
                mov     [esp+4Ch+var_24], ebx
                mov     [esp+4Ch+var_38], ecx

loc_4CD2F0:                             ; CODE XREF: sub_4CCC80+54Ej
                xor     ecx, ecx
                cmp     edx, 7
                setnl   cl
                sub     ecx, 1
                and     ecx, 0FFFFFFFDh
                add     ecx, 0Bh
                mov     [esp+4Ch+var_34], ecx
                lea     ecx, [edi+0A68h]

loc_4CD30B:                             ; CODE XREF: sub_4CCC80+411j
                cmp     eax, 1000000h
                jnb     short loc_4CD332
                mov     edx, [esp+4Ch+arg_8]
                cmp     edx, [esp+4Ch+var_3C]
                jz      loc_4CD6E2
                movzx   edi, byte ptr [edx]
                shl     esi, 8
                shl     eax, 8
                or      esi, edi
                add     edx, 1
                mov     [esp+4Ch+arg_8], edx

loc_4CD332:                             ; CODE XREF: sub_4CCC80+690j
                movzx   edi, word ptr [ecx]
                movzx   ebx, di
                mov     edx, eax
                shr     edx, 0Bh
                imul    edx, ebx
                cmp     esi, edx
                jnb     short loc_4CD36E
                mov     eax, edx
                mov     edx, 800h
                sub     edx, ebx
                sar     edx, 5
                add     edx, edi
                mov     [ecx], dx
                shl     ebp, 4
                lea     ecx, [ecx+ebp+4]
                mov     [esp+4Ch+var_1C], 0
                mov     edx, 3
                jmp     loc_4CD409
; ---------------------------------------------------------------------------

loc_4CD36E:                             ; CODE XREF: sub_4CCC80+6C2j
                sub     eax, edx
                sub     esi, edx
                mov     dx, di
                shr     dx, 5
                sub     di, dx
                cmp     eax, 1000000h
                mov     [ecx], di
                jnb     short loc_4CD3A6
                mov     edx, [esp+4Ch+arg_8]
                cmp     edx, [esp+4Ch+var_3C]
                jz      loc_4CD6E2
                movzx   edi, byte ptr [edx]
                shl     esi, 8
                shl     eax, 8
                or      esi, edi
                add     edx, 1
                mov     [esp+4Ch+arg_8], edx

loc_4CD3A6:                             ; CODE XREF: sub_4CCC80+704j
                movzx   edx, word ptr [ecx+2]
                movzx   ebx, dx
                mov     edi, eax
                shr     edi, 0Bh
                imul    edi, ebx
                cmp     esi, edi
                jnb     short loc_4CD3E4
                mov     eax, edi
                mov     edi, 800h
                sub     edi, ebx
                sar     edi, 5
                add     edi, edx
                shl     ebp, 4
                mov     [ecx+2], di
                lea     ecx, [ecx+ebp+104h]
                mov     [esp+4Ch+var_1C], 8
                mov     edx, 3
                jmp     short loc_4CD409
; ---------------------------------------------------------------------------

loc_4CD3E4:                             ; CODE XREF: sub_4CCC80+737j
                sub     eax, edi
                sub     esi, edi
                mov     di, dx
                shr     di, 5
                sub     dx, di
                mov     [ecx+2], dx
                add     ecx, 204h
                mov     [esp+4Ch+var_1C], 10h
                mov     edx, 8

loc_4CD409:                             ; CODE XREF: sub_4CCC80+6E9j
                                        ; sub_4CCC80+762j
                mov     [esp+4Ch+arg_0], edx
                mov     [esp+4Ch+var_10], edx
                mov     ebx, 1
                jmp     short loc_4CD420
; ---------------------------------------------------------------------------
                align 10h

loc_4CD420:                             ; CODE XREF: sub_4CCC80+796j
                                        ; sub_4CCC80+819j
                cmp     eax, 1000000h
                mov     edx, [esp+4Ch+arg_8]
                lea     edi, [ebx+ebx]
                mov     [esp+4Ch+var_30], edi
                jnb     short loc_4CD44E
                cmp     edx, [esp+4Ch+var_3C]
                jz      loc_4CD6E2
                movzx   ebp, byte ptr [edx]
                shl     esi, 8
                shl     eax, 8
                or      esi, ebp
                add     edx, 1
                mov     [esp+4Ch+arg_8], edx

loc_4CD44E:                             ; CODE XREF: sub_4CCC80+7B0j
                movzx   edi, word ptr [edi+ecx]
                movzx   ebp, di
                mov     edx, eax
                shr     edx, 0Bh
                imul    edx, ebp
                cmp     esi, edx
                jnb     short loc_4CD47B
                mov     eax, edx
                mov     edx, 800h
                sub     edx, ebp
                sar     edx, 5
                add     edx, edi
                mov     edi, [esp+4Ch+var_30]
                mov     [edi+ecx], dx
                add     ebx, ebx
                jmp     short loc_4CD494
; ---------------------------------------------------------------------------

loc_4CD47B:                             ; CODE XREF: sub_4CCC80+7DFj
                mov     ebx, [esp+4Ch+var_30]
                sub     eax, edx
                sub     esi, edx
                mov     dx, di
                shr     dx, 5
                sub     di, dx
                mov     [ebx+ecx], di
                add     ebx, 1

loc_4CD494:                             ; CODE XREF: sub_4CCC80+7F9j
                sub     [esp+4Ch+var_10], 1
                jnz     short loc_4CD420
                mov     ecx, [esp+4Ch+arg_0]
                mov     edx, 1
                shl     edx, cl
                mov     ecx, [esp+4Ch+var_1C]
                sub     ecx, edx
                add     ebx, ecx
                cmp     [esp+4Ch+var_34], 4
                mov     [esp+4Ch+var_4], ebx
                jge     loc_4CD69D
                add     [esp+4Ch+var_34], 7
                cmp     ebx, 4
                jl      short loc_4CD4CC
                mov     ebx, 3

loc_4CD4CC:                             ; CODE XREF: sub_4CCC80+845j
                mov     ecx, [esp+4Ch+var_20]
                shl     ebx, 7
                lea     ecx, [ebx+ecx+360h]
                mov     [esp+4Ch+var_30], ecx
                mov     [esp+4Ch+arg_0], 6
                mov     edi, 1
                jmp     short loc_4CD4F0
; ---------------------------------------------------------------------------
                align 10h

loc_4CD4F0:                             ; CODE XREF: sub_4CCC80+86Bj
                                        ; sub_4CCC80+8E3j
                cmp     eax, 1000000h
                mov     edx, [esp+4Ch+arg_8]
                lea     ebx, [edi+edi]
                jnb     short loc_4CD51A
                cmp     edx, [esp+4Ch+var_3C]
                jz      loc_4CD6E2
                movzx   ebp, byte ptr [edx]
                shl     esi, 8
                shl     eax, 8
                or      esi, ebp
                add     edx, 1
                mov     [esp+4Ch+arg_8], edx

loc_4CD51A:                             ; CODE XREF: sub_4CCC80+87Cj
                movzx   edx, word ptr [ebx+ecx]
                movzx   ebp, dx
                mov     ecx, eax
                shr     ecx, 0Bh
                imul    ecx, ebp
                cmp     esi, ecx
                jnb     short loc_4CD545
                mov     eax, ecx
                mov     ecx, 800h
                sub     ecx, ebp
                sar     ecx, 5
                add     ecx, edx
                mov     [esp+4Ch+var_10], ecx
                mov     edx, ecx
                add     edi, edi
                jmp     short loc_4CD556
; ---------------------------------------------------------------------------

loc_4CD545:                             ; CODE XREF: sub_4CCC80+8ABj
                sub     eax, ecx
                sub     esi, ecx
                mov     cx, dx
                shr     cx, 5
                sub     dx, cx
                lea     edi, [ebx+1]

loc_4CD556:                             ; CODE XREF: sub_4CCC80+8C3j
                sub     [esp+4Ch+arg_0], 1
                mov     ecx, [esp+4Ch+var_30]
                mov     [ebx+ecx], dx
                jnz     short loc_4CD4F0
                sub     edi, 40h
                cmp     edi, 4
                jl      loc_4CD68A
                mov     ebx, 1
                mov     ecx, edi
                mov     edx, edi
                sar     ecx, 1
                and     edx, ebx
                sub     ecx, ebx
                or      edx, 2
                cmp     edi, 0Eh
                mov     [esp+4Ch+var_30], ecx
                jge     short loc_4CD5A1
                shl     edx, cl
                mov     ecx, [esp+4Ch+var_20]
                mov     [esp+4Ch+var_38], edx
                sub     edx, edi
                lea     ebp, [ecx+edx*2+55Eh]
                jmp     short loc_4CD5F3
; ---------------------------------------------------------------------------

loc_4CD5A1:                             ; CODE XREF: sub_4CCC80+90Aj
                mov     edi, [esp+4Ch+arg_8]
                sub     ecx, 4

loc_4CD5A8:                             ; CODE XREF: sub_4CCC80+958j
                cmp     eax, 1000000h
                jnb     short loc_4CD5CA
                cmp     edi, [esp+4Ch+var_3C]
                jz      loc_4CD6EF
                movzx   ebp, byte ptr [edi]
                shl     esi, 8
                shl     eax, 8
                or      esi, ebp
                add     edi, ebx
                mov     [esp+4Ch+arg_8], edi

loc_4CD5CA:                             ; CODE XREF: sub_4CCC80+92Dj
                shr     eax, 1
                add     edx, edx
                cmp     esi, eax
                jb      short loc_4CD5D6
                sub     esi, eax
                or      edx, ebx

loc_4CD5D6:                             ; CODE XREF: sub_4CCC80+950j
                sub     ecx, ebx
                jnz     short loc_4CD5A8
                mov     ebp, [esp+4Ch+var_20]
                add     ebp, 644h
                shl     edx, 4
                mov     [esp+4Ch+var_38], edx
                mov     [esp+4Ch+var_30], 4

loc_4CD5F3:                             ; CODE XREF: sub_4CCC80+91Fj
                mov     [esp+4Ch+var_1C], ebx
                mov     [esp+4Ch+arg_0], ebx
                jmp     short loc_4CD600
; ---------------------------------------------------------------------------
                align 10h

loc_4CD600:                             ; CODE XREF: sub_4CCC80+97Bj
                                        ; sub_4CCC80+A02j
                mov     ebx, [esp+4Ch+arg_0]
                add     ebx, ebx
                cmp     eax, 1000000h
                jnb     short loc_4CD62D
                mov     ecx, [esp+4Ch+arg_8]
                cmp     ecx, [esp+4Ch+var_3C]
                jz      loc_4CD6E2
                movzx   edx, byte ptr [ecx]
                shl     esi, 8
                shl     eax, 8
                or      esi, edx
                add     ecx, 1
                mov     [esp+4Ch+arg_8], ecx

loc_4CD62D:                             ; CODE XREF: sub_4CCC80+98Bj
                movzx   edi, word ptr [ebx+ebp]
                movzx   ecx, di
                mov     edx, eax
                shr     edx, 0Bh
                imul    edx, ecx
                cmp     esi, edx
                jnb     short loc_4CD658
                mov     eax, edx
                mov     edx, 800h
                sub     edx, ecx
                sar     edx, 5
                add     edx, edi
                shl     [esp+4Ch+arg_0], 1
                mov     [ebx+ebp], dx
                jmp     short loc_4CD679
; ---------------------------------------------------------------------------

loc_4CD658:                             ; CODE XREF: sub_4CCC80+9BEj
                mov     cx, di
                shr     cx, 5
                sub     di, cx
                sub     eax, edx
                sub     esi, edx
                mov     edx, [esp+4Ch+var_1C]
                mov     [ebx+ebp], di
                add     ebx, 1
                or      [esp+4Ch+var_38], edx
                mov     [esp+4Ch+arg_0], ebx

loc_4CD679:                             ; CODE XREF: sub_4CCC80+9D6j
                shl     [esp+4Ch+var_1C], 1
                sub     [esp+4Ch+var_30], 1
                jnz     loc_4CD600
                jmp     short loc_4CD68E
; ---------------------------------------------------------------------------

loc_4CD68A:                             ; CODE XREF: sub_4CCC80+8EBj
                mov     [esp+4Ch+var_38], edi

loc_4CD68E:                             ; CODE XREF: sub_4CCC80+A08j
                add     [esp+4Ch+var_38], 1
                jz      loc_4CCFB3
                mov     ebx, [esp+4Ch+var_4]

loc_4CD69D:                             ; CODE XREF: sub_4CCC80+837j
                mov     ebp, [esp+4Ch+var_2C]
                mov     ecx, [esp+4Ch+var_38]
                add     ebx, 2
                cmp     ecx, ebp
                ja      short loc_4CD6E2
                mov     edi, ebp
                sub     edi, ecx
                add     edi, [esp+4Ch+arg_10]

loc_4CD6B4:                             ; CODE XREF: sub_4CCC80+A60j
                mov     cl, [edi]
                mov     edx, [esp+4Ch+arg_10]
                sub     ebx, 1
                mov     [edx+ebp], cl
                add     ebp, 1
                add     edi, 1
                test    ebx, ebx
                mov     byte ptr [esp+4Ch+arg_0], cl
                mov     [esp+4Ch+var_2C], ebp
                jz      loc_4CCFA5
                cmp     ebp, [esp+4Ch+arg_14]
                jnb     loc_4CCFB3
                jmp     short loc_4CD6B4
; ---------------------------------------------------------------------------

loc_4CD6E2:                             ; CODE XREF: sub_4CCC80+101j
                                        ; sub_4CCC80+1C9j ...
                pop     edi
                pop     esi
                pop     ebp
                mov     eax, 1
                pop     ebx
                add     esp, 3Ch
                retn
; ---------------------------------------------------------------------------

loc_4CD6EF:                             ; CODE XREF: sub_4CCC80+933j
                pop     edi
                pop     esi
                pop     ebp
                mov     eax, ebx
                pop     ebx
                add     esp, 3Ch
                retn
sub_4CCC80      endp

_starcraft_decompress_lzma PROC
;sub_4CD700

var_14          = byte ptr -14h
var_10          = dword ptr -10h
var_C           = dword ptr -0Ch
var_4           = dword ptr -4
pbInBuffer      = dword ptr  4
cbInBuffer      = dword ptr  8
pbOutBuffer     = dword ptr  0Ch
cbOutBuffer     = dword ptr  10h
pcbOutBuffer    = dword ptr  14h
pfnAllocateMemory= dword ptr  18h
pfnFreeMemory   = dword ptr  1Ch

                sub     esp, 14h
                push    ebx
                mov     ebx, [esp+18h+cbInBuffer]
                cmp     ebx, 0Eh        ; LZMA_PROPS_SIZE + 8
                jnb     short loc_4CD714
                xor     al, al
                pop     ebx
                add     esp, 14h
                retn
; ---------------------------------------------------------------------------

loc_4CD714:                             ; CODE XREF: Decompress_lzma_internal+Bj
                push    ebp
                mov     ebp, [esp+1Ch+pcbOutBuffer]
                push    edi
                mov     edi, [esp+20h+pbInBuffer]
                mov     dword ptr [ebp+0], 0
                cmp     byte ptr [edi], 0
                jnz     short loc_4CD741
                push    5
                lea     eax, [edi+1]
                push    eax
                lea     ecx, [esp+28h+var_10]
                push    ecx
                call    LzmaProps_Decode
                add     esp, 0Ch
                test    eax, eax
                jz      short loc_4CD74A

loc_4CD741:                             ; CODE XREF: Decompress_lzma_internal+28j
                pop     edi
                pop     ebp
                xor     al, al
                pop     ebx
                add     esp, 14h
                retn
; ---------------------------------------------------------------------------

loc_4CD74A:                             ; CODE XREF: Decompress_lzma_internal+3Fj
                mov     edx, [esp+20h+var_10]
                mov     eax, [esp+20h+var_C]
                lea     ecx, [eax+edx]
                mov     edx, 300h
                shl     edx, cl
                push    esi
                lea     eax, [edx+edx+0E6Ch]
                push    eax
                call    [esp+28h+pfnAllocateMemory]
                mov     esi, eax
                add     esp, 4
                test    esi, esi
                mov     [esp+24h+var_4], esi
                jz      short loc_4CD7AA
                mov     edx, [esp+24h+cbOutBuffer]
                mov     eax, [esp+24h+pbOutBuffer]
                lea     ecx, [esp+24h+cbInBuffer]
                push    ecx             ; cbInBuffer
                push    edx             ; cbOutBuffer
                push    eax             ; pbOutBuffer
                lea     ecx, [esp+30h+var_14]
                push    ecx             ; &var_14
                add     ebx, 0FFFFFFF2h
                push    ebx             ; cbInBuffer - LZMA86_HEADER_SIZE
                add     edi, 0Eh
                lea     edx, [esp+38h+var_10]
                push    edi             ; pbInBuffer + LZMA86_HEADER_SIZE
                push    edx             ; dest
                call    sub_4CCC80
                push    esi
                mov     edi, eax
                call    [esp+44h+pfnFreeMemory]
                add     esp, 20h
                test    edi, edi
                jz      short loc_4CD7B4

loc_4CD7AA:                             ; CODE XREF: Decompress_lzma_internal+74j
                pop     esi
                pop     edi
                pop     ebp
                xor     al, al
                pop     ebx
                add     esp, 14h
                retn
; ---------------------------------------------------------------------------

loc_4CD7B4:                             ; CODE XREF: Decompress_lzma_internal+A8j
                mov     eax, [esp+24h+cbInBuffer]
                pop     esi
                pop     edi
                mov     [ebp+0], eax
                pop     ebp
                mov     al, 1
                pop     ebx
                add     esp, 14h
                retn
_starcraft_decompress_lzma ENDP

; =============== S U B R O U T I N E =======================================

sub_4CD7D0      proc near               ; CODE XREF: sub_4CDC00+74p

arg_0           = dword ptr  4

                push    esi
                mov     esi, [esp+4+arg_0]
                or      esi, 8
                xor     eax, eax
                cmp     esi, 1
                jz      short loc_4CD806
                push    edi

loc_4CD7E0:                             ; CODE XREF: sub_4CD7D0+33j
                mov     edx, esi
                shr     esi, 1
                mov     edi, [ecx+esi*4]
                and     edx, 1
                sub     edi, edx
                neg     edx
                xor     edi, edx
                shr     edi, 2
                and     edi, 1FFh
                add     eax, dword_550998[edi*4]
                cmp     esi, 1
                jnz     short loc_4CD7E0
                pop     edi

loc_4CD806:                             ; CODE XREF: sub_4CD7D0+Dj
                pop     esi
                retn    4
sub_4CD7D0      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CD810      proc near               ; CODE XREF: CEncoder_FillAlignPrices+17p

var_4           = dword ptr -4
arg_0           = dword ptr  4

                push    ecx
                push    ebx
                push    ebp
                push    esi
                xor     eax, eax
                push    edi
                mov     edi, [esp+14h+arg_0]
                mov     [esp+14h+var_4], ecx
                lea     esi, [eax+1]
                lea     ebx, [eax+4]

loc_4CD825:                             ; CODE XREF: sub_4CD810+42j
                mov     ecx, [esp+14h+var_4]
                mov     ecx, [ecx+esi*4]
                mov     edx, edi
                and     edx, 1
                sub     ecx, edx
                mov     ebp, edx
                neg     ebp
                xor     ecx, ebp
                shr     ecx, 2
                and     ecx, 1FFh
                add     eax, dword_550998[ecx*4]
                add     esi, esi
                shr     edi, 1
                or      esi, edx
                sub     ebx, 1
                jnz     short loc_4CD825
                pop     edi
                pop     esi
                pop     ebp
                pop     ebx
                pop     ecx
                retn    4
sub_4CD810      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CD860      proc near               ; CODE XREF: CEncoder_FillDistancesPrices+6Bp

arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch

                push    edi
                mov     edi, [esp+4+arg_4]
                xor     eax, eax
                test    edi, edi
                lea     edx, [eax+1]
                jz      short loc_4CD8A7
                push    ebx
                push    ebp
                push    esi
                mov     esi, [esp+10h+arg_8]

loc_4CD875:                             ; CODE XREF: sub_4CD860+42j
                mov     ebx, [esp+10h+arg_0]
                mov     ebx, [ebx+edx*4]
                mov     ecx, esi
                and     ecx, 1
                sub     ebx, ecx
                mov     ebp, ecx
                neg     ebp
                xor     ebx, ebp
                shr     ebx, 2
                and     ebx, 1FFh
                add     eax, dword_550998[ebx*4]
                add     edx, edx
                shr     esi, 1
                or      edx, ecx
                sub     edi, 1
                jnz     short loc_4CD875
                pop     esi
                pop     ebp
                pop     ebx

loc_4CD8A7:                             ; CODE XREF: sub_4CD860+Cj
                pop     edi
                retn
sub_4CD860      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CD8B0      proc near               ; CODE XREF: CEncoder_CodeOneBlock+7B8p
                mov     eax, [ecx+24h]
                mov     edx, [ecx+1Ch]
                push    ebx
                push    esi
                mov     esi, [ecx+30h]
                xor     ebx, ebx
                push    edi
                mov     edi, [ecx+34h]
                sub     esi, eax
                sbb     edi, ebx
                add     esi, edx
                adc     edi, ebx
                cmp     eax, edx
                jbe     short loc_4CD8D4
                mov     eax, [ecx+28h]
                add     esi, eax
                adc     edi, ebx

loc_4CD8D4:                             ; CODE XREF: sub_4CD8B0+1Bj
                mov     eax, [ecx]
                xor     edx, edx
                add     eax, esi
                adc     edx, edi
                pop     edi
                add     eax, 4
                pop     esi
                adc     edx, ebx
                pop     ebx
                retn
sub_4CD8B0      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CD8F0      proc near               ; CODE XREF: sub_4CD940+21p
                                        ; .text:loc_4CF730j ...
                mov     eax, dword_553598
                test    eax, eax
                push    esi
                mov     esi, ecx
                push    edi
                mov     edi, [esi]
                jnz     short loc_4CD92A
                push    0Ch             ; Size
                call    _operator_new    ; operator new(uint)
                add     esp, 4
                test    eax, eax
                jz      short loc_4CD923
                mov     dword ptr [eax], 0
                mov     dword ptr [eax+4], 0
                mov     dword ptr [eax+8], 0
                jmp     short loc_4CD925
; ---------------------------------------------------------------------------

loc_4CD923:                             ; CODE XREF: sub_4CD8F0+1Bj
                xor     eax, eax

loc_4CD925:                             ; CODE XREF: sub_4CD8F0+31j
                mov     dword_553598, eax

loc_4CD92A:                             ; CODE XREF: sub_4CD8F0+Dj
                mov     eax, [eax+4]
                test    eax, eax
                jz      short loc_4CD937
                push    edi
                call    eax
                add     esp, 4

loc_4CD937:                             ; CODE XREF: sub_4CD8F0+3Fj
                pop     edi
                mov     dword ptr [esi], 0
                pop     esi
                retn
sub_4CD8F0      endp

; =============== S U B R O U T I N E =======================================

sub_4CD940      proc near               ; CODE XREF: sub_4D0270+74p

arg_0           = dword ptr  4
arg_4           = dword ptr  8

                push    ebx
                mov     ebx, [esp+4+arg_4]
                push    esi
                mov     esi, ecx
                cmp     dword ptr [esi], 0
                push    edi
                mov     edi, [esp+0Ch+arg_0]
                jz      short loc_4CD95F
                mov     eax, [esi+8]
                add     eax, [esi+4]
                lea     ecx, [edi+ebx]
                cmp     ecx, eax
                jz      short loc_4CD981

loc_4CD95F:                             ; CODE XREF: sub_4CD940+10j
                mov     ecx, esi
                call    sub_4CD8F0
                lea     ecx, [edi+ebx]
                mov     edx, 1
                shl     edx, cl
                imul    edx, 0C00h
                push    edx
                call    sub_4CB8A0
                add     esp, 4
                mov     [esi], eax

loc_4CD981:                             ; CODE XREF: sub_4CD940+1Dj
                mov     ecx, edi
                mov     eax, 1
                shl     eax, cl
                mov     [esi+8], edi
                pop     edi
                mov     [esi+4], ebx
                sub     eax, 1
                mov     [esi+0Ch], eax
                xor     eax, eax
                cmp     [esi], eax
                pop     esi
                setnz   al
                pop     ebx
                retn    8
sub_4CD940      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================


sub_4CD9B0      proc near               ; CODE XREF: CEncoder_GetOptimum+436p
                                        ; CEncoder_GetOptimum+AE1p

arg_0           = dword ptr  4
arg_4           = byte ptr  8
arg_8           = dword ptr  0Ch

                mov     edx, [esp+arg_0]
                test    edx, edx
                push    esi
                jnz     short loc_4CD9F2
                movzx   eax, [esp+4+arg_4]
                mov     edx, eax
                shl     edx, 4
                add     edx, [esp+4+arg_8]
                mov     esi, 800h
                sub     esi, [ecx+edx*4+284B0h]
                mov     ecx, [ecx+eax*4+28420h]
                shr     esi, 2
                mov     eax, dword_550998[esi*4]
                shr     ecx, 2
                add     eax, dword_550998[ecx*4]
                pop     esi
                retn    0Ch
; ---------------------------------------------------------------------------

loc_4CD9F2:                             ; CODE XREF: sub_4CD9B0+7j
                movzx   esi, [esp+4+arg_4]
                mov     eax, 800h
                sub     eax, [ecx+esi*4+28420h]
                shr     eax, 2
                cmp     edx, 1
                mov     eax, dword_550998[eax*4]
                jnz     short loc_4CDA27
                mov     ecx, [ecx+esi*4+28450h]
                shr     ecx, 2
                add     eax, dword_550998[ecx*4]
                pop     esi
                retn    0Ch
; ---------------------------------------------------------------------------

loc_4CDA27:                             ; CODE XREF: sub_4CD9B0+60j
                push    edi
                add     edx, 0FFFFFFFEh
                mov     edi, 800h
                sub     edi, [ecx+esi*4+28450h]
                mov     ecx, [ecx+esi*4+28480h]
                sub     ecx, edx
                neg     edx
                xor     ecx, edx
                shr     edi, 2
                mov     edx, dword_550998[edi*4]
                shr     ecx, 2
                and     ecx, 1FFh
                add     edx, dword_550998[ecx*4]
                pop     edi
                add     eax, edx
                pop     esi
                retn    0Ch
sub_4CD9B0      endp

; ---------------------------------------------------------------------------
                align 10h

; =============== S U B R O U T I N E =======================================


sub_4CDA70      proc near               ; CODE XREF: CEncoder_CodeReal+10Cp
                                        ; CEncoder_CodeReal+134p ...
                push    esi
                mov     esi, [ecx]
                cmp     dword ptr [esi+80h], 0
                jz      short loc_4CDA8C
                cmp     byte ptr [esi+33B95h], 0
                jz      short loc_4CDA8C
                mov     byte ptr [esi+33B95h], 0

loc_4CDA8C:                             ; CODE XREF: sub_4CDA70+Aj
                                        ; sub_4CDA70+13j
                mov     eax, [esi+33B8Ch]
                test    eax, eax
                jz      short loc_4CDAA8
                mov     ecx, [eax]
                mov     edx, [ecx+8]
                push    eax
                call    edx
                mov     dword ptr [esi+33B8Ch], 0

loc_4CDAA8:                             ; CODE XREF: sub_4CDA70+24j
                mov     ecx, [esi+4]
                mov     edx, [ecx+10h]
                lea     eax, [esi+4]
                push    eax
                call    edx
                pop     esi
                retn
sub_4CDA70      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================


sub_4CDAC0      proc near               ; CODE XREF: CEncoder_GetOptimum+2C4p
                                        ; CEncoder_GetOptimum+7ACp ...

var_4           = dword ptr -4
arg_0           = dword ptr  4
arg_4           = byte ptr  8
arg_8           = byte ptr  0Ch

                push    ecx
                push    ebx
                push    ebp
                xor     ebp, ebp
                cmp     byte ptr [esp+0Ch+arg_0], 0
                push    esi
                mov     eax, ecx
                push    edi
                mov     [esp+14h+var_4], eax
                lea     edi, [ebp+1]
                lea     ebx, [ebp+8]
                jz      short loc_4CDB3B
                movzx   ecx, [esp+14h+arg_8]
                mov     [esp+14h+arg_0], ecx

loc_4CDAE3:                             ; CODE XREF: sub_4CDAC0+71j
                movzx   esi, [esp+14h+arg_4]
                mov     edx, [esp+14h+arg_0]
                sub     ebx, 1
                movzx   ecx, bl
                shr     esi, cl
                shr     edx, cl
                and     esi, 1
                mov     ecx, esi
                shl     ecx, 8
                add     ecx, edi
                mov     eax, [eax+ecx*4+400h]
                and     edx, 1
                sub     eax, edx
                mov     ecx, edx
                neg     ecx
                xor     eax, ecx
                shr     eax, 2
                and     eax, 1FFh
                add     ebp, dword_550998[eax*4]
                add     edi, edi
                or      edi, edx
                cmp     esi, edx
                jnz     short loc_4CDB33
                test    ebx, ebx
                jz      short loc_4CDB75
                mov     eax, [esp+14h+var_4]
                jmp     short loc_4CDAE3
; ---------------------------------------------------------------------------

loc_4CDB33:                             ; CODE XREF: sub_4CDAC0+67j
                test    ebx, ebx
                jz      short loc_4CDB75
                mov     eax, [esp+14h+var_4]

loc_4CDB3B:                             ; CODE XREF: sub_4CDAC0+18j
                movzx   edx, [esp+14h+arg_8]
                mov     [esp+14h+arg_0], edx

loc_4CDB44:                             ; CODE XREF: sub_4CDAC0+B3j
                mov     edx, [esp+14h+arg_0]
                sub     ebx, 1
                mov     cl, bl
                shr     edx, cl
                mov     ecx, [eax+edi*4]
                add     edi, edi
                and     edx, 1
                sub     ecx, edx
                mov     esi, edx
                neg     esi
                xor     ecx, esi
                shr     ecx, 2
                and     ecx, 1FFh
                add     ebp, dword_550998[ecx*4]
                or      edi, edx
                test    ebx, ebx
                jnz     short loc_4CDB44

loc_4CDB75:                             ; CODE XREF: sub_4CDAC0+6Bj
                                        ; sub_4CDAC0+75j
                pop     edi
                pop     esi
                mov     eax, ebp
                pop     ebp
                pop     ebx
                pop     ecx
                retn    0Ch
sub_4CDAC0      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CDB80      proc near               ; CODE XREF: sub_4CDEA0+11Ep
                                        ; sub_4CDEA0+137p

arg_0           = dword ptr  4

                push    esi
                mov     esi, [esp+4+arg_0]
                test    esi, esi
                mov     edx, 400h
                push    edi
                mov     [ecx], edx
                mov     [ecx+4], edx
                jbe     short loc_4CDBE6
                lea     eax, [ecx+20Ch]
                lea     ebx, [ebx+0]

loc_4CDBA0:                             ; CODE XREF: sub_4CDB80+64j
                mov     [eax-200h], edx
                mov     [eax-1FCh], edx
                mov     [eax-1F8h], edx
                mov     [eax-1F4h], edx
                mov     [eax-1F0h], edx
                mov     [eax-1ECh], edx
                mov     [eax-1E8h], edx
                mov     [eax], edx
                mov     [eax+4], edx
                mov     [eax+8], edx
                mov     [eax+0Ch], edx
                mov     [eax+10h], edx
                mov     [eax+14h], edx
                mov     [eax+18h], edx
                add     eax, 20h
                sub     esi, 1
                jnz     short loc_4CDBA0

loc_4CDBE6:                             ; CODE XREF: sub_4CDB80+12j
                lea     edi, [ecx+40Ch]
                mov     ecx, 0FFh
                mov     eax, edx
                rep stosd
                pop     edi
                pop     esi
                retn    4
sub_4CDB80      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CDC00      proc near               ; CODE XREF: sub_4CF740+22p
                                        ; sub_4CF780+2Bp

var_C           = dword ptr -0Ch
var_8           = dword ptr -8
var_4           = dword ptr -4
arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch

                sub     esp, 0Ch
                push    ebx
                push    ebp
                push    esi
                push    edi
                mov     edi, ecx
                mov     eax, [edi]
                mov     ebx, [esp+1Ch+arg_0]
                mov     ecx, eax
                shr     ecx, 2
                mov     edx, dword_550998[ecx*4]
                mov     ecx, 800h
                sub     ecx, eax
                shr     ecx, 2
                mov     eax, dword_550998[ecx*4]
                mov     ecx, [edi+4]
                mov     [esp+1Ch+var_C], edx
                mov     edx, ecx
                shr     edx, 2
                mov     ebp, dword_550998[edx*4]
                mov     edx, 800h
                sub     edx, ecx
                shr     edx, 2
                mov     ecx, dword_550998[edx*4]
                add     ebp, eax
                add     ecx, eax
                mov     [esp+1Ch+var_8], ebp
                mov     [esp+1Ch+var_4], ecx
                xor     esi, esi
                mov     edi, edi

loc_4CDC60:                             ; CODE XREF: sub_4CDC00+8Aj
                cmp     esi, [esp+1Ch+arg_4]
                jnb     loc_4CDD62
                mov     eax, ebx
                shl     eax, 5
                push    esi
                lea     ecx, [eax+edi+8]
                call    sub_4CD7D0
                add     eax, [esp+1Ch+var_C]
                mov     ecx, [esp+1Ch+arg_8]
                mov     [ecx+esi*4], eax
                add     esi, 1
                cmp     esi, 8
                jb      short loc_4CDC60
                cmp     esi, 10h
                jnb     short loc_4CDD00
                lea     ecx, [esi-8]
                mov     [esp+1Ch+arg_0], ecx
                jmp     short loc_4CDCA0
; ---------------------------------------------------------------------------
                align 10h

loc_4CDCA0:                             ; CODE XREF: sub_4CDC00+98j
                                        ; sub_4CDC00+FEj
                cmp     esi, [esp+1Ch+arg_4]
                jnb     loc_4CDD62
                or      ecx, 8
                xor     edx, edx
                cmp     ecx, 1
                jz      short loc_4CDCE4

loc_4CDCB4:                             ; CODE XREF: sub_4CDC00+DEj
                mov     eax, ecx
                shr     ecx, 1
                and     eax, 1
                lea     ebp, [ecx+ebx*8]
                mov     ebp, [edi+ebp*4+208h]
                sub     ebp, eax
                neg     eax
                xor     ebp, eax
                shr     ebp, 2
                and     ebp, 1FFh
                add     edx, dword_550998[ebp*4]
                cmp     ecx, 1
                jnz     short loc_4CDCB4
                mov     ebp, [esp+1Ch+var_8]

loc_4CDCE4:                             ; CODE XREF: sub_4CDC00+B2j
                mov     eax, [esp+1Ch+arg_8]
                mov     ecx, [esp+1Ch+arg_0]
                add     edx, ebp
                mov     [eax+esi*4], edx
                add     esi, 1
                add     ecx, 1
                cmp     esi, 10h
                mov     [esp+1Ch+arg_0], ecx
                jb      short loc_4CDCA0

loc_4CDD00:                             ; CODE XREF: sub_4CDC00+8Fj
                cmp     esi, [esp+1Ch+arg_4]
                jnb     short loc_4CDD62
                lea     ebx, [esi-10h]
                lea     esp, [esp+0]

loc_4CDD10:                             ; CODE XREF: sub_4CDC00+160j
                mov     ecx, ebx
                or      ecx, 100h
                xor     edx, edx
                cmp     ecx, 1
                jz      short loc_4CDD49
                nop

loc_4CDD20:                             ; CODE XREF: sub_4CDC00+147j
                mov     eax, ecx
                shr     ecx, 1
                mov     ebp, [edi+ecx*4+408h]
                and     eax, 1
                sub     ebp, eax
                neg     eax
                xor     ebp, eax
                shr     ebp, 2
                and     ebp, 1FFh
                add     edx, dword_550998[ebp*4]
                cmp     ecx, 1
                jnz     short loc_4CDD20

loc_4CDD49:                             ; CODE XREF: sub_4CDC00+11Dj
                mov     ecx, [esp+1Ch+var_4]
                mov     eax, [esp+1Ch+arg_8]
                add     edx, ecx
                mov     [eax+esi*4], edx
                add     esi, 1
                add     ebx, 1
                cmp     esi, [esp+1Ch+arg_4]
                jb      short loc_4CDD10

loc_4CDD62:                             ; CODE XREF: sub_4CDC00+64j
                                        ; sub_4CDC00+A4j ...
                pop     edi
                pop     esi
                pop     ebp
                pop     ebx
                add     esp, 0Ch
                retn    0Ch
sub_4CDC00      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

; int __cdecl sub_4CDD70(SIZE_T dwSize)
sub_4CDD70      proc near               ; DATA XREF: .data:off_546E20o

dwSize          = dword ptr  4

                mov     eax, [esp+dwSize]
                test    eax, eax
                jnz     short loc_4CDD79
                retn
; ---------------------------------------------------------------------------

loc_4CDD79:                             ; CODE XREF: sub_4CDD70+6j
                push    4               ; flProtect
                push    1000h           ; flAllocationType
                push    eax             ; dwSize
                push    0               ; lpAddress
                call    ds:VirtualAlloc
                retn
sub_4CDD70      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================


; int __cdecl sub_4CDD90(void * lpAddress)
sub_4CDD90      proc near               ; CODE XREF: sub_4CF810+53p
                                        ; sub_4CF810+73p
                                        ; DATA XREF: ...

lpAddress       = dword ptr  4

                mov     eax, [esp+lpAddress]
                test    eax, eax
                jz      short locret_4CDDA6
                push    8000h           ; dwFreeType
                push    0               ; dwSize
                push    eax             ; lpAddress
                call    ds:VirtualFree

locret_4CDDA6:                          ; CODE XREF: sub_4CDD90+6j
                retn
sub_4CDD90      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================


sub_4CDDB0      proc near               ; DATA XREF: .rdata:00517AC8o

var_10          = dword ptr -10h
var_C           = byte ptr -0Ch
var_B           = byte ptr -0Bh
var_A           = byte ptr -0Ah
var_9           = byte ptr -9
var_8           = byte ptr -8
var_4           = dword ptr -4
arg_0           = dword ptr  4
arg_4           = dword ptr  8

                sub     esp, 10h
                mov     eax, dword_544960
                xor     eax, esp
                mov     [esp+10h+var_4], eax
                mov     ecx, [esp+10h+arg_0]
                mov     al, [ecx+33B50h]
                mov     dl, 5
                imul    dl
                add     al, [ecx+33B58h]
                mov     dl, 9
                imul    dl
                add     al, [ecx+33B5Ch]
                push    ebp
                mov     ebp, [esp+14h+arg_4]
                mov     [esp+14h+var_C], al
                mov     eax, [ecx+33B60h]
                mov     ecx, eax
                mov     edx, eax
                push    esi
                shr     ecx, 8
                shr     edx, 10h
                mov     [esp+18h+var_B], al
                shr     eax, 18h
                push    edi
                mov     [esp+1Ch+var_A], cl
                mov     [esp+1Ch+var_9], dl
                mov     [esp+1Ch+var_8], al
                mov     esi, 5
                lea     edi, [esp+1Ch+var_C]

loc_4CDE13:                             ; CODE XREF: sub_4CDDB0+85j
                mov     eax, [ebp+0]
                mov     edx, [eax+0Ch]
                lea     ecx, [esp+1Ch+var_10]
                push    ecx
                push    esi
                push    edi
                push    ebp
                call    edx
                mov     ecx, [esp+1Ch+var_10]
                add     edi, ecx
                sub     esi, ecx
                test    eax, eax
                jnz     short loc_4CDE37
                test    ecx, ecx
                jz      short loc_4CDE4B
                test    esi, esi
                jnz     short loc_4CDE13

loc_4CDE37:                             ; CODE XREF: sub_4CDDB0+7Dj
                pop     edi
                pop     esi
                pop     ebp
                mov     ecx, [esp+10h+var_4]
                xor     ecx, esp
                call    sub_4A0686
                add     esp, 10h
                retn    8
; ---------------------------------------------------------------------------

loc_4CDE4B:                             ; CODE XREF: sub_4CDDB0+81j
                mov     ecx, [esp+1Ch+var_4]
                pop     edi
                pop     esi
                pop     ebp
                xor     ecx, esp
                mov     eax, 80004005h
                call    sub_4A0686
                add     esp, 10h
                retn    8
sub_4CDDB0      endp

                align 10h

; =============== S U B R O U T I N E =======================================

sub_4CDE70      proc near               ; DATA XREF: .rdata:00517AF4o

arg_0           = dword ptr  4

                push    esi
                mov     esi, [esp+4+arg_0]
                mov     eax, [esi+50h]
                test    eax, eax
                jz      short loc_4CDE8B
                mov     ecx, [eax]
                mov     edx, [ecx+8]
                push    eax
                call    edx
                mov     dword ptr [esi+50h], 0

loc_4CDE8B:                             ; CODE XREF: sub_4CDE70+Aj
                xor     eax, eax
                pop     esi
                retn    4
sub_4CDE70      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================


sub_4CDEA0      proc near               ; CODE XREF: CEncoder_SetStreams+3Cp

var_4           = dword ptr -4

                push    ecx
                push    ebx
                xor     ebx, ebx
                push    ebp
                push    esi
                mov     esi, ecx
                mov     byte ptr [esi+10h], 0
                mov     byte ptr [esi+11h], 0
                mov     [esi+14h], ebx
                mov     [esi+18h], ebx
                mov     [esi+1Ch], ebx
                mov     [esi+20h], ebx
                mov     eax, [esi+50h]
                mov     [esi+4Ch], ebx
                mov     [esi+48h], eax
                mov     [esi+44h], ebx
                mov     [esi+58h], ebx
                mov     [esi+5Ch], ebx
                mov     [esi+64h], bl
                push    edi
                mov     [esi+30h], ebx
                mov     [esi+34h], ebx
                mov     dword ptr [esi+38h], 0FFFFFFFFh
                mov     dword ptr [esi+28h], 1
                mov     [esi+2Ch], bl
                lea     ecx, [esi+28420h]
                lea     edi, [esi+284B0h]
                mov     [esp+14h+var_4], 0Ch
                mov     ebp, 400h

loc_4CDF02:                             ; CODE XREF: sub_4CDEA0+9Cj
                xor     edx, edx
                mov     eax, edi
                jmp     short loc_4CDF10
; ---------------------------------------------------------------------------
                align 10h

loc_4CDF10:                             ; CODE XREF: sub_4CDEA0+66j
                                        ; sub_4CDEA0+84j
                mov     [eax-3C0h], ebp
                mov     [eax], ebp
                add     edx, 1
                add     eax, 4
                cmp     edx, [esi+33B60h]
                jbe     short loc_4CDF10
                mov     [ecx-30h], ebp
                mov     [ecx], ebp
                mov     [ecx+30h], ebp
                mov     [ecx+60h], ebp
                add     ecx, 4
                add     edi, 40h
                sub     [esp+14h+var_4], 1
                jnz     short loc_4CDF02
                mov     ecx, [esi+32658h]
                add     ecx, [esi+32654h]
                mov     eax, 1
                shl     eax, cl
                cmp     eax, ebx
                jbe     short loc_4CDF7C
                xor     edx, edx
                mov     ebx, eax
                lea     esp, [esp+0]

loc_4CDF60:                             ; CODE XREF: sub_4CDEA0+DAj
                mov     edi, [esi+32650h]
                add     edi, edx
                mov     ecx, 300h
                mov     eax, ebp
                add     edx, 0C00h
                sub     ebx, 1
                rep stosd
                jnz     short loc_4CDF60

loc_4CDF7C:                             ; CODE XREF: sub_4CDEA0+B3j
                lea     edx, [esi+287B4h]
                mov     ebx, 4

loc_4CDF87:                             ; CODE XREF: sub_4CDEA0+FBj
                mov     edi, edx
                mov     ecx, 3Fh
                mov     eax, ebp
                add     edx, 100h
                sub     ebx, 1
                rep stosd
                jnz     short loc_4CDF87
                lea     edi, [esi+28BB0h]
                mov     ecx, 72h
                rep stosd
                mov     ecx, [esi+33B5Ch]
                mov     edx, 1
                shl     edx, cl
                lea     ecx, [esi+28DB8h]
                push    edx
                call    sub_4CDB80
                mov     ecx, [esi+33B5Ch]
                mov     eax, 1
                shl     eax, cl
                lea     ecx, [esi+2DA04h]
                push    eax
                call    sub_4CDB80
                mov     eax, ebp
                mov     [esi+28D7Ch], eax
                mov     [esi+28D80h], eax
                mov     [esi+28D84h], eax
                mov     [esi+28D88h], eax
                mov     [esi+28D8Ch], eax
                mov     [esi+28D90h], eax
                mov     [esi+28D94h], eax
                mov     [esi+28D98h], eax
                mov     [esi+28D9Ch], eax
                mov     [esi+28DA0h], eax
                mov     [esi+28DA4h], eax
                mov     [esi+28DA8h], eax
                mov     [esi+28DACh], eax
                mov     [esi+28DB0h], eax
                mov     [esi+28DB4h], eax
                xor     eax, eax
                pop     edi
                mov     [esi+32F10h], bl
                mov     [esi+32F08h], eax
                mov     [esi+32F0Ch], eax
                mov     [esi+32F04h], eax
                pop     esi
                pop     ebp
                pop     ebx
                pop     ecx
                retn
sub_4CDEA0      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CF450      proc near               ; CODE XREF: .text:004CF692p
                                        ; CEncoder_Flush+42p

var_8           = dword ptr -8
var_4           = dword ptr -4

                sub     esp, 8
                push    esi
                mov     esi, ecx
                mov     eax, [esi+0Ch]
                push    edi
                mov     edi, [esi+4]
                cmp     eax, edi
                jb      short loc_4CF464
                mov     edi, [esi+10h]

loc_4CF464:                             ; CODE XREF: sub_4CF450+Fj
                push    ebp
                mov     ebp, [esi+20h]
                xor     edx, edx
                sub     edi, eax
                cmp     ebp, edx
                mov     [esp+14h+var_4], edx
                jz      short loc_4CF4BA
                push    ebx
                mov     ebx, [esi]
                add     ebx, eax
                mov     eax, dword_553598
                cmp     eax, edx
                jnz     short loc_4CF4A5
                push    0Ch             ; Size
                call    _operator_new    ; operator new(uint)
                xor     ecx, ecx
                add     esp, 4
                cmp     eax, ecx
                jz      short loc_4CF49C
                mov     [eax], ecx
                mov     [eax+4], ecx
                mov     [eax+8], ecx
                jmp     short loc_4CF49E
; ---------------------------------------------------------------------------

loc_4CF49C:                             ; CODE XREF: sub_4CF450+40j
                xor     eax, eax

loc_4CF49E:                             ; CODE XREF: sub_4CF450+4Aj
                mov     dword_553598, eax
                xor     edx, edx

loc_4CF4A5:                             ; CODE XREF: sub_4CF450+30j
                mov     eax, [eax+8]
                cmp     eax, edx
                jz      short loc_4CF4B6
                push    edi
                push    ebx
                push    ebp
                call    eax
                add     esp, 0Ch
                xor     edx, edx

loc_4CF4B6:                             ; CODE XREF: sub_4CF450+5Aj
                add     [esi+20h], edi
                pop     ebx

loc_4CF4BA:                             ; CODE XREF: sub_4CF450+22j
                mov     eax, [esi+14h]
                cmp     eax, edx
                pop     ebp
                jz      short loc_4CF4E4
                mov     [esp+10h+var_8], edx
                mov     ecx, [eax]
                lea     edx, [esp+10h+var_8]
                push    edx
                mov     edx, [esi]
                add     edx, [esi+0Ch]
                push    edi
                push    edx
                push    eax
                mov     eax, [ecx+0Ch]
                call    eax
                mov     edi, [esp+10h+var_8]
                mov     [esp+10h+var_4], eax
                xor     edx, edx

loc_4CF4E4:                             ; CODE XREF: sub_4CF450+70j
                add     [esi+0Ch], edi
                mov     ecx, [esi+0Ch]
                mov     eax, [esi+10h]
                cmp     ecx, eax
                jnz     short loc_4CF4F4
                mov     [esi+0Ch], edx

loc_4CF4F4:                             ; CODE XREF: sub_4CF450+9Fj
                cmp     [esi+4], eax
                jnz     short loc_4CF500
                mov     byte ptr [esi+24h], 1
                mov     [esi+4], edx

loc_4CF500:                             ; CODE XREF: sub_4CF450+A7j
                mov     ecx, [esi+0Ch]
                cmp     ecx, [esi+4]
                jbe     short loc_4CF50A
                mov     eax, ecx

loc_4CF50A:                             ; CODE XREF: sub_4CF450+B6j
                add     [esi+18h], edi
                mov     [esi+8], eax
                mov     eax, [esp+10h+var_4]
                adc     [esi+1Ch], edx
                pop     edi
                pop     esi
                add     esp, 8
                retn
sub_4CF450      endp

; ---------------------------------------------------------------------------
                align 10h


; ---------------------------------------------------------------------------

; int __stdcall Interface1_QueryInterface(int, void *Buf1, int)
Interface1_QueryInterface      proc near               ; DATA XREF: .rdata:off_517A90o
; sub_4CF520

arg_0           = dword ptr  4
Buf1            = dword ptr  8
arg_8           = dword ptr  0Ch

                mov     eax, [esp+Buf1]
                push    offset dword_512730 ; Buf2
                push    eax             ; Buf1
                call    unknown_libname_324 ; MFC 3.1/4.0/4.2/8.0 32bit
                add     esp, 8
                test    eax, eax
                jz      short loc_4CF54D
                mov     eax, [esp+arg_0]
                mov     ecx, [esp+arg_8]
                mov     [ecx], eax
                mov     edx, [eax]
                push    eax
                mov     eax, [edx+4]
                call    eax
                xor     eax, eax
                retn    0Ch
loc_4CF54D:                             ; CODE XREF: Interface1_QueryInterface+14j
                mov     eax, 80004002h
                retn    0Ch
Interface1_QueryInterface      endp

; ---------------------------------------------------------------------------

; int __stdcall Interface1_Release(void *pUnknown)
Interface1_Release         proc near               ; DATA XREF: .rdata:00517A98o

pUnknown        = dword ptr  4

                mov     ecx, [esp+pUnknown]
                add     dword ptr [ecx+4], 0FFFFFFFFh
                mov     eax, [ecx+4]
                jnz     short locret_4CF585
                push    ecx             ; Memory
                mov     dword ptr [ecx], offset off_517A90
                mov     dword ptr [ecx+8], 0
                call    j__free
                add     esp, 4
                xor     eax, eax

locret_4CF585:                          ; CODE XREF: Interface1_Release+Bj
                retn    4
Interface1_Release         endp

; ---------------------------------------------------------------------------

sub_4CF590      proc near               ; DATA XREF: .rdata:00517AB4o

arg_0           = dword ptr  4
arg_4           = byte ptr  8
arg_8           = dword ptr  0Ch
arg_C           = dword ptr  10h

                mov     eax, [esp+arg_0]
                mov     edx, [eax+10h]
                sub     edx, [eax+18h]
                mov     ecx, [eax+14h]
                sbb     ecx, [eax+1Ch]
                push    ebx
                mov     ebx, [esp+4+arg_8]
                push    edi
                mov     edi, [esp+8+arg_C]
                cmp     edi, ecx
                jb      short loc_4CF5C2
                ja      short loc_4CF5B4
                cmp     ebx, edx
                jbe     short loc_4CF5C2

loc_4CF5B4:                             ; CODE XREF: sub_4CF590+1Ej
                pop     edi
                mov     byte ptr [eax+20h], 1
                mov     eax, 80004005h
                pop     ebx
                retn    10h
; ---------------------------------------------------------------------------

loc_4CF5C2:                             ; CODE XREF: sub_4CF590+1Cj
                                        ; sub_4CF590+22j
                push    esi
                xor     esi, esi
                xor     ecx, ecx
                test    edi, edi
                jb      short loc_4CF5FA
                ja      short loc_4CF5D1
                test    ebx, ebx
                jbe     short loc_4CF5FA

loc_4CF5D1:                             ; CODE XREF: sub_4CF590+3Bj
                mov     dl, [esp+0Ch+arg_4]
                push    ebp

loc_4CF5D6:                             ; CODE XREF: sub_4CF590+5Fj
                                        ; sub_4CF590+67j
                mov     ebp, [eax+18h]
                mov     ebx, [eax+8]
                mov     [ebx+ebp], dl
                add     dword ptr [eax+18h], 1
                adc     dword ptr [eax+1Ch], 0
                add     esi, 1
                adc     ecx, 0
                cmp     ecx, edi
                jb      short loc_4CF5D6
                ja      short loc_4CF5F9
                cmp     esi, [esp+10h+arg_8]
                jb      short loc_4CF5D6

loc_4CF5F9:                             ; CODE XREF: sub_4CF590+61j
                pop     ebp

loc_4CF5FA:                             ; CODE XREF: sub_4CF590+39j
                                        ; sub_4CF590+3Fj
                pop     esi
                pop     edi
                xor     eax, eax
                pop     ebx
                retn    10h
sub_4CF590      endp

; =============== S U B R O U T I N E =======================================

; int __stdcall Interface2_Release(void *pUnknown)
Interface2_Release proc near            ; DATA XREF: .rdata:00517AACo
; sub_4CF610

pUnknown        = dword ptr  4

                mov     ecx, [esp+pUnknown]
                add     dword ptr [ecx+4], 0FFFFFFFFh
                mov     eax, [ecx+4]
                jnz     short locret_4CF635
                push    ecx             ; Memory
                mov     dword ptr [ecx], offset off_517AA4
                mov     dword ptr [ecx+8], 0
                call    j__free
                add     esp, 4
                xor     eax, eax

locret_4CF635:                          ; CODE XREF: Interface2_Release+Bj
                retn    4
Interface2_Release endp

; =============== S U B R O U T I N E =======================================

loc_4CF640:                             ; CODE XREF: sub_4CF6E0+39p
                                        ; sub_4CFAC0+57p ...
                push    ecx
                push    ebx
                push    esi
                push    edi
                mov     edi, ecx
                mov     esi, [edi+8]
                cmp     esi, 0FF000000h
                jb      short loc_4CF661
                mov     edx, [edi+0Ch]
                mov     eax, esi
                mov     cl, 20h
                call    __allshr         ; Microsoft VisualC 2-8/net runtime
                test    eax, eax
                jz      short loc_4CF6B6

loc_4CF661:                             ; CODE XREF: .text:004CF64Fj
                mov     bl, [edi+4]
                lea     esi, [edi+18h]

loc_4CF667:                             ; CODE XREF: .text:004CF6A9j
                mov     eax, [edi+8]
                mov     edx, [edi+0Ch]
                mov     cl, 20h
                call    __allshr         ; Microsoft VisualC 2-8/net runtime
                mov     ecx, [esi+4]
                mov     edx, [esi]
                add     al, bl
                mov     [ecx+edx], al
                add     dword ptr [esi+4], 1
                mov     eax, [esi+4]
                cmp     eax, [esi+8]
                jnz     short loc_4CF6A3
                cmp     [esi+0Ch], eax
                jz      short loc_4CF6A3
                nop

loc_4CF690:                             ; CODE XREF: .text:004CF6A1j
                mov     ecx, esi
                call    sub_4CF450
                test    eax, eax
                jnz     short loc_4CF6CB
                mov     eax, [esi+0Ch]
                cmp     eax, [esi+4]
                jnz     short loc_4CF690

loc_4CF6A3:                             ; CODE XREF: .text:004CF688j
                                        ; .text:004CF68Dj
                or      bl, 0FFh
                add     dword ptr [edi], 0FFFFFFFFh
                jnz     short loc_4CF667
                mov     esi, [edi+8]
                mov     edx, esi
                shr     edx, 18h
                mov     [edi+4], dl

loc_4CF6B6:                             ; CODE XREF: .text:004CF65Fj
                add     dword ptr [edi], 1
                shl     esi, 8
                mov     [edi+8], esi
                mov     dword ptr [edi+0Ch], 0
                pop     edi
                pop     esi
                pop     ebx
                pop     ecx
                retn
                
; ---------------------------------------------------------------------------

loc_4CF6CB:                             ; CODE XREF: .text:004CF699j
                push    offset dword_526DD0
                lea     ecx, [esp+10h]
                push    ecx
                mov     [esp+14h], eax
                int     3
;               call    __CxxThrowException@8 ; _CxxThrowException(x,x)
; ---------------------------------------------------------------------------

                db 2 dup(0CCh)

; =============== S U B R O U T I N E =======================================


sub_4CF6E0      proc near               ; CODE XREF: sub_4D0770+FBp
                                        ; CEncoder_CodeOneBlock+6C5p

arg_0           = dword ptr  4
arg_4           = dword ptr  8

                push    esi
                push    edi
                mov     edi, [esp+8+arg_4]
                add     edi, 0FFFFFFFFh
                mov     esi, ecx
                js      short loc_4CF724
                push    ebp
                mov     ebp, [esp+0Ch+arg_0]

loc_4CF6F2:                             ; CODE XREF: sub_4CF6E0+41j
                shr     dword ptr [esi+10h], 1
                mov     eax, [esi+10h]
                mov     edx, ebp
                mov     ecx, edi
                shr     edx, cl
                test    dl, 1
                jz      short loc_4CF70A
                add     [esi+8], eax
                adc     dword ptr [esi+0Ch], 0

loc_4CF70A:                             ; CODE XREF: sub_4CF6E0+21j
                cmp     eax, 1000000h
                jnb     short loc_4CF71E
                shl     eax, 8
                mov     ecx, esi
                mov     [esi+10h], eax
                call    loc_4CF640

loc_4CF71E:                             ; CODE XREF: sub_4CF6E0+2Fj
                sub     edi, 1
                jns     short loc_4CF6F2
                pop     ebp

loc_4CF724:                             ; CODE XREF: sub_4CF6E0+Bj
                pop     edi
                pop     esi
                retn    8
sub_4CF6E0      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CF740      proc near               ; CODE XREF: sub_4D0770+DFp
                                        ; CEncoder_CodeOneBlock+58Ap ...

arg_0           = dword ptr  4

                push    esi
                push    edi
                mov     edi, [esp+8+arg_0]
                mov     eax, edi
                imul    eax, 440h
                mov     esi, ecx
                mov     edx, [esi+4C08h]
                lea     ecx, [eax+esi+808h]
                push    ecx
                push    edx
                push    edi
                mov     ecx, esi
                call    sub_4CDC00
                mov     eax, [esi+4C08h]
                mov     [esi+edi*4+4C0Ch], eax
                pop     edi
                pop     esi
                retn    4
sub_4CF740      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================
              
sub_4CF780      proc near               ; CODE XREF: CEncoder_SetStreams+7Ep
                                        ; CEncoder_SetStreams+A6p

arg_0           = dword ptr  4

                push    esi
                push    edi
                xor     edi, edi
                cmp     [esp+8+arg_0], edi
                mov     esi, ecx
                jbe     short loc_4CF7CC
                push    ebx
                push    ebp
                lea     ebx, [esi+4C0Ch]
                lea     ebp, [esi+808h]
                lea     ebx, [ebx+0]

loc_4CF7A0:                             ; CODE XREF: sub_4CF780+48j
                mov     eax, [esi+4C08h]
                push    ebp
                push    eax
                push    edi
                mov     ecx, esi
                call    sub_4CDC00
                mov     ecx, [esi+4C08h]
                mov     [ebx], ecx
                add     edi, 1
                add     ebx, 4
                add     ebp, 440h
                cmp     edi, [esp+10h+arg_0]
                jb      short loc_4CF7A0
                pop     ebp
                pop     ebx

loc_4CF7CC:                             ; CODE XREF: sub_4CF780+Aj
                pop     edi
                pop     esi
                retn    4
sub_4CF780      endp

; ---------------------------------------------------------------------------
                align 10h
CEncoder_GetOptimum proc near           ; CODE XREF: CEncoder_CodeOneBlock+201p

var_7D          = byte ptr -7Dh
var_7C          = dword ptr -7Ch
var_78          = dword ptr -78h
var_74          = dword ptr -74h
var_70          = dword ptr -70h
var_6C          = dword ptr -6Ch
var_68          = dword ptr -68h
var_64          = dword ptr -64h
var_60          = dword ptr -60h
var_5C          = dword ptr -5Ch
var_58          = dword ptr -58h
var_54          = dword ptr -54h
var_50          = dword ptr -50h
var_4C          = dword ptr -4Ch
var_48          = dword ptr -48h
var_44          = dword ptr -44h
var_40          = dword ptr -40h
var_3C          = dword ptr -3Ch
var_38          = dword ptr -38h
var_34          = dword ptr -34h
var_30          = dword ptr -30h
var_2C          = dword ptr -2Ch
var_28          = dword ptr -28h
var_24          = dword ptr -24h
var_20          = dword ptr -20h
var_1C          = dword ptr -1Ch
var_18          = dword ptr -18h
var_14          = dword ptr -14h
var_10          = dword ptr -10h
arg_0           = dword ptr  4
arg_4           = dword ptr  8

                sub     esp, 80h
                push    ebp
                mov     ebp, ecx
                mov     edx, [ebp+32F0Ch]
                cmp     [ebp+32F08h], edx
                push    esi
                jz      short loc_4CE0A5
                mov     esi, [esp+88h+arg_4]
                lea     eax, [edx+edx*4+1Eh]
                lea     ecx, [ebp+eax*8+0]
                mov     eax, [ecx+10h]
                sub     eax, edx
                mov     edx, [ecx+14h]
                mov     [esi], edx
                mov     ecx, [ecx+10h]
                pop     esi
                mov     [ebp+32F0Ch], ecx
                pop     ebp
                add     esp, 80h
                retn    8
; ---------------------------------------------------------------------------

loc_4CE0A5:                             ; CODE XREF: CEncoder_GetOptimum+16j
                mov     edx, [ebp+80h]
                mov     eax, [ebp+70h]
                push    ebx
                xor     esi, esi
                push    edx
                mov     [ebp+32F08h], esi
                mov     [ebp+32F0Ch], esi
                call    eax
                add     esp, 4
                cmp     byte ptr [ebp+32F10h], 0
                mov     ebx, eax
                mov     [esp+8Ch+var_60], eax
                jnz     short loc_4CE0E4
                lea     ecx, [esp+8Ch+var_70]
                push    ecx
                mov     ecx, ebp
                call    sub_4CB3B0
                mov     [esp+8Ch+var_68], eax
                jmp     short loc_4CE0FF
; ---------------------------------------------------------------------------

loc_4CE0E4:                             ; CODE XREF: CEncoder_GetOptimum+70j
                mov     edx, [ebp+32EFCh]
                mov     eax, [ebp+32F00h]
                mov     [esp+8Ch+var_68], edx
                mov     [esp+8Ch+var_70], eax
                mov     byte ptr [ebp+32F10h], 0

loc_4CE0FF:                             ; CODE XREF: CEncoder_GetOptimum+82j
                mov     ecx, [ebp+80h]
                mov     edx, [ebp+74h]
                push    edi
                push    ecx
                call    edx
                mov     edi, eax
                add     esp, 4
                sub     edi, 1
                cmp     ebx, 2
                jnb     short loc_4CE138
                mov     eax, [esp+90h+arg_4]
                pop     edi
                pop     ebx
                pop     esi
                mov     dword ptr [eax], 0FFFFFFFFh
                mov     eax, 1
                pop     ebp
                add     esp, 80h
                retn    8
; ---------------------------------------------------------------------------

loc_4CE138:                             ; CODE XREF: CEncoder_GetOptimum+B7j
                cmp     ebx, 111h
                jbe     short loc_4CE149
                mov     ebx, 111h
                mov     [esp+90h+var_60], ebx

loc_4CE149:                             ; CODE XREF: CEncoder_GetOptimum+DEj
                lea     ecx, [ebp+14h]
                mov     [esp+90h+var_50], esi
                mov     [esp+90h+var_64], esi
                xor     edx, edx
                mov     [esp+90h+var_4C], esi
                mov     [esp+90h+var_6C], ecx
                mov     edi, edi

loc_4CE160:                             ; CODE XREF: CEncoder_GetOptimum+180j
                mov     eax, [esp+90h+var_6C]
                mov     eax, [eax]
                mov     ecx, edi
                sub     ecx, eax
                mov     [esp+edx+90h+var_20], eax
                mov     al, [edi]
                sub     ecx, 1
                cmp     al, [ecx]
                jnz     short loc_4CE1C9
                mov     al, [edi+1]
                cmp     al, [ecx+1]
                jnz     short loc_4CE1C9
                mov     eax, 2
                cmp     ebx, eax
                jbe     short loc_4CE1A7
                lea     esi, [edi+2]
                sub     ecx, edi
                lea     ecx, [ecx+0]

loc_4CE190:                             ; CODE XREF: CEncoder_GetOptimum+143j
                mov     bl, [esi]
                cmp     bl, [ecx+esi]
                mov     ebx, [esp+90h+var_60]
                jnz     short loc_4CE1A5
                add     eax, 1
                add     esi, 1
                cmp     eax, ebx
                jb      short loc_4CE190

loc_4CE1A5:                             ; CODE XREF: CEncoder_GetOptimum+139j
                xor     esi, esi

loc_4CE1A7:                             ; CODE XREF: CEncoder_GetOptimum+126j
                mov     ecx, [esp+90h+var_4C]
                mov     [esp+edx+90h+var_10], eax
                cmp     eax, [esp+ecx+90h+var_10]
                jbe     short loc_4CE1D0
                mov     eax, [esp+90h+var_64]
                mov     [esp+90h+var_50], eax
                mov     [esp+90h+var_4C], edx
                jmp     short loc_4CE1D0
; ---------------------------------------------------------------------------

loc_4CE1C9:                             ; CODE XREF: CEncoder_GetOptimum+115j
                                        ; CEncoder_GetOptimum+11Dj
                mov     [esp+edx+90h+var_10], esi

loc_4CE1D0:                             ; CODE XREF: CEncoder_GetOptimum+159j
                                        ; CEncoder_GetOptimum+167j
                add     [esp+90h+var_64], 1
                add     [esp+90h+var_6C], 4
                add     edx, 4
                cmp     edx, 10h
                jb      loc_4CE160
                mov     ecx, [esp+90h+var_50]
                mov     ebx, [esp+ecx*4+90h+var_10]
                mov     eax, [ebp+32EF8h]
                cmp     ebx, eax
                mov     [esp+90h+var_40], ebx
                jb      short loc_4CE234
                mov     edx, [esp+90h+arg_4]
                lea     eax, [ebx-1]
                cmp     eax, esi
                mov     [edx], ecx
                jz      short loc_4CE225
                add     [ebp+32F04h], eax
                mov     ecx, [ebp+7Ch]
                push    eax
                mov     eax, [ebp+80h]
                push    eax
                call    ecx
                add     esp, 8

loc_4CE225:                             ; CODE XREF: CEncoder_GetOptimum+1ADj
                pop     edi
                mov     eax, ebx
                pop     ebx
                pop     esi
                pop     ebp
                add     esp, 80h
                retn    8
; ---------------------------------------------------------------------------

loc_4CE234:                             ; CODE XREF: CEncoder_GetOptimum+19Dj
                mov     esi, [esp+90h+var_68]
                cmp     esi, eax
                jb      short loc_4CE27F
                mov     edx, [esp+90h+var_70]
                mov     eax, [ebp+edx*4+3265Ch]
                mov     ecx, [esp+90h+arg_4]
                add     eax, 4
                mov     [ecx], eax
                lea     eax, [esi-1]
                test    eax, eax
                jz      short loc_4CE270
                mov     edx, [ebp+80h]
                add     [ebp+32F04h], eax
                push    eax
                mov     eax, [ebp+7Ch]
                push    edx
                call    eax
                add     esp, 8

loc_4CE270:                             ; CODE XREF: CEncoder_GetOptimum+1F8j
                pop     edi
                pop     ebx
                mov     eax, esi
                pop     esi
                pop     ebp
                add     esp, 80h
                retn    8
; ---------------------------------------------------------------------------

loc_4CE27F:                             ; CODE XREF: CEncoder_GetOptimum+1DAj
                mov     al, [edi]
                mov     esi, [esp+90h+var_20]
                sub     edi, esi
                cmp     [esp+90h+var_68], 2
                mov     cl, [edi-1]
                mov     byte ptr [esp+90h+var_4C], al
                mov     byte ptr [esp+90h+var_50], cl
                jnb     short loc_4CE2C1
                cmp     al, cl
                jz      short loc_4CE2C1
                cmp     ebx, 2
                jnb     short loc_4CE2C1
                mov     ecx, [esp+90h+arg_4]
                pop     edi
                pop     ebx
                pop     esi
                mov     dword ptr [ecx], 0FFFFFFFFh
                mov     eax, 1
                pop     ebp
                add     esp, 80h
                retn    8
; ---------------------------------------------------------------------------

loc_4CE2C1:                             ; CODE XREF: CEncoder_GetOptimum+237j
                                        ; CEncoder_GetOptimum+23Bj ...
                mov     edx, [esp+90h+var_4C]
                mov     bl, [ebp+10h]
                mov     edi, [ebp+33B60h]
                and     edi, [esp+90h+arg_0]
                mov     ecx, [esp+90h+var_50]
                push    edx
                cmp     bl, 7
                setnb   dl
                push    ecx
                mov     [ebp+0F0h], bl
                mov     eax, [ebp+32654h]
                mov     ecx, 8
                sub     cl, al
                push    edx
                movzx   edx, byte ptr [ebp+11h]
                shr     edx, cl
                mov     ecx, [ebp+3265Ch]
                and     ecx, [esp+9Ch+arg_0]
                mov     [esp+9Ch+var_3C], ecx
                mov     ecx, eax
                mov     eax, [esp+9Ch+var_3C]
                shl     eax, cl
                add     edx, eax
                imul    edx, 0C00h
                add     edx, [ebp+32650h]
                mov     ecx, edx
                call    sub_4CDAC0
                movzx   ecx, bl
                shl     ecx, 4
                add     ecx, edi
                mov     edx, [ebp+ecx*4+280F0h]
                shr     edx, 2
                add     eax, dword_550998[edx*4]
                mov     ebx, 800h
                mov     [ebp+124h], eax
                mov     dword ptr [ebp+12Ch], 0FFFFFFFFh
                mov     byte ptr [ebp+119h], 0
                mov     cl, [ebp+10h]
                movzx   eax, cl
                mov     edx, eax
                shl     edx, 4
                add     edx, edi
                sub     ebx, [ebp+edx*4+280F0h]
                mov     edx, 800h
                sub     edx, [ebp+eax*4+283F0h]
                mov     al, byte ptr [esp+90h+var_4C]
                shr     edx, 2
                mov     edx, dword_550998[edx*4]
                shr     ebx, 2
                mov     ebx, dword_550998[ebx*4]
                add     edx, ebx
                cmp     byte ptr [esp+90h+var_50], al
                mov     [esp+90h+var_44], ebx
                mov     [esp+90h+var_3C], edx
                jnz     short loc_4CE3F3
                movzx   eax, cl
                mov     ebx, [ebp+eax*4+28420h]
                mov     ecx, eax
                shl     ecx, 4
                add     ecx, edi
                mov     ecx, [ebp+ecx*4+284B0h]
                shr     ecx, 2
                mov     eax, dword_550998[ecx*4]
                shr     ebx, 2
                add     eax, dword_550998[ebx*4]
                add     eax, edx
                cmp     eax, [ebp+124h]
                jnb     short loc_4CE3F3
                mov     [ebp+124h], eax
                mov     dword ptr [ebp+12Ch], 0
                mov     byte ptr [ebp+119h], 0

loc_4CE3F3:                             ; CODE XREF: CEncoder_GetOptimum+344j
                                        ; CEncoder_GetOptimum+37Aj
                mov     eax, [esp+90h+var_68]
                mov     ecx, [esp+90h+var_40]
                cmp     eax, ecx
                jb      short loc_4CE405
                mov     [esp+90h+var_7C], eax
                jmp     short loc_4CE40B
; ---------------------------------------------------------------------------

loc_4CE405:                             ; CODE XREF: CEncoder_GetOptimum+39Dj
                mov     [esp+90h+var_7C], ecx
                mov     eax, ecx

loc_4CE40B:                             ; CODE XREF: CEncoder_GetOptimum+3A3j
                cmp     eax, 2
                jnb     short loc_4CE431
                mov     edx, [ebp+12Ch]
                mov     eax, [esp+90h+arg_4]
                pop     edi
                pop     ebx
                pop     esi
                mov     [eax], edx
                mov     eax, 1
                pop     ebp
                add     esp, 80h
                retn    8
; ---------------------------------------------------------------------------

loc_4CE431:                             ; CODE XREF: CEncoder_GetOptimum+3AEj
                mov     ecx, [esp+90h+var_1C]
                mov     edx, [esp+90h+var_18]
                xor     ebx, ebx
                mov     [ebp+128h], ebx
                mov     [ebp+10Ch], ecx
                mov     ecx, [esp+90h+var_14]
                mov     [ebp+110h], edx
                lea     edx, [eax+eax*4]
                mov     [ebp+114h], ecx
                mov     [ebp+108h], esi
                lea     ecx, [ebp+edx*8+0FCh]
                jmp     short loc_4CE470
; ---------------------------------------------------------------------------
                align 10h

loc_4CE470:                             ; CODE XREF: CEncoder_GetOptimum+407j
                                        ; CEncoder_GetOptimum+41Fj
                mov     dword ptr [ecx], 0FFFFFFFh
                sub     eax, 1
                sub     ecx, 28h
                cmp     eax, 2
                jnb     short loc_4CE470

loc_4CE481:                             ; CODE XREF: CEncoder_GetOptimum+48Ej
                mov     esi, [esp+ebx*4+90h+var_10]
                cmp     esi, 2
                jb      short loc_4CE4E8
                movzx   eax, byte ptr [ebp+10h]
                push    edi
                push    eax
                push    ebx
                mov     ecx, ebp
                call    sub_4CD9B0
                add     eax, [esp+90h+var_3C]
                mov     ecx, edi
                imul    ecx, 110h
                add     ecx, esi
                mov     [esp+90h+var_40], eax
                lea     edx, [esi+esi*4]
                lea     eax, [ebp+ecx*4+2E204h]
                lea     ecx, [ebp+edx*8+0FCh]
                mov     edi, edi

loc_4CE4C0:                             ; CODE XREF: CEncoder_GetOptimum+486j
                mov     edx, [eax]
                add     edx, [esp+90h+var_40]
                cmp     edx, [ecx]
                jnb     short loc_4CE4DA
                mov     [ecx], edx
                mov     dword ptr [ecx+4], 0
                mov     [ecx+8], ebx
                mov     byte ptr [ecx-0Bh], 0

loc_4CE4DA:                             ; CODE XREF: CEncoder_GetOptimum+468j
                sub     esi, 1
                sub     eax, 4
                sub     ecx, 28h
                cmp     esi, 2
                jnb     short loc_4CE4C0

loc_4CE4E8:                             ; CODE XREF: CEncoder_GetOptimum+42Bj
                add     ebx, 1
                cmp     ebx, 4
                jb      short loc_4CE481
                movzx   eax, byte ptr [ebp+10h]
                mov     ecx, [ebp+eax*4+283F0h]
                shr     ecx, 2
                mov     eax, dword_550998[ecx*4]
                add     eax, [esp+90h+var_44]
                mov     [esp+90h+var_3C], eax
                mov     eax, [esp+90h+var_10]
                cmp     eax, 2
                lea     ebx, [eax+1]
                jnb     short loc_4CE521
                mov     ebx, 2

loc_4CE521:                             ; CODE XREF: CEncoder_GetOptimum+4BAj
                cmp     ebx, [esp+90h+var_68]
                ja      loc_4CE5BA
                xor     eax, eax
                cmp     ebx, [ebp+32660h]
                mov     [esp+90h+var_60], eax
                jbe     short loc_4CE550
                lea     esp, [esp+0]

loc_4CE540:                             ; CODE XREF: CEncoder_GetOptimum+4EAj
                add     eax, 2
                cmp     ebx, [ebp+eax*4+32660h]
                ja      short loc_4CE540
                mov     [esp+90h+var_60], eax

loc_4CE550:                             ; CODE XREF: CEncoder_GetOptimum+4D7j
                lea     edx, [ebx+ebx*4]
                lea     esi, [ebp+edx*8+0FCh]
                lea     ebx, [ebx+0]

loc_4CE560:                             ; CODE XREF: CEncoder_GetOptimum+558j
                mov     eax, [esp+90h+var_60]
                mov     eax, [ebp+eax*4+32664h]
                push    edi
                push    ebx
                push    eax
                mov     ecx, ebp
                mov     [esp+9Ch+var_40], eax
                call    sub_4CAEC0
                add     eax, [esp+90h+var_3C]
                cmp     eax, [esi]
                jnb     short loc_4CE598
                mov     ecx, [esp+90h+var_40]
                add     ecx, 4
                mov     [esi], eax
                mov     dword ptr [esi+4], 0
                mov     [esi+8], ecx
                mov     byte ptr [esi-0Bh], 0

loc_4CE598:                             ; CODE XREF: CEncoder_GetOptimum+51Fj
                mov     eax, [esp+90h+var_60]
                cmp     ebx, [ebp+eax*4+32660h]
                jnz     short loc_4CE5B2
                add     eax, 2
                cmp     eax, [esp+90h+var_70]
                mov     [esp+90h+var_60], eax
                jz      short loc_4CE5BA

loc_4CE5B2:                             ; CODE XREF: CEncoder_GetOptimum+543j
                add     ebx, 1
                add     esi, 28h
                jmp     short loc_4CE560
; ---------------------------------------------------------------------------

loc_4CE5BA:                             ; CODE XREF: CEncoder_GetOptimum+4C5j
                                        ; CEncoder_GetOptimum+550j
                mov     eax, 1
                cmp     [esp+90h+var_7C], eax
                mov     [esp+90h+var_78], eax
                jz      loc_4CF1D0
                mov     esi, eax
                jmp     short loc_4CE5D5
; ---------------------------------------------------------------------------

loc_4CE5D1:                             ; CODE XREF: CEncoder_GetOptimum+116Aj
                mov     esi, [esp+90h+var_78]

loc_4CE5D5:                             ; CODE XREF: CEncoder_GetOptimum+56Fj
                mov     edx, [ebp+80h]
                mov     eax, [ebp+70h]
                push    edx
                call    eax
                add     esp, 4
                lea     ecx, [esp+90h+var_4C]
                push    ecx
                mov     ecx, ebp
                mov     [esp+94h+var_60], eax
                call    sub_4CB3B0
                cmp     eax, [ebp+32EF8h]
                mov     [esp+90h+var_28], eax
                jnb     loc_4CF1D7
                add     [esp+90h+arg_0], 1
                lea     edx, [esi+esi*4+1Eh]
                mov     bl, [ebp+edx*8+1]
                test    bl, bl
                lea     eax, [ebp+edx*8+0]
                mov     edx, [eax+10h]
                jz      short loc_4CE673
                sub     edx, 1
                cmp     byte ptr [eax+2], 0
                jz      short loc_4CE660
                mov     ecx, [eax+4]
                add     ecx, 6
                cmp     dword ptr [eax+8], 4
                lea     ecx, [ecx+ecx*4]
                mov     cl, [ebp+ecx*8+0]
                movzx   ecx, cl
                jnb     short loc_4CE64F
                mov     cl, ds:kRepNextStates[ecx]
                movzx   ecx, cl
                mov     cl, ds:kLiteralNextStates[ecx]
                jmp     short loc_4CE67B
; ---------------------------------------------------------------------------

loc_4CE64F:                             ; CODE XREF: CEncoder_GetOptimum+5DCj
                mov     cl, ds:kMatchNextStates[ecx]
                movzx   ecx, cl
                mov     cl, ds:kLiteralNextStates[ecx]
                jmp     short loc_4CE67B
; ---------------------------------------------------------------------------

loc_4CE660:                             ; CODE XREF: CEncoder_GetOptimum+5C6j
                lea     ecx, [edx+edx*4+1Eh]
                mov     cl, [ebp+ecx*8+0]
                movzx   ecx, cl
                mov     cl, ds:kLiteralNextStates[ecx]
                jmp     short loc_4CE67B
; ---------------------------------------------------------------------------

loc_4CE673:                             ; CODE XREF: CEncoder_GetOptimum+5BDj
                lea     ecx, [edx+edx*4+1Eh]
                mov     cl, [ebp+ecx*8+0]

loc_4CE67B:                             ; CODE XREF: CEncoder_GetOptimum+5EDj
                                        ; CEncoder_GetOptimum+5FEj ...
                add     esi, 0FFFFFFFFh
                cmp     edx, esi
                jnz     short loc_4CE6AC
                cmp     dword ptr [eax+14h], 0
                jnz     short loc_4CE69A
                movzx   edx, cl
                mov     bl, ds:kShortRepNextStates[edx]
                mov     byte ptr [esp+90h+var_64], bl
                jmp     loc_4CE754
; ---------------------------------------------------------------------------

loc_4CE69A:                             ; CODE XREF: CEncoder_GetOptimum+626j
                movzx   ecx, cl
                mov     bl, ds:kLiteralNextStates[ecx]
                mov     byte ptr [esp+90h+var_64], bl
                jmp     loc_4CE754
; ---------------------------------------------------------------------------

loc_4CE6AC:                             ; CODE XREF: CEncoder_GetOptimum+620j
                test    bl, bl
                jz      short loc_4CE6CB
                cmp     byte ptr [eax+2], 0
                jz      short loc_4CE6CB
                mov     edi, [eax+8]
                mov     edx, [eax+4]
                movzx   ecx, cl
                mov     bl, ds:kRepNextStates[ecx]
                mov     [esp+90h+var_68], edi
                jmp     short loc_4CE6EA
; ---------------------------------------------------------------------------

loc_4CE6CB:                             ; CODE XREF: CEncoder_GetOptimum+64Ej
                                        ; CEncoder_GetOptimum+654j
                mov     esi, [eax+14h]
                cmp     esi, 4
                mov     [esp+90h+var_68], esi
                movzx   ecx, cl
                mov     edi, esi
                jnb     short loc_4CE6E4
                mov     bl, ds:kRepNextStates[ecx]
                jmp     short loc_4CE6EA
; ---------------------------------------------------------------------------

loc_4CE6E4:                             ; CODE XREF: CEncoder_GetOptimum+67Aj
                mov     bl, ds:kMatchNextStates[ecx]

loc_4CE6EA:                             ; CODE XREF: CEncoder_GetOptimum+669j
                                        ; CEncoder_GetOptimum+682j
                cmp     edi, 4
                lea     edx, [edx+edx*4+1Eh]
                mov     byte ptr [esp+90h+var_64], bl
                lea     edx, [ebp+edx*8+0]
                jnb     short loc_4CE738
                mov     ecx, [edx+edi*4+18h]
                mov     esi, 1
                cmp     edi, esi
                mov     [esp+90h+var_20], ecx
                jb      short loc_4CE723
                mov     ecx, edi
                lea     esi, [edx+18h]
                lea     edi, [esp+90h+var_1C]
                rep movsd
                mov     esi, [esp+90h+var_68]
                add     esi, 1
                cmp     esi, 4
                jnb     short loc_4CE754

loc_4CE723:                             ; CODE XREF: CEncoder_GetOptimum+6AAj
                lea     edx, [edx+esi*4+18h]
                mov     ecx, 4
                lea     edi, [esp+esi*4+90h+var_20]
                sub     ecx, esi
                mov     esi, edx
                rep movsd
                jmp     short loc_4CE754
; ---------------------------------------------------------------------------

loc_4CE738:                             ; CODE XREF: CEncoder_GetOptimum+699j
                mov     ecx, [edx+18h]
                mov     [esp+90h+var_1C], ecx
                mov     ecx, [edx+1Ch]
                mov     edx, [edx+20h]
                add     edi, 0FFFFFFFCh
                mov     [esp+90h+var_20], edi
                mov     [esp+90h+var_18], ecx
                mov     [esp+90h+var_14], edx

loc_4CE754:                             ; CODE XREF: CEncoder_GetOptimum+635j
                                        ; CEncoder_GetOptimum+647j ...
                mov     ecx, [esp+90h+var_1C]
                mov     edx, [esp+90h+var_18]
                mov     edi, [esp+90h+var_20]
                mov     [eax], bl
                mov     [eax+1Ch], ecx
                mov     ecx, [esp+90h+var_14]
                mov     [eax+18h], edi
                mov     [eax+20h], edx
                mov     [eax+24h], ecx
                mov     esi, [eax+0Ch]
                mov     edx, [ebp+80h]
                mov     eax, [ebp+74h]
                push    edx
                mov     [esp+94h+var_3C], esi
                call    eax
                movzx   ecx, byte ptr [eax-1]
                sub     eax, 1
                mov     edx, eax
                mov     byte ptr [esp+94h+var_5C], cl
                sub     edx, edi
                movzx   ecx, byte ptr [edx-1]
                lea     edi, [edx-1]
                mov     edx, [ebp+32654h]
                mov     byte ptr [esp+94h+var_58], cl
                mov     ecx, [ebp+33B60h]
                and     ecx, [esp+94h+arg_0]
                mov     [esp+94h+var_40], edi
                movzx   edi, bl
                mov     [esp+94h+var_54], ecx
                mov     [esp+94h+var_68], edi
                add     esp, 4
                shl     edi, 4
                add     edi, ecx
                mov     ecx, [esp+90h+var_5C]
                push    ecx
                mov     ecx, [esp+94h+var_58]
                push    ecx
                cmp     bl, 7
                mov     ebx, [ebp+3265Ch]
                setnb   cl
                and     ebx, [esp+98h+arg_0]
                mov     [esp+98h+var_74], eax
                movzx   eax, byte ptr [eax-1]
                push    ecx
                mov     ecx, 8
                sub     cl, dl
                shr     eax, cl
                mov     ecx, edx
                shl     ebx, cl
                add     eax, ebx
                imul    eax, 0C00h
                add     eax, [ebp+32650h]
                mov     ecx, eax
                call    sub_4CDAC0
                mov     ecx, [ebp+edi*4+280F0h]
                shr     ecx, 2
                add     eax, dword_550998[ecx*4]
                mov     ecx, [esp+90h+var_78]
                add     eax, esi
                lea     edx, [ecx+ecx*4+23h]
                cmp     eax, [ebp+edx*8+0Ch]
                lea     esi, [ebp+edx*8+0]
                mov     [esp+90h+var_7D], 0
                jnb     short loc_4CE851
                mov     [esi+0Ch], eax
                mov     [esi+10h], ecx
                mov     dword ptr [esi+14h], 0FFFFFFFFh
                mov     byte ptr [esi+1], 0
                mov     [esp+90h+var_7D], 1

loc_4CE851:                             ; CODE XREF: CEncoder_GetOptimum+7D9j
                mov     ebx, [esp+90h+var_68]
                mov     edx, 800h
                sub     edx, [ebp+edi*4+280F0h]
                shr     edx, 2
                mov     ecx, dword_550998[edx*4]
                add     ecx, [esp+90h+var_3C]
                mov     edx, 800h
                sub     edx, [ebp+ebx*4+283F0h]
                mov     ebx, [esp+90h+var_78]
                shr     edx, 2
                mov     edx, dword_550998[edx*4]
                add     edx, ecx
                mov     [esp+90h+var_24], ecx
                mov     cl, byte ptr [esp+90h+var_58]
                cmp     cl, byte ptr [esp+90h+var_5C]
                mov     [esp+90h+var_38], edx
                jnz     short loc_4CE8EB
                cmp     [esi+10h], ebx
                jnb     short loc_4CE8A8
                cmp     dword ptr [esi+14h], 0
                jz      short loc_4CE8EB

loc_4CE8A8:                             ; CODE XREF: CEncoder_GetOptimum+840j
                mov     ecx, [esp+90h+var_68]
                mov     ecx, [ebp+ecx*4+28420h]
                mov     edi, [ebp+edi*4+284B0h]
                shr     ecx, 2
                mov     ecx, dword_550998[ecx*4]
                shr     edi, 2
                add     ecx, dword_550998[edi*4]
                add     ecx, edx
                cmp     ecx, [esi+0Ch]
                ja      short loc_4CE8EB
                mov     [esi+0Ch], ecx
                mov     [esi+10h], ebx
                mov     dword ptr [esi+14h], 0
                mov     byte ptr [esi+1], 0
                mov     [esp+90h+var_7D], 1

loc_4CE8EB:                             ; CODE XREF: CEncoder_GetOptimum+83Bj
                                        ; CEncoder_GetOptimum+846j ...
                mov     edx, [esp+90h+var_60]
                mov     ecx, 0FFFh
                sub     ecx, ebx
                cmp     ecx, edx
                jnb     short loc_4CE900
                mov     edx, ecx
                mov     [esp+90h+var_60], edx

loc_4CE900:                             ; CODE XREF: CEncoder_GetOptimum+898j
                cmp     edx, 2
                mov     ebx, edx
                mov     [esp+90h+var_6C], ebx
                jb      loc_4CF1BB
                mov     esi, [ebp+32EF8h]
                mov     edi, [esp+90h+var_60]
                cmp     edi, esi
                jbe     short loc_4CE923
                mov     ebx, esi
                mov     [esp+90h+var_6C], esi

loc_4CE923:                             ; CODE XREF: CEncoder_GetOptimum+8BBj
                cmp     [esp+90h+var_7D], 0
                jnz     loc_4CEA90
                mov     dl, byte ptr [esp+90h+var_5C]
                cmp     byte ptr [esp+90h+var_58], dl
                jz      loc_4CEA90
                lea     ecx, [esi+1]
                cmp     edi, ecx
                jb      short loc_4CE945
                mov     edi, ecx

loc_4CE945:                             ; CODE XREF: CEncoder_GetOptimum+8E1j
                mov     esi, 1
                cmp     edi, esi
                jbe     short loc_4CE975
                mov     ebx, [esp+90h+var_74]
                mov     edx, [esp+90h+var_40]
                lea     ecx, [ebx+1]
                sub     edx, ebx
                jmp     short loc_4CE960
; ---------------------------------------------------------------------------
                align 10h

loc_4CE960:                             ; CODE XREF: CEncoder_GetOptimum+8FBj
                                        ; CEncoder_GetOptimum+90Fj
                mov     bl, [ecx]
                cmp     bl, [edx+ecx]
                jnz     short loc_4CE971
                add     esi, 1
                add     ecx, 1
                cmp     esi, edi
                jb      short loc_4CE960

loc_4CE971:                             ; CODE XREF: CEncoder_GetOptimum+905j
                mov     ebx, [esp+90h+var_6C]

loc_4CE975:                             ; CODE XREF: CEncoder_GetOptimum+8ECj
                add     esi, 0FFFFFFFFh
                cmp     esi, 2
                mov     [esp+90h+var_50], esi
                jb      loc_4CEA90
                mov     ecx, [esp+90h+var_68]
                mov     dl, ds:kLiteralNextStates[ecx]
                mov     ecx, [esp+90h+arg_0]
                movzx   ebx, dl
                add     ecx, 1
                and     ecx, [ebp+33B60h]
                mov     edx, ebx
                shl     edx, 4
                lea     esi, [edx+ecx]
                mov     edx, 800h
                sub     edx, [ebp+ebx*4+283F0h]
                mov     edi, 800h
                sub     edi, [ebp+esi*4+280F0h]
                shr     edx, 2
                mov     edx, dword_550998[edx*4]
                shr     edi, 2
                add     edx, dword_550998[edi*4]
                mov     edi, [esp+90h+var_78]
                add     edx, eax
                mov     eax, [esp+90h+var_50]
                lea     edi, [eax+edi+1]
                mov     eax, [esp+90h+var_7C]
                cmp     eax, edi
                mov     [esp+90h+var_40], esi
                jnb     short loc_4CEA22
                mov     esi, [esp+90h+var_7C]
                lea     eax, [eax+eax*4]
                lea     eax, [ebp+eax*8+0FCh]
                mov     [esp+90h+var_3C], eax
                mov     eax, edi
                sub     eax, esi
                add     esi, eax
                mov     [esp+90h+var_7C], esi
                mov     esi, [esp+90h+var_3C]

loc_4CEA10:                             ; CODE XREF: CEncoder_GetOptimum+9BCj
                add     esi, 28h
                sub     eax, 1
                mov     dword ptr [esi], 0FFFFFFFh
                jnz     short loc_4CEA10
                mov     esi, [esp+90h+var_40]

loc_4CEA22:                             ; CODE XREF: CEncoder_GetOptimum+98Ej
                imul    ecx, 110h
                add     ecx, [esp+90h+var_50]
                mov     eax, 800h
                sub     eax, [ebp+esi*4+284B0h]
                mov     esi, [ebp+ebx*4+28420h]
                mov     ebx, [esp+90h+var_6C]
                shr     eax, 2
                mov     eax, dword_550998[eax*4]
                shr     esi, 2
                add     eax, dword_550998[esi*4]
                mov     esi, [esp+90h+var_7C]
                add     eax, [ebp+ecx*4+2E204h]
                lea     ecx, [edi+edi*4+1Eh]
                add     eax, edx
                cmp     eax, [ebp+ecx*8+0Ch]
                lea     ecx, [ebp+ecx*8+0]
                jnb     short loc_4CEA94
                mov     edx, [esp+90h+var_78]
                add     edx, 1
                mov     [ecx+0Ch], eax
                mov     [ecx+10h], edx
                mov     dword ptr [ecx+14h], 0
                mov     byte ptr [ecx+1], 1
                mov     byte ptr [ecx+2], 0
                jmp     short loc_4CEA94
; ---------------------------------------------------------------------------

loc_4CEA90:                             ; CODE XREF: CEncoder_GetOptimum+8C8j
                                        ; CEncoder_GetOptimum+8D6j ...
                mov     esi, [esp+90h+var_7C]

loc_4CEA94:                             ; CODE XREF: CEncoder_GetOptimum+A10j
                                        ; CEncoder_GetOptimum+A2Ej
                mov     [esp+90h+var_70], 0
                mov     ecx, [esp+90h+var_70]
                mov     [esp+90h+var_40], 2
                jmp     short loc_4CEAB8
; ---------------------------------------------------------------------------
                align 10h

loc_4CEAB0:                             ; CODE XREF: CEncoder_GetOptimum+D63j
                mov     ebx, [esp+90h+var_6C]
                mov     esi, [esp+90h+var_7C]

loc_4CEAB8:                             ; CODE XREF: CEncoder_GetOptimum+A48j
                mov     edx, [esp+90h+var_74]
                mov     eax, edx
                sub     eax, [esp+ecx*4+90h+var_20]
                mov     cl, [edx]
                sub     eax, 1
                cmp     cl, [eax]
                mov     [esp+90h+var_48], eax
                jnz     loc_4CEDB5
                mov     cl, [edx+1]
                cmp     cl, [eax+1]
                jnz     loc_4CEDB5
                mov     edi, 2
                cmp     ebx, edi
                jbe     short loc_4CEB01
                lea     ecx, [edx+2]
                sub     eax, edx
                lea     ecx, [ecx+0]

loc_4CEAF0:                             ; CODE XREF: CEncoder_GetOptimum+A9Fj
                mov     dl, [ecx]
                cmp     dl, [eax+ecx]
                jnz     short loc_4CEB01
                add     edi, 1
                add     ecx, 1
                cmp     edi, ebx
                jb      short loc_4CEAF0

loc_4CEB01:                             ; CODE XREF: CEncoder_GetOptimum+A86j
                                        ; CEncoder_GetOptimum+A95j
                mov     eax, [esp+90h+var_78]
                lea     ebx, [edi+eax]
                cmp     esi, ebx
                jnb     short loc_4CEB2E
                mov     eax, ebx
                lea     ecx, [esi+esi*4]
                sub     eax, esi
                add     esi, eax
                lea     ecx, [ebp+ecx*8+0FCh]
                mov     [esp+90h+var_7C], esi

loc_4CEB20:                             ; CODE XREF: CEncoder_GetOptimum+ACCj
                add     ecx, 28h
                sub     eax, 1
                mov     dword ptr [ecx], 0FFFFFFFh
                jnz     short loc_4CEB20

loc_4CEB2E:                             ; CODE XREF: CEncoder_GetOptimum+AAAj
                mov     edx, [esp+90h+var_54]
                mov     eax, [esp+90h+var_64]
                mov     ecx, [esp+90h+var_70]
                push    edx
                push    eax
                push    ecx
                mov     ecx, ebp
                mov     esi, edi
                call    sub_4CD9B0
                add     eax, [esp+90h+var_38]
                mov     ecx, [esp+90h+var_54]
                imul    ecx, 110h
                lea     edx, [edi+ecx]
                mov     [esp+90h+var_34], ecx
                lea     ecx, [ebp+edx*4+2E204h]
                mov     [esp+90h+var_50], ecx
                lea     edx, [ebx+ebx*4]
                mov     ebx, [esp+90h+var_50]
                mov     [esp+90h+var_2C], eax
                lea     ecx, [ebp+edx*8+0FCh]

loc_4CEB78:                             ; CODE XREF: CEncoder_GetOptimum+B40j
                mov     edx, [ebx]
                add     edx, eax
                cmp     edx, [ecx]
                jnb     short loc_4CEB94
                mov     [ecx], edx
                mov     edx, [esp+90h+var_78]
                mov     [ecx+4], edx
                mov     edx, [esp+90h+var_70]
                mov     [ecx+8], edx
                mov     byte ptr [ecx-0Bh], 0

loc_4CEB94:                             ; CODE XREF: CEncoder_GetOptimum+B1Ej
                sub     edi, 1
                sub     ebx, 4
                sub     ecx, 28h
                cmp     edi, 2
                jnb     short loc_4CEB78
                cmp     [esp+90h+var_70], 0
                jnz     short loc_4CEBB0
                lea     eax, [esi+1]
                mov     [esp+90h+var_40], eax

loc_4CEBB0:                             ; CODE XREF: CEncoder_GetOptimum+B47j
                mov     ecx, [ebp+32EF8h]
                mov     edx, [esp+90h+var_60]
                lea     eax, [esi+1]
                add     ecx, eax
                cmp     edx, ecx
                jnb     short loc_4CEBC5
                mov     ecx, edx

loc_4CEBC5:                             ; CODE XREF: CEncoder_GetOptimum+B61j
                cmp     eax, ecx
                jnb     short loc_4CEBE7
                mov     ebx, [esp+90h+var_74]
                mov     edi, [esp+90h+var_48]
                lea     edx, [eax+ebx]
                sub     edi, ebx

loc_4CEBD6:                             ; CODE XREF: CEncoder_GetOptimum+B85j
                mov     bl, [edx]
                cmp     bl, [edx+edi]
                jnz     short loc_4CEBE7
                add     eax, 1
                add     edx, 1
                cmp     eax, ecx
                jb      short loc_4CEBD6

loc_4CEBE7:                             ; CODE XREF: CEncoder_GetOptimum+B67j
                                        ; CEncoder_GetOptimum+B7Bj
                or      ecx, 0FFFFFFFFh
                sub     ecx, esi
                add     eax, ecx
                cmp     eax, 2
                mov     [esp+90h+var_44], eax
                jb      loc_4CEDB5
                mov     edx, [esp+90h+var_68]
                mov     cl, ds:kRepNextStates[edx]
                mov     eax, [ebp+33B60h]
                mov     edi, [esp+90h+arg_0]
                movzx   ecx, cl
                mov     ebx, eax
                lea     edx, [esi+edi]
                and     ebx, edx
                mov     edx, ecx
                mov     cl, ds:kLiteralNextStates[ecx]
                shl     edx, 4
                add     ebx, edx
                mov     edx, [ebp+ebx*4+280F0h]
                movzx   ebx, cl
                shr     edx, 2
                mov     edx, dword_550998[edx*4]
                mov     [esp+90h+var_30], edx
                lea     edi, [esi+edi+1]
                and     edi, eax
                mov     eax, [ebp+32654h]
                mov     ecx, ebx
                shl     ecx, 4
                add     ecx, edi
                mov     [esp+90h+var_50], ecx
                mov     ecx, [esp+90h+var_74]
                movzx   edx, byte ptr [esi+ecx]
                push    edx
                mov     edx, [esp+94h+var_48]
                movzx   edx, byte ptr [esi+edx]
                push    edx
                movzx   edx, byte ptr [ecx+esi-1]
                mov     ecx, 8
                sub     cl, al
                shr     edx, cl
                mov     ecx, [esp+98h+arg_0]
                lea     eax, [esi+ecx]
                mov     ecx, [ebp+3265Ch]
                and     ecx, eax
                mov     eax, ecx
                mov     ecx, [ebp+32654h]
                shl     eax, cl
                push    1
                add     edx, eax
                imul    edx, 0C00h
                add     edx, [ebp+32650h]
                mov     ecx, edx
                call    sub_4CDAC0
                mov     ecx, [esp+90h+var_50]
                mov     edx, 800h
                sub     edx, [ebp+ecx*4+280F0h]
                mov     ecx, [esp+90h+var_34]
                shr     edx, 2
                add     eax, dword_550998[edx*4]
                mov     edx, 800h
                sub     edx, [ebp+ebx*4+283F0h]
                shr     edx, 2
                add     eax, dword_550998[edx*4]
                lea     edx, [esi+ecx]
                add     eax, [ebp+edx*4+2E204h]
                mov     ecx, [esp+90h+var_44]
                add     eax, [esp+90h+var_30]
                mov     edx, [esp+90h+var_78]
                add     eax, [esp+90h+var_2C]
                add     ecx, esi
                lea     ecx, [ecx+edx+1]
                cmp     [esp+90h+var_7C], ecx
                mov     [esp+90h+var_30], ecx
                jnb     short loc_4CED3E
                mov     edx, [esp+90h+var_7C]
                lea     edx, [edx+edx*4]
                lea     edx, [ebp+edx*8+0FCh]
                mov     [esp+90h+var_2C], edx
                mov     edx, [esp+90h+var_7C]
                sub     ecx, edx
                add     edx, ecx
                mov     [esp+90h+var_7C], edx
                mov     edx, [esp+90h+var_2C]
                jmp     short loc_4CED30
; ---------------------------------------------------------------------------
                align 10h

loc_4CED30:                             ; CODE XREF: CEncoder_GetOptimum+CCBj
                                        ; CEncoder_GetOptimum+CDCj
                add     edx, 28h
                sub     ecx, 1
                mov     dword ptr [edx], 0FFFFFFFh
                jnz     short loc_4CED30

loc_4CED3E:                             ; CODE XREF: CEncoder_GetOptimum+CA7j
                mov     edx, [esp+90h+var_50]
                imul    edi, 110h
                add     edi, [esp+90h+var_44]
                mov     ecx, 800h
                sub     ecx, [ebp+edx*4+284B0h]
                mov     edx, [ebp+ebx*4+28420h]
                shr     ecx, 2
                mov     ecx, dword_550998[ecx*4]
                shr     edx, 2
                add     ecx, dword_550998[edx*4]
                add     ecx, [ebp+edi*4+2E204h]
                add     ecx, eax
                mov     eax, [esp+90h+var_30]
                lea     eax, [eax+eax*4+1Eh]
                cmp     ecx, [ebp+eax*8+0Ch]
                lea     eax, [ebp+eax*8+0]
                jnb     short loc_4CEDB5
                mov     [eax+0Ch], ecx
                mov     ecx, [esp+90h+var_78]
                lea     edx, [esi+ecx+1]
                mov     [eax+4], ecx
                mov     ecx, [esp+90h+var_70]
                mov     [eax+10h], edx
                mov     dword ptr [eax+14h], 0
                mov     byte ptr [eax+1], 1
                mov     byte ptr [eax+2], 1
                mov     [eax+8], ecx

loc_4CEDB5:                             ; CODE XREF: CEncoder_GetOptimum+A6Dj
                                        ; CEncoder_GetOptimum+A79j ...
                mov     ecx, [esp+90h+var_70]
                add     ecx, 1
                cmp     ecx, 4
                mov     [esp+90h+var_70], ecx
                jb      loc_4CEAB0
                mov     edx, [esp+90h+var_28]
                mov     ecx, [esp+90h+var_6C]
                cmp     edx, ecx
                jbe     short loc_4CEDFB
                xor     eax, eax
                cmp     ecx, [ebp+32660h]
                mov     edx, ecx
                jbe     short loc_4CEDED

loc_4CEDE1:                             ; CODE XREF: CEncoder_GetOptimum+D8Bj
                add     eax, 2
                cmp     ecx, [ebp+eax*4+32660h]
                ja      short loc_4CEDE1

loc_4CEDED:                             ; CODE XREF: CEncoder_GetOptimum+D7Fj
                mov     [ebp+eax*4+32660h], ecx
                add     eax, 2
                mov     [esp+90h+var_4C], eax

loc_4CEDFB:                             ; CODE XREF: CEncoder_GetOptimum+D73j
                mov     esi, [esp+90h+var_40]
                cmp     edx, esi
                jb      loc_4CF1BB
                mov     eax, [esp+90h+var_68]
                mov     ecx, [ebp+eax*4+283F0h]
                shr     ecx, 2
                mov     eax, dword_550998[ecx*4]
                add     eax, [esp+90h+var_24]
                mov     ecx, [esp+90h+var_7C]
                mov     [esp+90h+var_40], eax
                mov     eax, [esp+90h+var_78]
                add     eax, edx
                cmp     ecx, eax
                jnb     short loc_4CEE52
                lea     edx, [ecx+ecx*4]
                sub     eax, ecx
                add     ecx, eax
                lea     edx, [ebp+edx*8+0FCh]
                mov     [esp+90h+var_7C], ecx

loc_4CEE44:                             ; CODE XREF: CEncoder_GetOptimum+DF0j
                add     edx, 28h
                sub     eax, 1
                mov     dword ptr [edx], 0FFFFFFFh
                jnz     short loc_4CEE44

loc_4CEE52:                             ; CODE XREF: CEncoder_GetOptimum+DD0j
                xor     eax, eax
                cmp     esi, [ebp+32660h]
                mov     [esp+90h+var_70], eax
                jbe     short loc_4CEE70

loc_4CEE60:                             ; CODE XREF: CEncoder_GetOptimum+E0Aj
                add     eax, 2
                cmp     esi, [ebp+eax*4+32660h]
                ja      short loc_4CEE60
                mov     [esp+90h+var_70], eax

loc_4CEE70:                             ; CODE XREF: CEncoder_GetOptimum+DFEj
                lea     ebx, ds:0[eax*4]
                mov     edx, [ebx+ebp+32664h]
                mov     ecx, 7FFFFh
                sub     ecx, edx
                sar     ecx, 1Fh
                and     ecx, 0Ch
                add     ecx, 6
                mov     eax, edx
                shr     eax, cl
                mov     [esp+90h+var_6C], edx
                lea     edi, [esi+1]
                movzx   eax, byte ptr dword_551198[eax]
                lea     ecx, [eax+ecx*2]
                mov     eax, [esp+90h+var_54]
                imul    eax, 110h
                add     eax, esi
                lea     eax, [ebp+eax*4+295B8h]
                mov     [esp+90h+var_3C], ecx
                mov     ecx, [esp+90h+var_78]
                mov     [esp+90h+var_54], eax
                lea     eax, [esi+ecx]
                lea     eax, [eax+eax*4]
                lea     ecx, [ebp+eax*8+0FCh]
                mov     [esp+90h+var_50], ecx

loc_4CEED3:                             ; CODE XREF: CEncoder_GetOptimum+1156j
                lea     eax, [edi-3]
                cmp     eax, 4
                jb      short loc_4CEEE0
                mov     eax, 3

loc_4CEEE0:                             ; CODE XREF: CEncoder_GetOptimum+E79j
                cmp     edx, 80h
                jnb     short loc_4CEEF6
                shl     eax, 7
                add     eax, edx
                mov     eax, [ebp+eax*4+33314h]
                jmp     short loc_4CEF10
; ---------------------------------------------------------------------------

loc_4CEEF6:                             ; CODE XREF: CEncoder_GetOptimum+E86j
                shl     eax, 6
                add     eax, [esp+90h+var_3C]
                mov     esi, edx
                mov     eax, [ebp+eax*4+32F14h]
                and     esi, 0Fh
                add     eax, [ebp+esi*4+33B14h]

loc_4CEF10:                             ; CODE XREF: CEncoder_GetOptimum+E94j
                add     eax, [esp+90h+var_40]
                mov     esi, [esp+90h+var_54]
                add     eax, [esi]
                cmp     eax, [ecx]
                mov     [esp+90h+var_2C], eax
                jnb     short loc_4CEF35
                mov     [ecx], eax
                mov     eax, [esp+90h+var_78]
                add     edx, 4
                mov     [ecx+4], eax
                mov     [ecx+8], edx
                mov     byte ptr [ecx-0Bh], 0

loc_4CEF35:                             ; CODE XREF: CEncoder_GetOptimum+EC0j
                lea     eax, [edi-1]
                cmp     eax, [ebx+ebp+32660h]
                jnz     loc_4CF1A1
                mov     ebx, [esp+90h+var_74]
                mov     eax, [ebp+32EF8h]
                mov     esi, [esp+90h+var_60]
                mov     edx, ebx
                sub     edx, [esp+90h+var_6C]
                add     eax, edi
                sub     edx, 1
                cmp     esi, eax
                mov     ecx, edi
                jnb     short loc_4CEF6C
                mov     eax, esi
                mov     [esp+90h+var_44], esi
                jmp     short loc_4CEF70
; ---------------------------------------------------------------------------

loc_4CEF6C:                             ; CODE XREF: CEncoder_GetOptimum+F02j
                mov     [esp+90h+var_44], eax

loc_4CEF70:                             ; CODE XREF: CEncoder_GetOptimum+F0Aj
                cmp     edi, eax
                jnb     short loc_4CEF93
                lea     esi, [edi+edx]
                sub     ebx, edx
                lea     esp, [esp+0]

loc_4CEF80:                             ; CODE XREF: CEncoder_GetOptimum+F31j
                mov     al, [ebx+esi]
                cmp     al, [esi]
                jnz     short loc_4CEF93
                add     ecx, 1
                add     esi, 1
                cmp     ecx, [esp+90h+var_44]
                jb      short loc_4CEF80

loc_4CEF93:                             ; CODE XREF: CEncoder_GetOptimum+F12j
                                        ; CEncoder_GetOptimum+F25j
                or      esi, 0FFFFFFFFh
                lea     eax, [edi-1]
                sub     esi, eax
                add     ecx, esi
                cmp     ecx, 2
                mov     [esp+90h+var_48], ecx
                jb      loc_4CF157
                mov     ecx, [esp+90h+var_68]
                mov     bl, ds:kMatchNextStates[ecx]
                mov     ecx, [ebp+33B60h]
                mov     eax, [esp+90h+arg_0]
                lea     esi, [edi+eax-1]
                mov     eax, ecx
                and     eax, esi
                movzx   esi, bl
                movzx   edx, byte ptr [edi+edx-1]
                mov     ebx, esi
                shl     ebx, 4
                add     ebx, eax
                mov     ebx, [ebp+ebx*4+280F0h]
                shr     ebx, 2
                mov     ebx, dword_550998[ebx*4]
                mov     [esp+90h+var_28], ebx
                mov     bl, ds:kLiteralNextStates[esi]
                lea     esi, [eax+1]
                mov     eax, [ebp+32654h]
                and     esi, ecx
                movzx   ebx, bl
                mov     ecx, ebx
                shl     ecx, 4
                add     ecx, esi
                mov     [esp+90h+var_44], ecx
                mov     ecx, [esp+90h+var_74]
                movzx   ecx, byte ptr [ecx+edi-1]
                push    ecx
                mov     ecx, [esp+94h+var_74]
                push    edx
                movzx   edx, byte ptr [edi+ecx-2]
                mov     ecx, 8
                sub     cl, al
                shr     edx, cl
                mov     ecx, [esp+98h+arg_0]
                lea     eax, [edi+ecx-1]
                mov     ecx, [ebp+3265Ch]
                and     ecx, eax
                mov     eax, ecx
                mov     ecx, [ebp+32654h]
                shl     eax, cl
                push    1
                add     edx, eax
                imul    edx, 0C00h
                add     edx, [ebp+32650h]
                mov     ecx, edx
                call    sub_4CDAC0
                mov     edx, 800h
                sub     edx, [ebp+ebx*4+283F0h]
                mov     ecx, 800h
                shr     edx, 2
                add     eax, dword_550998[edx*4]
                mov     edx, [esp+90h+var_44]
                sub     ecx, [ebp+edx*4+280F0h]
                mov     edx, [esp+90h+var_78]
                shr     ecx, 2
                add     eax, dword_550998[ecx*4]
                mov     ecx, [esp+90h+var_48]
                add     eax, [esp+90h+var_28]
                add     ecx, edx
                add     eax, [esp+90h+var_2C]
                add     ecx, edi
                cmp     [esp+90h+var_7C], ecx
                mov     [esp+90h+var_28], ecx
                jnb     short loc_4CF0DE
                mov     edx, [esp+90h+var_7C]
                lea     edx, [edx+edx*4]
                lea     edx, [ebp+edx*8+0FCh]
                mov     [esp+90h+var_24], edx
                mov     edx, [esp+90h+var_7C]
                sub     ecx, edx
                add     edx, ecx
                mov     [esp+90h+var_7C], edx
                mov     edx, [esp+90h+var_24]
                lea     ecx, [ecx+0]

loc_4CF0D0:                             ; CODE XREF: CEncoder_GetOptimum+107Cj
                add     edx, 28h
                sub     ecx, 1
                mov     dword ptr [edx], 0FFFFFFFh
                jnz     short loc_4CF0D0

loc_4CF0DE:                             ; CODE XREF: CEncoder_GetOptimum+1049j
                mov     edx, [esp+90h+var_44]
                imul    esi, 110h
                add     esi, [esp+90h+var_48]
                mov     ecx, 800h
                sub     ecx, [ebp+edx*4+284B0h]
                mov     edx, [ebp+ebx*4+28420h]
                shr     ecx, 2
                mov     ecx, dword_550998[ecx*4]
                shr     edx, 2
                add     ecx, dword_550998[edx*4]
                add     ecx, [ebp+esi*4+2E204h]
                add     ecx, eax
                mov     eax, [esp+90h+var_28]
                lea     eax, [eax+eax*4+1Eh]
                cmp     ecx, [ebp+eax*8+0Ch]
                lea     eax, [ebp+eax*8+0]
                jnb     short loc_4CF157
                mov     [eax+0Ch], ecx
                mov     ecx, [esp+90h+var_78]
                lea     edx, [ecx+edi]
                mov     [eax+4], ecx
                mov     ecx, [esp+90h+var_6C]
                add     ecx, 4
                mov     [eax+10h], edx
                mov     dword ptr [eax+14h], 0
                mov     byte ptr [eax+1], 1
                mov     byte ptr [eax+2], 1
                mov     [eax+8], ecx

loc_4CF157:                             ; CODE XREF: CEncoder_GetOptimum+F44j
                                        ; CEncoder_GetOptimum+10CCj
                mov     eax, [esp+90h+var_70]
                add     eax, 2
                cmp     eax, [esp+90h+var_4C]
                mov     [esp+90h+var_70], eax
                jz      short loc_4CF1BB
                lea     ebx, ds:0[eax*4]
                mov     eax, [ebx+ebp+32664h]
                cmp     eax, 80h
                mov     [esp+90h+var_6C], eax
                jb      short loc_4CF1A1
                mov     ecx, 7FFFFh
                sub     ecx, eax
                sar     ecx, 1Fh
                and     ecx, 0Ch
                add     ecx, 6
                shr     eax, cl
                movzx   edx, byte ptr dword_551198[eax]
                lea     eax, [edx+ecx*2]
                mov     [esp+90h+var_3C], eax

loc_4CF1A1:                             ; CODE XREF: CEncoder_GetOptimum+EDFj
                                        ; CEncoder_GetOptimum+111Fj
                add     [esp+90h+var_50], 28h
                add     [esp+90h+var_54], 4
                mov     ecx, [esp+90h+var_50]
                mov     edx, [esp+90h+var_6C]
                add     edi, 1
                jmp     loc_4CEED3
; ---------------------------------------------------------------------------

loc_4CF1BB:                             ; CODE XREF: CEncoder_GetOptimum+8A9j
                                        ; CEncoder_GetOptimum+DA1j ...
                mov     eax, [esp+90h+var_78]
                add     eax, 1
                cmp     eax, [esp+90h+var_7C]
                mov     [esp+90h+var_78], eax
                jnz     loc_4CE5D1

loc_4CF1D0:                             ; CODE XREF: CEncoder_GetOptimum+567j
                mov     ecx, [esp+90h+var_78]
                push    ecx
                jmp     short loc_4CF1EF
; ---------------------------------------------------------------------------

loc_4CF1D7:                             ; CODE XREF: CEncoder_GetOptimum+59Ej
                mov     ecx, [esp+90h+var_4C]
                mov     [ebp+32F00h], ecx
                mov     [ebp+32EFCh], eax
                mov     byte ptr [ebp+32F10h], 1
                push    esi

loc_4CF1EF:                             ; CODE XREF: CEncoder_GetOptimum+1175j
                mov     edx, [esp+94h+arg_4]
                push    edx
                mov     ecx, ebp
                call    sub_4CB2E0
                pop     edi
                pop     ebx
                pop     esi
                pop     ebp
                add     esp, 80h
                retn    8
CEncoder_GetOptimum endp

; ---------------------------------------------------------------------------
                align 10h

loc_4CF210:                             ; DATA XREF: CEncoder_CodeOneBlock+44o
                mov     edx, [esp+10h]
                mov     eax, [esp+4]
                mov     eax, [eax+4]
                mov     ecx, [eax]
                push    edx
                mov     edx, [esp+10h]
                push    edx
                mov     edx, [esp+10h]
                push    edx
                push    eax
                mov     eax, [ecx+0Ch]
                call    eax
                retn
; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

CEncoder_FillDistancesPrices proc near  ; CODE XREF: CEncoder_SetStreams+4Fp
                                        ; CEncoder_CodeOneBlock+751p

var_20C         = dword ptr -20Ch
var_208         = dword ptr -208h
var_204         = dword ptr -204h
var_200         = dword ptr -200h

                sub     esp, 20Ch
                push    ebx
                push    ebp
                push    esi
                push    edi
                mov     ebx, ecx
                mov     esi, 4

loc_4CF241:                             ; CODE XREF: CEncoder_FillDistancesPrices+80j
                cmp     esi, 2000h
                jnb     short loc_4CF252
                movzx   edx, byte ptr dword_551198[esi]
                jmp     short loc_4CF27A
; ---------------------------------------------------------------------------

loc_4CF252:                             ; CODE XREF: CEncoder_FillDistancesPrices+17j
                cmp     esi, 2000000h
                jnb     short loc_4CF26B
                mov     eax, esi
                shr     eax, 0Ch
                movzx   edx, byte ptr dword_551198[eax]
                add     edx, 18h
                jmp     short loc_4CF27A
; ---------------------------------------------------------------------------

loc_4CF26B:                             ; CODE XREF: CEncoder_FillDistancesPrices+28j
                mov     ecx, esi
                shr     ecx, 18h
                movzx   edx, byte ptr dword_551198[ecx]
                add     edx, 30h

loc_4CF27A:                             ; CODE XREF: CEncoder_FillDistancesPrices+20j
                                        ; CEncoder_FillDistancesPrices+39j
                mov     ecx, edx
                mov     eax, edx
                and     eax, 1
                shr     ecx, 1
                sub     ecx, 1
                or      eax, 2
                shl     eax, cl
                mov     edi, esi
                sub     edi, eax
                push    edi
                sub     eax, edx
                push    ecx
                lea     edx, [ebx+eax*4+28BACh]
                push    edx
                call    sub_4CD860
                mov     [esp+esi*4+228h+var_200], eax
                add     esi, 1
                add     esp, 0Ch
                cmp     esi, 80h
                jb      short loc_4CF241
                lea     ebp, [esp+21Ch+var_200]
                sub     ebp, ebx
                lea     esi, [ebx+3331Ch]
                sub     ebp, 33314h
                lea     edx, [ebx+32F14h]
                mov     [esp+21Ch+var_20C], esi
                mov     [esp+21Ch+var_208], ebp
                mov     [esp+21Ch+var_204], 4
                jmp     short loc_4CF2E4
; ---------------------------------------------------------------------------
                align 10h

loc_4CF2E0:                             ; CODE XREF: CEncoder_FillDistancesPrices+1BDj
                mov     esi, [esp+21Ch+var_20C]

loc_4CF2E4:                             ; CODE XREF: CEncoder_FillDistancesPrices+AAj
                xor     edi, edi
                cmp     [ebx+33B58h], edi
                jbe     short loc_4CF33F
                mov     edi, edi

loc_4CF2F0:                             ; CODE XREF: CEncoder_FillDistancesPrices+109j
                mov     ecx, edi
                or      ecx, 40h
                xor     esi, esi
                cmp     ecx, 1
                jz      short loc_4CF32D
                lea     esp, [esp+0]

loc_4CF300:                             ; CODE XREF: CEncoder_FillDistancesPrices+F7j
                mov     eax, ecx
                shr     ecx, 1
                mov     ebp, [edx+ecx*4-0A764h]
                and     eax, 1
                sub     ebp, eax
                neg     eax
                xor     ebp, eax
                shr     ebp, 2
                and     ebp, 1FFh
                add     esi, dword_550998[ebp*4]
                cmp     ecx, 1
                jnz     short loc_4CF300
                mov     ebp, [esp+21Ch+var_208]

loc_4CF32D:                             ; CODE XREF: CEncoder_FillDistancesPrices+CAj
                mov     [edx+edi*4], esi
                add     edi, 1
                cmp     edi, [ebx+33B58h]
                jb      short loc_4CF2F0
                mov     esi, [esp+21Ch+var_20C]

loc_4CF33F:                             ; CODE XREF: CEncoder_FillDistancesPrices+BCj
                mov     eax, 0Eh
                cmp     [ebx+33B58h], eax
                jbe     short loc_4CF368
                lea     esp, [esp+0]

loc_4CF350:                             ; CODE XREF: CEncoder_FillDistancesPrices+136j
                mov     ecx, eax
                shr     ecx, 1
                sub     ecx, 5
                shl     ecx, 6
                add     [edx+eax*4], ecx
                add     eax, 1
                cmp     eax, [ebx+33B58h]
                jb      short loc_4CF350

loc_4CF368:                             ; CODE XREF: CEncoder_FillDistancesPrices+11Aj
                mov     eax, [edx]
                mov     [esi-8], eax
                mov     ecx, [edx+4]
                mov     [esi-4], ecx
                mov     eax, [edx+8]
                mov     [esi], eax
                mov     ecx, [edx+0Ch]
                mov     [esi+4], ecx
                mov     eax, 4
                add     esi, 8

loc_4CF386:                             ; CODE XREF: CEncoder_FillDistancesPrices+19Ej
                cmp     eax, 2000h
                jnb     short loc_4CF396
                movzx   ecx, byte ptr dword_551198[eax]
                jmp     short loc_4CF3BB
; ---------------------------------------------------------------------------

loc_4CF396:                             ; CODE XREF: CEncoder_FillDistancesPrices+15Bj
                cmp     eax, 2000000h
                mov     ecx, eax
                jnb     short loc_4CF3AE
                shr     ecx, 0Ch
                movzx   ecx, byte ptr dword_551198[ecx]
                add     ecx, 18h
                jmp     short loc_4CF3BB
; ---------------------------------------------------------------------------

loc_4CF3AE:                             ; CODE XREF: CEncoder_FillDistancesPrices+16Dj
                shr     ecx, 18h
                movzx   ecx, byte ptr dword_551198[ecx]
                add     ecx, 30h

loc_4CF3BB:                             ; CODE XREF: CEncoder_FillDistancesPrices+164j
                                        ; CEncoder_FillDistancesPrices+17Cj
                mov     ecx, [edx+ecx*4]
                add     ecx, [esi+ebp]
                add     eax, 1
                mov     [esi], ecx
                add     esi, 4
                cmp     eax, 80h
                jb      short loc_4CF386
                add     [esp+21Ch+var_20C], 200h
                sub     ebp, 200h
                add     edx, 100h
                sub     [esp+21Ch+var_204], 1
                mov     [esp+21Ch+var_208], ebp
                jnz     loc_4CF2E0
                pop     edi
                pop     esi
                pop     ebp
                mov     dword ptr [ebx+33B70h], 0
                pop     ebx
                add     esp, 20Ch
                retn
CEncoder_FillDistancesPrices endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

CEncoder_FillAlignPrices proc near      ; CODE XREF: CEncoder_SetStreams+56p
                                        ; CEncoder_CodeOneBlock+761p
                push    ebx
                push    ebp
                push    esi
                mov     ebp, ecx
                push    edi
                xor     esi, esi
                lea     ebx, [ebp+28D78h]
                lea     edi, [ebp+33B14h]

loc_4CF424:                             ; CODE XREF: CEncoder_FillAlignPrices+27j
                push    esi
                mov     ecx, ebx
                call    sub_4CD810
                mov     [edi], eax
                add     esi, 1
                add     edi, 4
                cmp     esi, 10h
                jb      short loc_4CF424
                pop     edi
                pop     esi
                mov     dword ptr [ebp+33B54h], 0
                pop     ebp
                pop     ebx
                retn
CEncoder_FillAlignPrices endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CF810      proc near               ; CODE XREF: sub_4D0250+3p

var_10          = dword ptr -10h
var_C           = dword ptr -0Ch
var_4           = dword ptr -4

                push    0FFFFFFFFh
                push    offset loc_4DA0C9
                mov     eax, dword ptr fs:[0]
                push    eax
                push    ecx
                push    ebx
                push    esi
                mov     eax, dword_544960
                xor     eax, esp
                push    eax
                lea     eax, [esp+1Ch+var_C]
                mov     dword ptr fs:[0], eax
                mov     esi, ecx
                mov     [esp+1Ch+var_10], esi
                mov     dword ptr [esi], offset NCompress_NLZMA_CEncoder_vftable
                mov     dword ptr [esi+4], offset NCompress_NLZMA_CEncoder_vftable_ICompressSetOutStream
                mov     dword ptr [esi+8], offset NCompress_NLZMA_CEncoder_vftable_ICompressSetCoderProperties
                mov     dword ptr [esi+0Ch], offset NCompress_NLZMA_CEncoder_vftable_ICompressWriteCoderProperties
                mov     eax, [esi+0A4h]
                push    eax             ; lpAddress
                mov     [esp+20h+var_4], 1
                call    off_546E24
                xor     ebx, ebx
                add     esp, 4
                cmp     [esi+0D0h], ebx
                mov     [esi+0A4h], ebx
                jnz     short loc_4CF892
                mov     ecx, [esi+0B4h]
                push    ecx             ; lpAddress
                call    off_546E24
                add     esp, 4
                mov     [esi+0B4h], ebx

loc_4CF892:                             ; CODE XREF: sub_4CF810+6Aj
                mov     eax, [esi+33B8Ch]
                cmp     eax, ebx
                jz      short loc_4CF8A4
                mov     edx, [eax]
                push    eax
                mov     eax, [edx+8]
                call    eax

loc_4CF8A4:                             ; CODE XREF: sub_4CF810+8Aj
                lea     ecx, [esi+32650h]
                mov     byte ptr [esp+1Ch+var_4], bl
                call    sub_4CD8F0
                mov     eax, [esi+40h]
                cmp     eax, ebx
                mov     [esp+1Ch+var_4], 0FFFFFFFFh
                jz      short loc_4CF8CF
                push    8000h           ; dwFreeType
                push    ebx             ; dwSize
                push    eax             ; lpAddress
                call    ds:VirtualFree

loc_4CF8CF:                             ; CODE XREF: sub_4CF810+B0j
                mov     [esi+40h], ebx
                mov     esi, [esi+54h]
                cmp     esi, ebx
                jz      short loc_4CF8E1
                mov     ecx, [esi]
                mov     edx, [ecx+8]
                push    esi
                call    edx

loc_4CF8E1:                             ; CODE XREF: sub_4CF810+C7j
                mov     ecx, [esp+1Ch+var_C]
                mov     dword ptr fs:[0], ecx
                pop     ecx
                pop     esi
                pop     ebx
                add     esp, 10h
                retn
sub_4CF810      endp

; =============== S U B R O U T I N E =======================================

; int __stdcall sub_4CF900(int, void *Buf1, int)
sub_4CF900      proc near               ; CODE XREF: sub_4CFA20+5j
                                        ; ICompressSetCoderProperties_QueryInterface+5j ...

arg_0           = dword ptr  4
Buf1            = dword ptr  8
arg_8           = dword ptr  0Ch

                push    esi
                mov     esi, [esp+4+Buf1]
                push    offset dword_512730 ; Buf2
                push    esi             ; Buf1
                call    unknown_libname_324 ; MFC 3.1/4.0/4.2/8.0 32bit
                add     esp, 8
                test    eax, eax
                jz      short loc_4CF94C

loc_4CF917:                             ; CODE XREF: sub_4CF900+5Cj
                mov     eax, [esp+4+arg_0]
                test    eax, eax
                jz      short loc_4CF936
                mov     edx, [esp+4+arg_8]
                lea     ecx, [eax+4]
                mov     [edx], ecx
                mov     ecx, [eax]
                mov     edx, [ecx+4]
                push    eax
                call    edx
                xor     eax, eax
                pop     esi
                retn    0Ch
; ---------------------------------------------------------------------------

loc_4CF936:                             ; CODE XREF: sub_4CF900+1Dj
                                        ; sub_4CF900+76j ...
                mov     edx, [esp+4+arg_8]
                xor     ecx, ecx
                mov     [edx], ecx
                mov     ecx, [eax]
                mov     edx, [ecx+4]
                push    eax
                call    edx
                xor     eax, eax
                pop     esi
                retn    0Ch
; ---------------------------------------------------------------------------

loc_4CF94C:                             ; CODE XREF: sub_4CF900+15j
                push    offset dword_5535A0 ; Buf2
                push    esi             ; Buf1
                call    unknown_libname_324 ; MFC 3.1/4.0/4.2/8.0 32bit
                add     esp, 8
                test    eax, eax
                jnz     short loc_4CF917
                push    offset dword_5535B0 ; Buf2
                push    esi             ; Buf1
                call    unknown_libname_324 ; MFC 3.1/4.0/4.2/8.0 32bit
                add     esp, 8
                test    eax, eax
                jz      short loc_4CF98F
                mov     eax, [esp+4+arg_0]
                test    eax, eax
                jz      short loc_4CF936
                mov     edx, [esp+4+arg_8]
                lea     ecx, [eax+8]
                mov     [edx], ecx
                mov     ecx, [eax]
                mov     edx, [ecx+4]
                push    eax
                call    edx
                xor     eax, eax
                pop     esi
                retn    0Ch
; ---------------------------------------------------------------------------

loc_4CF98F:                             ; CODE XREF: sub_4CF900+6Ej
                push    offset dword_5535C0 ; Buf2
                push    esi             ; Buf1
                call    unknown_libname_324 ; MFC 3.1/4.0/4.2/8.0 32bit
                add     esp, 8
                test    eax, eax
                jz      short loc_4CF9C0
                mov     eax, [esp+4+arg_0]
                test    eax, eax
                jz      short loc_4CF936
                mov     edx, [esp+4+arg_8]
                lea     ecx, [eax+0Ch]
                mov     [edx], ecx
                mov     ecx, [eax]
                mov     edx, [ecx+4]
                push    eax
                call    edx
                xor     eax, eax
                pop     esi
                retn    0Ch
; ---------------------------------------------------------------------------

loc_4CF9C0:                             ; CODE XREF: sub_4CF900+9Fj
                mov     eax, 80004002h
                pop     esi
                retn    0Ch
sub_4CF900      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================


sub_4CF9D0      proc near               ; CODE XREF: ICompressSetCoderProperties_AddRef+5j
                                        ; sub_4CFA10+5j ...

arg_0           = dword ptr  4

                mov     eax, [esp+arg_0]
                add     dword ptr [eax+24h], 1
                mov     eax, [eax+24h]
                retn    4
sub_4CF9D0      endp

; ---------------------------------------------------------------------------
                align 10h

; =============== S U B R O U T I N E =======================================


sub_4CF9E0      proc near               ; CODE XREF: sub_4CFA40+5j
                                        ; ICompressSetCoderProperties_Release+5j ...

arg_0           = dword ptr  4

                mov     ecx, [esp+arg_0]
                add     dword ptr [ecx+24h], 0FFFFFFFFh
                mov     eax, [ecx+24h]
                jnz     short locret_4CF9F8
                mov     eax, [ecx]
                mov     edx, [eax+10h]
                push    1
                call    edx
                xor     eax, eax

locret_4CF9F8:                          ; CODE XREF: sub_4CF9E0+Bj
                retn    4
sub_4CF9E0      endp

; ---------------------------------------------------------------------------
                align 10h

; =============== S U B R O U T I N E =======================================


ICompressSetCoderProperties_AddRef      proc near               ; DATA XREF: .rdata:00517AD4o

arg_0           = dword ptr  4

                sub     [esp+arg_0], 8
                jmp     sub_4CF9D0
ICompressSetCoderProperties_AddRef      endp

; ---------------------------------------------------------------------------
                align 10h

; =============== S U B R O U T I N E =======================================


sub_4CFA10      proc near               ; DATA XREF: .rdata:00517AC0o

arg_0           = dword ptr  4

                sub     [esp+arg_0], 0Ch
                jmp     sub_4CF9D0
sub_4CFA10      endp

; ---------------------------------------------------------------------------
                align 10h

; =============== S U B R O U T I N E =======================================


sub_4CFA20      proc near               ; DATA XREF: .rdata:NCompress_NLZMA_CEncoder_vftable_ICompressSetOutStreamo

arg_0           = dword ptr  4

                sub     [esp+arg_0], 4
                jmp     sub_4CF900
sub_4CFA20      endp

; ---------------------------------------------------------------------------
                align 10h

; =============== S U B R O U T I N E =======================================


ICompressSetCoderProperties_QueryInterface      proc near               ; DATA XREF: .rdata:NCompress_NLZMA_CEncoder_vftable_ICompressSetCoderPropertieso

arg_0           = dword ptr  4

                sub     [esp+arg_0], 8
                jmp     sub_4CF900
ICompressSetCoderProperties_QueryInterface      endp

; ---------------------------------------------------------------------------
                align 10h

; =============== S U B R O U T I N E =======================================


sub_4CFA40      proc near               ; DATA XREF: .rdata:00517AECo

arg_0           = dword ptr  4

                sub     [esp+arg_0], 4
                jmp     sub_4CF9E0
sub_4CFA40      endp

; ---------------------------------------------------------------------------
                align 10h

; =============== S U B R O U T I N E =======================================


sub_4CFA50      proc near               ; DATA XREF: .rdata:NCompress_NLZMA_CEncoder_vftable_ICompressWriteCoderPropertieso

arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch

                sub     [esp+arg_0], 0Ch
                jmp     sub_4CF900
sub_4CFA50      endp

; ---------------------------------------------------------------------------
                align 10h

; =============== S U B R O U T I N E =======================================


ICompressSetCoderProperties_Release      proc near               ; DATA XREF: .rdata:00517AD8o

arg_0           = dword ptr  4

                sub     [esp+arg_0], 8
                jmp     sub_4CF9E0
ICompressSetCoderProperties_Release      endp

; ---------------------------------------------------------------------------
                align 10h

; =============== S U B R O U T I N E =======================================


sub_4CFA70      proc near               ; DATA XREF: .rdata:00517AC4o

arg_0           = dword ptr  4

                sub     [esp+arg_0], 0Ch
                jmp     sub_4CF9E0
sub_4CFA70      endp

; ---------------------------------------------------------------------------
                align 10h

; =============== S U B R O U T I N E =======================================


sub_4CFA80      proc near               ; DATA XREF: .rdata:00517AE8o

arg_0           = dword ptr  4

                sub     [esp+arg_0], 4
                jmp     sub_4CF9D0
sub_4CFA80      endp

; ---------------------------------------------------------------------------
                align 10h

; =============== S U B R O U T I N E =======================================


sub_4CFA90      proc near               ; DATA XREF: .rdata:00517AF0o

arg_0           = dword ptr  4
arg_4           = dword ptr  8

                push    esi
                mov     esi, [esp+4+arg_4]
                test    esi, esi
                push    edi
                mov     edi, [esp+8+arg_0]
                jz      short loc_4CFAA6
                mov     eax, [esi]
                mov     ecx, [eax+4]
                push    esi
                call    ecx

loc_4CFAA6:                             ; CODE XREF: sub_4CFA90+Cj
                mov     eax, [edi+50h]
                test    eax, eax
                jz      short loc_4CFAB5
                mov     edx, [eax]
                push    eax
                mov     eax, [edx+8]
                call    eax

loc_4CFAB5:                             ; CODE XREF: sub_4CFA90+1Bj
                mov     [edi+50h], esi
                pop     edi
                xor     eax, eax
                pop     esi
                retn    8
sub_4CFA90      endp

; =============== S U B R O U T I N E =======================================

sub_4CFAC0      proc near               ; CODE XREF: CEncoder_CodeOneBlock+42Ap
                                        ; CEncoder_CodeOneBlock+517p

arg_0           = dword ptr  4
arg_4           = dword ptr  8

                mov     eax, [esp+arg_0]
                push    esi
                mov     esi, [eax+10h]
                mov     edx, esi
                shr     edx, 0Bh
                imul    edx, [ecx]
                cmp     [esp+4+arg_4], 0
                jnz     short loc_4CFAEC
                mov     [eax+10h], edx
                mov     edx, [ecx]
                mov     esi, 800h
                sub     esi, edx
                shr     esi, 5
                add     esi, edx
                mov     [ecx], esi
                jmp     short loc_4CFB03
; ---------------------------------------------------------------------------

loc_4CFAEC:                             ; CODE XREF: sub_4CFAC0+15j
                add     [eax+8], edx
                adc     dword ptr [eax+0Ch], 0
                sub     esi, edx
                mov     [eax+10h], esi
                mov     edx, [ecx]
                mov     esi, edx
                shr     esi, 5
                sub     edx, esi
                mov     [ecx], edx

loc_4CFB03:                             ; CODE XREF: sub_4CFAC0+2Aj
                mov     ecx, [eax+10h]
                cmp     ecx, 1000000h
                pop     esi
                jnb     short locret_4CFB1C
                shl     ecx, 8
                mov     [eax+10h], ecx
                mov     ecx, eax
                call    loc_4CF640

locret_4CFB1C:                          ; CODE XREF: sub_4CFAC0+4Dj
                retn    8
sub_4CFAC0      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================


sub_4CFB20      proc near               ; CODE XREF: sub_4D0020+52p
                                        ; sub_4D0020+E4p

arg_0           = dword ptr  4
arg_4           = dword ptr  8

                push    ebx
                push    ebp
                push    esi
                mov     esi, [esp+0Ch+arg_0]
                push    edi
                mov     ebp, ecx
                mov     ebx, 1
                mov     edx, 3

loc_4CFB34:                             ; CODE XREF: sub_4CFB20+8Cj
                mov     edi, [esp+10h+arg_4]
                sub     edx, 1
                mov     ecx, edx
                shr     edi, cl
                mov     ecx, [esi+10h]
                mov     eax, ecx
                shr     eax, 0Bh
                imul    eax, [ebp+ebx*4+0]
                and     edi, 1
                test    edi, edi
                mov     [esp+10h+arg_0], edx
                jnz     short loc_4CFB70
                mov     [esi+10h], eax
                mov     eax, [ebp+ebx*4+0]
                mov     ecx, 800h
                sub     ecx, eax
                shr     ecx, 5
                add     ecx, eax
                mov     [ebp+ebx*4+0], ecx
                jmp     short loc_4CFB8B
; ---------------------------------------------------------------------------

loc_4CFB70:                             ; CODE XREF: sub_4CFB20+35j
                add     [esi+8], eax
                adc     dword ptr [esi+0Ch], 0
                sub     ecx, eax
                mov     [esi+10h], ecx
                mov     eax, [ebp+ebx*4+0]
                mov     ecx, eax
                shr     ecx, 5
                sub     eax, ecx
                mov     [ebp+ebx*4+0], eax

loc_4CFB8B:                             ; CODE XREF: sub_4CFB20+4Ej
                mov     eax, [esi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4CFBA6
                shl     eax, 8
                mov     ecx, esi
                mov     [esi+10h], eax
                call    loc_4CF640
                mov     edx, [esp+10h+arg_0]

loc_4CFBA6:                             ; CODE XREF: sub_4CFB20+73j
                add     ebx, ebx
                or      ebx, edi
                test    edx, edx
                jnz     short loc_4CFB34
                pop     edi
                pop     esi
                pop     ebp
                pop     ebx
                retn    8
sub_4CFB20      endp

; ---------------------------------------------------------------------------
                align 10h

; =============== S U B R O U T I N E =======================================


sub_4CFBC0      proc near               ; CODE XREF: sub_4D0020+136p

arg_0           = dword ptr  4
arg_4           = dword ptr  8

                push    ebx
                push    ebp
                push    esi
                mov     esi, [esp+0Ch+arg_0]
                push    edi
                mov     ebp, ecx
                mov     ebx, 1
                mov     edx, 8

loc_4CFBD4:                             ; CODE XREF: sub_4CFBC0+8Cj
                mov     edi, [esp+10h+arg_4]
                sub     edx, 1
                mov     ecx, edx
                shr     edi, cl
                mov     ecx, [esi+10h]
                mov     eax, ecx
                shr     eax, 0Bh
                imul    eax, [ebp+ebx*4+0]
                and     edi, 1
                test    edi, edi
                mov     [esp+10h+arg_0], edx
                jnz     short loc_4CFC10
                mov     [esi+10h], eax
                mov     eax, [ebp+ebx*4+0]
                mov     ecx, 800h
                sub     ecx, eax
                shr     ecx, 5
                add     ecx, eax
                mov     [ebp+ebx*4+0], ecx
                jmp     short loc_4CFC2B
; ---------------------------------------------------------------------------

loc_4CFC10:                             ; CODE XREF: sub_4CFBC0+35j
                add     [esi+8], eax
                adc     dword ptr [esi+0Ch], 0
                sub     ecx, eax
                mov     [esi+10h], ecx
                mov     eax, [ebp+ebx*4+0]
                mov     ecx, eax
                shr     ecx, 5
                sub     eax, ecx
                mov     [ebp+ebx*4+0], eax

loc_4CFC2B:                             ; CODE XREF: sub_4CFBC0+4Ej
                mov     eax, [esi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4CFC46
                shl     eax, 8
                mov     ecx, esi
                mov     [esi+10h], eax
                call    loc_4CF640
                mov     edx, [esp+10h+arg_0]

loc_4CFC46:                             ; CODE XREF: sub_4CFBC0+73j
                add     ebx, ebx
                or      ebx, edi
                test    edx, edx
                jnz     short loc_4CFBD4
                pop     edi
                pop     esi
                pop     ebp
                pop     ebx
                retn    8
sub_4CFBC0      endp

; ---------------------------------------------------------------------------
                align 10h

; =============== S U B R O U T I N E =======================================


sub_4CFC60      proc near               ; CODE XREF: sub_4D0770+EDp
                                        ; CEncoder_CodeOneBlock+67Cp

arg_0           = dword ptr  4
arg_4           = dword ptr  8

                push    ebx
                push    ebp
                push    esi
                mov     esi, [esp+0Ch+arg_0]
                push    edi
                mov     ebp, ecx
                mov     ebx, 1
                mov     edx, 6

loc_4CFC74:                             ; CODE XREF: sub_4CFC60+8Cj
                mov     edi, [esp+10h+arg_4]
                sub     edx, 1
                mov     ecx, edx
                shr     edi, cl
                mov     ecx, [esi+10h]
                mov     eax, ecx
                shr     eax, 0Bh
                imul    eax, [ebp+ebx*4+0]
                and     edi, 1
                test    edi, edi
                mov     [esp+10h+arg_0], edx
                jnz     short loc_4CFCB0
                mov     [esi+10h], eax
                mov     eax, [ebp+ebx*4+0]
                mov     ecx, 800h
                sub     ecx, eax
                shr     ecx, 5
                add     ecx, eax
                mov     [ebp+ebx*4+0], ecx
                jmp     short loc_4CFCCB
; ---------------------------------------------------------------------------

loc_4CFCB0:                             ; CODE XREF: sub_4CFC60+35j
                add     [esi+8], eax
                adc     dword ptr [esi+0Ch], 0
                sub     ecx, eax
                mov     [esi+10h], ecx
                mov     eax, [ebp+ebx*4+0]
                mov     ecx, eax
                shr     ecx, 5
                sub     eax, ecx
                mov     [ebp+ebx*4+0], eax

loc_4CFCCB:                             ; CODE XREF: sub_4CFC60+4Ej
                mov     eax, [esi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4CFCE6
                shl     eax, 8
                mov     ecx, esi
                mov     [esi+10h], eax
                call    loc_4CF640
                mov     edx, [esp+10h+arg_0]

loc_4CFCE6:                             ; CODE XREF: sub_4CFC60+73j
                add     ebx, ebx
                or      ebx, edi
                test    edx, edx
                jnz     short loc_4CFC74
                pop     edi
                pop     esi
                pop     ebp
                pop     ebx
                retn    8
sub_4CFC60      endp

; ---------------------------------------------------------------------------
                align 10h

; =============== S U B R O U T I N E =======================================


sub_4CFD00      proc near               ; CODE XREF: sub_4D0770+109p
                                        ; CEncoder_CodeOneBlock+6D5p

arg_0           = dword ptr  4
arg_4           = dword ptr  8

                push    ebx
                push    ebp
                push    esi
                mov     esi, [esp+0Ch+arg_0]
                push    edi
                mov     ebp, ecx
                mov     edi, 1
                mov     [esp+10h+arg_0], 4

loc_4CFD17:                             ; CODE XREF: sub_4CFD00+87j
                mov     ecx, [esi+10h]
                mov     ebx, [esp+10h+arg_4]
                mov     eax, ecx
                shr     eax, 0Bh
                imul    eax, [ebp+edi*4+0]
                and     ebx, 1
                test    ebx, ebx
                jnz     short loc_4CFD48
                mov     [esi+10h], eax
                mov     eax, [ebp+edi*4+0]
                mov     ecx, 800h
                sub     ecx, eax
                shr     ecx, 5
                add     ecx, eax
                mov     [ebp+edi*4+0], ecx
                jmp     short loc_4CFD63
; ---------------------------------------------------------------------------

loc_4CFD48:                             ; CODE XREF: sub_4CFD00+2Dj
                add     [esi+8], eax
                adc     dword ptr [esi+0Ch], 0
                sub     ecx, eax
                mov     [esi+10h], ecx
                mov     eax, [ebp+edi*4+0]
                mov     edx, eax
                shr     edx, 5
                sub     eax, edx
                mov     [ebp+edi*4+0], eax

loc_4CFD63:                             ; CODE XREF: sub_4CFD00+46j
                mov     eax, [esi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4CFD7A
                shl     eax, 8
                mov     ecx, esi
                mov     [esi+10h], eax
                call    loc_4CF640

loc_4CFD7A:                             ; CODE XREF: sub_4CFD00+6Bj
                shr     [esp+10h+arg_4], 1
                add     edi, edi
                or      edi, ebx
                sub     [esp+10h+arg_0], 1
                jnz     short loc_4CFD17
                pop     edi
                pop     esi
                pop     ebp
                pop     ebx
                retn    8
sub_4CFD00      endp


; =============== S U B R O U T I N E =======================================


sub_4CFD90      proc near               ; CODE XREF: CEncoder_CodeOneBlock+6AFp

arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch
arg_C           = dword ptr  10h

                mov     eax, [esp+arg_8]
                test    eax, eax
                push    edi
                mov     edi, 1
                jle     loc_4CFE26
                push    ebx
                push    ebp
                mov     ebp, [esp+0Ch+arg_0]
                push    esi
                mov     esi, [esp+10h+arg_4]
                mov     [esp+10h+arg_8], eax

loc_4CFDB1:                             ; CODE XREF: sub_4CFD90+91j
                mov     ecx, [esi+10h]
                mov     ebx, [esp+10h+arg_C]
                mov     eax, ecx
                shr     eax, 0Bh
                imul    eax, [ebp+edi*4+0]
                and     ebx, 1
                test    ebx, ebx
                jnz     short loc_4CFDE2
                mov     [esi+10h], eax
                mov     eax, [ebp+edi*4+0]
                mov     ecx, 800h
                sub     ecx, eax
                shr     ecx, 5
                add     ecx, eax
                mov     [ebp+edi*4+0], ecx
                jmp     short loc_4CFDFD
; ---------------------------------------------------------------------------

loc_4CFDE2:                             ; CODE XREF: sub_4CFD90+37j
                add     [esi+8], eax
                adc     dword ptr [esi+0Ch], 0
                sub     ecx, eax
                mov     [esi+10h], ecx
                mov     eax, [ebp+edi*4+0]
                mov     edx, eax
                shr     edx, 5
                sub     eax, edx
                mov     [ebp+edi*4+0], eax

loc_4CFDFD:                             ; CODE XREF: sub_4CFD90+50j
                mov     eax, [esi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4CFE14
                shl     eax, 8
                mov     ecx, esi
                mov     [esi+10h], eax
                call    loc_4CF640

loc_4CFE14:                             ; CODE XREF: sub_4CFD90+75j
                shr     [esp+10h+arg_C], 1
                add     edi, edi
                or      edi, ebx
                sub     [esp+10h+arg_8], 1
                jnz     short loc_4CFDB1
                pop     esi
                pop     ebp
                pop     ebx

loc_4CFE26:                             ; CODE XREF: sub_4CFD90+Cj
                pop     edi
                retn
sub_4CFD90      endp

; ---------------------------------------------------------------------------
                align 10h

; =============== S U B R O U T I N E =======================================


sub_4CFE30      proc near               ; CODE XREF: CEncoder_CodeOneBlock+190p
                                        ; CEncoder_CodeOneBlock+2CCp

arg_0           = dword ptr  4
arg_4           = byte ptr  8

                push    ebx
                push    ebp
                push    esi
                mov     esi, [esp+0Ch+arg_0]
                push    edi
                mov     ebx, ecx
                mov     ebp, 1
                mov     edx, 8

loc_4CFE44:                             ; CODE XREF: sub_4CFE30+88j
                movzx   edi, [esp+10h+arg_4]
                sub     edx, 1
                mov     cl, dl
                shr     edi, cl
                mov     ecx, [esi+10h]
                mov     eax, ecx
                shr     eax, 0Bh
                imul    eax, [ebx+ebp*4]
                and     edi, 1
                test    edi, edi
                mov     [esp+10h+arg_0], edx
                jnz     short loc_4CFE7E
                mov     [esi+10h], eax
                mov     eax, [ebx+ebp*4]
                mov     ecx, 800h
                sub     ecx, eax
                shr     ecx, 5
                add     ecx, eax
                mov     [ebx+ebp*4], ecx
                jmp     short loc_4CFE97
; ---------------------------------------------------------------------------

loc_4CFE7E:                             ; CODE XREF: sub_4CFE30+35j
                add     [esi+8], eax
                adc     dword ptr [esi+0Ch], 0
                sub     ecx, eax
                mov     [esi+10h], ecx
                mov     eax, [ebx+ebp*4]
                mov     ecx, eax
                shr     ecx, 5
                sub     eax, ecx
                mov     [ebx+ebp*4], eax

loc_4CFE97:                             ; CODE XREF: sub_4CFE30+4Cj
                mov     eax, [esi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4CFEB2
                shl     eax, 8
                mov     ecx, esi
                mov     [esi+10h], eax
                call    loc_4CF640
                mov     edx, [esp+10h+arg_0]

loc_4CFEB2:                             ; CODE XREF: sub_4CFE30+6Fj
                add     ebp, ebp
                or      ebp, edi
                test    edx, edx
                jnz     short loc_4CFE44
                pop     edi
                pop     esi
                pop     ebp
                pop     ebx
                retn    8
sub_4CFE30      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4CFED0      proc near               ; CODE XREF: CEncoder_CodeOneBlock+300p

var_4           = dword ptr -4
arg_0           = dword ptr  4
arg_4           = byte ptr  8
arg_8           = byte ptr  0Ch

                push    ecx
                push    ebx
                push    ebp
                push    esi
                mov     esi, [esp+10h+arg_0]
                push    edi
                mov     [esp+14h+var_4], ecx
                mov     ebx, 1
                mov     edx, 8
                jmp     short loc_4CFEF0
; ---------------------------------------------------------------------------
                align 10h

loc_4CFEF0:                             ; CODE XREF: sub_4CFED0+17j
                                        ; sub_4CFED0+ADj
                movzx   ebp, [esp+14h+arg_4]
                movzx   edi, [esp+14h+arg_8]
                sub     edx, 1
                movzx   ecx, dl
                shr     ebp, cl
                shr     edi, cl
                mov     ecx, [esp+14h+var_4]
                mov     [esp+14h+arg_0], edx
                mov     edx, [esi+10h]
                and     ebp, 1
                lea     eax, [ebp+1]
                shl     eax, 8
                add     eax, ebx
                lea     ecx, [ecx+eax*4]
                mov     eax, edx
                shr     eax, 0Bh
                imul    eax, [ecx]
                and     edi, 1
                test    edi, edi
                jnz     short loc_4CFF41
                mov     [esi+10h], eax
                mov     eax, [ecx]
                mov     edx, 800h
                sub     edx, eax
                shr     edx, 5
                add     edx, eax
                mov     [ecx], edx
                jmp     short loc_4CFF58
; ---------------------------------------------------------------------------

loc_4CFF41:                             ; CODE XREF: sub_4CFED0+5Aj
                add     [esi+8], eax
                adc     dword ptr [esi+0Ch], 0
                sub     edx, eax
                mov     [esi+10h], edx
                mov     eax, [ecx]
                mov     edx, eax
                shr     edx, 5
                sub     eax, edx
                mov     [ecx], eax

loc_4CFF58:                             ; CODE XREF: sub_4CFED0+6Fj
                mov     eax, [esi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4CFF6F
                shl     eax, 8
                mov     ecx, esi
                mov     [esi+10h], eax
                call    loc_4CF640

loc_4CFF6F:                             ; CODE XREF: sub_4CFED0+90j
                mov     edx, [esp+14h+arg_0]
                add     ebx, ebx
                or      ebx, edi
                cmp     ebp, edi
                jnz     short loc_4CFF8B
                test    edx, edx
                jnz     loc_4CFEF0
                pop     edi
                pop     esi
                pop     ebp
                pop     ebx
                pop     ecx
                retn    0Ch
; ---------------------------------------------------------------------------

loc_4CFF8B:                             ; CODE XREF: sub_4CFED0+A9j
                test    edx, edx
                jz      loc_4D0012

loc_4CFF93:                             ; CODE XREF: sub_4CFED0+140j
                movzx   edi, [esp+14h+arg_8]
                mov     ebp, [esp+14h+var_4]
                sub     edx, 1
                mov     cl, dl
                shr     edi, cl
                mov     ecx, [esi+10h]
                mov     eax, ecx
                shr     eax, 0Bh
                imul    eax, [ebp+ebx*4+0]
                and     edi, 1
                test    edi, edi
                mov     [esp+14h+arg_0], edx
                jnz     short loc_4CFFD4
                mov     [esi+10h], eax
                mov     eax, [ebp+ebx*4+0]
                mov     ecx, 800h
                sub     ecx, eax
                shr     ecx, 5
                add     ecx, eax
                mov     [ebp+ebx*4+0], ecx
                jmp     short loc_4CFFEF
; ---------------------------------------------------------------------------

loc_4CFFD4:                             ; CODE XREF: sub_4CFED0+E9j
                add     [esi+8], eax
                adc     dword ptr [esi+0Ch], 0
                sub     ecx, eax
                mov     [esi+10h], ecx
                mov     eax, [ebp+ebx*4+0]
                mov     ecx, eax
                shr     ecx, 5
                sub     eax, ecx
                mov     [ebp+ebx*4+0], eax

loc_4CFFEF:                             ; CODE XREF: sub_4CFED0+102j
                mov     eax, [esi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4D000A
                shl     eax, 8
                mov     ecx, esi
                mov     [esi+10h], eax
                call    loc_4CF640
                mov     edx, [esp+14h+arg_0]

loc_4D000A:                             ; CODE XREF: sub_4CFED0+127j
                add     ebx, ebx
                or      ebx, edi
                test    edx, edx
                jnz     short loc_4CFF93

loc_4D0012:                             ; CODE XREF: sub_4CFED0+BDj
                pop     edi
                pop     esi
                pop     ebp
                pop     ebx
                pop     ecx
                retn    0Ch
sub_4CFED0      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4D0020      proc near               ; CODE XREF: sub_4D0770+C6p
                                        ; CEncoder_CodeOneBlock+56Dp ...

arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch

                push    ebp
                mov     ebp, [esp+4+arg_4]
                cmp     ebp, 8
                push    esi
                mov     esi, [esp+8+arg_0]
                push    edi
                mov     edi, ecx
                jnb     short loc_4D007D
                mov     eax, [esi+10h]
                shr     eax, 0Bh
                imul    eax, [edi]
                mov     [esi+10h], eax
                mov     eax, [edi]
                mov     ecx, 800h
                sub     ecx, eax

loc_4D0047:                             ; DATA XREF: .rdata:0050C3BCo
                shr     ecx, 5
                add     ecx, eax
                mov     [edi], ecx
                mov     eax, [esi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4D0065
                shl     eax, 8

loc_4D005B:                             ; DATA XREF: .rdata:005064B0o
                mov     ecx, esi
                mov     [esi+10h], eax
                call    loc_4CF640

loc_4D0065:                             ; CODE XREF: sub_4D0020+36j
                mov     edx, [esp+0Ch+arg_8]
                push    ebp
                shl     edx, 5
                push    esi
                lea     ecx, [edx+edi+8]
                call    sub_4CFB20
                pop     edi
                pop     esi
                pop     ebp
                retn    0Ch
; ---------------------------------------------------------------------------

loc_4D007D:                             ; CODE XREF: sub_4D0020+10j
                mov     ecx, [esi+10h]
                mov     eax, ecx
                shr     eax, 0Bh
                imul    eax, [edi]
                add     [esi+8], eax
                adc     dword ptr [esi+0Ch], 0
                sub     ecx, eax
                mov     [esi+10h], ecx
                mov     eax, [edi]
                mov     ecx, eax
                shr     ecx, 5
                sub     eax, ecx
                mov     [edi], eax
                mov     eax, [esi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4D00B6
                shl     eax, 8
                mov     ecx, esi
                mov     [esi+10h], eax
                call    loc_4CF640

loc_4D00B6:                             ; CODE XREF: sub_4D0020+87j
                cmp     ebp, 10h
                jnb     short loc_4D010F
                mov     edx, [esi+10h]
                shr     edx, 0Bh
                imul    edx, [edi+4]
                mov     [esi+10h], edx
                mov     eax, [edi+4]
                mov     ecx, 800h
                sub     ecx, eax
                shr     ecx, 5
                add     ecx, eax
                mov     [edi+4], ecx
                mov     eax, [esi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4D00F1
                shl     eax, 8
                mov     ecx, esi
                mov     [esi+10h], eax
                call    loc_4CF640

loc_4D00F1:                             ; CODE XREF: sub_4D0020+C2j
                mov     edx, [esp+0Ch+arg_8]
                add     ebp, 0FFFFFFF8h
                push    ebp
                shl     edx, 5
                push    esi
                lea     ecx, [edx+edi+208h]
                call    sub_4CFB20
                pop     edi
                pop     esi
                pop     ebp
                retn    0Ch
; ---------------------------------------------------------------------------

loc_4D010F:                             ; CODE XREF: sub_4D0020+99j
                mov     ecx, [esi+10h]
                mov     eax, ecx
                shr     eax, 0Bh
                imul    eax, [edi+4]
                add     [esi+8], eax
                adc     dword ptr [esi+0Ch], 0
                sub     ecx, eax
                mov     [esi+10h], ecx
                mov     eax, [edi+4]
                mov     ecx, eax
                shr     ecx, 5
                sub     eax, ecx
                mov     [edi+4], eax
                mov     eax, [esi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4D014B
                shl     eax, 8
                mov     ecx, esi
                mov     [esi+10h], eax
                call    loc_4CF640

loc_4D014B:                             ; CODE XREF: sub_4D0020+11Cj
                add     ebp, 0FFFFFFF0h
                push    ebp
                push    esi
                lea     ecx, [edi+408h]
                call    sub_4CFBC0
                pop     edi
                pop     esi
                pop     ebp
                retn    0Ch
sub_4D0020      endp

; =============== S U B R O U T I N E =======================================

NCompress_NLZMA_CEncoder_CEncoder      proc near               ; CODE XREF: Compress_lzma_internal+149p
                mov     eax, ecx
                mov     dword ptr [eax+4], offset ICompressSetOutStream_vftable
                mov     dword ptr [eax+8], offset ICompressSetCoderProperties_vftable
                mov     dword ptr [eax+0Ch], offset ICompressWriteCoderProperties_vftable
                xor     ecx, ecx
                mov     [eax+24h], ecx
                mov     dword ptr [eax], offset NCompress_NLZMA_CEncoder_vftable
                mov     dword ptr [eax+4], offset NCompress_NLZMA_CEncoder_vftable_ICompressSetOutStream
                mov     dword ptr [eax+8], offset NCompress_NLZMA_CEncoder_vftable_ICompressSetCoderProperties
                mov     dword ptr [eax+0Ch], offset NCompress_NLZMA_CEncoder_vftable_ICompressWriteCoderProperties
                mov     [eax+40h], ecx
                mov     [eax+44h], ecx
                mov     [eax+54h], ecx
                mov     [eax+60h], ecx
                mov     [eax+32650h], ecx
                mov     dword ptr [eax+32EF8h], 20h
                mov     dword ptr [eax+33B58h], 2Ch
                mov     dword ptr [eax+33B5Ch], 2
                mov     [eax+33B64h], ecx
                mov     dword ptr [eax+33B6Ch], 00400000h
                mov     edx, 3
                mov     [eax+33B60h], edx
                mov     [eax+33B68h], edx
                mov     [eax+33B8Ch], ecx
                mov     [eax+33B90h], ecx
                mov     [eax+33B94h], cl
                mov     [eax+0B4h], ecx
                mov     [eax+0A4h], ecx
                mov     dword ptr [eax+0B0h], 20h
                mov     dword ptr [eax+0D4h], 1
                mov     dword ptr [eax+0CCh], 4
                mov     [eax+0D0h], ecx
                mov     [eax+0D8h], ecx
                mov     [eax+32EF4h], cl
                retn
NCompress_NLZMA_CEncoder_CEncoder      endp

; =============== S U B R O U T I N E =======================================

; int __thiscall sub_4D0250(void *Memory, char)
sub_4D0250      proc near               ; DATA XREF: .rdata:00517B0Co

arg_0           = byte ptr  4

                push    esi
                mov     esi, ecx
                call    sub_4CF810
                test    [esp+4+arg_0], 1
                jz      short loc_4D0268
                push    esi             ; Memory
                call    j__free
                add     esp, 4

loc_4D0268:                             ; CODE XREF: sub_4D0250+Dj
                mov     eax, esi
                pop     esi
                retn    4
sub_4D0250      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

sub_4D0270      proc near               ; CODE XREF: CEncoder_SetStreams+14p
                push    esi
                mov     esi, ecx
                mov     eax, [esi+40h]
                test    eax, eax
                push    edi
                mov     edi, 100000h
                jz      short loc_4D0297
                cmp     [esi+50h], edi
                jz      short loc_4D02C5
                test    eax, eax
                jz      short loc_4D0297
                push    8000h           ; dwFreeType
                push    0               ; dwSize
                push    eax             ; lpAddress
                call    ds:VirtualFree

loc_4D0297:                             ; CODE XREF: sub_4D0270+Ej
                                        ; sub_4D0270+17j
                push    4               ; flProtect
                push    1000h           ; flAllocationType
                push    edi             ; dwSize
                push    0               ; lpAddress
                mov     dword ptr [esi+40h], 0
                mov     [esi+50h], edi
                call    ds:VirtualAlloc
                test    eax, eax
                mov     [esi+40h], eax
                setnz   al
                test    al, al
                jnz     short loc_4D02C5
                pop     edi
                mov     eax, 8007000Eh
                pop     esi
                retn
; ---------------------------------------------------------------------------

loc_4D02C5:                             ; CODE XREF: sub_4D0270+13j
                                        ; sub_4D0270+4Bj
                mov     eax, [esi+33B68h]
                mov     ecx, [esi+33B64h]
                cmp     dword ptr [esi+0D4h], 0
                push    ebx
                push    eax
                push    ecx
                lea     ecx, [esi+32650h]
                setnz   bl
                call    sub_4CD940
                test    al, al
                jz      short loc_4D034F
                mov     ecx, [esi+33B6Ch]
                mov     edx, 1000000h
                cmp     edx, ecx
                sbb     eax, eax
                neg     eax
                push    ebp
                mov     ebp, [esi+32EF8h]
                mov     [esi+0D8h], eax
                mov     eax, ebp
                shr     eax, 1
                add     eax, 10h
                test    bl, bl
                jnz     short loc_4D0318
                shr     eax, 1

loc_4D0318:                             ; CODE XREF: sub_4D0270+A4j
                mov     edx, [esi+33B90h]
                test    edx, edx
                jz      short loc_4D0324
                mov     eax, edx

loc_4D0324:                             ; CODE XREF: sub_4D0270+B0j
                push    offset off_546E20
                push    111h
                push    ebp
                push    1000h
                push    ecx
                lea     edi, [esi+84h]
                push    edi
                mov     [esi+0B0h], eax
                call    sub_4CBA60
                add     esp, 18h
                test    eax, eax
                pop     ebp
                jnz     short loc_4D0358

loc_4D034F:                             ; CODE XREF: sub_4D0270+7Bj
                pop     ebx
                pop     edi
                mov     eax, 8007000Eh
                pop     esi
                retn
; ---------------------------------------------------------------------------

loc_4D0358:                             ; CODE XREF: sub_4D0270+DDj
                mov     [esi+80h], edi
                add     esi, 68h
                push    esi
                push    edi
                call    sub_4CCAA0
                add     esp, 8
                pop     ebx
                pop     edi
                xor     eax, eax
                pop     esi
                retn
sub_4D0270      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

CEncoder_SetStreams proc near           ; CODE XREF: CEncoder_CodeReal+4Ap

arg_0           = dword ptr  4
arg_4           = dword ptr  8

                mov     eax, [esp+arg_0]
                push    esi
                mov     esi, ecx
                mov     [esi+33B84h], eax
                mov     byte ptr [esi+33B80h], 0
                call    sub_4D0270
                test    eax, eax
                jnz     loc_4D0441
                mov     edx, [esp+4+arg_4]
                mov     ecx, [esi+4]
                lea     eax, [esi+4]
                push    edx
                push    eax
                mov     eax, [ecx+0Ch]
                call    eax
                test    eax, eax
                jnz     loc_4D0441
                mov     ecx, esi
                call    sub_4CDEA0
                test    eax, eax
                jnz     short loc_4D0441
                cmp     [esi+32EF4h], al
                jnz     short loc_4D03DB
                mov     ecx, esi
                call    CEncoder_FillDistancesPrices
                mov     ecx, esi
                call    CEncoder_FillAlignPrices

loc_4D03DB:                             ; CODE XREF: CEncoder_SetStreams+4Bj
                mov     ecx, [esi+32EF8h]
                sub     ecx, 1
                mov     [esi+2D9C0h], ecx
                mov     ecx, [esi+33B5Ch]
                mov     edx, 1
                shl     edx, cl
                lea     ecx, [esi+28DB8h]
                push    edx
                call    sub_4CF780
                mov     ecx, [esi+33B5Ch]
                mov     eax, [esi+32EF8h]
                mov     edx, 1
                shl     edx, cl
                sub     eax, 1
                lea     ecx, [esi+2DA04h]
                mov     [esi+3260Ch], eax
                push    edx
                call    sub_4CF780
                mov     dword ptr [esi+33B78h], 0
                mov     dword ptr [esi+33B7Ch], 0
                xor     eax, eax

loc_4D0441:                             ; CODE XREF: CEncoder_SetStreams+1Bj
                                        ; CEncoder_SetStreams+34j ...
                pop     esi
                retn    10h
CEncoder_SetStreams endp

;Compress_lzma_internal proc near        ; CODE XREF: Compress_lzma+34p
_starcraft_compress_lzma proc near        ; CODE XREF: Compress_lzma+34p
; sub_4D0450

var_58          = dword ptr -58h
var_54          = dword ptr -54h
var_50          = dword ptr -50h
var_4C          = dword ptr -4Ch
var_48          = dword ptr -48h
var_44          = dword ptr -44h
var_40          = dword ptr -40h
var_3C          = word ptr -3Ch
var_34          = dword ptr -34h
var_2C          = word ptr -2Ch
var_24          = dword ptr -24h
var_1C          = dword ptr -1Ch
var_14          = dword ptr -14h
var_C           = dword ptr -0Ch
var_4           = dword ptr -4
pbInBuffer      = dword ptr  4
cbInBuffer      = dword ptr  8
pcbInBuffer     = dword ptr  0Ch
pbOutBuffer     = dword ptr  10h
cbOutBuffer     = dword ptr  14h
dummy           = dword ptr  18h
pcbOutBuffer    = dword ptr  1Ch
pfnAllocateMemory= dword ptr  20h
pfnFreeMemory   = dword ptr  24h
pfnGiveData     = dword ptr  28h

                push    0FFFFFFFFh
                push    offset loc_4DA0FB
                mov     eax, dword ptr fs:[0]
                push    eax
                sub     esp, 4Ch
                push    ebx
                push    ebp
                push    esi
                push    edi
                mov     eax, dword_544960
                xor     eax, esp
                push    eax
                lea     eax, [esp+6Ch+var_C]
                mov     dword ptr fs:[0], eax   
                mov     eax, dword_553598
                xor     ebx, ebx
                cmp     eax, ebx
                jnz     short loc_4D04A1
                push    0Ch             ; Size
                call    _operator_new    ; operator new(uint)
                add     esp, 4
                cmp     eax, ebx
                jz      short loc_4D049A
                mov     [eax], ebx
                mov     [eax+4], ebx
                mov     [eax+8], ebx
                jmp     short loc_4D049C
; ---------------------------------------------------------------------------

loc_4D049A:                             ; CODE XREF: Compress_lzma_internal+3Ej
                xor     eax, eax

loc_4D049C:                             ; CODE XREF: Compress_lzma_internal+48j
                mov     dword ptr dword_553598, eax

loc_4D04A1:                             ; CODE XREF: Compress_lzma_internal+30j
                cmp     [eax], ebx
                jnz     short loc_4D04B3
                mov     ecx, [esp+6Ch+pfnAllocateMemory]
                mov     [eax], ecx
                mov     eax, dword_553598

loc_4D04B3:                             ; CODE XREF: Compress_lzma_internal+53j
                cmp     eax, ebx
                jnz     short loc_4D04D6
                push    0Ch             ; Size
                call    _operator_new    ; operator new(uint)
                add     esp, 4
                cmp     eax, ebx
                jz      short loc_4D04CF
                mov     [eax], ebx
                mov     [eax+4], ebx
                mov     [eax+8], ebx
                jmp     short loc_4D04D1
; ---------------------------------------------------------------------------

loc_4D04CF:                             ; CODE XREF: Compress_lzma_internal+73j
                xor     eax, eax

loc_4D04D1:                             ; CODE XREF: Compress_lzma_internal+7Dj
                mov     dword_553598, eax

loc_4D04D6:                             ; CODE XREF: Compress_lzma_internal+65j
                cmp     [eax+4], ebx
                jnz     short loc_4D04EA
                mov     edx, [esp+6Ch+pfnFreeMemory]
                mov     [eax+4], edx
                mov     eax, dword_553598

loc_4D04EA:                             ; CODE XREF: Compress_lzma_internal+89j
                cmp     [eax+8], ebx
                jnz     short loc_4D04F9
                mov     ecx, [esp+6Ch+pfnGiveData]
                mov     [eax+8], ecx

loc_4D04F9:                             ; CODE XREF: Compress_lzma_internal+9Dj
                mov     edx, [esp+6Ch+pcbOutBuffer]
                mov     ebp, [esp+6Ch+pcbInBuffer]
                cmp     ebp, ebx
                mov     esi, [esp+6Ch+cbInBuffer]
                mov     [edx], ebx
                mov     edx, 1
                mov     eax, esi
                mov     ecx, ebp
                ja      short loc_4D0520
                cmp     esi, ebx
                jbe     short loc_4D053A
                jmp     short loc_4D0520
; ---------------------------------------------------------------------------
                align 10h

loc_4D0520:                             ; CODE XREF: Compress_lzma_internal+C5j
                                        ; Compress_lzma_internal+CBj ...
                shrd    eax, ecx, 1
                add     edx, edx
                shr     ecx, 1
                cmp     edx, 2000000h
                ja      short loc_4D053A
                cmp     ecx, ebx
                ja      short loc_4D0520
                jb      short loc_4D053A
                cmp     eax, ebx
                ja      short loc_4D0520

loc_4D053A:                             ; CODE XREF: Compress_lzma_internal+C9j
                                        ; Compress_lzma_internal+DEj ...
                mov     eax, 13h
                push    33B98h          ; Size
                mov     [esp+70h+var_48], 470h
                mov     [esp+70h+var_44], 400h
                mov     [esp+70h+var_40], 450h
                mov     [esp+70h+var_3C], ax
                mov     [esp+70h+var_2C], ax
                mov     word ptr [esp+70h+var_1C], ax
                mov     [esp+70h+var_34], 2
                mov     [esp+70h+var_24], edx
                mov     [esp+70h+var_14], 40h
                mov     [esp+70h+var_58], ebx
                call    _operator_new    ; operator new(uint)
                add     esp, 4
                mov     [esp+6Ch+var_4C], eax
                cmp     eax, ebx
                mov     [esp+6Ch+var_4], ebx
                jz      short loc_4D05A4
                mov     ecx, eax
                call    NCompress_NLZMA_CEncoder_CEncoder
                mov     [esp+6Ch+var_54], eax
                jmp     short loc_4D05AA
; ---------------------------------------------------------------------------

loc_4D05A4:                             ; CODE XREF: Compress_lzma_internal+145j
                mov     [esp+6Ch+var_54], ebx
                mov     eax, ebx

loc_4D05AA:                             ; CODE XREF: Compress_lzma_internal+152j
                or      edi, 0FFFFFFFFh
                cmp     eax, ebx
                mov     [esp+6Ch+var_4], edi
                jz      short loc_4D05D1
                mov     ecx, [eax+8]
                push    3
                lea     edx, [esp+70h+var_3C]
                push    edx
                add     eax, 8
                lea     edx, [esp+74h+var_48]
                push    edx
                push    eax
                mov     eax, [ecx+0Ch]
                call    eax             ; ICompressSetCodeProperties::SetCoderProperties
                test    eax, eax
                jz      short loc_4D05D5

loc_4D05D1:                             ; CODE XREF: Compress_lzma_internal+163j
                mov     [esp+6Ch+var_58], edi

loc_4D05D5:                             ; CODE XREF: Compress_lzma_internal+17Fj
                push    28h             ; Size
                call    _operator_new    ; operator new(uint)
                add     esp, 4
                cmp     eax, ebx
                jz      short loc_4D060E
                mov     ecx, [esp+6Ch+pbInBuffer]
                mov     [eax+4], ebx
                add     dword ptr [eax+4], 1
                mov     dword ptr [eax], offset off_517A90
                mov     [eax+8], ecx
                mov     [eax+10h], esi
                mov     [eax+14h], ebp
                mov     [eax+18h], ebx
                mov     [eax+1Ch], ebx
                mov     [eax+20h], bl
                mov     edi, eax                ; EDI = pInStreamMemory
                mov     [esp+6Ch+var_50], eax
                jmp     short loc_4D0614
; ---------------------------------------------------------------------------

loc_4D060E:                             ; CODE XREF: Compress_lzma_internal+191j
                xor     edi, edi
                mov     [esp+6Ch+var_50], edi

loc_4D0614:                             ; CODE XREF: Compress_lzma_internal+1BCj
                push    28h             ; Size
                call    _operator_new    ; operator new(uint)
                add     esp, 4
                cmp     eax, ebx
                jz      short loc_4D0657
                mov     edx, [esp+6Ch+pbOutBuffer]
                mov     ecx, [esp+6Ch+cbOutBuffer]
                mov     [eax+4], ebx
                add     dword ptr [eax+4], 1
                mov     [eax+8], edx
                mov     edx, [esp+6Ch+dummy]
                mov     dword ptr [eax], offset off_517AA4
                mov     [eax+10h], ecx
                mov     [eax+14h], edx
                mov     [eax+18h], ebx
                mov     [eax+1Ch], ebx
                mov     [eax+20h], bl
                mov     esi, eax        ; ESI = pOutStreamMemory
                jmp     short loc_4D0659
; ---------------------------------------------------------------------------

loc_4D0657:                             ; CODE XREF: Compress_lzma_internal+1D0j
                xor     esi, esi

loc_4D0659:                             ; CODE XREF: Compress_lzma_internal+205j
                cmp     edi, ebx
                jz      short loc_4D0661
                cmp     esi, ebx
                jnz     short loc_4D0669

loc_4D0661:                             ; CODE XREF: Compress_lzma_internal+20Bj
                mov     [esp+6Ch+var_58], 0FFFFFFFFh

loc_4D0669:                             ; CODE XREF: Compress_lzma_internal+20Fj
                mov     eax, [esi]      ; EAX = pOutStreamMemory->vftable
                mov     ecx, [eax+10h]  ; ECX = 
                push    ebx
                mov     edi, 1
                push    edi
                push    ebx
                push    esi
                call    ecx
                test    eax, eax
                jz      short loc_4D0681
                mov     [esp+6Ch+var_58], edi

loc_4D0681:                             ; CODE XREF: Compress_lzma_internal+22Bj
                mov     eax, [esp+6Ch+var_54]
                mov     edx, [eax+0Ch]
                add     eax, 0Ch
                push    esi
                push    eax
                mov     eax, [edx+0Ch]
                call    eax
                test    eax, eax
                jz      short loc_4D069A
                mov     [esp+6Ch+var_58], edi

loc_4D069A:                             ; CODE XREF: Compress_lzma_internal+244j
                xor     edi, edi
                jmp     short loc_4D06A4
; ---------------------------------------------------------------------------
                align 10h

loc_4D06A0:                             ; CODE XREF: Compress_lzma_internal+27Fj
                mov     ebp, [esp+6Ch+pcbInBuffer]

loc_4D06A4:                             ; CODE XREF: Compress_lzma_internal+24Cj
                mov     eax, [esp+6Ch+cbInBuffer]
                push    ebx
                push    1
                mov     edx, ebp
                mov     ecx, edi
                call    __allshr         ; Microsoft VisualC 2-8/net runtime
                push    eax
                mov     eax, [esi]
                mov     ecx, [eax+10h]
                push    esi
                call    ecx
                test    eax, eax
                jz      short loc_4D06C9
                mov     [esp+6Ch+var_58], 1

loc_4D06C9:                             ; CODE XREF: Compress_lzma_internal+26Fj
                add     edi, 8
                cmp     edi, 40h
                jl      short loc_4D06A0
                mov     ebp, [esp+6Ch+var_54]
                xor     edi, edi
                cmp     [esp+6Ch+var_58], ebx
                jnz     short loc_4D0723
                mov     eax, [esp+6Ch+var_50]
                mov     edx, [ebp+0]
                mov     ecx, [edx+0Ch]
                push    ebx
                push    ebx
                push    ebx
                push    esi
                push    eax
                push    ebp
                call    ecx
                mov     ecx, [esi+18h]
                mov     edi, eax
                mov     eax, [esi+1Ch]
                cmp     eax, ebx
                ja      short loc_4D0700
                cmp     ecx, 0FFFFFFFFh
                jbe     short loc_4D0709

loc_4D0700:                             ; CODE XREF: Compress_lzma_internal+2A9j
                or      ecx, 0FFFFFFFFh
                mov     [esp+6Ch+pcbInBuffer], ebx
                jmp     short loc_4D070D
; ---------------------------------------------------------------------------

loc_4D0709:                             ; CODE XREF: Compress_lzma_internal+2AEj
                mov     [esp+6Ch+pcbInBuffer], eax

loc_4D070D:                             ; CODE XREF: Compress_lzma_internal+2B7j
                mov     edx, [esp+6Ch+pcbOutBuffer]
                mov     [edx], ecx
                cmp     [esi+20h], bl
                jz      short loc_4D0723
                mov     [esp+6Ch+var_58], 1

loc_4D0723:                             ; CODE XREF: Compress_lzma_internal+28Bj
                                        ; Compress_lzma_internal+2C9j
                mov     eax, [esp+6Ch+var_50]
                cmp     eax, ebx
                jz      short loc_4D0733
                mov     ecx, [eax]
                mov     edx, [ecx+8]
                push    eax
                call    edx

loc_4D0733:                             ; CODE XREF: Compress_lzma_internal+2D9j
                mov     eax, [esi]
                mov     ecx, [eax+8]
                push    esi
                call    ecx
                mov     edx, [ebp+0]
                mov     eax, [edx+10h]
                push    1
                mov     ecx, ebp
                call    eax
                mov     eax, [esp+6Ch+var_58]
                cmp     eax, ebx
                jnz     short loc_4D0755
                neg     edi
                sbb     edi, edi
                mov     eax, edi

loc_4D0755:                             ; CODE XREF: Compress_lzma_internal+2FDj
                mov     ecx, [esp+6Ch+var_C]
                mov     dword ptr fs:[0], ecx
                pop     ecx
                pop     edi
                pop     esi
                pop     ebp
                pop     ebx
                add     esp, 58h
                retn
_starcraft_compress_lzma endp
;Compress_lzma_internal endp

; =============== S U B R O U T I N E =======================================

Compress_lzma   proc near               ; DATA XREF: .rdata:00509684o

pbOutBuffer     = dword ptr  4
pcbOutBuffer    = dword ptr  8
pbInBuffer      = dword ptr  0Ch
cbInBuffer      = dword ptr  10h

                push    esi
                push    edi
;                call    sub_47F198
                mov     esi, [esp+8+pcbOutBuffer] ; ESI = pcbOutBuffer
                mov     edi, [esp+8+cbInBuffer] ; EDI = cbInBuffer
;                push    offset GiveDataToCompress
;                push    offset FreeMemory_47F3AB
;                push    offset AllocateMemory_47F396
                push    esi             ; pcbOutBuffer
                push    0
                mov     [eax+493E0h], eax
                push    dword ptr [esi] ; cbOutBuffer
                push    [esp+20h+pbOutBuffer] ; pbOutBuffer
                push    0
                push    edi             ; cbInBuffer
                push    [esp+2Ch+pbInBuffer] ; pbInBuffer
;                call    Compress_lzma_internal
                add     esp, 28h
                sub     eax, 0
                jz      short loc_47F401
                mov     [esi], edi
                dec     eax

loc_47F401:                             ; CODE XREF: Compress_lzma+3Fj
                pop     edi
                pop     esi
                retn
Compress_lzma  endp

; =============== S U B R O U T I N E =======================================

sub_4D0770      proc near               ; CODE XREF: CEncoder_Flush+1Ap

arg_0           = dword ptr  4

                push    edi
                mov     edi, ecx
                cmp     byte ptr [edi+33B94h], 0
                jz      loc_4D0881
                movzx   eax, byte ptr [edi+10h]
                mov     ecx, [edi+38h]
                shl     eax, 4
                push    ebx
                mov     ebx, [esp+8+arg_0]
                add     eax, ebx
                lea     edx, [edi+eax*4+280F0h]
                push    ebp
                push    esi
                lea     esi, [edi+28h]
                mov     eax, ecx
                shr     eax, 0Bh
                imul    eax, [edx]
                add     [esi+8], eax
                adc     dword ptr [esi+0Ch], 0
                sub     ecx, eax
                mov     [esi+10h], ecx
                mov     eax, [edx]
                mov     ecx, eax
                shr     ecx, 5
                sub     eax, ecx
                mov     [edx], eax
                mov     eax, [esi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4D07D3
                shl     eax, 8
                mov     ecx, esi
                mov     [esi+10h], eax
                call    loc_4CF640

loc_4D07D3:                             ; CODE XREF: sub_4D0770+54j
                movzx   edx, byte ptr [edi+10h]
                mov     ecx, [esi+10h]
                lea     eax, [edi+edx*4+283F0h]
                shr     ecx, 0Bh
                imul    ecx, [eax]
                mov     [esi+10h], ecx
                mov     ecx, [eax]
                mov     edx, 800h
                sub     edx, ecx
                shr     edx, 5
                add     edx, ecx
                mov     [eax], edx
                mov     eax, [esi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4D0811
                shl     eax, 8
                mov     ecx, esi
                mov     [esi+10h], eax
                call    loc_4CF640

loc_4D0811:                             ; CODE XREF: sub_4D0770+92j
                movzx   eax, byte ptr [edi+10h]
                mov     cl, ds:kMatchNextStates[eax]
                push    ebx
                mov     [edi+10h], cl
                cmp     byte ptr [edi+32EF4h], 0
                push    0
                lea     ebp, [edi+28DB8h]
                push    esi
                mov     ecx, ebp
                setz    byte ptr [esp+1Ch+arg_0]
                call    sub_4D0020
                cmp     byte ptr [esp+10h+arg_0], 0
                jz      short loc_4D0854
                add     dword ptr [ebp+ebx*4+4C0Ch], 0FFFFFFFFh
                jnz     short loc_4D0854
                push    ebx
                mov     ecx, ebp
                call    sub_4CF740

loc_4D0854:                             ; CODE XREF: sub_4D0770+D0j
                                        ; sub_4D0770+DAj
                push    3Fh
                push    esi
                lea     ecx, [edi+287B0h]
                call    sub_4CFC60
                push    1Ah
                push    3FFFFFFh
                mov     ecx, esi
                call    sub_4CF6E0
                push    0Fh
                push    esi
                lea     ecx, [edi+28D78h]
                call    sub_4CFD00
                pop     esi
                pop     ebp
                pop     ebx

loc_4D0881:                             ; CODE XREF: sub_4D0770+Aj
                pop     edi
                retn    4
sub_4D0770      endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

CEncoder_Flush  proc near               ; CODE XREF: CEncoder_CodeOneBlock+BAp
                                        ; CEncoder_CodeOneBlock+1D0p ...

arg_0           = dword ptr  4

                push    esi
                mov     esi, ecx
                mov     eax, [esi+0ECh]
                test    eax, eax
                jnz     short loc_4D08E5
                mov     eax, [esi+33B60h]
                and     eax, [esp+4+arg_0]
                push    ebx
                push    edi
                push    eax
                call    sub_4D0770
                lea     ebx, [esi+28h]
                mov     edi, 5

loc_4D08B7:                             ; CODE XREF: CEncoder_Flush+31j
                mov     ecx, ebx
                call    loc_4CF640
                sub     edi, 1
                jnz     short loc_4D08B7
                mov     ecx, [esi+4Ch]
                add     esi, 40h
                cmp     ecx, [esi+4]
                pop     edi
                pop     ebx
                jz      short loc_4D08E3

loc_4D08D0:                             ; CODE XREF: CEncoder_Flush+51j
                mov     ecx, esi
                call    sub_4CF450
                test    eax, eax
                jnz     short loc_4D08E5
                mov     edx, [esi+0Ch]
                cmp     edx, [esi+4]
                jnz     short loc_4D08D0

loc_4D08E3:                             ; CODE XREF: CEncoder_Flush+3Ej
                xor     eax, eax

loc_4D08E5:                             ; CODE XREF: CEncoder_Flush+Bj
                                        ; CEncoder_Flush+49j
                pop     esi
                retn    4
CEncoder_Flush  endp

; ---------------------------------------------------------------------------
                align 10h
; =============== S U B R O U T I N E =======================================

CEncoder_CodeOneBlock proc near         ; CODE XREF: CEncoder_CodeReal+B1p
                                        ; CEncoder_CodeReal+F5p

var_20          = byte ptr -20h
var_1C          = dword ptr -1Ch
var_18          = dword ptr -18h
var_14          = dword ptr -14h
var_10          = dword ptr -10h
var_C           = dword ptr -0Ch
var_8           = dword ptr -8
var_4           = dword ptr -4
arg_0           = dword ptr  4
arg_4           = dword ptr  8
arg_8           = dword ptr  0Ch

                sub     esp, 20h
                push    ebp
                push    esi
                mov     esi, ecx
                push    edi
                mov     edi, [esi+33B84h]
                xor     ebp, ebp
                cmp     edi, ebp
                jz      short loc_4D0952
                mov     eax, [edi]
                mov     ecx, [eax+4]
                push    edi
                call    ecx
                mov     eax, [esi+33B8Ch]
                cmp     eax, ebp
                jz      short loc_4D091E
                mov     edx, [eax]
                push    eax
                mov     eax, [edx+8]
                call    eax

loc_4D091E:                             ; CODE XREF: CEncoder_CodeOneBlock+24j
                mov     [esi+33B8Ch], edi
                mov     ecx, [esi+80h]
                mov     edx, [esi+68h]
                lea     eax, [esi+33B88h]
                push    ecx
                mov     dword ptr [eax], offset loc_4CF210
                mov     [esi+0B8h], eax
                call    edx
                add     esp, 4
                mov     byte ptr [esi+33B95h], 1
                mov     [esi+33B84h], ebp

loc_4D0952:                             ; CODE XREF: CEncoder_CodeOneBlock+12j
                mov     eax, [esp+2Ch+arg_8]
                mov     dword ptr [eax], 1
                cmp     byte ptr [esi+33B80h], 0
                jz      short loc_4D0974
                mov     eax, [esi+0ECh]
                pop     edi
                pop     esi
                pop     ebp
                add     esp, 20h
                retn    0Ch
; ---------------------------------------------------------------------------

loc_4D0974:                             ; CODE XREF: CEncoder_CodeOneBlock+73j
                mov     ecx, [esi+33B78h]
                or      ecx, [esi+33B7Ch]
                push    ebx
                mov     byte ptr [esi+33B80h], 1
                jnz     loc_4D0A9C
                mov     edx, [esi+80h]
                mov     eax, [esi+70h]
                push    edx
                call    eax
                add     esp, 4
                test    eax, eax
                jnz     short loc_4D09B9
                mov     ecx, [esi+33B78h]
                push    ecx
                mov     ecx, esi
                call    CEncoder_Flush
                pop     ebx
                pop     edi
                pop     esi
                pop     ebp
                add     esp, 20h
                retn    0Ch
; ---------------------------------------------------------------------------

loc_4D09B9:                             ; CODE XREF: CEncoder_CodeOneBlock+AFj
                lea     edx, [esp+30h+var_4]
                push    edx
                mov     ecx, esi
                call    sub_4CB3B0
                movzx   ecx, byte ptr [esi+10h]
                mov     eax, [esi+33B60h]
                and     eax, [esi+33B78h]
                mov     edx, [esi+38h]
                lea     edi, [esi+28h]
                shl     ecx, 4
                add     eax, ecx
                shr     edx, 0Bh
                imul    edx, [esi+eax*4+280F0h]
                lea     eax, [esi+eax*4+280F0h]
                mov     [edi+10h], edx
                mov     ecx, [eax]
                mov     edx, 800h
                sub     edx, ecx
                shr     edx, 5
                add     edx, ecx
                mov     [eax], edx
                mov     eax, [edi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4D0A1C
                shl     eax, 8
                mov     ecx, edi
                mov     [edi+10h], eax
                call    loc_4CF640

loc_4D0A1C:                             ; CODE XREF: CEncoder_CodeOneBlock+11Dj
                movzx   eax, byte ptr [esi+10h]
                mov     cl, ds:kLiteralNextStates[eax]
                mov     [esi+10h], cl
                mov     edx, [esi+32F04h]
                mov     eax, [esi+80h]
                mov     ecx, [esi+6Ch]
                neg     edx
                push    edx
                push    eax
                call    ecx
                mov     bl, al
                mov     eax, [esi+32654h]
                add     esp, 8
                mov     byte ptr [esp+30h+var_10], bl
                mov     edx, [esp+30h+var_10]
                push    edx
                movzx   edx, byte ptr [esi+11h]
                push    edi
                mov     edi, [esi+3265Ch]
                and     edi, [esi+33B78h]
                mov     ecx, 8
                sub     cl, al
                shr     edx, cl
                mov     ecx, eax
                shl     edi, cl
                add     edx, edi
                imul    edx, 0C00h
                add     edx, [esi+32650h]
                mov     ecx, edx
                call    sub_4CFE30
                add     dword ptr [esi+32F04h], 0FFFFFFFFh
                add     dword ptr [esi+33B78h], 1
                mov     [esi+11h], bl
                adc     [esi+33B7Ch], ebp

loc_4D0A9C:                             ; CODE XREF: CEncoder_CodeOneBlock+98j
                mov     edi, [esi+33B78h]
                mov     eax, [esi+80h]
                mov     ecx, [esi+70h]
                push    eax
                mov     [esp+34h+var_14], edi
                mov     [esp+34h+var_4], edi
                call    ecx
                add     esp, 4
                test    eax, eax
                jnz     short loc_4D0AD4
                push    edi
                mov     ecx, esi
                call    CEncoder_Flush
                pop     ebx
                pop     edi
                pop     esi
                pop     ebp
                add     esp, 20h
                retn    0Ch
; ---------------------------------------------------------------------------
                align 10h

loc_4D0AD0:                             ; CODE XREF: CEncoder_CodeOneBlock+735j
                                        ; CEncoder_CodeOneBlock+78Bj
                mov     edi, [esp+30h+var_14]

loc_4D0AD4:                             ; CODE XREF: CEncoder_CodeOneBlock+1CBj
                cmp     byte ptr [esi+32EF4h], 0
                mov     ecx, esi
                jz      short loc_4D0AEB
                lea     edx, [esp+30h+var_1C]
                push    edx
                call    CEncoder_GetOptimumFast
                jmp     short loc_4D0AF6
; ---------------------------------------------------------------------------

loc_4D0AEB:                             ; CODE XREF: CEncoder_CodeOneBlock+1EDj
                lea     eax, [esp+30h+var_1C]
                push    eax
                push    edi
                call    CEncoder_GetOptimum

loc_4D0AF6:                             ; CODE XREF: CEncoder_CodeOneBlock+1F9j
                mov     ebx, [esi+33B60h]
                and     ebx, edi
                cmp     eax, 1
                mov     [esp+30h+var_18], eax
                jnz     loc_4D0C0E
                cmp     [esp+30h+var_1C], 0FFFFFFFFh
                jnz     loc_4D0C0E
                movzx   ecx, byte ptr [esi+10h]
                mov     edx, [esi+38h]
                lea     ebp, [esi+28h]
                shl     ecx, 4
                shr     edx, 0Bh
                add     ecx, ebx
                imul    edx, [esi+ecx*4+280F0h]
                lea     eax, [esi+ecx*4+280F0h]
                mov     [ebp+10h], edx
                mov     ecx, [eax]
                mov     edx, 800h
                sub     edx, ecx
                shr     edx, 5
                add     edx, ecx
                mov     [eax], edx
                mov     eax, [ebp+10h]
                cmp     eax, 1000000h
                jnb     short loc_4D0B61
                shl     eax, 8
                mov     ecx, ebp
                mov     [ebp+10h], eax
                call    loc_4CF640

loc_4D0B61:                             ; CODE XREF: CEncoder_CodeOneBlock+262j
                mov     eax, [esi+32F04h]
                mov     ecx, [esi+80h]
                mov     edx, [esi+6Ch]
                neg     eax
                push    eax
                push    ecx
                call    edx
                movzx   edi, byte ptr [esi+11h]
                mov     edx, [esi+3265Ch]
                and     edx, [esp+38h+var_14]
                mov     bl, al
                mov     eax, [esi+32654h]
                mov     ecx, 8
                sub     cl, al
                shr     edi, cl
                mov     ecx, eax
                shl     edx, cl
                add     esp, 8
                mov     byte ptr [esp+30h+var_10], bl
                add     edi, edx
                imul    edi, 0C00h
                add     edi, [esi+32650h]
                cmp     byte ptr [esi+10h], 7
                jnb     short loc_4D0BC3
                mov     eax, [esp+30h+var_10]
                push    eax
                push    ebp
                mov     ecx, edi
                call    sub_4CFE30
                jmp     short loc_4D0BF5
; ---------------------------------------------------------------------------

loc_4D0BC3:                             ; CODE XREF: CEncoder_CodeOneBlock+2C2j
                mov     edx, [esi+80h]
                mov     eax, [esi+6Ch]
                or      ecx, 0FFFFFFFFh
                sub     ecx, [esi+14h]
                sub     ecx, [esi+32F04h]
                push    ecx
                push    edx
                call    eax
                mov     ecx, [esp+38h+var_10]
                add     esp, 8
                mov     byte ptr [esp+30h+var_C], al
                mov     edx, [esp+30h+var_C]
                push    ecx
                push    edx
                push    ebp
                mov     ecx, edi
                call    sub_4CFED0

loc_4D0BF5:                             ; CODE XREF: CEncoder_CodeOneBlock+2D1j
                movzx   eax, byte ptr [esi+10h]
                mov     cl, ds:kLiteralNextStates[eax]
                mov     ebp, [esp+30h+var_18]
                mov     [esi+10h], cl
                mov     [esi+11h], bl
                jmp     loc_4D1013
; ---------------------------------------------------------------------------

loc_4D0C0E:                             ; CODE XREF: CEncoder_CodeOneBlock+215j
                                        ; CEncoder_CodeOneBlock+220j
                movzx   edx, byte ptr [esi+10h]
                mov     ecx, [esi+38h]
                lea     edi, [esi+28h]
                shl     edx, 4
                mov     eax, ecx
                shr     eax, 0Bh
                add     edx, ebx
                imul    eax, [esi+edx*4+280F0h]
                add     [edi+8], eax
                lea     edx, [esi+edx*4+280F0h]
                mov     ebp, 0
                adc     [edi+0Ch], ebp
                sub     ecx, eax
                mov     [edi+10h], ecx
                mov     eax, [edx]
                mov     ecx, eax
                shr     ecx, 5
                sub     eax, ecx
                mov     [edx], eax
                mov     eax, [edi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4D0C63
                shl     eax, 8
                mov     ecx, edi
                mov     [edi+10h], eax
                call    loc_4CF640

loc_4D0C63:                             ; CODE XREF: CEncoder_CodeOneBlock+364j
                cmp     [esp+30h+var_1C], 4
                movzx   edx, byte ptr [esi+10h]
                mov     ecx, [edi+10h]
                jnb     loc_4D0E91
                mov     eax, ecx
                shr     eax, 0Bh
                imul    eax, [esi+edx*4+283F0h]
                add     [edi+8], eax
                lea     edx, [esi+edx*4+283F0h]
                adc     [edi+0Ch], ebp
                sub     ecx, eax
                mov     [edi+10h], ecx
                mov     eax, [edx]
                mov     ecx, eax
                shr     ecx, 5
                sub     eax, ecx
                mov     [edx], eax
                mov     eax, [edi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4D0CB6
                shl     eax, 8
                mov     ecx, edi
                mov     [edi+10h], eax
                call    loc_4CF640

loc_4D0CB6:                             ; CODE XREF: CEncoder_CodeOneBlock+3B7j
                mov     eax, [esp+30h+var_1C]
                cmp     eax, ebp
                mov     ecx, [edi+10h]
                jnz     short loc_4D0D24
                movzx   edx, byte ptr [esi+10h]
                lea     eax, [esi+edx*4+28420h]
                shr     ecx, 0Bh
                imul    ecx, [eax]
                mov     [edi+10h], ecx
                mov     ecx, [eax]
                mov     edx, 800h
                sub     edx, ecx
                shr     edx, 5
                add     edx, ecx
                mov     [eax], edx
                mov     eax, [edi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4D0CFC
                shl     eax, 8
                mov     ecx, edi
                mov     [edi+10h], eax
                call    loc_4CF640

loc_4D0CFC:                             ; CODE XREF: CEncoder_CodeOneBlock+3FDj
                mov     ebp, [esp+30h+var_18]
                movzx   ecx, byte ptr [esi+10h]
                xor     eax, eax
                cmp     ebp, 1
                setnz   al
                shl     ecx, 4
                add     ecx, ebx
                lea     ecx, [esi+ecx*4+284B0h]
                push    eax
                push    edi
                call    sub_4CFAC0
                jmp     loc_4D0E2E
; ---------------------------------------------------------------------------

loc_4D0D24:                             ; CODE XREF: CEncoder_CodeOneBlock+3CFj
                mov     edx, [esi+eax*4+14h]
                movzx   eax, byte ptr [esi+10h]
                mov     [esp+30h+var_8], edx
                lea     edx, [esi+eax*4+28420h]
                mov     eax, ecx
                shr     eax, 0Bh
                imul    eax, [edx]
                add     [edi+8], eax
                adc     [edi+0Ch], ebp
                sub     ecx, eax
                mov     [edi+10h], ecx
                mov     eax, [edx]
                mov     ecx, eax
                shr     ecx, 5
                sub     eax, ecx
                mov     [edx], eax
                mov     eax, [edi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4D0D6C
                shl     eax, 8
                mov     ecx, edi
                mov     [edi+10h], eax
                call    loc_4CF640

loc_4D0D6C:                             ; CODE XREF: CEncoder_CodeOneBlock+46Dj
                cmp     [esp+30h+var_1C], 1
                mov     ecx, [edi+10h]
                jnz     short loc_4D0DB3
                movzx   edx, byte ptr [esi+10h]
                lea     eax, [esi+edx*4+28450h]
                shr     ecx, 0Bh
                imul    ecx, [eax]
                mov     [edi+10h], ecx
                mov     ecx, [eax]
                mov     edx, 800h
                sub     edx, ecx
                shr     edx, 5
                add     edx, ecx
                mov     [eax], edx
                mov     eax, [edi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4D0E1D
                shl     eax, 8
                mov     ecx, edi
                mov     [edi+10h], eax
                call    loc_4CF640
                jmp     short loc_4D0E1D
; ---------------------------------------------------------------------------

loc_4D0DB3:                             ; CODE XREF: CEncoder_CodeOneBlock+484j
                movzx   eax, byte ptr [esi+10h]
                lea     edx, [esi+eax*4+28450h]
                mov     eax, ecx
                shr     eax, 0Bh
                imul    eax, [edx]
                add     [edi+8], eax
                adc     [edi+0Ch], ebp
                sub     ecx, eax
                mov     [edi+10h], ecx
                mov     eax, [edx]
                mov     ecx, eax
                shr     ecx, 5
                sub     eax, ecx
                mov     [edx], eax
                mov     eax, [edi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4D0DF3
                shl     eax, 8
                mov     ecx, edi
                mov     [edi+10h], eax
                call    loc_4CF640

loc_4D0DF3:                             ; CODE XREF: CEncoder_CodeOneBlock+4F4j
                mov     ebp, [esp+30h+var_1C]
                movzx   eax, byte ptr [esi+10h]
                lea     edx, [ebp-2]
                push    edx
                push    edi
                lea     ecx, [esi+eax*4+28480h]
                call    sub_4CFAC0
                cmp     ebp, 3
                jnz     short loc_4D0E17
                mov     ecx, [esi+1Ch]
                mov     [esi+20h], ecx

loc_4D0E17:                             ; CODE XREF: CEncoder_CodeOneBlock+51Fj
                mov     edx, [esi+18h]
                mov     [esi+1Ch], edx

loc_4D0E1D:                             ; CODE XREF: CEncoder_CodeOneBlock+4B2j
                                        ; CEncoder_CodeOneBlock+4C1j
                mov     eax, [esi+14h]
                mov     ecx, [esp+30h+var_8]
                mov     ebp, [esp+30h+var_18]
                mov     [esi+18h], eax
                mov     [esi+14h], ecx

loc_4D0E2E:                             ; CODE XREF: CEncoder_CodeOneBlock+42Fj
                cmp     ebp, 1
                jnz     short loc_4D0E45
                movzx   edx, byte ptr [esi+10h]
                mov     al, ds:kShortRepNextStates[edx]
                mov     [esi+10h], al
                jmp     loc_4D0FF5
; ---------------------------------------------------------------------------

loc_4D0E45:                             ; CODE XREF: CEncoder_CodeOneBlock+541j
                cmp     byte ptr [esi+32EF4h], 0
                push    ebx
                lea     edx, [ebp-2]
                push    edx
                lea     ecx, [esi+2DA04h]
                push    edi
                setz    [esp+3Ch+var_20]
                call    sub_4D0020
                cmp     [esp+30h+var_20], 0
                jz      short loc_4D0E7F
                add     dword ptr [esi+ebx*4+32610h], 0FFFFFFFFh
                lea     ecx, [esi+2DA04h]
                jnz     short loc_4D0E7F
                push    ebx
                call    sub_4CF740

loc_4D0E7F:                             ; CODE XREF: CEncoder_CodeOneBlock+577j
                                        ; CEncoder_CodeOneBlock+587j
                movzx   eax, byte ptr [esi+10h]
                mov     cl, ds:kRepNextStates[eax]
                mov     [esi+10h], cl
                jmp     loc_4D0FF5
; ---------------------------------------------------------------------------

loc_4D0E91:                             ; CODE XREF: CEncoder_CodeOneBlock+37Fj
                lea     eax, [esi+edx*4+283F0h]
                shr     ecx, 0Bh
                imul    ecx, [eax]
                mov     [edi+10h], ecx
                mov     ecx, [eax]
                mov     edx, 800h
                sub     edx, ecx
                shr     edx, 5
                add     edx, ecx
                mov     [eax], edx
                mov     eax, [edi+10h]
                cmp     eax, 1000000h
                jnb     short loc_4D0EC8
                shl     eax, 8
                mov     ecx, edi
                mov     [edi+10h], eax
                call    loc_4CF640

loc_4D0EC8:                             ; CODE XREF: CEncoder_CodeOneBlock+5C9j
                movzx   eax, byte ptr [esi+10h]
                mov     cl, ds:kMatchNextStates[eax]
                mov     eax, [esp+30h+var_18]
                mov     [esi+10h], cl
                cmp     byte ptr [esi+32EF4h], 0
                push    ebx
                setz    [esp+34h+var_20]
                add     eax, 0FFFFFFFEh
                push    eax
                lea     ebp, [esi+28DB8h]
                push    edi
                mov     ecx, ebp
                call    sub_4D0020
                cmp     [esp+30h+var_20], 0
                jz      short loc_4D0F11
                add     dword ptr [ebp+ebx*4+4C0Ch], 0FFFFFFFFh
                jnz     short loc_4D0F11
                push    ebx
                mov     ecx, ebp
                call    sub_4CF740

loc_4D0F11:                             ; CODE XREF: CEncoder_CodeOneBlock+60Dj
                                        ; CEncoder_CodeOneBlock+617j
                mov     eax, [esp+30h+var_1C]
                sub     eax, 4
                cmp     eax, 2000h
                mov     [esp+30h+var_1C], eax
                jnb     short loc_4D0F2C
                movzx   ebp, byte ptr dword_551198[eax]
                jmp     short loc_4D0F4F
; ---------------------------------------------------------------------------

loc_4D0F2C:                             ; CODE XREF: CEncoder_CodeOneBlock+631j
                cmp     eax, 2000000h
                jnb     short loc_4D0F42
                shr     eax, 0Ch
                movzx   ebp, byte ptr dword_551198[eax]
                add     ebp, 18h
                jmp     short loc_4D0F4F
; ---------------------------------------------------------------------------

loc_4D0F42:                             ; CODE XREF: CEncoder_CodeOneBlock+641j
                shr     eax, 18h
                movzx   ebp, byte ptr dword_551198[eax]
                add     ebp, 30h

loc_4D0F4F:                             ; CODE XREF: CEncoder_CodeOneBlock+63Aj
                                        ; CEncoder_CodeOneBlock+650j
                mov     eax, [esp+30h+var_18]
                add     eax, 0FFFFFFFEh
                cmp     eax, 4
                jb      short loc_4D0F60
                mov     eax, 3

loc_4D0F60:                             ; CODE XREF: CEncoder_CodeOneBlock+669j
                push    ebp
                shl     eax, 8
                push    edi
                lea     ecx, [eax+esi+287B0h]
                call    sub_4CFC60
                cmp     ebp, 4
                jb      short loc_4D0FD1
                mov     ebx, [esp+30h+var_1C]
                mov     ecx, ebp
                mov     eax, ebp
                and     eax, 1
                shr     ecx, 1
                sub     ecx, 1
                or      eax, 2
                shl     eax, cl
                sub     ebx, eax
                cmp     ebp, 0Eh
                jnb     short loc_4D0FA9
                push    ebx
                push    ecx
                sub     eax, ebp
                lea     edx, [esi+eax*4+28BACh]
                push    edi
                push    edx
                call    sub_4CFD90
                add     esp, 10h
                jmp     short loc_4D0FD1
; ---------------------------------------------------------------------------

loc_4D0FA9:                             ; CODE XREF: CEncoder_CodeOneBlock+6A0j
                add     ecx, 0FFFFFFFCh
                push    ecx
                mov     eax, ebx
                shr     eax, 4
                push    eax
                mov     ecx, edi
                call    sub_4CF6E0
                and     ebx, 0Fh
                push    ebx
                push    edi
                lea     ecx, [esi+28D78h]
                call    sub_4CFD00
                add     dword ptr [esi+33B54h], 1

loc_4D0FD1:                             ; CODE XREF: CEncoder_CodeOneBlock+684j
                                        ; CEncoder_CodeOneBlock+6B7j
                mov     ecx, [esi+1Ch]
                mov     edx, [esi+18h]
                mov     eax, [esi+14h]
                add     dword ptr [esi+33B70h], 1
                mov     ebp, [esp+30h+var_18]
                mov     [esi+20h], ecx
                mov     ecx, [esp+30h+var_1C]
                mov     [esi+1Ch], edx
                mov     [esi+18h], eax
                mov     [esi+14h], ecx

loc_4D0FF5:                             ; CODE XREF: CEncoder_CodeOneBlock+550j
                                        ; CEncoder_CodeOneBlock+59Cj
                mov     eax, [esi+80h]
                mov     ecx, [esi+6Ch]
                mov     edx, ebp
                sub     edx, [esi+32F04h]
                sub     edx, 1
                push    edx
                push    eax
                call    ecx
                add     esp, 8
                mov     [esi+11h], al

loc_4D1013:                             ; CODE XREF: CEncoder_CodeOneBlock+319j
                sub     [esi+32F04h], ebp
                mov     eax, [esi+32F04h]
                add     [esp+30h+var_14], ebp
                test    eax, eax
                jnz     loc_4D0AD0
                cmp     [esi+32EF4h], al
                jnz     short loc_4D1056
                cmp     dword ptr [esi+33B70h], 80h
                jb      short loc_4D1046
                mov     ecx, esi
                call    CEncoder_FillDistancesPrices

loc_4D1046:                             ; CODE XREF: CEncoder_CodeOneBlock+74Dj
                cmp     dword ptr [esi+33B54h], 10h
                jb      short loc_4D1056
                mov     ecx, esi
                call    CEncoder_FillAlignPrices

loc_4D1056:                             ; CODE XREF: CEncoder_CodeOneBlock+741j
                                        ; CEncoder_CodeOneBlock+75Dj
                mov     edx, [esi+80h]
                mov     eax, [esi+70h]
                push    edx
                call    eax
                add     esp, 4
                test    eax, eax
                mov     eax, [esp+30h+var_14]
                jz      short loc_4D10D7
                mov     ecx, [esp+30h+var_4]
                mov     edx, eax
                sub     edx, ecx
                cmp     edx, 4000h
                jb      loc_4D0AD0
                sub     eax, ecx
                add     [esi+33B78h], eax
                mov     ecx, [esi+33B78h]
                mov     eax, [esp+30h+arg_0]
                adc     dword ptr [esi+33B7Ch], 0
                mov     [eax], ecx
                mov     edx, [esi+33B7Ch]
                lea     ecx, [esi+28h]
                mov     [eax+4], edx
                call    sub_4CD8B0
                mov     ecx, [esp+30h+arg_4]
                mov     [ecx], eax
                mov     eax, [esp+30h+arg_8]
                mov     [ecx+4], edx
                pop     ebx
                mov     byte ptr [esi+33B80h], 0
                pop     edi
                mov     dword ptr [eax], 0
                mov     eax, [esi+0ECh]
                pop     esi
                pop     ebp
                add     esp, 20h
                retn    0Ch
; ---------------------------------------------------------------------------

loc_4D10D7:                             ; CODE XREF: CEncoder_CodeOneBlock+77Bj
                push    eax
                mov     ecx, esi
                call    CEncoder_Flush
                pop     ebx
                pop     edi
                pop     esi
                pop     ebp
                add     esp, 20h
                retn    0Ch
CEncoder_CodeOneBlock endp

; ---------------------------------------------------------------------------
                align 10h
CEncoder_CodeReal proc near             ; CODE XREF: CEncoder_Code+49p

var_20          = dword ptr -20h
processedOutSize= byte ptr -1Ch
processedInSize = byte ptr -14h
var_C           = dword ptr -0Ch
var_4           = dword ptr -4
inStream        = dword ptr  4
outStream       = dword ptr  8
inSize          = dword ptr  0Ch
outSize         = dword ptr  10h
progress        = dword ptr  14h

                push    0FFFFFFFFh
                push    offset loc_4DA128
                mov     eax, dword ptr fs:[0]
                push    eax
                sub     esp, 14h
                push    ebp
                push    esi
                push    edi
                mov     eax, dword_544960
                xor     eax, esp
                push    eax
                lea     eax, [esp+30h+var_C]
                mov     dword ptr fs:[0], eax
                mov     esi, ecx
                mov     [esp+30h+var_20], esi
                mov     eax, [esp+30h+outSize]
                mov     ecx, [esp+30h+inSize]
                mov     edx, [esp+30h+outStream]
                push    eax
                mov     eax, [esp+34h+inStream]
                push    ecx
                push    edx
                push    eax
                mov     ecx, esi
                mov     [esp+40h+var_4], 0
                call    CEncoder_SetStreams
                mov     edi, eax
                test    edi, edi
                jz      short loc_4D1190
                cmp     dword ptr [esi+80h], 0
                mov     [esp+30h+var_4], 0FFFFFFFFh
                jz      short loc_4D1166
                cmp     byte ptr [esi+33B95h], 0
                jz      short loc_4D1166
                mov     byte ptr [esi+33B95h], 0

loc_4D1166:                             ; CODE XREF: CEncoder_CodeReal+64j
                                        ; CEncoder_CodeReal+6Dj
                mov     eax, [esi+33B8Ch]
                test    eax, eax
                jz      short loc_4D1182
                mov     ecx, [eax]
                mov     edx, [ecx+8]
                push    eax
                call    edx
                mov     dword ptr [esi+33B8Ch], 0

loc_4D1182:                             ; CODE XREF: CEncoder_CodeReal+7Ej
                mov     ecx, [esi+4]
                mov     edx, [ecx+10h]
                lea     eax, [esi+4]
                push    eax
                call    edx
                jmp     short loc_4D1201
; ---------------------------------------------------------------------------

loc_4D1190:                             ; CODE XREF: CEncoder_CodeReal+53j
                lea     eax, [esp+30h+outSize]
                push    eax
                lea     ecx, [esp+34h+processedOutSize]
                push    ecx
                lea     edx, [esp+38h+processedInSize]
                push    edx
                mov     ecx, esi
                call    CEncoder_CodeOneBlock
                mov     edi, eax
                test    edi, edi
                jnz     short loc_4D11F0
                mov     ebp, [esp+30h+progress]

loc_4D11B0:                             ; CODE XREF: CEncoder_CodeReal+FEj
                cmp     [esp+30h+outSize], 0
                jnz     short loc_4D1218
                test    ebp, ebp
                jz      short loc_4D11D4
                mov     eax, [ebp+0]
                mov     eax, [eax+0Ch]
                lea     ecx, [esp+30h+processedOutSize]
                push    ecx
                lea     edx, [esp+34h+processedInSize]
                push    edx
                push    ebp
                call    eax             ; SetRatioInfo
                mov     edi, eax
                test    edi, edi
                jnz     short loc_4D11F0

loc_4D11D4:                             ; CODE XREF: CEncoder_CodeReal+C9j
                lea     ecx, [esp+30h+outSize]
                push    ecx
                lea     edx, [esp+34h+processedOutSize]
                push    edx
                lea     eax, [esp+38h+processedInSize]
                push    eax
                mov     ecx, esi
                call    CEncoder_CodeOneBlock
                mov     edi, eax
                test    edi, edi
                jz      short loc_4D11B0

loc_4D11F0:                             ; CODE XREF: CEncoder_CodeReal+BAj
                                        ; CEncoder_CodeReal+E2j
                lea     ecx, [esp+30h+var_20]
                mov     [esp+30h+var_4], 0FFFFFFFFh
                call    sub_4CDA70

loc_4D1201:                             ; CODE XREF: CEncoder_CodeReal+9Ej
                mov     eax, edi
                mov     ecx, [esp+30h+var_C]
                mov     dword ptr fs:[0], ecx
                pop     ecx
                pop     edi
                pop     esi
                pop     ebp
                add     esp, 20h
                retn    14h
; ---------------------------------------------------------------------------

loc_4D1218:                             ; CODE XREF: CEncoder_CodeReal+C5j
                lea     ecx, [esp+30h+var_20]
                mov     [esp+30h+var_4], 0FFFFFFFFh
                call    sub_4CDA70
                xor     eax, eax
                mov     ecx, [esp+30h+var_C]
                mov     dword ptr fs:[0], ecx
                pop     ecx
                pop     edi
                pop     esi
                pop     ebp
                add     esp, 20h
                retn    14h
CEncoder_CodeReal endp

; =============== S U B R O U T I N E =======================================
; Attributes: bp-based frame

CEncoder_Code   proc near               ; DATA XREF: .rdata:00517B08o
; sub_4D1240

var_10          = dword ptr -10h
var_C           = dword ptr -0Ch
var_4           = dword ptr -4
pThis           = dword ptr  8
pInStream       = dword ptr  0Ch
pOutStream      = dword ptr  10h
pInSize         = dword ptr  14h
pOutSize        = dword ptr  18h
progress        = dword ptr  1Ch

                push    ebp
                mov     ebp, esp
                push    0FFFFFFFFh
                push    offset loc_4DA150
                mov     eax, dword ptr fs:[0]
                push    eax
                sub     esp, 8
                push    ebx
                push    esi
                push    edi
                mov     eax, dword_544960
                xor     eax, ebp
                push    eax
                lea     eax, [ebp+var_C]
                mov     dword ptr fs:[0], eax
                mov     [ebp+var_10], esp
                mov     eax, [ebp+progress]
                mov     ecx, [ebp+pOutSize]
                mov     edx, [ebp+pInSize]
                push    eax
                mov     eax, [ebp+pOutStream]
                push    ecx
                mov     ecx, [ebp+pInStream]
                push    edx
                push    eax
                push    ecx
                mov     ecx, [ebp+pThis]
                mov     [ebp+var_4], 0
                call    CEncoder_CodeReal
                mov     ecx, [ebp+var_C]
                mov     dword ptr fs:[0], ecx
                pop     ecx
                pop     edi
                pop     esi
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    18h
CEncoder_Code   endp

; ---------------------------------------------------------------------------

loc_4DA0FB:                             ; DATA XREF: Compress_lzma_internal+2o
                mov     edx, [esp+8]
                lea     eax, [edx-5Ch]
                mov     ecx, [edx-60h]
                xor     ecx, eax
                call    sub_4A0686
                mov     eax, 0  ; offset dword_526E44
                int 3;
;               jmp     ___CxxFrameHandler3

loc_4DA0C9:                             ; DATA XREF: sub_4CF810+2o
                mov     edx, [esp+8]
                lea     eax, [edx-0Ch]
                mov     ecx, [edx-10h]
                xor     ecx, eax
                call    sub_4A0686
                mov     eax, 0  ; offset dword_526E18
                int 3;
;               jmp     ___CxxFrameHandler3

loc_4DA128:                             ; DATA XREF: CEncoder_CodeReal+2o
                mov     edx, [esp+8]
                lea     eax, [edx-20h]
                mov     ecx, [edx-24h]
                xor     ecx, eax
                call    sub_4A0686
                mov     eax, 0  ; offset unk_526E70
                int 3;
;               jmp     ___CxxFrameHandler3

loc_4DA150:                             ; DATA XREF: CEncoder_Code+5o
                mov     edx, [esp+8]
                lea     eax, [edx+0Ch]
                mov     ecx, [edx-18h]
                xor     ecx, eax
                call    sub_4A0686
                mov     eax, 0  ; offset unk_526ED8
                int 3;
;               jmp     ___CxxFrameHandler3

END
