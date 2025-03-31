SET @CGUID := 7001780;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 124953, 1643, 8721, 9033, '0', 0, 0, 0, 0, 187.4895782470703125, 1987.69970703125, 101.0208892822265625, 3.432718276977539062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888); -- Helena Gentle (Area: Shrouded Foothills - Difficulty: 0) CreateObject2

-- Template
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_helena_gentle_witch_hunt' WHERE `entry` = 124953;

UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=59888 WHERE `entry`=272422; -- Gentle's Spellbook

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=59888 WHERE (`Entry`=124953 AND `DifficultyID`=0); -- 124953 (Helena Gentle) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=59888 WHERE (`Entry`=128347 AND `DifficultyID`=0); -- 128347 (Hexbound Snarler) - CanSwim

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 124953;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(124953, 0, 0, 'I will show you the coven\'s power!', 12, 0, 100, 0, 0, 97672, 133717, 0, 'Helena Gentle'),
(124953, 1, 0, 'Our power is ancient. You will fall!', 12, 0, 100, 0, 0, 97673, 133718, 0, 'Helena Gentle'),
(124953, 2, 0, 'You cannot stop... my curse...', 12, 0, 100, 0, 0, 97674, 133719, 0, 'Helena Gentle to Player');

-- Target condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceEntry` IN (257877));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 257877, 0, 0, 51, 0, 5, 128347, 0, '', 0, 'Potential target of the spell is TYPEID_UNIT, entry is 128347');
