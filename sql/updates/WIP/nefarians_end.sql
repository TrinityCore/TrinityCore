-- Template Updates
-- Nefarian
UPDATE `creature_template` SET `ScriptName`= 'boss_nefarians_end' WHERE `entry`= 41376;
UPDATE `creature_template` SET `flags_extra`= 512 WHERE `entry` IN (41376, 51104, 51105, 51106);
-- Onyxia
UPDATE `creature_template` SET `ScriptName`= 'npc_nefarians_end_onyxia' WHERE `entry`= 41270;
UPDATE `creature_template` SET `unit_flags2`= 134219776 WHERE `entry`= 41270;

-- Lord Victor Nefarius
UPDATE `creature_template` SET `ScriptName`= 'npc_nefarians_end_lord_victor_nefarius' WHERE `entry`= 41379;
-- Orb of Culmination
UPDATE `gameobject_template` SET `ScriptName`= 'go_nefarians_end_orb_of_culmination' WHERE `entry`= 203254;


-- Spell Scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_bwd_dragon_orb',
'spell_nefarians_end_electrical_charge',
'spell_nefarians_end_lightning_discharge_triggered_periodic_aura');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(78219, 'spell_bwd_dragon_orb'),
(78220, 'spell_bwd_dragon_orb'),
(78949, 'spell_nefarians_end_electrical_charge'),
(95793, 'spell_nefarians_end_electrical_charge'),
(77832, 'spell_nefarians_end_lightning_discharge_triggered_periodic_aura');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (81198, 81159, 81174, 81176, 81158, 81175, 81177) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 81198, 0, 0, 31, 0, 3, 42844, 0, 0, 0, '', 'Electrocute - Target Invisible Stalker'),
(13, 1, 81159, 0, 0, 31, 0, 3, 41270, 0, 0, 0, '', 'Chains A Steel - Target Onyxia'),
(13, 1, 81174, 0, 0, 31, 0, 3, 41270, 0, 0, 0, '', 'Chains B Steel - Target Onyxia'),
(13, 1, 81176, 0, 0, 31, 0, 3, 41270, 0, 0, 0, '', 'Chains C Steel - Target Onyxia'),
(13, 1, 81158, 0, 0, 31, 0, 3, 41270, 0, 0, 0, '', 'Chains A Lightning - Target Onyxia'),
(13, 1, 81175, 0, 0, 31, 0, 3, 41270, 0, 0, 0, '', 'Chains B Lightning - Target Onyxia'),
(13, 1, 81177, 0, 0, 31, 0, 3, 41270, 0, 0, 0, '', 'Chains C Lightning - Target Onyxia');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (41379, 41376);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- Nefarian
(41376, 0, 0, 'The air crackles with electricity!', 41, 0, 100, 0, 0, 0, 43521, 'Nefarian to Player'),
-- Lord Victor Nefarius
(41379, 0, 0, 'Ha ha ha ha ha! The heroes have made it to the glorious finale. I take it you are in good spirits? Prepared for the final battle? Then gaze now upon my ultimate creation! RISE, SISTER!', 14, 0, 100, 1, 0, 20066, 41762, 'Lord Victor Nefarius to Player'),
(41379, 1, 0, 'Behold the brood mother, Onyxia, REBORN! Perhaps my finest work.', 14, 0, 100, 22, 0, 20070, 49416, 'Lord Victor Nefarius to Player'),
(41379, 2, 0, 'My dearest sibling, do you hunger? THEN FEAST UPON OUR ENEMIES!', 14, 0, 100, 22, 0, 20071, 49417, 'Lord Victor Nefarius to Player');
UPDATE `creature_text` SET `TextRange`= 3 WHERE `CreatureID` IN (41379, 41376);

-- Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (35592, 41376, 51104, 51105, 51106, 41270);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES
(35592, 0, '78173'),
-- Nefarian
(41376, 1, '94132'),
(51104, 1, '94132'),
(51105, 1, '94132'),
(51106, 1, '94132'),
-- Onyxia
(41270, 1, '94132 29266');

-- Spawn Groups
DELETE FROM `creature_summon_groups` WHERE `summonerId`= 41376 AND `summonerType`= 0;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(41376, 0, 0, 41270, -107.324, -224.6647, -7.330293, 3.141593, 8, 0),
(41376, 0, 0, 42844, -143.6852, -249.2931, -5.34586, 3.141593, 8, 0),
(41376, 0, 0, 42844, -111.4442, -268.6278, -5.34586, 3.141593, 8, 0),
(41376, 0, 0, 42844, -67.22468, -244.3953, -5.34586, 3.141593, 8, 0),
(41376, 0, 0, 42844, -66.85265, -205.3938, -5.34586, 3.141593, 8, 0),
(41376, 0, 0, 42844, -108.5982, -180.2777, -5.34586, 3.141593, 8, 0),
(41376, 0, 0, 42844, -143.3391, -199.5975, -5.34586, 3.141593, 8, 0),
(41376, 0, 0, 42844, -107.2374, -224.5609, -7.330293, 3.141593, 8, 0),
(41376, 0, 0, 42098, -141.3331, -224.6247, 1.512104, 0, 8, 0),
(41376, 0, 0, 42098, -90.35625, -253.4714, 1.46139, 2.111848, 8, 0),
(41376, 0, 0, 42098, -90.22045, -195.6071, 1.505078, 4.118977, 8, 0);

-- Spawns
SET @OGUID := 239510;
DELETE FROM `gameobject` WHERE `guid`= @OGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 203254, 669, 5094, 0, 15, 169, 0, -27.84375, -224.4774, 63.30268, 6.265733, 0, 0, -0.00872612, 0.9999619, 7200, 255, 1, 26365); -- Orb of Culmination (Area: 0 - Difficulty: 6)

SET @CGUID := 259779;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 35592, 669, 5094, 0, 15, 169, 0, 0, 0, -27.80208, -224.4497, 63.34686, 6.248279, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Invisible Stalker (Float, Uninteractible, GiganticAOI) (Area: 0 - Difficulty: 6) (Auras: 78173 - Dragon Orb)
(@CGUID+1, 42098, 669, 5094, 0, 15, 169, 0, 0, 0, -166.655, -224.602, 40.48163, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365); -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating) (Area: 0 - Difficulty: 6) (Auras: 78495 - Aura of Dread)

DELETE FROM `creature_addon` WHERE `guid`= @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `auras`) VALUES
(@CGUID+1, '78495');

-- Spawn Groups
DELETE FROM `instance_spawn_groups` WHERE `instanceMapId`= 669;
UPDATE `spawn_group_template` SET `groupFlags`= 4 WHERE `groupId`= 402;
DELETE FROM `spawn_group` WHERE `groupId`= 402 AND `spawnType`= 1 AND `spawnId`= @OGUID;
DELETE FROM `spawn_group` WHERE `groupId`= 402 AND `spawnType`= 0 AND `spawnId` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(402, 1, @OGUID),
(402, 0, @CGUID+0),
(402, 0, @CGUID+1);

-- Npc Text
UPDATE `npc_text` SET `text0_0`= 'A large humanoid hand print is embedded on the surface of the orb. A soft green glow seems to pulse within.', `BroadcastTextID0`= 41760 WHERE `ID`= 16139;
