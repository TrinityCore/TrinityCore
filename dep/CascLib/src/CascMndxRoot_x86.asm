.686P
.MODEL FLAT
ASSUME FS: NOTHING

; ---------------------------------------------------------------------------

TMndxFindResult struc ; (sizeof=0x1C) ; XREF: GAME_OBJECT_03F7E848::sub_E94500_r
szSearchMask    dd ?                    ; XREF: TMndxFindResult__SetPath+2D_w
                                        ; TMndxFindResult__Constructor+4_w ...
cchSearchMask   dd ?                    ; XREF: TMndxFindResult__SetPath:loc_1956E9A_w
                                        ; TMndxFindResult__Constructor+6_w ...
field_8         dd ?                    ; XREF: TMndxFindResult__Constructor+9_w
szFoundPath     dd ?                    ; XREF: TMndxFindResult__Constructor+C_w
                                        ; TFileNameDatabase__FindFileInDatabase+55_w
cchFoundPath    dd ?                    ; XREF: TMndxFindResult__Constructor+F_w
                                        ; TFileNameDatabase__FindFileInDatabase+5B_w
FileNameIndex   dd ?                    ; XREF: TMndxFindResult__Constructor+12_w
                                        ; TFileNameDatabase__FindFileInDatabase+6B_w
pStruct40       dd ?                    ; XREF: MAR_FILE__FindFileInDatabase+19_r
                                        ; TMndxFindResult__SetPath:loc_1956E8C_r ...
TMndxFindResult ends

; ---------------------------------------------------------------------------

TRIPLET         struc ; (sizeof=0xC)
BitIndex        dd ?                    ; XREF: TFileNameDatabase__CheckNextPathFragment+39_r
NextKey         dd ?                    ; XREF: TFileNameDatabase__CheckNextPathFragment+8C_r
                                        ; TSparseArray__GetItemValue:loc_1959B8F_r ...
Distance        dd ?                    ; XREF: TFileNameDatabase__CheckNextPathFragment+3E_r
                                        ; TSparseArray__GetItemValue:loc_1959BBE_r ...
TRIPLET         ends

; ---------------------------------------------------------------------------

NAME_ENTRY   struc ; (sizeof=0xC)
ExpectedHashModifier dd ?
NextHashModifier dd ?                   ; XREF: TArchiveDatabase__sub_1958B00+D3r
                                        ; sub_1958D70+2Cr
FragmentOffset  dd ?                    ; XREF: TArchiveDatabase__sub_1958B00+45r
                                        ; sub_1958D70+36r
NAME_ENTRY   ends

; ---------------------------------------------------------------------------

TStruct14       struc ; (sizeof=0x14)   ; XREF: TFileNameDatabase::sub_1959460r
HashValue       dd ?                    ; XREF: TGenericArray__InsertItem_STRUCT14+44r
                                        ; TGenericArray__InsertItem_STRUCT14+46w ...
field_4         dd ?                    ; XREF: TGenericArray__InsertItem_STRUCT14+48r
                                        ; TGenericArray__InsertItem_STRUCT14+4Bw ...
field_8         dd ?                    ; XREF: TGenericArray__InsertItem_STRUCT14+4Er
                                        ; TGenericArray__InsertItem_STRUCT14+51w ...
field_C         dd ?                    ; XREF: TGenericArray__InsertItem_STRUCT14+54r
                                        ; TGenericArray__InsertItem_STRUCT14+57w ...
field_10        dd ?                    ; XREF: TGenericArray__InsertItem_STRUCT14+5Ar
                                        ; TGenericArray__InsertItem_STRUCT14+5Dw ...
TStruct14       ends

; ---------------------------------------------------------------------------

TGenericArray   struc ; (sizeof=0x15)   ; XREF: TGenericArray::LoadDwordsArrayWithCopyr
                                        ; TFileNameDatabase::LoadBytesr ...
DataBuffer      dd ?                    ; XREF: TMndxFindResult__CreateStruct40+24w
                                        ; TMndxFindResult__CreateStruct40+35w ...
field_4         dd ?                    ; XREF: TMndxFindResult__CreateStruct40+26w
                                        ; TMndxFindResult__CreateStruct40+38w ...
ItemArray       dd ?                    ; XREF: TMndxFindResult__CreateStruct40+29w
                                        ; TMndxFindResult__CreateStruct40+3Bw ...
ItemCount       dd ?                    ; XREF: TMndxFindResult__CreateStruct40+2Cw
                                        ; TMndxFindResult__CreateStruct40+3Ew ...
MaxItemCount    dd ?                    ; XREF: TFileNameDatabasePtr__CreateDatabase+27o
                                        ; TMndxFindResult__CreateStruct40+2Fw ...
bIsValidArray   db ?                    ; XREF: LoadAndVerifyIndexFileHeader+31w
                                        ; TMndxFindResult__CreateStruct40+32w ...
TGenericArray   ends

; ---------------------------------------------------------------------------

TBitEntryArray  struc ; (sizeof=0x24)   ; XREF: TGenericArrayEx::LoadFromStream_Exchanger
                                        ; TFileNameDatabaser
DataBuffer      dd ?                    ; XREF: TArchiveDatabase__Destructor+64r
                                        ; TArchiveDatabase__Constructor+1A3w
field_4         dd ?                    ; XREF: TArchiveDatabase__Constructor+1A9w
ItemArray       dd ?                    ; XREF: sub_1957350+31r
                                        ; sub_19573D0+1Fr ...
ItemCount       dd ?                    ; XREF: TArchiveDatabase__Constructor+1B5w
MaxItemCount    dd ?                    ; XREF: TArchiveDatabase__Constructor+1BBw
bIsValidArray   db ?                    ; XREF: TArchiveDatabase__Constructor+1C1w
                db ? ; undefined
                db ? ; undefined
                db ? ; undefined
BitsPerEntry    dd ?                    ; XREF: sub_1957350+1Fr
                                        ; sub_19573D0+6r ...
EntryBitMask    dd ?                    ; XREF: sub_1957350:loc_19573B1r
                                        ; sub_19573D0:loc_1957419r ...
TotalEntries    dd ?                    ; XREF: TGenericArrayEx__LoadFromStream:loc_195861Bw
                                        ; TArchiveDatabase__Constructor+1D3w
TBitEntryArray  ends
                                        ; TFileNameDatabase__Constructor+1D3_w
; ---------------------------------------------------------------------------

TStruct40       struc ; (sizeof=0x40)
array_00        TGenericArray <>        ; XREF: TMndxFindResult__CreateStruct40+24w
                                        ; TMndxFindResult__CreateStruct40+26w ...
                db ? ; undefined
                db ? ; undefined
                db ? ; undefined
array_18        TGenericArray <>        ; XREF: TMndxFindResult__CreateStruct40+35w
                                        ; TMndxFindResult__CreateStruct40+38w ...
                db ? ; undefined
                db ? ; undefined
                db ? ; undefined
HashValue       dd ?                    ; XREF: TMndxFindResult__CreateStruct40+47w
                                        ; TFileNameDatabase__CheckNextPathFragment+1Ar ...
CharIndex       dd ?                    ; XREF: TMndxFindResult__CreateStruct40+4Aw
                                        ; TFileNameDatabase__CheckNextPathFragment+11r ...
ItemCount       dd ?                    ; XREF: TMndxFindResult__CreateStruct40+4Dw
                                        ; TStruct40__InitSearchBuffers+6Bw ...
SearchPhase     dd ?                    ; XREF: TMndxFindResult__CreateStruct40+50w
                                        ; TFileNameDatabase__FindFileInDatabase+17w ...
TStruct40       ends

; ---------------------------------------------------------------------------

TSparseArray    struc ; (sizeof=0x65)   ; XREF: TSparseArray::LoadFromStream_Exchange_r
                                        ; TNameIndexStruct_r ...
ItemIsPresent   TGenericArray <>        ; XREF: LoadAndVerifyIndexFileHeader+31_w
                                        ; TFileNameDatabase__Destructor+4C_r ...
                db ? ; undefined
                db ? ; undefined
                db ? ; undefined
TotalItemCount  dd ?                    ; XREF: TSparseArray__ExchangeWith+4D_r
                                        ; TSparseArray__ExchangeWith+56_w ...
ValidItemCount  dd ?                    ; XREF: TFileNameDatabasePtr__GetFileNameCount:loc_1956D32_r
                                        ; TSparseArray__ExchangeWith+59_r ...
ArrayTriplets_20 TGenericArray <>       ; XREF: TFileNameDatabase__Destructor+40_r
                                        ; TFileNameDatabase__Destructor+94_r ...
                db ? ; undefined
                db ? ; undefined
                db ? ; undefined
ArrayDwords_38  TGenericArray <>        ; XREF: TFileNameDatabasePtr__CreateDatabase+27_o
                                        ; TFileNameDatabase__Destructor+34_r ...
                db ? ; undefined
                db ? ; undefined
                db ? ; undefined
ArrayDwords_50  TGenericArray <>        ; XREF: TFileNameDatabase__Destructor+28_r
                                        ; TFileNameDatabase__Destructor+7C_r ...
TSparseArray    ends

; ---------------------------------------------------------------------------

TNameIndexStruct struc ; (sizeof=0x7D)  ; XREF: TNameIndexStruct::LoadFromStream_Exchange_r
                                        ; TFileNameDatabaser
NameFragments   TGenericArray <>        ; XREF: TFileNameDatabase__Destructor+58_r
                                        ; TFileNameDatabase__LoadFromStream+82_r ...
                db ? ; undefined
                db ? ; undefined
                db ? ; undefined
Struct68        TSparseArray <>         ; XREF: LoadAndVerifyIndexFileHeader+31_w
                                        ; TFileNameDatabase__Destructor+28_r ...
TNameIndexStruct ends

; ---------------------------------------------------------------------------

TByteStream     struc ; (sizeof=0x18)   ; XREF: TFileNameDatabasePtr::CreateDatabase_r
                                        ; TFileNameDatabase_r
pbData          dd ?                    ; XREF: TByteStream__Constructor+4_w
                                        ; TByteStream__IsMarDataValid+2_r ...
pvMappedFile    dd ?                    ; XREF: TByteStream__Constructor+6_w
                                        ; TByteStream__Destructor+3_r
cbData          dd ?                    ; XREF: TByteStream__Constructor+9_w
                                        ; TByteStream__GetBytes:loc_1959A05_r ...
field_C         dd ?                    ; XREF: TByteStream__Constructor+C_w
hFile           dd ?                    ; XREF: TByteStream__Constructor+F_w
                                        ; TByteStream__Destructor:loc_19599D2_r
hMap            dd ?                    ; XREF: TByteStream__Constructor+12_w
                                        ; TByteStream__Destructor:loc_19599C2_r
TByteStream     ends

; ---------------------------------------------------------------------------

TStruct10       struc ; (sizeof=0x10)   ; XREF: TStruct10::sub_1957800_r
                                        ; TFileNameDatabase_r
field_0         dd ?                    ; XREF: sub_19572E0+24_w
                                        ; TFileNameDatabase__Constructor+21A_w
field_4         dd ?                    ; XREF: sub_1956FD0+28_w
                                        ; sub_1956FD0:loc_1957001_w ...
field_8         dd ?                    ; XREF: sub_19572E0+4A_w
                                        ; sub_19572E0+5B_w ...
field_C         dd ?                    ; XREF: sub_1957050:loc_1957074_w
                                        ; sub_1957050:loc_1957081_w ...
TStruct10       ends

; ---------------------------------------------------------------------------

TFileNameDatabasePtr struc ; (sizeof=0x4) ; XREF: TFileNameDatabase_r
                                        ; MAR_FILE_r
pDatabase       dd ?                    ; XREF: MAR_FILE__Constructor+1D_w
                                        ; MAR_FILE__CreateDatabase+22_w ...
TFileNameDatabasePtr ends

; ---------------------------------------------------------------------------

TFileNameDatabase struc ; (sizeof=0x240) ; XREF: TFileNameDatabase::LoadFromStream_Exchange_r
Struct68_00     TSparseArray <>         ; XREF: TFileNameDatabasePtr__CreateDatabase+27_o
                                        ; TFileNameDatabase__Destructor+D9_r ...
                db ? ; undefined
                db ? ; undefined
                db ? ; undefined
FileNameIndexes TSparseArray <>         ; XREF: TFileNameDatabasePtr__GetFileNameCount:loc_1956D32_r
                                        ; TFileNameDatabase__Destructor+AC_r ...
                db ? ; undefined
                db ? ; undefined
                db ? ; undefined
Struct68_D0     TSparseArray <>         ; XREF: TFileNameDatabase__Destructor+7C_r
                                        ; TFileNameDatabase__Destructor+88_r ...
                db ? ; undefined
                db ? ; undefined
                db ? ; undefined
FrgmDist_LoBits TGenericArray <>        ; XREF: TFileNameDatabase__Destructor+70_r
                                        ; TFileNameDatabase__CheckNextPathFragment:loc_1957AC9_r ...
                db ? ; undefined
                db ? ; undefined
                db ? ; undefined
FrgmDist_HiBits TBitEntryArray <>       ; XREF: TFileNameDatabase__Destructor+64_r
                                        ; TFileNameDatabase__CheckNextPathFragment+119_r ...
IndexStruct_174 TNameIndexStruct <>     ; XREF: TFileNameDatabase__Destructor+28_r
                                        ; TFileNameDatabase__Destructor+34_r ...
                db ? ; undefined
                db ? ; undefined
                db ? ; undefined
NextDB          TFileNameDatabasePtr <> ; XREF: TFileNameDatabase__Destructor+1D_o
                                        ; TFileNameDatabase__CheckNextPathFragment+52_r ...
NameFragTable   TGenericArray <>        ; XREF: TFileNameDatabase__Destructor+E_r
                                        ; TFileNameDatabase__CheckNextPathFragment+2F_r ...
                db ? ; undefined
                db ? ; undefined
                db ? ; undefined
NameFragIndexMask dd ?                  ; XREF: TFileNameDatabase__CheckNextPathFragment+26_r
                                        ; sub_1957B80:loc_1957B95_r ...
field_214       dd ?                    ; XREF: TFileNameDatabase__Constructor+20E_w
                                        ; TFileNameDatabase__LoadFromStream+110_w
Struct10        TStruct10 <>            ; XREF: TFileNameDatabase__Constructor+21A_w
                                        ; TFileNameDatabase__Constructor+224_w ...
MarStream       TByteStream <>          ; XREF: TFileNameDatabase__Destructor+3_o
                                        ; TFileNameDatabase__Constructor+214_o
TFileNameDatabase ends

; ---------------------------------------------------------------------------

MAR_FILE        struc ; (sizeof=0xC)
pDatabasePtr    TFileNameDatabasePtr <>   ; XREF: MAR_FILE__Constructor+1D_w
                                        ; MAR_FILE__CreateDatabase+22_w ...
pbMarFileData   dd ?                    ; XREF: MAR_FILE__Constructor+1A_w
                                        ; MAR_FILE__CreateDatabase+1B_r ...
cbMarFileData   dd ?                    ; XREF: MAR_FILE__Constructor+12_w
                                        ; MAR_FILE__CreateDatabase+18_r ...
MAR_FILE        ends

.DATA
table_1BA1818   db 7, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0
                db 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 5, 0, 1, 0
                db 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0
                db 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 6, 0, 1, 0, 2, 0, 1, 0
                db 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0
                db 1, 0, 2, 0, 1, 0, 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0
                db 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0
                db 1, 0, 7, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0
                db 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 5, 0
                db 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0
                db 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 6, 0, 1, 0, 2, 0
                db 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0
                db 3, 0, 1, 0, 2, 0, 1, 0, 5, 0, 1, 0, 2, 0, 1, 0, 3, 0
                db 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0
                db 2, 0, 1, 0, 3 dup(7), 1, 7, 2 dup(2), 1, 7, 2 dup(3)
                db 1, 3, 2 dup(2), 1, 7, 2 dup(4), 1, 4, 2 dup(2), 1, 4
                db 2 dup(3), 1, 3, 2 dup(2), 1, 7, 2 dup(5), 1, 5, 2 dup(2)
                db 1, 5, 2 dup(3), 1, 3, 2 dup(2), 1, 5, 2 dup(4), 1, 4
                db 2 dup(2), 1, 4, 2 dup(3), 1, 3, 2 dup(2), 1, 7, 2 dup(6)
                db 1, 6, 2 dup(2), 1, 6, 2 dup(3), 1, 3, 2 dup(2), 1, 6
                db 2 dup(4), 1, 4, 2 dup(2), 1, 4, 2 dup(3), 1, 3, 2 dup(2)
                db 1, 6, 2 dup(5), 1, 5, 2 dup(2), 1, 5, 2 dup(3), 1, 3
                db 2 dup(2), 1, 5, 2 dup(4), 1, 4, 2 dup(2), 1, 4, 2 dup(3)
                db 1, 3, 2 dup(2), 1, 3 dup(7), 1, 7, 2 dup(2), 1, 7, 2 dup(3)
                db 1, 3, 2 dup(2), 1, 7, 2 dup(4), 1, 4, 2 dup(2), 1, 4
                db 2 dup(3), 1, 3, 2 dup(2), 1, 7, 2 dup(5), 1, 5, 2 dup(2)
                db 1, 5, 2 dup(3), 1, 3, 2 dup(2), 1, 5, 2 dup(4), 1, 4
                db 2 dup(2), 1, 4, 2 dup(3), 1, 3, 2 dup(2), 1, 7, 2 dup(6)
                db 1, 6, 2 dup(2), 1, 6, 2 dup(3), 1, 3, 2 dup(2), 1, 6
                db 2 dup(4), 1, 4, 2 dup(2), 1, 4, 2 dup(3), 1, 3, 2 dup(2)
                db 1, 6, 2 dup(5), 1, 5, 2 dup(2), 1, 5, 2 dup(3), 1, 3
                db 2 dup(2), 1, 5, 2 dup(4), 1, 4, 2 dup(2), 1, 4, 2 dup(3)
                db 1, 3, 2 dup(2), 1, 7 dup(7), 2, 3 dup(7), 3, 7, 2 dup(3)
                db 2, 3 dup(7), 4, 7, 2 dup(4), 2, 7, 2 dup(4), 3, 4, 2 dup(3)
                db 2, 3 dup(7), 5, 7, 2 dup(5), 2, 7, 2 dup(5), 3, 5, 2 dup(3)
                db 2, 7, 2 dup(5), 4, 5, 2 dup(4), 2, 5, 2 dup(4), 3, 4
                db 2 dup(3), 2, 3 dup(7), 6, 7, 2 dup(6), 2, 7, 2 dup(6)
                db 3, 6, 2 dup(3), 2, 7, 2 dup(6), 4, 6, 2 dup(4), 2, 6
                db 2 dup(4), 3, 4, 2 dup(3), 2, 7, 2 dup(6), 5, 6, 2 dup(5)
                db 2, 6, 2 dup(5), 3, 5, 2 dup(3), 2, 6, 2 dup(5), 4, 5
                db 2 dup(4), 2, 5, 2 dup(4), 3, 4, 2 dup(3), 2, 7 dup(7)
                db 2, 3 dup(7), 3, 7, 2 dup(3), 2, 3 dup(7), 4, 7, 2 dup(4)
                db 2, 7, 2 dup(4), 3, 4, 2 dup(3), 2, 3 dup(7), 5, 7, 2 dup(5)
                db 2, 7, 2 dup(5), 3, 5, 2 dup(3), 2, 7, 2 dup(5), 4, 5
                db 2 dup(4), 2, 5, 2 dup(4), 3, 4, 2 dup(3), 2, 3 dup(7)
                db 6, 7, 2 dup(6), 2, 7, 2 dup(6), 3, 6, 2 dup(3), 2, 7
                db 2 dup(6), 4, 6, 2 dup(4), 2, 6, 2 dup(4), 3, 4, 2 dup(3)
                db 2, 7, 2 dup(6), 5, 6, 2 dup(5), 2, 6, 2 dup(5), 3, 5
                db 2 dup(3), 2, 6, 2 dup(5), 4, 5, 2 dup(4), 2, 5, 2 dup(4)
                db 3, 4, 2 dup(3), 2, 0Fh dup(7), 3, 7 dup(7), 4, 3 dup(7)
                db 4, 7, 2 dup(4), 3, 7 dup(7), 5, 3 dup(7), 5, 7, 2 dup(5)
                db 3, 3 dup(7), 5, 7, 2 dup(5), 4, 7, 2 dup(5), 4, 5, 2 dup(4)
                db 3, 7 dup(7), 6, 3 dup(7), 6, 7, 2 dup(6), 3, 3 dup(7)
                db 6, 7, 2 dup(6), 4, 7, 2 dup(6), 4, 6, 2 dup(4), 3, 3 dup(7)
                db 6, 7, 2 dup(6), 5, 7, 2 dup(6), 5, 6, 2 dup(5), 3, 7
                db 2 dup(6), 5, 6, 2 dup(5), 4, 6, 2 dup(5), 4, 5, 2 dup(4)
                db 3, 0Fh dup(7), 3, 7 dup(7), 4, 3 dup(7), 4, 7, 2 dup(4)
                db 3, 7 dup(7), 5, 3 dup(7), 5, 7, 2 dup(5), 3, 3 dup(7)
                db 5, 7, 2 dup(5), 4, 7, 2 dup(5), 4, 5, 2 dup(4), 3, 7 dup(7)
                db 6, 3 dup(7), 6, 7, 2 dup(6), 3, 3 dup(7), 6, 7, 2 dup(6)
                db 4, 7, 2 dup(6), 4, 6, 2 dup(4), 3, 3 dup(7), 6, 7, 2 dup(6)
                db 5, 7, 2 dup(6), 5, 6, 2 dup(5), 3, 7, 2 dup(6), 5, 6
                db 2 dup(5), 4, 6, 2 dup(5), 4, 5, 2 dup(4), 3, 1Fh dup(7)
                db 4, 0Fh dup(7), 5, 7 dup(7), 5, 3 dup(7), 5, 7, 2 dup(5)
                db 4, 0Fh dup(7), 6, 7 dup(7), 6, 3 dup(7), 6, 7, 2 dup(6)
                db 4, 7 dup(7), 6, 3 dup(7), 6, 7, 2 dup(6), 5, 3 dup(7)
                db 6, 7, 2 dup(6), 5, 7, 2 dup(6), 5, 6, 2 dup(5), 4, 1Fh dup(7)
                db 4, 0Fh dup(7), 5, 7 dup(7), 5, 3 dup(7), 5, 7, 2 dup(5)
                db 4, 0Fh dup(7), 6, 7 dup(7), 6, 3 dup(7), 6, 7, 2 dup(6)
                db 4, 7 dup(7), 6, 3 dup(7), 6, 7, 2 dup(6), 5, 3 dup(7)
                db 6, 7, 2 dup(6), 5, 7, 2 dup(6), 5, 6, 2 dup(5), 4, 3Fh dup(7)
                db 5, 1Fh dup(7), 6, 0Fh dup(7), 6, 7 dup(7), 6, 3 dup(7)
                db 6, 7, 2 dup(6), 5, 3Fh dup(7), 5, 1Fh dup(7), 6, 0Fh dup(7)
                db 6, 7 dup(7), 6, 3 dup(7), 6, 7, 2 dup(6), 5, 7Fh dup(7)
                db 6, 7Fh dup(7), 6, 100h dup(7)

