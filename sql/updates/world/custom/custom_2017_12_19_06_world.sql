-- Chains for Military District

-- Class Quests
UPDATE `quest_template_addon` SET `PrevQuestID`= 14099 WHERE `ID`= 14280;
UPDATE `quest_template_addon` SET `PrevQuestID`= 14099 WHERE `ID`= 14275;
UPDATE `quest_template_addon` SET `PrevQuestID`= 14099 WHERE `ID`= 14277;
UPDATE `quest_template_addon` SET `PrevQuestID`= 14099 WHERE `ID`= 14278;
UPDATE `quest_template_addon` SET `PrevQuestID`= 14099 WHERE `ID`= 14269;
UPDATE `quest_template_addon` SET `PrevQuestID`= 14099 WHERE `ID`= 14273;
UPDATE `quest_template_addon` SET `PrevQuestID`= 14099 WHERE `ID`= 14265;

DELETE FROM `quest_template_addon` WHERE `ID` IN (14157, 24930);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 19 AND `SourceEntry` IN (14157, 24930);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ElseGroup`) VALUES
-- Old Divisions
(19, 14157, 8, 14285, 0),
(19, 14157, 8, 14286, 1),
(19, 14157, 8, 14287, 2),
(19, 14157, 8, 14288, 3),
(19, 14157, 8, 14289, 4),
(19, 14157, 8, 14290, 5),
(19, 14157, 8, 14291, 6),
-- While you're at it
(19, 24930, 8, 14285, 0),
(19, 24930, 8, 14286, 1),
(19, 24930, 8, 14287, 2),
(19, 24930, 8, 14288, 3),
(19, 24930, 8, 14289, 4),
(19, 24930, 8, 14290, 5),
(19, 24930, 8, 14291, 6);

DELETE FROM `quest_template_addon` WHERE `ID` IN (14159, 14294, 14212);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`) VALUES
(14159, 26129, 0, 0),
(14294, 14293, 0, 0),
(14212, 14294, 0, 0);

-- Creature Lord Godfrey 35115 SAI
SET @ENTRY := 35115;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 19, 0, 100, 0, 24930, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When player accepts quest 24930 - Action invoker: Talk 0 // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 64, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Target_0 = Action invoker // "),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 35112, 10, 0, 0, 0, 0, 0, " Linked - Self: Send stored target 0 to Creature King Genn Greymane (35112) in 10 yd // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 35112, 10, 0, 0, 0, 0, 0, " Linked - Creature King Genn Greymane (35112) in 10 yd: Set creature data #0 to 1 // ");

