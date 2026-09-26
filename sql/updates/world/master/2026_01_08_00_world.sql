-- Phases
DELETE FROM `phase_name` WHERE `ID` IN (19821, 19820, 19822);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES 
(19821, 'Toddy Whiskers and Portal in Stormwind Harbor'),
(19820, 'Dracthyr Sparring Area in Stormwind Harbor'),
(19822, 'Dracthyr and Commanders in Stormwind Harbor');

DELETE FROM `phase_area` WHERE `AreaId`=4411 AND `PhaseId`IN (19821, 19822, 19820);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES 
(4411, 19821, 'Cosmetic phase for Toddy Whiskers and Portal in Stormwind Harbor'),
(4411, 19820, 'Cosmetic phase for Dracthyr Sparring Area in Stormwind Harbor'),
(4411, 19822, 'Cosmetic phase for Dracthyr and Commanders in Stormwind Harbor');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 26 AND `SourceGroup` IN (19820, 19821, 19822);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES                                   -- Base level requirement
(26, 19821, 0, 0, 1, 28, 0, 72240, 0, 0, 0, 0, 0, '', 'Phase 19821: Player has completed/rewarded quest 72240'),
(26, 19821, 0, 0, 2, 9,  0, 72240, 0, 0, 0, 0, 0, '', 'Phase 19821: Player has quest 72240 taken/in progress'),
(26, 19820, 0, 0, 1, 9,  0, 72240, 0, 0, 0, 0, 0, '', 'Phase 19820: Player has quest 72240 taken/in progress ONLY'),
(26, 19822, 0, 0, 1, 28, 0, 72240, 0, 0, 0, 0, 0, '', 'Phase 19822: Player has completed/rewarded quest 72240');