unk_53ABE00     db 0

.CODE

;
; void * operator_new_safe(size_t ByteCount, void * unk_53ABE00);
;

EXTERN _allocate_zeroed_memory_x86:PROC
EXTERN _free_memory_x86:PROC

j_operator_new_safe PROC
                push    ebp
                mov     ebp, esp
                push    [ebp+08]
                call    _allocate_zeroed_memory_x86
                add     esp, 4
                mov     esp, ebp
                pop     ebp
                ret
j_operator_new_safe ENDP

operator_delete PROC
                push    ebp
                mov     ebp, esp
                push    [ebp+08]
                call    _free_memory_x86
                add     esp, 4
                mov     esp, ebp
                pop     ebp
                ret
operator_delete ENDP


TSparseArray__GetItemValue     proc near               ; CODE XREF: sub_1957350+1A_p
                                        ; TFileNameDatabase__CheckNextPathFragment+103_p ...

arg_0           = dword ptr  8

                push    ebp
                mov     ebp, esp
                mov     edx, [ecx+28h]
                push    ebx
                push    esi
                push    edi
                mov     edi, [ebp+arg_0]
                mov     eax, edi
                shr     eax, 9
                lea     eax, [eax+eax*2]
                mov     esi, [edx+eax*4]
                lea     eax, [edx+eax*4]
                mov     edx, edi
                shr     edx, 6
                and     edx, 7
                dec     edx
                cmp     edx, 6          ; switch 7 cases
                ja      short loc_1959BE0 ; jumptable 01959B88 default case
                jmp     ds:off_1959C90[edx*4] ; switch jump

loc_1959B8F:                            ; DATA XREF: .text:off_1959C90o
                mov     eax, [eax+4] ; jumptable 01959B88 case 0
                and     eax, 7Fh
                jmp     short loc_1959BDE
; ---------------------------------------------------------------------------

loc_1959B97:                            ; CODE XREF: TSparseArray__GetItemValue+28_j
                                        ; DATA XREF: .text:off_1959C90o
                mov     edx, [eax+4] ; jumptable 01959B88 case 1
                shr     edx, 7
                and     edx, 0FFh
                add     esi, edx
                jmp     short loc_1959BE0 ; jumptable 01959B88 default case
; ---------------------------------------------------------------------------

loc_1959BA7:                            ; CODE XREF: TSparseArray__GetItemValue+28_j
                                        ; DATA XREF: .text:off_1959C90o
                mov     eax, [eax+4] ; jumptable 01959B88 case 2
                shr     eax, 0Fh
                and     eax, 0FFh
                jmp     short loc_1959BDE
; ---------------------------------------------------------------------------

loc_1959BB4:                            ; CODE XREF: TSparseArray__GetItemValue+28_j
                                        ; DATA XREF: .text:off_1959C90o
                mov     edx, [eax+4] ; jumptable 01959B88 case 3
                shr     edx, 17h
                add     esi, edx
                jmp     short loc_1959BE0 ; jumptable 01959B88 default case
; ---------------------------------------------------------------------------

loc_1959BBE:                            ; CODE XREF: TSparseArray__GetItemValue+28_j
                                        ; DATA XREF: .text:off_1959C90o
                mov     eax, [eax+8]    ; jumptable 01959B88 case 4
                jmp     short loc_1959BD9
; ---------------------------------------------------------------------------

loc_1959BC3:                            ; CODE XREF: TSparseArray__GetItemValue+28_j
                                        ; DATA XREF: .text:off_1959C90o
                mov     edx, [eax+8]    ; jumptable 01959B88 case 5
                shr     edx, 9
                and     edx, 1FFh
                add     esi, edx
                jmp     short loc_1959BE0 ; jumptable 01959B88 default case
; ---------------------------------------------------------------------------

loc_1959BD3:                            ; CODE XREF: TSparseArray__GetItemValue+28_j
                                        ; DATA XREF: .text:off_1959C90o
                mov     eax, [eax+8]    ; jumptable 01959B88 case 6
                shr     eax, 12h

loc_1959BD9:                            ; CODE XREF: TSparseArray__GetItemValue+61_j
                and     eax, 1FFh

loc_1959BDE:                            ; CODE XREF: TSparseArray__GetItemValue+35_j
                                        ; TSparseArray__GetItemValue+52_j
                add     esi, eax

loc_1959BE0:                            ; CODE XREF: TSparseArray__GetItemValue+26_j
                                        ; TSparseArray__GetItemValue+45_j ...
                mov     ebx, edi        ; jumptable 01959B88 default case
                shr     ebx, 5
                test    bl, 1
                jz      short loc_1959C31
                mov     edx, [ecx+8]
                mov     edx, [edx+ebx*4-4]
                mov     eax, edx
                shr     eax, 1
                and     eax, 55555555h
                and     edx, 55555555h
                add     eax, edx
                mov     edx, eax
                and     eax, 33333333h
                shr     edx, 2
                and     edx, 33333333h
                add     edx, eax
                mov     eax, edx
                shr     eax, 4
                and     eax, 0F0F0F0Fh
                and     edx, 0F0F0F0Fh
                add     eax, edx
                imul    eax, 1010101h
                shr     eax, 18h
                add     esi, eax

loc_1959C31:                            ; CODE XREF: TSparseArray__GetItemValue+88_j
                mov     edx, [ecx+8]
                mov     ecx, edi
                and     ecx, 1Fh
                mov     eax, 1
                shl     eax, cl
                mov     ecx, [edx+ebx*4]
                pop     edi
                dec     eax
                and     ecx, eax
                mov     eax, ecx
                shr     eax, 1
                and     eax, 55555555h
                and     ecx, 55555555h
                add     eax, ecx
                mov     ecx, eax
                and     eax, 33333333h
                shr     ecx, 2
                and     ecx, 33333333h
                add     ecx, eax
                mov     eax, ecx
                shr     eax, 4
                and     eax, 0F0F0F0Fh
                and     ecx, 0F0F0F0Fh
                add     eax, ecx
                imul    eax, 1010101h
                shr     eax, 18h
                add     eax, esi
                pop     esi
                pop     ebx
                pop     ebp
                retn    4

off_1959C90     dd offset loc_1959B8F   ; DATA XREF: TSparseArray__GetItemValue+28_r
                dd offset loc_1959B97   ; jump table for switch statement
                dd offset loc_1959BA7
                dd offset loc_1959BB4
                dd offset loc_1959BBE
                dd offset loc_1959BC3
                dd offset loc_1959BD3

TSparseArray__GetItemValue     endp

;------------------------------------------------------------------------------
; TArchiveDatabase__sub_1959CB0

TArchiveDatabase__sub_1959CB0 proc near
                                        ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+A1_p
                                        ; sub_1958B00+E8_p ...

pThis           = dword ptr -4
dwKey           = dword ptr  8

                push    ebp
                mov     ebp, esp
                push    ecx
                mov     edx, [ebp+dwKey]
                mov     eax, edx
                shr     eax, 9
                mov     [ebp+pThis], ecx
                test    edx, 1FFh       ; if(dwKey & 0x01FF)
                jnz     short loc_1959CD3
                mov     ecx, [ecx+40h]
                mov     eax, [ecx+eax*4] ; EAX = pDatabase->NextKeyTable[dwKey >> 0x09]
                mov     esp, ebp
                pop     ebp
                retn    4
; ---------------------------------------------------------------------------

loc_1959CD3:                            ; CODE XREF: TFileNameDatabase__FindNextMatch+15_j
                push    ebx
                push    esi
                mov     esi, [ecx+40h]
                lea     esi, [esi+eax*4]
                mov     eax, [esi]
                mov     esi, [esi+4]
                shr     eax, 9
                add     esi, 1FFh
                push    edi
                shr     esi, 9
                lea     edi, [eax+0Ah]
                mov     [ebp+dwKey], esi
                cmp     edi, esi
                jb      short loc_1959D2E
                mov     edi, [ecx+28h]
                lea     esi, [eax+eax*2+3]
                lea     esi, [edi+esi*4]
                mov     edi, eax
                shl     edi, 9
                mov     ebx, edi
                sub     ebx, [esi]
                add     ebx, 200h
                cmp     edx, ebx
                jb      short loc_1959D5F

loc_1959D14:                            ; CODE XREF: TFileNameDatabase__FindNextMatch+7Aj
                add     edi, 200h
                add     esi, 0Ch
                mov     ebx, edi
                sub     ebx, [esi]
                inc     eax
                add     ebx, 200h
                cmp     edx, ebx
                jnb     short loc_1959D14
                jmp     short loc_1959D5F
; ---------------------------------------------------------------------------

loc_1959D2E:                            ; CODE XREF: TFileNameDatabase__FindNextMatch+45_j
                lea     edi, [eax+1]
                cmp     edi, esi
                jnb     short loc_1959D5F
                mov     ecx, [ecx+28h]

loc_1959D38:                            ; CODE XREF: TFileNameDatabase__FindNextMatch+AAj
                add     esi, eax
                shr     esi, 1
                mov     ebx, esi
                shl     ebx, 9
                lea     edi, [esi+esi*2]
                sub     ebx, [ecx+edi*4]
                cmp     edx, ebx
                jnb     short loc_1959D50
                mov     [ebp+dwKey], esi
                jmp     short loc_1959D55
; ---------------------------------------------------------------------------

loc_1959D50:                            ; CODE XREF: TFileNameDatabase__FindNextMatch+99_j
                mov     eax, esi
                mov     esi, [ebp+dwKey]

loc_1959D55:                            ; CODE XREF: TFileNameDatabase__FindNextMatch+9E_j
                lea     edi, [eax+1]
                cmp     edi, esi
                jb      short loc_1959D38
                mov     ecx, [ebp+pThis]

loc_1959D5F:                            ; CODE XREF: TFileNameDatabase__FindNextMatch+62_j
                                        ; TFileNameDatabase__FindNextMatch+7C_j ...
                mov     ecx, [ecx+28h]
                lea     esi, [eax+eax*2]
                mov     edi, [ecx+esi*4] ; EDI = Struct68_00.ArrayTriplets_20.ItemArray[eax]
                lea     esi, [ecx+esi*4] ; ESI = Struct68_00.ArrayTriplets_20.ItemArray + eax
                mov     ecx, eax
                shl     ecx, 9
                sub     edi, ecx
                shl     eax, 4
                add     edx, edi
                mov     edi, eax
                mov     eax, [esi+4]
                mov     ecx, eax
                shr     ecx, 17h
                mov     ebx, 100h
                sub     ebx, ecx
                cmp     edx, ebx
                jnb     short loc_1959DE8
                mov     ecx, eax
                shr     ecx, 7
                and     ecx, 0FFh
                mov     esi, 80h
                sub     esi, ecx
                cmp     edx, esi
                jnb     short loc_1959DC0
                and     eax, 7Fh
                mov     ecx, 40h
                sub     ecx, eax
                cmp     edx, ecx
                jb      loc_1959E53
                add     edi, 2
                lea     edx, [edx+eax-40h]
                jmp     loc_1959E53
; ---------------------------------------------------------------------------

loc_1959DC0:                            ; CODE XREF: TFileNameDatabase__FindNextMatch+F0_j
                shr     eax, 0Fh
                and     eax, 0FFh
                mov     esi, 0C0h
                sub     esi, eax
                cmp     edx, esi
                jnb     short loc_1959DDC
                add     edi, 4
                lea     edx, [edx+ecx-80h]
                jmp     short loc_1959E53
; ---------------------------------------------------------------------------

loc_1959DDC:                            ; CODE XREF: TFileNameDatabase__FindNextMatch+121_j
                add     edi, 6
                lea     edx, [edx+eax-0C0h]
                jmp     short loc_1959E53
; ---------------------------------------------------------------------------

loc_1959DE8:                            ; CODE XREF: TFileNameDatabase__FindNextMatch+DA_j
                mov     esi, [esi+8]
                mov     eax, esi
                shr     eax, 9
                and     eax, 1FFh
                mov     ebx, 180h
                sub     ebx, eax
                cmp     edx, ebx
                jnb     short loc_1959E29
                and     esi, 1FFh
                mov     eax, 140h
                sub     eax, esi
                cmp     edx, eax
                jnb     short loc_1959E1D
                add     edi, 8
                lea     edx, [edx+ecx-100h]
                jmp     short loc_1959E53
; ---------------------------------------------------------------------------

loc_1959E1D:                            ; CODE XREF: TFileNameDatabase__FindNextMatch+15F_j
                add     edi, 0Ah
                lea     edx, [edx+esi-140h]
                jmp     short loc_1959E53
; ---------------------------------------------------------------------------

loc_1959E29:                            ; CODE XREF: TFileNameDatabase__FindNextMatch+14E_j
                shr     esi, 12h
                and     esi, 1FFh
                mov     ecx, 1C0h
                sub     ecx, esi
                cmp     edx, ecx
                jnb     short loc_1959E49
                add     edi, 0Ch
                lea     edx, [edx+eax-180h]
                jmp     short loc_1959E53
; ---------------------------------------------------------------------------

loc_1959E49:                            ; CODE XREF: TFileNameDatabase__FindNextMatch+18B_j
                add     edi, 0Eh
                lea     edx, [edx+esi-1C0h]

loc_1959E53:                            ; CODE XREF: TFileNameDatabase__FindNextMatch+FE_j
                                        ; TFileNameDatabase__FindNextMatch+10B_j ...
                mov     eax, [ebp+pThis]
                mov     ebx, [eax+8]
                mov     ecx, [ebx+edi*4]
                not     ecx
                mov     eax, ecx
                shr     eax, 1
                and     eax, 55555555h
                mov     esi, ecx
                and     esi, 55555555h
                add     eax, esi
                mov     esi, eax
                shr     esi, 2
                and     eax, 33333333h
                and     esi, 33333333h
                add     esi, eax
                mov     eax, esi
                shr     eax, 4
                and     esi, 0F0F0F0Fh
                and     eax, 0F0F0F0Fh
                add     eax, esi
                imul    eax, 1010101h
                mov     esi, eax
                shr     esi, 18h
                cmp     edx, esi
                jb      short loc_1959EEA
                mov     ecx, [ebx+edi*4+4]
                inc     edi
                sub     edx, esi
                not     ecx
                mov     eax, ecx
                shr     eax, 1
                and     eax, 55555555h
                mov     esi, ecx
                and     esi, 55555555h
                add     eax, esi
                mov     esi, eax
                shr     esi, 2
                and     eax, 33333333h
                and     esi, 33333333h
                add     esi, eax
                mov     eax, esi
                shr     eax, 4
                and     eax, 0F0F0F0Fh
                and     esi, 0F0F0F0Fh
                add     eax, esi
                imul    eax, 1010101h

loc_1959EEA:                            ; CODE XREF: TFileNameDatabase__FindNextMatch+1F2_j
                mov     esi, eax
                shr     esi, 8
                and     esi, 0FFh
                shl     edi, 5
                cmp     edx, esi
                jnb     short loc_1959F0D
                and     eax, 0FFh
                cmp     edx, eax
                jb      short loc_1959F2B
                add     edi, 8
                shr     ecx, 8
                jmp     short loc_1959F29
; ---------------------------------------------------------------------------

loc_1959F0D:                            ; CODE XREF: TFileNameDatabase__FindNextMatch+24A_j
                shr     eax, 10h
                and     eax, 0FFh
                cmp     edx, eax
                jnb     short loc_1959F23
                add     edi, 10h
                shr     ecx, 10h
                sub     edx, esi
                jmp     short loc_1959F2B
; ---------------------------------------------------------------------------

loc_1959F23:                            ; CODE XREF: TFileNameDatabase__FindNextMatch+267_j
                add     edi, 18h
                shr     ecx, 18h

loc_1959F29:                            ; CODE XREF: TFileNameDatabase__FindNextMatch+25B_j
                sub     edx, eax

loc_1959F2B:                            ; CODE XREF: TFileNameDatabase__FindNextMatch+253_j
                                        ; TFileNameDatabase__FindNextMatch+271_j
                and     ecx, 0FFh
                shl     edx, 8
                movzx   eax, byte ptr ds:table_1BA1818[ecx+edx]
                add     eax, edi
                pop     edi
                pop     esi
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    4
TArchiveDatabase__sub_1959CB0 endp

; =============== S U B R O U T I N E =======================================

; Attributes: bp-based frame

TNameIndexStruct__CheckNameFragment     proc near               ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+6B_p
                                        ; TFileNameDatabase__CheckNextPathFragment+191_p ...

pThis           = dword ptr -4
pUnknownStruct1C= dword ptr  8
dwDistance      = dword ptr  0Ch

                push    ebp
                mov     ebp, esp
                push    ecx
                push    ebx
                push    esi
                push    edi
                mov     edi, ecx
                cmp     [edi+TNameIndexStruct.Struct68.TotalItemCount], 0
                mov     ecx, [ebp+pUnknownStruct1C]
                mov     edx, [ecx+TMndxFindResult.pStruct40]
                mov     [ebp+pThis], edi
                jnz     short loc_195A1C8
                mov     edi, [edi+TNameIndexStruct.NameFragments.ItemArray] ; Pointer to name table
                sub     edi, [edx+TStruct40.CharIndex]
                add     edi, [ebp+dwDistance] ; EDI = szPathFragment

loc_195A1A1:                            ; CODE XREF: TNameIndexStruct__CheckNameFragment+3Bj
                mov     eax, [edx+TStruct40.CharIndex]
                mov     esi, [ecx+TMndxFindResult.szSearchMask]
                mov     bl, [eax+edi]
                cmp     bl, [eax+esi]
                jnz     short loc_195A1BD
                inc     eax
                mov     [edx+TStruct40.CharIndex], eax
                cmp     byte ptr [eax+edi], 0
                jz      short loc_195A215
                cmp     eax, [ecx+TMndxFindResult.cchSearchMask]
                jb      short loc_195A1A1

loc_195A1BD:                            ; CODE XREF: TNameIndexStruct__CheckNameFragment+2C_j
                                        ; TNameIndexStruct__CheckNameFragment+5Ej ...
                pop     edi
                pop     esi
                xor     al, al
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    8
; ---------------------------------------------------------------------------

loc_195A1C8:                            ; CODE XREF: TNameIndexStruct__CheckNameFragment+16_j
                mov     eax, [ebp+dwDistance]
                jmp     short loc_195A1D0
; ---------------------------------------------------------------------------
                align 10h

