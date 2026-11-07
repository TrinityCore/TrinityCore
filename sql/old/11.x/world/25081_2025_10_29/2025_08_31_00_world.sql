SET @CGUID := 10006837;
SET @OGUID := 10001697;

SET @ATID := 163;

SET @NPCTEXTID := 600127;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 231919, 1643, 9042, 9575, '0', 24836, 0, 0, 0, 2519.23095703125, -769.3975830078125, 39.56610107421875, 0.777139186859130859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62801); -- Botanist Alaenra (Area: Rosaline's Apiary - Difficulty: 0) CreateObject1 (Auras: 466711 - Create Area Trigger [DNT])
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '466711'); -- Botanist Alaenra - 466711 - Create Area Trigger [DNT]

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 474242, 2738, 15336, 15792, '0', 24796, 0, 1331.578125, -1045.7066650390625, -97.1038818359375, 1.35928809642791748, 0, 0, 0.628516197204589843, 0.777796447277069091, 120, 255, 1, 62801); -- Portal to Stormsong Valley (Area: The Oasis - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+0;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0, 1, 2100, 24311); -- Portal to Stormsong Valley

-- Serverside Areatrigger
DELETE FROM `areatrigger_template` WHERE `Id`=@ATID+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(@ATID+0, 1, 1, 0, 0, 0);

DELETE FROM areatrigger_create_properties WHERE Id=34963 AND IsCustom=0;
INSERT INTO areatrigger_create_properties (Id, IsCustom, AreaTriggerId, IsAreatriggerCustom, Flags, MoveCurveId, ScaleCurveId, MorphCurveId, FacingCurveId, AnimId, AnimKitId, DecalPropertiesId, SpellForVisuals, TimeToTargetScale, Shape, ShapeData0, ShapeData1, ShapeData2, ShapeData3, ShapeData4, ShapeData5, ShapeData6, ShapeData7, ScriptName, VerifiedBuild) VALUES
(34963, 0, @ATID+0, 1, 4, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 15, 15, 0, 0, 0, 0, 0, 0, 'SmartAreaTriggerAI', 0);

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=231919; -- Botanist Alaenra

DELETE FROM `gameobject_template` WHERE `entry`=474242;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(474242, 10, 63415, 'Portal to Stormsong Valley', 'questinteract', 'Activating', '', 1.299999952316284179, 93, 0, 0, 1, 0, 0, 0, 0, 0, 0, 466678, 0, 0, 0, 129851, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3007, 62801); -- Portal to Stormsong Valley

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` = 231919);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(231919, 0, 0, 0, 3007, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62801); -- 231919 (Botanist Alaenra) - CanSwim

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=283264 WHERE (`Entry`=231919 AND `DifficultyID`=0); -- Botanist Alaenra

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID`=123088;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(123088, 0.382999986410140991, 1.5, 0, 62801);

-- Phasing
DELETE FROM `phase_name` WHERE `ID` IN (24796,24836);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(24796, 'Cosmetic - Portal to Stormsong Valley in The Oasis'),
(24836, 'Cosmetic - See Botanist Alaenra kneel at Rosalines Apiary');

DELETE FROM `phase_area` WHERE `PhaseId` IN (24796,24836);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(15792, 24796, 'Portal to Stormsong Valley in The Oasis'),
(9042, 24836, 'See Botanist Alaenra kneel at Rosalines Apiary');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (24796,24836) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 24796, 0, 0, 0, 47, 0, 85075, 2|8|64, 0, 0, 'Apply Phase 24796 if Quest 85075 is in progress | complete | rewarded'),
(26, 24836, 0, 0, 0, 47, 0, 85075, 2|8|64, 0, 0, 'Apply Phase 24796 if Quest 85075 is in progress | complete | rewarded');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=27023;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(27023, 73841, 0, 62801);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=27023 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(27023, 102228, 10006795, 0, 0, 0, 0, 0, 62801); -- Full: 0x2042255640E2630000088600003060C1 Creature/0 R4233/S2182 Map: 2738 (K'aresh) Entry: 231820 (Ve'nari) Low: 3170497

