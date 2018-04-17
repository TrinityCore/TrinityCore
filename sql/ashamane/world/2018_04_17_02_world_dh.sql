UPDATE areatrigger_template SET scriptname = "at_dh_shattered_souls" WHERE ID in (11266, 12929);

DELETE FROM spell_script_names WHERE scriptname = "aura_dh_chaos_cleave";
INSERT INTO spell_script_names VALUES
(206475, "aura_dh_chaos_cleave");

DELETE FROM `spell_proc` WHERE `SpellId` = 206475;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellPhaseMask`) VALUES
(206475, 107, 16384, 2048, 2);
