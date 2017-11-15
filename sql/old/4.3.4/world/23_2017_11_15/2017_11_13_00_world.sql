-- Creature Corpse Eater 47134 SAI
SET @ENTRY := 47134;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 0, 0, 100, 0, 7000, 7000, 6000, 7000, 11, 91088, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 7000 and 7000 ms (and later repeats every 6000 and 7000 ms) - Self: Cast spell Consume Flesh (91088) on Victim // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 1000, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 1000 - 1000 ms // "),
(@ENTRY, 0, 2, 0, 59, 0, 100, 4, 0, 0, 0, 0, 11, 91099, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell Rotting Bile (91099) on Random hostile (not top) // ");

-- Creature Frantic Geist 47131 SAI
SET @ENTRY := 47131;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 4, 0, 100, 4, 0, 0, 0, 0, 11, 91077, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Cast spell Frantic Leap (91077) on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 6000, 7000, 3000, 3000, 11, 91064, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 7000 ms (and later repeats every 3000 and 3000 ms) - Self: Cast spell Slashing Claws (91064) on Victim // ");

-- Creature Mindless Horror 47137 SAI
SET @ENTRY := 47137;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 5000, 6000, 8000, 9000, 11, 91213, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 6000 ms (and later repeats every 8000 and 9000 ms) - Self: Cast spell Smash (91213) on Self // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 4, 10000, 11000, 10000, 11000, 11, 91220, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 10000 and 11000 ms (and later repeats every 10000 and 11000 ms) - Self: Cast spell Cowering Roar (91220) on Self // ");

-- Creature Spitebone Skeleton 47143 SAI
SET @ENTRY := 47143;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 6000, 7000, 10000, 11000, 11, 91419, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 7000 ms (and later repeats every 10000 and 11000 ms) - Self: Cast spell Bone Flurry (91419) on Random hostile // ");

-- Creature Haunted Servitor 3875 SAI
SET @ENTRY := 3875;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 15000, 16000, 15000, 16000, 11, 7057, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 15000 and 16000 ms (and later repeats every 15000 and 16000 ms) - Self: Cast spell Haunting Spirits (7057) on Random hostile // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 4, 3000, 3000, 3000, 3000, 11, 91291, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 3000 and 3000 ms (and later repeats every 3000 and 3000 ms) - Self: Cast spell Drain Life (91291) on Random hostile // ");

DELETE FROM `creature_template_addon` WHERE `entry` IN (47231, 48973);
INSERT INTO `creature_template_addon` (`entry`, `Auras`) VALUES
(47231, '37816'),
(48973, '37816');

-- Creature Shadowy Attendant 47231 SAI
SET @ENTRY := 47231;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 29000, 30000, 29000, 30000, 5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 29000 and 30000 ms (and later repeats every 29000 and 30000 ms) - None: Play emote ONESHOT_TALK(DNR) (1) // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 2, 1, 1, 3000, 3000, 11, 12739, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1 and 1 ms (and later repeats every 3000 and 3000 ms) - Self: Cast spell Shadow Bolt (12739) on Victim // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 4, 11000, 14000, 9000, 10000, 11, 91324, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 11000 and 14000 ms (and later repeats every 9000 and 10000 ms) - Self: Cast spell Shadowy Touch (91324) on Random hostile // "),
(@ENTRY, 0, 3, 0, 0, 0, 100, 4, 8000, 10000, 14000, 16000, 11, 91325, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 8000 and 10000 ms (and later repeats every 14000 and 16000 ms) - Self: Cast spell Shadow Vortex (91325) on Random hostile // ");

-- Creature Ghostly Cook 47232 SAI
SET @ENTRY := 47232;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 7000, 8000, 1000, 3000, 11, 15496, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 7000 and 8000 ms (and later repeats every 1000 and 3000 ms) - Invoker: Cast spell Cleave (15496) to Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 4, 6000, 7000, 6000, 7000, 11, 91348, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 7000 ms (and later repeats every 6000 and 7000 ms) - Invoker: Cast spell Tenderize (91348) to Victim // ");


DELETE FROM `creature_template_addon` WHERE `entry` IN (47135, 49126);
INSERT INTO `creature_template_addon` (`entry`, `Auras`) VALUES
(47135, '91561'),
(49126, '91561');

-- Creature Fetid Ghoul 47135 SAI
SET @ENTRY := 47135;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 6, 0, 100, 4, 0, 0, 0, 0, 11, 91554, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On death - Self: Cast spell Fetid Cloud (91554) on Self // ");

-- Creature Sorcerous Skeleton 47140 SAI
SET @ENTRY := 47140;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 0, 0, 4500, 4500, 11, 15497, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 4500 and 4500 ms) - Self: Cast spell 15497 on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 4, 15000, 16000, 15000, 16000, 11, 91563, 65, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 15000 and 16000 ms (and later repeats every 15000 and 16000 ms) - Self: Cast spell 91563 on Random hostile // ");

UPDATE `creature_template` SET `InhabitType`= 5 WHERE `entry` IN (3870, 49160, 3869, 49155);
DELETE FROM `creature_template_addon` WHERE `entry` IN (3870, 49160, 3869, 49155);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`) VALUES
(3870, 1),
(49160, 1),
(3869, 1),
(49155, 1);

-- Lesser Gargoyles are only visible on heroic difficulty
UPDATE `creature` SET `spawnMask`= 2 WHERE `id`= 3869;

-- Creature Unstable Ravager 47136 SAI
SET @ENTRY := 47136;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 0, 0, 100, 0, 8000, 9000, 12000, 13000, 11, 3242, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 8000 and 9000 ms (and later repeats every 12000 and 13000 ms) - Self: Cast spell 3242 on Victim // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 73, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Trigger timed event 0 // "),
(@ENTRY, 0, 2, 0, 59, 0, 100, 4, 0, 0, 0, 0, 11, 91668, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell 91668 on Self // ");

-- Creature Dark Creeper 47132 SAI
SET @ENTRY := 47132;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 6000, 7000, 5000, 5000, 11, 91522, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 7000 ms (and later repeats every 5000 and 5000 ms) - Self: Cast spell 91522 on Victim // ");

DELETE FROM `spell_script_names` WHERE `spell_id`= 91629;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(91629, 'spell_sfk_shield_of_bones');

-- Creature Spitebone Guardian 47145 SAI
SET @ENTRY := 47145;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 3000, 3000, 6000, 6000, 11, 87081, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 3000 and 3000 ms (and later repeats every 6000 and 6000 ms) - Self: Cast spell 87081 on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 8000, 8000, 9500, 9500, 11, 11972, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 8000 and 8000 ms (and later repeats every 9500 and 9500 ms) - Self: Cast spell 11972 on Victim // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 4, 10000, 10000, 21000, 21000, 11, 91629, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 10000 and 10000 ms (and later repeats every 21000 and 21000 ms) - Self: Cast spell 91629 on Self // ");


UPDATE `creature` SET `MovementType`= 2, `position_x`= -104.5692, `position_y`= 2164.683, `position_z`= 104.4168, `orientation`= 4.345834 WHERE `guid`= 371035;
DELETE FROM `creature_addon` WHERE `guid`= 371035;
INSERT INTO `creature_addon` (`guid`, `path_id`) VALUES
(371035, 371035);

DELETE FROM `waypoint_data` WHERE `id`= 371035;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(371035, 0, -107.177, 2157.89, 102.0936),
(371035, 1, -104.217, 2165.6, 104.7692),
(371035, 2, -105.325, 2168.27, 105.3551),
(371035, 3, -110.116, 2170.54, 107.3326),
(371035, 4, -121.795, 2175.26, 112.6948),
(371035, 5, -125.892, 2176.94, 112.6948),
(371035, 6, -139.924, 2182.26, 110.8881),
(371035, 7, -147.009, 2185.09, 107.4098),
(371035, 8, -151.307, 2186.88, 105.7329),
(371035, 9, -154.755, 2186.2, 104.9672),
(371035, 10, -158.517, 2177.08, 102.178),
(371035, 11, -157.297, 2176, 102.174),
(371035, 12, -151.898, 2174.59, 99.87618),
(371035, 13, -157.0323, 2175.824, 102.1958),
(371035, 14, -158.517, 2177.08, 102.178),
(371035, 15, -154.7644, 2186.177, 104.9622),
(371035, 16, -153.214, 2187.62, 105.0722),
(371035, 17, -151.307, 2186.88, 105.7329),
(371035, 18, -147.009, 2185.09, 107.4098),
(371035, 19, -139.924, 2182.26, 110.8881),
(371035, 20, -125.892, 2176.94, 112.6948),
(371035, 21, -121.795, 2175.26, 112.6948),
(371035, 22, -110.116, 2170.54, 107.3326),
(371035, 23, -105.325, 2168.27, 105.3551),
(371035, 24, -104.118, 2167.28, 104.9537);


-- Creature Spitebone Flayer 47146 SAI
SET @ENTRY := 47146;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 6000, 6000, 11000, 11000, 11, 32731, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 6000 ms (and later repeats every 11000 and 11000 ms) - Self: Cast spell 32731 on Self // ");

-- Creature Dread Scryer 47141 SAI
SET @ENTRY := 47141;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 2, 3000, 3000, 6000, 6000, 11, 33832, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 3000 and 3000 ms (and later repeats every 6000 and 6000 ms) - Self: Cast spell 33832 on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 6, 21000, 21000, 21000, 21000, 11, 12611, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 21000 and 21000 ms (and later repeats every 21000 and 21000 ms) - Self: Cast spell 12611 on Victim // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 4, 0, 0, 3800, 3800, 11, 91622, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 3800 and 3800 ms) - Self: Cast spell 91622 on Victim // "),
(@ENTRY, 0, 3, 0, 0, 0, 100, 4, 11000, 11000, 11000, 11000, 11, 91623, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 11000 and 11000 ms (and later repeats every 11000 and 11000 ms) - Self: Cast spell 91623 on Self // "),
(@ENTRY, 0, 4, 0, 0, 0, 100, 4, 16000, 16000, 20000, 20000, 11, 91624, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 16000 and 16000 ms (and later repeats every 20000 and 20000 ms) - Self: Cast spell 91624 on Self // ");

-- Creature Pustulant Monstrosity 47138 SAI
SET @ENTRY := 47138;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 3500, 3500, 5500, 5500, 11, 91678, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 3500 and 3500 ms (and later repeats every 5500 and 5500 ms) - Self: Cast spell 91678 on Random hostile // ");
