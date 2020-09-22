UPDATE `creature_template` SET `ScriptName`= 'npc_bwd_lord_victor_nefarius' WHERE `entry`= 48964;
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 57478;

DELETE FROM `creature_text` WHERE `CreatureID`= 48964 AND `GroupID` > 4;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(48964, 5, 0, 'Welcome to my personal sanctum, heroes! I hope you find the accommodations to your liking. Herein you will find many of my failed experiments and ultimately my greatest triumph!', 14, 0, 100, 0, 0, 20090, 49415, ''),
(48964, 6, 0, 'Finally someone to deal with that unsightly pest! You have my thanks, \"heroes.\"', 14, 0, 100, 0, 0, 20085, 49410, ''),
(48964, 7, 0, 'That malfunctioning piece of junk was murder on the repair bills.', 14, 0, 100, 0, 0, 20086, 49411, 'Lord Victor Nefarius to Player'),
(48964, 8, 0, 'Impressive. You have managed to destroy one of my most horrific creations, a task I had thought impossible until now.', 14, 0, 100, 0, 0, 20088, 49413, ''),
(48964, 9, 0, 'Now that was really unnecessary.', 14, 0, 100, 0, 0, 20087, 49412, ''),
(48964, 10, 0, 'We never did see eye to eye... Good riddance I say!', 14, 0, 100, 0, 0, 20089, 49414, '');

UPDATE `creature_text` SET `TextRange`= 3 WHERE `CreatureID`= 48964;

SET @CGUID := 396406;
DELETE FROM `creature` WHERE `guid`= @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 48964, 669, 5094, 5094, 3, 169, 0, 0, 0, -61.6267356872558593, -224.701385498046875, 201.37677001953125, 3.228859186172485351, 7200, 0, 0, 0, 0, 0, 0, 33554496, 0, 15595); -- Lord Victor Nefarius (Area: Blackwing Descent - Difficulty: 4) (Auras: )

DELETE FROM `creature_addon` WHERE `guid`= @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `auras`) VALUES
(@CGUID+0, '41577');

-- Serverside Spells
DELETE FROM `spell_dbc` WHERE `Id`= 41577;
INSERT INTO `spell_dbc` (`Id`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `Comment`) VALUES
(41577, 1, 21, 1, 0x00000110, 0x10000000, 0x00000001, 0x00100000, '(Serverside/Non-DB2) Transform: Invisible Stalker');

DELETE FROM `spelleffect_dbc` WHERE `Id`= 160106;
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectAura`, `EffectBasePoints`, `EffectMiscValue`, `EffectMiscValueB`, `EffectRadiusIndex`, `EffectRadiusMaxIndex`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `SpellID`, `EffectIndex`, `Comment`) VALUES
(160106, 6, 56, 1, 57478, 0, 0, 0, 1, 0, 41577, 0, '');