DELETE FROM `conversation_line_template` WHERE `Id` IN (78546, 73841);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(78546, 0, 0, 0, 0, 62801),
(73841, 0, 0, 0, 0, 62801);

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=231919 AND `MenuID`=36982);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(231919, 36982, 62801); -- Botanist Alaenra

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+3;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 275682, 0, 0, 0, 0, 0, 0, 0, 62801), -- 231919 (Botanist Alaenra)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 275680, 0, 0, 0, 0, 0, 0, 0, 62801), -- 231919 (Botanist Alaenra)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 275678, 0, 0, 0, 0, 0, 0, 0, 62801), -- 231919 (Botanist Alaenra)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 275673, 0, 0, 0, 0, 0, 0, 0, 62801); -- 231919 (Botanist Alaenra)

DELETE FROM `gossip_menu` WHERE (`MenuID`=36979 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=36980 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=36981 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=36982 AND `TextID`=@NPCTEXTID+3);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(36979, @NPCTEXTID+0, 62801), -- 231919 (Botanist Alaenra)
(36980, @NPCTEXTID+1, 62801), -- 231919 (Botanist Alaenra)
(36981, @NPCTEXTID+2, 62801), -- 231919 (Botanist Alaenra)
(36982, @NPCTEXTID+3, 62801); -- 231919 (Botanist Alaenra)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (36979,36980,36982,36981));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(36979, 125077, 0, 0, 'Let\'s save some bees.', 0, 0, 0, 36982, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 62801),
(36980, 125074, 0, 0, 'K\'aresh.', 76407, 0, 0, 36979, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 62801),
(36982, 125076, 0, 0, 'To get bees.', 0, 0, 0, 36981, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 62801),
(36981, 125075, 0, 0, 'I really need bees.', 0, 0, 0, 36980, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 62801);

-- Spelltarget
DELETE FROM `spell_target_position` WHERE (`ID`=466678 AND `EffectIndex`=0 AND `OrderIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `OrderIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(466678, 0, 0, 1643, 2529.449951171875, -759.8599853515625, 36.34000015258789062, 62801); -- Spell: 466678 (Portal to Stormsong Valley) Effect 0: 15 (SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL)

-- Quest
DELETE FROM `quest_details` WHERE `ID`=85075;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(85075, 1, 0, 0, 0, 0, 0, 0, 0, 62801); -- To Stormsong

DELETE FROM `creature_queststarter` WHERE (`id`=231820 AND `quest`=85075);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(231820, 85075, 62801); -- To Stormsong offered by Ve'nari

DELETE FROM `creature_questender` WHERE (`id`=231919 AND `quest`=85075);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(231919, 85075, 62801); -- To Stormsong ended by Botanist Alaenra

DELETE FROM `quest_template_addon` WHERE `ID` = 85075;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(85075, 0, 0, 0, 87340, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Ve'nari smart ai
SET @ENTRY := 231820;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 87339, 0, 0, 0, 0, 143, 28311, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Ongoing Activities (87339) - Player who accepted quest: Start conversation (28311) Actors<> (first line 77832)', ''),
(@ENTRY, 0, 1, 0, 19, 0, 100, 0, 87340, 0, 0, 0, 0, 143, 28316, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Junk Mail (87340) - Player who accepted quest: Start conversation (28316) Actors<> (first line 77849)', ''),
(@ENTRY, 0, 2, 0, 19, 0, 100, 0, 85075, 0, 0, 0, 0, 143, 27023, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest To Stormsong (85075) - Player who accepted quest: Start conversation 27023', '');

SET @ENTRY := @ATID+0;
DELETE FROM `smart_scripts` WHERE `source_type` = 12 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ATID+0, 12, 0, 0, '', 46, 0, 100, 0, 0, 0, 0, 0, 0, '', 33, 231923, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On trigger - reward Credit 231923 to Invoker');
