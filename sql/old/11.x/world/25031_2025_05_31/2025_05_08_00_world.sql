SET @CGUID := 7002760;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 127160, 1643, 8721, 9224, '0', 9442, 0, 0, 0, 418.939239501953125, 2399.130126953125, 122.446868896484375, 5.124086380004882812, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Euphemia Batten-Chase (Area: North Pass Caverns - Difficulty: 0) CreateObject1 (Auras: 252803 - Captive)
(@CGUID+1, 127157, 1643, 8721, 9224, '0', 9586, 0, 0, 0, 334.9132080078125, 2400.638916015625, 129.041168212890625, 5.976168632507324218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Marcus Howlingdale (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@CGUID+2, 127159, 1643, 8721, 9224, '0', 9440, 0, 0, 0, 443.651031494140625, 2339.83154296875, 128.57421875, 4.986971378326416015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Amelia Tidecrest (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@CGUID+3, 127158, 1643, 8721, 9224, '0', 9439, 0, 0, 0, 462.380218505859375, 2282.085205078125, 119.9774627685546875, 1.8473283052444458, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Jonathan "Johnny" Presterby (Area: North Pass Caverns - Difficulty: 0) CreateObject1 (Auras: 252803 - Captive)
(@CGUID+4, 127159, 1643, 8721, 9224, '0', 9441, 0, 0, 0, 335.532989501953125, 2401.44970703125, 129.105926513671875, 4.986971378326416015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Amelia Tidecrest (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@CGUID+5, 127158, 1643, 8721, 9224, '0', 9438, 0, 0, 0, 335.5538330078125, 2399.02783203125, 128.9415740966796875, 1.093778371810913085, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Jonathan "Johnny" Presterby (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@CGUID+6, 127160, 1643, 8721, 9224, '0', 9443, 0, 0, 0, 336.973968505859375, 2401.380126953125, 129.2994232177734375, 4.610091686248779296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568); -- Euphemia Batten-Chase (Area: North Pass Caverns - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '252803'), -- Euphemia Batten-Chase - 252803 - Captive
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '252803'); -- Jonathan "Johnny" Presterby - 252803 - Captive

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry` IN (127159,127160,127158) AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=127159 AND `DifficultyID`=0); -- 127159 (Amelia Tidecrest) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=127160 AND `DifficultyID`=0); -- 127160 (Euphemia Batten-Chase) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=127158 AND `DifficultyID`=0); -- 127158 (Jonathan "Johnny" Presterby) - CanSwim

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (9585,9586,9440,9441,9439,9438,9442,9443);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(9585, 'Cosmetic - See Marcus Howlingdale near the Rocks'),
(9586, 'Cosmetic - See Marcus Howlingdale near the cave'),
(9440, 'Cosmetic - See Amelia Tidecrest on the rock'),
(9441, 'Cosmetic - See Amelia Tidecrest freed'),
(9439, 'Cosmetic - See Jonathan Presterby captive'),
(9438, 'Cosmetic - See Jonathan Presterby freed'),
(9442, 'Cosmetic - See Euphemia Batten-Chase captive'),
(9443, 'Cosmetic - See Euphemia Batten-Chase freed');

DELETE FROM `phase_area` WHERE `PhaseId` IN (9585,9586,9440,9441,9439,9438,9442,9443);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9224, 9585, 'See Marcus Howlingdale near the Rocks'),
(9224, 9586, 'See Marcus Howlingdale near the cave'),
(9224, 9440, 'See Amelia Tidecrest on the rock'),
(9224, 9441, 'See Amelia Tidecrest freed'),
(9224, 9439, 'See Jonathan Presterby captive'),
(9224, 9438, 'See Jonathan Presterby freed'),
(9224, 9442, 'See Euphemia Batten-Chase captive'),
(9224, 9443, 'See Euphemia Batten-Chase freed');

UPDATE `creature` SET `PhaseId` = 9585 WHERE `guid` = 7002758;

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (9585,9586,9440,9441,9439,9438,9442,9443) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 9585, 0, 0, 0, 47, 0, 48804, 2|8|64, 0, 1, 'Apply Phase 9585 if Quest 48804 is not in progress complete | rewarded'),
(26, 9586, 0, 0, 0, 47, 0, 48804, 2|8|64, 0, 0, 'Apply Phase 9586 if Quest 48804 is in progress complete | rewarded'),
(26, 9440, 0, 0, 0, 47, 0, 48804, 8, 0, 0, 'Apply Phase 9440 if Quest 48804 is in progress'),
(26, 9440, 0, 0, 0, 48, 0, 292959, 0, 1, 1, 'Apply Phase 9440 if Questobjective 292959 is not rewarded'),
(26, 9439, 0, 0, 0, 47, 0, 48804, 8, 0, 0, 'Apply Phase 9439 if Quest 48804 is in progress'),
(26, 9439, 0, 0, 0, 48, 0, 292958, 0, 1, 1, 'Apply Phase 9439 if Questobjective 292958 is not rewarded'),
(26, 9442, 0, 0, 0, 47, 0, 48804, 8, 0, 0, 'Apply Phase 9442 if Quest 48804 is in progress'),
(26, 9442, 0, 0, 0, 48, 0, 292960, 0, 1, 1, 'Apply Phase 9442 if Questobjective 292960 is not rewarded'),
(26, 9441, 0, 0, 0, 47, 0, 48804, 2|64, 0, 0, 'Apply Phase 9441 if Quest 48804 is complete | rewarded'),
(26, 9441, 0, 0, 1, 48, 0, 292959, 0, 1, 0, 'Apply Phase 9441 if Questobjective 292959 is rewarded'),
(26, 9438, 0, 0, 0, 47, 0, 48804, 2|64, 0, 0, 'Apply Phase 9438 if Quest 48804 is complete | rewarded'),
(26, 9438, 0, 0, 1, 48, 0, 292958, 0, 1, 0, 'Apply Phase 9438 if Questobjective 292958 is rewarded'),
(26, 9443, 0, 0, 0, 47, 0, 48804, 2|64, 0, 0, 'Apply Phase 9443 if Quest 48804 is complete | rewarded'),
(26, 9443, 0, 0, 1, 48, 0, 292960, 0, 1, 0, 'Apply Phase 9443 if Questobjective 292960 is rewarded');

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (127157,127158,127159,127160);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(127157, 0, 0, 'I think I\'m gonna stand back over there. The, uh, light\'s better for reading. Good luck!', 12, 0, 100, 0, 0, 0, 137999, 0, 'Marcus Howlingdale to Player'),
(127158, 0, 0, 'Hey, thanks! Who knew troggs could use magic?', 12, 0, 100, 0, 0, 0, 137020, 0, 'Jonathan \"Johnny\" Presterby to Player'),
(127158, 1, 0, 'I\'m going to find Marcus and wait with him. See ya there!', 12, 0, 100, 0, 0, 0, 137021, 0, 'Jonathan \"Johnny\" Presterby to Player'),
(127159, 0, 0, 'Thank you! I was gonna run out of rocks up here!', 12, 0, 100, 0, 0, 0, 137037, 0, 'Amelia Tidecrest to Player'),
(127159, 1, 0, 'I\'m going to hide with Marcus!', 12, 0, 100, 0, 0, 0, 137038, 0, 'Amelia Tidecrest to Player'),
(127160, 0, 0, 'Oh, thank you! It was quite uncomfortable in here.', 12, 0, 100, 0, 0, 0, 137027, 0, 'Euphemia Batten-Chase to Player'),
(127160, 1, 0, 'I\'ll go find Marcus! See you there!', 12, 0, 100, 0, 0, 0, 137028, 0, 'Euphemia Batten-Chase to Player');

-- Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (127160,127159,127158);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(127160, 252830, 1, 0),
(127159, 252924, 1, 0),
(127158, 252830, 1, 0);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 18) AND (`SourceGroup` IN (127160,127159,127158));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(18, 127160, 252830, 0, 0, 47, 0, 48804, 8, 0, '', 0, 'Clicker has Mistakes Were Made (48804) in state incomplete'),
(18, 127160, 252830, 0, 0, 48, 0, 292960, 0, 1, '', 1, 'Clicker hasn\'t quest objective 292960 < 1 or has rewarded the quest'),
(18, 127159, 252924, 0, 0, 47, 0, 48804, 8, 0, '', 0, 'Clicker has Mistakes Were Made (48804) in state incomplete'),
(18, 127159, 252924, 0, 0, 48, 0, 292959, 0, 1, '', 1, 'Clicker hasn\'t quest objective 292959 < 1 or has rewarded the quest'),
(18, 127158, 252830, 0, 0, 47, 0, 48804, 8, 0, '', 0, 'Clicker has Mistakes Were Made (48804) in state incomplete'),
(18, 127158, 252830, 0, 0, 48, 0, 292958, 0, 1, '', 1, 'Clicker hasn\'t quest objective 292958 < 1 or has rewarded the quest');

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=127157 AND `quest`=48853);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(127157, 48853, 60568); -- Terminal Degree offered by Marcus Howlingdale

DELETE FROM `creature_questender` WHERE (`id`=127157 AND `quest`=48804);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(127157, 48804, 60568); -- Mistakes Were Made ended by Marcus Howlingdale

DELETE FROM `quest_template_addon` WHERE `ID` = 48853;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(48853, 0, 0, 0, 48804, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Terminal Degree

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` IN (292959,292958,292960);
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(292959, NULL, NULL, NULL, 1, 0),
(292958, NULL, NULL, NULL, 1, 0),
(292960, NULL, NULL, NULL, 1, 0);

-- Marcus Howlingdale smart ai
SET @ENTRY := 127157;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 48804, 0, 0, 0, 0, 80, 12715700, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Mistakes Were Made (48804) - Self: Start timed action list id #Marcus Howlingdale #0 (12715700) (update out of combat)', ''),
(@ENTRY, 0, 1, 2, 34, 0, 100, 0, 2, 8, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.976168, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 8 - Self: Set orientation to 5.976168', ''),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 8 - Self: Despawn in 1 s', '');

-- Timed list 12715700 smart ai
SET @ENTRY := 12715700;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Owner/Summoner: Talk 0 to invoker', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 53, 0, 12715700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Start path #12715700, walk, do not repeat, Passive', '');

-- Jonathan "Johnny" Presterby smart ai
SET @ENTRY := 127158;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, 252830, 0, 0, 0, 0, 80, 12715800, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  252830 hit - Self: Start timed action list id #Jonathan "Johnny" Presterby #0 (12715800) (update out of combat)', '');

-- Timed list 12715800 smart ai
SET @ENTRY := 12715800;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set npc flags NONE', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 33, 127158, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Owner/Summoner: Give kill credit Jonathan "Johnny" Presterby (127158)', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Talk 1 to invoker', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 53, 0, 12715800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Start path #12715800, walk, do not repeat, Passive', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Despawn instantly', '');

-- Euphemia Batten-Chase smart ai
SET @ENTRY := 127160;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, 252830, 0, 0, 0, 0, 80, 12716000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  252830 hit - Self: Start timed action list id #Euphemia Batten-Chase #0 (12716000) (update out of combat)', '');

-- Timed list 12716000 smart ai
SET @ENTRY := 12716000;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set npc flags NONE', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 33, 127160, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Owner/Summoner: Give kill credit Euphemia Batten-Chase (127160)', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Talk 1 to invoker', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 53, 0, 12716000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Start path #12716000, walk, do not repeat, Passive', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Despawn instantly', '');

-- Amelia Tidecrest smart ai
SET @ENTRY := 127159;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, 252924, 0, 0, 0, 0, 80, 12715900, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  252924 hit - Self: Start timed action list id #Amelia Tidecrest #0 (12715900) (update out of combat)', '');

-- Timed list 12715900 smart ai
SET @ENTRY := 12715900;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set npc flags NONE', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 33, 127159, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Owner/Summoner: Give kill credit Amelia Tidecrest (127159)', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Talk 1 to invoker', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 32, 7000, 7000, 0, 0, 0, 97, 8, 0, 10, 1, 0, 0, 0, 8, 0, 0, 0, 448.563, 2334.16, 121.294, 0, 'After 7 seconds - Self: Jump to pos (448.563, 2334.16, 121.294) with speed XY 8, speed Z 0 and gravity 10', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 53, 0, 12715900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Start path #12715900, walk, do not repeat, Passive', ''),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Despawn in 2 s', '');

-- Path for Marcus Howlingdale
SET @ENTRY := 127157;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Marcus Howlingdale - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 371.71094, 2361.481, 124.01987, NULL, 0),
(@PATH, 1, 365.96094, 2362.981, 123.51987, NULL, 0),
(@PATH, 2, 361.46094, 2366.231, 124.26987, NULL, 0),
(@PATH, 3, 356.21094, 2375.231, 126.01987, NULL, 0),
(@PATH, 4, 353.71094, 2382.481, 127.51987, NULL, 0),
(@PATH, 5, 349.71094, 2387.981, 128.51987, NULL, 0),
(@PATH, 6, 344.71094, 2390.481, 128.01987, NULL, 0),
(@PATH, 7, 339.46094, 2394.481, 128.76987, NULL, 0),
(@PATH, 8, 334.85245, 2400.5798, 128.94786, NULL, 0);

-- Path for Jonathan Presterby
SET @ENTRY := 127158;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Jonathan "Johnny" Presterby - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 462.0151, 2283.8953, 120.53959, NULL, 0),
(@PATH, 1, 461.7651, 2284.1453, 120.78959, NULL, 0),
(@PATH, 2, 461.7651, 2284.6453, 120.53959, NULL, 0),
(@PATH, 3, 461.7651, 2285.8953, 120.78959, NULL, 0),
(@PATH, 4, 460.5151, 2289.1453, 121.03959, NULL, 0),
(@PATH, 5, 460.5151, 2289.6453, 121.03959, NULL, 0),
(@PATH, 6, 460.5151, 2289.8953, 121.03959, NULL, 0),
(@PATH, 7, 460.0151, 2291.1453, 121.78959, NULL, 0),
(@PATH, 8, 459.65, 2291.7053, 121.51838, NULL, 0);

