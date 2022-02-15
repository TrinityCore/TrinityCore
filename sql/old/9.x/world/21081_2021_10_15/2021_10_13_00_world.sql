-- 
SET @OGUID := 600015;
SET @WLSID := 100000;

DELETE FROM `gameobject` WHERE `guid`=@OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 341833, 2297, 12952, 12951, '0', 0, 0, 529.26043701171875, -2124.81591796875, 840.85693359375, 0, 0, 0, 0, 1, 120, 255, 1, 40120); -- Death Gate (Area: The Frozen Throne - Difficulty: 0)

DELETE FROM `serverside_spell` WHERE `Id`=316990 AND `DifficultyID`=0;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `SpellName`, `RangeIndex`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`) VALUES
(316990, 0, '"Defender of Azeroth": 02 Death Gate Selector', 1, 0x29000180, 0x00000420, 0x10484004, 0x10030200, 0x00800080, 0x00060008, 0x00001200);

DELETE FROM `serverside_spell_effect` WHERE `SpellID`=316990 AND `EffectIndex`=0 AND `DifficultyID`=0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectMiscValue1`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(316990, 0, 0, 3, 0, 1, 0); -- Death Gate Selector

DELETE FROM `spell_script_names` WHERE `ScriptName` IN('spell_defender_of_azeroth_death_gate_selector', 'spell_defender_of_azeroth_speak_with_mograine');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(316983, 'spell_defender_of_azeroth_speak_with_mograine'),
(316990, 'spell_defender_of_azeroth_death_gate_selector');

DELETE FROM `spell_target_position` WHERE `ID` IN(316999, 317000) AND `EffectIndex`=0;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(316999, 0, 0, -9088.990234375, 415.220001220703125, 92.1699981689453125, 40120), -- Spell: 316999 (Death Gate) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(317000, 0, 1, 1370.1600341796875, -4371.6201171875, 26.04999923706054687, 40443); -- Spell: 317000 (Death Gate) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

DELETE FROM `world_safe_locs` WHERE `ID` IN(@WLSID+0);
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@WLSID+0, 2297, 544.54865, -2124.7031, 840.85693, 3.141906976699829101, 'Icecrown Citadel - Allied Race DK Intro - GY');

DELETE FROM `graveyard_zone` WHERE `ID`=@WLSID+0 AND `GhostZone`=12952;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Faction`, `Comment`) VALUES
(@WLSID+0, 12952, 0, 'Icecrown Citadel - Allied Race DK Intro - GY');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=161709;
DELETE FROM `smart_scripts` WHERE `entryorguid`=161709 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `event_type`, `event_param1`, `action_type`, `action_param1`, `action_param2`, `target_type`, `target_param1`, `comment`) VALUES 
(161709, 0, 0, 62, 25082, 85, 316983, 0, 1, 0, 'Darion Mograine - On Gossip Option Select - Invoker Cast - Self'),
(161709, 0, 1, 62, 25082, 143, 13254, 1, 7, 0, 'Darion Mograine - On Gossip Option Select - Create Conversation - Invoker'),
(161709, 0, 2, 62, 25082, 72, 0, 0, 7, 0, 'Darion Mograine - On Gossip Option Select - Close Gossip - Invoker');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=316983;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ConditionTarget`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `Comment`) VALUES
(13, 1, 316983, 0, 0, 31, 3, 161709, 0, 'Defender of Azeroth: Speak.. should only hit creatures with entry 161709');

-- some fixups
DELETE FROM `creature_questender` WHERE `id`=163016 AND `quest` IN(58902, 58903);
UPDATE `conditions` SET `ConditionValue1`=395159 WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=25082 AND `ConditionTypeOrReference`=48 AND `ElseGroup`=1;
UPDATE `conditions` SET `ConditionValue1`=395215 WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=25082 AND `ConditionTypeOrReference`=48 AND `ElseGroup`=2;
