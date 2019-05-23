UPDATE `creature_template` SET `flags_extra`= 2 WHERE `entry`= 43396;
UPDATE `creature_template` SET `flags_extra`= 2 WHERE `entry`= 43404;
UPDATE `creature_template` SET `flags_extra`= 2 WHERE `entry`= 43407;
UPDATE `creature_template` SET `flags_extra`= 130 WHERE `entry` IN (43400, 43401, 43402, 51506);
UPDATE `gameobject_template` SET `ScriptName`= 'go_bwd_ancient_bell' WHERE `entry`= 204276;

DELETE FROM `creature_template_addon` WHERE `entry` IN (43396, 43404, 43407, 43402, 43401, 43400);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `auras`) VALUES
(43396, 0, 1, '69676'),
(43404, 0, 1, '69676 81271'),
(43407, 0, 1, '69676'),
(43402, 0, 1, '81184'),
(43401, 0, 1, '81183'),
(43400, 0, 1, '81178');

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (43396, 43404, 43407, 43402, 43401, 43400);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Flight`, `Rooted`) VALUES
(43396, 1, 1, 1),
(43404, 1, 1, 1),
(43407, 1, 1, 0),
(43402, 1, 1, 1),
(43401, 1, 1, 1),
(43400, 1, 1, 1);

DELETE FROM `creature_summon_groups` WHERE `summonerId`= 669 AND `summonerType`= 2;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(669, 2, 0, 43396, 150.7813, -231.1962, 75.53674, 2.216568, 3, 114000),
(669, 2, 0, 43404, 149.7569, -207.6285, 75.53674, 4.049164, 3, 114000),
(669, 2, 0, 43407, 136.0764, -207.6441, 75.53674, 4.764749, 3, 114000),
(669, 2, 0, 43402, 166.7639, -229.9844, 74.99064, 3.124139, 3, 114000),
(669, 2, 0, 43402, 149.4306, -245.8802, 74.99064, 0.5934119, 3, 114000),
(669, 2, 0, 43401, 157.25, -236.1198, 75.53674, 2.373648, 3, 114000),
(669, 2, 0, 43400, 166.7326, -220.3958, 75.53674, 0, 3, 114000),
(669, 2, 0, 43400, 155.2049, -212.3611, 75.53674, 0, 3, 114000),
(669, 2, 0, 43400, 145.0451, -225.7205, 75.53674, 0, 3, 114000);

DELETE FROM `creature_text` WHERE `CreatureID` IN (43396, 43404);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(43396, 0, 0, 'Ah, Maloriak. How gracious of you to finally appear from that quarantine you call a laboratory. What have you got this time?', 12, 0, 100, 1, 0, 20091, 43488, 'Lord Victor Nefarius'),
(43396, 1, 0, 'By all means, enlighten me. ', 12, 0, 100, 6, 0, 20092, 43489, 'Lord Victor Nefarius'),
(43396, 2, 0, ' It appears as though your experiment has failed. That whelp has gone completely blind! Look at him.', 12, 0, 100, 1, 0, 20093, 43490, 'Lord Victor Nefarius'),
(43396, 3, 0, 'LOOK AT HIM!', 12, 0, 100, 25, 0, 20156, 43491, 'Lord Victor Nefarius'),
(43396, 4, 0, 'No, not yet.', 12, 0, 100, 274, 0, 20094, 43492, 'Lord Victor Nefarius'),
(43396, 5, 0, 'This object of your chagrin may still prove... valuable... to me.', 12, 0, 100, 273, 0, 20095, 43493, 'Lord Victor Nefarius'),
(43396, 6, 0, 'Leave now, pathetic alchemist. I anxiously await your next failure.', 12, 0, 100, 21, 0, 20096, 43494, 'Lord Victor Nefarius'),
(43404, 0, 0, 'My sincerest apologies for the disturbance, my liege. But I believe I have something you may be very interested in!', 12, 0, 100, 2, 0, 19860, 43495, 'Maloriak'),
(43404, 1, 0, 'Yes, yes! ', 12, 0, 100, 273, 0, 19861, 43496, 'Maloriak'),
(43404, 2, 0, 'By extracting agents from the blood of various dragonflights I have created a salve that will bestow the wearer sight beyond sight!', 12, 0, 100, 1, 0, 19862, 43497, 'Maloriak'),
(43404, 3, 0, 'Senses beyond this realm of mortality!', 12, 0, 100, 5, 0, 19863, 43514, 'Maloriak'),
(43404, 4, 0, 'Atramedes! Your master beckons.', 12, 0, 100, 25, 0, 19864, 43554, 'Maloriak'),
(43404, 5, 0, 'I present to you experiment number 25463-D!', 12, 0, 100, 21, 0, 19865, 43498, 'Maloriak'),
(43404, 6, 0, 'How could this be?! I will dispose of him immediately! \n', 12, 0, 100, 6, 0, 19866, 43502, 'Maloriak'),
(43404, 7, 0, 'Yes, my lord.', 12, 0, 100, 16, 0, 19867, 43553, 'Maloriak');
UPDATE `creature_text` SET `TextRange`= 1 WHERE `CreatureID` IN (43396, 43404);

DELETE FROM `conditions` WHERE `SourceEntry`= 81221 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`,  `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 81221, 0, 0, 31, 0, 3, 43407, 0, 0, 0, '', 'Apply Mixture - Target Atramedes');

-- Creature Lord Victor Nefarius 43396 SAI
SET @ENTRY := 43396;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 5900, 5900, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 5900 and 5900 ms) - Self: Talk 0 // "),
(@ENTRY, 0, 1, 0, 60, 0, 100, 1, 25400, 25400, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 25400 and 25400 ms) - Self: Talk 1 // "),
(@ENTRY, 0, 2, 0, 60, 0, 100, 1, 71400, 71400, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 71400 and 71400 ms) - Self: Talk 2 // "),
(@ENTRY, 0, 3, 0, 60, 0, 100, 1, 79900, 79900, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 79900 and 79900 ms) - Self: Talk 3 // "),
(@ENTRY, 0, 4, 0, 60, 0, 100, 1, 89800, 89800, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 89800 and 89800 ms) - Self: Talk 4 // "),
(@ENTRY, 0, 5, 0, 60, 0, 100, 1, 93400, 93400, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 93400 and 93400 ms) - Self: Talk 5 // "),
(@ENTRY, 0, 6, 0, 60, 0, 100, 1, 99700, 99700, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 99700 and 99700 ms) - Self: Talk 6 // ");

-- Creature Maloriak 43404 SAI
SET @ENTRY := 43404;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 15600, 15600, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 15600 and 15600 ms) - Self: Talk 0 // "),
(@ENTRY, 0, 1, 0, 60, 0, 100, 1, 30200, 30200, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 30200 and 30200 ms) - Self: Talk 1 // "),
(@ENTRY, 0, 2, 0, 60, 0, 100, 1, 32600, 32600, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 32600 and 32600 ms) - Self: Talk 2 // "),
(@ENTRY, 0, 3, 0, 60, 0, 100, 1, 42300, 42300, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 42300 and 42300 ms) - Self: Talk 3 // "),
(@ENTRY, 0, 4, 0, 60, 0, 100, 1, 47200, 47200, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 47200 and 47200 ms) - Self: Talk 4 // "),
(@ENTRY, 0, 5, 0, 60, 0, 100, 1, 53300, 53300, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 53300 and 53300 ms) - Self: Talk 5 // "),
(@ENTRY, 0, 6, 0, 60, 0, 100, 1, 59100, 59100, 0, 0, 11, 81217, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 59100 and 59100 ms) - Self: Cast spell Potion Hand (81217) on Self // "),
(@ENTRY, 0, 7, 0, 60, 0, 100, 1, 62600, 62600, 0, 0, 11, 81221, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 62600 and 62600 ms) - Self: Cast spell Apply Mixture (81221) on Self // "),
(@ENTRY, 0, 8, 0, 60, 0, 100, 1, 84800, 84800, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 84800 and 84800 ms) - Self: Talk 6 // "),
(@ENTRY, 0, 9, 0, 60, 0, 100, 1, 106900, 106900, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 106900 and 106900 ms) - Self: Talk 7 // ");

-- Creature Atramedes 43407 SAI
SET @ENTRY := 43407;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 53800, 53800, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 141.849, -220.95, 75.4534, 0, "Every 0 and 0 ms (for the first time, timer between 53800 and 53800 ms) - Self: Move to position (141.849, -220.95, 75.4534, 0) (point id 0) // "),
(@ENTRY, 0, 1, 0, 60, 0, 100, 1, 78800, 78800, 0, 0, 11, 81214, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 78800 and 78800 ms) - Self: Cast spell Blind Whelp (81214) on Self // "),
(@ENTRY, 0, 2, 0, 60, 0, 100, 1, 110400, 110400, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 136.0764, -207.6441, 75.45341, 4.764749, "Every 0 and 0 ms (for the first time, timer between 110400 and 110400 ms) - Self: Move to position (136.0764, -207.6441, 75.45341, 4.764749) (point id 0) // ");