-- Path for Euphemia Batten-Chase
SET @ENTRY := 127160;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Euphemia Batten-Chase - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 419.44006, 2398.5479, 122.67833, NULL, 0),
(@PATH, 1, 419.94006, 2397.5479, 122.42833, NULL, 0),
(@PATH, 2, 420.44006, 2396.2979, 121.92833, NULL, 0),
(@PATH, 3, 421.44006, 2393.7979, 121.92833, NULL, 0),
(@PATH, 4, 422.69006, 2391.9479, 121.67833, NULL, 0),
(@PATH, 5, 422.9409, 2389.9656, 121.32645, NULL, 0);

-- Path for Amelia Tidecrest
SET @ENTRY := 127159;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Amelia Tidecrest - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 440.97424, 2327.5898, 121.380104, NULL, 0),
(@PATH, 1, 439.47424, 2326.3398, 121.630104, NULL, 0),
(@PATH, 2, 436.72424, 2323.8398, 121.130104, NULL, 0),
(@PATH, 3, 435.72424, 2322.5898, 120.880104, NULL, 0),
(@PATH, 4, 434.72424, 2322.0898, 120.880104, NULL, 0),
(@PATH, 5, 432.97424, 2320.5898, 120.630104, NULL, 0),
(@PATH, 6, 426.97424, 2315.3398, 120.880104, NULL, 0),
(@PATH, 7, 425.88547, 2314.5198, 120.46621, NULL, 0);
