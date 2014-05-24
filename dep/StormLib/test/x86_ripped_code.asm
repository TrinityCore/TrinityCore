.686P
.MODEL FLAT
ASSUME FS: NOTHING
.CODE

extrn _memset:PROC
extrn _memcpy:PROC
extrn _memmove:PROC

;------------------------------------------------------------------------------
; Structures
;

;------------------------------------------------------------------------------
; Functions
;

_aullrem        proc near               ; CODE XREF: sub_6CC140+3Ap
                                        ; sub_6CC1E0+57p ...

DividendLo      = dword ptr  8
DividendHi      = dword ptr  0Ch
DivisorLo       = dword ptr  10h
DivisorHi       = dword ptr  14h

                push    ebx
                mov     eax, [esp+DivisorHi]
                or      eax, eax
                jnz     short loc_8F8FE1
                mov     ecx, [esp+DivisorLo]
                mov     eax, [esp+DividendHi]
                xor     edx, edx
                div     ecx
                mov     eax, [esp+DividendLo]
                div     ecx
                mov     eax, edx
                xor     edx, edx
                jmp     short loc_8F9031
; ---------------------------------------------------------------------------

loc_8F8FE1:                             ; CODE XREF: _aullrem+7j
                mov     ecx, eax
                mov     ebx, [esp+DivisorLo]
                mov     edx, [esp+DividendHi]
                mov     eax, [esp+DividendLo]

loc_8F8FEF:                             ; CODE XREF: _aullrem+39j
                shr     ecx, 1
                rcr     ebx, 1
                shr     edx, 1
                rcr     eax, 1
                or      ecx, ecx
                jnz     short loc_8F8FEF
                div     ebx
                mov     ecx, eax
                mul     [esp+DivisorHi]
                xchg    eax, ecx
                mul     [esp+DivisorLo]
                add     edx, ecx
                jb      short loc_8F901A
                cmp     edx, [esp+DividendHi]
                ja      short loc_8F901A
                jb      short loc_8F9022
                cmp     eax, [esp+DividendLo]
                jbe     short loc_8F9022

loc_8F901A:                             ; CODE XREF: _aullrem+4Aj
                                        ; _aullrem+50j
                sub     eax, [esp+DivisorLo]
                sbb     edx, [esp+DivisorHi]

loc_8F9022:                             ; CODE XREF: _aullrem+52j
                                        ; _aullrem+58j
                sub     eax, [esp+DividendLo]
                sbb     edx, [esp+DividendHi]
                neg     edx
                neg     eax
                sbb     edx, 0

loc_8F9031:                             ; CODE XREF: _aullrem+1Fj
                pop     ebx
                retn    10h
_aullrem        endp

_aullshr        proc near               ; CODE XREF: sub_40E2B6+1ECp
                                        ; sub_40E2B6+240p ...
                cmp     cl, 40h
                jnb     short loc_414BDA
                cmp     cl, 20h
                jnb     short loc_414BD0
                shrd    eax, edx, cl
                shr     edx, cl
                retn
; ---------------------------------------------------------------------------

loc_414BD0:                             ; CODE XREF: _aullshr+8j
                mov     eax, edx
                xor     edx, edx
                and     cl, 1Fh
                shr     eax, cl
                retn
; ---------------------------------------------------------------------------

loc_414BDA:                             ; CODE XREF: _aullshr+3j
                xor     eax, eax
                xor     edx, edx
                retn
_aullshr        endp


; =============== S U B R O U T I N E =======================================

; Attributes: bp-based frame

SFileDecryptMpqHeader proc near         ; CODE XREF: sub_6D00E0+AEp
                                        ; sub_6D00E0+D3p

