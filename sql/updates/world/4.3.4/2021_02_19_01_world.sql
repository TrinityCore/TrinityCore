UPDATE `spell_proc` SET `Cooldown`= 1000, `ProcsPerMinute`= 15 WHERE `SpellId`= 20165;

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_pal_seal_of_insight';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(20165, 'spell_pal_seal_of_insight');
