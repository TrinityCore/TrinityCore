SET @CGUID := 9004523;
SET @OGUID := 9003984;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 206596, 0, 1519, 5154, '0', 0, 0, 0, 0, -8907.33203125, 968.248291015625, 117.64715576171875, 4.032818317413330078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55939), -- Delivery Imp (Area: Mage Quarter - Difficulty: 0) CreateObject1 (Auras: 413842 - Carrying Papers [DNT])
(@CGUID+1, 206381, 0, 1519, 5154, '0', 0, 0, 0, 0, -8908.5537109375, 964.857666015625, 117.686553955078125, 1.916299939155578613, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55939), -- Notary Imp (Area: Mage Quarter - Difficulty: 0) CreateObject1 (Auras: 343476 - Taking Notes)
(@CGUID+2, 206596, 0, 1519, 5154, '0', 0, 0, 0, 0, -8910.0576171875, 966.3038330078125, 117.564208984375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55939), -- Delivery Imp (Area: Mage Quarter - Difficulty: 0) CreateObject1 (Auras: 413842 - Carrying Papers [DNT])
(@CGUID+3, 204198, 0, 1519, 5154, '0', 21679, 0, 0, 0, -8911.751953125, 963.6632080078125, 117.4807586669921875, 2.982371807098388671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55939), -- Assistant Phineas (Area: Mage Quarter - Difficulty: 0) CreateObject1
(@CGUID+4, 207684, 0, 1519, 5154, '0', 21679, 0, 0, 0, -8910.375, 959.20831298828125, 117.60601806640625, 3.685421943664550781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55939); -- Stagecoach (Area: Mage Quarter - Difficulty: 0) CreateObject1 (Auras: )

-- GameObject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 403736, 0, 1519, 5154, '0', 0, 0, -8908.216796875, 966.451416015625, 117.708282470703125, 0, 0, 0, 0, 1, 120, 255, 1, 55939); -- Pile of Letters (Area: Mage Quarter - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=206381; -- Notary Imp
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=206596; -- Delivery Imp
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=204198; -- Assistant Phineas
UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=16777217, `VehicleId`=8143 WHERE `entry`=207684; -- Stagecoach

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (204198 /*204198 (Assistant Phineas) - Ride Mr. Shadow's Stagecoach*/, 206381 /*206381 (Notary Imp) - Taking Notes*/, 206596 /*206596 (Delivery Imp) - Carrying Papers [DNT]*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(204198, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 204198 (Assistant Phineas) - Ride Mr. Shadow's Stagecoach
(206381, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '343476'), -- 206381 (Notary Imp) - Taking Notes
(206596, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '413842'); -- 206596 (Delivery Imp) - Carrying Papers [DNT]

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 21679;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(21679, 'Cosmetic - See Assistant Phineas and Stagecoach');

DELETE FROM `phase_area` WHERE `PhaseId` = 21679; 
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 21679, 'Cosmetic - See Assistant Phineas and Stagecoach');

-- Vehicle
DELETE FROM `vehicle_template_accessory` WHERE (`entry`=207684 AND `seat_id` IN (5,4));
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(207684, 14505, 5, 0, 'Stagecoach - Dreadsteed', 8, 0), -- Stagecoach - Dreadsteed
(207684, 14505, 4, 0, 'Stagecoach - Dreadsteed', 8, 0); -- Stagecoach - Dreadsteed

-- spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 207684;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(207684, 408907, 1, 0);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 18) AND (`SourceGroup` IN (207684));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(18, 207684, 408907, 0, 0, 9, 0, 75538, 0, 0, '', 0, 'Clicker has quest Beginning Impositions (75538) active'),
(18, 207684, 408907, 0, 1, 51, 0, 5, 14505, 0, '', 0, 'Clicker is TYPEID_UNIT, entry is 14505');

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=55939 WHERE (`Entry`=206381 AND `DifficultyID`=0); -- 206381 (Notary Imp) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=55939 WHERE (`Entry`=206596 AND `DifficultyID`=0); -- 206596 (Delivery Imp) - CanSwim

-- Quest
DELETE FROM `quest_description_conditional` WHERE (`QuestId`=75538 AND `PlayerConditionId`=1702260588 AND `QuestgiverCreatureId`=1064593696 AND `locale`='enUS');
INSERT INTO `quest_description_conditional` (`QuestId`, `PlayerConditionId`, `QuestgiverCreatureId`, `locale`, `Text`, `OrderIndex`, `VerifiedBuild`) VALUES
(75538, 1702260588, 1064593696, 'enUS', 'es. Yes!\n\nAhem.\n\nShe requires your presence, she does! Our Lady of the Midnight Moon. The Damsel of Darkness! The Mother of Crows...\n\n...Madam Shadow.Travel to the Darkmoon Faire.', 0, 55939); -- Beginning Impositions

DELETE FROM `creature_queststarter` WHERE (`id`=204198 AND `quest`=75538);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(204198, 75538, 55939); -- Beginning Impositions offered by Assistant Phineas 

DELETE FROM `quest_template_addon` WHERE `ID` = 75538;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(75538, 0, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
