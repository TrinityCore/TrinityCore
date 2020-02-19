-- Creature Black Widow 45582 SAI
SET @ENTRY := 45582;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 2, 0, 100, 1, 0, 15, 0, 0, 11, 87080, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 15% (check every 0 - 0 ms) - Self: Cast spell Vanish (87080) on Self // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 122, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self flees for 2000 ms // ");

UPDATE `creature` SET `spawndist`= 7, `MovementType`= 1 WHERE `Id`= 45582;

-- Creature Rotted One 948 SAI
SET @ENTRY := 948;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 17000, 17000, 32000, 33000, 11, 85234, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 17000 min and 17000 max ms (repeat 32000 min 33000 max ms) - Self: Cast spell Fetid Breath (85234) on Victim // "),
(@ENTRY, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 3428, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On death - Self: Cast spell Summon Flesh Eating Worms (3428) on Self // ");

UPDATE `creature` SET `spawndist`= 7, `MovementType`= 1 WHERE `Id`= 948;

-- Creature Flesh Eater 3 SAI
SET @ENTRY := 3;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 2, 0, 100, 0, 0, 50, 31000, 31000, 11, 83884, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 50% (check every 31000 - 31000 ms) - Self: Cast spell Cannibalize (83884) on Self // ");

UPDATE `creature` SET `spawndist`= 7, `MovementType`= 1 WHERE `Id`= 3;

-- Creature Plague Spreader 604 SAI
SET @ENTRY := 604;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 14000, 15000, 32000, 33000, 11, 3436, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 14000 min and 15000 max ms (repeat 32000 min 33000 max ms) - Self: Cast spell Wandering Plague (3436) on Victim // "),
(@ENTRY, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 85236, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On death - Self: Cast spell Corpse Rot (85236) on Self // ");

UPDATE `creature` SET `spawndist`= 7, `MovementType`= 1 WHERE `Id`= 604;

-- Creature Rotting Horror 202 SAI
SET @ENTRY := 202;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 85236, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On death - Self: Cast spell Corpse Rot (85236) on Self // ");

UPDATE `creature` SET `spawndist`= 7, `MovementType`= 1 WHERE `Id`= 202;

-- Creature Bone Chewer 210 SAI
SET @ENTRY := 210;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 10000, 10000, 12000, 17000, 11, 82625, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 10000 min and 10000 max ms (repeat 12000 min 17000 max ms) - Self: Cast spell Bone Toss (82625) on Victim // ");

UPDATE `creature` SET `spawndist`= 7, `MovementType`= 1 WHERE `Id`= 210;

-- Creature Carrion Recluse 949 SAI
SET @ENTRY := 949;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 20000, 20000, 18000, 20000, 11, 3609, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 20000 min and 20000 max ms (repeat 18000 min 20000 max ms) - Self: Cast spell Paralyzing Poison (3609) on Victim // ");

UPDATE `creature` SET `spawndist`= 12, `MovementType`= 1 WHERE `Id`= 949;

-- Creature Coalpelt Bear 44016 SAI
SET @ENTRY := 44016;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 2, 0, 100, 0, 0, 45, 31000, 31000, 11, 84868, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 45% (check every 31000 - 31000 ms) - Self: Cast spell Hibernate (84868) on Self // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 4000, 5000, 6000, 6000, 11, 31279, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 4000 min and 5000 max ms (repeat 6000 min 6000 max ms) - Self: Cast spell Swipe (31279) on Victim // ");

UPDATE `creature` SET `spawndist`= 7, `MovementType`= 1 WHERE `Id`= 949;

-- Creature Anguished Spirit 45614 SAI
SET @ENTRY := 45614;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 4000, 5000, 6000, 10000, 11, 80132, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 4000 min and 5000 max ms (repeat 6000 min 10000 max ms) - Self: Cast spell Unbound Darkness (80132) on Victim // ");

UPDATE `creature` SET `spawndist`= 10, `MovementType`= 1 WHERE `Id`= 45614;

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 45614;
INSERT INTO `creature_template_movement` (`CreatureId`, `Random`) VALUES
(45614, 2);

-- Creature Forlorn Spirit 43923 SAI
SET @ENTRY := 43923;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 8000, 9000, 12000, 15000, 11, 81193, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 8000 min and 9000 max ms (repeat 12000 min 15000 max ms) - Self: Cast spell Unrelenting Anguish (81193) on Victim // ");

UPDATE `creature` SET `spawndist`= 7, `MovementType`= 1 WHERE `Id`= 43923;

-- Creature Venom Web Spider 217 SAI
SET @ENTRY := 217;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 8000, 9000, 13000, 20000, 11, 85246, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 8000 min and 9000 max ms (repeat 13000 min 20000 max ms) - Self: Cast spell Pygmy (85246) on Self // ");

UPDATE `creature` SET `spawndist`= 7, `MovementType`= 1 WHERE `Id`= 217;

-- Creature Nightbane Worgen 898 SAI
SET @ENTRY := 898;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 6000, 7000, 30000, 32000, 11, 84308, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 6000 min and 7000 max ms (repeat 30000 min 32000 max ms) - Self: Cast spell Furious Howl (84308) on Self // ");

-- Creature Dire Wolf 43704 SAI
SET @ENTRY := 43704;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 16000, 16000, 32000, 33000, 11, 3150, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 16000 min and 16000 max ms (repeat 32000 min 33000 max ms) - Self: Cast spell Rabies (3150) on Victim // "),
(@ENTRY, 0, 1, 2, 2, 0, 100, 1, 0, 50, 0, 0, 11, 18501, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 50% (check every 0 - 0 ms) - Self: Cast spell Enrage (18501) on Self // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // ");

UPDATE `creature` SET `spawndist`= 7, `MovementType`= 1 WHERE `Id`= 43704;

DELETE FROM `creature_text` WHERE `CreatureID`= 43704;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(43704, 0, 0, '%s goes into a frenzy!', 16, 0, 100, 0, 0, 0, 1191, 'Dire Wolf');

-- Creature Nightbane Dark Runner 205 SAI
SET @ENTRY := 205;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 1000, 2000, 31000, 32000, 11, 7137, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 1000 min and 2000 max ms (repeat 31000 min 32000 max ms) - Self: Cast spell Shadow Charge (7137) on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 7000, 8000, 13000, 16000, 11, 6595, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 7000 min and 8000 max ms (repeat 13000 min 16000 max ms) - Self: Cast spell Exploit Weakness (6595) on Victim // ");

-- Creature Corpseweed 43732 SAI
SET @ENTRY := 43732;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 600000, 600000, 11, 85253, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (OOC) 1000 min and 1000 max ms (repeat 600000 min 600000 max ms) - Self: Cast spell Rotten Stench (85253) on Self // ");

UPDATE `creature` SET `spawndist`= 7, `MovementType`= 1 WHERE `Id` IN (212, 889, 1251, 44020, 44089, 43732, 930, 202, 48, 203, 511, 44087, 1270);

-- Pathing for  Entry: 205 'TDB FORMAT' 
SET @NPC := 317517;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -10340, `position_y`= -975.198, `position_z`= 46.08131 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -10340, -975.198, 46.08131, 0, 146, 0, 0, 100, 0),
(@PATH, 2, -10352.4, -960.139, 44.60948, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -10369, -948.965, 44.21052, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -10386.7, -924.875, 47.33474, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -10400, -906.153, 46.71668, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -10419.7, -878.91, 46.32598, 0, 224, 0, 0, 100, 0),
(@PATH, 7, -10400, -906.153, 46.71668, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -10386.7, -924.875, 47.33474, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -10369, -948.965, 44.21052, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -10352.4, -960.139, 44.60948, 0, 0, 0, 0, 100, 0);
-- 0x203CD8000000334000003100004C9A6C .go xyz -10340 -975.198 46.08131

UPDATE `waypoint_data` SET `move_type`= 1 WHERE `id`= @PATH;

-- Pathing for  Entry: 205 'TDB FORMAT' 
SET @NPC := 317476;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -10605.2, `position_y`= -920.679, `position_z`= 55.11224 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -10605.2, -920.679, 55.11224, 0, 41, 0, 0, 100, 0),
(@PATH, 2, -10572.2, -895.842, 47.79381, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -10552.9, -875.25, 47.48726, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -10521.1, -848.3, 50.53896, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -10526.9, -833.09, 53.74474, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -10555.6, -810.939, 53.73056, 0, 100, 0, 0, 100, 0),
(@PATH, 7, -10526.9, -833.09, 53.74474, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -10521.1, -848.3, 50.53896, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -10552.9, -875.25, 47.48726, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -10572.2, -895.842, 47.79381, 0, 0, 0, 0, 100, 0);
-- 0x203CD8000000334000003100004C9A70 .go xyz -10605.2 -920.679 55.11224

UPDATE `waypoint_data` SET `move_type`= 1 WHERE `id`= @PATH;

-- Pathing for  Entry: 205 'TDB FORMAT' 
SET @NPC := 317423;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -10345.4, `position_y`= -880.816, `position_z`= 39.5604 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -10345.4, -880.816, 39.5604, 0, 299, 0, 0, 100, 0),
(@PATH, 2, -10377.6, -854.064, 44.41235, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -10405.9, -828.821, 48.46384, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -10409.3, -799.422, 52.21737, 0, 314, 0, 0, 100, 0),
(@PATH, 5, -10405.9, -828.821, 48.46384, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -10377.6, -854.064, 44.41235, 0, 0, 0, 0, 100, 0);
-- 0x203CD8000000334000003100004C9A71 .go xyz -10345.4 -880.816 39.5604

UPDATE `waypoint_data` SET `move_type`= 1 WHERE `id`= @PATH;

-- Pathing for  Entry: 205 'TDB FORMAT' 
SET @NPC := 317417;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -10308.7, `position_y`= -802.693, `position_z`= 47.59847 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -10308.7, -802.693, 47.59847, 0, 189, 0, 0, 100, 0),
(@PATH, 2, -10288.4, -830.295, 42.60696, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -10277.4, -863.594, 40.5671, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -10281.4, -906.568, 40.76699, 0, 335, 0, 0, 100, 0),
(@PATH, 5, -10277.45, -863.7363, 40.53536, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -10288.4, -830.295, 42.60696, 0, 0, 0, 0, 100, 0);
-- 0x203CD800000033400000310000CC9A6C .go xyz -10308.7 -802.693 47.59847

UPDATE `waypoint_data` SET `move_type`= 1 WHERE `id`= @PATH;
UPDATE `creature` SET `MovementType`= 1, `spawndist`= 7 WHERE `guid` IN (317369, 317436, 317372, 317433, 317475, 317434, 317427, 317428, 317429, 317514, 317421, 317423, 317418, 317419, 317389, 317331);
