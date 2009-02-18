UPDATE `creature_template` SET `minhealth`=2655000, `maxhealth`=2655000, `ScriptName` = 'boss_the_lurker_below', `InhabitType` = '3' WHERE `entry` = '21217';

UPDATE `creature_template` SET `ScriptName` = 'mob_coilfang_ambusher' WHERE `entry` = '21865';
UPDATE `creature_template` SET `ScriptName` = 'mob_coilfang_guardian' WHERE `entry` = '21873';

UPDATE `creature_model_info` SET `bounding_radius` = '13', `combat_reach` = '20' WHERE `modelid` = '20216';

