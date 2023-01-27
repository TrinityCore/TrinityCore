DELETE FROM smart_scripts WHERE entryorguid in (65471, 54587);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(65471, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Reset - Invincibility HP Level 1'),
(65471, 0, 1, 2, 2, 0, 100, 1, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'HP <5% - Talk Random Text'),
(65471, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 33, 54586, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - Kill Credit'),
(65471, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Despawn'),
(65471, 0, 4, 0, 1, 0, 100, 0, 5000, 5000, 5000, 5000, 5, 543, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'cung-fu panda');

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(54587, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Reset - Invincibility HP Level 1'),
(54587, 0, 1, 2, 2, 0, 100, 1, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'HP <5% - Talk Random Text'),
(54587, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 33, 54586, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - Kill Credit'),
(54587, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Despawn'),
(54587, 0, 4, 0, 1, 0, 100, 0, 5000, 5000, 5000, 5000, 5, 543, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'cung-fu panda');

UPDATE `creature_template` SET `faction_A`=2101, `faction_H`=2101 WHERE `entry` in (65470, 54586);

-- some flags again add after creature templates
UPDATE `creature_template` SET `IconName` = 'openhand', `npcflag` =  npcflag | 16777216, `unit_flags` = '295680' WHERE `entry` = 53566;
UPDATE `creature_template` SET `IconName` = 'vehichleCursor', `unit_flags` = '33536', `npcflag` = '16777216', `VehicleId` = '1887' WHERE `entry` = 55918;
UPDATE `creature_template` SET `npcflag` = '16777216', `AIName` = '', `ScriptName` = 'npc_hurted_soldier' WHERE `entry` = 55999;
UPDATE `creature_template` SET `npcflag` =2, `mindmg` = '20', `maxdmg` = '30', `attackpower` = '15',`AIName` = '', `ScriptName` = 'npc_aysa_cloudsinger' WHERE `entry` = 56416;


UPDATE `creature_template` SET `ScriptName` = 'vehicle_balance_pole' WHERE  `entry` in (54993, 55083, 57431, 57626);
UPDATE `creature_template` SET `modelid2` = '38347' WHERE `entry` in (54993, 55083, 57431);
UPDATE `creature_template` SET `modelid1` = '38347', `modelid2` = '0' WHERE `entry` = 57626;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 18 AND `SourceGroup` in(54993, 55083, 57431, 57626);
REPLACE INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`, `ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`)VALUES 
(18, 54993, 46598, 1, 0, 102938, 0, 1, 'not aura 102938'),
(18, 54993, 46598, 1, 0, 102939, 0, 1, 'not aura 102939'),
(18, 54993, 46598, 1, 0, 102940, 0, 1, 'not aura 102940'),
(18, 54993, 46598, 1, 0, 102941, 0, 1, 'not aura 102941'),
(18, 54993, 46598, 1, 0, 102942, 0, 1, 'not aura 102942'),
--
(18, 55083, 46598, 1, 0, 102938, 0, 1, 'not aura 102938'),
(18, 55083, 46598, 1, 0, 102939, 0, 1, 'not aura 102939'),
(18, 55083, 46598, 1, 0, 102940, 0, 1, 'not aura 102940'),
(18, 55083, 46598, 1, 0, 102941, 0, 1, 'not aura 102941'),
(18, 55083, 46598, 1, 0, 102942, 0, 1, 'not aura 102942'),
--
(18, 57431, 46598, 1, 0, 102938, 0, 1, 'not aura 102938'),
(18, 57431, 46598, 1, 0, 102939, 0, 1, 'not aura 102939'),
(18, 57431, 46598, 1, 0, 102940, 0, 1, 'not aura 102940'),
(18, 57431, 46598, 1, 0, 102941, 0, 1, 'not aura 102941'),
(18, 57431, 46598, 1, 0, 102942, 0, 1, 'not aura 102942'),
--
(18, 57626, 46598, 1, 0, 102938, 0, 1, 'not aura 102938'),
(18, 57626, 46598, 1, 0, 102939, 0, 1, 'not aura 102939'),
(18, 57626, 46598, 1, 0, 102940, 0, 1, 'not aura 102940'),
(18, 57626, 46598, 1, 0, 102941, 0, 1, 'not aura 102941'),
(18, 57626, 46598, 1, 0, 102942, 0, 1, 'not aura 102942');

UPDATE `quest_template` SET `CompleteScript` = '29662' WHERE `Id` = 29662;
DELETE FROM `quest_end_scripts` WHERE id = 29662;
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('29662', '0', '15', '108786', '1', '0', '0', '0', '0', '0');

UPDATE `creature_template` SET `AIName`='' WHERE `entry`=55021;
DELETE FROM smart_scripts WHERE entryorguid = 55021;

UPDATE `creature_template` SET `AIName`='' WHERE `entry`=55478;
DELETE FROM smart_scripts WHERE entryorguid = 55478;

UPDATE `quest_template` SET `CompleteScript` = '29771' WHERE `Id` = 29771;
DELETE FROM `quest_end_scripts` WHERE id = 29771;
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('29771', '0', '15', '108827', '1', '0', '0', '0', '0', '0');

UPDATE `creature_template` SET `AIName`='' WHERE `entry`=55585;
DELETE FROM smart_scripts WHERE entryorguid = 55585;

UPDATE `quest_template` SET `CompleteScript` = '29783' WHERE `Id` = 29783;
DELETE FROM `quest_end_scripts` WHERE id = 29783;
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('29783', '0', '15', '108847', '1', '0', '0', '0', '0', '0');

UPDATE `quest_template` SET `CompleteScript` = '29782' WHERE `Id` = 29782;
DELETE FROM `quest_end_scripts` WHERE id = 29782;
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('29782', '0', '15', '108858', '1', '0', '0', '0', '0', '0');