EncryptedDataAligned= dword ptr -88h
var_48          = dword ptr -48h
DecryptBuffer   = dword ptr -44h
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
var_0C          = dword ptr -0Ch
var_8           = dword ptr -8
var_4           = dword ptr -4
arg_FFFFFFF8    = dword ptr  0
arg_FFFFFFFC    = dword ptr  4
arg_0           = dword ptr  8

                push    ebp
                mov     ebp, esp
                sub     esp, 88h
                mov     eax, [ecx+8]
                mov     edx, [ecx+14h]
                push    ebx
                mov     ebx, [ecx+10h]
                mov     [ebp+var_0C], eax
                mov     eax, [ebp+arg_0]
                push    esi
                push    edi
                mov     edi, [ecx+0Ch]
                mov     [ebp+DecryptBuffer], ecx
                mov     [ebp+var_10], edx
                test    al, 3
                jz      short loc_6C9F03
                mov     ecx, [eax]
                mov     [ebp+EncryptedDataAligned], ecx
                mov     ecx, [eax+4]
                mov     [ebp+EncryptedDataAligned+4], ecx
                mov     ecx, [eax+8]
                mov     [ebp+EncryptedDataAligned+8], ecx
                mov     ecx, [eax+0Ch]
                mov     [ebp+EncryptedDataAligned+0Ch], ecx
                mov     ecx, [eax+10h]
                mov     [ebp+EncryptedDataAligned+10h], ecx
                mov     ecx, [eax+14h]
                mov     [ebp+EncryptedDataAligned+14h], ecx
                mov     ecx, [eax+18h]
                mov     [ebp+EncryptedDataAligned+18h], ecx
                mov     ecx, [eax+1Ch]
                mov     [ebp+EncryptedDataAligned+1Ch], ecx
                mov     ecx, [eax+20h]
                mov     [ebp+EncryptedDataAligned+20h], ecx
                mov     ecx, [eax+24h]
                mov     [ebp+EncryptedDataAligned+24h], ecx
                mov     ecx, [eax+28h]
                mov     [ebp+EncryptedDataAligned+28h], ecx
                mov     ecx, [eax+2Ch]
                mov     [ebp+EncryptedDataAligned+2Ch], ecx
                mov     ecx, [eax+30h]
                mov     [ebp+EncryptedDataAligned+30h], ecx
                mov     ecx, [eax+34h]
                mov     [ebp+EncryptedDataAligned+34h], ecx
                mov     ecx, [eax+38h]
                mov     eax, [eax+3Ch]
                mov     [ebp+EncryptedDataAligned+3Ch], eax
                mov     [ebp+EncryptedDataAligned+38h], ecx
                lea     eax, [ebp+EncryptedDataAligned]

