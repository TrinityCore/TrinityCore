SET @CGUID := 9004157;
SET @OGUID := 9003903;

SET @NPCTEXTID := 590107;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 202700, 0, 1519, 5397, '0', 21386, 0, 0, 0, -8046.04443359375, 819.17938232421875, 68.32535552978515625, 5.918725967407226562, 120, 0, 0, 90335, 7196, 0, NULL, NULL, NULL, NULL, 53441), -- Lysander Starshade (Area: The Wollerton Stead - Difficulty: 0) CreateObject1
(@CGUID+1, 207353, 0, 1519, 5397, '0', 21386, 0, 0, 0, -8048.08837890625, 813.717041015625, 67.7155609130859375, 3.808499336242675781, 120, 0, 0, 112919, 3155, 0, NULL, NULL, NULL, NULL, 53441); -- Arko'narin Starshade (Area: The Wollerton Stead - Difficulty: 0) CreateObject1

-- Farmer Wollerton is now phased during Nightelf Heritage Questchain
UPDATE `creature` SET `PhaseId` = 21855 WHERE `guid` = 314390;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 405958, 0, 1519, 9171, '0', 21687, 0, -8160.28466796875, 814.25177001953125, 76.64415740966796875, 4.848750114440917968, 0, 0, -0.65729045867919921, 0.753637373447418212, 120, 255, 1, 53441); -- Sealed Kaldorei Scroll (Area: Stormwind Embassy - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `faction`=80, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=207353; -- Arko'narin Starshade
UPDATE `creature_template` SET `faction`=80, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=202700; -- Lysander Starshade

DELETE FROM `gameobject_template` WHERE `entry`=405958;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(405958, 2, 30915, 'Sealed Kaldorei Scroll', '', '', '', 0.85000002384185791, 0, 26598, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53441); -- Sealed Kaldorei Scroll

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN ( 405958 /*Sealed Kaldorei Scroll*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(405958, 0, 4, 0, 0); -- Sealed Kaldorei Scroll

DELETE FROM `creature_template_addon` WHERE `entry` IN (207353, 202700);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(207353, 0, 0, 0, 0, 0, 0, 0, 743, 0, 0, 0, 0, ''), -- Arko'narin Starshade
(202700, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 202700 (Lysander Starshade)

-- Phasing
DELETE FROM `phase_name` WHERE `ID` IN (21687, 21855, 21386);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(21687, 'Cosmetic - See Sealed Kaldorei Scroll in Stormwind Embassy'),
(21855, 'Cosmetic - See Farmer Wollerton at The Wollerton Stead'),
(21386, 'Cosmetic - See Lysander and Arkonarin at The Wollerton Stead');

DELETE FROM `phase_area` WHERE `PhaseId` IN (21687, 21855, 21386);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 21687, 'See Sealed Kaldorei Scroll in Stormwind Embassy'),
(1519, 21855, 'See Farmer Wollerton at The Wollerton Stead'),
(1519, 21386, 'See Lysander and Arkonarin at The Wollerton Stead');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 21687 AND `SourceEntry` = 0) OR (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 21855 AND `SourceEntry` = 0) OR (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 21386 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 21687, 0, 0, 0, 16, 0, 0x8, 0, 0, 0, 'Apply Phase 21687 if Player is Nightelf'),
(26, 21687, 0, 0, 0, 27, 0, 50, 3, 0, 0, 'Apply Phase 21687 if Player is level 50 or higher'),
(26, 21687, 0, 0, 0, 47, 0, 75890, 2|8|64, 0, 1, 'Apply Phase 21687 if Quest 75890 is not in Progress | complete | rewarded'),
(26, 21855, 0, 0, 0, 47, 0, 75890, 2|8, 0, 1, 'Apply Phase 21855 if Quest 75890 is not in Progress | complete'),
(26, 21386, 0, 0, 0, 47, 0, 75890, 2|8|64, 0, 0, 'Apply Phase 12881 if Quest 75890 is in Progress | complete | rewarded');

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (207353,202700));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(207353, 1, 127986, 0, 0, 128321, 0, 0, 0, 0, 0, 53441), -- Arko'narin Starshade
(202700, 1, 94844, 0, 0, 0, 0, 0, 0, 0, 0, 53441); -- Lysander Starshade

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=207353 AND `MenuID` IN (32731,31902)) OR (`CreatureID`=202700 AND `MenuID`=31904);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(202700, 31904, 53441), -- Lysander Starshade
(207353, 31902, 53441); -- Arko'narin Starshade

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+2;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 244311, 0, 0, 0, 0, 0, 0, 0, 53441), -- 207353 (Arko'narin Starshade)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 244330, 0, 0, 0, 0, 0, 0, 0, 53441), -- 202700 (Lysander Starshade)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 249420, 0, 0, 0, 0, 0, 0, 0, 53441); -- 207353 (Arko'narin Starshade)

DELETE FROM `gossip_menu` WHERE (`MenuID`=31902 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=31904 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=32731 AND `TextID`=@NPCTEXTID+2);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(31902, @NPCTEXTID+0, 53441), -- 207353 (Arko'narin Starshade)
(31904, @NPCTEXTID+1, 53441), -- 202700 (Lysander Starshade)
(32731, @NPCTEXTID+2, 53441); -- 207353 (Arko'narin Starshade)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (32731,31902));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(32731, 113956, 0, 0, 'I want to ask about something else.', 149761, 0, 0, 31902, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 53441),
(31902, 113955, 0, 0, 'That sword is an odd weapon for a Warden.', 0, 0, 0, 32731, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 53441);

-- Difficulty & Model
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456 WHERE (`DifficultyID`=0 AND `Entry` IN (133675,112694,88080,88081,88067,133431,162393,130069,129679,126332,133409,133326,112686,133394,133433,133672,133322,112698,143711,133441,133363,133509));
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=53441 WHERE (`DifficultyID`=0 AND `Entry` IN (73636,73637,2442,721));
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `StaticFlags3`=33554432, `VerifiedBuild`=53441 WHERE (`Entry`=207353 AND `DifficultyID`=0); -- Arko'narin Starshade
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53441 WHERE (`Entry`=202700 AND `DifficultyID`=0); -- Lysander Starshade
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53441 WHERE (`Entry`=44807 AND `DifficultyID`=0); -- Farmer Wollerton
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53441 WHERE (`Entry`=88070 AND `DifficultyID`=0); -- Gardener Flin
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168 WHERE (`DifficultyID`=0 AND `Entry` IN (72654,111190));
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306624, `VerifiedBuild`=53441 WHERE (`Entry`=62822 AND `DifficultyID`=0); -- Cousin Slowhands
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306624, `VerifiedBuild`=53441 WHERE (`Entry`=62821 AND `DifficultyID`=0); -- Mystic Birdhat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306624 WHERE (`Entry`=167032 AND `DifficultyID`=0);

-- Quest stuff
DELETE FROM `quest_details` WHERE `ID` IN (75890, 75891);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(75890, 0, 0, 0, 0, 0, 0, 0, 0, 53441), -- The Clarion Call
(75891, 0, 0, 0, 0, 0, 0, 0, 0, 53441); -- Ancient Curses

DELETE FROM `quest_offer_reward` WHERE `ID`=75890;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(75890, 0, 0, 0, 0, 0, 0, 0, 0, 'It is an honor to meet you, $n.', 53441); -- The Clarion Call

DELETE FROM `gameobject_queststarter` WHERE (`id`=405958 AND `quest`=75890);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(405958, 75890, 53441); -- The Clarion Call offered by Sealed Kaldorei Scroll

DELETE FROM `creature_queststarter` WHERE (`id`=207353 AND `quest`=75891);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(207353, 75891, 53441); -- Ancient Curses offered by Arko'narin Starshade

DELETE FROM `creature_questender` WHERE (`id`=207353 AND `quest`=75890);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(207353, 75890, 53441); -- The Clarion Call ended by Arko'narin Starshade

DELETE FROM `quest_template_addon` WHERE `ID` = 75891;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(75891, 0, 0, 0, 75890, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Path for CGUID+0
SET @ENTRY := 202700;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Lysander Starshade - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -8045.847, 819.1042, 68.327, NULL, 0),
(@PATH, 1, -8044.969, 820.5035, 68.45518, NULL, 0),
(@PATH, 2, -8047.37, 822.4566, 68.55392, NULL, 0),
(@PATH, 3, -8050.842, 823.5521, 68.30903, NULL, 0),
(@PATH, 4, -8051.116, 821.8472, 68.30904, NULL, 0),
(@PATH, 5, -8048.503, 820.1007, 68.30903, NULL, 0);

UPDATE `creature` SET `position_x`= -8045.847, `position_y`= 819.1042, `position_z`= 68.327, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+0;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+0, @PATH, 0);
