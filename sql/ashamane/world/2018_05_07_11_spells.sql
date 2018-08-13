DELETE FROM spell_script_names WHERE scriptname IN ("aura_sha_stormlash", "aura_sha_stormlash_buff");
INSERT INTO spell_script_names VALUES
(195255, "aura_sha_stormlash"),
(195222, "aura_sha_stormlash_buff");

DELETE FROM `spell_proc` WHERE `SpellId` = 194084; 
INSERT INTO `spell_proc` (`SpellId`, `HitMask`) VALUES (194084, 1); 