loc_195A1D0:                            ; CODE XREF: TNameIndexStruct__CheckNameFragment+4B_j
                                        ; TNameIndexStruct__CheckNameFragment+93j
                mov     ebx, [edi+TNameIndexStruct.NameFragments.ItemArray]
                mov     esi, [edx+TStruct40.CharIndex]
                mov     ecx, [ecx+TMndxFindResult.szSearchMask]
                mov     bl, [eax+ebx]   ; pNameList[dwNameOffset] == szPathName[nCharIndex]
                cmp     bl, [esi+ecx]
                jnz     short loc_195A1BD
                lea     ecx, [esi+1]
                mov     [edx+TStruct40.CharIndex], ecx
                mov     edi, [edi+TNameIndexStruct.Struct68.ItemIsPresent.ItemArray]
                mov     [ebp+dwDistance], ecx
                mov     ecx, eax
                and     ecx, 1Fh        ; ecx = (dwNameOffset & 0x1F)
                mov     esi, eax
                mov     ebx, 1
                shl     ebx, cl         ; ebx = 1 << (dwNameOffset & 0x1F);
                shr     esi, 5          ; esi = (dwNameOffset >> 0x05)
                mov     ecx, [edi+esi*4]
                inc     eax
                and     ecx, ebx
                jnz     short loc_195A215
                mov     esi, [ebp+dwDistance]
                mov     ecx, [ebp+pUnknownStruct1C]
                cmp     esi, [ecx+4]
                jnb     short loc_195A1BD
                mov     edi, [ebp+pThis]
                jmp     short loc_195A1D0
; ---------------------------------------------------------------------------

loc_195A215:                            ; CODE XREF: TNameIndexStruct__CheckNameFragment+36_j
                                        ; TNameIndexStruct__CheckNameFragment+83_j
                pop     edi
                pop     esi
                mov     al, 1
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    8
TNameIndexStruct__CheckNameFragment     endp

; =============== S U B R O U T I N E =======================================

; Attributes: bp-based frame

sub_1957350     proc near               ; CODE XREF: sub_1957B80+D8p
                                        ; sub_1957B80:loc_1957C73p ...

arg_0           = dword ptr  8

                push    ebp
                mov     ebp, esp
                mov     eax, [ebp+arg_0]
                push    ebx
                push    esi
                mov     esi, ecx
                mov     ebx, [esi+140h]
                push    edi
                push    eax
                lea     ecx, [esi+0D0h]
                add     ebx, eax
                call    TSparseArray__GetItemValue
                mov     edi, [esi+168h]
                mov     ecx, edi
                imul    ecx, eax
                mov     eax, ecx
                and     ecx, 1Fh
                mov     edx, ecx
                mov     ecx, [esi+158h]
                add     edi, edx
                shr     eax, 5
                cmp     edi, 20h
                ja      short loc_195739A
                mov     eax, [ecx+eax*4]
                mov     ecx, edx
                shr     eax, cl
                jmp     short loc_19573B1
; ---------------------------------------------------------------------------

loc_195739A:                            ; CODE XREF: sub_1957350+3F_j
                lea     edi, [ecx+eax*4]
                mov     eax, [edi+4]
                mov     edi, [edi]
                mov     ecx, 20h
                sub     ecx, edx
                shl     eax, cl
                mov     ecx, edx
                shr     edi, cl
                or      eax, edi

loc_19573B1:                            ; CODE XREF: sub_1957350+48_j
                and     eax, [esi+16Ch]
                movzx   edx, byte ptr [ebx]
                pop     edi
                shl     eax, 8
                pop     esi
                or      eax, edx
                pop     ebx
                pop     ebp
                retn    4
sub_1957350     endp

; ---------------------------------------------------------------------------


; =============== S U B R O U T I N E =======================================

; Attributes: bp-based frame

sub_1959F50     proc near               ; CODE XREF: sub_1957B80+14C_p
                                        ; sub_1958980+62_p ...

var_4           = dword ptr -4
arg_0           = dword ptr  8

                push    ebp
                mov     ebp, esp
                push    ecx
                mov     edx, [ebp+arg_0]
                mov     eax, edx
                shr     eax, 9
                mov     [ebp+var_4], ecx
                test    edx, 1FFh
                jnz     short loc_1959F73
                mov     ecx, [ecx+58h]
                mov     eax, [ecx+eax*4]
                mov     esp, ebp
                pop     ebp
                retn    4
; ---------------------------------------------------------------------------

loc_1959F73:                            ; CODE XREF: sub_1959F50+15_j
                push    ebx
                push    esi
                mov     esi, [ecx+58h]
                lea     esi, [esi+eax*4]
                mov     eax, [esi]
                push    edi
                mov     edi, [esi+4]
                shr     eax, 9
                add     edi, 1FFh
                shr     edi, 9
                lea     esi, [eax+0Ah]
                cmp     esi, edi
                jb      short loc_1959FAD
                mov     edi, [ecx+28h]
                lea     esi, [eax+eax*2+3]
                cmp     edx, [edi+esi*4]
                lea     esi, [edi+esi*4]
                jb      short loc_1959FD4

loc_1959FA3:                            ; CODE XREF: sub_1959F50+59j
                add     esi, 0Ch
                inc     eax
                cmp     edx, [esi]
                jnb     short loc_1959FA3
                jmp     short loc_1959FD4
; ---------------------------------------------------------------------------

loc_1959FAD:                            ; CODE XREF: sub_1959F50+42_j
                lea     esi, [eax+1]
                cmp     esi, edi
                jnb     short loc_1959FD4
                mov     ecx, [ecx+28h]

loc_1959FB7:                            ; CODE XREF: sub_1959F50+7Fj
                lea     esi, [edi+eax]
                shr     esi, 1
                lea     ebx, [esi+esi*2]
                cmp     edx, [ecx+ebx*4]
                jnb     short loc_1959FC8
                mov     edi, esi
                jmp     short loc_1959FCA
; ---------------------------------------------------------------------------

loc_1959FC8:                            ; CODE XREF: sub_1959F50+72_j
                mov     eax, esi

loc_1959FCA:                            ; CODE XREF: sub_1959F50+76_j
                lea     esi, [eax+1]
                cmp     esi, edi
                jb      short loc_1959FB7
                mov     ecx, [ebp+var_4]

loc_1959FD4:                            ; CODE XREF: sub_1959F50+51_j
                                        ; sub_1959F50+5B_j ...
                mov     edi, [ecx+28h]
                lea     esi, [eax+eax*2]
                sub     edx, [edi+esi*4]
                shl     eax, 4
                lea     esi, [edi+esi*4]
                mov     edi, eax
                mov     eax, [esi+4]
                mov     ebx, eax
                shr     ebx, 17h
                cmp     edx, ebx
                jnb     short loc_195A026
                mov     esi, eax
                shr     esi, 7
                and     esi, 0FFh
                cmp     edx, esi
                jnb     short loc_195A00E
                and     eax, 7Fh
                cmp     edx, eax
                jb      short loc_195A066
                add     edi, 2
                sub     edx, eax
                jmp     short loc_195A066
; ---------------------------------------------------------------------------

loc_195A00E:                            ; CODE XREF: sub_1959F50+AE_j
                shr     eax, 0Fh
                and     eax, 0FFh
                cmp     edx, eax
                jnb     short loc_195A01F
                add     edi, 4
                jmp     short loc_195A064
; ---------------------------------------------------------------------------

loc_195A01F:                            ; CODE XREF: sub_1959F50+C8_j
                add     edi, 6
                sub     edx, eax
                jmp     short loc_195A066
; ---------------------------------------------------------------------------

loc_195A026:                            ; CODE XREF: sub_1959F50+9F_j
                mov     esi, [esi+8]
                mov     eax, esi
                shr     eax, 9
                and     eax, 1FFh
                cmp     edx, eax
                jnb     short loc_195A04D
                and     esi, 1FFh
                cmp     edx, esi
                jnb     short loc_195A048
                add     edi, 8
                sub     edx, ebx
                jmp     short loc_195A066
; ---------------------------------------------------------------------------

loc_195A048:                            ; CODE XREF: sub_1959F50+EF_j
                add     edi, 0Ah
                jmp     short loc_195A064
; ---------------------------------------------------------------------------

loc_195A04D:                            ; CODE XREF: sub_1959F50+E5_j
                shr     esi, 12h
                and     esi, 1FFh
                cmp     edx, esi
                jnb     short loc_195A061
                add     edi, 0Ch
                sub     edx, eax
                jmp     short loc_195A066
; ---------------------------------------------------------------------------

loc_195A061:                            ; CODE XREF: sub_1959F50+108_j
                add     edi, 0Eh

loc_195A064:                            ; CODE XREF: sub_1959F50+CD_j
                                        ; sub_1959F50+FB_j
                sub     edx, esi

loc_195A066:                            ; CODE XREF: sub_1959F50+B5_j
                                        ; sub_1959F50+BC_j ...
                mov     ebx, [ecx+8]
                mov     esi, [ebx+edi*4]
                mov     eax, esi
                shr     eax, 1
                and     eax, 55555555h
                mov     ecx, esi
                and     ecx, 55555555h
                add     eax, ecx
                mov     ecx, eax
                shr     ecx, 2
                and     eax, 33333333h
                and     ecx, 33333333h
                add     ecx, eax
                mov     eax, ecx
                shr     eax, 4
                and     ecx, 0F0F0F0Fh
                and     eax, 0F0F0F0Fh
                add     eax, ecx
                imul    eax, 1010101h
                mov     ecx, eax
                shr     ecx, 18h
                cmp     edx, ecx
                jb      short loc_195A0F6
                mov     esi, [ebx+edi*4+4]
                sub     edx, ecx
                inc     edi
                mov     eax, esi
                shr     eax, 1
                and     eax, 55555555h
                mov     ecx, esi
                and     ecx, 55555555h
                add     eax, ecx
                mov     ecx, eax
                shr     ecx, 2
                and     eax, 33333333h
                and     ecx, 33333333h
                add     ecx, eax
                mov     eax, ecx
                shr     eax, 4
                and     eax, 0F0F0F0Fh
                and     ecx, 0F0F0F0Fh
                add     eax, ecx
                imul    eax, 1010101h

loc_195A0F6:                            ; CODE XREF: sub_1959F50+160_j
                mov     ecx, eax
                shr     ecx, 8
                and     ecx, 0FFh
                shl     edi, 5
                cmp     edx, ecx
                jnb     short loc_195A119
                and     eax, 0FFh
                cmp     edx, eax
                jb      short loc_195A137
                add     edi, 8
                shr     esi, 8
                jmp     short loc_195A135
; ---------------------------------------------------------------------------

loc_195A119:                            ; CODE XREF: sub_1959F50+1B6_j
                shr     eax, 10h
                and     eax, 0FFh
                cmp     edx, eax
                jnb     short loc_195A12F
                add     edi, 10h
                shr     esi, 10h
                sub     edx, ecx
                jmp     short loc_195A137
; ---------------------------------------------------------------------------

loc_195A12F:                            ; CODE XREF: sub_1959F50+1D3_j
                add     edi, 18h
                shr     esi, 18h

loc_195A135:                            ; CODE XREF: sub_1959F50+1C7_j
                sub     edx, eax

loc_195A137:                            ; CODE XREF: sub_1959F50+1BF_j
                                        ; sub_1959F50+1DD_j
                and     esi, 0FFh
                shl     edx, 8
                movzx   eax, ds:table_1BA1818[esi+edx]
                add     eax, edi
                pop     edi
                pop     esi
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    4
sub_1959F50     endp

; ---------------------------------------------------------------------------

; =============== S U B R O U T I N E =======================================

; Attributes: bp-based frame

sub_1957B80     proc near               ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+5E_p
                                        ; TFileNameDatabase__CheckNextPathFragment+180_p ...

pStruct40       = dword ptr -4
arg_0           = dword ptr  8
arg_4           = dword ptr  0Ch

                push    ebp
                mov     ebp, esp
                push    ecx
                push    ebx
                mov     ebx, [ebp+arg_0]
                mov     eax, [ebx+18h]
                push    esi
                push    edi
                mov     edi, [ebp+arg_4]
                mov     esi, ecx
                mov     [ebp+pStruct40], eax

loc_1957B95:                            ; CODE XREF: sub_1957B80+9Fj
                                        ; sub_1957B80+156j
                mov     eax, [esi+TFileNameDatabase.NameFragIndexMask]
                and     eax, edi
                lea     ecx, [eax+eax*2]
                mov     eax, [esi+TFileNameDatabase.NameFragTable.ItemArray]
                add     ecx, ecx
                add     ecx, ecx
                add     eax, ecx
                mov     [ebp+arg_4], ecx
                cmp     edi, [eax+4]
                jnz     short loc_1957C30
                mov     edx, [eax+8]
                mov     edi, edx
                and     edi, 0FFFFFF00h
                cmp     edi, 0FFFFFF00h
                jz      short loc_1957BEE
                mov     ecx, [esi+TFileNameDatabase.NextDB.pDatabase]
                push    edx
                push    ebx
                test    ecx, ecx
                jz      short loc_1957BDA
                call    sub_1957B80
                jmp     short loc_1957BE5
; ---------------------------------------------------------------------------

loc_1957BDA:                            ; CODE XREF: sub_1957B80+51_j
                lea     ecx, [esi+TFileNameDatabase.IndexStruct_174]
                call    TNameIndexStruct__CheckNameFragment

loc_1957BE5:                            ; CODE XREF: sub_1957B80+58_j
                test    al, al
                jz      short loc_1957C25
                mov     ecx, [ebp+arg_4]
                jmp     short loc_1957C05
; ---------------------------------------------------------------------------

loc_1957BEE:                            ; CODE XREF: sub_1957B80+45_j
                mov     edx, [ebp+pStruct40]
                mov     edi, [edx+34h]
                mov     edx, [ebx]
                mov     al, [eax+8]
                cmp     al, [edi+edx]
                jnz     short loc_1957C25
                mov     edx, [ebp+pStruct40]
                inc     edi
                mov     [edx+34h], edi

loc_1957C05:                            ; CODE XREF: sub_1957B80+6C_j
                mov     eax, [esi+200h]
                mov     edi, [ecx+eax]
                test    edi, edi
                jz      loc_1957CDB
                mov     ecx, [ebp+pStruct40]
                mov     edx, [ecx+34h]
                cmp     edx, [ebx+4]
                jb      loc_1957B95

loc_1957C25:                            ; CODE XREF: sub_1957B80+67_j
                                        ; sub_1957B80+7C_j ...
                pop     edi
                pop     esi
                xor     al, al
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    8
; ---------------------------------------------------------------------------

loc_1957C30:                            ; CODE XREF: sub_1957B80+32_j
                mov     edx, [esi+0D8h]
                mov     ecx, edi
                and     ecx, 1Fh
                mov     ebx, 1
                shl     ebx, cl
                mov     eax, edi
                shr     eax, 5
                test    [edx+eax*4], ebx
                jz      short loc_1957C8E
                cmp     dword ptr [esi+1F4h], 0
                push    edi
                mov     ecx, esi
                jz      short loc_1957C73
                call    sub_1957350
                mov     ecx, [esi+1F4h]
                mov     ebx, [ebp+arg_0]
                push    eax
                push    ebx
                test    ecx, ecx
                jz      short loc_1957C7D
                call    sub_1957B80
                jmp     short loc_1957C88
; ---------------------------------------------------------------------------

loc_1957C73:                            ; CODE XREF: sub_1957B80+D6_j
                call    sub_1957350
                mov     ebx, [ebp+arg_0]
                push    eax
                push    ebx

loc_1957C7D:                            ; CODE XREF: sub_1957B80+EA_j
                lea     ecx, [esi+174h]
                call    TNameIndexStruct__CheckNameFragment

loc_1957C88:                            ; CODE XREF: sub_1957B80+F1_j
                test    al, al
                jz      short loc_1957C25
                jmp     short loc_1957CB2
; ---------------------------------------------------------------------------

loc_1957C8E:                            ; CODE XREF: sub_1957B80+CA_j
                mov     eax, [ebp+pStruct40]
                mov     ecx, [esi+140h]
                mov     ebx, [ebp+arg_0]
                mov     eax, [eax+34h]
                mov     edx, [ebx]
                mov     cl, [edi+ecx]
                cmp     cl, [eax+edx]
                jnz     loc_1957C25
                mov     edx, [ebp+pStruct40]
                inc     eax
                mov     [edx+34h], eax

loc_1957CB2:                            ; CODE XREF: sub_1957B80+10C_j
                cmp     edi, [esi+214h]
                jbe     short loc_1957CDB
                mov     eax, [ebp+pStruct40]
                mov     ecx, [eax+34h]
                cmp     ecx, [ebx+4]
                jnb     loc_1957C25
                push    edi
                mov     ecx, esi
                call    sub_1959F50
                sub     eax, edi
                lea     edi, [eax-1]
                jmp     loc_1957B95
; ---------------------------------------------------------------------------

loc_1957CDB:                            ; CODE XREF: sub_1957B80+90_j
                                        ; sub_1957B80+138_j
                pop     edi
                pop     esi
                mov     al, 1
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    8
sub_1957B80     endp


; =============== S U B R O U T I N E =======================================

; Attributes: bp-based frame

sub_19573D0     proc near               ; CODE XREF: TFileNameDatabase__sub_1959460+1D9p

arg_0           = dword ptr  8
arg_4           = dword ptr  0Ch

                push    ebp
                mov     ebp, esp
                push    esi
                mov     esi, ecx
                mov     edx, [esi+TFileNameDatabase.FrgmDist_HiBits.BitsPerEntry]
                mov     eax, edx
                imul    eax, [ebp+arg_4]
                mov     ecx, eax
                and     eax, 1Fh
                add     edx, eax
                shr     ecx, 5
                cmp     edx, 20h
                mov     edx, [esi+TFileNameDatabase.FrgmDist_HiBits.ItemArray]
                ja      short loc_1957400
                mov     edx, [edx+ecx*4]
                mov     ecx, eax
                shr     edx, cl
                jmp     short loc_1957419
; ---------------------------------------------------------------------------

loc_1957400:                            ; CODE XREF: sub_19573D0+25j
                push    edi
                lea     edi, [edx+ecx*4]
                mov     edx, [edi+4]
                mov     edi, [edi]
                mov     ecx, 20h
                sub     ecx, eax
                shl     edx, cl
                mov     ecx, eax
                shr     edi, cl
                or      edx, edi
                pop     edi

loc_1957419:                            ; CODE XREF: sub_19573D0+2Ej
                and     edx, [esi+TFileNameDatabase.FrgmDist_HiBits.EntryBitMask]
                mov     eax, [esi+TFileNameDatabase.FrgmDist_LoBits.ItemArray]
                mov     ecx, [ebp+arg_0]
                movzx   eax, byte ptr [eax+ecx]
                shl     edx, 8
                or      eax, edx
                pop     esi
                pop     ebp
                retn    8
sub_19573D0     endp

; ---------------------------------------------------------------------------

; =============== S U B R O U T I N E =======================================

; Attributes: bp-based frame

TFileNameDatabase__CheckNextPathFragment proc near ; CODE XREF: TFileNameDatabase__FindFileInDatabase+25p

var_C           = dword ptr -0Ch
CollisionIndex  = dword ptr -8
var_4           = dword ptr -4
pStruct1C       = dword ptr  8

                push    ebp
                mov     ebp, esp
                mov     edx, [ebp+pStruct1C]
                sub     esp, 0Ch
                push    ebx
                mov     ebx, [edx+TMndxFindResult.szSearchMask]
                push    esi
                push    edi
                mov     edi, [edx+TMndxFindResult.pStruct40]
                mov     eax, [edi+TStruct40.CharIndex]
                movzx   eax, byte ptr [eax+ebx] ; EAX = szPathName[nCharIndex]
                mov     esi, ecx
                mov     ecx, [edi+TStruct40.HashValue]
                mov     ebx, ecx
                shl     ebx, 5
                xor     eax, ebx
                xor     eax, ecx
                and     eax, [esi+TFileNameDatabase.NameFragIndexMask] ; (000000ff) - Mask value
                lea     ebx, [eax+eax*2]
                mov     eax, [esi+TFileNameDatabase.NameFragTable.ItemArray] ; (7f3ae128) - Array of 256 triplets
                add     ebx, ebx
                add     ebx, ebx        ; EBX = Offset of the triplet we want to know
                cmp     ecx, [eax+ebx+TRIPLET.BitIndex]
                jnz     short loc_1957A0E
                mov     eax, [eax+ebx+TRIPLET.Distance]
                mov     ecx, eax
                and     ecx, 0FFFFFF00h
                cmp     ecx, 0FFFFFF00h
                jz      short loc_19579EF
                mov     ecx, [esi+TFileNameDatabase.NextDB.pDatabase]
                push    eax
                push    edx
                test    ecx, ecx
                jz      short loc_19579D5
                call    sub_1957B80
                jmp     short loc_19579E0
; ---------------------------------------------------------------------------

loc_19579D5:                            ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+5C_j
                lea     ecx, [esi+TFileNameDatabase.IndexStruct_174]
                call    TNameIndexStruct__CheckNameFragment

loc_19579E0:                            ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+63_j
                test    al, al
                jnz     short loc_19579F6

