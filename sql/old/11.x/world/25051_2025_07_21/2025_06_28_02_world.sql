SET @CGUID := 6005163;

-- Creatures
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `StringId`, `VerifiedBuild`) VALUES
(@CGUID+0, 103662, 1501, 7805, 7805, '1,2,8,23,24', '0', 0, 0, 0, 3221.896728515625, 7534.16845703125, 22.26258468627929687, 0.978301584720611572, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 'amalgam_door_stalker_left', 60822), -- Secret Door Stalker (Area: Black Rook Hold - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+1, 103662, 1501, 7805, 7805, '1,2,8,23,24', '0', 0, 0, 0, 3219.341064453125, 7535.9443359375, 24.50200271606445312, 0.885492563247680664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 'amalgam_door_stalker_mid', 60822), -- Secret Door Stalker (Area: Black Rook Hold - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+2, 103662, 1501, 7805, 7805, '1,2,8,23,24', '0', 0, 0, 0, 3217.076416015625, 7537.67041015625, 22.50607109069824218, 0.794547736644744873, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 'amalgam_door_stalker_right', 60822); -- Secret Door Stalker (Area: Black Rook Hold - Difficulty: 0) CreateObject1 (Auras: )

DELETE FROM `creature_template_addon` WHERE `entry` IN (99090);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(99090, 0, 0, 0, 0, 0, 1, 0, 0, 9176, 0, 0, 0, ''); -- 99090 (Soul Echoes Stalker)

UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x20000100, `VerifiedBuild`=60822 WHERE (`Entry`=99090 AND `DifficultyID`=23); -- 99090 (Soul Echoes Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=98542 AND `DifficultyID`=23); -- 98542 (Amalgam of Souls) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1279 WHERE (`Entry`=99664 AND `DifficultyID`=23);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=99857 AND `DifficultyID`=23); -- 99857 (Lord Etheldrin Ravencrest) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=99858 AND `DifficultyID`=23); -- 99858 (Lady Velandras Ravencrest) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=99426 AND `DifficultyID`=23); -- 99426 (Staellis Rivermoor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x20000100, `VerifiedBuild`=60822 WHERE (`Entry`=103662 AND `DifficultyID`=0); -- 103662 (Secret Door Stalker) - Sessile, Floating

UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800, `unit_flags3`=0x41080001, `ScriptName`='npc_amalgam_of_souls_soul_echoes_stalker' WHERE `entry`=99090; -- Soul Echoes Stalker
UPDATE `creature_template` SET `unit_flags2`=0x800, `ScriptName`='boss_amalgam_of_souls' WHERE `entry`=98542; -- Amalgam of Souls
UPDATE `creature_template` SET `ScriptName`='npc_amalgam_of_souls_restless_soul' WHERE `entry`=99664;
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x80000, `AIName`='SmartAI' WHERE `entry`=99426; -- Staellis Rivermoor
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x80000, `ScriptName`='npc_amalgam_of_souls_lord_etheldrin_ravencrest' WHERE `entry`=99857; -- Lord Etheldrin Ravencrest
UPDATE `creature_template` SET `BaseAttackTime`=1500, `unit_flags2`=0x800, `unit_flags3`=0x80000, `AIName`='SmartAI' WHERE `entry`=99858; -- Lady Velandras Ravencrest
UPDATE `creature_template` SET `unit_flags3`=0x41000000 WHERE `entry`=103662; -- Secret Door Stalker

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (99426,99857,99858));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(99426, 1, 118562, 0, 0, 0, 0, 0, 0, 0, 0, 60822), -- Staellis Rivermoor
(99857, 1, 116571, 0, 0, 0, 0, 0, 0, 0, 0, 60822), -- Lord Etheldrin Ravencrest
(99858, 1, 29437, 0, 0, 0, 0, 0, 0, 0, 0, 60822); -- Lady Velandras Ravencrest

