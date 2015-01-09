UPDATE `creature_template` SET `AIName` = '', `ScriptName`= 'boss_rokmar_the_crackler' WHERE entry=17991;
-- DELETE FROM creature_ai_scripts WHERE creature_id=17991;
UPDATE `creature_template` SET `AIName` = '', `ScriptName`= 'boss_mennu_the_betrayer' WHERE entry=17941;
/*
DELETE FROM creature_ai_scripts WHERE creature_id=17941;
DELETE FROM creature_ai_texts WHERE entry BETWEEN -98 AND -93;
*/
UPDATE `creature_template` SET `AIName` = '', `ScriptName`= 'boss_quagmirran' WHERE entry=17942;
-- DELETE FROM creature_ai_scripts WHERE creature_id=17942;

-- Add missing spelldifficulty_dbc values
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (31956,34780);
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`) VALUES
(31956,31956,39005), -- Rokmar the Crackler
(34780,34780,39340); -- Quagmirran
