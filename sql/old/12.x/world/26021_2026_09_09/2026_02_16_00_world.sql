SET @CGUID := 10006934;
SET @OGUID := 10001991;

SET @NPCTEXTID := 600175;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+27;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 231044, 2552, 14717, 15943, '0', 25033, 0, 0, 0, 2506.575439453125, -617.95660400390625, 43.21270370483398437, 6.251854419708251953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Voidbringer Aqu'lir (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: 470722 - Act 1 - Q04a - Combat Conversation Area Trigger [DNT], 458839 - [DNT] 11.0 Z5 - Arathi's End - Cosmetic Void Channeling)
(@CGUID+1, 231131, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2672.126708984375, -592.94268798828125, 10.41444110870361328, 4.610484600067138671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Voidshaper (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: 447099 - Void Channeling)
(@CGUID+2, 231131, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2619.4296875, -607.796875, 18.826171875, 3.896938323974609375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Voidshaper (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: 447099 - Void Channeling)
(@CGUID+3, 231131, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2664.595458984375, -612.89239501953125, 13.18012619018554687, 2.260497570037841796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Voidshaper (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: 447099 - Void Channeling)
(@CGUID+4, 231132, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2616.651123046875, -607.234375, 19.08385848999023437, 5.128014087677001953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Reaver (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+5, 231132, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2586.998291015625, -664.5555419921875, 32.88380050659179687, 5.303042411804199218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Reaver (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+6, 231131, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2656.049560546875, -655.1007080078125, 14.07492923736572265, 2.93261122703552246, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Voidshaper (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: 447099 - Void Channeling)
(@CGUID+7, 231132, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2654.08935546875, -656.04339599609375, 14.48240470886230468, 2.387708187103271484, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Reaver (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+8, 231132, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2671.893310546875, -629.99481201171875, 10.82830810546875, 0.367085874080657958, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Reaver (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+9, 231132, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2625.739501953125, -701.86285400390625, 17.19153594970703125, 2.446544885635375976, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Reaver (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+10, 231132, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2629.69873046875, -656.57293701171875, 18.42652320861816406, 3.16241312026977539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Reaver (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+11, 231132, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2630.0625, -693.2882080078125, 16.79233741760253906, 3.152737617492675781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Reaver (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+12, 231131, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2641.765625, -639.42535400390625, 16.6365509033203125, 2.990788459777832031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Voidshaper (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+13, 231131, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2628.7265625, -654.62847900390625, 18.51388931274414062, 4.21378326416015625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Voidshaper (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: 447099 - Void Channeling)
(@CGUID+14, 231132, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2647.512939453125, -625.592041015625, 15.14007186889648437, 1.218245983123779296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Reaver (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+15, 231132, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2683.259521484375, -642.14410400390625, 10.80036354064941406, 0.881974518299102783, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Reaver (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+16, 231132, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2672.32373046875, -628.68231201171875, 11.11631965637207031, 0.34865465760231018, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Reaver (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+17, 231132, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2654.077392578125, -590.48089599609375, 12.96639060974121093, 4.553288936614990234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Reaver (Area: Oztan Isle - Difficulty: 0) CreateObject2
(@CGUID+18, 231131, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2651.04345703125, -594.11981201171875, 11.02543354034423828, 5.956804275512695312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Voidshaper (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: 447099 - Void Channeling)
(@CGUID+19, 231132, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2618.009521484375, -682.42535400390625, 19.19444465637207031, 1.008606195449829101, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Reaver (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+20, 231132, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2617.7109375, -681.19268798828125, 19.27083396911621093, 3.929467439651489257, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Reaver (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+21, 231132, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2558.34033203125, -673.88543701171875, 38.79765701293945312, 2.533053874969482421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Reaver (Area: Oztan Isle - Difficulty: 0) CreateObject2
(@CGUID+22, 231132, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2585.89404296875, -625.2117919921875, 32.7240753173828125, 3.452043771743774414, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Reaver (Area: Oztan Isle - Difficulty: 0) CreateObject2
(@CGUID+23, 231132, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2585.671875, -627.49481201171875, 33.21722030639648437, 2.478862762451171875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Reaver (Area: Oztan Isle - Difficulty: 0) CreateObject2
(@CGUID+24, 231131, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2591.392333984375, -667.185791015625, 32.55603790283203125, 3.370379447937011718, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Twilight Voidshaper (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: 447099 - Void Channeling)
(@CGUID+25, 233312, 2552, 14717, 15943, '0', 25036, 0, 0, 1, 2731.892333984375, -607.65625, 10.58854103088378906, 3.109530210494995117, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Arator (Area: Oztan Isle - Difficulty: 0) CreateObject1 (Auras: 1219560 - Act 1 - Q05 - Stay Awhile RP Chat Bubble [DNT])
(@CGUID+26, 233314, 2552, 14717, 15943, '0', 25035, 0, 0, 1, 2731.713623046875, -609.6319580078125, 10.48090267181396484, 3.359456539154052734, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Vereesa Windrunner (Area: Oztan Isle - Difficulty: 0) CreateObject1 (Auras: 470255 - Pained by Vision)
(@CGUID+27, 231131, 2552, 14717, 15943, '0', 25033, 0, 0, 1, 2543.501708984375, -658.904541015625, 40.29861068725585937, 4.072113037109375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727); -- Twilight Voidshaper (Area: Oztan Isle - Difficulty: 0) CreateObject2 (Auras: 447099 - Void Channeling)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+27;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Reaver
(@CGUID+22, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Reaver
(@CGUID+23, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Reaver
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 3, '1219560'), -- Arator - 1219560 - Act 1 - Q05 - Stay Awhile RP Chat Bubble [DNT]
(@CGUID+26, 0, 0, 0, 0, 0, 1, 0, 376, 0, 0, 0, 0, '470255'); -- Vereesa Windrunner - 470255 - Pained by Vision

-- GameObject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 494778, 2552, 14717, 15943, '0', 25033, 0, 2488.7119140625, -618.80035400390625, 41.82032012939453125, 0, 0, 0, 0, 1, 120, 255, 1, 65727); -- Void Portal (Area: Oztan Isle - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0, 1, 0, 9882); -- Void Portal

-- Template
DELETE FROM `gameobject_template` WHERE `entry`=494778;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `RequiredLevel`, `ContentTuningId`, `VerifiedBuild`) VALUES
(494778, 5, 86858, 'Void Portal', '', '', '', 5, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65727); -- Void Portal

UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=231044; -- Voidbringer Aqu'lir
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=231131; -- Twilight Voidshaper
UPDATE `creature_template` SET `faction`=16, `speed_walk`=0.888888001441955566, `speed_run`=0.992062866687774658, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=231133; -- Bound Voidminion
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=231132; -- Twilight Reaver
UPDATE `creature_template` SET `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=233329; -- Silver Hand Avenger
UPDATE `creature_template` SET `faction`=2007, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry` IN (231136, 233366, 233372, 233374); -- Dalaran Custodian
UPDATE `creature_template` SET `faction`=534, `npcflag`=281474976710659, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4800 WHERE `entry`=233314; -- Vereesa Windrunner
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=233312; -- Arator

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (231044);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(231044, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '470722'); -- 231044 (Voidbringer Aqu'lir) - Act 1 - Q04a - Combat Conversation Area Trigger [DNT], [DNT] 11.0 Z5 - Arathi's End - Cosmetic Void Channeling

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (25033,25035,25036);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(25033, 'Oztan Isle - Twilight Attack'),
(25035, 'Cosmetic - See Vereesa after Ceromony'),
(25036, 'Cosmetic - See Arator after Ceromony');

DELETE FROM `phase_area` WHERE `PhaseId` IN (25033,25035,25036);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(14717, 25033, 'Oztan Isle - Twilight Attack'),
(14717, 25035, 'Cosmetic - See Vereesa after Ceromony'),
(14717, 25036, 'Cosmetic - See Arator after Ceromony');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (25033,25035,25036) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 25033, 0, 0, 0, 47, 0, 84997, 2|64, 0, 0, 'Apply Phase 25033 if Quest 84997 is complete|rewarded'),
(26, 25033, 0, 0, 0, 47, 0, 85002, 64, 0, 1, 'Apply Phase 25033 if Quest 85002 is not rewarded'),
(26, 25035, 0, 0, 0, 47, 0, 84997, 2|64, 0, 0, 'Apply Phase 25035 if Quest 84997 is complete|rewarded'),
(26, 25036, 0, 0, 0, 47, 0, 84997, 2|64, 0, 0, 'Apply Phase 25036 if Quest 84997 is complete|rewarded');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=27504;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(27504, 83249, 0, 65727);

DELETE FROM `conversation_line_template` WHERE `Id` IN (75414, 83249);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(75414, 1870, 1, 0, 1, 65727),
(83249, 0, 0, 0, 0, 65727);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=27504 AND `Idx` IN (1,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(27504, 103072, 1, 231044, 137872, 0, 0, 65727),
(27504, 0, 0, 0, 0, 0, 1, 65727); -- Full: 0x0800040000000000FFFFFFFFFFFFFFFF Player/0 R1/S16777215 Map: 0 (Eastern Kingdoms) Low: 1099511627775

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=233312 AND `MenuID`=38055);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(233312, 38055, 65893); -- Arator

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 281397, 0, 0, 0, 0, 0, 0, 0, 65893); -- 233312 (Arator)

DELETE FROM `gossip_menu` WHERE (`MenuID`=38055 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(38055, @NPCTEXTID+0, 65893); -- 233312 (Arator)

-- SpellArea
DELETE FROM `spell_area` WHERE `spell` = 470697 AND `area` = 14717;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(470697, 14717, 84997, 85002, 0, 0, 2, 3, 66, 11);

-- Quest
DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` = 453588;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(453588, NULL, NULL, 27504, 1, 0);

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID`=131870;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(131870, 0.382999986410140991, 1.5, 0, 65727);

UPDATE `creature_model_info` SET `VerifiedBuild`=65727 WHERE `DisplayID` IN (120674, 120684, 119468, 61950, 100362, 90740, 131869, 123915, 123904, 123905, 104040, 104041, 137872, 131871, 104531, 131872, 131867, 131868, 131866, 61947, 106699, 106700, 123907, 123910, 114820, 114816, 104530, 123908, 123906, 130420, 123909, 28222);
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=65727 WHERE `DisplayID`=62328;
UPDATE `creature_model_info` SET `BoundingRadius`=0.659033596515655517, `CombatReach`=0.60000002384185791, `VerifiedBuild`=65727 WHERE `DisplayID`=129733;

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3020, `StaticFlags1`=0x10000000, `VerifiedBuild`=65727 WHERE (`Entry`=231044 AND `DifficultyID`=0); -- 231044 (Voidbringer Aqu'lir) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3020, `StaticFlags1`=0x10000000, `VerifiedBuild`=65727 WHERE (`Entry`=231131 AND `DifficultyID`=0); -- 231131 (Twilight Voidshaper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3020, `StaticFlags1`=0x10000000, `VerifiedBuild`=65727 WHERE (`Entry`=231133 AND `DifficultyID`=0); -- 231133 (Bound Voidminion) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3020, `StaticFlags1`=0x10000000, `VerifiedBuild`=65727 WHERE (`Entry`=231132 AND `DifficultyID`=0); -- 231132 (Twilight Reaver) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3020, `StaticFlags1`=0x10000000, `VerifiedBuild`=65727 WHERE (`Entry`=233329 AND `DifficultyID`=0); -- 233329 (Silver Hand Avenger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3020, `StaticFlags1`=0x10000000, `VerifiedBuild`=65727 WHERE (`Entry`=231136 AND `DifficultyID`=0); -- 231136 (Dalaran Custodian) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3020, `StaticFlags1`=0x10000000, `VerifiedBuild`=65727 WHERE (`Entry`=233366 AND `DifficultyID`=0); -- 233366 (Dalaran Custodian) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3020, `StaticFlags1`=0x10000000, `StaticFlags3`=0x2000000, `VerifiedBuild`=65727 WHERE (`Entry`=233314 AND `DifficultyID`=0); -- 233314 (Vereesa Windrunner) - CanSwim - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3020, `StaticFlags1`=0x10000000, `StaticFlags3`=0x2000000, `VerifiedBuild`=65727 WHERE (`Entry`=233252 AND `DifficultyID`=0); -- 233252 (Vereesa Windrunner) - CanSwim - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3020, `StaticFlags1`=0x10000000, `VerifiedBuild`=65727 WHERE (`Entry`=233312 AND `DifficultyID`=0); -- 233312 (Arator) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3020, `StaticFlags1`=0x10000000, `VerifiedBuild`=65727 WHERE (`Entry`=233372 AND `DifficultyID`=0); -- 233372 (Dalaran Custodian) - CanSwim

-- Path for Twilight Voidshaper
SET @MOVERGUID := @CGUID+12;
SET @ENTRY := 231131;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Twilight Voidshaper - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2624.3525, -635.78516, 18.925592, NULL, 0),
(@PATH, 1, 2618.1536, -631.7118, 20.649437, NULL, 0),
(@PATH, 2, 2615.5051, -628.27954, 21.534279, NULL, 0),
(@PATH, 3, 2613.4446, -624.4184, 21.947727, NULL, 0),
(@PATH, 4, 2614.263, -621.3472, 21.492739, NULL, 0),
(@PATH, 5, 2615.4524, -616.9948, 20.545212, NULL, 0),
(@PATH, 6, 2618.6545, -614.7483, 19.552668, NULL, 0),
(@PATH, 7, 2620.842, -611.7708, 18.922993, NULL, 0),
(@PATH, 8, 2622.3176, -607.49304, 18.361992, NULL, 0),
(@PATH, 9, 2621.888, -603.32117, 17.981695, NULL, 0),
(@PATH, 10, 2623.087, -597.1927, 16.339722, NULL, 0),
(@PATH, 11, 2626.4114, -595.0174, 15.153481, NULL, 0),
(@PATH, 12, 2630.375, -593.9028, 14.192085, NULL, 0),
(@PATH, 13, 2631.295, -593.50977, 13.773273, NULL, 0),
(@PATH, 14, 2634.0547, -592.33203, 13.416786, NULL, 0),
(@PATH, 15, 2635.5686, -591.6875, 13.3828745, NULL, 0),
(@PATH, 16, 2639.6685, -588.4531, 12.401909, NULL, 0),
(@PATH, 17, 2645.8135, -582.94794, 9.87181, NULL, 0),
(@PATH, 18, 2650.3672, -579.6893, 8.379915, NULL, 0),
(@PATH, 19, 2654.9036, -578.61804, 7.2015867, NULL, 0),
(@PATH, 20, 2661.4072, -577.9427, 6.6468606, NULL, 0),
(@PATH, 21, 2667.763, -576.92535, 5.948327, NULL, 0),
(@PATH, 22, 2674.1406, -575.25, 4.1074123, NULL, 0),
(@PATH, 23, 2678.6165, -576.6493, 3.701209, NULL, 0),
(@PATH, 24, 2682.159, -582.31946, 2.8112543, NULL, 0),
(@PATH, 25, 2685.1355, -586.97394, 4.000943, NULL, 0),
(@PATH, 26, 2685.1692, -590.90106, 6.1002893, NULL, 0),
(@PATH, 27, 2684.869, -595.88196, 7.7998314, NULL, 0),
(@PATH, 28, 2685.3196, -599.3299, 8.509237, NULL, 0),
(@PATH, 29, 2687.8716, -601.86456, 8.9180155, NULL, 0),
(@PATH, 30, 2687.8665, -605.375, 9.394666, NULL, 0),
(@PATH, 31, 2683.712, -611.1233, 9.004056, NULL, 0),
(@PATH, 32, 2678.283, -617.3889, 9.200097, NULL, 0),
(@PATH, 33, 2674.2744, -620.37695, 9.857422, NULL, 0),
(@PATH, 34, 2668.89, -628.23956, 11.04159, NULL, 0),
(@PATH, 35, 2662.5383, -632.65106, 12.632517, NULL, 0),
(@PATH, 36, 2655.6128, -634.4774, 14.500346, NULL, 0),
(@PATH, 37, 2651.3628, -635.6893, 15.271956, NULL, 0),
(@PATH, 38, 2645.0999, -638.53644, 16.164696, NULL, 0),
(@PATH, 39, 2639.3958, -639.25696, 16.864336, NULL, 0),
(@PATH, 40, 2633.0452, -638.1059, 17.719675, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Twilight Voidshaper
SET @MOVERGUID := @CGUID+27;
SET @ENTRY := 231131;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Twilight Voidshaper - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2547.4653, -655.6285, 39.218483, NULL, 0),
(@PATH, 1, 2552.244, -651.0851, 38.518364, NULL, 0),
(@PATH, 2, 2557.3057, -646.99133, 37.81605, NULL, 0),
(@PATH, 3, 2562.3655, -644.3351, 37.157333, NULL, 0),
(@PATH, 4, 2569.3308, -640.4948, 36.217552, NULL, 0),
(@PATH, 5, 2578.3638, -634.30383, 34.211185, NULL, 0),
(@PATH, 6, 2582.1501, -629.033, 33.835613, NULL, 16116),
(@PATH, 7, 2569.4575, -640.30554, 36.198803, NULL, 0),
(@PATH, 8, 2562.6077, -644.0018, 37.12532, NULL, 0),
(@PATH, 9, 2557.4392, -646.94617, 37.786583, NULL, 0),
(@PATH, 10, 2552.862, -650.6215, 38.477444, NULL, 0),
(@PATH, 11, 2547.75, -655.2083, 39.074623, NULL, 0),
(@PATH, 12, 2545.0574, -657.0868, 39.7119, NULL, 0),
(@PATH, 13, 2543.5017, -658.90454, 40.214787, NULL, 24611);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Twilight Reaver
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+20;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+20, @CGUID+20, 0, 0, 515, 0, 0),
(@CGUID+20, @CGUID+19, 3, 270, 515, 7, 17);

SET @MOVERGUID := @CGUID+20;
SET @ENTRY := 231132;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Twilight Reaver - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2626.0251, -679.8073, 17.920355, NULL, 0),
(@PATH, 1, 2631.2864, -677.25867, 16.805307, NULL, 0),
(@PATH, 2, 2635.5886, -674.8507, 17.116846, NULL, 0),
(@PATH, 3, 2641.303, -675.441, 17.0131, NULL, 0),
(@PATH, 4, 2645.5286, -679.0035, 16.405273, NULL, 0),
(@PATH, 5, 2648.073, -683.4722, 16.298347, NULL, 0),
(@PATH, 6, 2650.6033, -689.2049, 16.622469, NULL, 0),
(@PATH, 7, 2653.4404, -693.3262, 16.156189, NULL, 16289),
(@PATH, 8, 2650.6035, -689.2051, 16.625908, NULL, 0),
(@PATH, 9, 2648.073, -683.4722, 16.298347, NULL, 0),
(@PATH, 10, 2645.5977, -679.12695, 16.45663, NULL, 0),
(@PATH, 11, 2641.303, -675.441, 17.0131, NULL, 0),
(@PATH, 12, 2635.5886, -674.8507, 17.116846, NULL, 0),
(@PATH, 13, 2631.2864, -677.25867, 16.805307, NULL, 0),
(@PATH, 14, 2626.0251, -679.8073, 17.920355, NULL, 0),
(@PATH, 15, 2622.264, -681.066, 18.47234, NULL, 0),
(@PATH, 16, 2619.0774, -680.6007, 18.798607, NULL, 0),
(@PATH, 17, 2617.8047, -681.8698, 19.145943, NULL, 19626),
(@PATH, 18, 2622.264, -681.066, 18.47234, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