loc_19579E4:                            ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+C1j
                                        ; TFileNameDatabase__CheckNextPathFragment+1A4j
                pop     edi
                pop     esi
                xor     al, al
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    4
; ---------------------------------------------------------------------------

loc_19579EF:                            ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+50_j
                mov     eax, [edi+TStruct40.CharIndex] ; nCharIndex = nCharIndex + 1
                inc     eax
                mov     [edi+TStruct40.CharIndex], eax

loc_19579F6:                            ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+72_j
                mov     edx, [esi+TFileNameDatabase.NameFragTable.ItemArray] ; EDX = pTripletArray
                mov     eax, [edx+ebx+TRIPLET.NextKey]
                mov     [edi+TStruct40.HashValue], eax

loc_1957A03:                            ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+198j
                pop     edi
                pop     esi
                mov     al, 1
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    4
; ---------------------------------------------------------------------------

loc_1957A0E:                            ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+3C_j
                push    ecx             ; dwKey
                mov     ecx, esi        ; pDatabase
                call    TArchiveDatabase__sub_1959CB0
                mov     ebx, [esi+TFileNameDatabase.Struct68_00.ItemIsPresent.ItemArray]
                inc     eax
                mov     ecx, eax
                and     ecx, 1Fh
                mov     edx, 1
                shl     edx, cl
                mov     ecx, eax
                shr     ecx, 5
                mov     [ebp+CollisionIndex], eax
                test    [ebx+ecx*4], edx
                jz      short loc_19579E4
                sub     eax, [edi+TStruct40.HashValue]
                mov     [ebp+var_4], 0FFFFFFFFh
                dec     eax
                mov     [edi+TStruct40.HashValue], eax

loc_1957A41:                            ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+1E1j
                mov     eax, [edi+TStruct40.HashValue]
                mov     ebx, [esi+TFileNameDatabase.Struct68_D0.ItemIsPresent.ItemArray]
                mov     ecx, eax
                and     ecx, 1Fh
                mov     edx, 1
                shl     edx, cl
                mov     ecx, eax
                shr     ecx, 5
                test    [ebx+ecx*4], edx
                jz      loc_1957B1C
                mov     ecx, [ebp+var_4]
                cmp     ecx, 0FFFFFFFFh
                jnz     short loc_1957A7F
                push    eax
                lea     ecx, [esi+TFileNameDatabase.Struct68_D0]
                call    TSparseArray__GetItemValue
                mov     ecx, eax
                mov     [ebp+var_4], eax
                jmp     short loc_1957A83
; ---------------------------------------------------------------------------

loc_1957A7F:                            ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+FA_j
                inc     ecx
                mov     [ebp+var_4], ecx

loc_1957A83:                            ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+10D_j
                mov     edx, [edi+TStruct40.CharIndex]
                mov     [ebp+var_C], edx
                mov     edx, [esi+TFileNameDatabase.FrgmDist_HiBits.BitsPerEntry]
                mov     eax, edx
                imul    eax, ecx
                mov     ecx, eax
                and     eax, 1Fh
                add     edx, eax
                shr     ecx, 5
                cmp     edx, 20h
                mov     edx, [esi+TFileNameDatabase.FrgmDist_HiBits.ItemArray]
                ja      short loc_1957AB2
                mov     edx, [edx+ecx*4]
                mov     ecx, eax
                shr     edx, cl
                jmp     short loc_1957AC9
; ---------------------------------------------------------------------------

loc_1957AB2:                            ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+137_j
                lea     ebx, [edx+ecx*4]
                mov     edx, [ebx+4]
                mov     ebx, [ebx]
                mov     ecx, 20h
                sub     ecx, eax
                shl     edx, cl
                mov     ecx, eax
                shr     ebx, cl
                or      edx, ebx

loc_1957AC9:                            ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+140_j
                mov     ecx, [esi+TFileNameDatabase.FrgmDist_LoBits.ItemArray]
                and     edx, [esi+TFileNameDatabase.FrgmDist_HiBits.EntryBitMask]
                mov     eax, [edi+TStruct40.HashValue]
                movzx   eax, byte ptr [ecx+eax]
                mov     ecx, [esi+TFileNameDatabase.NextDB.pDatabase]
                shl     edx, 8
                or      eax, edx
                push    eax
                test    ecx, ecx
                jz      short loc_1957AF7
                mov     edx, [ebp+pStruct1C]
                push    edx
                call    sub_1957B80
                jmp     short loc_1957B06
; ---------------------------------------------------------------------------

loc_1957AF7:                            ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+17A_j
                mov     eax, [ebp+pStruct1C]
                push    eax
                lea     ecx, [esi+TFileNameDatabase.IndexStruct_174]
                call    TNameIndexStruct__CheckNameFragment

loc_1957B06:                            ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+185_j
                test    al, al
                jnz     loc_1957A03
                mov     ecx, [ebp+var_C]
                cmp     [edi+TStruct40.CharIndex], ecx
                jnz     loc_19579E4
                jmp     short loc_1957B32
; ---------------------------------------------------------------------------

loc_1957B1C:                            ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+EE_j
                mov     edx, [esi+TFileNameDatabase.FrgmDist_LoBits.ItemArray]
                mov     ebx, [ebp+pStruct1C]
                mov     ecx, [edi+TStruct40.CharIndex]
                mov     ebx, [ebx+TMndxFindResult.szSearchMask]
                mov     dl, [eax+edx]
                cmp     dl, [ecx+ebx]
                jz      short loc_1957B62

loc_1957B32:                            ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+1AA_j
                mov     eax, [ebp+CollisionIndex]
                inc     [edi+TStruct40.HashValue]
                inc     eax
                mov     ecx, eax
                and     ecx, 1Fh
                mov     edx, 1
                shl     edx, cl
                mov     ecx, [esi+TFileNameDatabase.Struct68_00.ItemIsPresent.ItemArray]
                mov     [ebp+CollisionIndex], eax
                shr     eax, 5
                test    [ecx+eax*4], edx
                jnz     loc_1957A41
                pop     edi
                pop     esi
                xor     al, al
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    4
; ---------------------------------------------------------------------------

loc_1957B62:                            ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+1C0_j
                mov     eax, 1
                add     [edi+TStruct40.CharIndex], eax
                pop     edi
                pop     esi
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    4
TFileNameDatabase__CheckNextPathFragment endp


TFileNameDatabase__FindFileInDatabase proc near
                                        ; CODE XREF: MAR_FILE__FindFileInDatabase+2D_p

pThis           = dword ptr -4
pStruct1C       = dword ptr  8

                push    ebp             ; ecx = Pointer to ARCHIVE_DATABASE
                mov     ebp, esp
                push    ecx
                push    ebx
                push    esi
                mov     esi, [ebp+pStruct1C]
                xor     eax, eax
                push    edi
                mov     edi, [esi+TMndxFindResult.pStruct40]
                mov     ebx, ecx
                mov     [edi+TStruct40.HashValue], eax
                mov     [edi+TStruct40.CharIndex], eax
                mov     [edi+TStruct40.SearchPhase], eax
                mov     [ebp+pThis], ebx
                cmp     [esi+TMndxFindResult.cchSearchMask], eax
                jbe     short loc_1957F26

label_process_all_characters:           ; CODE XREF: TFileNameDatabase__FindFileInDatabase+34j
                push    esi
                mov     ecx, ebx
                call    TFileNameDatabase__CheckNextPathFragment
                test    al, al
                jz      short label_return_false
                mov     eax, [edi+TStruct40.CharIndex]
                cmp     eax, [esi+TMndxFindResult.cchSearchMask]
                jb      short label_process_all_characters

loc_1957F26:                            ; CODE XREF: TFileNameDatabase__FindFileInDatabase+20_j
                mov     ecx, [edi+TStruct40.HashValue]
                mov     eax, [ebx+TFileNameDatabase.FileNameIndexes.ItemIsPresent.ItemArray]
                mov     edx, ecx
                and     ecx, 1Fh
                mov     ebx, 1
                shl     ebx, cl
                shr     edx, 5
                test    [eax+edx*4], ebx
                jz      short label_return_false
                mov     ecx, [esi+TMndxFindResult.szSearchMask]
                mov     eax, [esi+TMndxFindResult.cchSearchMask]
                mov     [esi+TMndxFindResult.szFoundPath], ecx
                mov     ecx, [ebp+pThis]
                mov     [esi+TMndxFindResult.cchFoundPath], eax
                mov     edi, [edi+TStruct40.HashValue]
                push    edi
                add     ecx, TFileNameDatabase.FileNameIndexes
                call    TSparseArray__GetItemValue
                pop     edi
                mov     [esi+TMndxFindResult.FileNameIndex], eax
                pop     esi
                mov     al, 1
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    4
; ---------------------------------------------------------------------------

label_return_false:                     ; CODE XREF: TFileNameDatabase__FindFileInDatabase+2C_j
                                        ; TFileNameDatabase__FindFileInDatabase+4E_j
                pop     edi
                pop     esi
                xor     al, al
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    4
TFileNameDatabase__FindFileInDatabase endp


; =============== S U B R O U T I N E =======================================

; Attributes: bp-based frame

TGenericArray__SetMaxItems_BYTE proc near ; CODE XREF: sub_19582E0+2Cp
                                        ; TStruct40__InitSearchBuffers+2Cp ...

ByteCount       = dword ptr  8

                push    ebp
                mov     ebp, esp
                push    ebx
                mov     ebx, [ebp+ByteCount]
                push    esi
                push    edi
                push    offset unk_53ABE00
                push    ebx
                mov     esi, ecx
                call    j_operator_new_safe
                xor     ecx, ecx
                add     esp, 8
                mov     edi, eax
                cmp     [esi+TGenericArray.ItemCount], ecx
                jbe     short loc_19575D7

loc_19575C2:                            ; CODE XREF: TGenericArray__SetMaxItems_BYTE+35j
                lea     edx, [ecx+edi]
                test    edx, edx
                jz      short loc_19575D1
                mov     eax, [esi+TGenericArray.field_4]
                mov     al, [ecx+eax]
                mov     [edx], al

loc_19575D1:                            ; CODE XREF: TGenericArray__SetMaxItems_BYTE+27j
                inc     ecx
                cmp     ecx, [esi+TGenericArray.ItemCount]
                jb      short loc_19575C2

loc_19575D7:                            ; CODE XREF: TGenericArray__SetMaxItems_BYTE+20j
                mov     eax, [esi+TGenericArray.DataBuffer]
                push    eax
                mov     [esi+TGenericArray.DataBuffer], edi
                mov     [esi+TGenericArray.field_4], edi
                mov     [esi+TGenericArray.ItemArray], edi
                mov     [esi+TGenericArray.MaxItemCount], ebx
                call    operator_delete
                add     esp, 4
                pop     edi
                pop     esi
                pop     ebx
                pop     ebp
                retn    4
TGenericArray__SetMaxItems_BYTE endp

; =============== S U B R O U T I N E =======================================

; Attributes: bp-based frame

TGenericArray__SetMaxItems_STRUCT14 proc near
                                        ; CODE XREF: TGenericArray__InsertItem_STRUCT14+2Cp
                                        ; TGenericArray__sub_19583A0+2Dp ...

var_4           = dword ptr -4
ItemCount       = dword ptr  8

                push    ebp
                mov     ebp, esp
                push    ecx
                push    esi
                push    edi
                mov     edi, [ebp+ItemCount]
                lea     eax, [edi+edi*4] ; EAX = (ItemCount * 5)
                add     eax, eax        ; EAX = (ItemCount * 10)
                add     eax, eax        ; EAX = (ItemCount * 20)
                push    offset unk_53ABE00
                push    eax
                mov     esi, ecx
                call    j_operator_new_safe
                mov     ecx, eax
                xor     eax, eax
                add     esp, 8
                mov     [ebp+var_4], ecx
                cmp     [esi+0Ch], eax
                jbe     short loc_195766A
                xor     edi, edi
                mov     edx, ecx
                push    ebx

loc_1957631:                            ; CODE XREF: TGenericArray__SetMaxItems_STRUCT14+64j
                test    edx, edx
                jz      short loc_195765A
                mov     ecx, [esi+4]
                mov     ebx, [ecx+edi]
                add     ecx, edi
                mov     [edx], ebx
                mov     ebx, [ecx+4]
                mov     [edx+4], ebx
                mov     ebx, [ecx+8]
                mov     [edx+8], ebx
                mov     ebx, [ecx+0Ch]
                mov     [edx+0Ch], ebx
                mov     ecx, [ecx+10h]
                mov     [edx+10h], ecx
                mov     ecx, [ebp+var_4]

loc_195765A:                            ; CODE XREF: TGenericArray__SetMaxItems_STRUCT14+33j
                inc     eax
                add     edi, 14h
                add     edx, 14h
                cmp     eax, [esi+0Ch]
                jb      short loc_1957631
                mov     edi, [ebp+ItemCount]
                pop     ebx

loc_195766A:                            ; CODE XREF: TGenericArray__SetMaxItems_STRUCT14+2Aj
                mov     eax, [esi+TGenericArray.DataBuffer]
                push    eax
                mov     [esi+TGenericArray.DataBuffer], ecx
                mov     [esi+TGenericArray.field_4], ecx
                mov     [esi+TGenericArray.ItemArray], ecx
                mov     [esi+TGenericArray.MaxItemCount], edi
                call    operator_delete
                add     esp, 4
                pop     edi
                pop     esi
                mov     esp, ebp
                pop     ebp
                retn    4
TGenericArray__SetMaxItems_STRUCT14 endp

; =============== S U B R O U T I N E =======================================

; Attributes: bp-based frame

TGenericArray__sub_19583A0 proc near    ; CODE XREF: TStruct40__InitSearchBuffers+35p

NewItemCount    = dword ptr  8

                push    ebp
                mov     ebp, esp
                push    esi
                mov     esi, ecx
                mov     eax, [esi+TGenericArray.MaxItemCount]
                push    edi
                mov     edi, [ebp+NewItemCount]
                cmp     edi, eax
                jbe     short loc_19583D2
                mov     edx, edi
                shr     edx, 1
                mov     ecx, edi
                cmp     eax, edx
                jbe     short loc_19583CA
                mov     ecx, 0CCCCCCCh
                cmp     eax, 6666666h
                ja      short loc_19583CA
                lea     ecx, [eax+eax]

loc_19583CA:                            ; CODE XREF: TGenericArray__sub_19583A0+19j
                                        ; TGenericArray__sub_19583A0+25j
                push    ecx
                mov     ecx, esi
                call    TGenericArray__SetMaxItems_STRUCT14

loc_19583D2:                            ; CODE XREF: TGenericArray__sub_19583A0+Fj
                mov     eax, [esi+TGenericArray.ItemCount]
                cmp     eax, edi
                jnb     short loc_1958410
                lea     ecx, [eax+eax*4]
                add     ecx, ecx
                mov     edx, edi
                push    ebx
                add     ecx, ecx
                sub     edx, eax
                or      ebx, 0FFFFFFFFh

loc_19583E8:                            ; CODE XREF: TGenericArray__sub_19583A0+6Dj
                mov     eax, [esi+TGenericArray.field_4]
                add     eax, ecx
                jz      short loc_1958409
                mov     dword ptr [eax], 0
                mov     dword ptr [eax+4], 0
                mov     dword ptr [eax+8], 0
                mov     [eax+0Ch], ebx
                mov     [eax+10h], ebx

loc_1958409:                            ; CODE XREF: TGenericArray__sub_19583A0+4Dj
                add     ecx, 14h
                dec     edx
                jnz     short loc_19583E8
                pop     ebx

loc_1958410:                            ; CODE XREF: TGenericArray__sub_19583A0+37j
                mov     [esi+TGenericArray.ItemCount], edi
                pop     edi
                pop     esi
                pop     ebp
                retn    4
TGenericArray__sub_19583A0 endp

; =============== S U B R O U T I N E =======================================


TStruct40__InitSearchBuffers     proc near               ; CODE XREF: TFileNameDatabase__sub_1959460+2Bp
                push    ebx
                push    esi
                mov     esi, ecx
                mov     eax, [esi+TStruct40.array_00.MaxItemCount]
                xor     ebx, ebx
                push    edi
                mov     [esi+TStruct40.array_00.ItemCount], ebx
                cmp     eax, 40h
                jnb     short loc_19586E1
                lea     ecx, [ebx+40h]  ; ECX = 0x40
                cmp     eax, 20h
                jbe     short loc_19586D9
                cmp     eax, 7FFFFFFFh
                jbe     short loc_19586D6
                or      ecx, 0FFFFFFFFh
                jmp     short loc_19586D9
; ---------------------------------------------------------------------------

loc_19586D6:                            ; CODE XREF: TStruct40__InitSearchBuffers+1Fj
                lea     ecx, [eax+eax]

loc_19586D9:                            ; CODE XREF: TStruct40__InitSearchBuffers+18j
                                        ; TStruct40__InitSearchBuffers+24j
                push    ecx
                mov     ecx, esi
                call    TGenericArray__SetMaxItems_BYTE

loc_19586E1:                            ; CODE XREF: TStruct40__InitSearchBuffers+10j
                push    ebx
                lea     ecx, [esi+TStruct40.array_18]
                call    TGenericArray__sub_19583A0
                mov     eax, [esi+TStruct40.array_18.MaxItemCount]
                cmp     eax, 4
                jnb     short loc_1958714
                mov     ecx, 4
                cmp     eax, 2
                jbe     short loc_195870B
                mov     ecx, 0CCCCCCCh
                cmp     eax, 6666666h
                ja      short loc_195870B
                lea     ecx, [eax+eax]

loc_195870B:                            ; CODE XREF: TStruct40__InitSearchBuffers+4Aj
                                        ; TStruct40__InitSearchBuffers+56j
                push    ecx
                lea     ecx, [esi+TStruct40.array_18]
                call    TGenericArray__SetMaxItems_STRUCT14

loc_1958714:                            ; CODE XREF: TStruct40__InitSearchBuffers+40j
                pop     edi
                mov     [esi+TStruct40.HashValue], ebx
                mov     [esi+TStruct40.CharIndex], ebx
                mov     [esi+TStruct40.ItemCount], ebx
                mov     [esi+TStruct40.SearchPhase], 2
                pop     esi
                pop     ebx
                retn
TStruct40__InitSearchBuffers     endp

; =============== S U B R O U T I N E =======================================

; Attributes: bp-based frame

TGenericArray__InsertItem_STRUCT14 proc near
                                        ; CODE XREF: TFileNameDatabase__sub_1959460+73p

pStruct14       = dword ptr  8

                push    ebp
                mov     ebp, esp
                push    esi
                mov     esi, ecx
                mov     eax, [esi+TGenericArray.ItemCount]
                mov     ecx, [esi+TGenericArray.MaxItemCount]
                inc     eax
                cmp     eax, ecx
                jbe     short loc_1958361
                mov     edx, eax
                shr     eax, 1
                cmp     ecx, eax
                jbe     short loc_1958359
                mov     edx, 0CCCCCCCh
                cmp     ecx, 6666666h
                ja      short loc_1958359
                lea     edx, [ecx+ecx]

loc_1958359:                            ; CODE XREF: TGenericArray__InsertItem_STRUCT14+17j
                                        ; TGenericArray__InsertItem_STRUCT14+24j
                push    edx
                mov     ecx, esi
                call    TGenericArray__SetMaxItems_STRUCT14

loc_1958361:                            ; CODE XREF: TGenericArray__InsertItem_STRUCT14+Fj
                mov     eax, [esi+TGenericArray.ItemCount]
                mov     ecx, [esi+TGenericArray.field_4]
                lea     eax, [eax+eax*4]
                lea     eax, [ecx+eax*4]
                test    eax, eax
                jz      short loc_1958390
                mov     ecx, [ebp+pStruct14]
                mov     edx, [ecx+TStruct14.HashValue]
                mov     [eax+TStruct14.HashValue], edx
                mov     edx, [ecx+TStruct14.field_4]
                mov     [eax+TStruct14.field_4], edx
                mov     edx, [ecx+TStruct14.field_8]
                mov     [eax+TStruct14.field_8], edx
                mov     edx, [ecx+TStruct14.field_C]
                mov     [eax+TStruct14.field_C], edx
                mov     ecx, [ecx+TStruct14.field_10]
                mov     [eax+TStruct14.field_10], ecx

loc_1958390:                            ; CODE XREF: TGenericArray__InsertItem_STRUCT14+3Fj
                inc     [esi+TGenericArray.ItemCount]
                pop     esi
                pop     ebp
                retn    4
TGenericArray__InsertItem_STRUCT14 endp

; =============== S U B R O U T I N E =======================================

; Attributes: bp-based frame

CopyNameFragment proc near              ; CODE XREF: sub_1958980+DAp
                                        ; sub_1958D70+6Dp ...

