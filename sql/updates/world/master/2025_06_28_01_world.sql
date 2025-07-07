SET @CGUID := 6005154;

SET @NPCTEXTID := 560017;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+8;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 105773, 0, 85, 173, '0', 5737, 0, 0, 0, 2604.624267578125, -509.385406494140625, 89.09778594970703125, 4.645145416259765625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Riding Bat (Area: Faol's Rest - Difficulty: 0) CreateObject1
(@CGUID+1, 102342, 0, 85, 173, '0', 5737, 0, 0, 1, 2597.46533203125, -546.171875, 89.08292388916015625, 3.92900252342224121, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hooded Priest (Area: Faol's Rest - Difficulty: 0) CreateObject1
(@CGUID+2, 102342, 0, 85, 173, '0', 5737, 0, 0, 1, 2617.961181640625, -556.15814208984375, 88.9995880126953125, 3.677475929260253906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hooded Priest (Area: Faol's Rest - Difficulty: 0) CreateObject1
(@CGUID+3, 102342, 0, 85, 173, '0', 5737, 0, 0, 1, 2604.8916015625, -525.70489501953125, 89.08292388916015625, 1.789143204689025878, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hooded Priest (Area: Faol's Rest - Difficulty: 0) CreateObject1
(@CGUID+4, 102343, 0, 85, 173, '0', 5737, 0, 0, 0, 2600.9296875, -540.50177001953125, 89.08292388916015625, 0.436123520135879516, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Calia (Area: Faol's Rest - Difficulty: 0) CreateObject1
(@CGUID+5, 102342, 0, 85, 173, '0', 5737, 0, 0, 1, 2620.703125, -542.8524169921875, 89.08292388916015625, 0.066048525273799896, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hooded Priest (Area: Faol's Rest - Difficulty: 0) CreateObject1
(@CGUID+6, 105769, 0, 85, 173, '0', 5737, 0, 0, 0, 2600.161376953125, -513.60418701171875, 89.08292388916015625, 5.099428653717041015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Brother Larry (Area: Faol's Rest - Difficulty: 0) CreateObject1
(@CGUID+7, 102342, 0, 85, 173, '0', 5737, 0, 0, 1, 2616.7919921875, -553.683837890625, 88.9995880126953125, 3.4843292236328125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hooded Priest (Area: Faol's Rest - Difficulty: 0) CreateObject1
(@CGUID+8, 101314, 0, 85, 173, '0', 5738, 0, 0, 0, 2602.81591796875, -534.5225830078125, 89.08292388916015625, 4.944195747375488281, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609); -- Alonsus Faol (Area: Faol's Rest - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry`=102342;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(102342, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- 102342 (Hooded Priest)

-- Template
UPDATE `creature_template` SET `npcflag`=2, `BaseAttackTime`=1000, `unit_flags`=0x300, `unit_flags2`=0x4800 WHERE `entry`=102333; -- Hooded Priestess
UPDATE `creature_template` SET `npcflag`=2, `BaseAttackTime`=1000, `unit_flags`=0x300, `unit_flags2`=0x4800 WHERE `entry`=101344; -- Hooded Priestess
UPDATE `creature_template` SET `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x800 WHERE `entry`=101314; -- Alonsus Faol
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x800, `unit_flags3`=0x80000 WHERE `entry`=102358; -- Alonsus Faol
UPDATE `creature_template` SET `npcflag`=1, `BaseAttackTime`=1000, `unit_flags`=0x300, `unit_flags2`=0x4800 WHERE `entry`=105769; -- Brother Larry
UPDATE `creature_template` SET `npcflag`=1, `BaseAttackTime`=1000, `unit_flags`=0x300, `unit_flags2`=0x4800 WHERE `entry`=102343; -- Calia
UPDATE `creature_template` SET `npcflag`=2, `BaseAttackTime`=1000, `unit_flags`=0x300, `unit_flags2`=0x4800 WHERE `entry`=102342; -- Hooded Priest
UPDATE `creature_template` SET `speed_run`=4.285714149475097656, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=105773; -- Riding Bat

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=642, `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=102333 AND `DifficultyID`=0); -- 102333 (Hooded Priestess) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=642, `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=101344 AND `DifficultyID`=0); -- 101344 (Hooded Priestess) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=633, `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=101314 AND `DifficultyID`=0); -- 101314 (Alonsus Faol) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=633, `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=102358 AND `DifficultyID`=0); -- 102358 (Alonsus Faol) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=339, `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=105769 AND `DifficultyID`=0); -- 105769 (Brother Larry) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=339, `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=102343 AND `DifficultyID`=0); -- 102343 (Calia) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=339, `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=102342 AND `DifficultyID`=0); -- 102342 (Hooded Priest) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=633, `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=105773 AND `DifficultyID`=0); -- 105773 (Riding Bat) - CanSwim

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (102333,101344,102358);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(102333, 0, 0, 'Master $n, if I could get your attention for a moment!', 12, 0, 100, 0, 0, 0, 103668, 0, 'Hooded Priestess to Player'),
(102333, 1, 0, 'Excellent, Faol wants you to have this hearthstone. It should get you to his meeting place.', 12, 0, 100, 1, 0, 0, 103669, 0, 'Hooded Priestess to Player'),
(101344, 0, 0, 'Master $n, if I could get your attention for a moment!', 12, 0, 100, 0, 0, 0, 103668, 0, 'Hooded Priestess to Player'),
(101344, 1, 0, 'Excellent, Faol wants you to have this hearthstone. It should get you to his meeting place.', 12, 0, 100, 1, 0, 0, 103669, 0, 'Hooded Priestess to Player'),
(102358, 0, 0, 'Forgive the secrecy... old habits die hard. I am Alonsus Faol. At times I have been a leader of a church, a mindless minion of the Scourge, and a commander in a secret war. But I have always been a priest first.', 12, 0, 100, 1, 0, 63426, 104642, 0, 'Alonsus Faol to Player'),
(102358, 1, 0, 'The Legion poses a threat that cannot be ignored. So I have decided to step out from the shadows. I believe we must unite priesthoods of all denominations against our common enemy.', 12, 0, 100, 0, 0, 63427, 104643, 0, 'Alonsus Faol to Player'),
(102358, 2, 0, 'To lead this effort, we require a priest who is a proven champion to all people. I believe you are that hero, $n, but others must be convinced. Will you accept this challenge?', 12, 0, 100, 0, 0, 63428, 104644, 0, 'Alonsus Faol to Player');

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=102342 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(102342, 1, 129394, 0, 0, 0, 0, 0, 0, 0, 0, 61609); -- Hooded Priest

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (5737,5738);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(5737, 'Cosmetic - See Hooded Priests at Faols Rest'),
(5738, 'Cosmetic - See Alonsus Faol at Faols Rest');

DELETE FROM `phase_area` WHERE `PhaseId` IN (5737,5738);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(85, 5737, 'See Hooded Priests at Faols Rest'),
(85, 5738, 'See Alonsus Faol at Faols Rest');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (5737,5738) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 5737, 0, 0, 0, 47, 0, 40705, 2|8|64, 0, 0, 'Apply Phase 5737 if Quest 40705 is in progress | complete | rewarded'),
(26, 5738, 0, 0, 0, 47, 0, 40705, 2|64, 0, 0, 'Apply Phase 5737 if Quest 40705 is complete | rewarded');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=102343 AND `MenuID`=19236) OR (`CreatureID`=105769 AND `MenuID`=19521);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(102343, 19236, 61609), -- Calia
(105769, 19521, 61609); -- Brother Larry

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 108621, 0, 0, 0, 0, 0, 0, 0, 61609), -- 105769 (Brother Larry)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 104597, 0, 0, 0, 0, 0, 0, 0, 61609); -- 102343 (Calia)

DELETE FROM `gossip_menu` WHERE (`MenuID`=19521 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=19236 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(19521, @NPCTEXTID+0, 61609), -- 105769 (Brother Larry)
(19236, @NPCTEXTID+1, 61609); -- 102343 (Calia)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (19521,19236));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(19521, 45625, 0, 0, 'I\'d like to travel to Dalaran.', 108622, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 61609),
(19236, 45465, 0, 0, 'Are you the one I\'m supposed to meet? Why all the way out here?', 104599, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 61609);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (19236));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 19236, 0, 0, 0, 47, 0, 40705, 8, 0, '', 0, 'Player for which gossip text is shown has Priestly Matters (40705) in state incomplete'),
(15, 19236, 0, 0, 0, 48, 0, 281368, 0, 1, '', 1, 'Player for which gossip text is shown hasn\'t quest objective 281368 < 1 or has rewarded the quest');

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=102333 AND `quest`=40705) OR (`id`=101344 AND `quest`=40705);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(102333, 40705, 61609), -- Priestly Matters offered by Hooded Priestess
(101344, 40705, 61609); -- Priestly Matters offered by Hooded Priestess

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` = 281369;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(281369, NULL, NULL, NULL, 1, 0);

DELETE FROM `ui_map_quest_line` WHERE (`UIMapId`=18 AND `QuestLineId` IN (5718,5673));
INSERT INTO `ui_map_quest_line` (`UIMapId`, `QuestLineId`, `VerifiedBuild`) VALUES
(18, 5718, 61609),
(18, 5673, 61609);

-- Spell target pos.
DELETE FROM `spell_target_position` WHERE (`ID`=311643 AND `EffectIndex`=0 AND `OrderIndex`=0) OR (`ID`=202112 AND `EffectIndex`=0 AND `OrderIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `OrderIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(311643, 0, 0, 0, 2575.60009765625, -569, 86.3000030517578125, 61609), -- Spell: 311643 (Hearth to Faol's Rest) Effect 0: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(202112, 0, 0, 0, 2597.08, -529.766, 88.9996, 61609); -- Spell: 202112 -- Target_dest_nearby_entry -> serverside creature -> changed to dest_db

-- Hooded Priestess smart ai
SET @ENTRY := 102333;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 80, 10233300, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Start timed action list id #Hooded Priestess #0 (10233300) (update out of combat)', ''),
(@ENTRY, 0, 1, 0, 19, 0, 100, 0, 40705, 0, 0, 0, 0, 80, 10233301, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Priestly Matters (40705) - Self: Start timed action list id #Hooded Priestess #1 (10233301) (update out of combat)', '');

-- Hooded Priestess smart ai
SET @ENTRY := 101344;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 80, 10233300, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Start timed action list id #Hooded Priestess #0 (10233300) (update out of combat)', ''),
(@ENTRY, 0, 1, 0, 19, 0, 100, 0, 40705, 0, 0, 0, 0, 80, 10233301, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Priestly Matters (40705) - Self: Start timed action list id #Hooded Priestess #1 (10233301) (update out of combat)', '');

-- Timed list 10233300 smart ai
SET @ENTRY := 10233300;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Follow Owner/Summoner by distance 0, angle 0', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Owner/Summoner: Talk 0 to invoker', '');

-- Timed list 10233301 smart ai
SET @ENTRY := 10233301;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Follow None by distance 0, angle 0', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Look at Owner/Summoner', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Owner/Summoner: Talk 1 to invoker', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 128, 3003, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Plays Anim with ID 3003', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Set walk', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 114, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 20, 0, 0, 'After 0 seconds - Self: Move forward by 0, left by 20, up by 0 yards', ''),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 10000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Despawn in 10 s', '');

-- Calia smart ai
SET @ENTRY := 102343;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 19236, 0, 0, 0, 0, 85, 202109, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19236 selected - Gossip player: Cast spell 202109 on self', ''),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 33, 102340, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19236 selected - Gossip player: Give kill credit Kill Credit: Found Faol\'s Rest (102340)', ''),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19236 selected - Gossip player: Close gossip', '');

-- Alonsus Faol smart ai
SET @ENTRY := 102358;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Owner/Summoner: Talk 0 to invoker', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 53, 0, 10235800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Start path #10235800, walk, do not repeat, Passive', ''),
(@ENTRY, 0, 2, 0, 34, 0, 100, 0, 2, 3, 0, 0, 0, 80, 10235800, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 3 - Self: Start timed action list id #Alonsus Faol #0 (10235800) (update out of combat)', ''),
(@ENTRY, 0, 3, 0, 34, 0, 100, 0, 2, 5, 0, 0, 0, 80, 10235801, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 5 - Self: Start timed action list id #Alonsus Faol #1 (10235801) (update out of combat)', ''),
(@ENTRY, 0, 4, 0, 34, 0, 100, 0, 2, 6, 0, 0, 0, 80, 10235802, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 6 - Self: Start timed action list id #Alonsus Faol #2 (10235802) (update out of combat)', '');

-- Timed list 10235800 smart ai
SET @ENTRY := 10235800;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 128, 3261, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Plays Anim with ID 3261', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 128, 9926, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Plays Anim with ID 9926', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 0, 128, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 11 seconds - Self: Plays Anim with ID 0', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Owner/Summoner: Talk 1 to invoker', '');

-- Timed list 10235801 smart ai
SET @ENTRY := 10235801;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.908771, 'After 0 seconds - Self: Set orientation to 5.908771', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 128, 9926, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 9926', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, 0, 128, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 13 seconds - Self: Plays Anim with ID 0', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Talk 2 to invoker', '');

-- Timed list 10235802 smart ai
SET @ENTRY := 10235802;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.489006, 'After 0 seconds - Self: Set orientation to 2.489006', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 33, 102341, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Owner/Summoner: Give kill credit Kill Credit: Talked to Faol (102341)', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Despawn in 1 s', '');

-- Path for Hooded Priest
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+7;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+7, @CGUID+7, 0, 0, 515, 0, 0),
(@CGUID+7, @CGUID+2, 2, 270, 515, 0, 0);

SET @MOVERGUID := @CGUID+7;
SET @ENTRY := 102342;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Hooded Priest - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2604.2883, -556.69446, 88.99959, NULL, 0),
(@PATH, 1, 2600.5781, -555.38715, 88.99959, NULL, 0),
(@PATH, 2, 2593.5442, -550.0781, 88.39082, NULL, 0),
(@PATH, 3, 2592.8186, -543.94446, 88.39353, NULL, 0),
(@PATH, 4, 2593.0815, -536.52606, 88.99959, NULL, 0),
(@PATH, 5, 2594.1145, -529.27606, 88.99959, NULL, 0),
(@PATH, 6, 2600.5557, -522.7101, 88.99959, NULL, 0),
(@PATH, 7, 2604.4714, -521.8976, 88.99959, NULL, 0),
(@PATH, 8, 2610.7188, -522.88715, 88.99959, NULL, 0),
(@PATH, 9, 2616.4375, -526.1059, 88.99959, NULL, 0),
(@PATH, 10, 2620.4602, -530.94446, 88.99959, NULL, 0),
(@PATH, 11, 2623.039, -535.57465, 89.00888, NULL, 0),
(@PATH, 12, 2624.7883, -542.11115, 89.23042, NULL, 0),
(@PATH, 13, 2622.7336, -549.06946, 88.99959, NULL, 0),
(@PATH, 14, 2617.823, -553.316, 88.99959, NULL, 0),
(@PATH, 15, 2613.5461, -554.84204, 88.99959, NULL, 0),
(@PATH, 16, 2608.5703, -556.4184, 88.99959, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path Alonsus Faol
SET @ENTRY := 102358;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Alonsus Faol - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2599.9766, -525.6858, 88.99959, NULL, 0),
(@PATH, 1, 2601.7249, -525.8559, 88.99959, NULL, 0),
(@PATH, 2, 2603.3586, -530.01215, 88.99959, NULL, 0),
(@PATH, 3, 2604.567, -531.5278, 88.99959, NULL, 16090),
(@PATH, 4, 2600.816, -536.3785, 88.99959, NULL, 0),
(@PATH, 5, 2600.684, -537.6667, 88.99959, NULL, 13934),
(@PATH, 6, 2602.815, -534.522, 88.99959, NULL, 0);
