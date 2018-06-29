UPDATE `spell_proc` SET `HitMask` = 16 WHERE `SpellId` = 195630;

DELETE FROM spell_script_names WHERE scriptname = "spell_monk_elusive_brawler_mastery";
INSERT INTO spell_script_names VALUES
(117906, "spell_monk_elusive_brawler_mastery");
