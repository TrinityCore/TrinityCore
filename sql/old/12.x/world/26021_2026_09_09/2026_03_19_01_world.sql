SET @CGUID := 11000000;
SET @NPCTEXTID := 610006;

SET @ATID := 183;
SET @ATIDSPAWN := 281;
SET @ATCP := 174;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+15;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 252524, 0, 15969, 16079, '0', 27731, 0, 0, 0, 8272.0341796875, -4646.7587890625, 18.7498931884765625, 4.022519588470458984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66198), -- Generic Bunny (Area: The Bazaar - Difficulty: 0) CreateObject1 (Auras: 1256029 - Light Circle)
(@CGUID+1, 242177, 0, 15969, 16079, '0', 27731, 0, 0, 1, 8273.142578125, -4647.40478515625, 18.7498931884765625, 1.586910605430603027, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66198), -- High Exarch Turalyon (Area: The Bazaar - Difficulty: 0) CreateObject1 (Auras: 1229378 - Spectral Form)
(@CGUID+2, 241677, 0, 15969, 16079, '0', 27731, 0, 0, 1, 8271.912109375, -4645.44287109375, 18.7498931884765625, 1.697510004043579101, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66198), -- Image of Lady Liadrin (Area: The Bazaar - Difficulty: 0) CreateObject1 (Auras: 1227721 - Spectral Form, 1261314 - [DNT] Talk To Me)
(@CGUID+3, 242175, 0, 15969, 16079, '0', 27731, 0, 0, 1, 8270.205078125, -4647.49853515625, 18.7498931884765625, 1.871971011161804199, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66198), -- Lor'themar Theron (Area: The Bazaar - Difficulty: 0) CreateObject1 (Auras: 1229378 - Spectral Form)
(@CGUID+4, 242173, 0, 1519, 5151, '0', 27732, 0, 0, 0, -8624.078125, 798.3367919921875, 97.38117218017578125, 6.18256378173828125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66198), -- Generic Bunny (Area: Cathedral Square - Difficulty: 0) CreateObject1 (Auras: 1229377 - Light Circle)
(@CGUID+5, 241677, 0, 1519, 5151, '0', 27732, 0, 0, 1, -8625.107421875, 797.50347900390625, 97.30132293701171875, 3.85755467414855957, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66198), -- Image of Lady Liadrin (Area: Cathedral Square - Difficulty: 0) CreateObject1 (Auras: 1227721 - Spectral Form, 1261314 - [DNT] Talk To Me)
(@CGUID+6, 242177, 0, 1519, 5151, '0', 27732, 0, 0, 1, -8624.1650390625, 799.61456298828125, 97.24207305908203125, 3.746955156326293945, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66198), -- High Exarch Turalyon (Area: Cathedral Square - Difficulty: 0) CreateObject1 (Auras: 1229378 - Spectral Form)
(@CGUID+7, 242175, 0, 1519, 5151, '0', 27732, 0, 0, 1, -8622.451171875, 797.2274169921875, 97.31203460693359375, 4.032015323638916015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66198), -- Lor'themar Theron (Area: Cathedral Square - Difficulty: 0) CreateObject1 (Auras: 1229378 - Spectral Form)
(@CGUID+8, 252524, 1, 1637, 5170, '0', 27733, 0, 0, 0, 1590.02783203125, -4437.25, 13.54166603088378906, 3.958757400512695312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66198), -- Generic Bunny (Area: Valley of Strength - Difficulty: 0) CreateObject1 (Auras: 1256029 - Light Circle)
(@CGUID+9, 242177, 1, 1637, 5170, '0', 27733, 0, 0, 1, 1591.625, -4438.33837890625, 13.45592594146728515, 1.523148655891418457, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66198), -- High Exarch Turalyon (Area: Valley of Strength - Difficulty: 0) CreateObject1 (Auras: 1229378 - Spectral Form)
(@CGUID+10, 241677, 1, 1637, 5170, '0', 27733, 0, 0, 1, 1590.1353759765625, -4435.73095703125, 13.73611068725585937, 1.633748173713684082, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66198), -- Image of Lady Liadrin (Area: Valley of Strength - Difficulty: 0) CreateObject1 (Auras: 1227721 - Spectral Form, 1261314 - [DNT] Talk To Me)
(@CGUID+11, 242175, 1, 1637, 5170, '0', 27733, 0, 0, 1, 1588.6875, -4438.24462890625, 13.27256965637207031, 1.808209657669067382, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66198), -- Lor'themar Theron (Area: Valley of Strength - Difficulty: 0) CreateObject1 (Auras: 1229378 - Spectral Form)
(@CGUID+12, 242173, 2552, 14771, 15042, '0', 27734, 0, 0, 0, 2813.788330078125, -2461.435791015625, 239.1597137451171875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66198), -- Generic Bunny (Area: Keepers Terrace - Difficulty: 0) CreateObject1 (Auras: 1229377 - Light Circle)
(@CGUID+13, 242175, 2552, 14771, 15042, '0', 27734, 0, 0, 1, 2815.6884765625, -2461.734375, 239.200439453125, 4.13263702392578125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66198), -- Lor'themar Theron (Area: Keepers Terrace - Difficulty: 0) CreateObject1 (Auras: 1229378 - Spectral Form)
(@CGUID+14, 242177, 2552, 14771, 15042, '0', 27734, 0, 0, 1, 2813.744873046875, -2459.532958984375, 239.1829986572265625, 3.847576856613159179, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66198), -- High Exarch Turalyon (Area: Keepers Terrace - Difficulty: 0) CreateObject1 (Auras: 1229378 - Spectral Form)
(@CGUID+15, 241677, 2552, 14771, 15042, '0', 27734, 0, 0, 1, 2812.98779296875, -2462.282958984375, 239.2056121826171875, 3.958176374435424804, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66198); -- Image of Lady Liadrin (Area: Keepers Terrace - Difficulty: 0) CreateObject1 (Auras: 1227721 - Spectral Form, 1261314 - [DNT] Talk To Me)