loc_6C9F03:                             ; CODE XREF: SFileDecryptMpqHeader+26j
                mov     ecx, [eax]
                mov     [ebp+var_30], ecx
                mov     esi, edi
                not     esi
                and     esi, edx
                mov     edx, ebx
                and     edx, edi
                or      esi, edx
                add     esi, ecx
                mov     ecx, [ebp+var_0C]
                lea     edx, [esi+ecx-28955B88h]
                mov     ecx, [eax+4]
                rol     edx, 7
                add     edx, edi
                mov     [ebp+var_2C], ecx
                mov     ecx, edx
                not     ecx
                and     ecx, ebx
                mov     esi, edi
                and     esi, edx
                or      ecx, esi
                add     ecx, [ebp+var_2C]
                mov     esi, [ebp+var_10]
                lea     esi, [ecx+esi-173848AAh]
                mov     ecx, [eax+8]
                mov     [ebp+var_40], ecx
                rol     esi, 0Ch
                add     esi, edx
                mov     ecx, esi
                not     ecx
                and     ecx, edi
                mov     edi, esi
                and     edi, edx
                or      ecx, edi
                add     ecx, [ebp+var_40]
                lea     edi, [ecx+ebx+242070DBh]
                mov     ecx, [eax+0Ch]
                ror     edi, 0Fh
                add     edi, esi
                mov     [ebp+var_1C], ecx
                mov     ebx, edi
                not     ebx
                and     ebx, edx
                mov     ecx, esi
                and     ecx, edi
                or      ebx, ecx
                add     ebx, [ebp+var_1C]
                mov     ecx, [ebp+DecryptBuffer]
                mov     ecx, [ecx+0Ch]
                lea     ecx, [ebx+ecx-3E423112h]
                ror     ecx, 0Ah
                add     ecx, edi
                mov     [ebp+var_4], edi
                and     edi, ecx
                mov     ebx, ecx
                not     ebx
                and     ebx, esi
                or      ebx, edi
                mov     edi, [eax+10h]
                add     ebx, edi
                lea     edx, [ebx+edx-0A83F051h]
                rol     edx, 7
                add     edx, ecx
                mov     [ebp+arg_0], edx
                not     edx
                and     edx, [ebp+var_4]
                mov     ebx, ecx
                and     ebx, [ebp+arg_0]
                mov     [ebp+var_10], edi
                mov     edi, [eax+14h]
                or      edx, ebx
                add     edx, edi
                lea     esi, [edx+esi+4787C62Ah]
                mov     edx, [eax+18h]
                mov     [ebp+var_34], edi
                mov     edi, [ebp+arg_0]
                rol     esi, 0Ch
                add     esi, edi
                mov     [ebp+var_20], edx
                mov     edx, esi
                not     edx
                and     edx, ecx
                mov     ebx, esi
                and     ebx, edi
                or      edx, ebx
                add     edx, [ebp+var_20]
                mov     ebx, [ebp+var_4]
                lea     edx, [edx+ebx-57CFB9EDh]
                ror     edx, 0Fh
                add     edx, esi
                mov     ebx, edx
                not     ebx
                and     ebx, edi
                mov     edi, esi
                and     edi, edx
                or      ebx, edi
                mov     edi, [eax+1Ch]
                add     ebx, edi
                lea     ecx, [ebx+ecx-2B96AFFh]
                ror     ecx, 0Ah
                add     ecx, edx
                mov     [ebp+var_3C], edi
                mov     edi, [eax+20h]
                mov     [ebp+var_14], edi
                mov     edi, ecx
                not     edi
                and     edi, esi
                mov     ebx, edx
                and     ebx, ecx
                or      edi, ebx
                add     edi, [ebp+var_14]
                mov     ebx, [ebp+arg_0]
                lea     edi, [edi+ebx+698098D8h]
                mov     [ebp+var_8], ecx
                rol     edi, 7
                add     edi, ecx
                and     ecx, edi
                mov     ebx, edi
                not     ebx
                and     ebx, edx
                or      ebx, ecx
                mov     ecx, [eax+24h]
                add     ebx, ecx
                mov     [ebp+var_0C], ecx
                mov     ecx, [eax+28h]
                lea     esi, [ebx+esi-74BB0851h]
                mov     [ebp+var_24], ecx
                rol     esi, 0Ch
                add     esi, edi
                mov     ecx, esi
                not     ecx
                and     ecx, [ebp+var_8]
                mov     ebx, esi
                and     ebx, edi
                or      ecx, ebx
                add     ecx, [ebp+var_24]
                mov     ebx, esi
                lea     edx, [ecx+edx-0A44Fh]
                mov     ecx, [eax+2Ch]
                ror     edx, 0Fh
                add     edx, esi
                mov     [ebp+var_18], ecx
                and     ebx, edx
                mov     ecx, edx
                not     ecx
                and     ecx, edi
                or      ecx, ebx
                add     ecx, [ebp+var_18]
                mov     ebx, [ebp+var_8]
                lea     ecx, [ecx+ebx-76A32842h]
                ror     ecx, 0Ah
                add     ecx, edx
                mov     ebx, ecx
                not     ebx
                mov     [ebp+var_4], edx
                and     edx, ecx
                and     ebx, esi
                or      ebx, edx
                mov     edx, [eax+30h]
                add     ebx, edx
                mov     [ebp+var_38], edx
                lea     edi, [ebx+edi+6B901122h]
                mov     edx, [eax+34h]
                rol     edi, 7
                add     edi, ecx
                mov     [ebp+arg_0], edi
                not     edi
                and     edi, [ebp+var_4]
                mov     ebx, ecx
                and     ebx, [ebp+arg_0]
                mov     [ebp+var_8], edx
                or      edi, ebx
                add     edi, edx
                mov     edx, [eax+38h]
                mov     eax, [eax+3Ch]
                lea     esi, [edi+esi-2678E6Dh]
                rol     esi, 0Ch
                add     esi, [ebp+arg_0]
                mov     [ebp+var_28], edx
                mov     edi, esi
                not     edi
                mov     edx, edi
                and     edx, ecx
                mov     ebx, esi
                and     ebx, [ebp+arg_0]
                or      edx, ebx
                add     edx, [ebp+var_28]
                mov     ebx, [ebp+var_4]
                lea     edx, [edx+ebx-5986BC72h]
                mov     [ebp+var_4], eax
                ror     edx, 0Fh
                add     edx, esi
                mov     ebx, edx
                not     ebx
                mov     [ebp+var_48], ebx
                and     ebx, [ebp+arg_0]
                mov     eax, esi
                and     eax, edx
                or      ebx, eax
                add     ebx, [ebp+var_4]
                and     edi, edx
                lea     ecx, [ebx+ecx+49B40821h]
                ror     ecx, 0Ah
                add     ecx, edx
                mov     eax, esi
                and     eax, ecx
                or      edi, eax
                add     edi, [ebp+var_2C]
                mov     eax, [ebp+arg_0]
                lea     edi, [edi+eax-9E1DA9Eh]
                mov     eax, [ebp+var_48]
                and     eax, ecx
                rol     edi, 5
                add     edi, ecx
                mov     ebx, edx
                and     ebx, edi
                or      eax, ebx
                add     eax, [ebp+var_20]
                lea     esi, [eax+esi-3FBF4CC0h]
                rol     esi, 9
                add     esi, edi
                mov     eax, ecx
                not     eax
                and     eax, edi
                mov     ebx, esi
                and     ebx, ecx
                or      eax, ebx
                add     eax, [ebp+var_18]
                lea     edx, [eax+edx+265E5A51h]
                rol     edx, 0Eh
                add     edx, esi
                mov     eax, edi
                not     eax
                and     eax, esi
                mov     ebx, edx
                and     ebx, edi
                or      eax, ebx
                add     eax, [ebp+var_30]
                lea     ecx, [eax+ecx-16493856h]
                ror     ecx, 0Ch
                mov     eax, esi
                add     ecx, edx
                not     eax
                and     eax, edx
                mov     ebx, esi
                and     ebx, ecx
                or      eax, ebx
                add     eax, [ebp+var_34]
                lea     edi, [eax+edi-29D0EFA3h]
                rol     edi, 5
                add     edi, ecx
                mov     [ebp+arg_0], edi
                mov     eax, edx
                not     eax
                and     eax, ecx
                mov     edi, edx
                and     edi, [ebp+arg_0]
                or      eax, edi
                add     eax, [ebp+var_24]
                mov     edi, ecx
                lea     esi, [eax+esi+2441453h]
                mov     eax, [ebp+arg_0]
                not     edi
                and     edi, eax
                rol     esi, 9
                add     esi, eax
                not     eax
                and     eax, esi
                mov     ebx, esi
                and     ebx, ecx
                or      edi, ebx
                add     edi, [ebp+var_4]
                lea     edx, [edi+edx-275E197Fh]
                rol     edx, 0Eh
                add     edx, esi
                mov     edi, edx
                and     edi, [ebp+arg_0]
                or      eax, edi
                add     eax, [ebp+var_10]
                mov     edi, esi
                lea     ecx, [eax+ecx-182C0438h]
                ror     ecx, 0Ch
                add     ecx, edx
                and     edi, ecx
                mov     eax, esi
                not     eax
                and     eax, edx
                or      eax, edi
                add     eax, [ebp+var_0C]
                mov     edi, [ebp+arg_0]
                lea     eax, [eax+edi+21E1CDE6h]
                rol     eax, 5
                add     eax, ecx
                mov     [ebp+arg_0], eax
                mov     eax, edx
                not     eax
                and     eax, ecx
                mov     edi, edx
                and     edi, [ebp+arg_0]
                or      eax, edi
                add     eax, [ebp+var_28]
                mov     edi, ecx
                lea     esi, [eax+esi-3CC8F82Ah]
                mov     eax, [ebp+arg_0]
                rol     esi, 9
                add     esi, eax
                not     edi
                and     edi, eax
                mov     ebx, esi
                and     ebx, ecx
                or      edi, ebx
                add     edi, [ebp+var_1C]
                not     eax
                lea     edx, [edi+edx-0B2AF279h]
                rol     edx, 0Eh
                add     edx, esi
                and     eax, esi
                mov     edi, edx
                and     edi, [ebp+arg_0]
                or      eax, edi
                add     eax, [ebp+var_14]
                lea     ecx, [eax+ecx+455A14EDh]
                ror     ecx, 0Ch
                add     ecx, edx
                mov     eax, esi
                not     eax
                and     eax, edx
                mov     edi, esi
                and     edi, ecx
                or      eax, edi
                add     eax, [ebp+var_8]
                mov     edi, [ebp+arg_0]
                lea     eax, [eax+edi-561C16FBh]
                rol     eax, 5
                add     eax, ecx
                mov     [ebp+arg_0], eax
                mov     eax, edx
                not     eax
                and     eax, ecx
                mov     edi, edx
                and     edi, [ebp+arg_0]
                or      eax, edi
                add     eax, [ebp+var_40]
                mov     edi, ecx
                lea     esi, [eax+esi-3105C08h]
                mov     eax, [ebp+arg_0]
                not     edi
                and     edi, eax
                rol     esi, 9
                add     esi, eax
                mov     ebx, esi
                and     ebx, ecx
                or      edi, ebx
                add     edi, [ebp+var_3C]
                not     eax
                lea     edx, [edi+edx+676F02D9h]
                and     eax, esi
                rol     edx, 0Eh
                add     edx, esi
                mov     edi, edx
                and     edi, [ebp+arg_0]
                or      eax, edi
                add     eax, [ebp+var_38]
                mov     edi, [ebp+arg_0]
                lea     ecx, [eax+ecx-72D5B376h]
                ror     ecx, 0Ch
                add     ecx, edx
                mov     eax, esi
                xor     eax, edx
                xor     eax, ecx
                add     eax, [ebp+var_34]
                lea     eax, [eax+edi-5C6BEh]
                rol     eax, 4
                add     eax, ecx
                mov     edi, edx
                xor     edi, ecx
                xor     edi, eax
                add     edi, [ebp+var_14]
                lea     esi, [edi+esi-788E097Fh]
                rol     esi, 0Bh
                add     esi, eax
                mov     edi, esi
                xor     edi, ecx
                xor     edi, eax
                add     edi, [ebp+var_18]
                lea     edx, [edi+edx+6D9D6122h]
                rol     edx, 10h
                add     edx, esi
                mov     edi, esi
                xor     edi, edx
                mov     ebx, edi
                xor     ebx, eax
                add     ebx, [ebp+var_28]
                lea     ecx, [ebx+ecx-21AC7F4h]
                ror     ecx, 9
                add     ecx, edx
                xor     edi, ecx
                add     edi, [ebp+var_2C]
                lea     eax, [edi+eax-5B4115BCh]
                rol     eax, 4
                mov     edi, edx
                add     eax, ecx
                xor     edi, ecx
                xor     edi, eax
                add     edi, [ebp+var_10]
                lea     esi, [edi+esi+4BDECFA9h]
                rol     esi, 0Bh
                add     esi, eax
                mov     edi, esi
                xor     edi, ecx
                xor     edi, eax
                add     edi, [ebp+var_3C]
                lea     edx, [edi+edx-944B4A0h]
                rol     edx, 10h
                add     edx, esi
                mov     edi, esi
                xor     edi, edx
                mov     ebx, edi
                xor     ebx, eax
                add     ebx, [ebp+var_24]
                lea     ecx, [ebx+ecx-41404390h]
                ror     ecx, 9
                add     ecx, edx
                xor     edi, ecx
                add     edi, [ebp+var_8]
                lea     eax, [edi+eax+289B7EC6h]
                rol     eax, 4
                add     eax, ecx
                mov     edi, edx
                xor     edi, ecx
                xor     edi, eax
                add     edi, [ebp+var_30]
                lea     esi, [edi+esi-155ED806h]
                rol     esi, 0Bh
                add     esi, eax
                mov     edi, esi
                xor     edi, ecx
                xor     edi, eax
                add     edi, [ebp+var_1C]
                lea     edi, [edi+edx-2B10CF7Bh]
                rol     edi, 10h
                add     edi, esi
                mov     edx, esi
                xor     edx, edi
                mov     ebx, edx
                xor     ebx, eax
                add     ebx, [ebp+var_20]
                lea     ecx, [ebx+ecx+4881D05h]
                ror     ecx, 9
                add     ecx, edi
                xor     edx, ecx
                add     edx, [ebp+var_0C]
                lea     eax, [edx+eax-262B2FC7h]
                rol     eax, 4
                add     eax, ecx
                mov     edx, edi
                xor     edx, ecx
                xor     edx, eax
                add     edx, [ebp+var_38]
                lea     edx, [edx+esi-1924661Bh]
                rol     edx, 0Bh
                add     edx, eax
                mov     esi, edx
                xor     esi, ecx
                xor     esi, eax
                add     esi, [ebp+var_4]
                mov     ebx, edx
                lea     esi, [esi+edi+1FA27CF8h]
                mov     edi, [ebp+var_40]
                rol     esi, 10h
                add     esi, edx
                xor     ebx, esi
                xor     ebx, eax
                add     ebx, edi
                lea     ecx, [ebx+ecx-3B53A99Bh]
                ror     ecx, 9
                add     ecx, esi
                mov     ebx, edx
                not     ebx
                or      ebx, ecx
                xor     ebx, esi
                add     ebx, [ebp+var_30]
                lea     eax, [ebx+eax-0BD6DDBCh]
                rol     eax, 6
                add     eax, ecx
                mov     ebx, esi
                not     ebx
                or      ebx, eax
                xor     ebx, ecx
                add     ebx, [ebp+var_3C]
                lea     edx, [ebx+edx+432AFF97h]
                rol     edx, 0Ah
                add     edx, eax
                mov     ebx, ecx
                not     ebx
                or      ebx, edx
                xor     ebx, eax
                add     ebx, [ebp+var_28]
                lea     esi, [ebx+esi-546BDC59h]
                rol     esi, 0Fh
                add     esi, edx
                mov     ebx, eax
                not     ebx
                or      ebx, esi
                xor     ebx, edx
                add     ebx, [ebp+var_34]
                lea     ecx, [ebx+ecx-36C5FC7h]
                ror     ecx, 0Bh
                add     ecx, esi
                mov     ebx, edx
                not     ebx
                or      ebx, ecx
                xor     ebx, esi
                add     ebx, [ebp+var_38]
                lea     eax, [ebx+eax+655B59C3h]
                rol     eax, 6
                add     eax, ecx
                mov     ebx, esi
                not     ebx
                or      ebx, eax
                xor     ebx, ecx
                add     ebx, [ebp+var_1C]
                lea     edx, [ebx+edx-70F3336Eh]
                rol     edx, 0Ah
                add     edx, eax
                mov     ebx, ecx
                not     ebx
                or      ebx, edx
                xor     ebx, eax
                add     ebx, [ebp+var_24]
                lea     esi, [ebx+esi-100B83h]
                rol     esi, 0Fh
                add     esi, edx
                mov     ebx, eax
                not     ebx
                or      ebx, esi
                xor     ebx, edx
                add     ebx, [ebp+var_2C]
                lea     ecx, [ebx+ecx-7A7BA22Fh]
                ror     ecx, 0Bh
                add     ecx, esi
                mov     ebx, edx
                not     ebx
                or      ebx, ecx
                xor     ebx, esi
                add     ebx, [ebp+var_14]
                lea     eax, [ebx+eax+6FA87E4Fh]
                rol     eax, 6
                add     eax, ecx
                mov     ebx, esi
                not     ebx
                or      ebx, eax
                xor     ebx, ecx
                add     ebx, [ebp+var_4]
                lea     edx, [ebx+edx-1D31920h]
                rol     edx, 0Ah
                add     edx, eax
                mov     ebx, ecx
                not     ebx
                or      ebx, edx
                xor     ebx, eax
                add     ebx, [ebp+var_20]
                lea     esi, [ebx+esi-5CFEBCECh]
                rol     esi, 0Fh
                mov     ebx, eax
                add     esi, edx
                not     ebx
                or      ebx, esi
                xor     ebx, edx
                add     ebx, [ebp+var_8]
                lea     ecx, [ebx+ecx+4E0811A1h]
                ror     ecx, 0Bh
                add     ecx, esi
                mov     ebx, edx
                not     ebx
                or      ebx, ecx
                xor     ebx, esi
                add     ebx, [ebp+var_10]
                lea     eax, [ebx+eax-8AC817Eh]
                rol     eax, 6
                add     eax, ecx
                mov     ebx, esi
                not     ebx
                or      ebx, eax
                xor     ebx, ecx
                add     ebx, [ebp+var_18]
                lea     edx, [ebx+edx-42C50DCBh]
                rol     edx, 0Ah
                add     edx, eax
                mov     ebx, ecx
                not     ebx
                or      ebx, edx
                xor     ebx, eax
                add     ebx, edi
                lea     esi, [ebx+esi+2AD7D2BBh]
                mov     edi, eax
                not     edi
                rol     esi, 0Fh
                add     esi, edx
                or      edi, esi
                xor     edi, edx
                add     edi, [ebp+var_0C]
                lea     edi, [edi+ecx-14792C6Fh]
                mov     ecx, [ebp+DecryptBuffer]
                mov     ebx, [ecx+8]
                add     ebx, eax
                mov     eax, [ecx+10h]
                ror     edi, 0Bh
                add     edi, [ecx+0Ch]
                add     eax, esi
                add     edi, esi
                mov     [ecx+10h], eax
                mov     eax, [ecx+14h]
                mov     [ecx+0Ch], edi
                pop     edi
                add     eax, edx
                pop     esi
                mov     [ecx+8], ebx
                mov     [ecx+14h], eax
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    4
SFileDecryptMpqHeader endp

