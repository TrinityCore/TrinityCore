SET @CGUID := 9003909;
SET @OGUID := 9000360;

SET @NPCTEXTID := 590078;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 198896, 0, 12, 5637, '0', 19933, 0, 0, 1, -9472.2412109375, -3.41319441795349121, 49.87804412841796875, 5.388506889343261718, 120, 0, 0, 2258380, 0, 0, 0, 0, 0, 49801), -- Master Mathias Shaw (Area: Lion's Pride Inn - Difficulty: 0) CreateObject1 (Auras: 400406 - [DNT] Chat Bubble)
(@CGUID+1, 198883, 0, 12, 5637, '0', 19934, 0, 0, 1, -9468.169921875, -3.61284732818603515, 49.87674331665039062, 4.472257614135742187, 120, 0, 0, 338757, 100, 0, 0, 0, 0, 49801); -- Vanessa VanCleef (Area: Lion's Pride Inn - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 743, 0, 0, 0, 0, ''); -- Vanessa VanCleef

DELETE FROM `creature_template_addon` WHERE `entry` IN (198896 /*198896 (Master Mathias Shaw) - [DNT] Chat Bubble*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(198896, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '400406'); -- 198896 (Master Mathias Shaw) - [DNT] Chat Bubble

UPDATE `creature_template` SET `faction`=190, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=18432 WHERE `entry`=198883; -- Vanessa VanCleef
UPDATE `creature_template` SET `faction`=12, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=198896; -- Master Mathias Shaw

-- Update phaseUseFlag for old spawns visible in Phase 0 and 19932
UPDATE `creature` SET `phaseUseFlags` = 0x1 WHERE `guid` IN (280705, 280711, 280710, 280712, 280715);

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 386412, 0, 12, 5637, '0', 19932, 0, -9470.296875, -7.25694465637207031, 57.36728286743164062, 1.361118197441101074, 0, 0, 0.629227638244628906, 0.777221083641052246, 120, 255, 1, 49801), -- Firewood (Area: Lion's Pride Inn - Difficulty: 0) CreateObject1
(@OGUID+1, 386412, 0, 12, 5637, '0', 19932, 0, -9456.423828125, 22.96701431274414062, 56.88551712036132812, 4.230845451354980468, 0, 0, -0.85532093048095703, 0.518098533153533935, 120, 255, 1, 49801), -- Firewood (Area: Lion's Pride Inn - Difficulty: 0) CreateObject1
(@OGUID+2, 386412, 0, 12, 5637, '0', 19932, 0, -9455.013671875, 23.25694465637207031, 56.91201400756835937, 0.282728582620620727, 0, 0, 0.140893936157226562, 0.990024685859680175, 120, 255, 1, 49801), -- Firewood (Area: Lion's Pride Inn - Difficulty: 0) CreateObject1
(@OGUID+3, 386412, 0, 12, 5637, '0', 19932, 0, -9456.3369140625, 24.34201431274414062, 57.01468276977539062, 3.120019197463989257, 0, 0, 0.999941825866699218, 0.01078648492693901, 120, 255, 1, 49801), -- Firewood (Area: Lion's Pride Inn - Difficulty: 0) CreateObject1
(@OGUID+4, 386412, 0, 12, 5637, '0', 19932, 0, -9469.373046875, -6.9375, 57.34429931640625, 0.018366117030382156, 0, 0, 0.009182929992675781, 0.999957799911499023, 120, 255, 1, 49801), -- Firewood (Area: Lion's Pride Inn - Difficulty: 0) CreateObject1
(@OGUID+5, 386412, 0, 12, 5637, '0', 19932, 0, -9456.111328125, 21.42534828186035156, 56.91201400756835937, 1.437543153762817382, 0, 0, 0.658460617065429687, 0.752615213394165039, 120, 255, 1, 49801); -- Firewood (Area: Lion's Pride Inn - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_template` WHERE `entry`=386412;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(386412, 5, 199, 'Firewood', '', '', '', 1.20000004768371582, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 49801); -- Firewood

-- Phasing
DELETE FROM `phase_name` WHERE `ID` IN (19932, 19933, 19934);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(19932, 'Goldshire Lions Pride Inn Human Heritage Questchain'),
(19933, 'Cosmetic - See Master Mathias Shawn in Lions Pride Basement'),
(19934, 'Cosmetic - See Vanessa VanCleef in Lions Pride Basement');

DELETE FROM `phase_area` WHERE (`AreaId` = 5637 AND `PhaseId` IN (19932, 19933, 19934));
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(5637, 19932, 'Goldshire Lions Pride Inn Human Heritage Questchain'),
(5637, 19933, 'Cosmetic - See Master Mathias Shawn in Lions Pride Basement'),
(5637, 19934, 'Cosmetic - See Vanessa VanCleef in Lions Pride Basement');

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` IN (19932, 19933, 19934) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
-- Phase 19932
(26, 19932, 0, 0, 0, 47, 0, 72405, 2 | 8 | 64, 0, 0, 'Apply Phase 19932 if Quest 75265 is in progress | complete | rewarded'),
-- Phase 19933
(26, 19933, 0, 0, 0, 47, 0, 72405, 2 | 8 | 64, 0, 0, 'Apply Phase 19933 if Quest 75265 is in progress | complete | rewarded'),
-- Phase 19934
(26, 19934, 0, 0, 0, 47, 0, 72405, 2 | 64, 0, 0, 'Apply Phase 19933 if Quest 75265 is complete | rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 30224 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(15, 30224, 0, 0, 0, 9, 0, 72405, 0, 0, 0, 'Show Gossip Option Menu 30224 if Quest 72405 is taken');

-- Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (198883,198896));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(198883, 1, 42347, 0, 0, 0, 0, 0, 0, 0, 0, 49801), -- Vanessa VanCleef
(198896, 1, 47104, 0, 0, 47104, 0, 0, 0, 0, 0, 49801); -- Master Mathias Shaw

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=198883 AND `MenuID`=30837) OR (`CreatureID`=198896 AND `MenuID`=30224);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(198883, 30837, 49801), -- Vanessa VanCleef
(198896, 30224, 49801); -- Master Mathias Shaw

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 236791, 0, 0, 0, 0, 0, 0, 0, 49801), -- 198883 (Vanessa VanCleef)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 233054, 0, 0, 0, 0, 0, 0, 0, 49801); -- 198896 (Master Mathias Shaw)

DELETE FROM `gossip_menu` WHERE (`MenuID`=30837 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=30224 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(30837, @NPCTEXTID+0, 49801), -- 198883 (Vanessa VanCleef)
(30224, @NPCTEXTID+1, 49801); -- 198896 (Master Mathias Shaw)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=30224 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`GossipOptionID`, `MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `Flags`, `OverrideIconID`, `GossipNpcOptionID`, `VerifiedBuild`) VALUES
(107712, 30224, 0, 0, '<Tell Shaw to signal his informant.>', 233055, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801);

-- Quest stuff
DELETE FROM `quest_offer_reward` WHERE `ID`=72405;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(72405, 0, 0, 0, 0, 0, 0, 0, 0, 'My few interactions with Vanessa told me she isn\'t interested in the banditry of the old Defias Brotherhood. To her, the Brotherhood meant supporting the downtrodden... those that Stormwind had left behind. \n\nThat, I can respect. \n\nBut most of her Brotherhood continue to engage in thievery from innocent travelers. That\'s not revolution, that\'s highway robbery.\n\nShe insists she tries to stop them.', 49801); -- An Unlikely Informant

DELETE FROM `quest_details` WHERE `ID`=72408;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(72408, 1, 1, 0, 0, 0, 0, 0, 0, 49801); -- A Window to the Past

DELETE FROM `quest_request_items` WHERE `ID`=72405;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(72405, 0, 0, 0, 0, 'We must recover what was stolen from the Keep, at all costs.', 49801); -- An Unlikely Informant

DELETE FROM `creature_queststarter` WHERE (`id`=198896 AND `quest`=72408);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(198896, 72408, 49801); -- A Window to the Past offered Master Mathias Shaw

DELETE FROM `creature_questender` WHERE (`id`=198896 AND `quest`=72405);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(198896, 72405, 49801); -- An Unlikely Informant ended by Master Mathias Shaw

DELETE FROM `quest_template_addon` WHERE `ID` = 72408;
INSERT INTO `quest_template_addon` (`ID`, `prevQuestID`) VALUES
(72408, 72405);

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry`=198896 AND `DifficultyID`=0) OR (`Entry`=198883 AND `DifficultyID`=0);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(198896, 0, 0, 0, 1281, 9, 20, 1, 227309, 0, 0, 49801),
(198883, 0, 0, 0, 1281, 9, 3, 1, 227296, 0, 0, 49801);

-- Creature Model
DELETE FROM `creature_model_info` WHERE `DisplayID`=110980;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(110980, 0.228800013661384582, 1.65000009536743164, 0, 49801);
