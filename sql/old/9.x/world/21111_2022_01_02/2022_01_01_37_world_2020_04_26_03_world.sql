-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` IN (71849);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 71849, 0, 24, 1, 8, 0, 0, 0, '', "Toxic Wasteling Find Target hits only critters");

DELETE FROM `creature_template_addon` WHERE `entry` = 38374;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(38374, 0, 0, 0, 0, 0, '71849');

DELETE FROM `spell_scripts` WHERE `id` IN (71848 ,71874,26264);
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(71848 ,0,0,15,71847,0,0,0,0,0,0),
(71848 ,0,1,15,71874,0,0,0,0,0,0),
(71874 ,1,1,15,71854,1,0,0,0,0,0),
(71874 ,1,1,15,26264,2,0,0,0,0,0),
(26264 ,0,0,18,0,0,0,0,0,0,0);
