DELETE FROM spell_proc_event WHERE entry IN (42135,42136);

INSERT INTO spell_proc_event (entry, SchoolMask, Category, SkillID, SpellFamilyName, SpellFamilyMask, procFlags, ppmRate, cooldown) VALUES
(42135,0,0,0,0,0x0000000000000000,0x00100402,0,90),
(42136,0,0,0,0,0x0000000000000000,0x00100402,0,90);