; ---------------------------------------------------------------------------

; ---------------------------------------------------------------------------

sub_6D00E0      proc near               ; CODE XREF: sub_6D0210+59p
                                        ; sub_6D0210+66p ...

var_10          = dword ptr -10h
pbMpqHeader     = dword ptr -4
pMpqHeader      = dword ptr  8
dwSize          = dword ptr  0Ch

                push    ebp
                mov     ebp, esp
                push    ecx
                mov     eax, [ebp+pMpqHeader] ; EAX = MPQ Header
                push    ebx
                mov     ebx, [ebp+dwSize] ; EBX - size of MPQ Header
                push    esi
                push    edi
                mov     esi, ecx        ; ESI - decryption buffer (6 DWORDs)
                mov     edi, [esi]
                shr     edi, 3
                and     edi, 3Fh
                mov     [ebp+pbMpqHeader], eax
                lea     ecx, ds:0[ebx*8] ; ECX = sizeof header * 8
                test    ebx, ebx
                jbe     loc_6D01F8
                add     [esi], ecx
                mov     edx, ebx        ; EDX = size of header
                shr     edx, 1Dh
                add     [esi+4], edx
                mov     edx, [esi+4]
                cmp     [esi], ecx
                jnb     short loc_6D011E
                inc     edx
                mov     [esi+4], edx

