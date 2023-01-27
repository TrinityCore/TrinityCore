UPDATE `spell_area` SET `quest_start_status`='66' WHERE (`spell`='59073') AND (`area`='4756') AND (`quest_start`='14091') AND (`aura_spell`='0') AND (`racemask`='0') AND (`gender`='2');

UPDATE `quest_template` SET `RequiredNpcOrGo1` = 0 WHERE `Id` = 14283;
UPDATE `quest_template` SET `RequiredNpcOrGo1` = 0 WHERE `Id` = 14279;
UPDATE `quest_template` SET `RequiredNpcOrGo1` = 0 WHERE `Id` = 14272;
UPDATE `quest_template` SET `RequiredNpcOrGo1` = 0 WHERE `Id` = 14281;

UPDATE `gameobject` SET `spawnMask` = 2 WHERE `guid` = 522373;

DELETE FROM `smart_scripts` WHERE (`entryorguid`=35369 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(35369, 0, 0, 0, 20, 0, 100, 0, 14159, 0, 0, 0, 41, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Despawn on quest 14159');

DELETE FROM `spell_area` WHERE `spell`='72872' AND `area`='4757' AND `quest_start`='14159';
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('72872', '4757', '14159', '0', '0', '0', '2', '1', '66', '11');

DELETE FROM `spell_area` WHERE `spell`='72872' AND `area`='4758' AND `quest_start`='14159';
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('72872', '4758', '14159', '0', '0', '0', '2', '1', '66', '11');

UPDATE `spell_area` SET `quest_end`='14222', `quest_end_status`='66' WHERE (`spell`='72872') AND (`area`='4758') AND (`quest_start`='14159') AND (`aura_spell`='0') AND (`racemask`='0') AND (`gender`='2');


DELETE FROM `spell_area` WHERE `spell`='72872' AND `area`='4755' AND `quest_start`='14159';
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('72872', '4755', '14159', '0', '0', '0', '2', '1', '66', '11');

DELETE FROM `spell_area` WHERE `spell`='59073' AND `area`='4786' AND `quest_start`='14222';
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('59073', '4786', '14222', '0', '0', '0', '2', '1', '64', '11');


DELETE FROM `spell_area` WHERE `spell`='97709' AND `area`='4786' AND `quest_start`='14222';
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('97709', '4786', '14222', '0', '0', '0', '2', '1', '64', '11');

-- Phase 8
DELETE FROM `spell_area` WHERE `spell`='59087' AND `area`='4786' AND `quest_start`='14465';
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `autocast`, `quest_start_status`) VALUES 
('59087', '4786', '14465', '1', '2');

-- Spell Area 4714
DELETE FROM `spell_area` WHERE `spell`='59073' AND `area`='4714' AND `quest_start`='14222';
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('59073', '4714', '14222', '0', '0', '0', '2', '1', '66', '11');

DELETE FROM `spell_area` WHERE `spell`='59074' AND `area`='4714' AND `quest_end`='14222';
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('59074', '4714', '14222', '0', '0', '0', '2', '1', '66', '11');

DELETE FROM `spell_area` WHERE `spell`='97709' AND `area`='4714' AND `quest_start`='14222';
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('97709', '4714', '14222', '0', '0', '0', '2', '1', '66', '11');


UPDATE `gameobject` SET `map`='655' WHERE (`guid`='522293');
UPDATE `gameobject` SET `spawnMask`='1', `phaseMask`='8' WHERE (`guid`='522293');

UPDATE `gameobject_template` SET `flags` = 18 WHERE `entry` = 196399;
UPDATE `gameobject` SET `spawnMask`='1', `phaseMask`='15' WHERE (`guid`='522291');

DELETE FROM `gameobject` WHERE (`id`='196399');
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) VALUES 
('522291', '196399', '654', '4714', '4714', '1', '15', '-1817.84', '2333.37', '36.3445', '-2.48419', '0', '0', '-0.946463', '0.322813', '300', '255', '1', '0');

INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) VALUES 
(NULL, '196399', '655', '4714', '4714', '1', '6', '-1817.84', '2333.37', '36.3445', '-2.48419', '0', '0', '-0.946463', '0.322813', '300', '255', '1', '0');


UPDATE `gameobject` SET `spawnMask` = 1, `phaseMask` = 2 WHERE `guid` = 522611;
UPDATE `gameobject` SET `phaseMask`='2' WHERE (`guid`='522356');
UPDATE `gameobject` SET `phaseMask`='2' WHERE (`guid`='522357');
UPDATE `gameobject` SET `phaseMask`='2' WHERE (`guid`='522358');


UPDATE `quest_template` SET `PrevQuestId` = 26706 WHERE `Id` = 14434;
UPDATE `quest_template` SET `CompleteScript`='14434' WHERE (`Id`='14434');