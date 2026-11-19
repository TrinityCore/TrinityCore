SET @CGUID := 6000000;
SET @OGUID := 6000000;
SET @EVENT := 8;

-- Areatrigger templates
DELETE FROM `areatrigger_template` WHERE (`IsServerSide`=0 AND `Id`=13260);
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) VALUES
(13260, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 48069);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=9242;
INSERT INTO `areatrigger_create_properties` (`Id`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(9242, 13260, 0, 0, 0, 0, -1, 0, 60, 0, 10000, 0, 3, 3, 0, 0, 0, 0, 0, 0, 48069); -- SpellId : 231879

-- Creature templates
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=116285; -- Test Subject
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114279; -- Exploited Crown Intern
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114278; -- Crown Supply Guard
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114275; -- Crown Technician
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=38035; -- Chemical Wagon

DELETE FROM `creature_template_addon` WHERE `entry` IN (116285, 114279, 114278, 114275, 38035);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(116285, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '231867'), -- 116285 (Test Subject)
(114279, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 114279 (Exploited Crown Intern)
(114278, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 114278 (Crown Supply Guard)
(114275, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '71856'), -- 114275 (Crown Technician) - Plaguethrower Backpack
(38035, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 38035 (Chemical Wagon)

DELETE FROM `creature_template_movement` WHERE `CreatureId`=38035;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(38035, 0, 0, 1, 0, 0, 0, NULL);

-- Equipments
UPDATE `creature_equip_template` SET `VerifiedBuild`=48069 WHERE (`ID`=1 AND `CreatureID` IN (114278,114275));

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=48069 WHERE `DisplayID` IN (100511, 93574, 71887, 27323, 73165, 73164, 30709, 30577, 30578, 30579, 42334, 10612, 32814, 32813, 23884);

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (116285,114279,114278,114275,38035));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(116285, 0, 0, 0, 378, 48069),
(114279, 0, 0, 0, 378, 48069),
(114278, 0, 0, 0, 378, 48069),
(114275, 0, 0, 0, 378, 48069),
(38035, 0, 0, 0, 378, 48069);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=48069 WHERE (`DifficultyID`=0 AND `Entry` IN (169421,158637,144961,61890,46058,46054,45896,45198));

-- Gameobject templates
DELETE FROM `gameobject_template` WHERE `entry` IN (259803 /*Recipe Fragment*/, 259806 /*Love Potion Recipe*/, 259461 /*Crown Chemical Co. Supplies*/, 247561 /*Table Large 01*/, 259459 /*Tools*/, 259804 /*Recipe Fragment*/, 259764 /*Love Potion No. 8*/, 259805 /*Recipe Fragment*/, 244432 /*Memorial Flowers*/, 259523 /*Crown Crate (Large)*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(259803, 10, 15781, 'Recipe Fragment', '', '', '', 1, 43, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 294, 48069), -- Recipe Fragment
(259806, 2, 9196, 'Love Potion Recipe', 'quest', '', '', 1, 0, 20586, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 378, 48069), -- Love Potion Recipe
(259461, 3, 6656, 'Crown Chemical Co. Supplies', '', '', '', 0.800000011920928955, 1691, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27766, 0, 0, 0, 0, 378, 48069), -- Crown Chemical Co. Supplies
(247561, 5, 31545, 'Table Large 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 48069), -- Table Large 01
(259459, 5, 38135, 'Tools', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48069), -- Tools
(259804, 10, 19417, 'Recipe Fragment', '', '', '', 1, 43, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 294, 48069), -- Recipe Fragment
(259764, 3, 38182, 'Love Potion No. 8', '', 'Taking', '', 1.299999952316284179, 1690, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 96454, 0, 0, 45033, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 69777, 0, 0, 0, 0, 378, 48069), -- Love Potion No. 8
(259805, 10, 19417, 'Recipe Fragment', '', '', '', 1, 43, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 294, 48069), -- Recipe Fragment
(244432, 5, 7814, 'Memorial Flowers', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 885, 48069), -- Memorial Flowers
(259523, 5, 9215, 'Crown Crate (Large)', '', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48069); -- Crown Crate (Large)

UPDATE `gameobject_template` SET `size`=0.800000011920928955, `Data6`=0, `VerifiedBuild`=48069 WHERE `entry`=201751; -- Crown Crate
UPDATE `gameobject_template` SET `ContentTuningId`=378, `VerifiedBuild`=48069 WHERE `entry`=201716; -- Chemical Wagon
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=48069 WHERE `entry`=206770; -- Standing, Large - Val (Scale 2)

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (259806 /*Love Potion Recipe*/, 259805 /*Recipe Fragment*/, 259804 /*Recipe Fragment*/, 259803 /*Recipe Fragment*/, 259764 /*Love Potion No. 8*/, 259523 /*Crown Crate (Large)*/, 259461 /*Crown Chemical Co. Supplies*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(259806, 0, 4, 0, 0), -- Love Potion Recipe
(259805, 0, 262144, 0, 0), -- Recipe Fragment
(259804, 0, 262144, 0, 0), -- Recipe Fragment
(259803, 0, 262144, 0, 0), -- Recipe Fragment
(259764, 0, 0, 2100, 0), -- Love Potion No. 8
(259523, 114, 0, 0, 0), -- Crown Crate (Large)
(259461, 0, 4, 0, 0); -- Crown Chemical Co. Supplies

UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=206770; -- Standing, Large - Val (Scale 2)
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=201751; -- Crown Crate

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=259461 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(259461, 0, 49867, 48069); -- Crown Chemical Co. Supplies

DELETE FROM `gameobject_loot_template` WHERE `Entry`=69777;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(69777, 141624, 0, 100, 0, 1, 0, 1, 1, 'Love Potion No. 8 - Love Potion No. 8');

-- Quests
UPDATE `quest_template` SET `Expansion`=9, `VerifiedBuild`=48069 WHERE `ID` IN (44559, 44560); -- Follow the Recipe

DELETE FROM `quest_template_addon`WHERE `ID` IN (44559, 44560);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(44559, 0, 0, 0, 24576, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, ''),
(44560, 0, 0, 0, 24657, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, '');

UPDATE `quest_poi` SET `VerifiedBuild`=48069 WHERE (`QuestID`=44559 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=44559 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=44559 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=44559 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=44559 AND `BlobIndex`=0 AND `Idx1`=0);

UPDATE `quest_poi_points` SET `VerifiedBuild`=48069 WHERE (`QuestID`=44559 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=44559 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=44559 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=44559 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=44559 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID` IN (44559, 44560);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(44559, 0, 0, 0, 0, 0, 0, 0, 0, 48069), -- Follow the Recipe
(44560, 0, 0, 0, 0, 0, 0, 0, 0, 48069); -- Follow the Recipe

DELETE FROM `gameobject_queststarter` WHERE (`id`=259806 AND `quest` IN (44559, 44560));
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(259806, 44559, 48069), -- Follow the Recipe offered by Love Potion Recipe
(259806, 44560, 48069); -- Follow the Recipe offered by Love Potion Recipe

DELETE FROM `creature_questender` WHERE (`id`=37172 AND `quest`=44559) OR (`id`=38066 AND `quest`=44560);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(37172, 44559, 48069), -- Follow the Recipe ended by Detective Snap Snagglebolt
(38066, 44560, 48069); -- Follow the Recipe ended by Inspector Snip Snagglebolt

-- Misc
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=227412;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 227412, 0, 0, 31, 1, 3, 114275, 0, 0, 13, 0, '', 'Spell Love Potion No. 8 targets Crown Technician'),
(17, 0, 227412, 0, 1, 31, 1, 3, 114278, 0, 0, 13, 0, '', 'Spell Love Potion No. 8 targets Crown Supply Guard'),
(17, 0, 227412, 0, 2, 31, 1, 3, 114279, 0, 0, 13, 0, '', 'Spell Love Potion No. 8 targets Exploited Crown Intern'),
(17, 0, 227412, 0, 3, 31, 1, 3, 116285, 0, 0, 13, 0, '', 'Spell Love Potion No. 8 targets Test Subject');

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+53;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 38035, 0, 130, 236, '0', 0, 0, 0, 0, -292.638885498046875, 1638.732666015625, 18.816131591796875, 1.530821204185485839, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Chemical Wagon (Area: Shadowfang Keep - Difficulty: 0)
(@CGUID+1, 38035, 0, 130, 204, '0', 0, 0, 0, 0, -396.68402099609375, 1646.6007080078125, 18.74117851257324218, 3.32196211814880371, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Chemical Wagon (Area: Pyrewood Village - Difficulty: 0)
(@CGUID+2, 38035, 0, 130, 204, '0', 0, 0, 0, 0, -394.953125, 1536.5382080078125, 18.74117851257324218, 4.001675605773925781, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Chemical Wagon (Area: Pyrewood Village - Difficulty: 0) (Auras: 227464 - Cosmetic - Fire (with Sound))
(@CGUID+3, 114275, 0, 130, 204, '0', 0, 0, 0, 1, -390.96875, 1606.2257080078125, 18.74117851257324218, 2.199768543243408203, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Crown Technician (Area: Pyrewood Village - Difficulty: 0) (Auras: 71856 - Plaguethrower Backpack)
(@CGUID+4, 114275, 0, 130, 204, '0', 0, 0, 0, 1, -381.982635498046875, 1452.8367919921875, 25.76718521118164062, 4.522929668426513671, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Crown Technician (Area: Pyrewood Village - Difficulty: 0) (Auras: 71856 - Plaguethrower Backpack)
(@CGUID+5, 114275, 0, 130, 204, '0', 0, 0, 0, 1, -366.305572509765625, 1544.138916015625, 24.1021270751953125, 3.237104654312133789, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Crown Technician (Area: Pyrewood Village - Difficulty: 0) (Auras: 71856 - Plaguethrower Backpack)
(@CGUID+6, 114275, 0, 130, 204, '0', 0, 0, 0, 1, -354.3125, 1490.7396240234375, 18.9093475341796875, 0.005104747135192155, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Crown Technician (Area: Pyrewood Village - Difficulty: 0) (Auras: 71856 - Plaguethrower Backpack)
(@CGUID+7, 114275, 0, 130, 204, '0', 0, 0, 0, 1, -323.05035400390625, 1607.46875, 18.94118881225585937, 2.818253755569458007, 120, 10, 0, 112919, 0, 1, 0, 0, 0, 48069), -- Crown Technician (Area: Pyrewood Village - Difficulty: 0)
(@CGUID+8, 114275, 0, 130, 204, '0', 0, 0, 0, 1, -306.28125, 1619.967041015625, 18.49070930480957031, 4.95096445083618164, 120, 10, 0, 112919, 0, 1, 0, 0, 0, 48069), -- Crown Technician (Area: Pyrewood Village - Difficulty: 0) (Auras: 71856 - Plaguethrower Backpack)
(@CGUID+9, 114275, 0, 130, 5477, '0', 0, 0, 0, 1, -319.59722900390625, 1631.951416015625, 20.07411766052246093, 5.31919097900390625, 120, 10, 0, 112919, 0, 1, 0, 0, 0, 48069), -- Crown Technician (Area: Pyrewood Inn - Difficulty: 0) (Auras: 71856 - Plaguethrower Backpack) (possible waypoints or random movement)
(@CGUID+10, 114275, 0, 130, 204, '0', 0, 0, 0, 1, -335.895843505859375, 1639.3021240234375, 18.49936294555664062, 2.50869607925415039, 120, 10, 0, 112919, 0, 1, 0, 0, 0, 48069), -- Crown Technician (Area: Pyrewood Village - Difficulty: 0) (Auras: 71856 - Plaguethrower Backpack) (possible waypoints or random movement)
(@CGUID+11, 114275, 0, 130, 204, '0', 0, 0, 0, 1, -293, 1663.4461669921875, 18.9598541259765625, 0, 120, 10, 0, 112919, 0, 1, 0, 0, 0, 48069), -- Crown Technician (Area: Pyrewood Village - Difficulty: 0) (Auras: 71856 - Plaguethrower Backpack) (possible waypoints or random movement)
(@CGUID+12, 114275, 0, 130, 204, '0', 0, 0, 0, 1, -317.0850830078125, 1652.59375, 18.87410545349121093, 3.490433454513549804, 120, 10, 0, 112919, 0, 1, 0, 0, 0, 48069), -- Crown Technician (Area: Pyrewood Village - Difficulty: 0) (Auras: 71856 - Plaguethrower Backpack) (possible waypoints or random movement)
(@CGUID+13, 114275, 0, 130, 204, '0', 0, 0, 0, 1, -353.239593505859375, 1660.513916015625, 18.9004974365234375, 2.287267446517944335, 120, 10, 0, 112919, 0, 1, 0, 0, 0, 48069), -- Crown Technician (Area: Pyrewood Village - Difficulty: 0) (Auras: 71856 - Plaguethrower Backpack) (possible waypoints or random movement)
(@CGUID+14, 114278, 0, 130, 204, '0', 0, 0, 0, 1, -393.338531494140625, 1640.6632080078125, 18.74117851257324218, 4.041388511657714843, 120, 0, 0, 169379, 0, 0, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Pyrewood Village - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+15, 114278, 0, 130, 204, '0', 0, 0, 0, 1, -397.123260498046875, 1639.71533203125, 18.74117851257324218, 0.45136958360671997, 120, 0, 0, 169379, 0, 0, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Pyrewood Village - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+16, 114278, 0, 130, 236, '0', 0, 0, 0, 1, -298.87847900390625, 1634.9583740234375, 18.88715362548828125, 5.964731693267822265, 120, 0, 0, 169379, 0, 0, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Shadowfang Keep - Difficulty: 0) (Auras: )
(@CGUID+17, 114278, 0, 130, 236, '0', 0, 0, 0, 1, -296.68402099609375, 1631.7413330078125, 18.59673690795898437, 2.374712467193603515, 120, 0, 0, 169379, 0, 0, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Shadowfang Keep - Difficulty: 0) (Auras: )
(@CGUID+18, 114278, 0, 130, 5478, '0', 0, 0, 0, 1, -440.204864501953125, 1567.0052490234375, 20.154571533203125, 0.44505736231803894, 120, 0, 0, 169379, 0, 0, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Pyrewood Town Hall - Difficulty: 0)
(@CGUID+19, 114278, 0, 130, 5478, '0', 0, 0, 0, 1, -356.789947509765625, 1525.267333984375, 25.53247261047363281, 0.889120817184448242, 120, 0, 0, 169379, 0, 0, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Pyrewood Town Hall - Difficulty: 0)
(@CGUID+20, 114278, 0, 130, 204, '0', 0, 0, 0, 1, -439.888885498046875, 1517.314208984375, 19.99297142028808593, 0.44505736231803894, 120, 0, 0, 169379, 0, 0, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Pyrewood Village - Difficulty: 0)
(@CGUID+21, 114278, 0, 130, 204, '0', 0, 0, 0, 1, -388.28472900390625, 1532.7291259765625, 18.74117851257324218, 4.740899562835693359, 120, 0, 0, 169379, 0, 0, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Pyrewood Village - Difficulty: 0) (Auras: )
(@CGUID+22, 114278, 0, 130, 5476, '0', 0, 0, 0, 1, -390.1319580078125, 1529.71533203125, 18.74117851257324218, 1.150880813598632812, 120, 0, 0, 169379, 0, 0, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Pyrewood Chapel - Difficulty: 0)
(@CGUID+23, 114278, 0, 130, 204, '0', 0, 0, 0, 1, -438.854156494140625, 1496.5728759765625, 18.7411651611328125, 2.125786781311035156, 120, 0, 0, 169379, 0, 0, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Pyrewood Village - Difficulty: 0)
(@CGUID+24, 114278, 0, 130, 5476, '0', 0, 0, 0, 1, -440.19097900390625, 1500.23095703125, 18.7411651611328125, 5.7158050537109375, 120, 0, 0, 169379, 0, 0, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Pyrewood Chapel - Difficulty: 0)
(@CGUID+25, 114278, 0, 130, 204, '0', 0, 0, 0, 1, -358.633697509765625, 1503.8524169921875, 18.741180419921875, 3.851434230804443359, 120, 0, 0, 169379, 0, 0, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Pyrewood Village - Difficulty: 0)
(@CGUID+26, 114278, 0, 130, 5476, '0', 0, 0, 0, 1, -332.532989501953125, 1540.8160400390625, 26.21770095825195312, 1.131183028221130371, 120, 0, 0, 169379, 0, 0, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Pyrewood Chapel - Difficulty: 0)
(@CGUID+27, 114278, 0, 130, 5476, '0', 0, 0, 0, 1, -330.633697509765625, 1543.798583984375, 26.2138671875, 4.721203327178955078, 120, 0, 0, 169379, 0, 0, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Pyrewood Chapel - Difficulty: 0)
(@CGUID+28, 114278, 0, 130, 5476, '0', 0, 0, 0, 1, -417.743072509765625, 1543.5572509765625, 18.7411651611328125, 4.46129608154296875, 120, 0, 0, 169379, 0, 0, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Pyrewood Chapel - Difficulty: 0)
(@CGUID+29, 114278, 0, 130, 5476, '0', 0, 0, 0, 1, -417.310760498046875, 1548.560791015625, 18.74213218688964843, 2.813216447830200195, 120, 0, 0, 169379, 0, 0, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Pyrewood Chapel - Difficulty: 0)
(@CGUID+30, 114278, 0, 130, 204, '0', 0, 0, 0, 1, -352.432281494140625, 1548.657958984375, 24.2135467529296875, 3.222635507583618164, 120, 0, 0, 169379, 0, 2, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Pyrewood Village - Difficulty: 0) (Auras: 227358 - Carrying A Box) (possible waypoints or random movement)
(@CGUID+31, 114278, 0, 130, 204, '0', 0, 0, 0, 1, -369.80035400390625, 1635.0521240234375, 18.74117851257324218, 6.030056476593017578, 120, 0, 0, 169379, 0, 2, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Pyrewood Village - Difficulty: 0) (Auras: 227358 - Carrying A Box) (possible waypoints or random movement)
(@CGUID+32, 114278, 0, 130, 204, '0', 0, 0, 0, 1, -443.638885498046875, 1532.9166259765625, 18.7411651611328125, 0.387833863496780395, 120, 0, 0, 169379, 0, 2, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Pyrewood Village - Difficulty: 0) (Auras: 227358 - Carrying A Box) (possible waypoints or random movement)
(@CGUID+33, 114278, 0, 130, 204, '0', 0, 0, 0, 1, -380.164947509765625, 1444.6961669921875, 25.76718521118164062, 5.972138881683349609, 120, 0, 0, 169379, 0, 2, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Pyrewood Village - Difficulty: 0) (Auras: 227358 - Carrying A Box) (possible waypoints or random movement)
(@CGUID+34, 114279, 0, 130, 236, '0', 0, 0, 0, 0, -332.767364501953125, 1563.0504150390625, 26.22071266174316406, 2.301711082458496093, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Exploited Crown Intern (Area: Shadowfang Keep - Difficulty: 0) (Auras: )
(@CGUID+35, 114279, 0, 130, 204, '0', 0, 0, 0, 0, -334.723968505859375, 1563.1805419921875, 26.21933555603027343, 1.566106438636779785, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Exploited Crown Intern (Area: Pyrewood Village - Difficulty: 0) (Auras: )
(@CGUID+36, 114279, 0, 130, 5476, '0', 0, 0, 0, 0, -323.399322509765625, 1465.3853759765625, 32.36318588256835937, 5.880589962005615234, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Exploited Crown Intern (Area: Pyrewood Chapel - Difficulty: 0)
(@CGUID+37, 114279, 0, 130, 236, '0', 0, 0, 0, 0, -352.404510498046875, 1586.5816650390625, 19.96207618713378906, 5.138869762420654296, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Exploited Crown Intern (Area: Shadowfang Keep - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+38, 114279, 0, 130, 236, '0', 0, 0, 0, 0, -351.776031494140625, 1584.564208984375, 19.96207618713378906, 2.421776294708251953, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Exploited Crown Intern (Area: Shadowfang Keep - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+39, 114279, 0, 130, 204, '0', 0, 0, 0, 0, -367.96527099609375, 1607.8836669921875, 18.74117851257324218, 3.730381488800048828, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Exploited Crown Intern (Area: Pyrewood Village - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+40, 114279, 0, 130, 204, '0', 0, 0, 0, 0, -373.973968505859375, 1633.407958984375, 18.74117851257324218, 4.989530086517333984, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Exploited Crown Intern (Area: Pyrewood Village - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+41, 114279, 0, 130, 204, '0', 0, 0, 0, 0, -400.767364501953125, 1593.3125, 18.74117851257324218, 3.15964365005493164, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Exploited Crown Intern (Area: Pyrewood Village - Difficulty: 0) (Auras: )
(@CGUID+42, 114279, 0, 130, 5478, '0', 0, 0, 0, 0, -438.3819580078125, 1571.9427490234375, 20.154571533203125, 2.704391002655029296, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Exploited Crown Intern (Area: Pyrewood Town Hall - Difficulty: 0)
(@CGUID+43, 114279, 0, 130, 204, '0', 0, 0, 0, 0, -355.109375, 1525.5225830078125, 25.53247261047363281, 3.730381250381469726, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Exploited Crown Intern (Area: Pyrewood Village - Difficulty: 0)
(@CGUID+44, 114279, 0, 130, 204, '0', 0, 0, 0, 0, -437.32464599609375, 1513.7847900390625, 19.99297142028808593, 4.883222103118896484, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Exploited Crown Intern (Area: Pyrewood Village - Difficulty: 0)
(@CGUID+45, 114279, 0, 130, 5476, '0', 0, 0, 0, 0, -384.026031494140625, 1447.84375, 25.76718521118164062, 4.067164897918701171, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Exploited Crown Intern (Area: Pyrewood Chapel - Difficulty: 0)
(@CGUID+46, 114279, 0, 130, 204, '0', 0, 0, 0, 0, -370.076385498046875, 1607.814208984375, 18.74117851257324218, 0.164288803935050964, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Exploited Crown Intern (Area: Pyrewood Village - Difficulty: 0)
(@CGUID+47, 114279, 0, 130, 204, '0', 0, 0, 0, 0, -410.927093505859375, 1498.576416015625, 20.201690673828125, 5.299429893493652343, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Exploited Crown Intern (Area: Pyrewood Village - Difficulty: 0)
(@CGUID+48, 114279, 0, 130, 204, '0', 0, 0, 0, 0, -348.942718505859375, 1551.0572509765625, 24.27005767822265625, 6.122711658477783203, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Exploited Crown Intern (Area: Pyrewood Village - Difficulty: 0) (Auras: )
(@CGUID+49, 114279, 0, 130, 5476, '0', 0, 0, 0, 0, -446.401031494140625, 1531.9896240234375, 18.7411651611328125, 4.989530086517333984, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Exploited Crown Intern (Area: Pyrewood Chapel - Difficulty: 0)
(@CGUID+50, 114279, 0, 130, 5476, '0', 0, 0, 0, 0, -390.046875, 1496.4757080078125, 29.16997718811035156, 4.829231739044189453, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Exploited Crown Intern (Area: Pyrewood Chapel - Difficulty: 0)
(@CGUID+51, 116285, 0, 130, 5476, '0', 0, 0, 0, 0, -354.34375, 1429.26220703125, 27.0664825439453125, 1.915451407432556152, 120, 0, 0, 338757, 0, 2, 0, 0, 0, 48069), -- Test Subject (Area: Pyrewood Chapel - Difficulty: 0) (Auras: 231867 - Unpleasant Seepage) (possible waypoints or random movement)
(@CGUID+52, 116285, 0, 130, 204, '0', 0, 0, 0, 0, -411.505218505859375, 1525.4375, 18.7411651611328125, 2.365073919296264648, 120, 0, 0, 338757, 0, 2, 0, 0, 0, 48069), -- Test Subject (Area: Pyrewood Village - Difficulty: 0) (Auras: 231867 - Unpleasant Seepage) (possible waypoints or random movement)
(@CGUID+53, 116285, 0, 130, 204, '0', 0, 0, 0, 0, -372.828125, 1576.875, 18.862213134765625, 3.452315807342529296, 120, 0, 0, 338757, 0, 2, 0, 0, 0, 48069); -- Test Subject (Area: Pyrewood Village - Difficulty: 0) (Auras: )

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+14, @CGUID+15, @CGUID+30, @CGUID+31, @CGUID+32, @CGUID+33, @CGUID+34, @CGUID+35, @CGUID+36, @CGUID+40, @CGUID+41, @CGUID+42, @CGUID+44, @CGUID+45, @CGUID+47, @CGUID+48, @CGUID+49, @CGUID+51, @CGUID+52, @CGUID+53);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 378, 0, 0, 0, 0, ''), -- 114278 (Crown Supply Guard)
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 378, 0, 0, 0, 0, ''), -- 114278 (Crown Supply Guard)
(@CGUID+30, (@CGUID+30)*10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '227358'), -- 114278 (Crown Supply Guard) - 227358 - Carrying A Box
(@CGUID+31, (@CGUID+31)*10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '227358'), -- 114278 (Crown Supply Guard) - 227358 - Carrying A Box
(@CGUID+32, (@CGUID+32)*10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '227358'), -- 114278 (Crown Supply Guard) - 227358 - Carrying A Box
(@CGUID+33, (@CGUID+33)*10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '227358'), -- 114278 (Crown Supply Guard) - 227358 - Carrying A Box
(@CGUID+34, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 114279 (Exploited Crown Intern)
(@CGUID+35, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 114279 (Exploited Crown Intern)
(@CGUID+36, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 114279 (Exploited Crown Intern)
(@CGUID+40, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- 114279 (Exploited Crown Intern)
(@CGUID+41, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- 114279 (Exploited Crown Intern)
(@CGUID+42, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- 114279 (Exploited Crown Intern)
(@CGUID+44, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- 114279 (Exploited Crown Intern)
(@CGUID+45, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- 114279 (Exploited Crown Intern)
(@CGUID+47, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- 114279 (Exploited Crown Intern)
(@CGUID+48, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- 114279 (Exploited Crown Intern)
(@CGUID+49, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- 114279 (Exploited Crown Intern)
(@CGUID+51, (@CGUID+51)*10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '231867'), -- 116285 (Test Subject)
(@CGUID+52, (@CGUID+52)*10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '231867'), -- 116285 (Test Subject)
(@CGUID+53, (@CGUID+53)*10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '231867'); -- 116285 (Test Subject)

DELETE FROM `waypoint_data` WHERE `id` IN ((@CGUID+30)*10, (@CGUID+31)*10, (@CGUID+32)*10, (@CGUID+33)*10, (@CGUID+51)*10, (@CGUID+52)*10, (@CGUID+53)*10);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
((@CGUID+30)*10, 0, -357.1771, 1548.2726, 24.025185, NULL, 0, 0),
((@CGUID+30)*10, 1, -360.8559, 1548.9548, 23.83805, NULL, 0, 0),
((@CGUID+30)*10, 2, -365.23785, 1556.0642, 22.444618, NULL, 0, 0),
((@CGUID+30)*10, 3, -368.65625, 1566.3611, 19.429817, NULL, 0, 0),
((@CGUID+30)*10, 4, -372.875, 1573.0608, 18.782845, NULL, 0, 0),
((@CGUID+30)*10, 5, -380.39236, 1578.2067, 18.782845, NULL, 0, 0),
((@CGUID+30)*10, 6, -386.4861, 1581.7709, 18.782845, NULL, 0, 0),
((@CGUID+30)*10, 7, -392.8125, 1587.1945, 18.782845, NULL, 0, 0),
((@CGUID+30)*10, 8, -400.51562, 1589.9791, 18.727905, NULL, 5000, 0),
((@CGUID+30)*10, 9, -392.8125, 1587.1945, 18.782845, NULL, 0, 0),
((@CGUID+30)*10, 10, -386.4861, 1581.7709, 18.782845, NULL, 0, 0),
((@CGUID+30)*10, 11, -380.39236, 1578.2067, 18.782845, NULL, 0, 0),
((@CGUID+30)*10, 12, -372.875, 1573.0608, 18.782845, NULL, 0, 0),
((@CGUID+30)*10, 13, -368.65625, 1566.3611, 19.429817, NULL, 0, 0),
((@CGUID+30)*10, 14, -365.23785, 1556.0642, 22.444618, NULL, 0, 0),
((@CGUID+30)*10, 15, -360.8559, 1548.9548, 23.83805, NULL, 0, 0),
((@CGUID+30)*10, 16, -357.1771, 1548.2726, 24.025185, NULL, 0, 0),
((@CGUID+30)*10, 17, -351.82812, 1548.6562, 24.216957, NULL, 6000, 0),
((@CGUID+31)*10, 0, -365.34027, 1635.6024, 18.755281, NULL, 0, 0),
((@CGUID+31)*10, 1, -364.20834, 1632.1077, 18.672792, NULL, 0, 0),
((@CGUID+31)*10, 2, -363.8611, 1626.9723, 19.401007, NULL, 0, 0),
((@CGUID+31)*10, 3, -363.93576, 1622.3698, 20.678679, NULL, 0, 0),
((@CGUID+31)*10, 4, -365.87326, 1619.7952, 20.678679, NULL, 0, 0),
((@CGUID+31)*10, 5, -368.76532, 1619.384, 20.67868, NULL, 0, 0),
((@CGUID+31)*10, 6, -371.2639, 1620.625, 20.67868, NULL, 0, 0),
((@CGUID+31)*10, 7, -375.33508, 1622.6858, 20.678679, NULL, 4750, 0),
((@CGUID+31)*10, 8, -371.2639, 1620.625, 20.67868, NULL, 0, 0),
((@CGUID+31)*10, 9, -368.80383, 1619.3785, 20.67868, NULL, 0, 0),
((@CGUID+31)*10, 10, -365.87326, 1619.7952, 20.678679, NULL, 0, 0),
((@CGUID+31)*10, 11, -363.93576, 1622.3698, 20.678679, NULL, 0, 0),
((@CGUID+31)*10, 12, -363.8611, 1626.9723, 19.401007, NULL, 0, 0),
((@CGUID+31)*10, 13, -364.20834, 1632.1077, 18.672792, NULL, 0, 0),
((@CGUID+31)*10, 14, -365.34027, 1635.6024, 18.755281, NULL, 0, 0),
((@CGUID+31)*10, 15, -369.0486, 1634.8577, 18.737192, NULL, 0, 0),
((@CGUID+31)*10, 16, -370.46182, 1633.6024, 18.737192, NULL, 5000, 0),
((@CGUID+32)*10, 0, -438.86633, 1534.8663, 18.736483, NULL, 0, 0),
((@CGUID+32)*10, 1, -434.8611, 1535.3021, 18.736483, NULL, 0, 0),
((@CGUID+32)*10, 2, -429.25174, 1533.1163, 18.782831, NULL, 0, 0),
((@CGUID+32)*10, 3, -419.12848, 1524.9791, 18.782831, NULL, 0, 0),
((@CGUID+32)*10, 4, -410.46353, 1519.6389, 18.782831, NULL, 0, 0),
((@CGUID+32)*10, 5, -403.71875, 1516.8923, 18.782831, NULL, 0, 0),
((@CGUID+32)*10, 6, -405.68402, 1512.8351, 19.861908, NULL, 0, 0),
((@CGUID+32)*10, 7, -409.85938, 1507.882, 20.167545, NULL, 0, 0),
((@CGUID+32)*10, 8, -412.58334, 1504.2048, 20.365063, NULL, 4750, 0),
((@CGUID+32)*10, 9, -409.85938, 1507.882, 20.167545, NULL, 0, 0),
((@CGUID+32)*10, 10, -405.68402, 1512.8351, 19.861908, NULL, 0, 0),
((@CGUID+32)*10, 11, -403.71875, 1516.8923, 18.782831, NULL, 0, 0),
((@CGUID+32)*10, 12, -410.46353, 1519.6389, 18.782831, NULL, 0, 0),
((@CGUID+32)*10, 13, -419.12848, 1524.9791, 18.782831, NULL, 0, 0),
((@CGUID+32)*10, 14, -429.25174, 1533.1163, 18.782831, NULL, 0, 0),
((@CGUID+32)*10, 15, -434.8611, 1535.3021, 18.736483, NULL, 0, 0),
((@CGUID+32)*10, 16, -438.86633, 1534.8663, 18.736483, NULL, 0, 0),
((@CGUID+32)*10, 17, -442.9375, 1532.224, 18.674479, NULL, 4500, 0),
((@CGUID+33)*10, 0, -375.3212, 1440.3368, 25.736944, NULL, 0, 0),
((@CGUID+33)*10, 1, -377.07986, 1437.6146, 25.736944, NULL, 0, 0),
((@CGUID+33)*10, 2, -380.20312, 1436.3959, 27.573631, NULL, 0, 0),
((@CGUID+33)*10, 3, -382.70834, 1435.2291, 27.078674, NULL, 0, 0),
((@CGUID+33)*10, 4, -387.10764, 1433.1198, 27.078674, NULL, 0, 0),
((@CGUID+33)*10, 5, -389.283, 1431.0435, 27.115345, NULL, 0, 0),
((@CGUID+33)*10, 6, -390.26215, 1427.283, 27.2818, NULL, 0, 0),
((@CGUID+33)*10, 7, -390.76736, 1425.2952, 27.2818, NULL, 4750, 0),
((@CGUID+33)*10, 8, -389.283, 1431.0435, 27.115345, NULL, 0, 0),
((@CGUID+33)*10, 9, -387.10764, 1433.1198, 27.078674, NULL, 0, 0),
((@CGUID+33)*10, 10, -382.70834, 1435.2291, 27.078674, NULL, 0, 0),
((@CGUID+33)*10, 11, -380.22458, 1436.3859, 27.577177, NULL, 0, 0),
((@CGUID+33)*10, 12, -378.05557, 1437.3125, 26.314264, NULL, 0, 0),
((@CGUID+33)*10, 13, -375.51562, 1438.5955, 25.736944, NULL, 0, 0),
((@CGUID+33)*10, 14, -376.79688, 1443.1372, 25.736944, NULL, 0, 0),
((@CGUID+33)*10, 15, -378.93924, 1444.3021, 25.736944, NULL, 0, 0),
((@CGUID+33)*10, 16, -381.59375, 1444.6858, 25.736944, NULL, 4500, 0),
((@CGUID+33)*10, 17, -376.79688, 1443.1372, 25.736944, NULL, 0, 0),
((@CGUID+51)*10, 0, -358.7205, 1441.4254, 25.457922, NULL, 0, 0),
((@CGUID+51)*10, 1, -360.56946, 1454.7882, 23.217321, NULL, 0, 0),
((@CGUID+51)*10, 2, -363.82465, 1472.0348, 20.15039, NULL, 0, 0),
((@CGUID+51)*10, 3, -366.55035, 1485.9392, 18.857056, NULL, 0, 0),
((@CGUID+51)*10, 4, -367.21353, 1500.0521, 18.779945, NULL, 0, 0),
((@CGUID+51)*10, 5, -376.31076, 1511.3577, 18.779945, NULL, 4000, 0),
((@CGUID+51)*10, 6, -367.21353, 1500.0521, 18.779945, NULL, 0, 0),
((@CGUID+51)*10, 7, -366.55035, 1485.9392, 18.857056, NULL, 0, 0),
((@CGUID+51)*10, 8, -363.82465, 1472.0348, 20.15039, NULL, 0, 0),
((@CGUID+51)*10, 9, -360.56946, 1454.7882, 23.217321, NULL, 0, 0),
((@CGUID+51)*10, 10, -358.7205, 1441.4254, 25.457922, NULL, 0, 0),
((@CGUID+51)*10, 11, -354.283, 1429.6562, 26.937635, NULL, 4500, 0),
((@CGUID+52)*10, 0, -422.5486, 1536.2865, 18.75789, NULL, 0, 0),
((@CGUID+52)*10, 1, -427.7882, 1542.974, 18.610674, NULL, 0, 0),
((@CGUID+52)*10, 2, -426.342, 1550.3021, 18.580278, NULL, 0, 0),
((@CGUID+52)*10, 3, -421.31946, 1555.6754, 18.63289, NULL, 0, 0),
((@CGUID+52)*10, 4, -414.2795, 1556.9271, 18.75789, NULL, 0, 0),
((@CGUID+52)*10, 5, -405.24478, 1557.3802, 18.75789, NULL, 0, 0),
((@CGUID+52)*10, 6, -396.80557, 1558.6962, 18.782845, NULL, 0, 0),
((@CGUID+52)*10, 7, -392.12152, 1557.0278, 18.782845, NULL, 0, 0),
((@CGUID+52)*10, 8, -388.06598, 1552.474, 18.782845, NULL, 0, 0),
((@CGUID+52)*10, 9, -385.52777, 1548.1024, 18.782845, NULL, 0, 0),
((@CGUID+52)*10, 10, -384.84723, 1542.0608, 18.782845, NULL, 0, 0),
((@CGUID+52)*10, 11, -384.3507, 1535.481, 18.782845, NULL, 0, 0),
((@CGUID+52)*10, 12, -384.80557, 1530.9653, 18.779945, NULL, 0, 0),
((@CGUID+52)*10, 13, -387.42883, 1527.3351, 18.779945, NULL, 0, 0),
((@CGUID+52)*10, 14, -389.78125, 1524.1493, 18.779945, NULL, 0, 0),
((@CGUID+52)*10, 15, -395.20312, 1524.5938, 18.779945, NULL, 0, 0),
((@CGUID+52)*10, 16, -399.60416, 1525.9757, 18.779945, NULL, 0, 0),
((@CGUID+52)*10, 17, -405.61633, 1527.2291, 18.782831, NULL, 0, 0),
((@CGUID+52)*10, 18, -416.89062, 1529.9618, 18.782831, NULL, 0, 0),
((@CGUID+53)*10, 0, -383.03015, 1573.5989, 18.782845, NULL, 0, 0),
((@CGUID+53)*10, 1, -392.5606, 1578.4963, 18.782845, NULL, 0, 0),
((@CGUID+53)*10, 2, -395.8367, 1588.6984, 18.782845, NULL, 0, 0),
((@CGUID+53)*10, 3, -390.9393, 1598.2288, 18.782845, NULL, 0, 0),
((@CGUID+53)*10, 4, -380.73727, 1601.5049, 18.782845, NULL, 0, 0),
((@CGUID+53)*10, 5, -371.20682, 1596.6075, 18.782845, NULL, 0, 0),
((@CGUID+53)*10, 6, -367.93073, 1586.4055, 18.782845, NULL, 0, 0),
((@CGUID+53)*10, 7, -372.82812, 1576.875, 18.782845, NULL, 0, 0);

DELETE FROM `spawn_group` WHERE `spawnType`=0 AND `spawnId` BETWEEN @CGUID+3 AND @CGUID+53;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(2, 0, @CGUID+3),
(2, 0, @CGUID+4),
(2, 0, @CGUID+5),
(2, 0, @CGUID+6),
(2, 0, @CGUID+7),
(2, 0, @CGUID+8),
(2, 0, @CGUID+9),
(2, 0, @CGUID+10),
(2, 0, @CGUID+11),
(2, 0, @CGUID+12),
(2, 0, @CGUID+13),
(2, 0, @CGUID+14),
(2, 0, @CGUID+15),
(2, 0, @CGUID+16),
(2, 0, @CGUID+17),
(2, 0, @CGUID+18),
(2, 0, @CGUID+19),
(2, 0, @CGUID+20),
(2, 0, @CGUID+21),
(2, 0, @CGUID+22),
(2, 0, @CGUID+23),
(2, 0, @CGUID+24),
(2, 0, @CGUID+25),
(2, 0, @CGUID+26),
(2, 0, @CGUID+27),
(2, 0, @CGUID+28),
(2, 0, @CGUID+29),
(2, 0, @CGUID+30),
(2, 0, @CGUID+31),
(2, 0, @CGUID+32),
(2, 0, @CGUID+33),
(2, 0, @CGUID+34),
(2, 0, @CGUID+35),
(2, 0, @CGUID+36),
(2, 0, @CGUID+37),
(2, 0, @CGUID+38),
(2, 0, @CGUID+39),
(2, 0, @CGUID+40),
(2, 0, @CGUID+41),
(2, 0, @CGUID+42),
(2, 0, @CGUID+43),
(2, 0, @CGUID+44),
(2, 0, @CGUID+45),
(2, 0, @CGUID+46),
(2, 0, @CGUID+47),
(2, 0, @CGUID+48),
(2, 0, @CGUID+49),
(2, 0, @CGUID+50),
(2, 0, @CGUID+51),
(2, 0, @CGUID+52),
(2, 0, @CGUID+53);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+170;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+13, 181017, 0, 130, 204, '0', 0, 0, -362.5069580078125, 1582.2760009765625, 24.97548866271972656, 3.161124467849731445, 0, 0, -0.99995231628417968, 0.009765625, 120, 255, 1, 48069), -- Hanging, Streamer - Val (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+14, 181017, 0, 130, 204, '0', 0, 0, -397.977447509765625, 1604.27783203125, 25.07383918762207031, 5.550122737884521484, 0, 0, -0.35837936401367187, 0.933576047420501708, 120, 255, 1, 48069), -- Hanging, Streamer - Val (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+15, 181017, 0, 130, 5478, '0', 0, 0, -428.2413330078125, 1562.8177490234375, 25.07383918762207031, 5.460340023040771484, 0, 0, -0.39991378784179687, 0.916552722454071044, 120, 255, 1, 48069), -- Hanging, Streamer - Val (Area: Pyrewood Town Hall - Difficulty: 0)
(@OGUID+16, 181017, 0, 130, 5478, '0', 0, 0, -359.55902099609375, 1538.451416015625, 30.43657112121582031, 4.77773284912109375, 0, 0, -0.68363094329833984, 0.729827880859375, 120, 255, 1, 48069), -- Hanging, Streamer - Val (Area: Pyrewood Town Hall - Difficulty: 0)
(@OGUID+17, 181017, 0, 130, 204, '0', 0, 0, -432.338531494140625, 1528.5035400390625, 25.07383918762207031, 0.871590673923492431, 0, 0, 0.422131538391113281, 0.90653461217880249, 120, 255, 1, 48069), -- Hanging, Streamer - Val (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+18, 181017, 0, 130, 5476, '0', 0, 0, -323.383697509765625, 1457.7413330078125, 37.36285018920898437, 4.695339202880859375, 0, 0, -0.71310901641845703, 0.701053142547607421, 120, 255, 1, 48069), -- Hanging, Streamer - Val (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+19, 181020, 0, 130, 204, '0', 0, 0, -374.9375, 1612.79345703125, 20.41874885559082031, 4.660439968109130859, 0, 0, -0.72523307800292968, 0.688503444194793701, 120, 255, 1, 48069), -- Hanging, Square, Medium - Val (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+20, 181020, 0, 130, 204, '0', 0, 0, -388.727447509765625, 1613.1805419921875, 20.41874885559082031, 4.660439968109130859, 0, 0, -0.72523307800292968, 0.688503444194793701, 120, 255, 1, 48069), -- Hanging, Square, Medium - Val (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+21, 181020, 0, 130, 204, '0', 0, 0, -389.822906494140625, 1506.638916015625, 24.70978546142578125, 1.493292689323425292, 0, 0, 0.679181098937988281, 0.7339707612991333, 120, 255, 1, 48069), -- Hanging, Square, Medium - Val (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+22, 181025, 0, 130, 5478, '0', 0, 0, -342.0069580078125, 1543.001708984375, 25.88940048217773437, 3.125251531600952148, 0, 0, 0.999966621398925781, 0.008170507848262786, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Large - Val (Area: Pyrewood Town Hall - Difficulty: 0)
(@OGUID+23, 181060, 0, 130, 204, '0', 0, 0, -373.892364501953125, 1631.40283203125, 19.4093780517578125, 2.301022291183471679, 0.001986503601074218, 0.006320953369140625, 0.912950515747070312, 0.408016473054885864, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+24, 181060, 0, 130, 204, '0', 0, 0, -402.520843505859375, 1594.060791015625, 19.4093780517578125, 0.368683457374572753, 0.006330013275146484, 0.001958847045898437, 0.183290481567382812, 0.983036458492279052, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+25, 181060, 0, 130, 5478, '0', 0, 0, -347.078125, 1550.59033203125, 24.92294502258300781, 3.565793275833129882, 0.002133369445800781, -0.00627326965332031, -0.9775705337524414, 0.210504010319709777, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Pyrewood Town Hall - Difficulty: 0)
(@OGUID+26, 181060, 0, 130, 204, '0', 0, 0, -446.635406494140625, 1530.01220703125, 19.4093780517578125, 2.163007020950317382, 0.002418041229248046, 0.006169319152832031, 0.882643699645996093, 0.469995945692062377, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+27, 181060, 0, 130, 5476, '0', 0, 0, -385.3507080078125, 1446.5052490234375, 26.45168113708496093, 1.385794401168823242, 0.004575252532958984, 0.004793167114257812, 0.638751029968261718, 0.769384980201721191, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+28, 187668, 0, 130, 204, '0', 0, 0, -373.583343505859375, 1632.5555419921875, 19.34855079650878906, 3.051818370819091796, 0.588716983795166015, -0.35730361938476562, 0.644390106201171875, 0.332427203655242919, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Small - Val (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+29, 187668, 0, 130, 204, '0', 0, 0, -401.552093505859375, 1593.3663330078125, 19.34855079650878906, 1.11950993537902832, 0.040699958801269531, -0.68745708465576171, 0.092816352844238281, 0.71911853551864624, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Small - Val (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+30, 187668, 0, 130, 5478, '0', 0, 0, -348.086822509765625, 1551.2291259765625, 24.86211585998535156, 4.316674709320068359, -0.68606281280517578, -0.05976295471191406, -0.71626472473144531, 0.112743280827999114, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Small - Val (Area: Pyrewood Town Hall - Difficulty: 0)
(@OGUID+31, 187668, 0, 130, 204, '0', 0, 0, -446.17535400390625, 1531.107666015625, 19.34855079650878906, 2.913824319839477539, 0.562679290771484375, -0.39704608917236328, 0.619935989379882812, 0.376066207885742187, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Small - Val (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+32, 187668, 0, 130, 5476, '0', 0, 0, -384.25, 1446.9600830078125, 26.39084815979003906, 2.136607646942138671, 0.37028360366821289, -0.58064079284667968, 0.431220054626464843, 0.582919895648956298, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Small - Val (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+33, 201716, 0, 130, 236, '0', 0, 0, -292.638885498046875, 1638.732666015625, 18.73279762268066406, 1.530820608139038085, 0, 0, 0.69283294677734375, 0.721098124980926513, 120, 255, 1, 48069), -- Chemical Wagon (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+34, 201716, 0, 130, 204, '0', 0, 0, -396.68402099609375, 1646.6007080078125, 18.65784454345703125, 3.32197737693786621, 0, 0, -0.99593544006347656, 0.090070024132728576, 120, 255, 1, 48069), -- Chemical Wagon (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+35, 201716, 0, 130, 5478, '0', 0, 0, -394.953125, 1536.5382080078125, 18.65784454345703125, 4.001678466796875, 0, 0, -0.90894794464111328, 0.416909635066986083, 120, 255, 1, 48069), -- Chemical Wagon (Area: Pyrewood Town Hall - Difficulty: 0)
(@OGUID+36, 201751, 0, 130, 204, '0', 0, 0, -375.09722900390625, 1631.6910400390625, 19.40518760681152343, 5.652204513549804687, 0, 0, -0.31028270721435546, 0.950644373893737792, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+37, 201751, 0, 130, 204, '0', 0, 0, -376.765625, 1632.8333740234375, 18.65783119201660156, 6.205481529235839843, 0, 0, -0.03884220123291015, 0.999245345592498779, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+38, 201751, 0, 130, 204, '0', 0, 0, -376.81597900390625, 1631.46533203125, 18.65783119201660156, 0.27389228343963623, 0, 0, 0.136518478393554687, 0.990637540817260742, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+39, 201751, 0, 130, 204, '0', 0, 0, -400.166656494140625, 1596.2430419921875, 18.65783119201660156, 4.273142814636230468, 0, 0, -0.84417343139648437, 0.536070168018341064, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+40, 201751, 0, 130, 204, '0', 0, 0, -401.826385498046875, 1595.0850830078125, 19.40518760681152343, 3.719866275787353515, 0, 0, -0.95849037170410156, 0.285124897956848144, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+41, 201751, 0, 130, 204, '0', 0, 0, -401.430572509765625, 1596.7760009765625, 18.65783119201660156, 4.624742507934570312, 0, 0, -0.73740577697753906, 0.675450026988983154, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+42, 201751, 0, 130, 5478, '0', 0, 0, -349.3125, 1548.28125, 24.17138862609863281, 1.187062621116638183, 0, 0, 0.559291839599609375, 0.828970849514007568, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Town Hall - Difficulty: 0)
(@OGUID+43, 201751, 0, 130, 5478, '0', 0, 0, -347.720489501953125, 1549.5242919921875, 24.91875648498535156, 0.633784294128417968, 0, 0, 0.311614990234375, 0.950208425521850585, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Town Hall - Difficulty: 0)
(@OGUID+44, 201751, 0, 130, 5478, '0', 0, 0, -348.020843505859375, 1547.8160400390625, 24.17138862609863281, 1.538659572601318359, 0, 0, 0.695653915405273437, 0.71837705373764038, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Town Hall - Difficulty: 0)
(@OGUID+45, 201751, 0, 130, 204, '0', 0, 0, -447.7882080078125, 1530.4635009765625, 19.40518760681152343, 5.514192581176757812, 0, 0, -0.3750925064086914, 0.926987409591674804, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+46, 201751, 0, 130, 204, '0', 0, 0, -449.282989501953125, 1531.8211669921875, 18.65783119201660156, 6.067469596862792968, 0, 0, -0.10764884948730468, 0.994188964366912841, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+47, 201751, 0, 130, 204, '0', 0, 0, -449.524322509765625, 1530.4739990234375, 18.65783119201660156, 0.135879129171371459, 0, 0, 0.067887306213378906, 0.997693002223968505, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+48, 201751, 0, 130, 204, '0', 0, 0, -412.473968505859375, 1495.71533203125, 20.11561012268066406, 0.135879129171371459, 0, 0, 0.067887306213378906, 0.997693002223968505, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+49, 201751, 0, 130, 204, '0', 0, 0, -411.770843505859375, 1494.40283203125, 20.11803817749023437, 2.412203311920166015, 0, 0, 0.934232711791992187, 0.356664061546325683, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+50, 201751, 0, 130, 204, '0', 0, 0, -412.232635498046875, 1497.0625, 20.11665725708007812, 6.067469596862792968, 0, 0, -0.10764884948730468, 0.994188964366912841, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+51, 201751, 0, 130, 204, '0', 0, 0, -409.689239501953125, 1496.8541259765625, 20.11806869506835937, 0.435050070285797119, 0, 0, 0.215813636779785156, 0.976434588432312011, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+52, 201751, 0, 130, 204, '0', 0, 0, -409.06597900390625, 1495.6353759765625, 20.11702156066894531, 0.786645948886871337, 0, 0, 0.383259773254394531, 0.923640608787536621, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+53, 201751, 0, 130, 204, '0', 0, 0, -410.892364501953125, 1495.4478759765625, 20.11699104309082031, 2.763799667358398437, 0, 0, 0.982212066650390625, 0.187775090336799621, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+54, 201751, 0, 130, 5476, '0', 0, 0, -385.96875, 1449.6458740234375, 25.70012474060058593, 5.290255546569824218, 0, 0, -0.47632026672363281, 0.879271864891052246, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+55, 201751, 0, 130, 5476, '0', 0, 0, -385.8507080078125, 1447.6285400390625, 26.44748878479003906, 4.736977100372314453, 0, 0, -0.69836044311523437, 0.715746223926544189, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+56, 201751, 0, 130, 5476, '0', 0, 0, -387.079864501953125, 1448.8524169921875, 25.70012474060058593, 5.641852855682373046, 0, 0, -0.31519889831542968, 0.949025630950927734, 120, 255, 1, 48069), -- Crown Crate (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+57, 206770, 0, 130, 236, '0', 0, 0, -328.01910400390625, 1597.6180419921875, 18.59559059143066406, 5.627856254577636718, 0, 0, -0.32183265686035156, 0.946796596050262451, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+58, 206770, 0, 130, 236, '0', 0, 0, -343.145843505859375, 1592.7882080078125, 18.65784454345703125, 5.627856254577636718, 0, 0, -0.32183265686035156, 0.946796596050262451, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+59, 206770, 0, 130, 236, '0', 0, 0, -324.430572509765625, 1658.9879150390625, 19.69677162170410156, 5.950410366058349609, 0, 0, -0.16562080383300781, 0.986189544200897216, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+60, 206770, 0, 130, 236, '0', 0, 0, -328.571197509765625, 1594.1771240234375, 18.36774444580078125, 5.995562553405761718, 0, 0, -0.14331626892089843, 0.989676952362060546, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+61, 206770, 0, 130, 204, '0', 0, 0, -343.677093505859375, 1564.6649169921875, 24.19544792175292968, 5.627856254577636718, 0, 0, -0.32183265686035156, 0.946796596050262451, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+62, 206770, 0, 130, 204, '0', 0, 0, -386.47222900390625, 1632.126708984375, 18.65784454345703125, 5.864780902862548828, 0, 0, -0.20767974853515625, 0.97819685935974121, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+63, 206770, 0, 130, 204, '0', 0, 0, -368.09027099609375, 1611.4774169921875, 18.65784454345703125, 6.275496959686279296, 0, 0, -0.00384426116943359, 0.999992609024047851, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+64, 206770, 0, 130, 204, '0', 0, 0, -383.392364501953125, 1630.9410400390625, 18.65784454345703125, 5.627856254577636718, 0, 0, -0.32183265686035156, 0.946796596050262451, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+65, 206770, 0, 130, 204, '0', 0, 0, -377.921875, 1591.5521240234375, 18.65784454345703125, 5.654027938842773437, 0, 0, -0.30941581726074218, 0.950926840305328369, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+66, 206770, 0, 130, 204, '0', 0, 0, -393.234375, 1609.3958740234375, 18.65784454345703125, 5.627856254577636718, 0, 0, -0.32183265686035156, 0.946796596050262451, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+67, 206770, 0, 130, 204, '0', 0, 0, -390.015625, 1609.498291015625, 18.65784454345703125, 6.275496959686279296, 0, 0, -0.00384426116943359, 0.999992609024047851, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+68, 206770, 0, 130, 5478, '0', 0, 0, -412.38714599609375, 1546.9930419921875, 18.67681312561035156, 5.963945388793945312, 0, 0, -0.15894317626953125, 0.987287700176239013, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Pyrewood Town Hall - Difficulty: 0)
(@OGUID+69, 206770, 0, 130, 5478, '0', 0, 0, -413.48785400390625, 1545.7569580078125, 21.14084625244140625, 5.627856254577636718, 0, 0, -0.32183265686035156, 0.946796596050262451, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Pyrewood Town Hall - Difficulty: 0)
(@OGUID+70, 206770, 0, 130, 5478, '0', 0, 0, -355.592010498046875, 1541.953125, 24.18878555297851562, 5.891056060791015625, 0, 0, -0.19481086730957031, 0.980840802192687988, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Pyrewood Town Hall - Difficulty: 0)
(@OGUID+71, 206770, 0, 130, 5478, '0', 0, 0, -415.35589599609375, 1546.0660400390625, 18.65784072875976562, 6.071507930755615234, 0, 0, -0.10564136505126953, 0.994404315948486328, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Pyrewood Town Hall - Difficulty: 0)
(@OGUID+72, 206770, 0, 130, 5478, '0', 0, 0, -412.911468505859375, 1544.1492919921875, 18.65784645080566406, 6.091949462890625, 0, 0, -0.09547233581542968, 0.995432078838348388, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Pyrewood Town Hall - Difficulty: 0)
(@OGUID+73, 206770, 0, 130, 204, '0', 0, 0, -445.09722900390625, 1558.545166015625, 18.66840934753417968, 5.627856254577636718, 0, 0, -0.32183265686035156, 0.946796596050262451, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+74, 206770, 0, 130, 204, '0', 0, 0, -351.796875, 1489.935791015625, 19.2342376708984375, 5.963945388793945312, 0, 0, -0.15894317626953125, 0.987287700176239013, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+75, 206770, 0, 130, 204, '0', 0, 0, -350.751739501953125, 1486.3021240234375, 19.34778213500976562, 0.374568969011306762, 0, 0, 0.186191558837890625, 0.982513427734375, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+76, 206770, 0, 130, 204, '0', 0, 0, -390.3038330078125, 1451.5504150390625, 25.68385124206542968, 0.374568969011306762, 0, 0, 0.186191558837890625, 0.982513427734375, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+77, 206770, 0, 130, 5476, '0', 0, 0, -350.586822509765625, 1461.829833984375, 22.33709144592285156, 5.627856254577636718, 0, 0, -0.32183265686035156, 0.946796596050262451, 120, 255, 1, 48069), -- Standing, Large - Val (Scale 2) (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+78, 244432, 0, 130, 236, '0', 0, 0, -303.836822509765625, 1623.71533203125, 18.40972328186035156, 3.138830423355102539, 0, 0, 0.999999046325683593, 0.001381067908369004, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+79, 244432, 0, 130, 236, '0', 0, 0, -319.067718505859375, 1647.55908203125, 19.08722877502441406, 0.942973256111145019, 0, 0, 0.454211235046386718, 0.890894055366516113, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+80, 244432, 0, 130, 236, '0', 0, 0, -302.989593505859375, 1671.3228759765625, 19.8125, 1.681146502494812011, 0, 0, 0.745025634765625, 0.667035818099975585, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+81, 244432, 0, 130, 236, '0', 0, 0, -304.91839599609375, 1659.1441650390625, 19.390625, 3.299438238143920898, 0, 0, -0.99688720703125, 0.078840792179107666, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+82, 244432, 0, 130, 236, '0', 0, 0, -282.42535400390625, 1649.810791015625, 18.20883369445800781, 5.012798309326171875, 0, 0, -0.59333324432373046, 0.804956912994384765, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+83, 244432, 0, 130, 236, '0', 0, 0, -299.258697509765625, 1620.62158203125, 18.40737533569335937, 1.049973726272583007, 0, 0, 0.501201629638671875, 0.865330517292022705, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+84, 244432, 0, 130, 236, '0', 0, 0, -316.447906494140625, 1628.7100830078125, 19.42081832885742187, 2.536521673202514648, 0, 0, 0.954584121704101562, 0.297941505908966064, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+85, 244432, 0, 130, 236, '0', 0, 0, -321.026031494140625, 1631.8038330078125, 19.97048568725585937, 3.919273853302001953, 0, 0, -0.92534923553466796, 0.379115790128707885, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+86, 244432, 0, 130, 236, '0', 0, 0, -310.177093505859375, 1599.5538330078125, 17.86631965637207031, 5.134169578552246093, 0, 0, -0.54342174530029296, 0.839459836483001708, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+87, 244432, 0, 130, 236, '0', 0, 0, -286.713531494140625, 1674.3785400390625, 18.42801094055175781, 3.793166637420654296, 0, 0, -0.94739913940429687, 0.320054471492767333, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+88, 244432, 0, 130, 236, '0', 0, 0, -287.00347900390625, 1652.904541015625, 18.40625, 4.227080821990966796, 0, 0, -0.85629463195800781, 0.516487658023834228, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+89, 244432, 0, 130, 236, '0', 0, 0, -322.836822509765625, 1639.65283203125, 19.79848670959472656, 1.479302406311035156, 0, 0, 0.674030303955078125, 0.738703668117523193, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+90, 244432, 0, 130, 236, '0', 0, 0, -300.34027099609375, 1656.0504150390625, 19.574676513671875, 1.823093175888061523, 0, 0, 0.790452003479003906, 0.612523972988128662, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+91, 244432, 0, 130, 236, '0', 0, 0, -291.291656494140625, 1677.4722900390625, 18.43924331665039062, 4.743973731994628906, 0, 0, -0.69585227966308593, 0.718184947967529296, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+92, 244432, 0, 130, 236, '0', 0, 0, -298.411468505859375, 1668.2291259765625, 19.41287040710449218, 0, 0, 0, 0, 1, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+93, 244432, 0, 130, 236, '0', 0, 0, -305.598968505859375, 1596.4600830078125, 17.74093055725097656, 0.941614031791687011, 0, 0, 0.45360565185546875, 0.891202509403228759, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+94, 244432, 0, 130, 236, '0', 0, 0, -327.414947509765625, 1642.74658203125, 18.96354103088378906, 0.007917424663901329, 0, 0, 0.003958702087402343, 0.999992132186889648, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+95, 244432, 0, 130, 236, '0', 0, 0, -309.279510498046875, 1688.8489990234375, 19.77430534362792968, 3.70540165901184082, 0, 0, -0.96052742004394531, 0.278185367584228515, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+96, 244432, 0, 130, 236, '0', 0, 0, -332.651031494140625, 1649.59033203125, 18.64583396911621093, 2.865782737731933593, 0, 0, 0.990506172180175781, 0.13746829330921173, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+97, 244432, 0, 130, 236, '0', 0, 0, -351.651031494140625, 1657.486083984375, 18.96875, 1.110637187957763671, 0, 0, 0.52721405029296875, 0.849732518196105957, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+98, 244432, 0, 130, 236, '0', 0, 0, -336.416656494140625, 1627.1632080078125, 18.355255126953125, 3.412036895751953125, 0, 0, -0.99087142944335937, 0.134810283780097961, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+99, 244432, 0, 130, 236, '0', 0, 0, -347.072906494140625, 1654.392333984375, 19.114501953125, 3.345687150955200195, 0, 0, -0.9947977066040039, 0.101870141923427581, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+100, 244432, 0, 130, 236, '0', 0, 0, -324.451385498046875, 1602.4288330078125, 18.96701431274414062, 4.172742843627929687, 0, 0, -0.87000942230224609, 0.493035078048706054, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+101, 244432, 0, 130, 236, '0', 0, 0, -319.873260498046875, 1599.3350830078125, 18.86367225646972656, 1.393706083297729492, 0, 0, 0.64180755615234375, 0.766865730285644531, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+102, 244432, 0, 130, 236, '0', 0, 0, -304.701385498046875, 1685.7552490234375, 18.56967926025390625, 4.885887622833251953, 0, 0, -0.64318370819091796, 0.765711903572082519, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+103, 244432, 0, 130, 236, '0', 0, 0, -323.645843505859375, 1650.65283203125, 19.020782470703125, 2.558794260025024414, 0, 0, 0.957842826843261718, 0.287292718887329101, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+104, 244432, 0, 130, 236, '0', 0, 0, -340.994781494140625, 1630.2569580078125, 18.41666603088378906, 3.412036895751953125, 0, 0, -0.99087142944335937, 0.134810283780097961, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+105, 244432, 0, 130, 236, '0', 0, 0, -337.458343505859375, 1663.0086669921875, 18.41414451599121093, 4.466115474700927734, 0, 0, -0.78860378265380859, 0.614901721477508544, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+106, 244432, 0, 130, 236, '0', 0, 0, -331.9913330078125, 1613.423583984375, 18.59895896911621093, 3.702535390853881835, 0, 0, -0.96092510223388671, 0.276808530092239379, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+107, 244432, 0, 130, 236, '0', 0, 0, -328.072906494140625, 1646.49658203125, 18.71049118041992187, 3.980512380599975585, 0, 0, -0.91330909729003906, 0.407267093658447265, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+108, 244432, 0, 130, 236, '0', 0, 0, -342.036468505859375, 1666.1024169921875, 18.42361068725585937, 1.905924320220947265, 0, 0, 0.815135002136230468, 0.57927107810974121, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+109, 244432, 0, 130, 236, '0', 0, 0, -327.4132080078125, 1610.329833984375, 18.73045730590820312, 3.702535390853881835, 0, 0, -0.96092510223388671, 0.276808530092239379, 120, 255, 1, 48069), -- Memorial Flowers (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+110, 244432, 0, 130, 204, '0', 0, 0, -366.880218505859375, 1662.6024169921875, 18.38169097900390625, 0, 0, 0, 0, 1, 120, 255, 1, 48069), -- Memorial Flowers (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+111, 244432, 0, 130, 204, '0', 0, 0, -371.458343505859375, 1665.6961669921875, 18.40188026428222656, 0.483790129423141479, 0, 0, 0.239542961120605468, 0.970885753631591796, 120, 255, 1, 48069), -- Memorial Flowers (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+112, 247561, 0, 130, 204, '0', 0, 0, -374.229156494140625, 1631.8680419921875, 18.65746688842773437, 4.664952754974365234, 0, 0, -0.72367763519287109, 0.690138161182403564, 120, 255, 1, 48069), -- Table Large 01 (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+113, 247561, 0, 130, 204, '0', 0, 0, -401.96527099609375, 1594.2100830078125, 18.65746688842773437, 2.732607364654541015, 0, 0, 0.97916412353515625, 0.203070417046546936, 120, 255, 1, 48069), -- Table Large 01 (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+114, 247561, 0, 130, 5478, '0', 0, 0, -347.630218505859375, 1550.4097900390625, 24.17103385925292968, 5.929718971252441406, 0, 0, -0.17581462860107421, 0.984423279762268066, 120, 255, 1, 48069), -- Table Large 01 (Area: Pyrewood Town Hall - Difficulty: 0)
(@OGUID+115, 247561, 0, 130, 204, '0', 0, 0, -446.901031494140625, 1530.517333984375, 18.65746688842773437, 4.526938915252685546, 0, 0, -0.76954174041748046, 0.638596534729003906, 120, 255, 1, 48069), -- Table Large 01 (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+116, 247561, 0, 130, 5476, '0', 0, 0, -385.180572509765625, 1447.046875, 25.69975852966308593, 3.749729156494140625, 0, 0, -0.95412635803222656, 0.29940420389175415, 120, 255, 1, 48069), -- Table Large 01 (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+117, 259459, 0, 130, 204, '0', 0, 0, -374.34027099609375, 1632.2222900390625, 19.42716407775878906, 5.652204513549804687, 0, 0, -0.31028270721435546, 0.950644373893737792, 120, 255, 1, 48069), -- Tools (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+118, 259459, 0, 130, 204, '0', 0, 0, -401.59722900390625, 1594.189208984375, 19.42716407775878906, 3.719866275787353515, 0, 0, -0.95849037170410156, 0.285124897956848144, 120, 255, 1, 48069), -- Tools (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+119, 259459, 0, 130, 5478, '0', 0, 0, -348.00347900390625, 1550.40625, 24.94072914123535156, 0.633784294128417968, 0, 0, 0.311614990234375, 0.950208425521850585, 120, 255, 1, 48069), -- Tools (Area: Pyrewood Town Hall - Difficulty: 0)
(@OGUID+120, 259459, 0, 130, 204, '0', 0, 0, -446.96527099609375, 1530.88720703125, 19.42716407775878906, 5.514192581176757812, 0, 0, -0.3750925064086914, 0.926987409591674804, 120, 255, 1, 48069), -- Tools (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+121, 259459, 0, 130, 5476, '0', 0, 0, -384.96875, 1447.3524169921875, 26.46946144104003906, 4.736977100372314453, 0, 0, -0.69836044311523437, 0.715746223926544189, 120, 255, 1, 48069), -- Tools (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+122, 259461, 0, 130, 204, '0', 0, 0, -371.338531494140625, 1630.3646240234375, 18.65783119201660156, 0.187377259135246276, 0, 0, 0.0935516357421875, 0.995614409446716308, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+123, 259461, 0, 130, 204, '0', 0, 0, -370.963531494140625, 1631.045166015625, 19.6533660888671875, 6.036946773529052734, 0, 0, -0.12280845642089843, 0.992430388927459716, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+124, 259461, 0, 130, 204, '0', 0, 0, -371.5, 1631.513916015625, 18.65783119201660156, 0.138010814785957336, 0, 0, 0.068950653076171875, 0.997620046138763427, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+125, 259461, 0, 130, 204, '0', 0, 0, -370.364593505859375, 1631.2603759765625, 18.65783119201660156, 6.233489990234375, 0, 0, -0.02484512329101562, 0.999691307544708251, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+126, 259461, 0, 130, 204, '0', 0, 0, -403.90277099609375, 1590.8125, 18.65783119201660156, 4.301153182983398437, 0, 0, -0.83658313751220703, 0.547839999198913574, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+127, 259461, 0, 130, 204, '0', 0, 0, -404.392364501953125, 1592.0382080078125, 18.65783119201660156, 4.538226604461669921, 0, 0, -0.76592540740966796, 0.642929434776306152, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+128, 259461, 0, 130, 204, '0', 0, 0, -403.263885498046875, 1591.7847900390625, 18.65783119201660156, 4.488860607147216796, 0, 0, -0.78155994415283203, 0.623830139636993408, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+129, 259461, 0, 130, 204, '0', 0, 0, -403.892364501953125, 1591.4461669921875, 19.6533660888671875, 4.104610443115234375, 0, 0, -0.88629722595214843, 0.463116884231567382, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+130, 259461, 0, 130, 204, '0', 0, 0, -345.85589599609375, 1553.2708740234375, 25.16693305969238281, 1.018527388572692871, 0, 0, 0.487534523010253906, 0.873103737831115722, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+131, 259461, 0, 130, 204, '0', 0, 0, -346.46527099609375, 1552.904541015625, 24.17138862609863281, 1.402779221534729003, 0, 0, 0.645279884338378906, 0.763946235179901123, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+132, 259461, 0, 130, 204, '0', 0, 0, -345.880218505859375, 1553.9149169921875, 24.17138862609863281, 1.215070724487304687, 0, 0, 0.570845603942871093, 0.821057438850402832, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+133, 259461, 0, 130, 5478, '0', 0, 0, -345.32464599609375, 1552.7135009765625, 24.17138862609863281, 1.452144265174865722, 0, 0, 0.663937568664550781, 0.747788012027740478, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Town Hall - Difficulty: 0)
(@OGUID+134, 259461, 0, 130, 204, '0', 0, 0, -415.039947509765625, 1504.6319580078125, 20.09019660949707031, 6.095476627349853515, 0, 0, -0.09371662139892578, 0.995598912239074707, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+135, 259461, 0, 130, 204, '0', 0, 0, -416.126739501953125, 1503.8853759765625, 20.09211158752441406, 0.049365285784006118, 0, 0, 0.024680137634277343, 0.999695420265197753, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+136, 259461, 0, 130, 204, '0', 0, 0, -443.78125, 1529.2552490234375, 19.6533660888671875, 5.898934841156005859, 0, 0, -0.19094562530517578, 0.981600642204284667, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+137, 259461, 0, 130, 204, '0', 0, 0, -416.1319580078125, 1505.0382080078125, 20.09297752380371093, 0, 0, 0, 0, 1, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+138, 259461, 0, 130, 204, '0', 0, 0, -444.248260498046875, 1528.63720703125, 18.65783119201660156, 0.049365285784006118, 0, 0, 0.024680137634277343, 0.999695420265197753, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+139, 259461, 0, 130, 204, '0', 0, 0, -444.25347900390625, 1529.7899169921875, 18.65783119201660156, 0, 0, 0, 0, 1, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+140, 259461, 0, 130, 204, '0', 0, 0, -415.65972900390625, 1504.5035400390625, 21.08718681335449218, 5.898934841156005859, 0, 0, -0.19094562530517578, 0.981600642204284667, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+141, 259461, 0, 130, 204, '0', 0, 0, -443.161468505859375, 1529.3836669921875, 18.65783119201660156, 6.095476627349853515, 0, 0, -0.09371662139892578, 0.995598912239074707, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+142, 259461, 0, 130, 5476, '0', 0, 0, -383.3125, 1443.6163330078125, 25.70012474060058593, 5.318263530731201171, 0, 0, -0.46396064758300781, 0.885855793952941894, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+143, 259461, 0, 130, 5476, '0', 0, 0, -327.85589599609375, 1468.2379150390625, 32.26903152465820312, 5.555337905883789062, 0, 0, -0.35594367980957031, 0.934507429599761962, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+144, 259461, 0, 130, 5476, '0', 0, 0, -327.05035400390625, 1469.0625, 32.26903152465820312, 5.505971908569335937, 0, 0, -0.37889957427978515, 0.925437808036804199, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+145, 259461, 0, 130, 5476, '0', 0, 0, -383.84375, 1443.9635009765625, 26.69566917419433593, 5.121720314025878906, 0, 0, -0.54863643646240234, 0.836061060428619384, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+146, 259461, 0, 130, 5476, '0', 0, 0, -384.611114501953125, 1443.8489990234375, 25.70012474060058593, 5.555337905883789062, 0, 0, -0.35594367980957031, 0.934507429599761962, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+147, 259461, 0, 130, 5476, '0', 0, 0, -327.088531494140625, 1468.3524169921875, 33.25806808471679687, 5.121720314025878906, 0, 0, -0.54863643646240234, 0.836061060428619384, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+148, 259461, 0, 130, 5476, '0', 0, 0, -383.805572509765625, 1444.673583984375, 25.70012474060058593, 5.505971908569335937, 0, 0, -0.37889957427978515, 0.925437808036804199, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+149, 259461, 0, 130, 5476, '0', 0, 0, -326.557281494140625, 1468.0052490234375, 32.26903152465820312, 5.318263530731201171, 0, 0, -0.46396064758300781, 0.885855793952941894, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+150, 259461, 0, 130, 5476, '0', 0, 0, -391.9444580078125, 1423.423583984375, 28.15021896362304687, 5.898934841156005859, 0, 0, -0.19094562530517578, 0.981600642204284667, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+151, 259461, 0, 130, 5476, '0', 0, 0, -391.32464599609375, 1423.5521240234375, 27.15202713012695312, 6.095476627349853515, 0, 0, -0.09371662139892578, 0.995598912239074707, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+152, 259461, 0, 130, 5476, '0', 0, 0, -392.411468505859375, 1422.8055419921875, 27.15764808654785156, 0.049365285784006118, 0, 0, 0.024680137634277343, 0.999695420265197753, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+153, 259461, 0, 130, 5476, '0', 0, 0, -392.416656494140625, 1423.9583740234375, 27.13882255554199218, 0, 0, 0, 0, 1, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+154, 259523, 0, 130, 236, '0', 0, 0, -327.861114501953125, 1658.65283203125, 19.3940887451171875, 5.627856254577636718, 0, 0, -0.32183265686035156, 0.946796596050262451, 120, 255, 1, 48069), -- Crown Crate (Large) (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+155, 259523, 0, 130, 204, '0', 0, 0, -378.23785400390625, 1567.8958740234375, 18.68685531616210937, 0.35231173038482666, 0, 0, 0.175246238708496093, 0.984524667263031005, 120, 255, 1, 48069), -- Crown Crate (Large) (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+156, 259523, 0, 130, 204, '0', 0, 0, -379.260406494140625, 1570.6041259765625, 18.70833396911621093, 0.224306836724281311, 0, 0, 0.111918449401855468, 0.993717372417449951, 120, 255, 1, 48069), -- Crown Crate (Large) (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+157, 259523, 0, 130, 204, '0', 0, 0, -379.564239501953125, 1568.9791259765625, 21.15660667419433593, 6.171406269073486328, 0, 0, -0.05586051940917968, 0.998438596725463867, 120, 255, 1, 48069), -- Crown Crate (Large) (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+158, 259523, 0, 130, 204, '0', 0, 0, -381.321197509765625, 1568.2742919921875, 18.65972328186035156, 0.331869840621948242, 0, 0, 0.165174484252929687, 0.986264348030090332, 120, 255, 1, 48069), -- Crown Crate (Large) (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+159, 259523, 0, 130, 204, '0', 0, 0, -387.477447509765625, 1454.1771240234375, 25.68385124206542968, 0.331869840621948242, 0, 0, 0.165174484252929687, 0.986264348030090332, 120, 255, 1, 48069), -- Crown Crate (Large) (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+160, 259523, 0, 130, 5476, '0', 0, 0, -349.664947509765625, 1453.0538330078125, 23.52892684936523437, 0.331869840621948242, 0, 0, 0.165174484252929687, 0.986264348030090332, 120, 255, 1, 48069), -- Crown Crate (Large) (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+161, 259764, 0, 130, 236, '0', 0, 0, -327.4444580078125, 1657.2916259765625, 22.21895217895507812, 5.080571651458740234, -0.36442422866821289, -0.50426387786865234, -0.45282173156738281, 0.638643383979797363, 120, 255, 1, 48069), -- Love Potion No. 8 (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+162, 259764, 0, 130, 236, '0', 0, 0, -332.40277099609375, 1554.9896240234375, 27.44699859619140625, 5.080571651458740234, -0.36442422866821289, -0.50426387786865234, -0.45282173156738281, 0.638643383979797363, 120, 255, 1, 48069), -- Love Potion No. 8 (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+163, 259764, 0, 130, 204, '0', 0, 0, -376.9444580078125, 1633.12158203125, 19.98502922058105468, 5.080571651458740234, -0.36442422866821289, -0.50426387786865234, -0.45282173156738281, 0.638643383979797363, 120, 255, 1, 48069), -- Love Potion No. 8 (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+164, 259764, 0, 130, 204, '0', 0, 0, -379.65277099609375, 1584.4566650390625, 19.56160545349121093, 5.080571651458740234, -0.36442422866821289, -0.50426387786865234, -0.45282173156738281, 0.638643383979797363, 120, 255, 1, 48069), -- Love Potion No. 8 (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+165, 259764, 0, 130, 204, '0', 0, 0, -434.15972900390625, 1520.138916015625, 21.19707107543945312, 5.080571651458740234, -0.36442422866821289, -0.50426387786865234, -0.45282173156738281, 0.638643383979797363, 120, 255, 1, 48069), -- Love Potion No. 8 (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+166, 259764, 0, 130, 5476, '0', 0, 0, -385.232635498046875, 1448.3785400390625, 26.80701446533203125, 5.080571651458740234, -0.36442422866821289, -0.50426387786865234, -0.45282173156738281, 0.638643383979797363, 120, 255, 1, 48069), -- Love Potion No. 8 (Area: Pyrewood Chapel - Difficulty: 0)
(@OGUID+167, 259803, 0, 130, 204, '0', 0, 0, -391.8194580078125, 1506.451416015625, 29.46763420104980468, 5.773909568786621093, 0, 0, -0.25189495086669921, 0.967754602432250976, 120, 255, 1, 48069), -- Recipe Fragment (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+168, 259804, 0, 130, 204, '0', 0, 0, -335.80902099609375, 1554.185791015625, 26.1377410888671875, 0.893613338470458984, 0, 0, 0.432087898254394531, 0.901831448078155517, 120, 255, 1, 48069), -- Recipe Fragment (Area: Pyrewood Village - Difficulty: 0)
(@OGUID+169, 259805, 0, 130, 236, '0', 0, 0, -325.595489501953125, 1656.361083984375, 19.50065231323242187, 5.272631645202636718, 0, 0, -0.48404979705810546, 0.87504047155380249, 120, 255, 1, 48069), -- Recipe Fragment (Area: Shadowfang Keep - Difficulty: 0)
(@OGUID+170, 259806, 0, 130, 5478, '0', 0, 0, -400.947906494140625, 1549.576416015625, 18.65784645080566406, 0.756443321704864501, 0, 0, 0.369268417358398437, 0.929322779178619384, 120, 255, 1, 48069); -- Love Potion Recipe (Area: Pyrewood Town Hall - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+53;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1),
(@EVENT, @CGUID+2),
(@EVENT, @CGUID+3),
(@EVENT, @CGUID+4),
(@EVENT, @CGUID+5),
(@EVENT, @CGUID+6),
(@EVENT, @CGUID+7),
(@EVENT, @CGUID+8),
(@EVENT, @CGUID+9),
(@EVENT, @CGUID+10),
(@EVENT, @CGUID+11),
(@EVENT, @CGUID+12),
(@EVENT, @CGUID+13),
(@EVENT, @CGUID+14),
(@EVENT, @CGUID+15),
(@EVENT, @CGUID+16),
(@EVENT, @CGUID+17),
(@EVENT, @CGUID+18),
(@EVENT, @CGUID+19),
(@EVENT, @CGUID+20),
(@EVENT, @CGUID+21),
(@EVENT, @CGUID+22),
(@EVENT, @CGUID+23),
(@EVENT, @CGUID+24),
(@EVENT, @CGUID+25),
(@EVENT, @CGUID+26),
(@EVENT, @CGUID+27),
(@EVENT, @CGUID+28),
(@EVENT, @CGUID+29),
(@EVENT, @CGUID+30),
(@EVENT, @CGUID+31),
(@EVENT, @CGUID+32),
(@EVENT, @CGUID+33),
(@EVENT, @CGUID+34),
(@EVENT, @CGUID+35),
(@EVENT, @CGUID+36),
(@EVENT, @CGUID+37),
(@EVENT, @CGUID+38),
(@EVENT, @CGUID+39),
(@EVENT, @CGUID+40),
(@EVENT, @CGUID+41),
(@EVENT, @CGUID+42),
(@EVENT, @CGUID+43),
(@EVENT, @CGUID+44),
(@EVENT, @CGUID+45),
(@EVENT, @CGUID+46),
(@EVENT, @CGUID+47),
(@EVENT, @CGUID+48),
(@EVENT, @CGUID+49),
(@EVENT, @CGUID+50),
(@EVENT, @CGUID+51),
(@EVENT, @CGUID+52),
(@EVENT, @CGUID+53);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID+0 AND @OGUID+170;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@EVENT, @OGUID+0),
(@EVENT, @OGUID+1),
(@EVENT, @OGUID+2),
(@EVENT, @OGUID+3),
(@EVENT, @OGUID+4),
(@EVENT, @OGUID+5),
(@EVENT, @OGUID+6),
(@EVENT, @OGUID+7),
(@EVENT, @OGUID+8),
(@EVENT, @OGUID+9),
(@EVENT, @OGUID+10),
(@EVENT, @OGUID+11),
(@EVENT, @OGUID+12),
(@EVENT, @OGUID+13),
(@EVENT, @OGUID+14),
(@EVENT, @OGUID+15),
(@EVENT, @OGUID+16),
(@EVENT, @OGUID+17),
(@EVENT, @OGUID+18),
(@EVENT, @OGUID+19),
(@EVENT, @OGUID+20),
(@EVENT, @OGUID+21),
(@EVENT, @OGUID+22),
(@EVENT, @OGUID+23),
(@EVENT, @OGUID+24),
(@EVENT, @OGUID+25),
(@EVENT, @OGUID+26),
(@EVENT, @OGUID+27),
(@EVENT, @OGUID+28),
(@EVENT, @OGUID+29),
(@EVENT, @OGUID+30),
(@EVENT, @OGUID+31),
(@EVENT, @OGUID+32),
(@EVENT, @OGUID+33),
(@EVENT, @OGUID+34),
(@EVENT, @OGUID+35),
(@EVENT, @OGUID+36),
(@EVENT, @OGUID+37),
(@EVENT, @OGUID+38),
(@EVENT, @OGUID+39),
(@EVENT, @OGUID+40),
(@EVENT, @OGUID+41),
(@EVENT, @OGUID+42),
(@EVENT, @OGUID+43),
(@EVENT, @OGUID+44),
(@EVENT, @OGUID+45),
(@EVENT, @OGUID+46),
(@EVENT, @OGUID+47),
(@EVENT, @OGUID+48),
(@EVENT, @OGUID+49),
(@EVENT, @OGUID+50),
(@EVENT, @OGUID+51),
(@EVENT, @OGUID+52),
(@EVENT, @OGUID+53),
(@EVENT, @OGUID+54),
(@EVENT, @OGUID+55),
(@EVENT, @OGUID+56),
(@EVENT, @OGUID+57),
(@EVENT, @OGUID+58),
(@EVENT, @OGUID+59),
(@EVENT, @OGUID+60),
(@EVENT, @OGUID+61),
(@EVENT, @OGUID+62),
(@EVENT, @OGUID+63),
(@EVENT, @OGUID+64),
(@EVENT, @OGUID+65),
(@EVENT, @OGUID+66),
(@EVENT, @OGUID+67),
(@EVENT, @OGUID+68),
(@EVENT, @OGUID+69),
(@EVENT, @OGUID+70),
(@EVENT, @OGUID+71),
(@EVENT, @OGUID+72),
(@EVENT, @OGUID+73),
(@EVENT, @OGUID+74),
(@EVENT, @OGUID+75),
(@EVENT, @OGUID+76),
(@EVENT, @OGUID+77),
(@EVENT, @OGUID+78),
(@EVENT, @OGUID+79),
(@EVENT, @OGUID+80),
(@EVENT, @OGUID+81),
(@EVENT, @OGUID+82),
(@EVENT, @OGUID+83),
(@EVENT, @OGUID+84),
(@EVENT, @OGUID+85),
(@EVENT, @OGUID+86),
(@EVENT, @OGUID+87),
(@EVENT, @OGUID+88),
(@EVENT, @OGUID+89),
(@EVENT, @OGUID+90),
(@EVENT, @OGUID+91),
(@EVENT, @OGUID+92),
(@EVENT, @OGUID+93),
(@EVENT, @OGUID+94),
(@EVENT, @OGUID+95),
(@EVENT, @OGUID+96),
(@EVENT, @OGUID+97),
(@EVENT, @OGUID+98),
(@EVENT, @OGUID+99),
(@EVENT, @OGUID+100),
(@EVENT, @OGUID+101),
(@EVENT, @OGUID+102),
(@EVENT, @OGUID+103),
(@EVENT, @OGUID+104),
(@EVENT, @OGUID+105),
(@EVENT, @OGUID+106),
(@EVENT, @OGUID+107),
(@EVENT, @OGUID+108),
(@EVENT, @OGUID+109),
(@EVENT, @OGUID+110),
(@EVENT, @OGUID+111),
(@EVENT, @OGUID+112),
(@EVENT, @OGUID+113),
(@EVENT, @OGUID+114),
(@EVENT, @OGUID+115),
(@EVENT, @OGUID+116),
(@EVENT, @OGUID+117),
(@EVENT, @OGUID+118),
(@EVENT, @OGUID+119),
(@EVENT, @OGUID+120),
(@EVENT, @OGUID+121),
(@EVENT, @OGUID+122),
(@EVENT, @OGUID+123),
(@EVENT, @OGUID+124),
(@EVENT, @OGUID+125),
(@EVENT, @OGUID+126),
(@EVENT, @OGUID+127),
(@EVENT, @OGUID+128),
(@EVENT, @OGUID+129),
(@EVENT, @OGUID+130),
(@EVENT, @OGUID+131),
(@EVENT, @OGUID+132),
(@EVENT, @OGUID+133),
(@EVENT, @OGUID+134),
(@EVENT, @OGUID+135),
(@EVENT, @OGUID+136),
(@EVENT, @OGUID+137),
(@EVENT, @OGUID+138),
(@EVENT, @OGUID+139),
(@EVENT, @OGUID+140),
(@EVENT, @OGUID+141),
(@EVENT, @OGUID+142),
(@EVENT, @OGUID+143),
(@EVENT, @OGUID+144),
(@EVENT, @OGUID+145),
(@EVENT, @OGUID+146),
(@EVENT, @OGUID+147),
(@EVENT, @OGUID+148),
(@EVENT, @OGUID+149),
(@EVENT, @OGUID+150),
(@EVENT, @OGUID+151),
(@EVENT, @OGUID+152),
(@EVENT, @OGUID+153),
(@EVENT, @OGUID+154),
(@EVENT, @OGUID+155),
(@EVENT, @OGUID+156),
(@EVENT, @OGUID+157),
(@EVENT, @OGUID+158),
(@EVENT, @OGUID+159),
(@EVENT, @OGUID+160),
(@EVENT, @OGUID+161),
(@EVENT, @OGUID+162),
(@EVENT, @OGUID+163),
(@EVENT, @OGUID+164),
(@EVENT, @OGUID+165),
(@EVENT, @OGUID+166),
(@EVENT, @OGUID+167),
(@EVENT, @OGUID+168),
(@EVENT, @OGUID+169),
(@EVENT, @OGUID+170);