loc_6D011E:                             ; CODE XREF: sub_6D00E0+38j
                test    edi, edi
                jz      short loc_6D0196
                lea     eax, [edi+ebx]
                cmp     eax, 40h
                jbe     short loc_6D0136
                mov     eax, 40h
                sub     eax, edi
                mov     [ebp+dwSize], eax
                jmp     short loc_6D013B
; ---------------------------------------------------------------------------

loc_6D0136:                             ; CODE XREF: sub_6D00E0+48j
                mov     [ebp+dwSize], ebx
                mov     eax, ebx

loc_6D013B:                             ; CODE XREF: sub_6D00E0+54j
                mov     edx, [ebp+pMpqHeader]
                add     edx, eax
                lea     ecx, [edi+esi+18h]
                mov     [ebp+pbMpqHeader], edx
                cmp     ecx, edx
                jnb     short loc_6D0163
                lea     edx, [ecx+eax]
                mov     ecx, [ebp+pMpqHeader]
                cmp     edx, ecx
                jbe     short loc_6D0166
                push    eax
                push    ecx
                lea     eax, [edi+esi+18h]
                push    eax
                call    _memmove
                jmp     short loc_6D0172
; ---------------------------------------------------------------------------

loc_6D0163:                             ; CODE XREF: sub_6D00E0+69j
                mov     ecx, [ebp+pMpqHeader]

