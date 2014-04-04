-- Deep in the bowels of the Underhalls
UPDATE `smart_scripts` SET `target_type`=24 WHERE `entryorguid`=30409 AND `source_type`=0 AND `id`=4 AND `link`=0;
-- Guide our sights
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN(23957,23972);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23957,23972);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23957, 0, 0, 0, 8, 0, 100, 0, 43076, 0, 0, 0, 33, 23957   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Westguard Cannon Credit Trigger East - On Spellhit - Kill Credit'),
(23972, 0, 0, 0, 8, 0, 100, 0, 43076, 0, 0, 0, 33, 23972   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Westguard Cannon Credit Trigger West - On Spellhit - Kill Credit');
-- Baleheim Must Burn
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN(24182,24183,24184,24185);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24182,24183,24184,24185);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24182, 0, 0, 0, 8, 0, 100, 0, 43233, 0, 0, 0, 33, 24182   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Dwelling Credit - On Spellhit - Kill Credit'),
(24183, 0, 0, 0, 8, 0, 100, 0, 43233, 0, 0, 0, 33, 24183   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Watchtower Credit - On Spellhit - Kill Credit'),
(24184, 0, 0, 0, 8, 0, 100, 0, 43233, 0, 0, 0, 33, 24184   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Barracks Credit - On Spellhit - Kill Credit'),
(24185, 0, 0, 0, 8, 0, 100, 0, 43233, 0, 0, 0, 33, 24185   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Bridge Credit - On Spellhit - Kill Credit');
-- Forge Camp: Annihilated
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN(17998,17999,18000,18002);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17998,17999,18000,18002);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17998, 0, 0, 0, 8, 0, 100, 0, 31736, 0, 0, 0, 33, 17998   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Umbrafen Steam Pump Credit Marker - On Spellhit - Kill Credit'),
(17999, 0, 0, 0, 8, 0, 100, 0, 31736, 0, 0, 0, 33, 17999   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lagoon Steam Pump Credit Marker - On Spellhit - Kill Credit'),
(18000, 0, 0, 0, 8, 0, 100, 0, 31736, 0, 0, 0, 33, 18000   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Serpent Steam Pump Credit Marker - On Spellhit - Kill Credit'),
(18002, 0, 0, 0, 8, 0, 100, 0, 31736, 0, 0, 0, 33, 18002   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Marshlight Steam Pump Credit Marker - On Spellhit - Kill Credit');
-- Balance Must Be Preserved
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN(17998,17999,18000,18002);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17998,17999,18000,18002);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17998, 0, 0, 0, 8, 0, 100, 0, 31736, 0, 0, 0, 33, 17998   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Umbrafen Steam Pump Credit Marker - On Spellhit - Kill Credit'),
(17999, 0, 0, 0, 8, 0, 100, 0, 31736, 0, 0, 0, 33, 17999   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lagoon Steam Pump Credit Marker - On Spellhit - Kill Credit'),
(18000, 0, 0, 0, 8, 0, 100, 0, 31736, 0, 0, 0, 33, 18000   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Serpent Steam Pump Credit Marker - On Spellhit - Kill Credit'),
(18002, 0, 0, 0, 8, 0, 100, 0, 31736, 0, 0, 0, 33, 18002   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Marshlight Steam Pump Credit Marker - On Spellhit - Kill Credit');
-- Burn in Effigy
UPDATE `smart_scripts` SET `event_flags`=0 WHERE `entryorguid` BETWEEN 25510 AND 25513 AND `source_type`=0;
-- A Necessary Distraction
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (21506);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21506);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21506, 0, 0, 0, 8, 0, 100, 0, 37834, 0, 0, 0, 33, 21892, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Azaloth - On Spellhit - Kill Credit');
-- Monitoring the Rift: Sundered Chasm 3.3.5
UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry`=25308;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25308 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25308,0,0,0,8,0,100,0,45414,0,0,0,33,25308,0,0,0,0,0,7,0,0,0,0,0,0,0,'Borean - Westrift Chasm Anomaly - On Spell Hit - Give Quest Credit');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=25309;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25309 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25309,0,0,0,8,0,100,0,45414,0,0,0,33,25309,0,0,0,0,0,7,0,0,0,0,0,0,0,'Borean - Westrift Cavern Anomaly - On Spell Hit - Give Quest Credit');
