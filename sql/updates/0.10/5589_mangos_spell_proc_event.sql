DELETE FROM `spell_proc_event` WHERE `entry` IN (16952,16954);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `Category`, `SkillID`, `SpellFamilyName`, `SpellFamilyMask`, `procFlags`, `ppmRate`) VALUE 
(16952,0,0,0,0,0x0000040000039000,0x00010000,0),
(16954,0,0,0,0,0x0000040000039000,0x00010000,0);


