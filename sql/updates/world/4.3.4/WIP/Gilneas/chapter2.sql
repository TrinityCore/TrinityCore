/*
17:05:42.484 -- phaseshift 105

14:55:38.148 -- summon krennan
14:55:39.333 -- move to   -1819.53 Y: 2291.25 Z: 42.32689
14:55:44.653 -- I am not giving up on you

14:55:49.364 -- forcecast summon personal godfrey  68635 
14:55:50.581 -- move wp
 -- godfrey move to  -1840.085 Y: 2293.042 Z: 42.53004
 --                  -1821.922 Y: 2295.05 Z: 42.17052

14:55:59.114

14:55:57.788 -- summon personal greymane  68636
14:55:57.788 -- greymane summon
14:55:58.194 -- move to   -1821.09 Y: 2292.597 Z: 42.23363



14:56:07.413 -- greymane (facing angle --> 1.32645)
14:56:17.039 -- das dachte ich mir
14:56:20.658 -- face to 5.497787


14:57:05.196 -- worgen intro completion  68638  (hitting 36330, 36331 and 36332

14:57:05.196 -- player casts altered form (97709)
14:57:05.617 -- everyone despawns
14:57:05.196 -- phase id 181 applied
*/


-- Phasing conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 26 AND `SourceEntry`= 4714 AND `SourceGroup` IN (105, 181);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 105, 4714, 8, 14221, 0, 'Gilneas - Phase 105 - active when rewarded quest 14222'),
-- (26, 105, 4714, 8, 14375, 1, 'Gilneas - Phase 105 - inactive when rewarded quest 14375'),
(26, 181, 4714, 8, 14375, 0, 'Gilneas - Phase 181 - active when rewarded quest 14222');


DELETE FROM `phase_area` WHERE `AreaId`= 4714;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(4714, 105, 'Gilneas - Phase 105'),
(4714, 181, 'Gilneas - Phase 181');

-- Spell Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (69123, 68632, 68634, 68638, 69296) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 69123, 0, 0, 31, 0, 3, 0, 377913, 0, 0, '', 'Curse of the Worgen - Target Generic Trigger Lab - Multiphase (Ground)'),
(13, 1, 68632, 0, 0, 31, 0, 3, 0, 377912, 0, 0, '', 'Summon Personal Godfrey - Target Generic Trigger Lab - Multiphase (Ground)'),
(13, 1, 68634, 0, 0, 31, 0, 3, 0, 377895, 0, 0, '', 'Summon Personal Greymane - Target Generic Trigger Lab - Multiphase (Ground)'),
(13, 2, 68638, 0, 0, 31, 0, 3, 36331, 0, 0, 0, '', 'Worgen Intro Completion - Target Krennan Aranas'),
(13, 2, 68638, 0, 0, 31, 0, 3, 36330, 0, 0, 0, '', 'Worgen Intro Completion - Target Lord Godfrey'),
(13, 2, 68638, 0, 0, 31, 0, 3, 36332, 0, 0, 0, '', 'Worgen Intro Completion - Target King Genn Greymane'),
(13, 2, 69296, 0, 0, 31, 0, 5, 197337, 0, 0, 0, '', 'Invasion Camera - Target Invasion Camera');

-- Template Updates
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 36198;

DELETE FROM `creature_text` WHERE `CreatureID` IN (36330, 36331, 36332);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES
(36330, 0, 0, 'Give it up, Krennan.  It''s time to put this one down.  It''s protocol.', 12, 0, 100, 274, 0, 19635, 36336, 'Lord Godfrey to Player'),
(36331, 0, 0, 'I am not giving up on you.  I don''t have a cure for the Curse yet... but there are treatments.  You will have control again.', 12, 0, 100, 274, 0, 20919, 36344, 'Krennan Aranas to Player'),
(36332, 0, 0, 'Tell me, Godfrey.  Those that stayed in Gilneas City so that we could live.  Were they following protocol?', 12, 0, 100, 1, 0, 19721, 36340, 'King Genn Greymane to Player'),
(36332, 1, 0, 'I didn''t think so.  Now hand me that potion, Krennan... and double the dosage.', 12, 0, 100, 1, 0, 19722, 36341, 'King Genn Greymane to Player');