pThis           = dword ptr -4
pStruct1C       = dword ptr  8
dwDistance      = dword ptr  0Ch

                push    ebp
                mov     ebp, esp
                push    ecx
                mov     eax, [ebp+pStruct1C]
                push    ebx
                mov     ebx, ecx
                cmp     [ebx+TNameIndexStruct.Struct68.TotalItemCount], 0
                push    esi
                mov     esi, [eax+TMndxFindResult.pStruct40]
                push    edi
                mov     [ebp+pThis], ebx
                jnz     loc_195A4B3
                mov     ebx, [ebx+TNameIndexStruct.NameFragments.ItemArray]
                add     ebx, [ebp+dwDistance]
                cmp     byte ptr [ebx], 0
                mov     [ebp+dwDistance], ebx
                jz      loc_195A55E
                mov     edi, edi

loc_195A420:                            ; CODE XREF: CopyNameFragment+B4j
                mov     eax, [esi+TStruct40.array_00.ItemCount]
                mov     ecx, [esi+TStruct40.array_00.MaxItemCount]
                inc     eax
                cmp     eax, ecx
                jbe     short loc_195A48E
                mov     ebx, eax
                shr     eax, 1
                cmp     ecx, eax
                jbe     short loc_195A443
                cmp     ecx, 7FFFFFFFh
                jbe     short loc_195A440
                or      ebx, 0FFFFFFFFh
                jmp     short loc_195A443
; ---------------------------------------------------------------------------

loc_195A440:                            ; CODE XREF: CopyNameFragment+49j
                lea     ebx, [ecx+ecx]

loc_195A443:                            ; CODE XREF: CopyNameFragment+41j
                                        ; CopyNameFragment+4Ej
                push    offset unk_53ABE00
                push    ebx
                call    j_operator_new_safe
                xor     ecx, ecx
                add     esp, 8
                mov     edi, eax
                cmp     [esi+TStruct40.array_00.ItemCount], ecx
                jbe     short loc_195A475
                lea     ebx, [ebx+0]

loc_195A460:                            ; CODE XREF: CopyNameFragment+83j
                lea     edx, [ecx+edi]
                test    edx, edx
                jz      short loc_195A46F
                mov     eax, [esi+TStruct40.array_00.field_4]
                mov     al, [ecx+eax]
                mov     [edx], al

loc_195A46F:                            ; CODE XREF: CopyNameFragment+75j
                inc     ecx
                cmp     ecx, [esi+TStruct40.array_00.ItemCount]
                jb      short loc_195A460

loc_195A475:                            ; CODE XREF: CopyNameFragment+68j
                mov     eax, [esi+TStruct40.array_00.DataBuffer]
                push    eax
                mov     [esi+TStruct40.array_00.DataBuffer], edi
                mov     [esi+TStruct40.array_00.field_4], edi
                mov     [esi+TStruct40.array_00.ItemArray], edi
                mov     [esi+TStruct40.array_00.MaxItemCount], ebx
                call    operator_delete
                mov     ebx, [ebp+dwDistance]
                add     esp, 4

loc_195A48E:                            ; CODE XREF: CopyNameFragment+39j
                mov     eax, [esi+TStruct40.array_00.ItemCount]
                add     eax, [esi+TStruct40.array_00.field_4]
                jz      short loc_195A49A
                mov     cl, [ebx]
                mov     [eax], cl

loc_195A49A:                            ; CODE XREF: CopyNameFragment+A4j
                inc     [esi+TStruct40.array_00.ItemCount]
                inc     ebx
                cmp     byte ptr [ebx], 0
                mov     [ebp+dwDistance], ebx
                jnz     loc_195A420
                pop     edi
                pop     esi
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    8
; ---------------------------------------------------------------------------

loc_195A4B3:                            ; CODE XREF: CopyNameFragment+16j
                                        ; CopyNameFragment+168j
                mov     eax, [esi+TStruct40.array_00.ItemCount]
                mov     edx, [ebx+TNameIndexStruct.NameFragments.ItemArray]
                mov     edi, [ebp+dwDistance]
                mov     ecx, [esi+TStruct40.array_00.MaxItemCount]
                add     edx, edi
                inc     eax
                mov     [ebp+pStruct1C], edx
                cmp     eax, ecx
                jbe     short loc_195A52C
                mov     ebx, eax
                shr     eax, 1
                cmp     ecx, eax
                jbe     short loc_195A4E1
                cmp     ecx, 7FFFFFFFh
                jbe     short loc_195A4DE
                or      ebx, 0FFFFFFFFh
                jmp     short loc_195A4E1
; ---------------------------------------------------------------------------

loc_195A4DE:                            ; CODE XREF: CopyNameFragment+E7j
                lea     ebx, [ecx+ecx]

loc_195A4E1:                            ; CODE XREF: CopyNameFragment+DFj
                                        ; CopyNameFragment+ECj
                push    offset unk_53ABE00
                push    ebx
                call    j_operator_new_safe
                xor     ecx, ecx
                add     esp, 8
                mov     edi, eax
                cmp     [esi+TStruct40.array_00.ItemCount], ecx
                jbe     short loc_195A50D

loc_195A4F8:                            ; CODE XREF: CopyNameFragment+11Bj
                lea     edx, [ecx+edi]
                test    edx, edx
                jz      short loc_195A507
                mov     eax, [esi+TStruct40.array_00.field_4]
                mov     al, [ecx+eax]
                mov     [edx], al

loc_195A507:                            ; CODE XREF: CopyNameFragment+10Dj
                inc     ecx
                cmp     ecx, [esi+TStruct40.array_00.ItemCount]
                jb      short loc_195A4F8

loc_195A50D:                            ; CODE XREF: CopyNameFragment+106j
                mov     eax, [esi+TStruct40.array_00.DataBuffer]
                push    eax
                mov     [esi+TStruct40.array_00.DataBuffer], edi
                mov     [esi+TStruct40.array_00.field_4], edi
                mov     [esi+TStruct40.array_00.ItemArray], edi
                mov     [esi+TStruct40.array_00.MaxItemCount], ebx
                call    operator_delete
                mov     edx, [ebp+pStruct1C]
                mov     edi, [ebp+dwDistance]
                mov     ebx, [ebp+pThis]
                add     esp, 4

loc_195A52C:                            ; CODE XREF: CopyNameFragment+D7j
                mov     eax, [esi+TStruct40.array_00.ItemCount]
                add     eax, [esi+TStruct40.array_00.field_4]
                jz      short loc_195A538
                mov     cl, [edx]
                mov     [eax], cl

loc_195A538:                            ; CODE XREF: CopyNameFragment+142j
                inc     [esi+TStruct40.array_00.ItemCount]
                mov     ecx, edi
                and     ecx, 1Fh
                mov     edx, 1
                shl     edx, cl
                mov     ecx, [ebx+TNameIndexStruct.Struct68.ItemIsPresent.ItemArray]
                mov     eax, edi
                shr     eax, 5
                and     edx, [ecx+eax*4]
                inc     edi
                mov     [ebp+dwDistance], edi
                test    edx, edx
                jz      loc_195A4B3

loc_195A55E:                            ; CODE XREF: CopyNameFragment+28j
                pop     edi
                pop     esi
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    8
CopyNameFragment endp

; =============== S U B R O U T I N E =======================================

; Attributes: bp-based frame

sub_1958D70     proc near               ; CODE XREF: sub_1958980+C9p
                                        ; sub_1958D70+59p ...

var_C           = dword ptr -0Ch
var_8           = dword ptr -8
var_1           = byte ptr -1
pStruct1C       = dword ptr  8
arg_4           = dword ptr  0Ch

                push    ebp
                mov     ebp, esp
                mov     eax, [ebp+pStruct1C]
                sub     esp, 0Ch
                push    ebx
                push    esi
                mov     esi, [eax+TMndxFindResult.pStruct40]
                push    edi
                mov     edi, ecx
                mov     ecx, [ebp+arg_4]

loc_1958D84:                            ; CODE XREF: sub_1958D70+10Fj
                                        ; sub_1958D70+28Fj
                mov     eax, [edi+TFileNameDatabase.NameFragIndexMask]
                and     eax, ecx
                lea     ebx, [eax+eax*2]
                mov     eax, [edi+TFileNameDatabase.NameFragTable.ItemArray]
                add     ebx, ebx
                add     ebx, ebx
                mov     [ebp+var_C], ebx
                cmp     ecx, [eax+ebx+4]
                jnz     loc_1958E8E
                mov     edx, [eax+ebx+8]
                mov     ecx, edx
                and     ecx, 0FFFFFF00h
                cmp     ecx, 0FFFFFF00h
                jz      short loc_1958DE7
                mov     ecx, [edi+TFileNameDatabase.NextDB.pDatabase]
                push    edx
                test    ecx, ecx
                jz      short loc_1958DD3
                mov     edx, [ebp+pStruct1C]
                push    edx
                call    sub_1958D70
                jmp     loc_1958E71
; ---------------------------------------------------------------------------

loc_1958DD3:                            ; CODE XREF: sub_1958D70+53j
                mov     eax, [ebp+pStruct1C]
                push    eax
                lea     ecx, [edi+TFileNameDatabase.IndexStruct_174]
                call    CopyNameFragment
                jmp     loc_1958E71
; ---------------------------------------------------------------------------

loc_1958DE7:                            ; CODE XREF: sub_1958D70+48j
                mov     eax, [esi+TStruct40.array_00.ItemCount]
                mov     ecx, [esi+TStruct40.array_00.MaxItemCount]
                inc     eax
                mov     byte ptr [ebp+arg_4+3], dl
                cmp     eax, ecx
                jbe     short loc_1958E61
                mov     [ebp+var_8], eax
                shr     eax, 1
                cmp     ecx, eax
                jbe     short loc_1958E15
                cmp     ecx, 7FFFFFFFh
                jbe     short loc_1958E0F
                mov     [ebp+var_8], 0FFFFFFFFh
                jmp     short loc_1958E15
; ---------------------------------------------------------------------------

loc_1958E0F:                            ; CODE XREF: sub_1958D70+94j
                lea     edx, [ecx+ecx]
                mov     [ebp+var_8], edx

loc_1958E15:                            ; CODE XREF: sub_1958D70+8Cj
                                        ; sub_1958D70+9Dj
                mov     eax, [ebp+var_8]
                push    offset unk_53ABE00
                push    eax
                call    j_operator_new_safe
                xor     ecx, ecx
                add     esp, 8
                cmp     [esi+TStruct40.array_00.ItemCount], ecx
                jbe     short loc_1958E48
                lea     ecx, [ecx+0]

loc_1958E30:                            ; CODE XREF: sub_1958D70+D6j
                lea     edx, [ecx+eax]
                test    edx, edx
                jz      short loc_1958E42
                mov     ebx, [esi+4]
                mov     bl, [ecx+ebx]
                mov     [edx], bl
                mov     ebx, [ebp+var_C]

loc_1958E42:                            ; CODE XREF: sub_1958D70+C5j
                inc     ecx
                cmp     ecx, [esi+TStruct40.array_00.ItemCount]
                jb      short loc_1958E30

loc_1958E48:                            ; CODE XREF: sub_1958D70+BBj
                mov     ecx, [esi]
                mov     edx, [ebp+var_8]
                push    ecx
                mov     [esi+TStruct40.array_00.DataBuffer], eax
                mov     [esi+TStruct40.array_00.field_4], eax
                mov     [esi+TStruct40.array_00.ItemArray], eax
                mov     [esi+TStruct40.array_00.MaxItemCount], edx
                call    operator_delete
                add     esp, 4

loc_1958E61:                            ; CODE XREF: sub_1958D70+83j
                mov     eax, [esi+TStruct40.array_00.field_4]
                add     eax, [esi+TStruct40.array_00.ItemCount]
                jz      short loc_1958E6E
                mov     cl, byte ptr [ebp+arg_4+3]
                mov     [eax], cl

loc_1958E6E:                            ; CODE XREF: sub_1958D70+F7j
                inc     [esi+TStruct40.array_00.ItemCount]

loc_1958E71:                            ; CODE XREF: sub_1958D70+5Ej
                                        ; sub_1958D70+72j
                mov     edx, [edi+TFileNameDatabase.NameFragTable.ItemArray]
                mov     ecx, [ebx+edx]
                mov     [ebp+arg_4], ecx
                test    ecx, ecx
                jnz     loc_1958D84

loc_1958E85:                            ; CODE XREF: sub_1958D70+277j
                pop     edi
                pop     esi
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    8
; ---------------------------------------------------------------------------

loc_1958E8E:                            ; CODE XREF: sub_1958D70+30j
                mov     edx, [edi+TFileNameDatabase.Struct68_D0.ItemIsPresent.ItemArray]
                mov     eax, ecx
                and     ecx, 1Fh
                mov     ebx, 1
                shl     ebx, cl
                shr     eax, 5
                test    [edx+eax*4], ebx
                mov     eax, [ebp+arg_4]
                jz      loc_1958F50
                mov     ebx, [edi+TFileNameDatabase.FrgmDist_LoBits.ItemArray]
                push    eax
                lea     ecx, [edi+TFileNameDatabase.Struct68_D0]
                add     ebx, eax
                call    TSparseArray__GetItemValue
                mov     ecx, [edi+TFileNameDatabase.FrgmDist_HiBits.BitsPerEntry]
                imul    ecx, eax
                mov     eax, ecx
                and     ecx, 1Fh
                mov     edx, ecx
                mov     ecx, [edi+TFileNameDatabase.FrgmDist_HiBits.BitsPerEntry]
                add     ecx, edx
                shr     eax, 5
                cmp     ecx, 20h
                mov     ecx, [edi+TFileNameDatabase.FrgmDist_HiBits.ItemArray]
                ja      short loc_1958EF2
                mov     eax, [ecx+eax*4]
                mov     ecx, edx
                shr     eax, cl
                jmp     short loc_1958F15
; ---------------------------------------------------------------------------

loc_1958EF2:                            ; CODE XREF: sub_1958D70+177j
                lea     eax, [ecx+eax*4]
                mov     [ebp+var_C], eax
                mov     eax, [eax+4]
                mov     ecx, 20h
                sub     ecx, edx
                shl     eax, cl
                mov     ecx, [ebp+var_C]
                mov     ecx, [ecx]
                mov     [ebp+var_C], ecx
                mov     ecx, edx
                mov     edx, [ebp+var_C]
                shr     edx, cl
                or      eax, edx

loc_1958F15:                            ; CODE XREF: sub_1958D70+180j
                and     eax, [edi+TFileNameDatabase.FrgmDist_HiBits.EntryBitMask]
                movzx   edx, byte ptr [ebx]
                mov     ecx, [edi+TFileNameDatabase.NextDB.pDatabase]
                shl     eax, 8
                or      eax, edx
                push    eax
                test    ecx, ecx
                jz      short loc_1958F3C
                mov     eax, [ebp+pStruct1C]
                push    eax
                call    sub_1958D70
                jmp     loc_1958FDE
; ---------------------------------------------------------------------------

loc_1958F3C:                            ; CODE XREF: sub_1958D70+1BCj
                mov     ecx, [ebp+pStruct1C]
                push    ecx
                lea     ecx, [edi+TFileNameDatabase.IndexStruct_174]
                call    CopyNameFragment
                jmp     loc_1958FDE
; ---------------------------------------------------------------------------

loc_1958F50:                            ; CODE XREF: sub_1958D70+139j
                mov     edx, [edi+TFileNameDatabase.FrgmDist_LoBits.ItemArray]
                mov     cl, [eax+edx]
                mov     eax, [esi+TStruct40.array_00.ItemCount]
                mov     [ebp+var_1], cl
                mov     ecx, [esi+TStruct40.array_00.MaxItemCount]
                inc     eax
                cmp     eax, ecx
                jbe     short loc_1958FCE
                mov     ebx, eax
                shr     eax, 1
                mov     [ebp+var_8], ebx
                cmp     ecx, eax
                jbe     short loc_1958F85
                cmp     ecx, 7FFFFFFFh
                jbe     short loc_1958F7F
                or      ebx, 0FFFFFFFFh
                jmp     short loc_1958F82
; ---------------------------------------------------------------------------

loc_1958F7F:                            ; CODE XREF: sub_1958D70+208j
                lea     ebx, [ecx+ecx]

loc_1958F82:                            ; CODE XREF: sub_1958D70+20Dj
                mov     [ebp+var_8], ebx

loc_1958F85:                            ; CODE XREF: sub_1958D70+200j
                push    offset unk_53ABE00
                push    ebx
                call    j_operator_new_safe
                xor     ecx, ecx
                add     esp, 8
                cmp     [esi+TStruct40.array_00.ItemCount], ecx
                jbe     short loc_1958FB8
                lea     ebx, [ebx+0]

loc_1958FA0:                            ; CODE XREF: sub_1958D70+243j
                lea     edx, [ecx+eax]
                test    edx, edx
                jz      short loc_1958FAF
                mov     ebx, [esi+TStruct40.array_00.field_4]
                mov     bl, [ecx+ebx]
                mov     [edx], bl

loc_1958FAF:                            ; CODE XREF: sub_1958D70+235j
                inc     ecx
                cmp     ecx, [esi+TStruct40.array_00.ItemCount]
                jb      short loc_1958FA0
                mov     ebx, [ebp+var_8]

loc_1958FB8:                            ; CODE XREF: sub_1958D70+228j
                mov     ecx, [esi+TStruct40.array_00.DataBuffer]
                push    ecx
                mov     [esi+TStruct40.array_00.DataBuffer], eax
                mov     [esi+TStruct40.array_00.field_4], eax
                mov     [esi+TStruct40.array_00.ItemArray], eax
                mov     [esi+TStruct40.array_00.MaxItemCount], ebx
                call    operator_delete
                add     esp, 4

loc_1958FCE:                            ; CODE XREF: sub_1958D70+1F5j
                mov     eax, [esi+TStruct40.array_00.field_4]
                add     eax, [esi+TStruct40.array_00.ItemCount]
                jz      short loc_1958FDB
                mov     dl, [ebp+var_1]
                mov     [eax], dl

loc_1958FDB:                            ; CODE XREF: sub_1958D70+264j
                inc     [esi+TStruct40.array_00.ItemCount]

loc_1958FDE:                            ; CODE XREF: sub_1958D70+1C7j
                                        ; sub_1958D70+1DBj
                mov     ebx, [ebp+arg_4]
                cmp     ebx, [edi+TFileNameDatabase.field_214]
                jbe     loc_1958E85
                push    ebx
                mov     ecx, edi
                call    sub_1959F50
                or      ecx, 0FFFFFFFFh
                sub     ecx, ebx
                add     ecx, eax
                mov     [ebp+arg_4], ecx
                jmp     loc_1958D84
sub_1958D70     endp

; =============== S U B R O U T I N E =======================================

; Attributes: bp-based frame

TFileNameDatabase__sub_1959CB0 proc near ; CODE XREF: TFileNameDatabase__CheckNextPathFragment+A1p
                                        ; TFileNameDatabase__sub_1958B00+E8p ...

pThis           = dword ptr -4
dwKey           = dword ptr  8

                push    ebp
                mov     ebp, esp
                push    ecx
                mov     edx, [ebp+dwKey]
                mov     eax, edx
                shr     eax, 9
                mov     [ebp+pThis], ecx
                test    edx, 1FFh       ; if(dwKey & 0x01FF)
                jnz     short loc_1959CD3
                mov     ecx, [ecx+TFileNameDatabase.Struct68_00.ArrayDwords_38.ItemArray]
                mov     eax, [ecx+eax*4] ; EAX = pDatabase->NextKeyTable[dwKey >> 0x09]
                mov     esp, ebp
                pop     ebp
                retn    4
; ---------------------------------------------------------------------------

loc_1959CD3:                            ; CODE XREF: TFileNameDatabase__sub_1959CB0+15j
                push    ebx
                push    esi
                mov     esi, [ecx+TFileNameDatabase.Struct68_00.ArrayDwords_38.ItemArray]
                lea     esi, [esi+eax*4]
                mov     eax, [esi]
                mov     esi, [esi+4]
                shr     eax, 9
                add     esi, 1FFh
                push    edi
                shr     esi, 9
                lea     edi, [eax+0Ah]
                mov     [ebp+dwKey], esi
                cmp     edi, esi
                jb      short loc_1959D2E
                mov     edi, [ecx+TFileNameDatabase.Struct68_00.ArrayTriplets_20.ItemArray]
                lea     esi, [eax+eax*2+3]
                lea     esi, [edi+esi*4]
                mov     edi, eax
                shl     edi, 9
                mov     ebx, edi
                sub     ebx, [esi]
                add     ebx, 200h
                cmp     edx, ebx
                jb      short loc_1959D5F

loc_1959D14:                            ; CODE XREF: TFileNameDatabase__sub_1959CB0+7Aj
                add     edi, 200h
                add     esi, 0Ch
                mov     ebx, edi
                sub     ebx, [esi]
                inc     eax
                add     ebx, 200h
                cmp     edx, ebx
                jnb     short loc_1959D14
                jmp     short loc_1959D5F
; ---------------------------------------------------------------------------

