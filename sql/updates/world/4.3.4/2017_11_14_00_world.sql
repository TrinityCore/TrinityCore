DELETE FROM `creature` WHERE `guid` IN (280330, 280327, 280328, 280329, 280331);
DELETE FROM `creature_addon` WHERE `guid` IN (280330, 280327, 280328, 280329, 280331);

UPDATE `creature_template` SET `AIName`= '', `scriptname`= 'npc_hogger' WHERE `entry`= 448;

UPDATE `creature_template_addon` SET `mount`= 2410 WHERE `entry`= 46942;
DELETE FROM `smart_scripts` WHERE `entryorguid`= 448;
UPDATE `creature` SET `MovementType`= 0, `SpawnDist`= 0 WHERE `guid`= 280348;

DELETE FROM `creature_text` WHERE `CreatureID` IN (448, 46943, 46942);
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(448, 0, 0, 'Yipe!  Help Hogger!', 14, 0, 100, 0, 0, 0, 46936, 'Hogger'),
(448, 1, 0, 'Hogger is eating!  Stop him!', 41, 0, 100, 0, 0, 0, 46939, 'Hogger'),
(448, 2, 0, 'Hogger is stunned!', 41, 0, 100, 0, 0, 0, 46940, 'Hogger to Hogger'),
(448, 3, 0, 'No hurt Hogger!', 14, 0, 100, 0, 0, 0, 47000, 'Hogger'),
(448, 4, 0, 'Grrr...', 12, 0, 100, 0, 0, 0, 46937, 'Hogger to Hogger'),
(448, 5, 0, 'Nooooo...', 12, 0, 100, 0, 0, 0, 46938, 'Hogger to Hogger'),
(46943, 0, 0, 'General Marcus Jonathan!', 12, 0, 100, 0, 0, 0, 0, 'Ragamuffin to Hogger'),
(46943, 1, 0, 'Wow!', 12, 0, 100, 0, 0, 0, 47006, 'Ragamuffin to Hogger'),
(46942, 0, 0, 'Hold your blade, adventurer!', 14, 0, 100, 25, 0, 0, 47004, 'General Hammond Clay to Hogger'),
(46942, 1, 0, 'This beast leads the Riverpaw gnoll gang and may be the key to ending gnoll aggression in Elwynn.', 12, 0, 100, 25, 0, 0, 47007, 'General Hammond Clay to Hogger'),
(46942, 2, 0, 'We''re taking him into custody in the name of King Varian Wrynn.', 12, 0, 100, 25, 0, 0, 47008, 'General Hammond Clay to Hogger'),
(46942, 3, 0, 'Take us to the Stockades, Andromath.', 12, 0, 100, 25, 0, 0, 47009, 'General Hammond Clay to Hogger');