-- Obsidian Warders (77240)
SET @CGUID := 50000500;
SET @OGUID := 50000000;
SET @NPCTEXTID := 50000000;

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+0;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0, 1, 0, 8021); -- Portal to the Dragon Isles

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (466766 /*Portal to the Dragon Isles*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(466766, 0, 0x0, 0, 8021); -- Portal to the Dragon Isles

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 466766, 0, 1519, 4411, '0', '19821', 0, -8632.2255859375, 1319.921875, 5.233369827270507812, 4.372927665710449218, 0, 0, -0.81638813018798828, 0.577503621578216552, 120, 255, 1, 64978); -- Portal to the Dragon Isles (Area: Stormwind Harbor - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_template` WHERE `entry` IN (466766 /*Portal to the Dragon Isles*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `RequiredLevel`, `ContentTuningId`, `VerifiedBuild`) VALUES
(466766, 22, 77931, 'Portal to the Dragon Isles', '', '', '', 0.5, 464137, -1, 0, 0, 0, 128099, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64978); -- Portal to the Dragon Isles

DELETE FROM `quest_objectives` WHERE `ID`=431790;
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `SecondaryAmount`, `Flags`, `Flags2`, `ProgressBarWeight`, `ParentObjectiveID`, `Visible`, `Description`, `VerifiedBuild`) VALUES 
(431790, 72240, 0, 0, 3, 198401, 1, 0, 0, 0, 0, 0, 1, 'Orders delivered to Dervishian', 64978); -- Obsidian Warders - Orders delivered to Dervishian

UPDATE `quest_offer_reward` SET `VerifiedBuild`=64978 WHERE `ID`=72240;

UPDATE `quest_poi` SET `VerifiedBuild`=64978 WHERE (`QuestID`=72240 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=72240 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=72240 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=64978 WHERE (`QuestID`=72240 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=72240 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=72240 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_details` SET `VerifiedBuild`=64978 WHERE `ID`=72240;
UPDATE `quest_description_conditional` SET `VerifiedBuild`=64978 WHERE (`QuestId`=72240 AND `PlayerConditionId`=101846 AND `QuestgiverCreatureId`=0 AND `locale`='enUS');

UPDATE `creature_queststarter` SET `VerifiedBuild`=64978 WHERE (`id`=189603 AND `quest`=72240);
UPDATE `creature_questender` SET `VerifiedBuild`=64978 WHERE (`id`=189077 AND `quest`=72240);

UPDATE `creature` SET `PhaseId`='19821' WHERE `id`=189077; -- Toddy Whiskers

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+9;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 198401, 0, 1519, 4411, '0', '19820', 0, 0, 0, -8475.4462890625, 1041.0242919921875, 59.70163726806640625, 4.206534385681152343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Dervishian (Area: Stormwind City Cemetery - Difficulty: 0) CreateObject1
(@CGUID+1, 198393, 0, 1519, 4411, '0', '19820', 0, 0, 0, -8481.5712890625, 1035.3646240234375, 59.88629913330078125, 1.231970787048339843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Dracthyr Evoker (Area: Stormwind City Cemetery - Difficulty: 0) CreateObject1 (Auras: 393746 - Sparring Aura: AzureStrike/Pyre/TimeSpiral/ObsidianScales [DNT])
(@CGUID+2, 198393, 0, 1519, 4411, '0', '19820', 0, 0, 0, -8480.2607421875, 1039.0833740234375, 59.82388687133789062, 4.373563766479492187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Dracthyr Evoker (Area: Stormwind City Cemetery - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+3, 198393, 0, 1519, 4411, '0', '19820', 0, 0, 0, -8475.5908203125, 1033.420166015625, 59.78345489501953125, 0.758572936058044433, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Dracthyr Evoker (Area: Stormwind City Cemetery - Difficulty: 0) CreateObject1 (Auras: 393746 - Sparring Aura: AzureStrike/Pyre/TimeSpiral/ObsidianScales [DNT])
(@CGUID+4, 198393, 0, 1519, 4411, '0', '19820', 0, 0, 0, -8472.7294921875, 1036.1319580078125, 59.69109344482421875, 3.900165796279907226, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Dracthyr Evoker (Area: Stormwind City Cemetery - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+5, 198408, 0, 1519, 4411, '0', '19822', 0, 0, 0, -8640.2275390625, 1282.6754150390625, 5.789757728576660156, 4.034814357757568359, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Dervishian (Area: Stormwind Harbor - Difficulty: 0) CreateObject1
(@CGUID+6, 198393, 0, 1519, 4411, '0', '19822', 0, 0, 0, -8635.0244140625, 1278.326416015625, 5.31617593765258789, 1.2318267822265625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Dracthyr Evoker (Area: Stormwind Harbor - Difficulty: 0) CreateObject1 (Auras: 393746 - Sparring Aura: AzureStrike/Pyre/TimeSpiral/ObsidianScales [DNT])
(@CGUID+7, 198393, 0, 1519, 4411, '0', '19822', 0, 0, 0, -8633.7138671875, 1282.04345703125, 5.317009925842285156, 4.373419761657714843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Dracthyr Evoker (Area: Stormwind Harbor - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+8, 189078, 0, 1519, 4411, '0', '19822', 0, 0, 0, -8638.8349609375, 1280.513916015625, 5.809106826782226562, 2.688635826110839843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Scalecommander Azurathel (Area: Stormwind Harbor - Difficulty: 0) CreateObject1 (Auras: 394125 - Chat Bubble)
(@CGUID+9, 198496, 0, 1519, 4411, '0', '19822', 0, 0, 0, -8641.73828125, 1280.515625, 5.639600276947021484, 0.412678122520446777, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978); -- Scalecommander Emberthal (Area: Stormwind Harbor - Difficulty: 0) CreateObject1

UPDATE `creature_template` SET `npcflag`=281474976710658 WHERE `entry`=189602; -- Toddy Whiskers

-- Devrishians and Dracthyr Evokers
DELETE FROM `creature_template_addon` WHERE `entry` IN (198408 /*198408 (Dervishian)*/, 198401 /*198401 (Dervishian)*/, 198393 /*198393 (Dracthyr Evoker) - Sparring Aura: AzureStrike/Pyre/TimeSpiral/ObsidianScales [DNT]*/, 189078 /*189078 (Scalecommander Azurathel) - Chat Bubble*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(198401, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 198401 (Dervishian)
(198408, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 198408 (Dervishian)
(198393, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '393746'), -- 198393 (Dracthyr Evoker) - Sparring Aura: AzureStrike/Pyre/TimeSpiral/ObsidianScales [DNT]
(189078, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '394125'); -- 189078 (Scalecommander Azurathel) - Chat Bubble

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=64978 WHERE (`Entry`=198401 AND `DifficultyID`=0); -- 198401 (Dervishian) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=64978 WHERE (`Entry`=198408 AND `DifficultyID`=0); -- 198408 (Dervishian) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=64978 WHERE (`Entry`=189078 AND `DifficultyID`=0); -- 189078 (Scalecommander Azurathel) - CanSwim

DELETE FROM `creature_text` WHERE `CreatureID`=198401 AND `comment`='Dervishian to Player';
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(198401, 0, 0, 'The dracthyr stand ready.', 12, 0, 100, 0, 0, 203256, 216925, 0, 'Dervishian to Player');

UPDATE `creature_template_gossip` SET `VerifiedBuild`=64978 WHERE (`CreatureID`=198401 AND `MenuID`=30045);

-- Scalecommander Azurathel
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=189078 AND `MenuID`=30077);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(189078, 30077, 64978); -- Scalecommander Azurathel

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 232566, 0, 0, 0, 0, 0, 0, 0, 64978); -- 189078 (Scalecommander Azurathel)

DELETE FROM `gossip_menu` WHERE (`MenuID`=30077 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(30077, @NPCTEXTID+0, 64978); -- 189078 (Scalecommander Azurathel)

-- Scalecommander Azurathel smart ai
SET @ENTRY := 189603;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 19, 0, 100, 0, 72240, 0, 0, 0, 0, 44, 19821, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest The Obsidian Warders (72240) - Player who accepted quest: Add phase id to Phase 19821 (19821)', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 44, 19820, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest The Obsidian Warders (72240) - Player who accepted quest: Add phase id to Phase 19820 (19820)', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 189603 AND `SourceId` = 0;

-- Dervishian smart ai
SET @ENTRY := 198401;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 30045, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 30045 selected - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 44, 19820, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 30045 selected - Gossip player: Remove phase id Phase 19820 (19820)', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 44, 19822, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 30045 selected - Gossip player: Add phase id to Phase 19822 (19822)', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 33, 198401, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 30045 selected - Gossip player: Give kill credit Dervishian (198401)', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 198401 AND `SourceId` = 0;
