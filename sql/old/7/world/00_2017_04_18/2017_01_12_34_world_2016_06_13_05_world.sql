UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=34320;

DELETE FROM `smart_scripts` WHERE `entryorguid`=34320 AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(34320, 0, 0, 0, 8, 0, 100, 0, 65258, 0, 2000, 2000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Venomhide Hatchling - On Spellhit (Feed Venomhide Hatchling) - Say'),
(34320, 0, 1, 0, 8, 0, 100, 0, 65265, 0, 2000, 2000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Venomhide Hatchling - On Spellhit (Feed Venomhide Hatchling) - Say'),
(34320, 0, 2, 0, 8, 0, 100, 0, 65200, 0, 2000, 2000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Venomhide Hatchling - On Spellhit (Feed Venomhide Hatchling) - Say');


DELETE FROM `creature_text` WHERE `entry`=34320;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(34320, 0, 0, 'The %s''s strong jaws tear into the food.', 16, 0, 100, 0, 0, 0, 34521, 0, 'Venomhide Hatchling'),
(34320, 0, 1, 'The %s quickly finishes the food and glances around for more.', 16, 0, 100, 0, 0, 0, 34522, 0, 'Venomhide Hatchling'),
(34320, 0, 2, 'The %s devours the food.', 16, 0, 100, 0, 0, 0, 34519, 0, 'Venomhide Hatchling'),
(34320, 0, 3, 'The %s catches the food in its mouth and swallows it in one gulp.', 16, 0, 100, 0, 0, 0, 34520, 0, 'Venomhide Hatchling');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=20747;

DELETE FROM `smart_scripts` WHERE `entryorguid`=20747 AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20747, 0, 0, 1, 2, 0, 100, 1, 0, 20, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Silkwing Larva - On Less Than 20% HP - Say Line 0 (No repeat)'),
(20747, 0, 1, 0,61, 0, 100, 1, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Silkwing Larva - On Less Than 20% HP - Set Phase 2'),
(20747, 0, 2, 3, 0, 2, 100, 1, 4000, 4000, 0, 0, 11, 36948, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Silkwing Larva - IC (Phase 2) - Cast Silkwing (No repeat)'),
(20747, 0, 3, 0,61, 0, 100, 1, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Silkwing Larva - IC (Phase 2) - Die');

DELETE FROM `creature_text` WHERE `entry`=20747;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(20747, 0, 0, '%s begins to metamorphose...', 16, 0, 100, 0, 0, 0, 18589, 0, 'Silkwing Larva');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=26452;

DELETE FROM `smart_scripts` WHERE `entryorguid`=26452 AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26452, 0, 0, 1, 8, 0, 100, 0, 47170, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Leviroth - On Spellhit (Impale Leviroth) - Remove Unit flags (Immune to PC)'),
(26452, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 46767, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Leviroth - On Spellhit (Impale Leviroth) - Cast Cosmetic - Underwater Blood'),
(26452, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Leviroth - On Spellhit (Impale Leviroth) - Start Attack');

UPDATE `smart_scripts` SET `target_type`=1 WHERE  `entryorguid`=8400 AND `source_type`=0 AND `id`=0 AND `link`=1;

DELETE FROM `smart_scripts` WHERE `entryorguid`=3127100 AND `source_type`=9 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3127700 AND `source_type`=9 AND `id`=5;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1468800 AND `source_type`=9 AND `id`=3;

UPDATE `smart_scripts` SET `event_param1`=10000, `event_param2`=10000 WHERE  `entryorguid`=31271 AND `source_type`=0 AND `id`=4 AND `link`=0;
UPDATE `smart_scripts` SET `event_param1`=1000, `event_param2`=1000 WHERE  `entryorguid`=3127700 AND `source_type`=9 AND `id`=3 AND `link`=0;
UPDATE `smart_scripts` SET `event_param1`=7500, `event_param2`=7500 WHERE  `entryorguid`=1468800 AND `source_type`=9 AND `id`=2 AND `link`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3127100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Carnage - OOC script 1 - Remove Unit Flags'),
(3127700, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thane Banahogg - OOC script 1 - Remove Unit Flags'),
(1468800, 9, 3, 0, 1, 0, 100, 0, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - OOC script 1 - Remove Unit Flags');