loc_6D0166:                             ; CODE XREF: sub_6D00E0+73j
                push    eax
                push    ecx
                lea     eax, [edi+esi+18h]
                push    eax
                call    _memcpy

loc_6D0172:                             ; CODE XREF: sub_6D00E0+81j
                mov     eax, [ebp+dwSize]
                lea     ecx, [eax+edi]
                add     esp, 0Ch
                cmp     ecx, 40h
                jl      short loc_6D01F8
                mov     edx, [ebp+pbMpqHeader]
                sub     ebx, eax
                lea     eax, [esi+18h]
                push    eax
                mov     ecx, esi
                mov     [ebp+pbMpqHeader], edx
                call    SFileDecryptMpqHeader
                mov     eax, [ebp+pbMpqHeader]

loc_6D0196:                             ; CODE XREF: sub_6D00E0+40j
                cmp     ebx, 40h
                jl      short loc_6D01C4
                mov     edi, ebx
                shr     edi, 6
                mov     ecx, edi
                neg     ecx
                shl     ecx, 6
                add     ebx, ecx
                lea     esp, [esp+0]

loc_6D01B0:                             ; CODE XREF: sub_6D00E0+E2j
                push    eax
                mov     ecx, esi
                call    SFileDecryptMpqHeader
                add     [ebp+pbMpqHeader], 40h
                sub     edi, 1
                mov     eax, [ebp+pbMpqHeader]
                jnz     short loc_6D01B0