DELETE FROM `creature_summon_groups` WHERE `summonerId`= 448 AND `summonerType`= 0;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`) VALUES
(448, 0, 0, 46942, -10128.3, 656.465, 36.05443, 2.045435, 8),
(448, 0, 0, 46941, -10123, 656.875, 36.05113, 1.971813, 8),
(448, 0, 0, 46940, -10132.9, 653.561, 36.05033, 2.0209991, 8);

-- Creature General Marcus Jonathan 46942 SAI
SET @ENTRY := 46942;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 1, 1, 1, 0, 0, 11, 64195, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 1 and 1 ms (and later repeats every 0 and 0 ms) - Self: Cast spell 64195 on Self // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, " Linked - None: Talk 0 // "),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set walk // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -10131.2, 662.197, 36.0578, 0, " Linked - Self: Move to None (point id 0) // "),
(@ENTRY, 0, 4, 0, 1, 0, 100, 1, 4000, 4000, 0, 0, 12, 46943, 8, 0, 0, 0, 0, 8, 0, 0, 0, -10122.5, 660.198, 36.0366, 2.83775, "When out of combat and timer at the begining between 4000 and 4000 ms (and later repeats every 0 and 0 ms) - Self: Summon creature Ragamuffin (46943) at (-10122.5, 660.198, 36.0366, 2.83775) // "),
(@ENTRY, 0, 5, 0, 1, 0, 100, 1, 4100, 4100, 0, 0, 12, 46943, 8, 0, 0, 0, 0, 8, 0, 0, 0, -10130.9, 653.302, 36.0501, 1.65242, "When out of combat and timer at the begining between 4100 and 4100 ms (and later repeats every 0 and 0 ms) - Self: Summon creature Ragamuffin (46943) at (-10130.9, 653.302, 36.0501, 1.65242) // "),
(@ENTRY, 0, 6, 0, 1, 0, 100, 1, 7000, 7000, 0, 0, 43, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 7000 and 7000 ms (and later repeats every 0 and 0 ms) - Self: Dismount // "),
(@ENTRY, 0, 7, 0, 1, 0, 100, 1, 8000, 8000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -10135.7, 668.389, 36.0412, 0, "When out of combat and timer at the begining between 8000 and 8000 ms (and later repeats every 0 and 0 ms) - Self: Move to None (point id 0) // "),
(@ENTRY, 0, 8, 0, 1, 0, 100, 1, 16000, 16000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 16000 and 16000 ms (and later repeats every 0 and 0 ms) - None: Talk 1 // "),
(@ENTRY, 0, 9, 0, 1, 0, 100, 1, 22000, 22000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 22000 and 22000 ms (and later repeats every 0 and 0 ms) - None: Talk 2 // "),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 30000, 30000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 11, 46941, 30, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 30000 and 30000 ms (and later repeats every 0 and 0 ms) - Self: Look at Creature High Sorcerer Andromath (46941) in 30 yd // "),
(@ENTRY, 0, 11, 0, 1, 0, 100, 0, 31000, 31000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 31000 and 31000 ms (and later repeats every 0 and 0 ms) - None: Talk 3 // "),
(@ENTRY, 0, 12, 13, 1, 0, 100, 1, 34000, 34000, 0, 0, 11, 87459, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 34000 and 34000 ms (and later repeats every 0 and 0 ms) - Self: Cast spell 87459 on Self // "),
(@ENTRY, 0, 13, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Despawn in 2000 ms // ");

-- Creature High Sorcerer Andromath 46941 SAI
SET @ENTRY := 46941;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1, 1, 0, 0, 11, 64195, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 1 and 1 ms (and later repeats every 0 and 0 ms) - Self: Cast spell 64195 on Self // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 1, 4000, 4000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 11, 448, 30, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 4000 and 4000 ms (and later repeats every 0 and 0 ms) - Self: Look at Creature Hogger (448) in 30 yd // "),
(@ENTRY, 0, 2, 3, 1, 0, 100, 1, 34000, 34000, 0, 0, 11, 64446, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 34000 and 34000 ms (and later repeats every 0 and 0 ms) - Self: Cast spell 64446 on Self // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Despawn in 2000 ms // ");

-- Creature Maginor Dumas 46940 SAI
SET @ENTRY := 46940;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1, 1, 0, 0, 11, 64195, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 1 and 1 ms (and later repeats every 0 and 0 ms) - Self: Cast spell 64195 on Self // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 1, 4000, 4000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 11, 448, 30, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 4000 and 4000 ms (and later repeats every 0 and 0 ms) - Self: Look at Creature Hogger (448) in 30 yd // "),
(@ENTRY, 0, 2, 3, 1, 0, 100, 1, 34000, 34000, 0, 0, 11, 64446, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 34000 and 34000 ms (and later repeats every 0 and 0 ms) - Self: Cast spell 64446 on Self // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Despawn in 2000 ms // ");

-- Creature Minion of Hogger 46932 SAI
SET @ENTRY := 46932;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 49, 0, 0, 0, 0, 0, 0, 25, 10, 1, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 1000 and 1000 ms (and later repeats every 0 and 0 ms) - Self: Attack Closest enemy player in 10 yards // "),
(@ENTRY, 0, 1, 0, 60, 0, 100, 1, 14000, 14000, 0, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 14000 and 14000 ms) - Self: Die // "),
(@ENTRY, 0, 2, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 87402, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On death - Self: Cast spell 87402 on Self // ");

-- Creature Ragamuffin 46943 SAI
SET @ENTRY := 46943;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;

-- Creature Ragamuffin 46943 SAI
SET @ENTRY := 46943;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100,@ENTRY*100+1) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @ENTRY*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Ragamuffin- On just summoned - action list"),
(@ENTRY*100, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -10128.8, 662.185, 36.0578, 0, "Ragamuffin- action list - Move to pos "),
(@ENTRY*100, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Ragamuffin- action list - say text"),
(@ENTRY*100, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -10122.5, 660.198, 36.0702, 0, "Ragamuffin- action list - Move to pos"),
(@ENTRY*100, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Ragamuffin- action list - Despawn"),

(@ENTRY, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @ENTRY*100+1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Ragamuffin- On just summoned - action list"),
(@ENTRY*100+1, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -10131.5, 660.094, 36.0578, 0, "Ragamuffin- action list - Move to pos "),
(@ENTRY*100+1, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Ragamuffin- action list - say text"),
(@ENTRY*100+1, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -10130.9, 653.302, 36.0578, 0, "Ragamuffin- action list - Move to pos"),
(@ENTRY*100+1, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Ragamuffin- action list - Despawn");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=46943 AND SourceId = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,	`ConditionTarget`, `ConditionTypeOrReference`, `ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `Comment`) VALUES
(22, 1, 46943, 0, 1, 29, 46941, 2, 0, "If there is creature High Sorcerer Andromath (46941) within range 4 yards to Invoker"),
(22, 2, 46943, 0, 1, 29, 46940,	2, 0, "If there is creature Maginor Dumas (46940) within range 4 yards to Invoker");