loc_1959D2E:                            ; CODE XREF: TFileNameDatabase__sub_1959CB0+45j
                lea     edi, [eax+1]
                cmp     edi, esi
                jnb     short loc_1959D5F
                mov     ecx, [ecx+TFileNameDatabase.Struct68_00.ArrayTriplets_20.ItemArray]

loc_1959D38:                            ; CODE XREF: TFileNameDatabase__sub_1959CB0+AAj
                add     esi, eax
                shr     esi, 1
                mov     ebx, esi
                shl     ebx, 9
                lea     edi, [esi+esi*2]
                sub     ebx, [ecx+edi*4]
                cmp     edx, ebx
                jnb     short loc_1959D50
                mov     [ebp+dwKey], esi
                jmp     short loc_1959D55
; ---------------------------------------------------------------------------

loc_1959D50:                            ; CODE XREF: TFileNameDatabase__sub_1959CB0+99j
                mov     eax, esi
                mov     esi, [ebp+dwKey]

loc_1959D55:                            ; CODE XREF: TFileNameDatabase__sub_1959CB0+9Ej
                lea     edi, [eax+1]
                cmp     edi, esi
                jb      short loc_1959D38
                mov     ecx, [ebp+pThis]

loc_1959D5F:                            ; CODE XREF: TFileNameDatabase__sub_1959CB0+62j
                                        ; TFileNameDatabase__sub_1959CB0+7Cj ...
                mov     ecx, [ecx+TFileNameDatabase.Struct68_00.ArrayTriplets_20.ItemArray]
                lea     esi, [eax+eax*2]
                mov     edi, [ecx+esi*4] ; EDI = Struct68_00.ArrayTriplets_20.ItemArray[eax]
                lea     esi, [ecx+esi*4] ; ESI = Struct68_00.ArrayTriplets_20.ItemArray + eax
                mov     ecx, eax
                shl     ecx, 9
                sub     edi, ecx
                shl     eax, 4
                add     edx, edi
                mov     edi, eax
                mov     eax, [esi+TRIPLET.NextKey]
                mov     ecx, eax
                shr     ecx, 17h
                mov     ebx, 100h
                sub     ebx, ecx
                cmp     edx, ebx
                jnb     short loc_1959DE8
                mov     ecx, eax
                shr     ecx, 7
                and     ecx, 0FFh
                mov     esi, 80h
                sub     esi, ecx
                cmp     edx, esi
                jnb     short loc_1959DC0
                and     eax, 7Fh
                mov     ecx, 40h
                sub     ecx, eax
                cmp     edx, ecx
                jb      loc_1959E53
                add     edi, 2
                lea     edx, [edx+eax-40h]
                jmp     loc_1959E53
; ---------------------------------------------------------------------------

loc_1959DC0:                            ; CODE XREF: TFileNameDatabase__sub_1959CB0+F0j
                shr     eax, 0Fh
                and     eax, 0FFh
                mov     esi, 0C0h
                sub     esi, eax
                cmp     edx, esi
                jnb     short loc_1959DDC
                add     edi, 4
                lea     edx, [edx+ecx-80h]
                jmp     short loc_1959E53
; ---------------------------------------------------------------------------

loc_1959DDC:                            ; CODE XREF: TFileNameDatabase__sub_1959CB0+121j
                add     edi, 6
                lea     edx, [edx+eax-0C0h]
                jmp     short loc_1959E53
; ---------------------------------------------------------------------------

loc_1959DE8:                            ; CODE XREF: TFileNameDatabase__sub_1959CB0+DAj
                mov     esi, [esi+TRIPLET.Distance]
                mov     eax, esi
                shr     eax, 9
                and     eax, 1FFh
                mov     ebx, 180h
                sub     ebx, eax
                cmp     edx, ebx
                jnb     short loc_1959E29
                and     esi, 1FFh
                mov     eax, 140h
                sub     eax, esi
                cmp     edx, eax
                jnb     short loc_1959E1D
                add     edi, 8
                lea     edx, [edx+ecx-100h]
                jmp     short loc_1959E53
; ---------------------------------------------------------------------------

loc_1959E1D:                            ; CODE XREF: TFileNameDatabase__sub_1959CB0+15Fj
                add     edi, 0Ah
                lea     edx, [edx+esi-140h]
                jmp     short loc_1959E53
; ---------------------------------------------------------------------------

loc_1959E29:                            ; CODE XREF: TFileNameDatabase__sub_1959CB0+14Ej
                shr     esi, 12h
                and     esi, 1FFh
                mov     ecx, 1C0h
                sub     ecx, esi
                cmp     edx, ecx
                jnb     short loc_1959E49
                add     edi, 0Ch
                lea     edx, [edx+eax-180h]
                jmp     short loc_1959E53
; ---------------------------------------------------------------------------

loc_1959E49:                            ; CODE XREF: TFileNameDatabase__sub_1959CB0+18Bj
                add     edi, 0Eh
                lea     edx, [edx+esi-1C0h]

loc_1959E53:                            ; CODE XREF: TFileNameDatabase__sub_1959CB0+FEj
                                        ; TFileNameDatabase__sub_1959CB0+10Bj ...
                mov     eax, [ebp+pThis]
                mov     ebx, [eax+TFileNameDatabase.Struct68_00.ItemIsPresent.ItemArray]
                mov     ecx, [ebx+edi*4]
                not     ecx
                mov     eax, ecx
                shr     eax, 1
                and     eax, 55555555h
                mov     esi, ecx
                and     esi, 55555555h
                add     eax, esi
                mov     esi, eax
                shr     esi, 2
                and     eax, 33333333h
                and     esi, 33333333h
                add     esi, eax
                mov     eax, esi
                shr     eax, 4
                and     esi, 0F0F0F0Fh
                and     eax, 0F0F0F0Fh
                add     eax, esi
                imul    eax, 1010101h
                mov     esi, eax
                shr     esi, 18h
                cmp     edx, esi
                jb      short loc_1959EEA
                mov     ecx, [ebx+edi*4+4]
                inc     edi
                sub     edx, esi
                not     ecx
                mov     eax, ecx
                shr     eax, 1
                and     eax, 55555555h
                mov     esi, ecx
                and     esi, 55555555h
                add     eax, esi
                mov     esi, eax
                shr     esi, 2
                and     eax, 33333333h
                and     esi, 33333333h
                add     esi, eax
                mov     eax, esi
                shr     eax, 4
                and     eax, 0F0F0F0Fh
                and     esi, 0F0F0F0Fh
                add     eax, esi
                imul    eax, 1010101h

loc_1959EEA:                            ; CODE XREF: TFileNameDatabase__sub_1959CB0+1F2j
                mov     esi, eax
                shr     esi, 8
                and     esi, 0FFh
                shl     edi, 5
                cmp     edx, esi
                jnb     short loc_1959F0D
                and     eax, 0FFh
                cmp     edx, eax
                jb      short loc_1959F2B
                add     edi, 8
                shr     ecx, 8
                jmp     short loc_1959F29
; ---------------------------------------------------------------------------

loc_1959F0D:                            ; CODE XREF: TFileNameDatabase__sub_1959CB0+24Aj
                shr     eax, 10h
                and     eax, 0FFh
                cmp     edx, eax
                jnb     short loc_1959F23
                add     edi, 10h
                shr     ecx, 10h
                sub     edx, esi
                jmp     short loc_1959F2B
; ---------------------------------------------------------------------------

loc_1959F23:                            ; CODE XREF: TFileNameDatabase__sub_1959CB0+267j
                add     edi, 18h
                shr     ecx, 18h

loc_1959F29:                            ; CODE XREF: TFileNameDatabase__sub_1959CB0+25Bj
                sub     edx, eax

loc_1959F2B:                            ; CODE XREF: TFileNameDatabase__sub_1959CB0+253j
                                        ; TFileNameDatabase__sub_1959CB0+271j
                and     ecx, 0FFh
                shl     edx, 8
                movzx   eax, ds:table_1BA1818[ecx+edx]
                add     eax, edi
                pop     edi
                pop     esi
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    4
TFileNameDatabase__sub_1959CB0 endp

; =============== S U B R O U T I N E =======================================

; Attributes: bp-based frame

TNameIndexStruct__CheckAndCopyNameFragment     proc near               ; CODE XREF: TArchiveDatabase__sub_1958B00+74p
                                        ; TArchiveDatabase__sub_1958B00+1E0p ...

var_C           = dword ptr -0Ch
pThis           = dword ptr -8
var_4           = dword ptr -4
pStruct1C       = dword ptr  8
dwDistance      = dword ptr  0Ch

                push    ebp
                mov     ebp, esp
                sub     esp, 0Ch
                mov     eax, [ebp+pStruct1C]
                push    ebx
                mov     edx, ecx
                cmp     [edx+TNameIndexStruct.Struct68.TotalItemCount], 0
                push    esi
                mov     esi, [eax+TMndxFindResult.pStruct40]
                push    edi
                mov     [ebp+pThis], edx
                jnz     loc_195A6B7
                mov     edi, [edx+TNameIndexStruct.NameFragments.ItemArray]
                sub     edi, [esi+TStruct40.CharIndex]
                add     edi, [ebp+dwDistance]
                mov     [ebp+pThis], edi
                lea     ebx, [ebx+0]

loc_195A5A0:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+E6j
                mov     edx, [esi+TStruct40.CharIndex]
                mov     ecx, [ebp+pStruct1C]
                mov     eax, [ecx+TMndxFindResult.szSearchMask]
                mov     cl, [edx+edi]
                mov     [ebp+dwDistance], edx
                cmp     cl, [edx+eax]
                jnz     loc_195A67D
                mov     eax, [esi+TStruct40.array_00.ItemCount]
                mov     ecx, [esi+TStruct40.array_00.MaxItemCount]
                mov     ebx, 1
                add     eax, ebx
                cmp     eax, ecx
                jbe     short loc_195A62D
                mov     ebx, eax
                shr     eax, 1
                cmp     ecx, eax
                jbe     short loc_195A5E0
                cmp     ecx, 7FFFFFFFh
                jbe     short loc_195A5DD
                or      ebx, 0FFFFFFFFh
                jmp     short loc_195A5E0
; ---------------------------------------------------------------------------

loc_195A5DD:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+66j
                lea     ebx, [ecx+ecx]

loc_195A5E0:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+5Ej
                                        ; TNameIndexStruct__CheckAndCopyNameFragment+6Bj
                push    offset unk_53ABE00
                push    ebx
                call    j_operator_new_safe
                xor     ecx, ecx
                add     esp, 8
                mov     edi, eax
                cmp     [esi+TStruct40.array_00.ItemCount], ecx
                jbe     short loc_195A60C

loc_195A5F7:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+9Aj
                lea     edx, [ecx+edi]
                test    edx, edx
                jz      short loc_195A606
                mov     eax, [esi+TStruct40.array_00.field_4]
                mov     al, [ecx+eax]
                mov     [edx], al

loc_195A606:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+8Cj
                inc     ecx
                cmp     ecx, [esi+TStruct40.array_00.ItemCount]
                jb      short loc_195A5F7

loc_195A60C:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+85j
                mov     eax, [esi+TStruct40.array_00.DataBuffer]
                push    eax
                mov     [esi+TStruct40.array_00.DataBuffer], edi
                mov     [esi+TStruct40.array_00.field_4], edi
                mov     [esi+TStruct40.array_00.ItemArray], edi
                mov     [esi+TStruct40.array_00.MaxItemCount], ebx
                call    operator_delete
                mov     edx, [ebp+dwDistance]
                mov     edi, [ebp+pThis]
                add     esp, 4
                mov     ebx, 1

loc_195A62D:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+56j
                mov     eax, [esi+TStruct40.array_00.field_4]
                add     eax, [esi+TStruct40.array_00.ItemCount]
                jz      short loc_195A63A
                mov     cl, [edx+edi]
                mov     [eax], cl

loc_195A63A:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+C3j
                add     [esi+TStruct40.CharIndex], ebx
                add     [esi+TStruct40.array_00.ItemCount], ebx
                mov     ecx, [esi+TStruct40.CharIndex]
                cmp     byte ptr [ecx+edi], 0
                mov     eax, [esi+TStruct40.array_00.ItemCount]
                jz      loc_195A806
                mov     edx, [ebp+pStruct1C]
                cmp     ecx, [edx+TMndxFindResult.cchSearchMask]
                jb      loc_195A5A0
                add     edi, ecx
                mov     edi, edi

loc_195A660:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+13Aj
                mov     ecx, [esi+TStruct40.array_00.MaxItemCount]
                inc     eax
                cmp     eax, ecx
                jbe     short loc_195A693
                mov     edx, eax
                shr     eax, 1
                cmp     ecx, eax
                jbe     short loc_195A68B
                cmp     ecx, 7FFFFFFFh
                jbe     short loc_195A688
                or      edx, 0FFFFFFFFh
                jmp     short loc_195A68B
; ---------------------------------------------------------------------------

loc_195A67D:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+41j
                                        ; TNameIndexStruct__CheckAndCopyNameFragment+16Bj
                pop     edi
                pop     esi
                xor     al, al
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    8
; ---------------------------------------------------------------------------

loc_195A688:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+106j
                lea     edx, [ecx+ecx]

loc_195A68B:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+FEj
                                        ; TNameIndexStruct__CheckAndCopyNameFragment+10Bj
                push    edx
                mov     ecx, esi
                call    TGenericArray__SetMaxItems_BYTE

loc_195A693:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+F6j
                mov     eax, [esi+TStruct40.array_00.field_4]
                add     eax, [esi+TStruct40.array_00.ItemCount]
                jz      short loc_195A69F
                mov     cl, [edi]
                mov     [eax], cl

loc_195A69F:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+129j
                add     [esi+TStruct40.array_00.ItemCount], ebx
                mov     eax, [esi+TStruct40.array_00.ItemCount]
                add     edi, ebx
                cmp     byte ptr [edi], 0
                jnz     short loc_195A660
                pop     edi
                pop     esi
                mov     al, 1
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    8
; ---------------------------------------------------------------------------

loc_195A6B7:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+18j
                mov     ebx, [ebp+dwDistance]
                lea     ebx, [ebx+0]

loc_195A6C0:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+231j
                mov     edi, [edx+TNameIndexStruct.NameFragments.ItemArray]
                mov     eax, [ebp+pStruct1C]
                mov     ecx, [esi+TStruct40.CharIndex]
                mov     eax, [eax]
                add     edi, ebx
                mov     [ebp+var_4], edx
                mov     dl, [edi]
                cmp     dl, [ecx+eax]
                mov     edx, [ebp+var_4]
                mov     [ebp+var_C], edi
                jnz     short loc_195A67D
                mov     eax, [esi+TStruct40.array_00.ItemCount]
                mov     ecx, [esi+TStruct40.array_00.MaxItemCount]
                inc     eax
                cmp     eax, ecx
                jbe     short loc_195A752
                mov     [ebp+var_4], eax
                shr     eax, 1
                cmp     ecx, eax
                jbe     short loc_195A707
                cmp     ecx, 7FFFFFFFh
                jbe     short loc_195A702
                mov     [ebp+var_4], 0FFFFFFFFh
                jmp     short loc_195A707
; ---------------------------------------------------------------------------

loc_195A702:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+187j
                add     ecx, ecx
                mov     [ebp+var_4], ecx

loc_195A707:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+17Fj
                                        ; TNameIndexStruct__CheckAndCopyNameFragment+190j
                mov     edx, [ebp+var_4]
                push    offset unk_53ABE00
                push    edx
                call    j_operator_new_safe
                xor     ecx, ecx
                add     esp, 8
                mov     edi, eax
                cmp     [esi+TStruct40.array_00.ItemCount], ecx
                jbe     short loc_195A736

loc_195A721:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+1C4j
                lea     edx, [ecx+edi]
                test    edx, edx
                jz      short loc_195A730
                mov     eax, [esi+TStruct40.array_00.field_4]
                mov     al, [ecx+eax]
                mov     [edx], al

loc_195A730:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+1B6j
                inc     ecx
                cmp     ecx, [esi+TStruct40.array_00.ItemCount]
                jb      short loc_195A721

loc_195A736:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+1AFj
                mov     eax, [esi+TStruct40.array_00.DataBuffer]
                mov     ecx, [ebp+var_4]
                push    eax
                mov     [esi+TStruct40.array_00.DataBuffer], edi
                mov     [esi+TStruct40.array_00.field_4], edi
                mov     [esi+TStruct40.array_00.ItemArray], edi
                mov     [esi+TStruct40.array_00.MaxItemCount], ecx
                call    operator_delete
                mov     edx, [ebp+pThis]
                add     esp, 4

loc_195A752:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+176j
                mov     edi, [esi+TStruct40.array_00.field_4]
                add     edi, [esi+TStruct40.array_00.ItemCount]
                jz      short loc_195A761
                mov     eax, [ebp+var_C]
                mov     cl, [eax]
                mov     [edi], cl

loc_195A761:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+1E8j
                mov     ecx, 1
                add     [esi+TStruct40.array_00.ItemCount], ecx
                add     [esi+TStruct40.CharIndex], ecx
                mov     edx, [edx+20h]
                mov     eax, [esi+TStruct40.array_00.ItemCount]
                mov     ecx, ebx
                mov     edi, ebx
                and     ecx, 1Fh
                mov     ebx, 1
                shl     ebx, cl
                shr     edi, 5
                mov     ecx, [edx+edi*4]
                and     ecx, ebx
                mov     ebx, [ebp+dwDistance]
                inc     ebx
                mov     [ebp+dwDistance], ebx
                test    ecx, ecx
                jnz     short loc_195A806
                mov     ecx, [esi+TStruct40.CharIndex]
                mov     edx, [ebp+pStruct1C]
                cmp     ecx, [edx+4]
                jnb     short loc_195A7A6
                mov     edx, [ebp+pThis]
                jmp     loc_195A6C0
; ---------------------------------------------------------------------------

loc_195A7A6:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+22Cj
                                        ; TNameIndexStruct__CheckAndCopyNameFragment+294j
                mov     ecx, [ebp+pThis]
                mov     edi, [ecx+8]
                mov     ecx, [esi+TStruct40.array_00.MaxItemCount]
                inc     eax
                cmp     eax, ecx
                jbe     short loc_195A7D4
                mov     edx, eax
                shr     eax, 1
                cmp     ecx, eax
                jbe     short loc_195A7CC
                cmp     ecx, 7FFFFFFFh
                jbe     short loc_195A7C9
                or      edx, 0FFFFFFFFh
                jmp     short loc_195A7CC
; ---------------------------------------------------------------------------

loc_195A7C9:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+252j
                lea     edx, [ecx+ecx]

loc_195A7CC:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+24Aj
                                        ; TNameIndexStruct__CheckAndCopyNameFragment+257j
                push    edx
                mov     ecx, esi
                call    TGenericArray__SetMaxItems_BYTE

loc_195A7D4:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+242j
                mov     eax, [esi+TStruct40.array_00.field_4]
                add     eax, [esi+TStruct40.array_00.ItemCount]
                jz      short loc_195A7E1
                mov     dl, [edi+ebx]
                mov     [eax], dl

loc_195A7E1:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+26Aj
                inc     [esi+TStruct40.array_00.ItemCount]
                mov     edi, [ebp+pThis]
                mov     edi, [edi+20h]
                mov     eax, [esi+TStruct40.array_00.ItemCount]
                mov     ecx, ebx
                and     ecx, 1Fh
                mov     edx, 1
                shl     edx, cl
                mov     ecx, ebx
                shr     ecx, 5
                inc     ebx
                and     edx, [edi+ecx*4]
                test    edx, edx
                jz      short loc_195A7A6

loc_195A806:                            ; CODE XREF: TNameIndexStruct__CheckAndCopyNameFragment+DAj
                                        ; TNameIndexStruct__CheckAndCopyNameFragment+221j
                pop     edi
                pop     esi
                mov     al, 1
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    8
TNameIndexStruct__CheckAndCopyNameFragment     endp

; =============== S U B R O U T I N E =======================================

; Attributes: bp-based frame

sub_1959010     proc near               ; CODE XREF: TArchiveDatabase__sub_1958B00+67p
                                        ; TArchiveDatabase__sub_1958B00+1CFp ...

pFragmentInfo   = dword ptr -0Ch
var_8           = dword ptr -8
var_1           = byte ptr -1
pStruct1C       = dword ptr  8
arg_4           = dword ptr  0Ch

                push    ebp
                mov     ebp, esp
                mov     eax, [ebp+pStruct1C]
                sub     esp, 0Ch
                push    ebx
                push    esi
                mov     esi, [eax+TMndxFindResult.pStruct40]
                push    edi
                mov     edi, ecx
                mov     ecx, [ebp+arg_4]

