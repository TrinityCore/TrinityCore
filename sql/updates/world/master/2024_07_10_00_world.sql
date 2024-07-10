SET @OGUID := 7000361;
SET @CGUID := 7001367;
SET @TGUID = 35;

SET @NPCTEXTID := 570044;

DELETE FROM `transports` WHERE `guid` IN (@TGUID+0, @TGUID+1);
INSERT INTO `transports` (`guid`, `entry`, `name` , `ScriptName`) VALUES
(@TGUID+0, 278407, 'Sword of Dawn', 'transport_seething_shore'),
(@TGUID+1, 279254, 'The warbringer', 'transport_seething_shore');

UPDATE `world_safe_locs` SET `TransportSpawnId`=@TGUID+0 WHERE `ID` = 6337;
UPDATE `world_safe_locs` SET `TransportSpawnId`=@TGUID+1 WHERE `ID` = 6380;

DELETE FROM `battleground_template` WHERE `ID` = 894;
INSERT INTO `battleground_template` (`ID`, `AllianceStartLoc`, `HordeStartLoc`, `StartMaxDist`, `Weight`, `Comment`) VALUES
(894, 6337, 6380, 0, 1, 'Seething Shore');

DELETE FROM `battleground_scripts` WHERE `MapId` = 1803;
INSERT INTO `battleground_scripts` (`MapId`, `ScriptName`) VALUES
(1803, 'battleground_seething_shore');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_bg_seething_shore_activate_azerite', 'spell_bg_seething_shore_azerite_geyser', 'spell_bg_seething_shore_rocket_parachute_trigger', 'spell_bg_seething_shore_rocket_parachute_ground_check', 'spell_bg_seething_shore_parachute', 'spell_bg_seething_shore_speed_up');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(248688, 'spell_bg_seething_shore_activate_azerite'),
(248668, 'spell_bg_seething_shore_azerite_geyser'),
(269779, 'spell_bg_seething_shore_parachute'),
(250917, 'spell_bg_seething_shore_rocket_parachute_trigger'),
(250921, 'spell_bg_seething_shore_rocket_parachute_ground_check'),
(294701, 'spell_bg_seething_shore_speed_up');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=248688 AND `ConditionTypeOrReference`=31;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
(13, 1, 248688, 31, 3, 125253, 'Activate Azerite - Only Target Azerute Fissure');

DELETE FROM `graveyard_zone` WHERE `ID` IN (6337, 6380);
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(6337, 9136, 'Seething Shore - Alliance Airship'),
(6380, 9136, 'Seething Shore - Horde Airship');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 27 AND `SourceEntry` IN (6337, 6380);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `NegativeCondition`, `Comment`) VALUES
(27, 6337, 9136, 0, 6, 469, 0, 0, 'Graveyard - Seething Shore - Alliance Airship - Team Alliance'),
(27, 6380, 9136, 0, 6, 67, 0, 0, 'Graveyard - Seething Shore - Horde Airship - Team Horde');

DELETE FROM `world_state` WHERE `ID` IN (13846, 13844, 13845);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `Comment`) VALUES
(13846, 1500, '1803', 'Seething Shore - Max Score'),
(13844, 0, '1803', 'Seething Shore - Horde Score'),
(13845, 0, '1803', 'Seething Shore - Alliance Score');

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (16508));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `SpellForVisuals`, `ScriptName`, `VerifiedBuild`) VALUES
(16508, 0, 20909, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 300000, 0, 4, 4, 0, 0, 0, 0, 0, 0, 294566, 'at_bg_seething_shore_haste_rune_buff', 54205); -- Spell: 295663 (Create Haste Rune Buff Area Trigger)

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (20909));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(20909, 0, 0, 54205);

