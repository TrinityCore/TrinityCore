UPDATE `spell_area` SET `flags`='3' WHERE  `spell`=79489 AND `area`=916 AND `quest_start`=0 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
DELETE FROM `spell_area` WHERE  `spell`=79489 AND `area`=40 AND `quest_start`=0 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES (79489, 40, 0, 0, 0, 0, 2, 3, 64, 11);

DELETE FROM `smart_scripts` WHERE  `entryorguid`=238 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `creature_template` SET `AIName`='' WHERE  `entry`=238;
DELETE FROM `creature_questender` WHERE  `id`=42309 AND `quest`=184;

DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=26209 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=28 AND `ConditionTarget`=0 AND `ConditionValue1`=184 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=26209 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=28 AND `ConditionTarget`=0 AND `ConditionValue1`=26378 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 26209, 0, 0, 28, 0, 184, 0, 0, 1, 0, 0, '', 'Quest Murder Was The Case That They Gave Me available if quest Furlbrow''s Deed has not been completed.'),
(19, 0, 26209, 0, 0, 28, 0, 26378, 0, 0, 1, 0, 0, '', 'Quest Murder Was The Case That They Gave Me available if quest Hero''s Call: Westfall! has not been completed.');

DELETE FROM `creature_text` WHERE `CreatureID`=42309 AND `GroupID` IN (0, 1, 2);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42309, 0, 0, 'It\'s a bloodbath, lieutenant. They\'ve been murdered.', 12, 7, 100, 1, 0, 0, 42224, 'Stormwind Investigator to Player'),
(42309, 1, 0, 'Given the body temperature, I\'d say they\'ve been dead no more than 6 hours.', 12, 7, 100, 0, 0, 0, 42225, 'Stormwind Investigator to Player'),
(42309, 2, 0, 'Damn shame what they did to Old Blanchy...', 12, 7, 100, 0, 0, 0, 42226, 'Stormwind Investigator to Player');

DELETE FROM `creature_text` WHERE `CreatureID`=42308 AND `GroupID` IN (0, 1, 2);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42308, 0, 0, 'No kidding, rookie...', 12, 7, 100, 273, 0, 0, 42227, 'Lieutenant Horatio Laine to Player'),
(42308, 1, 0, 'Looks like they really put the cart...', 12, 7, 100, 0, 0, 0, 42228, 'Lieutenant Horatio Laine to Player'),
(42308, 2, 0, '...before the horse.', 12, 7, 100, 0, 0, 0, 42229, 'Lieutenant Horatio Laine to Player');

-- AreaTrigger (-9852,38, 913,161, 30,0694) 5983 SAI
SET @ENTRY := 5983;
DELETE FROM `areatrigger_scripts` WHERE `entry`=@ENTRY;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES (@ENTRY,"SmartTrigger");
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 2, 0, 0, 46, 0, 100, 0, 5983, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 276258, 42308, 0, 0, 0, 0, 0, "On trigger - Creature Lieutenant Horatio Laine 42308 (276258): Set creature data #1 to 1 // ");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=5983 AND SourceId = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22, 1, 5983, 2, 0, 14, 0, 26209, 0, 0, 0, "", "If Invoker has never finished not has active quest Murder Was The Case That They Gave Me (26209)");

