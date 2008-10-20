DELETE FROM spell_proc_event where entry = 42083;
INSERT INTO spell_proc_event (entry, SchoolMask, Category, SkillID, SpellFamilyName, SpellFamilyMask, procFlags, ppmRate, cooldown) VALUES
(42083,0,0,0,0,0x0000000000000000,0x00401000,0,45);

ALTER TABLE characters
  CHANGE COLUMN gmstate extra_flags int(11) unsigned NOT NULL default '0';