loc_6D01C4:                             ; CODE XREF: sub_6D00E0+B9j
                test    ebx, ebx
                jz      short loc_6D01F8
                add     esi, 18h
                lea     edx, [ebx+eax]
                cmp     esi, edx
                jnb     short loc_6D01ED
                lea     ecx, [esi+ebx]
                cmp     ecx, eax
                jbe     short loc_6D01ED
                push    ebx
                push    eax
                push    esi
                call    _memmove
                add     esp, 0Ch
                pop     edi
                pop     esi
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    8
; ---------------------------------------------------------------------------

loc_6D01ED:                             ; CODE XREF: sub_6D00E0+F0j
                                        ; sub_6D00E0+F7j
                push    ebx
                push    eax
                push    esi
                call    _memcpy
                add     esp, 0Ch

loc_6D01F8:                             ; CODE XREF: sub_6D00E0+23j
                                        ; sub_6D00E0+9Ej ...
                pop     edi
                pop     esi
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    8
sub_6D00E0      endp

aA_1:                                   ; DATA XREF: sub_6249D0+68o
                                        ; sub_6D0210+4Fo ...
                dw 80h, 0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0
                db    0

sub_6D0210      proc near               ; CODE XREF: SFileVerifyMpqHeaderMD5+42p
                                        ; sub_6D2D60+A9p ...

var_8           = byte ptr -8
var_6           = byte ptr -6
var_5           = byte ptr -5
var_4           = byte ptr -4
var_3           = byte ptr -3
var_2           = byte ptr -2
var_1           = byte ptr -1
arg_0           = dword ptr  8

                push    ebp
                mov     ebp, esp
                sub     esp, 8
                push    esi
                mov     esi, ecx        ; Source address
                mov     eax, [esi]
                mov     ecx, eax        
                shr     ecx, 8
                mov     [ebp-7], cl
                mov     ecx, eax
                shr     ecx, 18h
                mov     [ebp+var_5], cl
                mov     ecx, [esi+4]
                mov     edx, eax
                shr     edx, 10h
                mov     [ebp+var_6], dl
                mov     edx, ecx
                mov     [ebp+var_4], cl
                shr     edx, 8
                mov     [ebp+var_3], dl
                mov     edx, ecx
                shr     ecx, 18h
                mov     [ebp+var_1], cl
                mov     [ebp+var_8], al
                shr     eax, 3
                mov     ecx, 0FFFFFFF7h
                sub     ecx, eax
                and     ecx, 3Fh
                push    edi
                inc     ecx
                push    ecx
                shr     edx, 10h
                push    offset aA_1     ; ""
                mov     ecx, esi
                mov     [ebp+var_2], dl
                call    sub_6D00E0
                push    8
                lea     edx, [ebp+var_8]
                push    edx
                mov     ecx, esi
                call    sub_6D00E0
                mov     edi, [ebp+arg_0]
                xor     eax, eax

