SET @CGUID := 7002979;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+13;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 128718, 1643, 8721, 9176, '0', 0, 0, 0, 0, -831.232666015625, 1597.9722900390625, 77.48785400390625, 0.633647501468658447, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Duke (Area: Wayward Thicket - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+1, 125457, 1643, 8721, 9176, '0', 0, 0, 0, 1, -831.576416015625, 1598.859375, 77.4791717529296875, 5.095559597015380859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Rebecca Hale (Area: Wayward Thicket - Difficulty: 0) CreateObject1 (Auras: 255727 - Kneel and Heal)
(@CGUID+2, 140575, 1643, 8721, 9176, '0', 0, 0, 0, 0, -1015.810791015625, 1653.87158203125, 122.6260757446289062, 1.009237885475158691, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Atherton (Area: Wayward Thicket - Difficulty: 0) CreateObject1
(@CGUID+3, 140574, 1643, 8721, 9176, '0', 0, 0, 0, 0, -1018.46881103515625, 1660.795166015625, 122.0448684692382812, 5.608292102813720703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Jennings (Area: Wayward Thicket - Difficulty: 0) CreateObject1
(@CGUID+4, 140573, 1643, 8721, 9176, '0', 0, 0, 0, 0, -1017.201416015625, 1650.84375, 122.4096221923828125, 1.346523046493530273, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bybee (Area: Wayward Thicket - Difficulty: 0) CreateObject1
(@CGUID+5, 140461, 1643, 8721, 9176, '0', 0, 0, 0, 0, -1019.2100830078125, 1655.2222900390625, 123.0814590454101562, 0.803664267063140869, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Dilbert McClint (Area: Wayward Thicket - Difficulty: 0) CreateObject1
(@CGUID+6, 139913, 1643, 8721, 9176, '0', 0, 0, 0, 0, -1003.22918701171875, 1750.6302490234375, 124.4599227905273437, 3.24004220962524414, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Captain (Area: Wayward Thicket - Difficulty: 0) CreateObject1
(@CGUID+7, 139912, 1643, 8721, 9176, '0', 0, 0, 0, 1, -1003.23272705078125, 1751.9322509765625, 124.466064453125, 3.242026329040527343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Ranger Wons (Area: Wayward Thicket - Difficulty: 0) CreateObject1
(@CGUID+8, 139926, 1643, 8721, 9176, '0', 0, 0, 0, 1, -1004.37152099609375, 1754.04345703125, 124.26983642578125, 3.744704961776733398, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Thornspeaker Birchgrove (Area: Wayward Thicket - Difficulty: 0) CreateObject1
(@CGUID+9, 139954, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1030.4461669921875, 1754.4444580078125, 118.2610626220703125, 3.01540994644165039, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Thornguard Ironclaw (Area: Gol Koval - Difficulty: 0) CreateObject1
(@CGUID+10, 139956, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1024.542724609375, 1763.8001708984375, 119.3606414794921875, 1.925188422203063964, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Thornguard Shieldpaw (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+11, 139956, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1027.7734375, 1742.642578125, 117.6528778076171875, 3.103324174880981445, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Thornguard Shieldpaw (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+12, 139954, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1094.1241455078125, 1740.4912109375, 109.4664077758789062, 4.571585655212402343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Thornguard Ironclaw (Area: Gol Koval - Difficulty: 0) CreateObject1
(@CGUID+13, 139954, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1022.31768798828125, 1766.357666015625, 119.850921630859375, 2.435044288635253906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568); -- Thornguard Ironclaw (Area: Gol Koval - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+13;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+7, 0, 0, 0, 0, 0, 2, 0, 376, 0, 0, 0, 0, ''), -- Ranger Wons
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, ''); -- Thornspeaker Birchgrove

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (139912 /*139912 (Ranger Wons)*/, 139913 /*139913 (Captain)*/, 125457 /*125457 (Rebecca Hale) - Kneel and Heal*/, 128718 /*128718 (Duke)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(139912, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, ''), -- 139912 (Ranger Wons)
(139913, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 139913 (Captain)
(125457, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '255727'), -- 125457 (Rebecca Hale) - Kneel and Heal
(128718, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 128718 (Duke)

-- Sparring
DELETE FROM `creature_template_sparring` WHERE `Entry` IN (139954,139956);
INSERT INTO `creature_template_sparring` (`Entry`, `NoNPCDamageBelowHealthPct`) VALUES
(139954, 85),
(139956, 85);

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=139912 AND `MenuID`=22747) OR (`CreatureID`=139926 AND `MenuID`=22752) OR (`CreatureID`=140461 AND `MenuID`=22794) OR (`CreatureID`=125457 AND `MenuID`=21728);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(139912, 22747, 60568), -- Ranger Wons
(139926, 22752, 60568), -- Thornspeaker Birchgrove
(140461, 22794, 60568), -- Dilbert McClint
(125457, 21728, 60568); -- Rebecca Hale

-- Quest
DELETE FROM `quest_details` WHERE `ID` IN (48183 /*The Hills Are Alive*/, 48182 /*Total Cairnage*/, 52075 /*Boned*/, 48179 /*Rescue Rangers*/, 52074 /*Deliverance*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(48183, 1, 0, 0, 0, 0, 0, 0, 0, 60568), -- The Hills Are Alive
(48182, 1, 0, 0, 0, 0, 0, 0, 0, 60568), -- Total Cairnage
(52075, 1, 0, 0, 0, 0, 0, 0, 0, 60568), -- Boned
(48179, 1, 0, 0, 0, 0, 0, 0, 0, 60568), -- Rescue Rangers
(52074, 1, 0, 0, 0, 0, 0, 0, 0, 60568); -- Deliverance

DELETE FROM `creature_queststarter` WHERE (`id`=139926 AND `quest` IN (48183,48182)) OR (`id`=139912 AND `quest` IN (52075,48179)) OR (`id`=125457 AND `quest`=52074);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(139926, 48183, 60568), -- The Hills Are Alive offered by Thornspeaker Birchgrove
(139926, 48182, 60568), -- Total Cairnage offered by Thornspeaker Birchgrove
(139912, 52075, 60568), -- Boned offered by Ranger Wons
(139912, 48179, 60568), -- Rescue Rangers offered by Ranger Wons
(125457, 52074, 60568); -- Deliverance offered by Rebecca Hale

DELETE FROM `creature_questender` WHERE (`id`=139912 AND `quest` IN (52075,48179,52074)) OR (`id`=139926 AND `quest` IN (48183,48182));
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(139912, 52075, 60568), -- Boned ended by Ranger Wons
(139912, 48179, 60568), -- Rescue Rangers ended by Ranger Wons
(139926, 48183, 60568), -- The Hills Are Alive ended by Thornspeaker Birchgrove
(139926, 48182, 60568), -- Total Cairnage ended by Thornspeaker Birchgrove
(139912, 52074, 60568); -- Deliverance ended by Ranger Wons

DELETE FROM `quest_template_addon` WHERE `ID` IN (48183,48182,52075,48179);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(48183, 0, 0, 0, 52074, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- The Hills Are Alive offered by Thornspeaker Birchgrove
(48182, 0, 0, 0, 52074, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Total Cairnage offered by Thornspeaker Birchgrove
(52075, 0, 0, 0, 52074, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Boned offered by Ranger Wons
(48179, 0, 0, 0, 52074, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Rescue Rangers offered by Ranger Wons
