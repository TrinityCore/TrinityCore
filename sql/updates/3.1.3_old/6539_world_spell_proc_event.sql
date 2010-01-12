-- Fixed Ruthlessness proc from Envenom
UPDATE spell_proc_event SET spellFamilyMask1 = 8 WHERE entry IN (14156, 14160, 14161);