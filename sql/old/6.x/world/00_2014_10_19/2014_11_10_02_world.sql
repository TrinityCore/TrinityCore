ALTER TABLE spell_proc_event ADD spellFamilyMask3 INT(10) UNSIGNED DEFAULT 0  NOT NULL AFTER spellFamilyMask2;
ALTER TABLE spell_proc ADD spellFamilyMask3 INT(10) UNSIGNED DEFAULT 0  NOT NULL AFTER spellFamilyMask2;