DELETE FROM `waypoints` WHERE `entry`= 36330;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES
(36330, 1, -1840.085, 2293.042, 42.53004),
(36330, 2, -1821.922, 2295.05, 42.17052);

-- Creature Krennan Aranas 36331 SAI
SET @ENTRY := 36331;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 63, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set walk // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 3633100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #3633100 // "),
(@ENTRY, 0, 2, 0, 8, 0, 100, 0, 68638, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Worgen Intro Completion (68638) hit  - Self: Despawn instantly // ");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3633100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3633100,9,0,0,0,0,100,0,1200,1200,0,0,69,0,0,0,0,0,0,8,0,0,0,-1819.53,2291.25,42.32689,0,""),
(3633100,9,1,0,0,0,100,0,5300,5300,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,""),
(3633100,9,2,0,0,0,100,0,4700,4700,0,0,11,68635,0,0,0,0,0,23,0,0,0,0,0,0,0,""),
(3633100,9,3,0,0,0,100,0,8400,8400,0,0,11,68636,0,0,0,0,0,23,0,0,0,0,0,0,0,"");

-- Creature Lord Godfrey 36330 SAI
SET @ENTRY := 36330;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, 3633000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Start timed action list id #3633000 // "),
(@ENTRY, 0, 1, 0, 8, 0, 100, 0, 68638, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Worgen Intro Completion (68638) hit  - Self: Despawn instantly // ");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3633000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3633000,9,0,0,0,0,100,0,1200,1200,0,0,53,0,36330,0,0,0,0,1,0,0,0,0,0,0,0,""),
(3633000,9,1,0,0,0,100,0,5300,5300,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"");

-- Creature King Genn Greymane 36332 SAI
SET @ENTRY := 36332;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On just summoned - Self: Set walk // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 3633200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #3633200 // "),
(@ENTRY, 0, 2, 3, 20, 0, 100, 1, 0, 0, 0, 0, 28, 68630, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When player rewards any quest - Action invoker: Remove aura due to spell Curse of the Worgen (68630) // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 68639, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell Forcecast Worgen Intro Completion (68639) on Action invoker // "),
(@ENTRY, 0, 4, 0, 8, 0, 100, 0, 68638, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Worgen Intro Completion (68638) hit  - Self: Despawn instantly // ");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3633200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3633200,9,0,0,0,0,100,0,400,400,0,0,69,0,0,0,0,0,0,8,0,0,0,-1821.09,2292.597,42.23363,0,""),
(3633200,9,1,0,0,0,100,0,11000,11000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,""),
(3633200,9,2,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.32645,""),
(3633200,9,3,0,0,0,100,0,9600,9600,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,""),
(3633200,9,4,0,0,0,100,0,3600,3600,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.497787,""),
(3633200,9,5,0,0,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"");

DELETE FROM `quest_template_addon` WHERE `ID`= 14321;
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`) VALUES
(14321, 14320);

UPDATE `gameobject_template` SET `ScriptName`= 'go_gilneas_invasion_camera' WHERE `entry`= 197337;

DELETE FROM `gameobject_template_addon` WHERE `entry`= 196394;
INSERT INTO `gameobject_template_addon` (`entry`, `flags`) VALUES
(196394, 4);

-- Creature Slain Watchman 36205 SAI
SET @ENTRY := 36205;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 14321, 0, 0, 0, 11, 68492, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When player accepts quest 14321 - Self: Cast spell Forcecast Summon Forsaken Assassin (68492) on Action invoker // ");

-- 14:58:31.449 gilneas will soon