DELETE FROM `vehicle_template_accessory` WHERE (`seat_id`=1 AND `entry`=133532) OR (`seat_id`=0 AND `entry` IN (133220, 133266));
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(133532, 133533, 1, 1, 'Air Supplies - Air Supplies', 7, 0), -- Air Supplies - Air Supplies
(133220, 93493, 0, 0, 'Goblin Hot Air Balloon - Goblin Sky Bomber', 7, 0), -- Goblin Hot Air Balloon - Goblin Sky Bomber
(133266, 133267, 0, 0, 'Byron Holungo - Byron Holungo', 7, 0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN(133532, 133220, 133266);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(133532, 46598, 1, 1),
(133220, 43671, 1, 1),
(133266, 46598, 1, 1);

UPDATE `gameobject_template` SET `size`=0.949999988079071044, `Data9`=1, `VerifiedBuild`=54205 WHERE `entry`=281226; -- Horde Airship Prep Collision
UPDATE `gameobject_template` SET `ScriptName`='go_bg_seething_shore_azerite' WHERE `entry` IN (272471, 281306, 281307);
UPDATE `gameobject_template` SET `ScriptName` = 'transport_seething_shore' WHERE `entry` IN (278407, 279254);

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (272471 /*Azerite*/, 281306 /*Azerite*/, 281307 /*Azerite*/, 281224 /*Alliance Airship Prep Collision*/, 281226 /*Horde Airship Prep Collision*/, 278407, 279254);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(272471, 0, 32, 0, 0), -- Azerite
(281306, 0, 32, 0, 0), -- Azerite
(281307, 0, 32, 0, 0), -- Azerite
(281224, 1375, 32, 0, 0), -- Alliance Airship Prep Collision
(281226, 1375, 32, 0, 0), -- Horde Airship Prep Collision
(278407, 0, 1048616, 0, 0), -- Sword of Dawn
(279254, 0, 1048616, 0, 0); -- The Warbringer

UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=206565; -- Food Buff
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=206566; -- Speed Buff
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=206564; -- Berserk Buff

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 281026, 1857, 9136, 9136, '0', '0', 0, -4.21496200561523437, -18.1041221618652343, 34.19417190551757812, 0, 0, 0, 0, 1, 7200, 255, 1, 54205), -- War Drums (Area: Seething Shore - Difficulty: 0) CreateObject1
(@OGUID+1, 281026, 1857, 9136, 9136, '0', '0', 0, 9.989482879638671875, -18.658599853515625, 34.79845428466796875, 0, 0, 0, 0, 1, 7200, 255, 1, 54205), -- War Drums (Area: Seething Shore - Difficulty: 0) CreateObject1
(@OGUID+2, 278775, 1856, 9136, 9136, '0', '0', 0, 13.60289192199707031, -4.72770023345947265, 20.79595565795898437, 3.103320121765136718, 0, 0, 0.99981689453125, 0.019135080277919769, 7200, 255, 1, 54205), -- Alliance Banner (Area: Seething Shore - Difficulty: 0) CreateObject1
(@OGUID+3, 278775, 1856, 9136, 9136, '0', '0', 0, 13.49236011505126953, 5.149053096771240234, 20.79655265808105468, 3.18142867088317871, 0, 0, -0.9998016357421875, 0.019916549324989318, 7200, 255, 1, 54205), -- Alliance Banner (Area: Seething Shore - Difficulty: 0) CreateObject1
(@OGUID+4, 281226, 1857, 9136, 9136, '0', '0', 0, 1, -1, 1, 0, 0, 0, 0, 1, 7200, 255, 1, 54205), -- Horde Airship Prep Collision (Area: Seething Shore - Difficulty: 0) CreateObject1
(@OGUID+5, 281224, 1856, 9136, 9136, '0', '0', 0, 1, 1, 1, 0, 0, 0, 0, 1, 7200, 255, 1, 54205); -- Alliance Airship Prep Collision (Area: Seething Shore - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;

UPDATE `creature_template` SET `unit_flags`=0, `unit_flags2`=67110912, `unit_flags3`=16777216 WHERE `entry`=125253; -- Azerite Fissure
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=133223; -- Adder
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=131776; -- Jeron Emberfall
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=132800; -- Mavvus Gingersnap
UPDATE `creature_template` SET `unit_flags`=0, `unit_flags3`=8388608 WHERE `entry`=133059; -- General Harris
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=130682; -- Rylai Crestfall
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=133056; -- Xander Silberman
UPDATE `creature_template` SET `unit_flags`=33554432, `unit_flags2`=0 WHERE `entry`=132702; -- Alliance Gunship Cannon
UPDATE `creature_template` SET `unit_flags`=768, `ScriptName`='npc_bg_seething_shore_commander' WHERE `entry`=131773; -- Nathanos Blightcaller
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=132972; -- Skyguard Cannoneer
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=132739; -- Feezzel Gingersnap
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=130677; -- Gunship Grunt
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=130540; -- Skyguard Marine
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=133048; -- Tevs Rusthammer
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=130542; -- Deckhand
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=130537; -- Sergeant Blackwell
UPDATE `creature_template` SET `unit_flags`=0, `unit_flags2`=67110912, `unit_flags3`=16777216 WHERE `entry`=125253; -- Azerite Fissure
UPDATE `creature_template` SET `unit_flags`=512, `ScriptName`='npc_bg_seething_shore_commander' WHERE `entry`=130532; -- Master Mathias Shaw
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=133047; -- Peon
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=133042; -- Sky Marshall Gabriel
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=130535; -- Sergeant Schmidt
UPDATE `creature_template` SET `unit_flags`=33554432, `unit_flags3`=25165825, `flags_extra` = `flags_extra`|0x80 WHERE `entry`=125269; -- Controller
UPDATE `creature_template` SET `unit_flags`=512, `unit_flags3`=8388608 WHERE `entry`=93493; -- Goblin Sky Bomber
UPDATE `creature_template` SET `unit_flags`=0, `unit_flags3`=16777216, `ScriptName`='npc_bg_seething_shore_air_supply_ground_dummy' WHERE `entry`=133542; -- Air Supply Ground Dummy
UPDATE `creature_template` SET `unit_flags`=33554944, `unit_flags3`=16777217 WHERE `entry`=133220; -- Goblin Hot Air Balloon
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=131149; -- Flying Machine
UPDATE `creature_template` SET `unit_flags`=33554432, `unit_flags3`=16777216 WHERE `entry`=133225; -- Frog
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=133224; -- Beetle
UPDATE `creature_template` SET `unit_flags`=33554432, `unit_flags3`=16777217 WHERE `entry`=133221; -- Skittering Softshell
UPDATE `creature_template` SET `unit_flags`=33554432, `unit_flags3`=16777216 WHERE `entry`=133222; -- Spider
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=133049; -- Gunship Warguard
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=132718; -- Sky Marshal Damarcus
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=133044; -- Grand Marshal Tremblade
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=133045; -- War Drummer
UPDATE `creature_template` SET `unit_flags`=33554432, `unit_flags2`=0 WHERE `entry`=133046; -- Horde Gunship Cannon
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=133043; -- High Warlord Volrath
UPDATE `creature_template` SET `unit_flags2`=67110912, `ScriptName`='npc_bg_seething_shore_air_supplies_crate', `AIName` = '' WHERE `entry`=133533; -- Air Supplies
UPDATE `creature_template` SET `unit_flags`=768, `unit_flags3`=16777216 WHERE `entry`=133266; -- Byron Holungo
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=133267; -- Byron Holungo

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x80, `ScriptName`='npc_bg_seething_shore_vignette_dummy' WHERE `entry`=129344;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 133533 AND `SourceId` = 0;

UPDATE `creature_template` SET `unit_flags2`=0, `ScriptName`='npc_bg_seething_shore_air_supplies_drop' WHERE `entry`=133532; -- Air Supplies
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=132960; -- Battle Alchemist Broadoak

UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306624, `VerifiedBuild`=54205 WHERE (`Entry`=133533 AND `DifficultyID`=0); -- Air Supplies
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=54205 WHERE (`Entry`=133532 AND `DifficultyID`=0); -- Air Supplies
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54205 WHERE (`Entry`=88238 AND `DifficultyID`=0); -- Alliance Spirit Guide
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54205 WHERE (`Entry`=88239 AND `DifficultyID`=0); -- Horde Spirit Guide
UPDATE `creature_template_difficulty` SET `ContentTuningID`=971, `StaticFlags1`=536871168, `VerifiedBuild`=54205 WHERE (`Entry`=129344 AND `DifficultyID`=0); -- Vignette Dummy

UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=131776 AND `DifficultyID`=0); -- Jeron Emberfall
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=132800 AND `DifficultyID`=0); -- Mavvus Gingersnap
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=133059 AND `DifficultyID`=0); -- General Harris
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=130682 AND `DifficultyID`=0); -- Rylai Crestfall
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=133056 AND `DifficultyID`=0); -- Xander Silberman
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54205 WHERE (`Entry`=132702 AND `DifficultyID`=0); -- Alliance Gunship Cannon
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=131773 AND `DifficultyID`=0); -- Nathanos Blightcaller
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=132972 AND `DifficultyID`=0); -- Skyguard Cannoneer
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=132739 AND `DifficultyID`=0); -- Feezzel Gingersnap
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=130677 AND `DifficultyID`=0); -- Gunship Grunt
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=130540 AND `DifficultyID`=0); -- Skyguard Marine
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54205 WHERE (`Entry`=133048 AND `DifficultyID`=0); -- Tevs Rusthammer
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=130537 AND `DifficultyID`=0); -- Sergeant Blackwell
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54205 WHERE (`Entry`=130532 AND `DifficultyID`=0); -- Master Mathias Shaw
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=133047 AND `DifficultyID`=0); -- Peon
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=130535 AND `DifficultyID`=0); -- Sergeant Schmidt
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54205 WHERE (`Entry`=125269 AND `DifficultyID`=0); -- Controller
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306624, `VerifiedBuild`=54205 WHERE (`Entry`=93493 AND `DifficultyID`=0); -- Goblin Sky Bomber
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=54205 WHERE (`Entry`=133220 AND `DifficultyID`=0); -- Goblin Hot Air Balloon
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306368, `StaticFlags3`=262144, `VerifiedBuild`=54205 WHERE (`Entry`=131149 AND `DifficultyID`=0); -- Flying Machine
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=133222 AND `DifficultyID`=0); -- Spider
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=133049 AND `DifficultyID`=0); -- Gunship Warguard
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=132718 AND `DifficultyID`=0); -- Sky Marshal Damarcus
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=133045 AND `DifficultyID`=0); -- War Drummer
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54205 WHERE (`Entry`=133046 AND `DifficultyID`=0); -- Horde Gunship Cannon
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=133043 AND `DifficultyID`=0); -- High Warlord Volrath
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306624, `VerifiedBuild`=54205 WHERE (`DifficultyID`=0 AND `Entry` IN (133266,133267)); -- Byron Holungo