-- Creature Lieutenant Horatio Laine 42308 SAI
SET @ENTRY := 42308;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On data 1 set to 1 - Self: Set walk // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 4230800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #4230800 // "),
(@ENTRY, 0, 2, 0, 34, 0, 100, 0, 8, 1, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type POINT_MOTION_TYPE inform, point 1 - Self: Set UNIT_FIELD_BYTES_1 to 8 // "),
(@ENTRY, 0, 3, 0, 34, 0, 100, 0, 8, 2, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type POINT_MOTION_TYPE inform, point 2 - Self: Look at home position // ");

-- TimedActionList  4230800 SAI
SET @ENTRY := 4230800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 10, 276261, 42309, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Creature Stormwind Investigator 42309 (276261): Set creature data #0 to 1 // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 276261, 42309, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 7000 and 7000 ms (and later repeats every 0 and 0 ms) - Creature Stormwind Investigator 42309 (276261): Set creature data #1 to 1 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 45, 2, 1, 0, 0, 0, 0, 10, 276238, 42309, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 7000 and 7000 ms (and later repeats every 0 and 0 ms) - Creature Stormwind Investigator 42309 (276238): Set creature data #2 to 1 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, -9851.94, 910.24, 29.9428, 0, "When in combat and timer at the begining between 6000 and 6000 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-9851.94, 910.24, 29.9428, 0) (point id 1) // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 150, 150, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 150 and 150 ms (and later repeats every 0 and 0 ms) - None: Talk 0 // "),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 5000 ms (and later repeats every 0 and 0 ms) - None: Talk 1 // "),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 85, 78935, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1500 and 1500 ms (and later repeats every 0 and 0 ms) - Cast spell Horatio's Sunglasses (78935) to themself // "),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 2300, 2300, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2300 and 2300 ms (and later repeats every 0 and 0 ms) - None: Talk 2 // "),
(@ENTRY, 9, 8, 0, 0, 0, 100, 0, 10500, 10500, 0, 0, 69, 2, 0, 0, 0, 0, 0, 8, 0, 0, 0, -9849.856, 914.9618, 30.27025, 0, "When in combat and timer at the begining between 10500 and 10500 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-9849.856, 914.9618, 30.27025, 0) (point id 2) // "),
(@ENTRY, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Remove 8 bytes from UNIT_FIELD_BYTES_1 // "),
(@ENTRY, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 78935, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Remove aura due to spell Horatio's Sunglasses (78935) // ");

-- Creature Stormwind Investigator 42309 SAI
SET @ENTRY := 42309;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 38, 0, 100, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On data 0 set to 1 - None: Talk 0 // "),
(@ENTRY, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On data 1 set to 1 - None: Talk 1 // "),
(@ENTRY, 0, 2, 0, 38, 0, 100, 0, 2, 1, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On data 2 set to 1 - None: Talk 2 // ");

DELETE FROM `creature_addon` WHERE `guid` = 276261;
INSERT INTO `creature_addon` (`guid`, `bytes1`, `bytes2`, `auras`) VALUES (276261, 65544, 1, '79488');

DELETE FROM `creature` WHERE  `guid`=290969;
DELETE FROM `creature` WHERE  `guid`=290984;
DELETE FROM `creature` WHERE  `guid`=290982;
DELETE FROM `creature` WHERE  `guid`=275867;
DELETE FROM `creature` WHERE  `guid`=275799;
DELETE FROM `creature` WHERE  `guid`=290970;
DELETE FROM `creature` WHERE  `guid`=275802;
DELETE FROM `creature` WHERE  `guid`=290971;
DELETE FROM `creature` WHERE  `guid`=275867;
DELETE FROM `creature` WHERE  `guid`=290975;
DELETE FROM `creature` WHERE  `guid`=275865;
DELETE FROM `creature_addon` WHERE  `guid`=290969;
DELETE FROM `creature_addon` WHERE  `guid`=290984;
DELETE FROM `creature_addon` WHERE  `guid`=290982;
DELETE FROM `creature_addon` WHERE  `guid`=275867;
DELETE FROM `creature_addon` WHERE  `guid`=275799;
DELETE FROM `creature_addon` WHERE  `guid`=290970;
DELETE FROM `creature_addon` WHERE  `guid`=275802;
DELETE FROM `creature_addon` WHERE  `guid`=290971;
DELETE FROM `creature_addon` WHERE  `guid`=275867;
DELETE FROM `creature_addon` WHERE  `guid`=290975;
DELETE FROM `creature_addon` WHERE  `guid`=275865;
UPDATE `creature` SET `position_x`=-9817.26, `position_y`=973.67, `position_z`=29.12 WHERE  `guid`=275866;
UPDATE `creature` SET `npcflag`= `npcflag` | 1, `spawndist`=10, `MovementType`=1, `ScriptName`='npc_westfall_hobo_witness' WHERE  `guid`=276255;
UPDATE `creature` SET `npcflag`= `npcflag` | 1, `spawndist`=10, `MovementType`=1, `ScriptName`='npc_westfall_hobo_witness' WHERE  `guid`=276254;
UPDATE `creature` SET `npcflag`= `npcflag` | 1, `spawndist`=10, `MovementType`=1, `ScriptName`='npc_westfall_hobo_witness' WHERE  `guid`=276230;
UPDATE `creature` SET `npcflag`= `npcflag` | 1, `spawndist`=10, `MovementType`=1, `ScriptName`='npc_westfall_hobo_witness' WHERE  `guid`=290974;
UPDATE `creature` SET `npcflag`= `npcflag` | 1, `spawndist`=10, `MovementType`=1, `ScriptName`='npc_westfall_hobo_witness' WHERE  `guid`=290981;
UPDATE `creature` SET `npcflag`= `npcflag` | 1, `spawndist`=10, `MovementType`=1, `ScriptName`='npc_westfall_hobo_witness' WHERE  `guid`=275868;
UPDATE `creature` SET `npcflag`= `npcflag` | 1, `spawndist`=10, `MovementType`=1, `ScriptName`='npc_westfall_hobo_witness' WHERE  `guid`=290980;
UPDATE `creature` SET `npcflag`= `npcflag` | 1, `spawndist`=10, `MovementType`=1, `ScriptName`='npc_westfall_hobo_witness' WHERE  `guid`=276028;
UPDATE `creature` SET `npcflag`= `npcflag` | 1, `spawndist`=10, `MovementType`=1, `ScriptName`='npc_westfall_hobo_witness' WHERE  `guid`=290985;
UPDATE `creature` SET `npcflag`= `npcflag` | 1, `spawndist`=10, `MovementType`=1, `ScriptName`='npc_westfall_hobo_witness' WHERE  `guid`=290972;
UPDATE `creature` SET `npcflag`= `npcflag` | 1, `spawndist`=10, `MovementType`=1, `ScriptName`='npc_westfall_hobo_witness' WHERE  `guid`=275869;
UPDATE `creature` SET `npcflag`= `npcflag` | 1, `spawndist`=10, `MovementType`=1, `ScriptName`='npc_westfall_hobo_witness' WHERE  `guid`=275866;

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42371, `OptionType`=1, `OptionNpcFlag`=1 WHERE (`MenuId`=11635 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42370, `OptionType`=1, `OptionNpcFlag`=1 WHERE (`MenuId`=11635 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_box` SET `BoxBroadcastTextId`=42373 WHERE  `MenuId`=11635 AND `OptionIndex`=1;

-- Condition for source Gossip menu option condition type Quest taken
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11635 AND `SourceEntry`=0 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 11635, 0, 0, 0, 9, 0, 26209, 0, 0, 0, 0, 0, '', 'Show gossip menu 11635 option id 0 if quest Murder Was The Case That They Gave Me has been taken.'),
(15, 11635, 0, 0, 0, 28, 0, 26209, 0, 0, 1, 0, 0, '', 'Show gossip menu 11635 option id 0 if quest Murder Was The Case That They Gave Me has not been completed.');

-- Condition for source Gossip menu option condition type Quest taken
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11635 AND `SourceEntry`=1 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 11635, 1, 0, 0, 9, 0, 26209, 0, 0, 0, 0, 0, '', 'Show gossip menu 11635 option id 1 if quest Murder Was The Case That They Gave Me has been taken.'),
(15, 11635, 1, 0, 0, 28, 0, 26209, 0, 0, 1, 0, 0, '', 'Show gossip menu 11635 option id 1 if quest Murder Was The Case That They Gave Me has not been completed.');

DELETE FROM `creature_text` WHERE `CreatureID` IN (42386, 42384, 42391, 42383, 42413) AND `GroupID` IN (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- CLUES
(42386, 0, 0, 'Listen, $g pal:lady;, I don\'t want any trouble, ok? I didn\'t see who murdered \'em, but I sure heard it! Lot of yelling. Human voices... you dig? Now get out of here before I change my mind about beating you up and takin\' your shoes.', 12, 0, 100, 396, 0, 0, 42380, 'Homeless Stormwind Citizen to Player'),
(42386, 1, 0, 'I didn\'t see who killed \'em, $g bub:lady;, but I got a whiff. Smelled rich, kinda like you. Damn shame too. Furlbrows were a fixture around here. Nice people, always willin\' to share a meal or a patch of dirt.', 12, 0, 100, 396, 0, 0, 42381, 'Homeless Stormwind Citizen to Player'),
(42386, 2, 0, 'Who killed the Furlbrows? I\'ll tell you who killed the Furlbrows: KING VARIAN WRYNN, THAT\'S WHO! And he\'s killin\' the rest of us too. One bum at a time. The only thing I can tell you is that I saw some gnolls leavin\' the place a few hours before the law arrived.', 12, 0, 100, 5, 0, 0, 42382, 'Homeless Stormwind Citizen to Player'),
(42386, 3, 0, 'Between you, me, and the tree, murlocs killed the Furlbrows. Yep, saw \'em with my own two eyes. Think they\'d been casin\' the joint for days, maybe months. They left in a hurry once they got wind of \"Johnny Law\" and the idiot brigade over there...', 12, 0, 100, 273, 0, 0, 42383, 'Homeless Stormwind Citizen to Player'),
(42384, 0, 0, 'Listen, $g pal:lady;, I don\'t want any trouble, ok? I didn\'t see who murdered \'em, but I sure heard it! Lot of yelling. Human voices... you dig? Now get out of here before I change my mind about beating you up and takin\' your shoes.', 12, 0, 100, 396, 0, 0, 42380, 'Homeless Stormwind Citizen to Player'),
(42384, 1, 0, 'I didn\'t see who killed \'em, $g bub:lady;, but I got a whiff. Smelled rich, kinda like you. Damn shame too. Furlbrows were a fixture around here. Nice people, always willin\' to share a meal or a patch of dirt.', 12, 0, 100, 396, 0, 0, 42381, 'Homeless Stormwind Citizen to Player'),
(42384, 2, 0, 'Who killed the Furlbrows? I\'ll tell you who killed the Furlbrows: KING VARIAN WRYNN, THAT\'S WHO! And he\'s killin\' the rest of us too. One bum at a time. The only thing I can tell you is that I saw some gnolls leavin\' the place a few hours before the law arrived.', 12, 0, 100, 5, 0, 0, 42382, 'Homeless Stormwind Citizen to Player'),
(42384, 3, 0, 'Between you, me, and the tree, murlocs killed the Furlbrows. Yep, saw \'em with my own two eyes. Think they\'d been casin\' the joint for days, maybe months. They left in a hurry once they got wind of \"Johnny Law\" and the idiot brigade over there...', 12, 0, 100, 273, 0, 0, 42383, 'Homeless Stormwind Citizen to Player'),
(42391, 0, 0, 'Listen, $g pal:lady;, I don\'t want any trouble, ok? I didn\'t see who murdered \'em, but I sure heard it! Lot of yelling. Human voices... you dig? Now get out of here before I change my mind about beating you up and takin\' your shoes.', 12, 0, 100, 396, 0, 0, 42380, 'West Plains Drifter to Player'),
(42391, 1, 0, 'I didn\'t see who killed \'em, $g bub:lady;, but I got a whiff. Smelled rich, kinda like you. Damn shame too. Furlbrows were a fixture around here. Nice people, always willin\' to share a meal or a patch of dirt.', 12, 0, 100, 396, 0, 0, 42381, 'West Plains Drifter to Player'),
(42391, 2, 0, 'Who killed the Furlbrows? I\'ll tell you who killed the Furlbrows: KING VARIAN WRYNN, THAT\'S WHO! And he\'s killin\' the rest of us too. One bum at a time. The only thing I can tell you is that I saw some gnolls leavin\' the place a few hours before the law arrived.', 12, 0, 100, 5, 0, 0, 42382, 'West Plains Drifter to Player'),
(42391, 3, 0, 'Between you, me, and the tree, murlocs killed the Furlbrows. Yep, saw \'em with my own two eyes. Think they\'d been casin\' the joint for days, maybe months. They left in a hurry once they got wind of \"Johnny Law\" and the idiot brigade over there...', 12, 0, 100, 273, 0, 0, 42383, 'West Plains Drifter to Player'),
(42383, 0, 0, 'Listen, $g pal:lady;, I don\'t want any trouble, ok? I didn\'t see who murdered \'em, but I sure heard it! Lot of yelling. Human voices... you dig? Now get out of here before I change my mind about beating you up and takin\' your shoes.', 12, 0, 100, 396, 0, 0, 42380, 'Transient to Player'),
(42383, 1, 0, 'I didn\'t see who killed \'em, $g bub:lady;, but I got a whiff. Smelled rich, kinda like you. Damn shame too. Furlbrows were a fixture around here. Nice people, always willin\' to share a meal or a patch of dirt.', 12, 0, 100, 396, 0, 0, 42381, 'Transient to Player'),
(42383, 2, 0, 'Who killed the Furlbrows? I\'ll tell you who killed the Furlbrows: KING VARIAN WRYNN, THAT\'S WHO! And he\'s killin\' the rest of us too. One bum at a time. The only thing I can tell you is that I saw some gnolls leavin\' the place a few hours before the law arrived.', 12, 0, 100, 5, 0, 0, 42382, 'Transient to Player'),
(42383, 3, 0, 'Between you, me, and the tree, murlocs killed the Furlbrows. Yep, saw \'em with my own two eyes. Think they\'d been casin\' the joint for days, maybe months. They left in a hurry once they got wind of \"Johnny Law\" and the idiot brigade over there...', 12, 0, 100, 273, 0, 0, 42383, 'Transient to Player'),
-- AGGRO ON CONVINCE BRIBE
(42386, 4, 0, 'Judgment day comes! The brotherhood will be reborn!', 12, 7, 100, 0, 0, 0, 42379, 'Homeless Stormwind Citizen to Player'),
(42386, 4, 1, 'Now you\'ve gone and done it! TIME FOR THE FIST!', 12, 7, 100, 0, 0, 0, 42389, 'Homeless Stormwind Citizen to Player'),
(42386, 4, 2, 'You\'ll get nothing out of me!', 12, 7, 100, 0, 0, 0, 42378, 'Homeless Stormwind Citizen to Player'),
(42386, 4, 3, 'Livin\' like an animal is hard enough without your insults!', 12, 7, 100, 0, 0, 0, 42386, 'Homeless Stormwind Citizen to Player'),
(42386, 4, 4, 'I ain\'t tellin\' you a damn thing!', 12, 7, 100, 0, 0, 0, 42385, 'Homeless Stormwind Citizen to Player'),
(42386, 4, 5, 'Maybe I can sell your liver for some gold.', 12, 7, 100, 0, 0, 0, 42387, 'Homeless Stormwind Citizen to Player'),
(42386, 4, 6, 'You want my foot in your front or in your rear? Make the call.', 12, 7, 100, 0, 0, 0, 42390, 'Homeless Stormwind Citizen to Player'),
(42386, 4, 7, 'They died of natural causes...', 12, 7, 100, 0, 0, 0, 42377, 'Homeless Stormwind Citizen to Player'),
(42386, 4, 8, 'You rich punks are all the same!', 12, 7, 100, 0, 0, 0, 42384, 'Homeless Stormwind Citizen to Player'),
(42386, 4, 9, 'You can\'t buy me! DIE!', 12, 7, 100, 0, 0, 0, 42374, 'Homeless Stormwind Citizen to Player'),
(42384, 4, 0, 'Judgment day comes! The brotherhood will be reborn!', 12, 7, 100, 0, 0, 0, 42379, 'Homeless Stormwind Citizen to Player'),
(42384, 4, 1, 'Now you\'ve gone and done it! TIME FOR THE FIST!', 12, 7, 100, 0, 0, 0, 42389, 'Homeless Stormwind Citizen to Player'),
(42384, 4, 2, 'You\'ll get nothing out of me!', 12, 7, 100, 0, 0, 0, 42378, 'Homeless Stormwind Citizen to Player'),
(42384, 4, 3, 'Livin\' like an animal is hard enough without your insults!', 12, 7, 100, 0, 0, 0, 42386, 'Homeless Stormwind Citizen to Player'),
(42384, 4, 4, 'I ain\'t tellin\' you a damn thing!', 12, 7, 100, 0, 0, 0, 42385, 'Homeless Stormwind Citizen to Player'),
(42384, 4, 5, 'Maybe I can sell your liver for some gold.', 12, 7, 100, 0, 0, 0, 42387, 'Homeless Stormwind Citizen to Player'),
(42384, 4, 6, 'You want my foot in your front or in your rear? Make the call.', 12, 7, 100, 0, 0, 0, 42390, 'Homeless Stormwind Citizen to Player'),
(42384, 4, 7, 'They died of natural causes...', 12, 7, 100, 0, 0, 0, 42377, 'Homeless Stormwind Citizen to Player'),
(42384, 4, 8, 'You rich punks are all the same!', 12, 7, 100, 0, 0, 0, 42384, 'Homeless Stormwind Citizen to Player'),
(42384, 4, 9, 'You can\'t buy me! DIE!', 12, 7, 100, 0, 0, 0, 42374, 'Homeless Stormwind Citizen to Player'),
(42391, 4, 0, 'Judgment day comes! The brotherhood will be reborn!', 12, 7, 100, 0, 0, 0, 42379, 'West Plains Drifter to Player'),
(42391, 4, 1, 'Now you\'ve gone and done it! TIME FOR THE FIST!', 12, 7, 100, 0, 0, 0, 42389, 'West Plains Drifter to Player'),
(42391, 4, 2, 'You\'ll get nothing out of me!', 12, 7, 100, 0, 0, 0, 42378, 'West Plains Drifter to Player'),
(42391, 4, 3, 'Livin\' like an animal is hard enough without your insults!', 12, 7, 100, 0, 0, 0, 42386, 'West Plains Drifter to Player'),
(42391, 4, 4, 'I ain\'t tellin\' you a damn thing!', 12, 7, 100, 0, 0, 0, 42385, 'West Plains Drifter to Player'),
(42391, 4, 5, 'Maybe I can sell your liver for some gold.', 12, 7, 100, 0, 0, 0, 42387, 'West Plains Drifter to Player'),
(42391, 4, 6, 'You want my foot in your front or in your rear? Make the call.', 12, 7, 100, 0, 0, 0, 42390, 'West Plains Drifter to Player'),
(42391, 4, 7, 'They died of natural causes...', 12, 7, 100, 0, 0, 0, 42377, 'West Plains Drifter to Player'),
(42391, 4, 8, 'You rich punks are all the same!', 12, 7, 100, 0, 0, 0, 42384, 'West Plains Drifter to Player'),
(42391, 4, 9, 'You can\'t buy me! DIE!', 12, 7, 100, 0, 0, 0, 42374, 'West Plains Drifter to Player'),
(42383, 4, 0, 'Judgment day comes! The brotherhood will be reborn!', 12, 7, 100, 0, 0, 0, 42379, 'Transient to Player'),
(42383, 4, 1, 'Now you\'ve gone and done it! TIME FOR THE FIST!', 12, 7, 100, 0, 0, 0, 42389, 'Transient to Player'),
(42383, 4, 2, 'You\'ll get nothing out of me!', 12, 7, 100, 0, 0, 0, 42378, 'Transient to Player'),
(42383, 4, 3, 'Livin\' like an animal is hard enough without your insults!', 12, 7, 100, 0, 0, 0, 42386, 'Transient to Player'),
(42383, 4, 4, 'I ain\'t tellin\' you a damn thing!', 12, 7, 100, 0, 0, 0, 42385, 'Transient to Player'),
(42383, 4, 5, 'Maybe I can sell your liver for some gold.', 12, 7, 100, 0, 0, 0, 42387, 'Transient to Player'),
(42383, 4, 6, 'You want my foot in your front or in your rear? Make the call.', 12, 7, 100, 0, 0, 0, 42390, 'Transient to Player'),
(42383, 4, 7, 'They died of natural causes...', 12, 7, 100, 0, 0, 0, 42377, 'Transient to Player'),
(42383, 4, 8, 'You rich punks are all the same!', 12, 7, 100, 0, 0, 0, 42384, 'Transient to Player'),
(42383, 4, 9, 'You can\'t buy me! DIE!', 12, 7, 100, 0, 0, 0, 42374, 'Transient to Player'),
-- AGGRO ON CONVINCE TALK
(42386, 5, 0, 'Judgment day comes! The brotherhood will be reborn!', 12, 7, 100, 0, 0, 0, 42379, 'Homeless Stormwind Citizen to Player'),
(42386, 5, 1, 'Now you\'ve gone and done it! TIME FOR THE FIST!', 12, 7, 100, 0, 0, 0, 42389, 'Homeless Stormwind Citizen to Player'),
(42386, 5, 2, 'You\'ll get nothing out of me!', 12, 7, 100, 0, 0, 0, 42378, 'Homeless Stormwind Citizen to Player'),
(42386, 5, 3, 'Livin\' like an animal is hard enough without your insults!', 12, 7, 100, 0, 0, 0, 42386, 'Homeless Stormwind Citizen to Player'),
(42386, 5, 4, 'I ain\'t tellin\' you a damn thing!', 12, 7, 100, 0, 0, 0, 42385, 'Homeless Stormwind Citizen to Player'),
(42386, 5, 5, 'Maybe I can sell your liver for some gold.', 12, 7, 100, 0, 0, 0, 42387, 'Homeless Stormwind Citizen to Player'),
(42386, 5, 6, 'You want my foot in your front or in your rear? Make the call.', 12, 7, 100, 0, 0, 0, 42390, 'Homeless Stormwind Citizen to Player'),
(42386, 5, 7, 'They died of natural causes...', 12, 7, 100, 0, 0, 0, 42377, 'Homeless Stormwind Citizen to Player'),
(42386, 5, 8, 'You rich punks are all the same!', 12, 7, 100, 0, 0, 0, 42384, 'Homeless Stormwind Citizen to Player'),
(42386, 5, 9, 'I TOLD YOU TO PAY UP, PAL!', 12, 7, 100, 0, 0, 0, 42388, 'Homeless Stormwind Citizen to Player'),
(42384, 5, 0, 'Judgment day comes! The brotherhood will be reborn!', 12, 7, 100, 0, 0, 0, 42379, 'Homeless Stormwind Citizen to Player'),
(42384, 5, 1, 'Now you\'ve gone and done it! TIME FOR THE FIST!', 12, 7, 100, 0, 0, 0, 42389, 'Homeless Stormwind Citizen to Player'),
(42384, 5, 2, 'You\'ll get nothing out of me!', 12, 7, 100, 0, 0, 0, 42378, 'Homeless Stormwind Citizen to Player'),
(42384, 5, 3, 'Livin\' like an animal is hard enough without your insults!', 12, 7, 100, 0, 0, 0, 42386, 'Homeless Stormwind Citizen to Player'),
(42384, 5, 4, 'I ain\'t tellin\' you a damn thing!', 12, 7, 100, 0, 0, 0, 42385, 'Homeless Stormwind Citizen to Player'),
(42384, 5, 5, 'Maybe I can sell your liver for some gold.', 12, 7, 100, 0, 0, 0, 42387, 'Homeless Stormwind Citizen to Player'),
(42384, 5, 6, 'You want my foot in your front or in your rear? Make the call.', 12, 7, 100, 0, 0, 0, 42390, 'Homeless Stormwind Citizen to Player'),
(42384, 5, 7, 'They died of natural causes...', 12, 7, 100, 0, 0, 0, 42377, 'Homeless Stormwind Citizen to Player'),
(42384, 5, 8, 'You rich punks are all the same!', 12, 7, 100, 0, 0, 0, 42384, 'Homeless Stormwind Citizen to Player'),
(42384, 5, 9, 'I TOLD YOU TO PAY UP, PAL!', 12, 7, 100, 0, 0, 0, 42388, 'Homeless Stormwind Citizen to Player'),
(42391, 5, 0, 'Judgment day comes! The brotherhood will be reborn!', 12, 7, 100, 0, 0, 0, 42379, 'West Plains Drifter to Player'),
(42391, 5, 1, 'Now you\'ve gone and done it! TIME FOR THE FIST!', 12, 7, 100, 0, 0, 0, 42389, 'West Plains Drifter to Player'),
(42391, 5, 2, 'You\'ll get nothing out of me!', 12, 7, 100, 0, 0, 0, 42378, 'West Plains Drifter to Player'),
(42391, 5, 3, 'Livin\' like an animal is hard enough without your insults!', 12, 7, 100, 0, 0, 0, 42386, 'West Plains Drifter to Player'),
(42391, 5, 4, 'I ain\'t tellin\' you a damn thing!', 12, 7, 100, 0, 0, 0, 42385, 'West Plains Drifter to Player'),
(42391, 5, 5, 'Maybe I can sell your liver for some gold.', 12, 7, 100, 0, 0, 0, 42387, 'West Plains Drifter to Player'),
(42391, 5, 6, 'You want my foot in your front or in your rear? Make the call.', 12, 7, 100, 0, 0, 0, 42390, 'West Plains Drifter to Player'),
(42391, 5, 7, 'They died of natural causes...', 12, 7, 100, 0, 0, 0, 42377, 'West Plains Drifter to Player'),
(42391, 5, 8, 'You rich punks are all the same!', 12, 7, 100, 0, 0, 0, 42384, 'West Plains Drifter to Player'),
(42391, 5, 9, 'I TOLD YOU TO PAY UP, PAL!', 12, 7, 100, 0, 0, 0, 42388, 'West Plains Drifter'),
(42383, 5, 0, 'Judgment day comes! The brotherhood will be reborn!', 12, 7, 100, 0, 0, 0, 42379, 'Transient to Player'),
(42383, 5, 1, 'Now you\'ve gone and done it! TIME FOR THE FIST!', 12, 7, 100, 0, 0, 0, 42389, 'Transient to Player'),
(42383, 5, 2, 'You\'ll get nothing out of me!', 12, 7, 100, 0, 0, 0, 42378, 'Transient to Player'),
(42383, 5, 3, 'Livin\' like an animal is hard enough without your insults!', 12, 7, 100, 0, 0, 0, 42386, 'Transient to Player'),
(42383, 5, 4, 'I ain\'t tellin\' you a damn thing!', 12, 7, 100, 0, 0, 0, 42385, 'Transient to Player'),
(42383, 5, 5, 'Maybe I can sell your liver for some gold.', 12, 7, 100, 0, 0, 0, 42387, 'Transient to Player'),
(42383, 5, 6, 'You want my foot in your front or in your rear? Make the call.', 12, 7, 100, 0, 0, 0, 42390, 'Transient to Player'),
(42383, 5, 7, 'They died of natural causes...', 12, 7, 100, 0, 0, 0, 42377, 'Transient to Player'),
(42383, 5, 8, 'You rich punks are all the same!', 12, 7, 100, 0, 0, 0, 42384, 'Transient to Player'),
(42383, 5, 9, 'I TOLD YOU TO PAY UP, PAL!', 12, 7, 100, 0, 0, 0, 42388, 'Transient to Player'),
-- EVENT
(42386, 6, 0, 'Looks like we\'ll be eating shoe leather for dinner again.', 12, 7, 100, 396, 0, 0, 42358, 'Homeless Stormwind Citizen'),
(42386, 6, 1, 'HAHAHAH! Good one, Mr. Penguin! GOOD ONE!', 12, 7, 100, 153, 0, 0, 42354, 'Homeless Stormwind Citizen'),
(42386, 6, 2, 'What happened to me? I used to be the king of Stormwind!', 12, 7, 100, 15, 0, 0, 42357, 'Homeless Stormwind Citizen'),
(42386, 6, 3, 'I don\'t think I\'m gonna make it...', 12, 7, 100, 18, 0, 0, 42356, 'Homeless Stormwind Citizen'),
(42386, 6, 4, 'Get off my land!', 12, 7, 100, 397, 0, 0, 42355, 'Homeless Stormwind Citizen'),
(42386, 6, 5, 'I miss being robbed by the Defias. At least they\'d leave you a little something to eat from time to time.', 12, 7, 100, 396, 0, 0, 42360, 'Homeless Stormwind Citizen'),
(42386, 6, 6, 'I\'m starving!', 12, 7, 100, 5, 0, 0, 42353, 'Homeless Stormwind Citizen'),
(42386, 6, 7, 'I wonder if it\'s possible to eat rocks? Got plenty of rocks around here. Just imagine it! I\'d be the richest person in the world for making that discovery!', 12, 7, 100, 4, 0, 0, 42359, 'Homeless Stormwind Citizen'),
(42386, 7, 0, 'JACKPOT!', 12, 7, 100, 5, 0, 0, 42351, 'Homeless Stormwind Citizen'),
(42386, 8, 0, 'Looks like I found us a savory and clean piece of dirt! Tonight we eat like kings, Mr. Penguin! Of course I\'ll share it with you! You\'re my best friend!', 12, 7, 100, 18, 0, 0, 42352, 'Transient'),
(42386, 9, 0, 'HEY! HEY YOU! GET OFF MY PROPERTY!', 12, 7, 100, 22, 0, 0, 42361, 'Homeless Stormwind Citizen'),
(42386, 10, 0, '%s attempts to run away in fear!', 16, 0, 100, 0, 0, 0, 1150, 'Homeless Stormwind Citizen'),
(42384, 6, 0, 'Looks like we\'ll be eating shoe leather for dinner again.', 12, 7, 100, 396, 0, 0, 42358, 'Homeless Stormwind Citizen'),
(42384, 6, 1, 'HAHAHAH! Good one, Mr. Penguin! GOOD ONE!', 12, 7, 100, 153, 0, 0, 42354, 'Homeless Stormwind Citizen'),
(42384, 6, 2, 'What happened to me? I used to be the king of Stormwind!', 12, 7, 100, 15, 0, 0, 42357, 'Homeless Stormwind Citizen'),
(42384, 6, 3, 'I don\'t think I\'m gonna make it...', 12, 7, 100, 18, 0, 0, 42356, 'Homeless Stormwind Citizen'),
(42384, 6, 4, 'Get off my land!', 12, 7, 100, 397, 0, 0, 42355, 'Homeless Stormwind Citizen'),
(42384, 6, 5, 'I miss being robbed by the Defias. At least they\'d leave you a little something to eat from time to time.', 12, 7, 100, 396, 0, 0, 42360, 'Homeless Stormwind Citizen'),
(42384, 6, 6, 'I\'m starving!', 12, 7, 100, 5, 0, 0, 42353, 'Homeless Stormwind Citizen'),
(42384, 6, 7, 'I wonder if it\'s possible to eat rocks? Got plenty of rocks around here. Just imagine it! I\'d be the richest person in the world for making that discovery!', 12, 7, 100, 4, 0, 0, 42359, 'Homeless Stormwind Citizen'),
(42384, 7, 0, 'JACKPOT!', 12, 7, 100, 5, 0, 0, 42351, 'Homeless Stormwind Citizen'),
(42384, 8, 0, 'Looks like I found us a savory and clean piece of dirt! Tonight we eat like kings, Mr. Penguin! Of course I\'ll share it with you! You\'re my best friend!', 12, 7, 100, 18, 0, 0, 42352, 'Homeless Stormwind Citizen'),
(42384, 9, 0, 'HEY! HEY YOU! GET OFF MY PROPERTY!', 12, 7, 100, 22, 0, 0, 42361, 'Homeless Stormwind Citizen'),
(42384, 10, 0, '%s attempts to run away in fear!', 16, 0, 100, 0, 0, 0, 1150, 'Homeless Stormwind Citizen'),
(42391, 6, 0, 'Looks like we\'ll be eating shoe leather for dinner again.', 12, 7, 100, 396, 0, 0, 42358, 'West Plains Drifter'),
(42391, 6, 1, 'HAHAHAH! Good one, Mr. Penguin! GOOD ONE!', 12, 7, 100, 153, 0, 0, 42354, 'West Plains Drifter'),
(42391, 6, 2, 'What happened to me? I used to be the king of Stormwind!', 12, 7, 100, 15, 0, 0, 42357, 'West Plains Drifter'),
(42391, 6, 3, 'I don\'t think I\'m gonna make it...', 12, 7, 100, 18, 0, 0, 42356, 'West Plains Drifter'),
(42391, 6, 4, 'Get off my land!', 12, 7, 100, 397, 0, 0, 42355, 'West Plains Drifter'),
(42391, 6, 5, 'I miss being robbed by the Defias. At least they\'d leave you a little something to eat from time to time.', 12, 7, 100, 396, 0, 0, 42360, 'West Plains Drifter'),
(42391, 6, 6, 'I\'m starving!', 12, 7, 100, 5, 0, 0, 42353, 'West Plains Drifter'),
(42391, 6, 7, 'I wonder if it\'s possible to eat rocks? Got plenty of rocks around here. Just imagine it! I\'d be the richest person in the world for making that discovery!', 12, 7, 100, 4, 0, 0, 42359, 'West Plains Drifter'),
(42391, 7, 0, 'JACKPOT!', 12, 7, 100, 5, 0, 0, 42351, 'West Plains Drifter'),
(42391, 8, 0, 'Looks like I found us a savory and clean piece of dirt! Tonight we eat like kings, Mr. Penguin! Of course I\'ll share it with you! You\'re my best friend!', 12, 7, 100, 18, 0, 0, 42352, 'West Plains Drifter'),
(42391, 9, 0, 'HEY! HEY YOU! GET OFF MY PROPERTY!', 12, 7, 100, 22, 0, 0, 42361, 'West Plains Drifter'),
(42391, 10, 0, '%s attempts to run away in fear!', 16, 0, 100, 0, 0, 0, 1150, 'West Plains Drifter'),
(42383, 6, 0, 'Looks like we\'ll be eating shoe leather for dinner again.', 12, 7, 100, 396, 0, 0, 42358, 'Transient'),
(42383, 6, 1, 'HAHAHAH! Good one, Mr. Penguin! GOOD ONE!', 12, 7, 100, 153, 0, 0, 42354, 'Transient'),
(42383, 6, 2, 'What happened to me? I used to be the king of Stormwind!', 12, 7, 100, 15, 0, 0, 42357, 'Transient'),
(42383, 6, 3, 'I don\'t think I\'m gonna make it...', 12, 7, 100, 18, 0, 0, 42356, 'Transient'),
(42383, 6, 4, 'Get off my land!', 12, 7, 100, 397, 0, 0, 42355, 'Transient'),
(42383, 6, 5, 'I miss being robbed by the Defias. At least they\'d leave you a little something to eat from time to time.', 12, 7, 100, 396, 0, 0, 42360, 'Transient'),
(42383, 6, 6, 'I\'m starving!', 12, 7, 100, 5, 0, 0, 42353, 'Transient'),
(42383, 6, 7, 'I wonder if it\'s possible to eat rocks? Got plenty of rocks around here. Just imagine it! I\'d be the richest person in the world for making that discovery!', 12, 7, 100, 4, 0, 0, 42359, 'Transient'),
(42383, 7, 0, 'JACKPOT!', 12, 7, 100, 5, 0, 0, 42351, 'Transient'),
(42383, 8, 0, 'Looks like I found us a savory and clean piece of dirt! Tonight we eat like kings, Mr. Penguin! Of course I\'ll share it with you! You\'re my best friend!', 12, 7, 100, 18, 0, 0, 42352, 'Transient'),
(42383, 9, 0, 'HEY! HEY YOU! GET OFF MY PROPERTY!', 12, 7, 100, 22, 0, 0, 42361, 'Transient'),
(42383, 10, 0, '%s attempts to run away in fear!', 16, 0, 100, 0, 0, 0, 1150, 'Transient'),
(42413, 0, 0, 'Check $g his:her; pockets!', 12, 7, 20, 0, 0, 0, 42364, 'Ragamuffin to Homeless Stormwind Citizen'),
(42413, 0, 1, 'Does $g he:she; have boots? Get \'em!', 12, 7, 20, 0, 0, 0, 42362, 'Ragamuffin to West Plains Drifter'),
(42413, 0, 2, 'MINE!', 12, 7, 20, 0, 0, 0, 42363, 'Ragamuffin to West Plains Drifter');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (79169, 79168);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(79169, 'spell_westfall_summon_ragamuffin_looter'),
(79168, 'spell_westfall_aggro_hobo');

UPDATE `creature_template` SET `unit_flags`=33536 WHERE  `entry`=42413;

-- Creature Ragamuffin 42413 SAI
SET @ENTRY := 42413;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "On just summoned - Self: Look at Owner/Summoner // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 2500, 2500, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 2500 - 2500 ms with 100% chance // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 10000, 10000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #1 in 10000 - 10000 ms with 100% chance // "),
(@ENTRY, 0, 3, 4, 59, 0, 100, 0, 0, 0, 0, 0, 125, 2, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Triggers Events randomly with Timed EventId between 2 and 5 // "),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 114, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1.5, 0, 0, " Linked - Use  target_x,  target_y,  target_z, With target_type=1 // "),
(@ENTRY, 0, 5, 0, 59, 0, 100, 0, 1, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 1 triggered - Self: Despawn instantly // "),
(@ENTRY, 0, 6, 0, 34, 0, 100, 0, 0, 0, 0, 0, 128, 649, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement inform - Self: Plays Anim with ID 649 // "),
(@ENTRY, 0, 7, 0, 59, 0, 100, 0, 2, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "On timed event 2 triggered - Owner/Summoner: Talk 0 // ");