-- Creature template
UPDATE `creature_template` SET `faction`=2361, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4004800, `unit_flags3`=0x41000000 WHERE `entry`=242175; -- Lor'themar Theron
UPDATE `creature_template` SET `faction`=190, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=241677; -- Image of Lady Liadrin
UPDATE `creature_template` SET `faction`=2361, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4004800, `unit_flags3`=0x41000000 WHERE `entry`=242177; -- High Exarch Turalyon
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x800, `unit_flags3`=0x40008000, `flags_extra`=128 WHERE `entry`=252524; -- Generic Bunny
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x800, `unit_flags3`=0x40008000, `flags_extra`=128 WHERE `entry`=242173; -- Generic Bunny

-- Creature template addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (242175 /*242175 (Lor'themar Theron) - Spectral Form*/, 241677 /*241677 (Image of Lady Liadrin) - Spectral Form, [DNT] Talk To Me*/, 242177 /*242177 (High Exarch Turalyon) - Spectral Form*/, 252524 /*252524 (Generic Bunny) - Light Circle*/, 242173 /*242173 (Generic Bunny) - Light Circle*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(242175, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '1229378'), -- 242175 (Lor'themar Theron) - Spectral Form
(241677, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1227721 1261314'), -- 241677 (Image of Lady Liadrin) - Spectral Form, [DNT] Talk To Me
(242177, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '1229378'), -- 242177 (High Exarch Turalyon) - Spectral Form
(252524, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '1256029'), -- 252524 (Generic Bunny) - Light Circle
(242173, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '1229377'); -- 242173 (Generic Bunny) - Light Circle

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (27731,27732,27733,27734);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES 
(27731, 'Cosmetic - See Liadrin, Turalyon & Theron in The Bazaar, Silvermoon City'),
(27732, 'Cosmetic - See Liadrin, Turalyon & Theron in Cathedral Square, Stormwind City'),
(27733, 'Cosmetic - See Liadrin, Turalyon & Theron in Valley of Strength, Orgrimmar'),
(27734, 'Cosmetic - See Liadrin, Turalyon & Theron in Keepers Terrace, Dornogal');

DELETE FROM `phase_area` WHERE (`AreaId`=16079 AND `PhaseId`=27731) OR (`AreaId`=5151 AND `PhaseId`=27732) OR (`AreaId`=5170 AND `PhaseId`=27733) OR (`AreaId`=15042 AND `PhaseId`=27734);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES 
(16079, 27731, 'Cosmetic: See Liadrin, Turalyon & Theron in The Bazaar, Silvermoon City'),
(5151, 27732, 'Cosmetic: See Liadrin, Turalyon & Theron in Cathedral Square, Stormwind City'),
(5170, 27733, 'Cosmetic: See Liadrin, Turalyon & Theron in Valley of Strength, Orgrimmar'),
(15042, 27734, 'Cosmetic: See Liadrin, Turalyon & Theron in Keepers Terrace, Dornogal');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE `CreatureID`=241677 AND `MenuID`=39008;
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(241677, 39008, 66198); -- Image of Lady Liadrin

DELETE FROM `npc_text` WHERE `ID`=@NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 288649, 0, 0, 0, 0, 0, 0, 0, 66198); -- 241677 (Image of Lady Liadrin)

DELETE FROM `gossip_menu` WHERE `MenuID`=39008 AND `TextID`=@NPCTEXTID+0;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(39008, @NPCTEXTID+0, 66198); -- 241677 (Image of Lady Liadrin)

DELETE FROM `gossip_menu_option` WHERE `MenuID`=39008 AND `OptionID` IN (7,8);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(39008, 133521, 7, 0, 'What has happened at the Sunwell?', 0, 0, 4, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66198),
(39008, 138201, 8, 0, 'I have heard this tale before.\n|cFFFF0000<Skip the Midnight introduction and travel to the Sanctum of Light.>|r', 0, 0, 0, 0, 0, NULL, 0, 0, 'Are you sure you wish to skip the Midnight introduction? Certain quests may be abandoned. This action cannot be undone.', 0, NULL, NULL, 66198);

-- Spelltarget
DELETE FROM `spell_target_position` WHERE `ID`=1278779 AND `EffectIndex`=0 AND `OrderIndex`=0;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `OrderIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(1278779, 0, 0, 0, 8452.6396484375, -4612.240234375, 48.25999832153320312, 66198); -- Spell: 1278779 ([DNT] Skip Midnight Intro - Teleport) Effect 0: 15 (SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL)

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3592, `StaticFlags1`=0x30000100, `VerifiedBuild`=66198 WHERE `Entry`=242175 AND `DifficultyID`=0; -- 242175 (Lor'themar Theron) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3085, `StaticFlags1`=0x10000000, `VerifiedBuild`=66198 WHERE `Entry`=241677 AND `DifficultyID`=0; -- 241677 (Image of Lady Liadrin) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3592, `StaticFlags1`=0x30000100, `VerifiedBuild`=66198 WHERE `Entry`=242177 AND `DifficultyID`=0; -- 242177 (High Exarch Turalyon) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3085, `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=66198 WHERE `Entry`=252524 AND `DifficultyID`=0; -- 252524 (Generic Bunny) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3085, `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=66198 WHERE `Entry`=242173 AND `DifficultyID`=0; -- 242173 (Generic Bunny) - Sessile, Floating - CannotTurn

-- Quest
DELETE FROM `quest_template_addon` WHERE `ID`=91281;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(91281, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, '');

-- Conversation
DELETE FROM `conversation_actors` WHERE `ConversationId`=29111 AND `Idx`=0;
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(29111, 106520, 0, 241677, 136435, 0, 0, 66337);

DELETE FROM `conversation_line_template` WHERE `Id` IN (85759, 80417);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(85759, 1894, 0, 0, 0, 66337),
(80417, 1894, 0, 0, 0, 66337);

DELETE FROM `conversation_template` WHERE `Id`=29111;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(29111, 80417, 0, 66337);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (27731,27732,27733,27734);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 27731, 16079, 0, 0, 47, 0, 88719, 64, 0, '', 1, 0, 0, '', 'Apply Phase 27731 If Quest 88719 is not rewarded'),
(26, 27732, 5151, 0, 0, 47, 0, 88719, 64, 0, '', 1, 0, 0, '', 'Apply Phase 27732 If Quest 88719 is not rewarded'),
(26, 27733, 5170, 0, 0, 47, 0, 88719, 64, 0, '', 1, 0, 0, '', 'Apply Phase 27733 If Quest 88719 is not rewarded'),
(26, 27734, 15042, 0, 0, 47, 0, 88719, 64, 0, '', 1, 0, 0, '', 'Apply Phase 27734 If Quest 88719 is not rewarded');

-- Serverside Areatrigger
DELETE FROM `areatrigger_template` WHERE `Id`=@ATID+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATIDSPAWN+0 AND @ATIDSPAWN+3;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 0, '0', 8271.912109375, -4645.44287109375, 18.7498931884765625, 1.697510004043579101, 0, 27731, 0, 'SmartAreaTriggerAI', 'Silvermoon City - Quest credit for 91281 ', 0),
(@ATIDSPAWN+1, @ATCP+0, 1, 0, '0', -8625.107421875, 797.50347900390625, 97.30132293701171875, 3.85755467414855957, 0, 27732, 0, 'SmartAreaTriggerAI', 'Stormwind City - Quest credit for 91281', 0),
(@ATIDSPAWN+2, @ATCP+0, 1, 1, '0', 1590.1353759765625, -4435.73095703125, 13.73611068725585937, 1.633748173713684082, 0, 27733, 0, 'SmartAreaTriggerAI', 'Orgrimmar City - Quest credit for 91281', 0),
(@ATIDSPAWN+3, @ATCP+0, 1, 2552, '0', 2812.98779296875, -2462.282958984375, 239.2056121826171875, 3.958176374435424804, 0, 27734, 0, 'SmartAreaTriggerAI', 'Dornogal - Quest credit for 91281', 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=@ATCP+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, '', 0); 

-- Image of Lady Liadrin smart ai
SET @ENTRY := 241677;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 62, 0, 100, 0, 39008, 7, 0, 0, 0, 85, 1231650, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 7 from menu 39008 selected - Gossip player: Cast spell 1231650 on self', ''),
(@ENTRY, 0, 1, 0, 62, 0, 100, 0, 39008, 8, 0, 0, 0, 85, 1278767, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 8 from menu 39008 selected - Gossip player: Cast spell 1278767 on self', '');

-- Midnight SAI
SET @ENTRY := 91281;
UPDATE `quest_template_addon` SET `ScriptName`='SmartQuest' WHERE `ID`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=5 AND `entryOrGuid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 5, 0, 0, 47, 0, 100, 0, 0, 0, 0, 0, 0, 143, 29111, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On quest accepted - Player who accepted: Start conversation 29111', '');

-- Serverside Areatrigger SAI + Conditions
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ATID+0 AND `source_type`=12 AND `id`=0 AND `link`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ATID+0, 12, 0, 1, '', 46, 0, 100, 0, 0, 0, 0, 0, 0, '', 33, 241677, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On AreaTrigger enter - reward Credit 241677 to Invoker');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=28 AND `SourceGroup`=@ATID+0 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(28, @ATID+0, 1, 0, 0, 47, 0, 91281, 8, 0, '', 0, 0, 0, '', 'Only trigger areatrigger when quest 91281 is in progress');