DELETE FROM `creature_template_addon` WHERE `entry` IN (125253, 133533, 133532, 133220, 133221, 131149, 93493, 132702, 133046, 133047, 132972);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(125253, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 125253 (Azerite Fissure)
(133533, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '87992 115048 92406'), -- 133533 (Air Supplies) - Crate State - Rope Beam
(133532, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Air Supplies
(133220, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Goblin Hot Air Balloon
(133221, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123168'), -- Skittering Softshell - 123168 - Mod Scale 115-120%
(131149, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Flying Machine
(93493, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Goblin Sky Bomber
(132702, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Alliance Gunship Cannon
(133046, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Horde Gunship Cannon
(133047, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '261772'), -- Peon - 261772 - Hold Torch
(132972, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '261772'); -- Skyguard Cannoneer - 261772 - Hold Torch

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+132;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+28, 125253, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1343.720458984375, 2919.94970703125, 32.86999130249023437, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Azerite Fissure (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+32, 125253, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1390.2447509765625, 2570.76904296875, 6.463711261749267578, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Azerite Fissure (Area: Seething Shore - Difficulty: 0) CreateObject1
(@CGUID+36, 125253, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1257.40625, 2882.73095703125, 27.95147514343261718, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Azerite Fissure (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+41, 125253, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1361.732666015625, 2643.2666015625, 4.467899322509765625, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Azerite Fissure (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+45, 125253, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1441.05908203125, 2700.151123046875, 9.504968643188476562, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Azerite Fissure (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+66, 125253, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1454.0850830078125, 2598.380126953125, 15.20614147186279296, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Azerite Fissure (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+82, 125253, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1126.6492919921875, 2781.23876953125, 30.86106491088867187, 1.093352198600769042, 7200, 10, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Azerite Fissure (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+112, 125253, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1461.357666015625, 2823.23779296875, 31.6768798828125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Azerite Fissure (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+115, 125253, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1243.154541015625, 2721.46533203125, 11.90171432495117187, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Azerite Fissure (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+118, 125253, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1339.5555419921875, 2785.6806640625, 2.559282541275024414, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Azerite Fissure (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+121, 125253, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1259.1614990234375, 2571.4228515625, 8.586249351501464843, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Azerite Fissure (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+127, 125253, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1113.923583984375, 2886.9931640625, 38.45600128173828125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205); -- Azerite Fissure (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `StringId`, `VerifiedBuild`) VALUES
(@CGUID+18, 133542, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1398.7603759765625, 2728.994873046875, 13.15371513366699218, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 'air_supply_ground_dummy_1', 54205), -- Air Supply Ground Dummy (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+19, 133542, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1226.2117919921875, 2935.498291015625, 55.46087265014648437, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 'air_supply_ground_dummy_2', 54205), -- Air Supply Ground Dummy (Area: Seething Shore - Difficulty: 0) CreateObject1
(@CGUID+20, 133542, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1226.2066650390625, 2828.38720703125, 30.05081939697265625, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 'air_supply_ground_dummy_3', 54205), -- Air Supply Ground Dummy (Area: Seething Shore - Difficulty: 0) CreateObject1
(@CGUID+59, 133542, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1384.6788330078125, 2848.819580078125, 21.447784423828125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 'air_supply_ground_dummy_4', 54205), -- Air Supply Ground Dummy (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+107, 133542, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1323.0850830078125, 2629.416748046875, 0.848163008689880371, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 'air_supply_ground_dummy_5', 54205), -- Air Supply Ground Dummy (Area: Seething Shore - Difficulty: 0) CreateObject1
(@CGUID+108, 133542, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1423.732666015625, 2871.681396484375, 37.09548568725585937, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 'air_supply_ground_dummy_6', 54205); -- Air Supply Ground Dummy (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: )

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 133043, 1857, 9136, 9136, '0', '0', 0, 0, 1, 48.26582717895507812, -0.31279590725898742, 30.178802490234375, 3.185770273208618164, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- High Warlord Volrath (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 164310 - Ashran Lane Mob Scaling Aura) (possible waypoints or random movement)
(@CGUID+1, 133046, 1857, 9136, 9136, '0', '0', 0, 0, 0, -3.8485107421875, 29.91275787353515625, 34.82189178466796875, 1.578369140625, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Horde Gunship Cannon (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+2, 133045, 1857, 9136, 9136, '0', '0', 0, 0, 1, -4.36667919158935546, -19.4284820556640625, 34.2917022705078125, 1.542391896247863769, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- War Drummer (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase) (possible waypoints or random movement)
(@CGUID+3, 133044, 1856, 9136, 9136, '0', '0', 0, 0, 1, 44.0166168212890625, 0.043116465210914611, 25.20822525024414062, 3.087687015533447265, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Grand Marshal Tremblade (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+4, 132718, 1856, 9136, 9136, '0', '0', 0, 0, 1, -13.2925615310668945, 2.026167631149291992, 24.43621826171875, 2.166225433349609375, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Sky Marshal Damarcus (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+5, 133049, 1857, 9136, 9136, '0', '0', 0, 0, 1, 12.51219940185546875, 4.569972038269042968, 34.66072463989257812, 3.447937965393066406, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Gunship Warguard (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+6, 133222, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1454.962646484375, 2798.11962890625, 24.64184951782226562, 4.078551292419433593, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Spider (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+7, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1335.60205078125, 2835.762451171875, 1.034905314445495605, 0.90386199951171875, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+8, 133222, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1444.7198486328125, 2795.10693359375, 21.22745704650878906, 5.819538116455078125, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Spider (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+9, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1346.901123046875, 2611.02783203125, -0.78168416023254394, 3.918522834777832031, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+10, 133222, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1441.227294921875, 2821.525390625, 30.82892990112304687, 2.533825397491455078, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Spider (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+11, 133224, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1148.4600830078125, 2761.30908203125, 25.55109405517578125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Beetle (Area: Seething Shore - Difficulty: 0) CreateObject1
(@CGUID+12, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1362.754150390625, 2599.63134765625, 0.279442250728607177, 2.084863901138305664, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+13, 133224, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1137.9375, 2791.780517578125, 30.27435302734375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Beetle (Area: Seething Shore - Difficulty: 0) CreateObject1
(@CGUID+14, 133225, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1284.3316650390625, 2887.61279296875, 26.73175048828125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Frog (Area: Seething Shore - Difficulty: 0) CreateObject1
(@CGUID+15, 133224, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1102.4322509765625, 2777.553955078125, 27.03694343566894531, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Beetle (Area: Seething Shore - Difficulty: 0) CreateObject1
(@CGUID+16, 131149, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1112.013427734375, 2509.376953125, 156.48406982421875, 1.701693654060363769, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Flying Machine (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+17, 133220, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1470.59033203125, 2627.364501953125, 513.9229736328125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Goblin Hot Air Balloon (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+21, 125269, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1399.68408203125, 2766.31689453125, 3.485144376754760742, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Controller (Area: Seething Shore - Difficulty: 0) CreateObject1
(@CGUID+22, 130535, 1856, 9136, 9136, '0', '0', 0, 0, 1, 16.10815811157226562, -2.13068008422851562, 20.50499343872070312, 3.127832651138305664, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Sergeant Schmidt (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+23, 133042, 1856, 9136, 9136, '0', '0', 0, 0, 0, 42.8487701416015625, 3.690071582794189453, 25.19219970703125, 4.270403861999511718, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Sky Marshall Gabriel (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+24, 133047, 1857, 9136, 9136, '0', '0', 0, 0, 0, 15.05074405670166015, 25.7812652587890625, 35.46322250366210937, 0.778234124183654785, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Peon (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 261772 - Hold Torch) (possible waypoints or random movement)
(@CGUID+25, 133222, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1485.2791748046875, 2802.49169921875, 34.7978973388671875, 5.265888214111328125, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Spider (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+26, 130532, 1856, 9136, 9136, '0', '0', 0, 0, 1, -13.9552288055419921, -0.343994140625, 24.50033760070800781, 1.611735463142395019, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Master Mathias Shaw (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+27, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1347.7705078125, 2554.14306640625, 0.536015212535858154, 5.455928325653076171, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+29, 133047, 1857, 9136, 9136, '0', '0', 0, 0, 0, -1.10877609252929687, 25.59661293029785156, 34.53367233276367187, 2.613483190536499023, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Peon (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 261772 - Hold Torch) (possible waypoints or random movement)
(@CGUID+30, 133046, 1857, 9136, 9136, '0', '0', 0, 0, 0, -23.2864723205566406, 27.40225601196289062, 34.42829132080078125, 1.527348518371582031, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Horde Gunship Cannon (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+31, 133045, 1857, 9136, 9136, '0', '0', 0, 0, 1, 10.22540664672851562, -19.5489559173583984, 34.92747879028320312, 1.77327275276184082, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- War Drummer (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase) (possible waypoints or random movement)
(@CGUID+33, 130537, 1856, 9136, 9136, '0', '0', 0, 0, 1, 15.81837844848632812, 2.732185125350952148, 20.50688362121582031, 3.041016578674316406, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Sergeant Blackwell (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+34, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1229.1431884765625, 2705.036376953125, 5.220393657684326171, 2.160965204238891601, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+35, 133225, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1218.970458984375, 2877.0078125, 26.54184150695800781, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Frog (Area: Seething Shore - Difficulty: 0) CreateObject1
(@CGUID+37, 130542, 1856, 9136, 9136, '0', '0', 0, 0, 1, 29.67688369750976562, 0.061542503535747528, 23.45696258544921875, 0.051342017948627471, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Deckhand (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+38, 133049, 1857, 9136, 9136, '0', '0', 0, 0, 1, 12.35111045837402343, -4.23962259292602539, 34.659393310546875, 2.792168140411376953, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Gunship Warguard (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+39, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1333.9249267578125, 2588.321044921875, 0.493305563926696777, 3.938067436218261718, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+40, 133048, 1857, 9136, 9136, '0', '0', 0, 0, 1, 43.07158660888671875, -5.18361282348632812, 30.178802490234375, 2.774509906768798828, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Tevs Rusthammer (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+42, 130540, 1856, 9136, 9136, '0', '0', 0, 0, 1, -14.4786109924316406, 11.64074325561523437, 20.49090194702148437, 1.578669667243957519, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Skyguard Marine (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+43, 133222, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1475.0546875, 2807.7314453125, 30.64089775085449218, 5.247282028198242187, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Spider (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+44, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1349.03955078125, 2590.06005859375, 0.705318689346313476, 1.874322056770324707, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+46, 133222, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1435.8787841796875, 2825.154052734375, 33.8293609619140625, 5.118026256561279296, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Spider (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+47, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1374.21533203125, 2551.144775390625, 0.400018572807312011, 1.994273304939270019, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+48, 130677, 1857, 9136, 9136, '0', '0', 0, 0, 1, -35.1225700378417968, -21.6558418273925781, 34.131591796875, 0.737916350364685058, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Gunship Grunt (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+49, 132739, 1856, 9136, 9136, '0', '0', 0, 0, 0, -58.6527900695800781, -2.40379309654235839, 23.48108291625976562, 5.089344978332519531, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Feezzel Gingersnap (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+50, 130677, 1857, 9136, 9136, '0', '0', 0, 0, 1, -33.2793502807617187, 21.268218994140625, 34.15110015869140625, 5.53271484375, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Gunship Grunt (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+51, 132972, 1856, 9136, 9136, '0', '0', 0, 0, 1, -3.73512649536132812, 22.57773208618164062, 21.73588180541992187, 2.383118867874145507, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Skyguard Cannoneer (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 261772 - Hold Torch) (possible waypoints or random movement)
(@CGUID+52, 130540, 1856, 9136, 9136, '0', '0', 0, 0, 1, -12.9639215469360351, -13.651686668395996, 20.478240966796875, 4.683331012725830078, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Skyguard Marine (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+53, 130542, 1856, 9136, 9136, '0', '0', 0, 0, 1, -3.025146484375, -9.304443359375, 20.75067138671875, 0.042224545031785964, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Deckhand (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+54, 130540, 1856, 9136, 9136, '0', '0', 0, 0, 1, -1.11232376098632812, -13.6833124160766601, 20.53236579895019531, 4.633946418762207031, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Skyguard Marine (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+55, 131773, 1857, 9136, 9136, '0', '0', 0, 0, 1, 22.57613563537597656, 10.75596332550048828, 40.53900146484375, 2.081272840499877929, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Nathanos Blightcaller (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+56, 131149, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1242.7576904296875, 2700.78369140625, 168.1562042236328125, 2.716730833053588867, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Flying Machine (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+57, 133220, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1300.8194580078125, 3144.25439453125, 398.692626953125, 1.46281898021697998, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Goblin Hot Air Balloon (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+58, 132702, 1856, 9136, 9136, '0', '0', 0, 0, 0, -5.01992988586425781, 24.43457603454589843, 21.732025146484375, 1.59703218936920166, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Alliance Gunship Cannon (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+60, 131149, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1003.94927978515625, 2756.8291015625, 279.31463623046875, 0.652265906333923339, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Flying Machine (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+61, 133056, 1857, 9136, 9136, '0', '0', 0, 0, 0, 46.39287567138671875, 4.546421527862548828, 30.17881011962890625, 3.780830860137939453, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Xander Silberman (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+62, 131149, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1016.74444580078125, 2773.197021484375, 278.314697265625, 6.227115154266357421, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Flying Machine (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+63, 133047, 1857, 9136, 9136, '0', '0', 0, 0, 0, -25.6241531372070312, 24.48468971252441406, 33.9487762451171875, 0.139996454119682312, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Peon (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 261772 - Hold Torch) (possible waypoints or random movement)
(@CGUID+64, 133046, 1857, 9136, 9136, '0', '0', 0, 0, 0, 17.90410041809082031, 29.11562156677246093, 36.22509384155273437, 1.45882582664489746, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Horde Gunship Cannon (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+65, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1361.6614990234375, 2598.394287109375, 0.48157358169555664, 2.903958082199096679, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+67, 133222, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1509.3074951171875, 2830.0029296875, 23.1142120361328125, 3.449080467224121093, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Spider (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+68, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1212.323974609375, 2693.66455078125, 0.30512547492980957, 4.825959205627441406, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+69, 133222, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1469.5582275390625, 2815.036865234375, 28.59724617004394531, 1.997747063636779785, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Spider (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+70, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1337.49462890625, 2651.881591796875, 0.660523414611816406, 4.691783428192138671, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+71, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1291.0621337890625, 2587.954833984375, 1.329391241073608398, 1.469087600708007812, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+72, 130677, 1857, 9136, 9136, '0', '0', 0, 0, 1, -34.0793342590332031, 18.82949256896972656, 34.29132843017578125, 0.421565473079681396, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Gunship Grunt (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+73, 130682, 1856, 9136, 9136, '0', '0', 0, 0, 1, -55.8800239562988281, 3.884849071502685546, 23.47028732299804687, 0.284854650497436523, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Rylai Crestfall (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+74, 131149, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1236.8428955078125, 2630.911865234375, 405.466094970703125, 0.232672646641731262, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Flying Machine (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+75, 132972, 1856, 9136, 9136, '0', '0', 0, 0, 1, -31.394876480102539, 21.63326454162597656, 21.77811813354492187, 3.05550384521484375, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Skyguard Cannoneer (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 261772 - Hold Torch) (possible waypoints or random movement)
(@CGUID+76, 133059, 1857, 9136, 9136, '0', '0', 0, 0, 1, -9.3961181640625, 14.787841796875, 33.906951904296875, 3.120755672454833984, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- General Harris (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+77, 130542, 1856, 9136, 9136, '0', '0', 0, 0, 1, 32.24197006225585937, 0.696868300437927246, 23.51468276977539062, 1.556824445724487304, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Deckhand (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+78, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1334.4609375, 2555.609375, 0.219356194138526916, 2.560238838195800781, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+79, 130540, 1856, 9136, 9136, '0', '0', 0, 0, 1, -27.7923908233642578, 11.54807758331298828, 20.56229209899902343, 1.556898117065429687, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Skyguard Marine (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+80, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1386.09814453125, 2517.27001953125, 0.025659790262579917, 6.278612613677978515, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+81, 133222, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1507.35546875, 2831.459716796875, 23.76836776733398437, 4.946171760559082031, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Spider (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+83, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1433.009521484375, 2519.8046875, 1.314021468162536621, 2.669278144836425781, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+84, 132800, 1856, 9136, 9136, '0', '0', 0, 0, 0, -57.8423194885253906, -4.4791874885559082, 23.53290748596191406, 1.958887100219726562, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Mavvus Gingersnap (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+85, 132702, 1856, 9136, 9136, '0', '0', 0, 0, 0, -18.5591468811035156, 23.65011024475097656, 21.697662353515625, 1.613786101341247558, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Alliance Gunship Cannon (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+86, 130540, 1856, 9136, 9136, '0', '0', 0, 0, 1, -24.6669921875, -13.0236759185791015, 20.53484916687011718, 4.678329944610595703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Skyguard Marine (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+87, 131149, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1413.3603515625, 2961.130859375, 461.298370361328125, 0.445346832275390625, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Flying Machine (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+88, 131149, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1006.18939208984375, 2782.48583984375, 279.314605712890625, 0.496292382478713989, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Flying Machine (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+89, 131149, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1395.7989501953125, 2580.189453125, 116.3642196655273437, 3.136027336120605468, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Flying Machine (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+90, 133220, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1097.88720703125, 2477.08154296875, 208.8053741455078125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Goblin Hot Air Balloon (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+91, 131776, 1857, 9136, 9136, '0', '0', 0, 0, 1, 44.24065017700195312, 5.620276927947998046, 30.17880630493164062, 4.541813373565673828, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Jeron Emberfall (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+92, 133223, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1240.0711669921875, 2939, 56.10253143310546875, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Adder (Area: Seething Shore - Difficulty: 0) CreateObject1
(@CGUID+93, 133222, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1464.579345703125, 2799.896484375, 27.12262153625488281, 2.14492034912109375, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Spider (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+94, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1250.23681640625, 2815.145263671875, 31.18149757385253906, 5.441139698028564453, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+95, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1332.7938232421875, 2629.211669921875, -0.82580351829528808, 0.05238494649529457, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+96, 132960, 1856, 9136, 9136, '0', '0', 0, 0, 0, -54.8386993408203125, 5.621935367584228515, 23.50576019287109375, 5.393166542053222656, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Battle Alchemist Broadoak (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 247198 - Potionmaster) (possible waypoints or random movement)
(@CGUID+97, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1341.2066650390625, 2996.704833984375, 68.66146087646484375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+98, 133222, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1479.1669921875, 2818.75, 29.19844818115234375, 3.949086666107177734, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Spider (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+99, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1362.4727783203125, 2688.15234375, 1.43612372875213623, 4.479050159454345703, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+100, 133222, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1443.3438720703125, 2852.173583984375, 37.91650390625, 5.410832405090332031, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Spider (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+101, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1323.3065185546875, 2689.6767578125, 0.65737771987915039, 2.630320310592651367, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+102, 131149, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1708.9417724609375, 2863.59765625, 445.887054443359375, 0.232672050595283508, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Flying Machine (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+103, 133224, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1136.1510009765625, 2800.045166015625, 29.07668876647949218, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Beetle (Area: Seething Shore - Difficulty: 0) CreateObject1
(@CGUID+104, 133224, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1150.4896240234375, 2791.627685546875, 49.1589202880859375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Beetle (Area: Seething Shore - Difficulty: 0) CreateObject1
(@CGUID+105, 132972, 1856, 9136, 9136, '0', '0', 0, 0, 1, -16.8911037445068359, 21.85056495666503906, 21.68953514099121093, 2.82088017463684082, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Skyguard Cannoneer (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 261772 - Hold Torch) (possible waypoints or random movement)
(@CGUID+106, 133220, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1727.53125, 2792.225830078125, 325.481201171875, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Goblin Hot Air Balloon (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+109, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1454.1083984375, 2503.28759765625, 0.328170329332351684, 1.994844555854797363, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+110, 133266, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1094.71533203125, 2902.552001953125, 44.06522369384765625, 2.291524410247802734, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Byron Holungo (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+111, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1271.0726318359375, 2599.248779296875, 2.79750823974609375, 3.145211219787597656, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+113, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1258.588134765625, 2596.36474609375, 4.1320343017578125, 4.551255226135253906, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+114, 133222, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1505.1607666015625, 2829.0068359375, 23.85546493530273437, 1.737656950950622558, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Spider (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+116, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1368.5380859375, 2516.490234375, 0.352114081382751464, 2.939025640487670898, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+117, 133222, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1460.161865234375, 2846.005126953125, 34.94598770141601562, 2.423222064971923828, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54205), -- Spider (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+119, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1339.04345703125, 3012.413330078125, 114.6979293823242187, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+120, 133225, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1242.5347900390625, 2892.37158203125, 26.10341072082519531, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Frog (Area: Seething Shore - Difficulty: 0) CreateObject1
(@CGUID+122, 130540, 1856, 9136, 9136, '0', '0', 0, 0, 1, -1.45382606983184814, 12.36301040649414062, 20.53528213500976562, 1.704131126403808593, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Skyguard Marine (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+123, 130542, 1856, 9136, 9136, '0', '0', 0, 0, 1, -2.5592041015625, 9.31005859375, 20.71612548828125, 6.255469322204589843, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Deckhand (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+124, 133221, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1125.8646240234375, 2831.224853515625, 29.88973045349121093, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Skittering Softshell (Area: Seething Shore - Difficulty: 0) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+125, 133225, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1240.3836669921875, 2973.181396484375, 59.04534912109375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Frog (Area: Seething Shore - Difficulty: 0) CreateObject1
(@CGUID+126, 132702, 1856, 9136, 9136, '0', '0', 0, 0, 0, -33.6063499450683593, 22.99365234375, 21.79162979125976562, 1.592116832733154296, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Alliance Gunship Cannon (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+128, 133224, 1803, 9136, 9136, '0', '0', 0, 0, 0, 1131.5694580078125, 2773.912353515625, 27.60393333435058593, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Beetle (Area: Seething Shore - Difficulty: 0) CreateObject1
(@CGUID+129, 130540, 1856, 9136, 9136, '0', '0', 0, 0, 1, 39.50041580200195312, 44.24650955200195312, 25.11629676818847656, 4.258817195892333984, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Skyguard Marine (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+130, 130677, 1857, 9136, 9136, '0', '0', 0, 0, 1, -34.8671531677246093, -18.192962646484375, 34.32552337646484375, 5.44598388671875, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205); -- Gunship Grunt (Area: Seething Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+131, 88239, 1857, 9136, 9515, '0', '0', 0, 0, 1, 0.877119839191436767, -0.19819752871990203, 34.29357147216796875, 1.636603832244873046, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Horde Spirit Guide (Area: Tar Pits - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+132, 88238, 1856, 9136, 9515, '0', '0', 0, 0, 1, -24.7726306915283203, -0.02911946550011634, 20.68126296997070312, 6.244111537933349609, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205); -- Alliance Spirit Guide (Area: Tar Pits - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+132;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '164310'), -- High Warlord Volrath - 164310 - Ashran Lane Mob Scaling Aura
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 0, 12265, 0, 0, 0, '228832'), -- War Drummer - 228832 - Mod Scale Increase
(@CGUID+5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Gunship Warguard
(@CGUID+22, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '18950'), -- Sergeant Schmidt - 18950 - Invisibility and Stealth Detection
(@CGUID+31, 0, 0, 0, 0, 0, 1, 0, 0, 12265, 0, 0, 0, '228832'), -- War Drummer - 228832 - Mod Scale Increase
(@CGUID+37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Deckhand
(@CGUID+38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Gunship Warguard
(@CGUID+40, 0, 0, 0, 0, 0, 1, 0, 483, 0, 0, 0, 0, ''), -- Tevs Rusthammer
(@CGUID+42, 0, 0, 0, 0, 0, 1, 0, 0, 2923, 0, 0, 0, ''), -- Skyguard Marine
(@CGUID+53, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Deckhand
(@CGUID+76, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '18950'), -- General Harris - 18950 - Invisibility and Stealth Detection
(@CGUID+77, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Deckhand
(@CGUID+79, 0, 0, 0, 0, 0, 1, 0, 0, 2923, 0, 0, 0, ''), -- Skyguard Marine
(@CGUID+91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Jeron Emberfall
(@CGUID+96, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '247198'), -- Battle Alchemist Broadoak - 247198 - Potionmaster
(@CGUID+110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Byron Holungo
(@CGUID+122, 0, 0, 0, 0, 0, 1, 0, 0, 2923, 0, 0, 0, ''), -- Skyguard Marine
(@CGUID+123, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Deckhand
(@CGUID+129, 0, 0, 0, 0, 0, 1, 0, 0, 2923, 0, 0, 0, ''); -- Skyguard Marine

DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+62;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(@CGUID+62, @CGUID+62, 0, 0, 515),
(@CGUID+62, @CGUID+60, 10, 45, 515),
(@CGUID+62, @CGUID+88, 10, 315, 515);

DELETE FROM `creature_text` WHERE `CreatureID` = 131773;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(131773, 0, 0, 'Let me have a look at you. Ugh... pathetic! Why aren''t there any dark rangers in your ranks? Well, you''ll have to do.', 12, 0, 100, 1, 0, 0, 143504, 0, 'Nathanos Blightcaller'),
(131773, 1, 0, 'Champions of the Horde! We have found Azerite deposits on some wretched island off the Feralas coast. It is your duty to secure it in the name of the Dark Lady!', 12, 0, 100, 1, 0, 0, 143501, 0, 'Nathanos Blightcaller'),
(131773, 2, 0, 'Your mission here is simple. Collect every bit of Azerite and leave nothing for the Alliance to find. I trust that isn''t too hard to grasp.', 12, 0, 100, 1, 0, 0, 143502, 0, 'Nathanos Blightcaller'),
(131773, 3, 0, 'Down there... Azerite! Take it for our warchief. And should those Alliance get in your way, litter the beach with their corpses. Move!', 12, 0, 100, 1, 0, 0, 143505, 0, 'Nathanos Blightcaller'),
(131773, 4, 0, 'Supplies are on the way. I better not see the Alliance getting them before you do!', 12, 0, 100, 1, 0, 0, 143506, 0, 'Nathanos Blightcaller'),
(131773, 4, 1, 'Grab these supplies, if you need them. But don''t lose sight of the Banshee Queen''s prize!', 12, 0, 100, 1, 0, 0, 143507, 0, 'Nathanos Blightcaller'),
(131773, 5, 0, 'Zounds! There''s even more Azerite to be had. Follow your map and lock down those sites!', 12, 0, 100, 1, 0, 0, 143512, 0, 'Nathanos Blightcaller'),
(131773, 5, 1, 'Almost there. Do not relent. More Azerite!', 12, 0, 100, 1, 0, 94746, 143510, 0, 'Nathanos Blightcaller');

DELETE FROM `creature_text` WHERE `CreatureID` = 130532;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(130532, 0, 0, 'You all look like a sturdy lot. Hmm... could use another rogue or two, I''d say... but you''ll do!', 12, 0, 100, 1, 0, 0, 143496, 0, 'Master Mathias Shaw'),
(130532, 1, 0, 'Champions, Azerite deposits have been located on an island off the coast of Feralas. We must secure them before the Horde does.', 12, 0, 100, 1, 0, 0, 143483, 0, 'Master Mathias Shaw'),
(130532, 2, 0, 'We''ve brought our ship around to the center of the island. Collect as much Azerite as you can. It is the key to victory!', 12, 0, 100, 1, 0, 0, 143484, 0, 'Master Mathias Shaw'),
(130532, 3, 0, 'There''s a rich Azerite deposit below us, heroes. Get down there and collect all you can. And if those Horde marauders gets in your way... put them down!', 12, 0, 100, 1, 0, 0, 143486, 0, 'Master Mathias Shaw'),
(130532, 4, 0, 'Supplies incoming! Grab them, champions!', 12, 0, 100, 603, 0, 0, 143493, 0, 'Master Mathias Shaw'),
(130532, 5, 0, 'You kept that Azerite out of the Horde''s hands. Well done!', 12, 0, 100, 1, 0, 0, 143490, 0, 'Master Mathias Shaw'),
(130532, 5, 1, 'You''re doing well so far, heroes. But we need more Azerite!', 12, 0, 100, 0, 0, 0, 143489, 0, 'Master Mathias Shaw'),
(130532, 5, 2, 'You''re doing good work. Just a bit more Azerite and the day is ours!', 12, 0, 100, 1, 0, 0, 143491, 0, 'Master Mathias Shaw'),
(130532, 6, 0, 'Nicely done, champions! King Wrynn will be pleased to learn of your victory. For the Alliance!', 12, 0, 100, 1, 0, 0, 143494, 0, 'Master Mathias Shaw');

DELETE FROM `npc_vendor` WHERE `entry` IN (132960, 133056);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(132960, 10, 138478, 0, 6182, 1, 0, 0, 54673), -- Feast of Ribs
(132960, 9, 138479, 0, 6182, 1, 0, 0, 54673), -- Potato Stew Feast
(132960, 8, 163604, 0, 5986, 1, 0, 0, 54673), -- Net-o-Matic 5000
(132960, 6, 167862, 0, 6501, 1, 0, 0, 54673), -- Horde Glider Kit
(132960, 5, 138486, 0, 6181, 1, 0, 0, 54673), -- "Third Wind" Potion
(132960, 4, 138729, 0, 6181, 1, 0, 0, 54673), -- Potion of Heightened Senses
(132960, 3, 138488, 0, 6181, 1, 0, 0, 54673), -- Saltwater Potion
(132960, 2, 138728, 0, 6181, 1, 0, 0, 54673), -- Potion of Trivial Invisibility
(132960, 1, 138727, 0, 6181, 1, 0, 0, 54673), -- Potion of Defiance
(133056, 10, 138478, 0, 6182, 1, 0, 0, 54904), -- Feast of Ribs
(133056, 9, 138479, 0, 6182, 1, 0, 0, 54904), -- Potato Stew Feast
(133056, 8, 163604, 0, 5986, 1, 0, 0, 54904), -- Net-o-Matic 5000
(133056, 6, 167862, 0, 6501, 1, 0, 0, 54904), -- Horde Glider Kit
(133056, 5, 138486, 0, 6181, 1, 0, 0, 54904), -- "Third Wind" Potion
(133056, 4, 138729, 0, 6181, 1, 0, 0, 54904), -- Potion of Heightened Senses
(133056, 3, 138488, 0, 6181, 1, 0, 0, 54904), -- Saltwater Potion
(133056, 2, 138728, 0, 6181, 1, 0, 0, 54904), -- Potion of Trivial Invisibility
(133056, 1, 138727, 0, 6181, 1, 0, 0, 54904); -- Potion of Defiance

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 146214, 0, 0, 0, 0, 0, 0, 0, 54904), -- 131776
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 146213, 0, 0, 0, 0, 0, 0, 0, 54673); -- 130682

DELETE FROM `gossip_menu` WHERE (`MenuID`=22094 AND `TextID`=@NPCTEXTID+0) OR (`menuID`=22093 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(22094, @NPCTEXTID+0, 54904), -- 131776
(22093, @NPCTEXTID+1, 54673); -- 130682

DELETE FROM `gossip_menu_option` WHERE (`MenuID` IN (22094, 22093) AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(22093, 48128, 0, 0, 'Could you conjure me some food?', 90533, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 54673),
(22094, 48129, 0, 0, 'Could you conjure me some food?', 90533, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 54904);

DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=131776 AND `MenuID`=22094) OR (`CreatureID`=130682 AND `MenuID`=22093);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(131776, 22094, 54904), -- Jeron Emberfall
(130682, 22093, 54673);

-- Waypoints
-- flying Machine - 1
SET @ENTRY := 131149;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0x2, 'Flying Machine - 1');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1349.8546, 2649.3228, 116.36422, NULL, 0),
(@PATH, 1, 1360.6932, 2665.5437, 116.36422, NULL, 0),
(@PATH, 2, 1376.9144, 2676.3826, 116.36422, NULL, 0),
(@PATH, 3, 1396.0486, 2680.1885, 116.36422, NULL, 0),
(@PATH, 4, 1415.1827, 2676.3826, 116.36422, NULL, 0),
(@PATH, 5, 1431.4039, 2665.5437, 116.36422, NULL, 0),
(@PATH, 6, 1442.2426, 2649.3228, 116.36422, NULL, 0),
(@PATH, 7, 1446.0486, 2630.1885, 116.36422, NULL, 0),
(@PATH, 8, 1442.2426, 2611.0542, 116.36422, NULL, 0),
(@PATH, 9, 1431.4039, 2594.8333, 116.36422, NULL, 0),
(@PATH, 10, 1415.1827, 2583.9944, 116.36422, NULL, 0),
(@PATH, 11, 1396.0486, 2580.1885, 116.36422, NULL, 0),
(@PATH, 12, 1376.9144, 2583.9944, 116.36422, NULL, 0),
(@PATH, 13, 1360.6932, 2594.8333, 116.36422, NULL, 0),
(@PATH, 14, 1349.8546, 2611.0542, 116.36422, NULL, 0),
(@PATH, 15, 1346.0486, 2630.1885, 116.36422, NULL, 0);

UPDATE `creature` SET `ScriptName` = '', `wander_distance` = 0, `MovementType` = 2 WHERE `guid` = @CGUID+89;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+89, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Flying Machine

-- flying Machine - 2
SET @ENTRY := 131149;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0x2, 'Flying Machine - 2');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1059.1251, 2701.8071, 278.31467, NULL, 0),
(@PATH, 1, 1047.4727, 2686.1604, 278.31467, NULL, 0),
(@PATH, 2, 1030.7195, 2676.1638, 278.31467, NULL, 0),
(@PATH, 3, 1011.41595, 2673.3394, 278.31467, NULL, 0),
(@PATH, 4, 992.501, 2678.117, 278.31467, NULL, 0),
(@PATH, 8, 976.8542, 2689.7695, 278.31467, NULL, 0),
(@PATH, 9, 966.8576, 2706.5227, 278.31467, NULL, 0),
(@PATH, 10, 964.0332, 2725.8262, 278.31467, NULL, 0),
(@PATH, 11, 968.81085, 2744.7412, 278.31467, NULL, 0),
(@PATH, 12, 980.4633, 2760.388, 278.31467, NULL, 0),
(@PATH, 13, 997.21655, 2770.3845, 278.31467, NULL, 0),
(@PATH, 14, 1016.52, 2773.209, 278.31467, NULL, 0),
(@PATH, 15, 1035.435, 2768.4314, 278.31467, NULL, 0),
(@PATH, 16, 1051.0818, 2756.7788, 278.31467, NULL, 0),
(@PATH, 17, 1061.0784, 2740.0256, 278.31467, NULL, 0),
(@PATH, 18, 1063.9028, 2720.7222, 278.31467, NULL, 0);

UPDATE `creature` SET `ScriptName` = '', `wander_distance` = 0, `MovementType` = 2 WHERE `guid` = @CGUID+62;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+62, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Flying Machine

-- flying Machine - 3
SET @ENTRY := 131149;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0x2, 'Flying Machine - 3');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1314.0575, 2856.8752, 461.29834, NULL, 0),
(@PATH, 1, 1357.412, 2921.76, 461.29834, NULL, 0),
(@PATH, 2, 1422.2966, 2965.1145, 461.29834, NULL, 0),
(@PATH, 3, 1498.8334, 2980.3386, 461.29834, NULL, 0),
(@PATH, 4, 1575.37, 2965.1145, 461.29834, NULL, 0),
(@PATH, 5, 1640.2546, 2921.76, 461.29834, NULL, 0),
(@PATH, 6, 1683.6093, 2856.8752, 461.29834, NULL, 0),
(@PATH, 7, 1698.8334, 2780.3386, 461.29834, NULL, 0),
(@PATH, 8, 1683.6093, 2703.802, 461.29834, NULL, 0),
(@PATH, 9, 1640.2548, 2638.9172, 461.29834, NULL, 0),
(@PATH, 10, 1575.3701, 2595.5627, 461.29834, NULL, 0),
(@PATH, 11, 1498.8334, 2580.3386, 461.29834, NULL, 0),
(@PATH, 12, 1422.2966, 2595.5627, 461.29834, NULL, 0),
(@PATH, 13, 1357.412, 2638.9172, 461.29834, NULL, 0),
(@PATH, 14, 1314.0575, 2703.802, 461.29834, NULL, 0),
(@PATH, 15, 1298.8334, 2780.3386, 461.29834, NULL, 0);

UPDATE `creature` SET `ScriptName` = '', `wander_distance` = 0, `MovementType` = 2 WHERE `guid` = @CGUID+87;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+87, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Flying Machine

-- flying Machine - 4
SET @ENTRY := 131149;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0x2, 'Flying Machine - 4');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1098.5626, 2513.0332, 405.46613, NULL, 0),
(@PATH, 1, 1141.9171, 2577.918, 405.46613, NULL, 0),
(@PATH, 2, 1206.8018, 2621.2725, 405.46613, NULL, 0),
(@PATH, 3, 1283.3385, 2636.4966, 405.46613, NULL, 0),
(@PATH, 4, 1359.8751, 2621.2725, 405.46613, NULL, 0),
(@PATH, 5, 1424.7598, 2577.918, 405.46613, NULL, 0),
(@PATH, 6, 1468.1144, 2513.0332, 405.46613, NULL, 0),
(@PATH, 7, 1483.3385, 2436.4966, 405.46613, NULL, 0),
(@PATH, 8, 1468.1144, 2359.96, 405.46613, NULL, 0),
(@PATH, 9, 1424.7599, 2295.0752, 405.46613, NULL, 0),
(@PATH, 10, 1359.8752, 2251.7207, 405.46613, NULL, 0),
(@PATH, 11, 1283.3385, 2236.4966, 405.46613, NULL, 0),
(@PATH, 12, 1206.8018, 2251.7207, 405.46613, NULL, 0),
(@PATH, 13, 1141.9171, 2295.0752, 405.46613, NULL, 0),
(@PATH, 14, 1098.5626, 2359.96, 405.46613, NULL, 0),
(@PATH, 15, 1083.3385, 2436.4966, 405.46613, NULL, 0);

UPDATE `creature` SET `ScriptName` = '', `wander_distance` = 0, `MovementType` = 2 WHERE `guid` = @CGUID+74;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+74, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Flying Machine

-- flying Machine - 5
SET @ENTRY := 131149;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0x2, 'Flying Machine - 5');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1570.6616, 2745.719, 445.88705, NULL, 0),
(@PATH, 1, 1614.0161, 2810.6038, 445.88705, NULL, 0),
(@PATH, 2, 1678.9008, 2853.9583, 445.88705, NULL, 0),
(@PATH, 3, 1755.4375, 2869.1824, 445.88705, NULL, 0),
(@PATH, 4, 1831.9741, 2853.9583, 445.88705, NULL, 0),
(@PATH, 5, 1896.8589, 2810.6038, 445.88705, NULL, 0),
(@PATH, 6, 1940.2134, 2745.719, 445.88705, NULL, 0),
(@PATH, 7, 1955.4375, 2669.1824, 445.88705, NULL, 0),
(@PATH, 8, 1940.2134, 2592.6458, 445.88705, NULL, 0),
(@PATH, 9, 1896.8589, 2527.761, 445.88705, NULL, 0),
(@PATH, 10, 1831.9741, 2484.4065, 445.88705, NULL, 0),
(@PATH, 11, 1755.4375, 2469.1824, 445.88705, NULL, 0),
(@PATH, 12, 1678.9008, 2484.4065, 445.88705, NULL, 0),
(@PATH, 13, 1614.0161, 2527.761, 445.88705, NULL, 0),
(@PATH, 14, 1570.6616, 2592.6458, 445.88705, NULL, 0),
(@PATH, 15, 1555.4375, 2669.1824, 445.88705, NULL, 0);

UPDATE `creature` SET `ScriptName` = '', `wander_distance` = 0, `MovementType` = 2 WHERE `guid` = @CGUID+102;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+102, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Flying Machine

-- flying Machine - 6
SET @ENTRY := 131149;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0x2, 'Flying Machine - 6');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1114.7167, 2529.7676, 156.48407, NULL, 0),
(@PATH, 1, 1123.3876, 2542.7444, 156.48407, NULL, 0),
(@PATH, 2, 1136.3645, 2551.4153, 156.48407, NULL, 0),
(@PATH, 3, 1151.6719, 2554.4602, 156.48407, NULL, 0),
(@PATH, 4, 1166.9792, 2551.4153, 156.48407, NULL, 0),
(@PATH, 5, 1179.9562, 2542.7444, 156.48407, NULL, 0),
(@PATH, 6, 1188.6271, 2529.7676, 156.48407, NULL, 0),
(@PATH, 7, 1191.6719, 2514.4602, 156.48407, NULL, 0),
(@PATH, 8, 1188.6271, 2499.1528, 156.48407, NULL, 0),
(@PATH, 9, 1179.9562, 2486.176, 156.48407, NULL, 0),
(@PATH, 10, 1166.9792, 2477.5051, 156.48407, NULL, 0),
(@PATH, 11, 1151.6719, 2474.4602, 156.48407, NULL, 0),
(@PATH, 12, 1136.3645, 2477.5051, 156.48407, NULL, 0),
(@PATH, 13, 1123.3876, 2486.176, 156.48407, NULL, 0),
(@PATH, 14, 1114.7167, 2499.1528, 156.48407, NULL, 0),
(@PATH, 15, 1111.6719, 2514.4602, 156.48407, NULL, 0);

UPDATE `creature` SET `ScriptName` = '', `wander_distance` = 0, `MovementType` = 2 WHERE `guid` = @CGUID+16;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+16, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Flying Machine

-- flying Machine - 7
SET @ENTRY := 131149;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0x2, 'Flying Machine - 7');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1217.0491, 2765.5266, 168.1562, NULL, 0),
(@PATH, 1, 1227.8877, 2781.7476, 168.1562, NULL, 0),
(@PATH, 2, 1244.1089, 2792.5864, 168.1562, NULL, 0),
(@PATH, 3, 1263.243, 2796.3923, 168.1562, NULL, 0),
(@PATH, 4, 1282.3772, 2792.5864, 168.1562, NULL, 0),
(@PATH, 5, 1298.5984, 2781.7476, 168.1562, NULL, 0),
(@PATH, 6, 1309.437, 2765.5266, 168.1562, NULL, 0),
(@PATH, 7, 1313.243, 2746.3923, 168.1562, NULL, 0),
(@PATH, 8, 1309.437, 2727.258, 168.1562, NULL, 0),
(@PATH, 9, 1298.5984, 2711.037, 168.1562, NULL, 0),
(@PATH, 10, 1282.3772, 2700.1982, 168.1562, NULL, 0),
(@PATH, 11, 1263.243, 2696.3923, 168.1562, NULL, 0),
(@PATH, 12, 1244.1089, 2700.1982, 168.1562, NULL, 0),
(@PATH, 13, 1227.8877, 2711.037, 168.1562, NULL, 0),
(@PATH, 14, 1217.0491, 2727.258, 168.1562, NULL, 0),
(@PATH, 15, 1213.243, 2746.3923, 168.1562, NULL, 0);

UPDATE `creature` SET `ScriptName` = '', `wander_distance` = 0, `MovementType` = 2 WHERE `guid` = @CGUID+56;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+56, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Flying Machine

 -- Jeron Emberfall smart ai
SET @ENTRY := 131776;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, '', 62, 0, 100, 0, 22094, 0, 0, 0, 86, 176351, 0, 7, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 22094 selected - Gossip player: Cast spell  176351 at Gossip player'),
(@ENTRY, 0, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 22094 selected - Gossip player: Close gossip');

 -- Rylai Crestfall smart ai
SET @ENTRY := 130682;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, '', 62, 0, 100, 0, 22093, 0, 0, 0, 86, 176351, 0, 7, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 22093 selected - Gossip player: Cast spell  176351 at Gossip player'),
(@ENTRY, 0, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 22093 selected - Gossip player: Close gossip');
