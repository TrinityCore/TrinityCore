SET @CGUID := 7003667;
SET @OGUID := 7000691;
SET @WORLD_SAFE_LOC_ID := 100101;
SET @SPAWN_GROUP := 1269;

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @WORLD_SAFE_LOC_ID + 0 AND @WORLD_SAFE_LOC_ID + 1;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@WORLD_SAFE_LOC_ID+0, 1911, -1935.0973, 1233.2969, 34.700943, DEGREES(2.3190832), 'Mugambala - Purple Team'),
(@WORLD_SAFE_LOC_ID+1, 1911, -1934.25, 1369.32, 34.4306, DEGREES(3.9550033), 'Mugambala - Gold Team');

DELETE FROM `battleground_scripts` WHERE `MapId` = 1911 AND `BattlemasterListId` = 0;
INSERT INTO `battleground_scripts` (`MapId`, `BattlemasterListId`, `ScriptName`) VALUES
(1911, 0, 'arena_mugambala'); -- Mugambala

DELETE FROM `battleground_template` WHERE `ID` = 903;
INSERT INTO `battleground_template` (`ID`, `AllianceStartLoc`, `HordeStartLoc`, `StartMaxDist`, `Weight`, `Comment`) VALUES
(903, @WORLD_SAFE_LOC_ID+0, @WORLD_SAFE_LOC_ID+1, 0, 1, 'Mugambala');

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 278211, 1911, 9992, 9992, '0', '0', 0, -1126.50439453125, 757.6019287109375, 487.86822509765625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 24, 63305), -- Doodad_8TR_zandalari_elevator001 (Area: Mugambala - Difficulty: 0) CreateObject1
(@OGUID+1, 278212, 1911, 9992, 9992, '0', '0', 0, -1126.50439453125, 851.7958984375, 487.86822509765625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 24, 63305), -- Doodad_8TR_zandalari_elevator002 (Area: Mugambala - Difficulty: 0) CreateObject1
(@OGUID+2, 298781, 1911, 9992, 9992, '0', '0', 0, -1947.682373046875, 1354.986083984375, 34.56772994995117187, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 63305), -- Doodad_8TR_ZANDALARI_ArenaGate002 (Area: Mugambala - Difficulty: 0) CreateObject1
(@OGUID+3, 298780, 1911, 9992, 9992, '0', '0', 0, -1947.85546875, 1246.4124755859375, 34.56772994995117187, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 7200, 255, 1, 63305), -- Doodad_8TR_ZANDALARI_ArenaGate001 (Area: Mugambala - Difficulty: 0) CreateObject1
(@OGUID+4, 184664, 1911, 9992, 9992, '0', '0', 0, -1962.5364990234375, 1245.8975830078125, 34.43144989013671875, 3.316144466400146484, 0, 0, -0.99619388580322265, 0.087165042757987976, 360, 255, 1, 63305), -- Shadow Sight (Area: Mugambala - Difficulty: 0) CreateObject2
(@OGUID+5, 184663, 1911, 9992, 9992, '0', '0', 0, -1960.6129150390625, 1354.592041015625, 34.4305572509765625, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 360, 255, 1, 63305); -- Shadow Sight (Area: Mugambala - Difficulty: 0) CreateObject2

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8TR_zandalari_elevator001
(@OGUID+1, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8TR_zandalari_elevator002
(@OGUID+2, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8TR_ZANDALARI_ArenaGate002
(@OGUID+3, 0, 0, 1, -0.00000004371138828, 0, 0); -- Doodad_8TR_ZANDALARI_ArenaGate001

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+27;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+1, 142640, 1911, 9992, 9992, '0', '0', 0, 0, 0, -2031.4757080078125, 1319.6978759765625, 6.492127895355224609, 6.013492107391357421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Caravan Brutosaur (Area: Mugambala - Difficulty: 0) CreateObject1
(@CGUID+2, 142710, 1911, 9992, 9992, '0', '0', 0, 0, 1, -1949.5867919921875, 1374.52783203125, 34.51388931274414062, 2.54727792739868164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- 7th Legion Soldier (Area: Mugambala - Difficulty: 0) CreateObject1
(@CGUID+3, 142645, 1911, 9992, 9992, '0', '0', 0, 0, 0, -1921.0504150390625, 1389.3697509765625, 35.2127532958984375, 4.51738739013671875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frog Critter (Area: Mugambala - Difficulty: 0) CreateObject1
(@CGUID+4, 142640, 1911, 9992, 9992, '0', '0', 0, 0, 0, -2000.5399169921875, 1393.7222900390625, 16.95162010192871093, 5.951320171356201171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Caravan Brutosaur (Area: Mugambala - Difficulty: 0) CreateObject1
(@CGUID+5, 142667, 1911, 9992, 9992, '0', '0', 0, 0, 0, -1923.670166015625, 1341.748291015625, 51.72408294677734375, 3.469998836517333984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Trained Pterrordax (Area: Mugambala - Difficulty: 0) CreateObject1
(@CGUID+6, 142665, 1911, 9992, 9992, '0', '0', 0, 0, 0, -1895.3997802734375, 1255.052734375, 43.69062042236328125, 5.605297088623046875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Temple Beetle (Area: Mugambala - Difficulty: 0) CreateObject1
(@CGUID+8, 141962, 1911, 9992, 9992, '0', '0', 0, 0, 0, -1892.9114990234375, 1300.4288330078125, 50.76938629150390625, 3.359557867050170898, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Je'stry the Untamed (Area: Mugambala - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+9, 142665, 1911, 9992, 9992, '0', '0', 0, 0, 0, -1937.283203125, 1230.040283203125, 34.7009429931640625, 1.579180121421813964, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Temple Beetle (Area: Mugambala - Difficulty: 0) CreateObject1
(@CGUID+10, 142667, 1911, 9992, 9992, '0', '0', 0, 0, 0, -1923.13720703125, 1260.0833740234375, 50.34122848510742187, 2.982066154479980468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Trained Pterrordax (Area: Mugambala - Difficulty: 0) CreateObject1
(@CGUID+11, 142665, 1911, 9992, 9992, '0', '0', 0, 0, 0, -1973.7257080078125, 1267.515625, 34.51388931274414062, 4.337609291076660156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Temple Beetle (Area: Mugambala - Difficulty: 0) CreateObject1
(@CGUID+13, 142640, 1911, 9992, 9992, '0', '0', 0, 0, 0, -1977.935791015625, 1207.142333984375, 25.15067100524902343, 0.541338086128234863, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Caravan Brutosaur (Area: Mugambala - Difficulty: 0) CreateObject1
(@CGUID+14, 142665, 1911, 9992, 9992, '0', '0', 0, 0, 0, -1931.6075439453125, 1326.2352294921875, 39.13532638549804687, 5.140517711639404296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Temple Beetle (Area: Mugambala - Difficulty: 0) CreateObject1
(@CGUID+15, 142640, 1911, 9992, 9992, '0', '0', 0, 0, 0, -2026.2274169921875, 1280.001708984375, 7.550435543060302734, 0.311443358659744262, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Caravan Brutosaur (Area: Mugambala - Difficulty: 0) CreateObject1
(@CGUID+16, 142665, 1911, 9992, 9992, '0', '0', 0, 0, 0, -1894.1776123046875, 1334.4818115234375, 43.69257354736328125, 0.534181714057922363, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Temple Beetle (Area: Mugambala - Difficulty: 0) CreateObject1
(@CGUID+17, 142665, 1911, 9992, 9992, '0', '0', 0, 0, 0, -1934.046875, 1298.1707763671875, 34.43056488037109375, 3.940336227416992187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Temple Beetle (Area: Mugambala - Difficulty: 0) CreateObject1
(@CGUID+18, 142643, 1911, 9992, 9992, '0', '0', 0, 0, 0, -1950.1978759765625, 1373.857666015625, 34.51388931274414062, 0.854648888111114501, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Harbor Saurid (Area: Mugambala - Difficulty: 0) CreateObject1
(@CGUID+19, 142665, 1911, 9992, 9992, '0', '0', 0, 0, 0, -1924.8299560546875, 1270.6712646484375, 43.42324447631835937, 2.870828866958618164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Temple Beetle (Area: Mugambala - Difficulty: 0) CreateObject1
(@CGUID+21, 142645, 1911, 9992, 9992, '0', '0', 0, 0, 0, -1913.2413330078125, 1379.4375, 35.2127532958984375, 3.470753908157348632, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frog Critter (Area: Mugambala - Difficulty: 0) CreateObject1
(@CGUID+22, 142643, 1911, 9992, 9992, '0', '0', 0, 0, 0, -1950.3038330078125, 1375.064208984375, 34.51388931274414062, 5.911371707916259765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Harbor Saurid (Area: Mugambala - Difficulty: 0) CreateObject1
(@CGUID+23, 142665, 1911, 9992, 9992, '0', '0', 0, 0, 0, -1962.3663330078125, 1335.2691650390625, 34.51388931274414062, 0.460075914859771728, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305); -- Temple Beetle (Area: Mugambala - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+27;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 0, 16363, 0, 0, 4, ''), -- Caravan Brutosaur
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 0, 1652, 0, 0, 0, ''), -- 7th Legion Soldier
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 0, 16363, 0, 0, 4, ''), -- Caravan Brutosaur
(@CGUID+5, 0, 0, 0, 0, 0, 1, 1, 0, 16368, 0, 0, 0, ''), -- Trained Pterrordax
(@CGUID+8, 0, 0, 0, 3, 0, 1, 0, 0, 12224, 0, 0, 0, ''), -- Je'stry the Untamed
(@CGUID+10, 0, 0, 0, 0, 0, 1, 1, 0, 16368, 0, 0, 0, ''), -- Trained Pterrordax
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 0, 16363, 0, 0, 4, ''), -- Caravan Brutosaur
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 0, 16363, 0, 0, 4, ''), -- Caravan Brutosaur
(@CGUID+18, 0, 0, 0, 0, 0, 1, 0, 0, 1372, 0, 0, 0, ''), -- Harbor Saurid
(@CGUID+22, 0, 0, 0, 0, 0, 1, 0, 0, 1372, 0, 0, 0, ''); -- Harbor Saurid

UPDATE `creature_template` SET `unit_flags`=0x2000100, `unit_flags3`=0x1000000 WHERE `entry`=141962; -- Je'stry the Untamed
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=142665; -- Temple Beetle
UPDATE `creature_template` SET `unit_flags`=0x2000200, `unit_flags3`=0x40000000 WHERE `entry`=142667; -- Trained Pterrordax
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=142645; -- Frog Critter
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=142710; -- 7th Legion Soldier
UPDATE `creature_template` SET `unit_flags`=0x2000000, `unit_flags2`=0x800 WHERE `entry`=142640; -- Caravan Brutosaur
UPDATE `creature_template` SET `unit_flags`=0x2000000, `unit_flags3`=0x800000 WHERE `entry`=142646; -- Arena Spectator

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=142643 AND `DifficultyID`=0); -- 142643 (Harbor Saurid) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=63305 WHERE (`Entry`=141962 AND `DifficultyID`=0); -- 141962 (Je'stry the Untamed) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=63305 WHERE (`Entry`=142667 AND `DifficultyID`=0); -- 142667 (Trained Pterrordax) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=142645 AND `DifficultyID`=0); -- 142645 (Frog Critter) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=142710 AND `DifficultyID`=0); -- 142710 (7th Legion Soldier) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=142640 AND `DifficultyID`=0); -- 142640 (Caravan Brutosaur) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=63305 WHERE (`Entry`=142646 AND `DifficultyID`=0); -- 142646 (Arena Spectator) - Sessile, CanSwim, Floating

DELETE FROM `creature_text` WHERE `CreatureID`=141962;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(141962, 0, 0, 'Today, your cries of battle and de clash of your weapons will be heard by de great loa! And de fallen will join dem... in de afterlife.', 12, 0, 100, 1, 0, 104446, 153457, 3, 'Je\'stry the Untamed'), -- arena starts in 30s
(141962, 1, 0, 'For Zandalar!', 12, 0, 100, 1, 0, 104445, 153451, 3, 'Je\'stry the Untamed'), -- arena start
(141962, 2, 0, 'Ahhhh?!', 12, 0, 100, 1, 0, 104449, 153454, 3, 'Je\'stry the Untamed to Player'), -- 20% reaction
(141962, 3, 0, 'Grant her an honorable death...', 12, 0, 100, 1, 0, 104451, 153456, 3, 'Je\'stry the Untamed to Player'), -- 20% reaction
(141962, 4, 0, 'Grant him an honorable death...', 12, 0, 100, 1, 0, 104450, 153455, 3, 'Je\'stry the Untamed to Player'), -- 20% reaction
(141962, 5, 0, 'To de afterlife...', 12, 0, 100, 1, 0, 104448, 153453, 3, 'Je\'stry the Untamed to Player'), -- dead
(141962, 5, 1, 'You did not have de loa\'s blessing this day.', 12, 0, 100, 1, 0, 104447, 153452, 3, 'Je\'stry the Untamed to Player'); -- dead

DELETE FROM `vehicle_template_accessory` WHERE (`entry`=142640 AND `seat_id`=0);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(142640, 142646, 0, 0, 'Caravan Brutosaur - Arena Spectator', 5, 0); -- Caravan Brutosaur - Arena Spectator

DELETE FROM `spawn_group_template` WHERE `groupId` = @SPAWN_GROUP;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP, 'Mugambala - Shadow sight', 0x20);

DELETE FROM `spawn_group` WHERE `groupId` = @SPAWN_GROUP;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP, 1, @OGUID+4),
(@SPAWN_GROUP, 1, @OGUID+5);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 33 AND `SourceEntry` = @SPAWN_GROUP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ScriptName`) VALUES
(33, @SPAWN_GROUP, 0, 0, 0, 'condition_is_shadow_sight_enabled');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_zandalar_arena_reaction_trigger_low_health', 'spell_zandalar_arena_reaction_trigger');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(278770, 'spell_zandalar_arena_reaction_trigger_low_health'),
(278771, 'spell_zandalar_arena_reaction_trigger');

DELETE FROM `spell_proc` WHERE `SpellId` IN (278771);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(278771,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0,0,0,0); -- Zandalar Arena Reaction Trigger