loc_6D0280:                             ; CODE XREF: sub_6D0210+8Ej
                mov     ecx, eax
                and     ecx, 3
                add     ecx, ecx
                mov     edx, eax
                sar     edx, 2
                mov     edx, [esi+edx*4+8]
                add     ecx, ecx
                add     ecx, ecx
                shr     edx, cl
                inc     eax
                cmp     eax, 10h
                mov     [eax+edi-1], dl
                jl      short loc_6D0280
                pop     edi
                pop     esi
                mov     esp, ebp
                pop     ebp
                retn    4
sub_6D0210      endp


sub_6CEBE0      proc near               ; CODE XREF: sub_4A72D0+49p
                                        ; SFileVerifyMpqHeaderMD5+51p ...

var_4           = dword ptr -4
arg_0           = dword ptr  8

                push    ebp
                mov     ebp, esp
                mov     edx, [ebp+arg_0]
                mov     eax, 10h
                push    esi
                lea     esp, [esp+0]

loc_6CEBF0:                             ; CODE XREF: sub_6CEBE0+22j
                mov     esi, [ecx]
                cmp     esi, [edx]
                jnz     short loc_6CEC14
                sub     eax, 4
                add     edx, 4
                add     ecx, 4
                cmp     eax, 4
                jnb     short loc_6CEBF0
                xor     eax, eax
                xor     edx, edx
                test    eax, eax
                setz    dl
                mov     al, dl
                pop     esi
                pop     ebp
                retn    4
; ---------------------------------------------------------------------------

loc_6CEC14:                             ; CODE XREF: sub_6CEBE0+14j
                movzx   eax, byte ptr [ecx]
                movzx   esi, byte ptr [edx]
                sub     eax, esi
                jnz     short loc_6CEC40
                movzx   eax, byte ptr [ecx+1]
                movzx   esi, byte ptr [edx+1]
                sub     eax, esi
                jnz     short loc_6CEC40
                movzx   eax, byte ptr [ecx+2]
                movzx   esi, byte ptr [edx+2]
                sub     eax, esi
                jnz     short loc_6CEC40
                movzx   eax, byte ptr [ecx+3]
                movzx   ecx, byte ptr [edx+3]
                sub     eax, ecx

loc_6CEC40:                             ; CODE XREF: sub_6CEBE0+3Cj
                                        ; sub_6CEBE0+48j ...
                sar     eax, 1Fh
                or      eax, 1
                xor     edx, edx
                test    eax, eax
                setz    dl
                mov     al, dl
                pop     esi
                pop     ebp
                retn    4
sub_6CEBE0      endp

SFileVerifyMpqHeaderMD5 proc near    ; CODE XREF: SFileVerifyMpqHeader+6Bp

var_68          = dword ptr -68h
var_64          = dword ptr -64h
var_60          = dword ptr -60h
var_5C          = dword ptr -5Ch
var_58          = dword ptr -58h
var_54          = dword ptr -54h
var_10          = dword ptr -10h

                push    ebp
                mov     ebp, esp
                sub     esp, 68h
                push    esi
                mov     esi, eax        ; ESI = pointer to MPQ Header
                xor     eax, eax
                push    0C0h
                push    esi
                lea     ecx, [ebp+var_68]
                mov     [ebp+var_64], eax
                mov     [ebp+var_68], eax
                mov     [ebp+var_60], 67452301h
                mov     [ebp+var_5C], 0EFCDAB89h
                mov     [ebp+var_58], 98BADCFEh
                mov     [ebp+var_54], 10325476h
                call    sub_6D00E0
                lea     eax, [ebp+var_10]
                push    eax
                lea     ecx, [ebp+var_68]
                call    sub_6D0210
                add     esi, 0C0h
                push    esi
                lea     ecx, [ebp+var_10]
                call    sub_6CEBE0
                pop     esi
                mov     esp, ebp
                pop     ebp
                retn
SFileVerifyMpqHeaderMD5 endp


_wow_SFileVerifyMpqHeaderMD5 proc
                push    ebp
                mov     ebp, esp
                mov     eax, [ebp+8]
                call    SFileVerifyMpqHeaderMD5
                mov     esp, ebp
                pop     ebp
                retn
_wow_SFileVerifyMpqHeaderMD5 endp

END