-- Creature King Genn Greymane 35112 SAI
SET @ENTRY := 35112;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 38, 0, 100, 0, 0, 1, 0, 0, 67, 0, 5000, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On data 0 set to 1 - Trigger timed event #0 in 5000 - 5000 ms // "),
(@ENTRY, 0, 1, 0, 59, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - storedTarget[0]: Talk 0 // ");

DELETE FROM `creature_text` WHERE `CreatureID` IN (35112, 35115, 35378, 35550, 35905, 35907, 35906);
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(35112, 0, 0, 'Enough!  I''ve made up my mind.  We need Crowley on our side.', 12, 0, 100, 0, 0, 0, 38602, 'King Genn Greymane to Player'),
(35115, 0, 0, 'We ought to leave Crowley in prison with those beasts!', 12, 0, 100, 0, 0, 0, 38601, 'Lord Godfrey to Player'),
(35378, 0, 0, 'This mastiff will help you find the hidden worgen.', 12, 0, 100, 0, 0, 19696, 38744, 'Lorna Crowley to Player'),
(35550, 0, 0, 'Keep them back!', 14, 0, 100, 0, 0, 19712, 36092, 'King Genn Greymane'),
(35550, 0, 1, 'Fire!', 14, 0, 100, 0, 0, 19710, 36091, 'King Genn Greymane'),
(35550, 0, 2, 'Hold the barricades!  Do not give them an inch!', 14, 0, 100, 0, 0, 19709, 36090, 'King Genn Greymane'),
(35905, 0, 0, 'Rescue Krennan Aranas by using your vehicle''s ability.$B|TInterface\\Icons\\inv_misc_groupneedmore.blp:64|t', 42, 0, 100, 0, 0, 0, 36078, 'King Greymane''s Horse to Player'),
(35907, 0, 0, 'Thank you!  I owe you my life.', 12, 0, 100, 0, 0, 20922, 38729, 'Krennan Aranas to King Greymane''s Horse'),
(35906, 0, 0, 'We''ve got Aranas!  Fire at will!', 14, 0, 100, 0, 0, 19634, 36099, 'Lord Godfrey to Player');


DELETE FROM `creature` WHERE `id` IN (35456, 35457);

-- Creature Lord Darius Crowley 35077 SAI
SET @ENTRY := 35077;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 14154, 0, 0, 0, 11, 66914, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When player accepts quest 14154 - Self: Cast spell 66914 on Action invoker // ");

DELETE FROM `spell_area` WHERE `spell` IN (72870, 49416, 72872, 76642) AND `area` IN (4755, 4757, 4758, 4759, 4761);
INSERT INTO `spell_area` (`spell`, `area`, `gender`, `quest_start`, `quest_start_status`, `autocast`, `quest_end`, `quest_end_status`) VALUES
(72870, 4757, 2, 14159, 64, 1, 14293, 1|2|8|32),
(72870, 4758, 2, 14159, 64, 1, 14293, 1|2|8|32),
(49416, 4757, 2, 14159, 64, 1, 14221, 1|2|8|32),
(72872, 4757, 2, 14293, 64, 1, 14221, 1|2|8|32),
(72872, 4758, 2, 14293, 64, 1, 14221, 1|2|8|32),
(72872, 4759, 2, 14293, 64, 1, 14221, 1|2|8|32),
(72872, 4761, 2, 14293, 64, 1, 14221, 1|2|8|32),
(72872, 4755, 2, 14293, 64, 1, 14221, 1|2|8|32),
-- Last Stand
(76642, 4757, 2, 14221, 64, 1, 14222, 1|2|8|32),
(76642, 4758, 2, 14221, 64, 1, 14222, 1|2|8|32),
(76642, 4759, 2, 14221, 64, 1, 14222, 1|2|8|32),
(76642, 4761, 2, 14221, 64, 1, 14222, 1|2|8|32);

UPDATE `creature` SET `phaseId`= 0, `phaseGroup`= 367 WHERE `id` IN (35906);
UPDATE `creature` SET `phaseId`= 0, `phaseGroup`= 460 WHERE `id` IN (35229, 35317, 35566);
UPDATE `creature` SET `phaseId`= 172, `phaseGroup`= 0 WHERE `id` IN (35618, 36057);

-- Creature Wounded Guard 47091 SAI
SET @ENTRY := 47091;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, 774, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On spell 774 hit  - Action invoker: Give kill credit Spell Practice Credit (44175) // "),
(@ENTRY, 0, 1, 0, 8, 0, 100, 0, 2061, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On spell 2061 hit  - Action invoker: Give kill credit Spell Practice Credit (44175) // "),
(@ENTRY, 0, 2, 0, 1, 0, 100, 0, 1, 1, 30000, 30000, 11, 46577, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 1 and 1 ms (and later repeats every 30000 and 30000 ms) - Self: Cast spell 46577 on Self // ");

-- Creature Bloodfang Worgen 35118 SAI
SET @ENTRY := 35118;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell 8599 on Self // Bloodfang Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Bloodfang Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY, 0, 2, 0, 8, 0, 100, 0, 100, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On spell 100 hit  - Action invoker: Give kill credit Spell Practice Credit (44175) // "),
(@ENTRY, 0, 3, 0, 8, 0, 100, 0, 56641, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On spell 56641 hit  - Action invoker: Give kill credit Spell Practice Credit (44175) // "),
(@ENTRY, 0, 4, 0, 8, 0, 100, 0, 2098, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On spell 2098 hit  - Action invoker: Give kill credit Spell Practice Credit (44175) // "),
(@ENTRY, 0, 5, 0, 8, 0, 100, 0, 348, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On spell 348 hit  - Action invoker: Give kill credit Spell Practice Credit (44175) // "),
(@ENTRY, 0, 6, 0, 8, 0, 100, 0, 5143, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On spell 5143 hit  - Action invoker: Give kill credit Spell Practice Credit (44175) // ");

-- Creature Myriam Spellwaker 35872 SAI
SET @ENTRY := 35872;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Disable combat based movement // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 0, 0, 3000, 3000, 11, 11538, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 3000 and 3000 ms) - Self: Cast spell 11538 on Victim // ");

-- Creature Sergeant Cleese 35839 SAI
SET @ENTRY := 35839;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Disable combat based movement // ");

-- Creature Lorna Crowley 35378 SAI
SET @ENTRY := 35378;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 14204, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When player accepts quest 14204 - Action invoker: Talk 0 // ");

DELETE FROM `conditions` WHERE `SourceEntry` IN (67805, 68228, 68235) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO conditions (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 67805, 0, 0, 31, 0, 3, 35463, 0, 0, 0, '', 'Attack Lurker - Target Bloodfang Lurker'),
(13, 1, 68228, 0, 0, 31, 0, 3, 35753, 0, 0, 0, '', 'Rescue Krennan - Target Krennan'),
(13, 1, 68235, 0, 0, 31, 0, 3, 35916, 0, 0, 0, '', 'Cannon Fire - Target Bloodfang Ripper');

-- Creature Bloodfang Lurker 35463 SAI
SET @ENTRY := 35463;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell 8599 on Self // Bloodfang Lurker - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Bloodfang Lurker - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY, 0, 2, 3, 11, 0, 100, 1, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On respawn  - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 5916, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 5916 on Self // Bloodfang Lurker - On Respawn - Cast 'Shadowstalker Stealth' (No Repeat)"),
(@ENTRY, 0, 4, 5, 7, 0, 100, 1, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On evade - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 5916, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 5916 on Self // Bloodfang Lurker - On Evade - Cast 'Shadowstalker Stealth' (No Repeat)"),
(@ENTRY, 0, 6, 0, 4, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Set react state to REACT_AGGRESSIVE // ");

-- Creature King Genn Greymane 35550 SAI
SET @ENTRY := 35550;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 19000, 20000, 70000, 70000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 70000 and 70000 ms (for the first time, timer between 19000 and 20000 ms) - Self: Talk 0 // "),
(@ENTRY, 0, 1, 0, 19, 0, 100, 0, 14293, 0, 0, 0, 11, 68232, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When player accepts quest 14293 - Self: Cast spell 68232 on Action invoker // ");

-- Creature Krennan Aranas 35907 SAI
SET @ENTRY := 35907;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 1, 0, 54, 0, 100, 1, 0, 0, 0, 0, 11, 46598, 2, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, "On just summoned - Self: Cast spell 46598 on Invoker's vehicle // ");

-- Creature Lord Godfrey 35906 SAI
SET @ENTRY := 35906;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 20, 0, 100, 0, 14293, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When player rewards quest 14293 - Action invoker: Talk 0 // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 3591400, 0, 0, 0, 0, 0, 10, 376902, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #0 // ");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= 35914;
DELETE FROM `smart_scripts` WHERE `entryorguid`=35914 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3591400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3591400,9,0,0,0,0,100,0,3000,3000,0,0,11,68235,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commandeered Cannon - On Script - cast spell"), -- 3secs delay
(3591400,9,1,0,0,0,100,0,2000,2000,0,0,11,68235,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commandeered Cannon - On Script - cast spell"), -- 2secs delay
(3591400,9,2,0,0,0,100,0,2000,2000,0,0,11,68235,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commandeered Cannon - On Script - cast spell"); -- 2secs delay

UPDATE `creature_template` SET `vehicleID`= 494, `speed_run`= 1.2857, `ScriptName`= 'npc_greymanes_horse' WHERE `entry`= 35905;
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry`= 35753;
UPDATE `creature_addon` SET `emote`= 472 WHERE `guid`= 376850;
UPDATE `creature_template` SET `vehicleID`= 1418 WHERE `entry`= 50420;

UPDATE `creature_addon` SET `emote`= 431 WHERE `guid`= 376588;
UPDATE `gameobject` SET `phaseGroup`= 0, `phaseID`= 171 WHERE `guid`= 235509;
UPDATE `gameobject` SET `phaseGroup`= 507, `phaseID`= 0 WHERE `guid`= 235509;

UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 35374;
-- Turn multiple npc's into civillians to avoid aggro
UPDATE `creature_template` SET `flags_extra`= 2 WHERE `entry` IN (35112, 35115, 47091, 35912, 35873, 32768, 35869, 35874, 38832, 35550, 35618, 51947, 35906, 35753, 44469, 44461, 44463, 44465, 35554, 44455, 35552, 35911, 44470, 44468, 44459, 35551);

-- Spawn Krennan Gameobject Focus
DELETE FROM `gameobject` WHERE `guid`= 235581;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseID`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(235581, 195660, 654, 1, 171, -1672.96, 1344.75, 15.1352, 1.36203);

-- Fix flags for not selectable gameobjects
UPDATE `gameobject_template_addon` SET `flags`= `flags`|16 WHERE `entry` IN (195466, 195465, 195430, 195454, 195453);
-- Put barricades in correct phase
UPDATE `gameobject` SET `phaseId`= 0, `phaseGroup`= 507 WHERE `guid` IN (235561, 235562, 235560, 235559);
-- Corrected trigger phase id's
UPDATE `creature` SET `phaseId`= 0, `phaseGroup`= 372 WHERE `id`= 35374 AND `map`= 654;