loc_1959024:                            ; CODE XREF: sub_1959010+2CEj
                mov     eax, [edi+TFileNameDatabase.NameFragIndexMask]
                and     eax, ecx
                lea     ebx, [eax+eax*2]
                mov     eax, [edi+TFileNameDatabase.NameFragTable.ItemArray]
                add     ebx, ebx
                add     ebx, ebx
                add     eax, ebx
                mov     [ebp+pFragmentInfo], ebx
                cmp     ecx, [eax+NAME_ENTRY.NextHashModifier]
                jnz     loc_1959147
                mov     edx, [eax+NAME_ENTRY.FragmentOffset]
                mov     ecx, edx
                and     ecx, 0FFFFFF00h
                cmp     ecx, 0FFFFFF00h
                jz      short loc_1959092
                mov     ecx, [edi+TFileNameDatabase.NextDB.pDatabase]
                push    edx
                test    ecx, ecx
                jz      short loc_1959070
                mov     edx, [ebp+pStruct1C]
                push    edx
                call    sub_1959010
                jmp     short loc_195907F
; ---------------------------------------------------------------------------

loc_1959070:                            ; CODE XREF: sub_1959010+53j
                mov     eax, [ebp+pStruct1C]
                push    eax
                lea     ecx, [edi+TFileNameDatabase.IndexStruct_174]
                call    TNameIndexStruct__CheckAndCopyNameFragment

loc_195907F:                            ; CODE XREF: sub_1959010+5Ej
                test    al, al
                jnz     loc_195912E

loc_1959087:                            ; CODE XREF: sub_1959010+90j
                                        ; sub_1959010+1F3j ...
                pop     edi
                pop     esi
                xor     al, al
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    8
; ---------------------------------------------------------------------------

loc_1959092:                            ; CODE XREF: sub_1959010+48j
                mov     ecx, [ebp+pStruct1C]
                mov     eax, [ecx+TMndxFindResult.szSearchMask]
                mov     ecx, [esi+TStruct40.CharIndex]
                mov     byte ptr [ebp+arg_4+3], dl
                cmp     dl, [eax+ecx]
                jnz     short loc_1959087
                mov     eax, [esi+TStruct40.array_00.ItemCount]
                mov     ecx, [esi+TStruct40.array_00.MaxItemCount]
                inc     eax
                cmp     eax, ecx
                jbe     short loc_1959119
                mov     [ebp+var_8], eax
                shr     eax, 1
                cmp     ecx, eax
                jbe     short loc_19590CD
                cmp     ecx, 7FFFFFFFh
                jbe     short loc_19590C7
                mov     [ebp+var_8], 0FFFFFFFFh
                jmp     short loc_19590CD
; ---------------------------------------------------------------------------

loc_19590C7:                            ; CODE XREF: sub_1959010+ACj
                lea     edx, [ecx+ecx]
                mov     [ebp+var_8], edx

loc_19590CD:                            ; CODE XREF: sub_1959010+A4j
                                        ; sub_1959010+B5j
                mov     eax, [ebp+var_8]
                push    offset unk_53ABE00
                push    eax
                call    j_operator_new_safe
                xor     ecx, ecx
                add     esp, 8
                cmp     [esi+TStruct40.array_00.ItemCount], ecx
                jbe     short loc_19590FD

loc_19590E5:                            ; CODE XREF: sub_1959010+EBj
                lea     edx, [ecx+eax]
                test    edx, edx
                jz      short loc_19590F7
                mov     ebx, [esi+TStruct40.array_00.field_4]
                mov     bl, [ecx+ebx]
                mov     [edx], bl
                mov     ebx, [ebp+pFragmentInfo]

loc_19590F7:                            ; CODE XREF: sub_1959010+DAj
                inc     ecx
                cmp     ecx, [esi+TStruct40.array_00.ItemCount]
                jb      short loc_19590E5

loc_19590FD:                            ; CODE XREF: sub_1959010+D3j
                mov     ecx, [esi+TStruct40.array_00.DataBuffer]
                mov     edx, [ebp+var_8]
                push    ecx
                mov     [esi+TStruct40.array_00.DataBuffer], eax
                mov     [esi+TStruct40.array_00.field_4], eax
                mov     [esi+TStruct40.array_00.ItemArray], eax
                mov     [esi+TStruct40.array_00.MaxItemCount], edx
                call    operator_delete
                mov     dl, byte ptr [ebp+arg_4+3]
                add     esp, 4

loc_1959119:                            ; CODE XREF: sub_1959010+9Bj
                mov     eax, [esi+TStruct40.array_00.field_4]
                add     eax, [esi+TStruct40.array_00.ItemCount]
                jz      short loc_1959123
                mov     [eax], dl

loc_1959123:                            ; CODE XREF: sub_1959010+10Fj
                mov     eax, 1
                add     [esi+TStruct40.array_00.ItemCount], eax
                add     [esi+TStruct40.CharIndex], eax

loc_195912E:                            ; CODE XREF: sub_1959010+71j
                mov     eax, [edi+TFileNameDatabase.NameFragTable.ItemArray]
                mov     ecx, [ebx+eax]
                mov     [ebp+arg_4], ecx
                test    ecx, ecx
                jz      loc_19592ED
                jmp     loc_19592D5
; ---------------------------------------------------------------------------

loc_1959147:                            ; CODE XREF: sub_1959010+31j
                mov     eax, [edi+TFileNameDatabase.Struct68_D0.ItemIsPresent.ItemArray]
                mov     edx, ecx
                and     ecx, 1Fh
                mov     ebx, 1
                shl     ebx, cl
                shr     edx, 5
                test    [eax+edx*4], ebx
                mov     eax, [ebp+arg_4]
                jz      loc_195920E
                mov     ebx, [edi+TFileNameDatabase.FrgmDist_LoBits.ItemArray]
                push    eax
                lea     ecx, [edi+TFileNameDatabase.Struct68_D0]
                add     ebx, eax
                call    TSparseArray__GetItemValue
                mov     ecx, [edi+TFileNameDatabase.FrgmDist_HiBits.BitsPerEntry]
                imul    ecx, eax
                mov     eax, ecx
                and     ecx, 1Fh
                mov     edx, ecx
                mov     ecx, [edi+TFileNameDatabase.FrgmDist_HiBits.BitsPerEntry]
                add     ecx, edx
                shr     eax, 5
                cmp     ecx, 20h
                mov     ecx, [edi+TFileNameDatabase.FrgmDist_HiBits.ItemArray]
                ja      short loc_19591AB
                mov     eax, [ecx+eax*4]
                mov     ecx, edx
                shr     eax, cl
                jmp     short loc_19591CE
; ---------------------------------------------------------------------------

loc_19591AB:                            ; CODE XREF: sub_1959010+190j
                lea     eax, [ecx+eax*4]
                mov     [ebp+pFragmentInfo], eax
                mov     eax, [eax+4]
                mov     ecx, 20h
                sub     ecx, edx
                shl     eax, cl
                mov     ecx, [ebp+pFragmentInfo]
                mov     ecx, [ecx]
                mov     [ebp+pFragmentInfo], ecx
                mov     ecx, edx
                mov     edx, [ebp+pFragmentInfo]
                shr     edx, cl
                or      eax, edx

loc_19591CE:                            ; CODE XREF: sub_1959010+199j
                and     eax, [edi+TFileNameDatabase.FrgmDist_HiBits.EntryBitMask]
                movzx   edx, byte ptr [ebx]
                mov     ecx, [edi+TFileNameDatabase.NextDB.pDatabase]
                shl     eax, 8
                or      eax, edx
                push    eax
                test    ecx, ecx
                jz      short loc_19591F2
                mov     eax, [ebp+pStruct1C]
                push    eax
                call    sub_1959010
                jmp     short loc_1959201
; ---------------------------------------------------------------------------

loc_19591F2:                            ; CODE XREF: sub_1959010+1D5j
                mov     ecx, [ebp+pStruct1C]
                push    ecx
                lea     ecx, [edi+TFileNameDatabase.IndexStruct_174]
                call    TNameIndexStruct__CheckAndCopyNameFragment

loc_1959201:                            ; CODE XREF: sub_1959010+1E0j
                test    al, al
                jz      loc_1959087
                jmp     loc_19592B6
; ---------------------------------------------------------------------------

loc_195920E:                            ; CODE XREF: sub_1959010+152j
                mov     edx, [edi+TFileNameDatabase.FrgmDist_LoBits.ItemArray]
                mov     dl, [eax+edx]
                mov     ecx, [ebp+pStruct1C]
                mov     eax, [ecx+TMndxFindResult.szSearchMask]
                mov     ecx, [esi+TStruct40.CharIndex]
                mov     [ebp+var_1], dl
                cmp     dl, [eax+ecx]
                jnz     loc_1959087
                mov     eax, [esi+TStruct40.array_00.ItemCount]
                mov     ecx, [esi+TStruct40.array_00.MaxItemCount]
                inc     eax
                cmp     eax, ecx
                jbe     short loc_19592A1
                mov     ebx, eax
                shr     eax, 1
                mov     [ebp+var_8], ebx
                cmp     ecx, eax
                jbe     short loc_1959254
                cmp     ecx, 7FFFFFFFh
                jbe     short loc_195924E
                or      ebx, 0FFFFFFFFh
                jmp     short loc_1959251
; ---------------------------------------------------------------------------

loc_195924E:                            ; CODE XREF: sub_1959010+237j
                lea     ebx, [ecx+ecx]

loc_1959251:                            ; CODE XREF: sub_1959010+23Cj
                mov     [ebp+var_8], ebx

loc_1959254:                            ; CODE XREF: sub_1959010+22Fj
                push    offset unk_53ABE00
                push    ebx
                call    j_operator_new_safe
                xor     ecx, ecx
                add     esp, 8
                cmp     [esi+TStruct40.array_00.ItemCount], ecx
                jbe     short loc_1959288
                lea     esp, [esp+0]

loc_1959270:                            ; CODE XREF: sub_1959010+273j
                lea     edx, [ecx+eax]
                test    edx, edx
                jz      short loc_195927F
                mov     ebx, [esi+TStruct40.array_00.field_4]
                mov     bl, [ecx+ebx]
                mov     [edx], bl

loc_195927F:                            ; CODE XREF: sub_1959010+265j
                inc     ecx
                cmp     ecx, [esi+TStruct40.array_00.ItemCount]
                jb      short loc_1959270
                mov     ebx, [ebp+var_8]

loc_1959288:                            ; CODE XREF: sub_1959010+257j
                mov     ecx, [esi+TStruct40.array_00.DataBuffer]
                push    ecx
                mov     [esi+TStruct40.array_00.DataBuffer], eax
                mov     [esi+TStruct40.array_00.field_4], eax
                mov     [esi+TStruct40.array_00.ItemArray], eax
                mov     [esi+TStruct40.array_00.MaxItemCount], ebx
                call    operator_delete
                mov     dl, [ebp+var_1]
                add     esp, 4

loc_19592A1:                            ; CODE XREF: sub_1959010+224j
                mov     eax, [esi+TStruct40.array_00.field_4]
                add     eax, [esi+TStruct40.array_00.ItemCount]
                jz      short loc_19592AB
                mov     [eax], dl

loc_19592AB:                            ; CODE XREF: sub_1959010+297j
                mov     eax, 1
                add     [esi+TStruct40.array_00.ItemCount], eax
                add     [esi+TStruct40.CharIndex], eax

loc_19592B6:                            ; CODE XREF: sub_1959010+1F9j
                mov     ebx, [ebp+arg_4]
                cmp     ebx, [edi+TFileNameDatabase.field_214]
                jbe     short loc_19592ED
                push    ebx
                mov     ecx, edi
                call    sub_1959F50
                or      edx, 0FFFFFFFFh
                sub     edx, ebx
                add     eax, edx
                mov     ecx, eax
                mov     [ebp+arg_4], eax

loc_19592D5:                            ; CODE XREF: sub_1959010+132j
                mov     edx, [esi+TStruct40.CharIndex]
                mov     eax, [ebp+pStruct1C]
                cmp     edx, [eax+TMndxFindResult.cchSearchMask]
                jb      loc_1959024
                push    ecx
                push    eax
                mov     ecx, edi
                call    sub_1958D70

loc_19592ED:                            ; CODE XREF: sub_1959010+12Cj
                                        ; sub_1959010+2AFj
                pop     edi
                pop     esi
                mov     al, 1
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    8
sub_1959010     endp

; =============== S U B R O U T I N E =======================================

; Attributes: bp-based frame

sub_19582E0     proc near               ; CODE XREF: TFileNameDatabase__sub_1958B00+253p

arg_0           = dword ptr  8

                push    ebp
                mov     ebp, esp
                push    esi
                mov     esi, ecx
                mov     eax, [esi+0Ch]
                mov     ecx, [esi+10h]
                inc     eax
                cmp     eax, ecx
                jbe     short loc_1958311
                mov     edx, eax
                shr     eax, 1
                cmp     ecx, eax
                jbe     short loc_1958309
                cmp     ecx, 7FFFFFFFh
                jbe     short loc_1958306
                or      edx, 0FFFFFFFFh
                jmp     short loc_1958309
; ---------------------------------------------------------------------------

loc_1958306:                            ; CODE XREF: sub_19582E0+1Fj
                lea     edx, [ecx+ecx]

loc_1958309:                            ; CODE XREF: sub_19582E0+17j
                                        ; sub_19582E0+24j
                push    edx
                mov     ecx, esi
                call    TGenericArray__SetMaxItems_BYTE

loc_1958311:                            ; CODE XREF: sub_19582E0+Fj
                mov     eax, [esi+4]
                add     eax, [esi+0Ch]
                jz      short loc_1958320
                mov     ecx, [ebp+arg_0]
                mov     dl, [ecx]
                mov     [eax], dl

loc_1958320:                            ; CODE XREF: sub_19582E0+37j
                inc     dword ptr [esi+0Ch]
                pop     esi
                pop     ebp
                retn    4
sub_19582E0     endp

; =============== S U B R O U T I N E =======================================

; Attributes: bp-based frame

TFileNameDatabase__sub_1958B00 proc near ; CODE XREF: TFileNameDatabase__sub_1959460+3Bp

var_C           = dword ptr -0Ch
ItemArrayOffset = dword ptr -8
var_4           = dword ptr -4
arg_0           = dword ptr  8

                push    ebp
                mov     ebp, esp
                sub     esp, 0Ch
                mov     edx, [ebp+pStruct1C]
                push    ebx
                mov     ebx, [edx+TMndxFindResult.szSearchMask]
                push    esi
                push    edi
                mov     edi, [edx+TMndxFindResult.pStruct40]
                mov     eax, [edi+TStruct40.CharIndex]
                movzx   eax, byte ptr [eax+ebx]
                mov     esi, ecx
                mov     ecx, [edi+TStruct40.HashValue]
                mov     ebx, ecx
                shl     ebx, 5
                xor     eax, ebx
                mov     ebx, [esi+TFileNameDatabase.NameFragTable.ItemArray]
                xor     eax, ecx
                and     eax, [esi+TFileNameDatabase.NameFragIndexMask]
                lea     eax, [eax+eax*2]
                add     eax, eax
                add     eax, eax
                mov     [ebp+ItemArrayOffset], eax
                cmp     ecx, [eax+ebx]
                jnz     loc_1958BE5
                mov     ecx, [eax+ebx+NAME_ENTRY.FragmentOffset]
                mov     ebx, ecx
                and     ebx, 0FFFFFF00h
                cmp     ebx, 0FFFFFF00h
                jz      short loc_1958B88
                mov     eax, [esi+TFileNameDatabase.NextDB.pDatabase]
                push    ecx
                push    edx
                test    eax, eax
                jz      short loc_1958B6E
                mov     ecx, eax
                call    sub_1959010
                jmp     short loc_1958B79
; ---------------------------------------------------------------------------

loc_1958B6E:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+63j
                lea     ecx, [esi+TFileNameDatabase.IndexStruct_174]
                call    TNameIndexStruct__CheckAndCopyNameFragment

loc_1958B79:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+6Cj
                test    al, al
                jnz     short loc_1958BCA

loc_1958B7D:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+108j
                                        ; TArchiveDatabase__sub_1958B00+1F3j
                pop     edi
                pop     esi
                xor     al, al
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    4
; ---------------------------------------------------------------------------

loc_1958B88:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+57j
                mov     eax, [edi+TStruct40.array_00.ItemCount]
                mov     bl, cl
                mov     ecx, [edi+TStruct40.array_00.MaxItemCount]
                inc     eax
                cmp     eax, ecx
                jbe     short loc_1958BB5
                mov     edx, eax
                shr     eax, 1
                cmp     ecx, eax
                jbe     short loc_1958BAD
                cmp     ecx, 7FFFFFFFh
                jbe     short loc_1958BAA
                or      edx, 0FFFFFFFFh
                jmp     short loc_1958BAD
; ---------------------------------------------------------------------------

loc_1958BAA:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+A3j
                lea     edx, [ecx+ecx]

loc_1958BAD:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+9Bj
                                        ; TArchiveDatabase__sub_1958B00+A8j
                push    edx
                mov     ecx, edi
                call    TGenericArray__SetMaxItems_BYTE

loc_1958BB5:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+93j
                mov     eax, [edi+TStruct40.array_00.field_4]
                add     eax, [edi+TStruct40.array_00.ItemCount]
                jz      short loc_1958BBF
                mov     [eax], bl

loc_1958BBF:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+BBj
                mov     eax, 1
                add     [edi+TStruct40.array_00.ItemCount], eax
                add     [edi+TStruct40.CharIndex], eax

loc_1958BCA:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+7Bj
                mov     ecx, [esi+TFileNameDatabase.NameFragTable.ItemArray]
                mov     edx, [ebp+ItemArrayOffset]
                mov     eax, [ecx+edx+NAME_ENTRY.NextHashModifier]
                mov     [edi+TStruct40.HashValue], eax

loc_1958BDA:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+1E7j
                pop     edi
                pop     esi
                mov     al, 1
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    4
; ---------------------------------------------------------------------------

loc_1958BE5:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+3Fj
                push    ecx
                mov     ecx, esi
                call    TArchiveDatabase__sub_1959CB0
                mov     ebx, [esi+TFileNameDatabase.Struct68_00.ItemIsPresent.ItemArray]
                inc     eax
                mov     ecx, eax
                and     ecx, 1Fh
                mov     edx, 1
                shl     edx, cl
                mov     ecx, eax
                shr     ecx, 5
                mov     [ebp+ItemArrayOffset], eax
                test    [ebx+ecx*4], edx
                jz      loc_1958B7D
                sub     eax, [edi+TStruct40.HashValue]
                mov     [ebp+var_4], 0FFFFFFFFh
                dec     eax
                mov     [edi+TStruct40.HashValue], eax
                lea     esp, [esp+0]

loc_1958C20:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+230j
                mov     eax, [edi+TStruct40.HashValue]
                mov     ebx, [esi+TFileNameDatabase.Struct68_D0.ItemIsPresent.ItemArray]
                mov     ecx, eax
                and     ecx, 1Fh
                mov     edx, 1
                shl     edx, cl
                mov     ecx, eax
                shr     ecx, 5
                test    [ebx+ecx*4], edx
                jz      loc_1958CFB
                mov     ecx, [ebp+var_4]
                cmp     ecx, 0FFFFFFFFh
                jnz     short loc_1958C5E
                push    eax
                lea     ecx, [esi+TFileNameDatabase.Struct68_D0]
                call    TSparseArray__GetItemValue
                mov     ecx, eax
                mov     [ebp+var_4], eax
                jmp     short loc_1958C62
; ---------------------------------------------------------------------------

loc_1958C5E:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+149j
                inc     ecx
                mov     [ebp+var_4], ecx

loc_1958C62:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+15Cj
                mov     edx, [edi+TStruct40.CharIndex]
                mov     [ebp+var_C], edx
                mov     edx, [esi+TFileNameDatabase.FrgmDist_HiBits.BitsPerEntry]
                mov     eax, edx
                imul    eax, ecx
                mov     ecx, eax
                and     eax, 1Fh
                add     edx, eax
                shr     ecx, 5
                cmp     edx, 20h
                mov     edx, [esi+TFileNameDatabase.FrgmDist_HiBits.ItemArray]
                ja      short loc_1958C91
                mov     edx, [edx+ecx*4]
                mov     ecx, eax
                shr     edx, cl
                jmp     short loc_1958CA8
; ---------------------------------------------------------------------------

loc_1958C91:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+186j
                lea     ebx, [edx+ecx*4]
                mov     edx, [ebx+4]
                mov     ebx, [ebx]
                mov     ecx, 20h
                sub     ecx, eax
                shl     edx, cl
                mov     ecx, eax
                shr     ebx, cl
                or      edx, ebx

loc_1958CA8:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+18Fj
                mov     ecx, [esi+TFileNameDatabase.FrgmDist_LoBits.ItemArray]
                and     edx, [esi+TFileNameDatabase.FrgmDist_HiBits.EntryBitMask]
                mov     eax, [edi+TStruct40.HashValue]
                movzx   eax, byte ptr [ecx+eax]
                mov     ecx, [esi+TFileNameDatabase.NextDB.pDatabase]
                shl     edx, 8
                or      eax, edx
                push    eax
                test    ecx, ecx
                jz      short loc_1958CD6
                mov     edx, [ebp+pStruct1C]
                push    edx
                call    sub_1959010
                jmp     short loc_1958CE5
