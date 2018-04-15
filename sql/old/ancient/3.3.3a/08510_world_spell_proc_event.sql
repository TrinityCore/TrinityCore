UPDATE spell_proc_event SET SpellFamilyMask0 = SpellFamilyMask0 | 0x40000000, procEx = ProcEx | 0x0000001 WHERE entry IN(53569,53576);