DELETE FROM `creature_summon_groups` WHERE `summonerId`=98542;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`, `Comment`) VALUES
(98542, 0, 0, 99664, 3265.507080078125, 7543.8681640625, 5.631319999694824218, 1.907930254936218261, 8, 0, 'Amalgam of Souls - Restless Souls'),
(98542, 0, 0, 99664, 3290.262939453125, 7574.5947265625, 5.631304740905761718, 2.955646991729736328, 8, 0, 'Amalgam of Souls - Restless Souls'),
(98542, 0, 0, 99664, 3286.51123046875, 7601.3115234375, 5.631319999694824218, 3.660738945007324218, 8, 0, 'Amalgam of Souls - Restless Souls'),
(98542, 0, 0, 99664, 3255.626708984375, 7622.0068359375, 5.631304740905761718, 4.62844085693359375, 8, 0, 'Amalgam of Souls - Restless Souls'),
(98542, 0, 0, 99664, 3228.8046875, 7616.51171875, 6.50103616714477539, 5.3057861328125, 8, 0, 'Amalgam of Souls - Restless Souls'),
(98542, 0, 0, 99664, 3212.127685546875, 7582.49462890625, 5.154406547546386718, 6.263723373413085937, 8, 0, 'Amalgam of Souls - Restless Souls'),
(98542, 0, 0, 99664, 3219.781005859375, 7560.11572265625, 5.68906402587890625, 0.588002622127532958, 8, 0, 'Amalgam of Souls - Restless Souls');

-- Areatriggers
UPDATE `areatrigger_template` SET `VerifiedBuild`=60822 WHERE (`Id`=9899 AND `IsCustom`=0);
UPDATE `areatrigger_template` SET `VerifiedBuild`=60822 WHERE (`Id`=10015 AND `IsCustom`=0);

DELETE FROM `areatrigger_create_properties` WHERE (`Id` IN (5167, 5293) AND `IsCustom`=0);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(5167, 0, 9899, 0, 82, 0, 0, 0, 0, -1, 0, 39, NULL, 30000, 8, 0, 3.5, 3.5, 0, 0, 0, 0, 0, 0, 'at_amalgam_of_souls_swirling_scythe', 60822), -- Spell: 195254 (Swirling Scythe)
(5293, 0, 10015, 0, 4, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 'at_amalgam_of_souls_call_souls', 60822); -- Spell: 196925 (Call Souls)

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_amalgam_of_souls_soul_echoes_clone_caster', 'spell_amalgam_of_souls_soulgorge', 'spell_amalgam_of_souls_call_souls', 'spell_amalgam_of_souls_soul_burst');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(194981, 'spell_amalgam_of_souls_soul_echoes_clone_caster'),
(196930, 'spell_amalgam_of_souls_soulgorge'),
(196078, 'spell_amalgam_of_souls_call_souls'),
(196587, 'spell_amalgam_of_souls_soul_burst');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (98542, 99857);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(98542, 0, 0, 'Consume! Devour!', 14, 0, 100, 0, 0, 54518, 100957, 0, 'Amalgam of Souls'),
(98542, 1, 0, 'The harvest has come!', 14, 0, 100, 0, 0, 54516, 100995, 0, 'Amalgam of Souls'),
(98542, 2, 0, 'Leave this meager vessel, and join us...', 14, 0, 100, 0, 0, 54564, 100994, 0, 'Amalgam of Souls'),
(98542, 3, 0, 'I feed on your essence...', 14, 0, 100, 0, 0, 54522, 100993, 0, 'Amalgam of Souls'),
(98542, 4, 0, 'Ancient souls of the Black Rook, rise and join our chorus!', 14, 0, 100, 0, 0, 54563, 100997, 0, 'Amalgam of Souls'),
(98542, 5, 0, 'This energy... it is too much!', 14, 0, 100, 0, 0, 54521, 100998, 0, 'Amalgam of Souls'),
(99857, 0, 0, 'I... understand now. You... you must find Kur\'talos. You must put a stop to this.', 12, 0, 100, 0, 0, 54558, 101007, 0, 'Lord Etheldrin Ravencrest');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (196930, 205210, 205211, 205212);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 196930, 0, 0, 51, 0, 5, 98542, 0, '', 0, 0, 0, '', 'Spell \'Soulgorge\' can only hit \'Amalgam of Souls\''),
(13, 1, 205210, 0, 0, 58, 0, 0, 0, 0, 'amalgam_door_stalker_left', 0, 0, 0, '', 'Spell \'Secret Door Channel - Staellis Left\' can only hit \'Secret Door Stalker\''),
(13, 1, 205211, 0, 0, 58, 0, 0, 0, 0, 'amalgam_door_stalker_mid', 0, 0, 0, '', 'Spell \'Secret Door Channel - Lady V Mid\' can only hit \'Secret Door Stalker\''),
(13, 1, 205212, 0, 0, 58, 0, 0, 0, 0, 'amalgam_door_stalker_right', 0, 0, 0, '', 'Spell \'Secret Door Channel - Lord E Right\' can only hit \'Secret Door Stalker\'');

-- Conversation
DELETE FROM `conversation_actors` WHERE (`ConversationId`=754 AND `Idx` IN (2,1,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(754, 50270, 2, 99857, 0, 0, 0, 60822), -- Full: 0x204254BBA0618440000578000034D42F Creature/0 R4245/S1400 Map: 1501 (Black Rook Hold) Entry: 99857 (Lord Etheldrin Ravencrest) Low: 3462191
(754, 50272, 1, 99858, 0, 0, 0, 60822), -- Full: 0x204254BBA0618480000578000034D42F Creature/0 R4245/S1400 Map: 1501 (Black Rook Hold) Entry: 99858 (Lady Velandras Ravencrest) Low: 3462191
(754, 50273, 0, 99426, 0, 0, 0, 60822); -- Full: 0x204254BBA0611880000578000034D42F Creature/0 R4245/S1400 Map: 1501 (Black Rook Hold) Entry: 99426 (Staellis Rivermoor) Low: 3462191

DELETE FROM `conversation_line_template` WHERE `Id` IN (1792, 1791, 1790);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(1792, 0, 2, 0, 1, 60822),
(1791, 0, 1, 0, 0, 60822),
(1790, 0, 0, 0, 0, 60822);

DELETE FROM `conversation_template` WHERE `Id` IN (754);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `ScriptName`, `VerifiedBuild`) VALUES
(754, 1790, 0, 'conversation_amalgam_of_souls_outro', 60822);

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (99858, 99426) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(99858, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 90, 8, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Lady Velandras Ravencrest - Just Created - Set StandState: Kneel'),
(99426, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 90, 8, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Staellis Rivermoor - Just Created - Set StandState: Kneel');

DELETE FROM `instance_template` WHERE `map`=1501;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(1501, 0, 'instance_black_rook_hold');