; ---------------------------------------------------------------------------

loc_1958CD6:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+1C9j
                mov     eax, [ebp+pStruct1C]
                push    eax
                lea     ecx, [esi+TFileNameDatabase.IndexStruct_174]
                call    TNameIndexStruct__CheckAndCopyNameFragment

loc_1958CE5:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+1D4j
                test    al, al
                jnz     loc_1958BDA
                mov     ecx, [ebp+var_C]
                cmp     [edi+TStruct40.CharIndex], ecx
                jnz     loc_1958B7D
                jmp     short loc_1958D11
; ---------------------------------------------------------------------------

loc_1958CFB:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+13Dj
                mov     edx, [esi+TFileNameDatabase.FrgmDist_LoBits.ItemArray]
                mov     ebx, [ebp+pStruct1C]
                mov     ecx, [edi+TStruct40.CharIndex]
                mov     ebx, [ebx+TMndxFindResult.szSearchMask]
                mov     dl, [eax+edx]
                cmp     dl, [ecx+ebx]
                jz      short loc_1958D41

loc_1958D11:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+1F9j
                mov     eax, [ebp+ItemArrayOffset]
                inc     [edi+TStruct40.HashValue]
                inc     eax
                mov     ecx, eax
                and     ecx, 1Fh
                mov     edx, 1
                shl     edx, cl
                mov     ecx, [esi+TFileNameDatabase.Struct68_00.ItemIsPresent.ItemArray]
                mov     [ebp+ItemArrayOffset], eax
                shr     eax, 5
                test    [ecx+eax*4], edx
                jnz     loc_1958C20
                pop     edi
                pop     esi
                xor     al, al
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    4
; ---------------------------------------------------------------------------

loc_1958D41:                            ; CODE XREF: TArchiveDatabase__sub_1958B00+20Fj
                mov     edx, [esi+TFileNameDatabase.FrgmDist_LoBits.ItemArray]
                mov     cl, [edx+eax]
                lea     edx, [ebp+pStruct1C+3]
                mov     byte ptr [ebp+pStruct1C+3], cl
                push    edx
                mov     ecx, edi
                call    sub_19582E0
                mov     eax, 1
                add     [edi+TStruct40.CharIndex], eax
                pop     edi
                pop     esi
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    4
TFileNameDatabase__sub_1958B00 endp

; =============== S U B R O U T I N E =======================================

; Attributes: bp-based frame

TFileNameDatabase__sub_1959460 proc near ; CODE XREF: TFileNameDatabasePtr__sub_1956CE0+2Dp

Struct14        = dword ptr -20h
var_1C          = dword ptr -1Ch
var_18          = dword ptr -18h
var_14          = dword ptr -14h
var_10          = dword ptr -10h
pStruct14       = dword ptr -0Ch
pThis           = dword ptr -8
OneChar         = byte ptr -1
pStruct1C       = dword ptr  8

                push    ebp
                mov     ebp, esp
                sub     esp, 20h
                push    ebx
                push    esi
                push    edi
                mov     edi, [ebp+pStruct1C]
                mov     esi, [edi+TMndxFindResult.pStruct40]
                mov     eax, [esi+TStruct40.SearchPhase]
                mov     ebx, ecx
                mov     [ebp+pThis], ebx
                cmp     eax, 4
                jz      return_false
                cmp     eax, 2
                jz      loc_1959530
                mov     ecx, esi
                call    TStruct40__InitSearchBuffers
                mov     eax, [esi+TStruct40.CharIndex]
                cmp     eax, [edi+TMndxFindResult.cchSearchMask]
                jnb     short loc_19594B0

loc_1959498:                            ; CODE XREF: TFileNameDatabase__sub_1959460+4Ej
                push    edi
                mov     ecx, ebx
                call    TFileNameDatabase__sub_1958B00
                test    al, al
                jz      loc_1959778
                mov     ecx, [esi+TStruct40.CharIndex]
                cmp     ecx, [edi+TMndxFindResult.cchSearchMask]
                jb      short loc_1959498

loc_19594B0:                            ; CODE XREF: TFileNameDatabase__sub_1959460+36j
                mov     edx, [esi+TStruct40.HashValue]
                or      eax, 0FFFFFFFFh
                mov     [ebp+Struct14], edx
                mov     [ebp+var_14], eax
                mov     [ebp+var_10], eax
                mov     eax, [esi+TStruct40.array_00.ItemCount]
                lea     edx, [ebp+Struct14]
                lea     ecx, [esi+TStruct40.array_18]
                push    edx
                mov     [ebp+var_1C], 0
                mov     [ebp+var_18], eax
                call    TGenericArray__InsertItem_STRUCT14
                mov     ecx, [esi+TStruct40.HashValue]
                mov     eax, ecx
                and     ecx, 1Fh
                mov     edi, 1
                shl     edi, cl
                mov     [esi+TStruct40.ItemCount], 1
                mov     edx, [ebx+TFileNameDatabase.FileNameIndexes.ItemIsPresent.ItemArray]
                shr     eax, 5
                test    [edx+eax*4], edi
                jz      short loc_1959530
                mov     ecx, [esi+TStruct40.array_00.field_4]
                mov     eax, [esi+TStruct40.array_00.ItemCount]
                mov     edi, [ebp+pStruct1C]
                mov     [edi+TMndxFindResult.szFoundPath], ecx
                mov     [edi+TMndxFindResult.cchFoundPath], eax
                mov     esi, [esi+TStruct40.HashValue]
                push    esi
                lea     ecx, [ebx+TFileNameDatabase.FileNameIndexes]
                call    TSparseArray__GetItemValue
                mov     [edi+TMndxFindResult.FileNameIndex], eax
                pop     edi
                pop     esi
                mov     al, 1
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    4
; ---------------------------------------------------------------------------

loc_1959522:                            ; CODE XREF: TFileNameDatabase__sub_1959460+26Bj
                                        ; TFileNameDatabase__sub_1959460+2D9j ...
                mov     ebx, [ebp+pThis]
                jmp     short loc_1959530
; ---------------------------------------------------------------------------
                align 10h

loc_1959530:                            ; CODE XREF: TFileNameDatabase__sub_1959460+23j
                                        ; TFileNameDatabase__sub_1959460+97j ...
                mov     edx, [esi+TStruct40.ItemCount]
                cmp     edx, [esi+TStruct40.array_18.ItemCount]
                jnz     loc_19595BD
                mov     eax, [esi+TStruct40.array_18.ItemCount]
                mov     ecx, [esi+TStruct40.array_18.field_4]
                lea     eax, [eax+eax*4]
                lea     eax, [ecx+eax*4-14h]
                mov     [ebp+pStruct14], eax
                mov     eax, [eax+TStruct14.HashValue]
                push    eax
                mov     ecx, ebx
                call    TFileNameDatabase__sub_1959CB0
                mov     edx, [ebp+pStruct14]
                mov     ecx, [esi+TStruct40.array_18.ItemCount]
                inc     eax
                mov     ebx, eax
                sub     ebx, [edx+TStruct14.HashValue]
                mov     edx, [esi+TStruct40.array_18.MaxItemCount]
                inc     ecx
                dec     ebx
                mov     [ebp+var_1C], eax
                cmp     ecx, edx
                jbe     short loc_1959591
                mov     eax, ecx
                shr     ecx, 1
                cmp     edx, ecx
                jbe     short loc_1959585
                mov     eax, 0CCCCCCCh
                cmp     edx, 6666666h
                ja      short loc_1959585
                lea     eax, [edx+edx]

loc_1959585:                            ; CODE XREF: TFileNameDatabase__sub_1959460+113j
                                        ; TFileNameDatabase__sub_1959460+120j
                push    eax
                lea     ecx, [esi+TStruct40.array_18]
                call    TGenericArray__SetMaxItems_STRUCT14
                mov     eax, [ebp+var_1C]

loc_1959591:                            ; CODE XREF: TFileNameDatabase__sub_1959460+10Bj
                mov     ecx, [esi+TStruct40.array_18.ItemCount]
                mov     edx, [esi+TStruct40.array_18.field_4]
                lea     ecx, [ecx+ecx*4]
                lea     ecx, [edx+ecx*4]
                test    ecx, ecx
                jz      short loc_19595B7
                mov     [ecx+TStruct14.HashValue], ebx
                mov     [ecx+TStruct14.field_4], eax
                xor     eax, eax
                mov     [ecx+TStruct14.field_8], eax
                or      eax, 0FFFFFFFFh
                mov     [ecx+TStruct14.field_C], eax
                or      eax, 0FFFFFFFFh
                mov     [ecx+TStruct14.field_10], eax

loc_19595B7:                            ; CODE XREF: TFileNameDatabase__sub_1959460+13Fj
                inc     [esi+TStruct40.array_18.ItemCount]
                mov     ebx, [ebp+pThis]

loc_19595BD:                            ; CODE XREF: TFileNameDatabase__sub_1959460+D6j
                mov     eax, [esi+TStruct40.ItemCount]
                mov     ecx, [esi+TStruct40.array_18.field_4]
                mov     ebx, [ebx+TFileNameDatabase.Struct68_00.ItemIsPresent.ItemArray]
                lea     eax, [eax+eax*4]
                lea     edi, [ecx+eax*4]
                mov     eax, [edi+TStruct14.field_4]
                mov     ecx, eax
                and     ecx, 1Fh
                mov     edx, 1
                shl     edx, cl
                mov     ecx, eax
                shr     ecx, 5
                test    [ebx+ecx*4], edx
                setnz   cl
                inc     eax
                mov     [edi+TStruct14.field_4], eax
                test    cl, cl
                jz      loc_19596E9
                inc     [esi+TStruct40.ItemCount]
                mov     ecx, [edi+TStruct14.HashValue]
                mov     eax, [ebp+pThis]
                mov     eax, [eax+TFileNameDatabase.Struct68_D0.ItemIsPresent.ItemArray]
                mov     edx, ecx
                and     ecx, 1Fh
                mov     ebx, 1
                shl     ebx, cl
                shr     edx, 5
                test    [eax+edx*4], ebx
                mov     ebx, [ebp+pThis]
                jz      short loc_1959665
                mov     eax, [edi+TStruct14.field_C]
                cmp     eax, 0FFFFFFFFh
                jnz     short loc_195962F
                mov     eax, [edi+TStruct14.HashValue]
                push    eax
                lea     ecx, [ebx+TFileNameDatabase.Struct68_D0]
                call    TSparseArray__GetItemValue
                jmp     short loc_1959630
; ---------------------------------------------------------------------------

loc_195962F:                            ; CODE XREF: TFileNameDatabase__sub_1959460+1BDj
                inc     eax

loc_1959630:                            ; CODE XREF: TFileNameDatabase__sub_1959460+1CDj
                mov     ecx, [edi+TStruct14.HashValue]
                push    eax
                push    ecx
                mov     ecx, ebx
                mov     [edi+TStruct14.field_C], eax
                call    sub_19573D0
                mov     ecx, [ebx+TFileNameDatabase.NextDB.pDatabase]
                push    eax
                test    ecx, ecx
                jz      short loc_1959654
                mov     edx, [ebp+pStruct1C]
                push    edx
                call    sub_1958D70
                jmp     short loc_19596AE
; ---------------------------------------------------------------------------

loc_1959654:                            ; CODE XREF: TFileNameDatabase__sub_1959460+1E7j
                mov     eax, [ebp+pStruct1C]
                push    eax
                lea     ecx, [ebx+TFileNameDatabase.IndexStruct_174]
                call    CopyNameFragment
                jmp     short loc_19596AE
; ---------------------------------------------------------------------------

loc_1959665:                            ; CODE XREF: TFileNameDatabase__sub_1959460+1B5j
                mov     ecx, [ebx+TFileNameDatabase.FrgmDist_LoBits.ItemArray]
                mov     eax, [edi+TStruct14.HashValue]
                mov     dl, [eax+ecx]
                mov     eax, [esi+TStruct40.array_00.ItemCount]
                mov     ecx, [esi+TStruct40.array_00.MaxItemCount]
                inc     eax
                mov     [ebp+OneChar], dl
                cmp     eax, ecx
                jbe     short loc_195969E
                mov     edx, eax
                shr     eax, 1
                cmp     ecx, eax
                jbe     short loc_1959696
                cmp     ecx, 7FFFFFFFh
                jbe     short loc_1959693
                or      edx, 0FFFFFFFFh
                jmp     short loc_1959696
; ---------------------------------------------------------------------------

loc_1959693:                            ; CODE XREF: TFileNameDatabase__sub_1959460+22Cj
                lea     edx, [ecx+ecx]

loc_1959696:                            ; CODE XREF: TFileNameDatabase__sub_1959460+224j
                                        ; TFileNameDatabase__sub_1959460+231j
                push    edx
                mov     ecx, esi
                call    TGenericArray__SetMaxItems_BYTE

loc_195969E:                            ; CODE XREF: TFileNameDatabase__sub_1959460+21Cj
                mov     eax, [esi+TStruct40.array_00.field_4]
                add     eax, [esi+TStruct40.array_00.ItemCount]
                jz      short loc_19596AB
                mov     cl, [ebp+OneChar]
                mov     [eax], cl

loc_19596AB:                            ; CODE XREF: TFileNameDatabase__sub_1959460+244j
                inc     [esi+TStruct40.array_00.ItemCount]

loc_19596AE:                            ; CODE XREF: TFileNameDatabase__sub_1959460+1F2j
                                        ; TFileNameDatabase__sub_1959460+203j
                mov     edx, [esi+TStruct40.array_00.ItemCount]
                mov     ecx, [edi+TStruct14.HashValue]
                mov     [edi+TStruct14.field_8], edx
                mov     edx, [ebx+TFileNameDatabase.FileNameIndexes.ItemIsPresent.ItemArray]
                mov     eax, ecx
                and     ecx, 1Fh
                mov     ebx, 1
                shl     ebx, cl
                shr     eax, 5
                test    [edx+eax*4], ebx
                jz      loc_1959522
                mov     eax, [edi+TStruct14.field_10]
                cmp     eax, 0FFFFFFFFh
                jnz     short loc_1959754
                mov     eax, [edi+TStruct14.HashValue]
                mov     ecx, [ebp+pThis]
                push    eax
                add     ecx, TFileNameDatabase.FileNameIndexes
                call    TSparseArray__GetItemValue
                jmp     short loc_1959755
; ---------------------------------------------------------------------------

loc_19596E9:                            ; CODE XREF: TFileNameDatabase__sub_1959460+18Cj
                mov     eax, [esi+TStruct40.ItemCount]
                cmp     eax, 1
                jz      loc_1959778
                mov     ecx, [esi+TStruct40.array_18.field_4]
                lea     eax, [eax+eax*4]
                inc     dword ptr [ecx+eax*4-14h]
                lea     eax, [ecx+eax*4-14h]
                mov     eax, [esi+TStruct40.ItemCount]
                lea     edx, [eax+eax*4]
                mov     eax, [esi+TStruct40.array_18.field_4]
                mov     edi, [eax+edx*4-20h]
                mov     eax, [esi+TStruct40.array_00.MaxItemCount]
                cmp     edi, eax
                jbe     short loc_1959749
                mov     edx, edi
                shr     edx, 1
                mov     ecx, edi
                cmp     eax, edx
                jbe     short loc_1959741
                cmp     eax, 7FFFFFFFh
                jbe     short loc_195973E
                or      ecx, 0FFFFFFFFh
                push    ecx
                mov     ecx, esi
                call    TGenericArray__SetMaxItems_BYTE
                dec     [esi+TStruct40.ItemCount]
                mov     [esi+TStruct40.array_00.ItemCount], edi
                jmp     loc_1959522
; ---------------------------------------------------------------------------

loc_195973E:                            ; CODE XREF: TFileNameDatabase__sub_1959460+2C6j
                lea     ecx, [eax+eax]

loc_1959741:                            ; CODE XREF: TFileNameDatabase__sub_1959460+2BFj
                push    ecx
                mov     ecx, esi
                call    TGenericArray__SetMaxItems_BYTE

loc_1959749:                            ; CODE XREF: TFileNameDatabase__sub_1959460+2B5j
                dec     [esi+TStruct40.ItemCount]
                mov     [esi+TStruct40.array_00.ItemCount], edi
                jmp     loc_1959522
; ---------------------------------------------------------------------------

loc_1959754:                            ; CODE XREF: TFileNameDatabase__sub_1959460+277j
                inc     eax

loc_1959755:                            ; CODE XREF: TFileNameDatabase__sub_1959460+287j
                mov     [edi+TStruct14.field_10], eax
                mov     ecx, [esi+TStruct40.array_00.ItemCount]
                mov     edx, [esi+TStruct40.array_00.field_4]
                mov     eax, [ebp+pStruct1C]
                mov     [eax+TMndxFindResult.szFoundPath], edx
                mov     [eax+TMndxFindResult.cchFoundPath], ecx
                mov     ecx, [edi+TStruct14.field_10]
                pop     edi
                pop     esi
                mov     [eax+TMndxFindResult.FileNameIndex], ecx
                mov     al, 1
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    4
; ---------------------------------------------------------------------------

loc_1959778:                            ; CODE XREF: TFileNameDatabase__sub_1959460+42j
                                        ; TFileNameDatabase__sub_1959460+28Fj
                mov     [esi+TStruct40.SearchPhase], 4

return_false:                           ; CODE XREF: TFileNameDatabase__sub_1959460+1Aj
                pop     edi
                pop     esi
                xor     al, al
                pop     ebx
                mov     esp, ebp
                pop     ebp
                retn    4
TFileNameDatabase__sub_1959460 endp

; ---------------------------------------------------------------------------

;------------------------------------------------------------------------------
; Public functions callable from C++

;
; DWORD _cdecl sub_19573D0_x86(TFileNameDatabase * pDB, DWORD arg_0, DWORD arg_4);
;

_sub_19573D0_x86 PROC

                push    ebp
                mov     ebp, esp
                mov     ecx, [ebp+8]    ; pDB
                push    [ebp+10h]       ; arg_4
                push    [ebp+0Ch]       ; arg_0
                call    sub_19573D0
                mov     esp, ebp
                pop     ebp
                ret

_sub_19573D0_x86 ENDP

;
; DWORD _cdecl sub_1957EF0_x86(TFileNameDatabase * pDB, TMndxFindResult * pStruct1C);
;

_sub_1957EF0_x86 PROC

                push    ebp
                mov     ebp, esp
                mov     ecx, [ebp+8]    ; pDB
                push    [ebp+0Ch]       ; pStruct1C
                call    TFileNameDatabase__FindFileInDatabase
                mov     esp, ebp
                pop     ebp
                ret

_sub_1957EF0_x86 ENDP

;
; bool _cdecl _sub_1959460_x86(TFileNameDatabase * pDB, TMndxFindResult * pStruct1C);
;

_sub_1959460_x86 PROC

                push    ebp
                mov     ebp, esp
                mov     ecx, [ebp+8]    ; pDB
                push    [ebp+0Ch]       ; pStruct1C
                call    TFileNameDatabase__sub_1959460
                mov     esp, ebp
                pop     ebp
                ret

_sub_1959460_x86 ENDP

;
; bool _cdecl sub_1958B00_x86(TFileNameDatabase * pDB, TMndxFindResult * pStruct1C);
;

_sub_1958B00_x86 PROC

                push    ebp
                mov     ebp, esp
                mov     ecx, [ebp+8]    ; pDB
                push    [ebp+0Ch]       ; pStruct1C
                call    TFileNameDatabase__sub_1959460
                mov     esp, ebp
                pop     ebp
                ret

_sub_1958B00_x86 ENDP

;
; DWORD _cdecl GetItemValue_x86(TSparseArray * pStruct, DWORD dwKey);
;

_GetItemValue_x86 PROC

                push    ebp
                mov     ebp, esp
                mov     ecx, [ebp+8]    ; pStruct68
                push    [ebp+0Ch]       ; dwKey
                call    TSparseArray__GetItemValue
                mov     esp, ebp
                pop     ebp
                ret

_GetItemValue_x86 ENDP

;
; DWORD _cdecl sub_1959CB0_x86(TFileNameDatabase * pDB, DWORD dwKey);
;

_sub_1959CB0_x86 PROC

                push    ebp
                mov     ebp, esp
                mov     ecx, [ebp+8]    ; pDB
                push    [ebp+0Ch]       ; dwKey
                call    TArchiveDatabase__sub_1959CB0
                mov     esp, ebp
                pop     ebp
                ret

_sub_1959CB0_x86 ENDP

;
; DWORD _cdecl sub_1959F50_x86(TFileNameDatabase * pDB, DWORD arg_0);
;

_sub_1959F50_x86 PROC

                push    ebp
                mov     ebp, esp
                mov     ecx, [ebp+8]    ; pDB
                push    [ebp+0Ch]       ; dwKey
                call    sub_1959F50
                mov     esp, ebp
                pop     ebp
                ret

_sub_1959F50_x86 ENDP

END
