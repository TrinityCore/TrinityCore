--
UPDATE `spell_dbc` SET `Effect1` = 28, `EffectMiscValueB1` = 64 WHERE `Id` IN (11475,11632,11633,11634,11635,11636,11645,11755,11794,11803,11804,11819,11822,11823,11855,11904,14329,17694,19829,21988,23361,25789,26564,26630,26631,26632,28218,29110,31692,33931,35721,35722,35723,36626,39424);
UPDATE `spell_dbc` SET `Effect2` = 28, `EffectMiscValueB2` = 64 WHERE `Id` = 29110;
-- Fix errors (summon creatures by spells and not manually)
UPDATE `smart_scripts` SET `link` = 0, `action_type` = 11, `action_param1` = 21988, `action_param2` = 2, `action_param3` = 0, `target_type` = 1, `comment` = "Foreman Bonds - Between 0-30% Health - Cast 'Summon Dun Garok Soldiers' (No Repeat)" WHERE `entryorguid` = 2305 AND `source_type` = 0 AND `id` = 2;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2305 AND `source_type` = 0 AND `id` = 3;
-- Script tries to summon creature 6086 and it's probably incorrect
-- Script is not used, texts from it are used in different script, removing
DELETE FROM `smart_scripts` WHERE `entryorguid` = 369300 AND `source_type` = 9;
