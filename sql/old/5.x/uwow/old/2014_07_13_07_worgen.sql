-- PHASE 1024
DELETE FROM `spell_area` WHERE `spell` in (67789) AND area in (4755, 4714);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('67789', '4755', '14222', '0', '0', '0', '2', '1', '74', '0'),
('67789', '4714', '14222', '0', '0', '0', '2', '1', '74', '0');

-- PHASE 262144
DELETE FROM `spell_area` WHERE `spell` in (69485) AND area in (4755, 4714);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('69485', '4755', '24676', '0', '0', '0', '2', '1', '64', '0'),
('69485', '4714', '24676', '0', '0', '0', '2', '1', '64', '0');

-- PHASE 524288
DELETE FROM `spell_area` WHERE `spell` in (69486) AND area in (4714, 4755);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('69486', '4755', '24903', '0', '0', '0', '2', '1', '74', '0'),
('69486', '4714', '24903', '0', '0', '0', '2', '1', '74', '0');

--
UPDATE `quest_template` SET `SourceItemId` = '49202' WHERE `quest_template`.`Id` = 14348;
UPDATE `quest_template` SET `Method` = '2' WHERE `quest_template`.`Id` = 24920;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 18 AND SourceGroup = 38615;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
('18', '38615', '72472', '0', '0', '9', '0', '24920', '0', '0', '0', '0', '', 'req. quest 24920');

--
DELETE FROM `conditions` WHERE SourceEntry = 67063 AND SourceTypeOrReferenceId = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 7, 67063, 0, 0, 32, 0, 16, 0, 0, 1, 0, '', NULL);

--
DELETE FROM creature where map = 654 and id = 31144 ;
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `isActive`) VALUES
(31144, 654, 4755, 4757, 1, 3, 0, 0, -1688.97, 1337.88, 15.1355, 1.51659, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(31144, 654, 4755, 4757, 1, 3, 0, 0, -1684.23, 1345.68, 15.1355, 5.29985, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0);
