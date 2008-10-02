DELETE FROM spell_proc_event where entry = 44604;
INSERT INTO spell_proc_event (entry, SchoolMask, Category, SkillID, SpellFamilyName, SpellFamilyMask, procFlags, ppmRate, cooldown) VALUES
(44604,0,0,0,0,0x0000000000000000,0x00004000,0,0);

DELETE FROM spell_proc_event where entry = 44599;
INSERT INTO spell_proc_event (entry, SchoolMask, Category, SkillID, SpellFamilyName, SpellFamilyMask, procFlags, ppmRate, cooldown) VALUES
(44599,0,0,0,0,0x0000000000000000,0x00000001,0,5);

DELETE FROM spell_proc_event where entry = 46046;
INSERT INTO spell_proc_event (entry, SchoolMask, Category, SkillID, SpellFamilyName, SpellFamilyMask, procFlags, ppmRate, cooldown) VALUES
(46046,0,0,0,0,0x0000000000000000,0x00000001,0,5); 
