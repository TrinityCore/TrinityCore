SET @CGUID := 7002659;
SET @OGUID := 7000558;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 129509, 1643, 8721, 9026, '0', 9033, 0, 0, 0, 225.373260498046875, 1678.2535400390625, 20.83416366577148437, 5.070085048675537109, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Travis Daybreak (Area: Carver's Harbor - Difficulty: 0) CreateObject1 (Auras: 248917 - Cursed, 256598 - Pig Belt)
(@CGUID+1, 129508, 1643, 8721, 9026, '0', 9033, 0, 0, 0, 218.21875, 1680.6666259765625, 21.15810966491699218, 5.167193889617919921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Trevor Hightide (Area: Carver's Harbor - Difficulty: 0) CreateObject1 (Auras: 248917 - Cursed, 256576 - Pig Goggles)
(@CGUID+2, 129511, 1643, 8721, 9026, '0', 9033, 0, 0, 0, 221.8506927490234375, 1678.748291015625, 20.71439361572265625, 4.998590469360351562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Burke Stevenson (Area: Carver's Harbor - Difficulty: 0) CreateObject1 (Auras: 248917 - Cursed, 256574 - Pig Top Hat)
(@CGUID+3, 129510, 1643, 8721, 9026, '0', 9033, 0, 0, 0, 216.4270782470703125, 1676.5191650390625, 19.96473121643066406, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490); -- Kyle Sailford (Area: Carver's Harbor - Difficulty: 0) CreateObject1 (Auras: 248917 - Cursed, 256582 - Pig Dock Hat, 109525 - Sleeping Sleep)

-- GameObject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 277459, 1643, 8721, 9026, '0', 0, 0, 113.0381927490234375, 1669.4097900390625, 3.88733839988708496, 3.071101188659667968, 0.537440776824951171, 0.045001983642578125, -0.84202766418457031, 0.011026943102478981, 120, 255, 1, 60490); -- Pig Effigy (Area: Carver's Harbor - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (129510 /*129510 (Kyle Sailford) - Cursed, Pig Dock Hat, Sleeping Sleep*/, 129511 /*129511 (Burke Stevenson) - Cursed, Pig Top Hat*/, 129508 /*129508 (Trevor Hightide) - Cursed, Pig Goggles*/, 129509 /*129509 (Travis Daybreak) - Cursed, Pig Belt*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(129510, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, '248917 256582 109525'), -- 129510 (Kyle Sailford) - Cursed, Pig Dock Hat, Sleeping Sleep
(129511, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '248917 256574'), -- 129511 (Burke Stevenson) - Cursed, Pig Top Hat
(129508, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '248917 256576'), -- 129508 (Trevor Hightide) - Cursed, Pig Goggles
(129509, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '248917 256598'); -- 129509 (Travis Daybreak) - Cursed, Pig Belt

DELETE FROM `gameobject_template_addon` WHERE `entry` = 277459;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(277459, 0, 0x4, 0, 0); -- Pig Effigy

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry` IN (129510,129511,124921,129508,129509) AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000100, `VerifiedBuild`=60490 WHERE (`Entry`=129510 AND `DifficultyID`=0); -- 129510 (Kyle Sailford) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60490 WHERE (`Entry`=129511 AND `DifficultyID`=0); -- 129511 (Burke Stevenson) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60490 WHERE (`Entry`=129508 AND `DifficultyID`=0); -- 129508 (Trevor Hightide) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60490 WHERE (`Entry`=129509 AND `DifficultyID`=0); -- 129509 (Travis Daybreak) - CanSwim

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 9033;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(9033, 'Cosmetic - See freed Trevor, Travis, Kyle and Burke');

DELETE FROM `phase_area` WHERE `PhaseId` = 9033;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(8721, 9033, 'See freed Trevor, Travis, Kyle and Burke');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 9033 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 9033, 0, 0, 0, 47, 0, 47946, 2|64, 0, 0, 'Apply Phase 9115 if Quest 47946 is complete | rewarded');

-- Quest
DELETE FROM `quest_details` WHERE `ID`=47949;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(47949, 1, 0, 0, 0, 0, 0, 0, 0, 60490); -- That's Not My Fetish

DELETE FROM `creature_questender` WHERE (`id`=124786 AND `quest`=47949);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(124786, 47949, 60490); -- That's Not My Fetish ended by Thomas Staughton

DELETE FROM `gameobject_queststarter` WHERE (`id`=277459 AND `quest`=47949);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(277459, 47949, 60490); -- That's Not My Fetish offered by Pig Effigy

DELETE FROM `quest_template_addon` WHERE `ID` = 47949;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(47949, 0, 0, 0, 47946, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- That's Not My Fetish

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` IN (291211,294652,294651,294650);
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(291211, NULL, NULL, NULL, 1, 0),
(294652, NULL, NULL, NULL, 1, 0),
(294651, NULL, NULL, NULL, 1, 0),
(294650, NULL, NULL, NULL, 1, 0);
