-- 
DELETE FROM `conditions` WHERE `SourceEntry` IN (59951, 59952) AND `SourceTypeOrReferenceId`=13 AND `ConditionValue2`=29686;
DELETE FROM `creature_template_addon` WHERE `entry` IN (29686);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(29686, 0, 0, 8, 1, 0, ''); -- 29686

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=54990;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,3,54990,0,0,31,0,3,29700,0,0,0,'','Chains of the Scourge');

DELETE FROM `spell_scripts` WHERE `id`=54990;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(54990,1,0,15,55009,3,0,0,0,0,0);
