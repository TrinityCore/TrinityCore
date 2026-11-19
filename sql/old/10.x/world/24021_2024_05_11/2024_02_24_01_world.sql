SET @CGUID := 8000041;
SET @OGUID := 8000014;

-- Add missing Creature Spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID AND @CGUID+17;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
-- Alliance
(@CGUID,162817,2175,10424,10529,'0',0,14663,0,0,0,0,243.55556,-2242.9185,83.88086,4.5683498,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52649), -- Torgok <Binder of Souls>
(@CGUID+1,150245,2175,10424,10529,'0',0,13794,0,0,0,0,169.23438,-2297.9983,82.15651,2.54967,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52649), -- Lindie Springstock
(@CGUID+2,156800,2175,10424,10529,'0',0,13794,0,0,0,0,186.51042,-2284.6216,81.91817,3.558244,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52649), -- Quartermaster Richter <Supplies>
(@CGUID+3,156807,2175,10424,10529,'0',0,13835,0,0,0,0,185.90625,-2288.927,81.77783,1.908762,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52649), -- Captain Garrick
(@CGUID+4,156808,2175,10424,10529,'0',0,13794,0,0,0,0,169.73827,-2293.4995,82.96085,2.618248,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52649), -- Small Boar
-- Horde
(@CGUID+5,167142,2175,10424,10588,'0',0,15331,0,0,0,0,107.87153,-2414.177,95.44844,0,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52808), -- Choppy Booster Mk. 5
(@CGUID+6,167212,2175,10424,10529,'0',0,15485,0,0,0,0,185.70660400390625,-2282.98095703125,81.93126678466796875,3.950360536575317382,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52808), -- Warlord Breka Grimaxe
(@CGUID+7,167216,2175,10424,10529,'0',0,15447,0,0,0,0,183.4184112548828125,-2278.020751953125,81.93170166015625,1.636933207511901855,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52808), -- Grunt Throg
(@CGUID+8,167217,2175,10424,10529,'0',0,15330,0,0,0,0,177.1770782470703125,-2295.96875,81.96833038330078125,0,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52808), -- Cork Fizzlepop
(@CGUID+9,167213,2175,10424,10529,'0',0,15330,0,0,0,0,178.4184112548828125,-2292.552001953125,81.93624114990234375,0.398178786039352416,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52808), -- Provisioner Jin'hake
(@CGUID+10,167219,2175,10424,10529,'0',0,15353,0,0,0,0,257.260406494140625,-2337.651123046875,81.06317138671875,5.754884243011474609,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52808), -- Shuja Grimaxe
(@CGUID+11,167222,2175,10424,10529,'0',0,15338,0,0,0,0,160.5868072509765625,-2310.088623046875,84.49564361572265625,3.033173322677612304,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52808), -- Won'sa
(@CGUID+12,167221,2175,10424,10529,'0',0,15338,0,0,0,0,160.5989532470703125,-2307.404541015625,84.11737060546875,2.955642223358154296,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52808), -- Lana Jordan
(@CGUID+13,167215,2175,10424,10529,'0',0,15377,0,0,0,0,183.6805572509765625,-2295.94091796875,82.250396728515625,4.669465065002441406,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52808), -- Mithdran Dawntracker <Stable Master>
(@CGUID+14,167290,2175,10424,10528,'0',0,15354,0,0,0,0,392.46875,-2440.225830078125,125.4717788696289062,4.147569179534912109,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,53212), -- Shuja Grimaxe "Harpy area"
(@CGUID+15,167291,2175,10424,10588,'0',0,15354,0,0,0,0,391.211822509765625,-2443.717041015625,125.1890335083007812,0.829528868198394775,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,53212), -- Bo "Harpy area"
(@CGUID+16,167225,2175,10424,10527,'0',0,15337,0,0,0,0,92.015625,-2246.911376953125,94.49737548828125,2.622560739517211914,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,53212), -- Lana Jordan "Pit Area"
(@CGUID+17,167226,2175,10424,10527,'0',0,15337,0,0,0,0,89.265625,-2248.960205078125,94.74571990966796875,1.861210823059082031,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,53212); -- Won'sa "Pit Area"

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+18 AND @CGUID+21;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+18, 167926, 2175, 10424, 10529, '0', 15558, 0, 0, 1, 232.1614532470703125, -2292.53466796875, 80.9791717529296875, 4.706853866577148437, 120, 0, 0, 224, 0, 0, NULL, NULL, NULL, NULL, 53262), -- Warlord Breka Grimaxe (Area: Ogre Ruins - Difficulty: 0) CreateObject1
(@CGUID+19, 167126, 2175, 10424, 10529, '0', 15558, 0, 0, 0, 230.795135498046875, -2297.085205078125, 80.9791717529296875, 1.356228590011596679, 120, 0, 0, 119, 0, 0, 2, NULL, NULL, NULL, 53262), -- Shuja Grimaxe (Area: Ogre Ruins - Difficulty: 0) CreateObject1
(@CGUID+20, 156799, 2175, 10424, 10529, '0', 13795, 0, 0, 0, 230.795135498046875, -2297.085205078125, 80.9791717529296875, 1.356228590011596679, 120, 0, 0, 95, 382, 0, NULL, NULL, NULL, NULL, 53262), -- Henry Garrick (Area: Ogre Ruins - Difficulty: 0) CreateObject1
(@CGUID+21, 156807, 2175, 10424, 10529, '0', 13795, 0, 0, 1, 232.1614532470703125, -2292.53466796875, 80.9791717529296875, 4.706853866577148437, 120, 0, 0, 357, 0, 0, NULL, NULL, NULL, NULL, 53262); -- Captain Garrick (Area: Ogre Ruins - Difficulty: 0) CreateObject1

-- Add missing Creature Spawns
DELETE FROM `gameobject` WHERE `guid`=@OGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Horde
(@OGUID, 351765, 2175, 10424, 10529, '0', 15330, 0, 162.796875, -2303.585205078125, 81.78006744384765625, 0.724311470985412597, 0, 0, 0.354290962219238281, 0.935135245323181152, 7200, 255, 1, 53212);

-- Fix campfire at ogre ruins
UPDATE `gameobject_template_addon` SET `flags` = 4 WHERE `entry` = 342365;

-- Ride of the Scientifically Enhanced Boar

-- Pathing for Small Boar Entry: 156808
SET @NPC := @CGUID+4;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `wander_distance`=0,`MovementType`=2,`position_x`=165.30946,`position_y`=-2298.7698,`position_z`=82.51129 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`PathId`,`mount`,`StandState`,`SheathState`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Small Boar Ogre Ruins');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,165.30946,-2298.7698,82.51129,NULL,0),
(@PATH,2,170.00575,-2301.923,82.05885,NULL,0),
(@PATH,3,173.15572,-2298.7876,81.85623,NULL,0),
(@PATH,4,168.463,-2294.0735,81.95101,NULL,0);

-- Pathing for Henry Garrick Ogre Ruins
SET @NPC := 8000023;
SET @PATH := @NPC * 10;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Henry Garrick Ogre Ruins');
DELETE FROM `waypoint_path_node` WHERE `PathId` IN (@PATH);
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,231.05,-2297.1802,87.1176,NULL,0),
(@PATH,2,230.88,-2297.09,84.0067,NULL,0),
(@PATH,3,230.71,-2297,80.8958,NULL,0),
(@PATH,4,230.71,-2297,80.8958,1.396685,0);

UPDATE `creature` SET `StringId`= "captain_garrick_plains" WHERE `guid`=8000018;
UPDATE `creature` SET `StringId` = 'henry_garrick_ogre_ruins_prisoner' WHERE `guid`=8000023;

UPDATE `creature_template` SET `faction`=1, `ScriptName`="npc_captain_garrick_q55879" WHERE `entry`=174955;
UPDATE `creature_template` SET `ScriptName`="npc_giant_boar_vehicle_q55879" WHERE `entry`=156267;
UPDATE `creature_template` SET `ScriptName`="npc_torgok_q55879" WHERE `entry`=162817;
UPDATE `creature_template` SET `ScriptName`="npc_prisoner_q55879" WHERE `entry`=156799;
UPDATE `creature_template` SET `npcflag`=16777216 WHERE entry IN (156595);
UPDATE `creature_template` SET `VehicleId`=6832 WHERE `entry`=156267;
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry` IN (156799,156807);
UPDATE `creature_template` SET `npcflag`=641 WHERE `entry` IN (156800);

DELETE FROM `creature_template_addon` WHERE `entry` IN (162817);
INSERT INTO `creature_template_addon` (`entry`,`visibilityDistanceType`,`emote`,`auras`) VALUES
(162817,3,617, ''); -- Torgok

-- Henry Garrick & Shuja Grimaxe
UPDATE `creature_template_movement` SET `Ground`=1, `Swim`=1 WHERE `CreatureId` IN (156799,167126);

DELETE FROM `npc_vendor` WHERE (`entry`=156800 AND `item`=168100 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=156800 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(156800, 2, 168100, 0, 0, 1, 0, 0, 53040), -- 168100
(156800, 1, 117, 0, 0, 1, 0, 1, 53040); -- 117

DELETE FROM `creature_template_gossip` WHERE `CreatureID`=156800;
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(156800, 24885, 53040); -- 156800

DELETE FROM `gossip_menu` WHERE (`MenuID`=24885 AND `TextID`=201865);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(24885, 201865, 53040); -- 156800

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (24885);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(24885, 49522, 0, 1, 'Let me browse your goods.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 53040);

DELETE FROM `creature_text` WHERE `CreatureID`=162817;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(162817, 0, 0, 'We take soul for ritual, you no stop!', 12, 0, 100, 0, 0, 0, 0, 0, 'Torgok aggro'),
(162817, 1, 0, 'Me never get... to see... ritual...', 12, 0, 100, 0, 0, 0, 0, 0, 'Torgok death');

-- Add Scenes for Ride of the Scientifically Enhanced Boar
DELETE FROM `scene_template` WHERE `SceneId` IN (2338,2341,2423,2422,2421,2420);
INSERT INTO `scene_template` (`SceneId`,`Flags`,`ScriptPackageID`,`Encrypted`,`ScriptName`) VALUES
(2338,16,2712,0,'scene_darkmaul_plains_skeleton_army_alliance'),
(2341,17,2933,0,''),
(2423,16,2825,0,''),
(2422,16,2824,0,''),
(2421,16,2823,0,''),
(2420,16,2822,0,'');

-- Summon data for Captain Garrick
DELETE FROM `creature_summoned_data` WHERE `CreatureID` IN (174955, 167126);
INSERT INTO `creature_summoned_data` (`CreatureID`,`CreatureIDVisibleToSummoner`,`GroundMountDisplayID`,`FlyingMountDisplayID`, `DespawnOnQuestsRemoved`) VALUES
(174955,156781,NULL,NULL,''),
(167126,NULL,NULL,NULL,'59942');

DELETE FROM `creature_equip_template` WHERE `CreatureID`=174955;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(174955, 1, 163887, 0, 0, 163891, 0, 0, 0, 0, 0, 52808);

-- Spell Click
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (156595);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(156595,305068,1,0);

-- Spell Target Position
DELETE FROM `spell_target_position` WHERE `ID` IN (305069);
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`VerifiedBuild`) VALUES
(305069,0,2175,116.44965,-2430.3699,90.6546,52649);

-- Condition for Spell click event condition type Queststate
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup` IN (156595) AND `SourceEntry` IN (305068) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 156595, 305068, 0, 0, 47, 0, 55879, 8, 0, 0, 0, 0, '', 'Spellclick unit Giant Boar will cast spell Summon Darkmaul Plains Questgivers (DNT) on player if quest Ride of the Scientifically Enhanced Boar queststate is INCOMPLETE');

-- Condition for source Spell implicit target condition type Object entry guid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=325406 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 325406, 0, 0, 31, 0, 3, 162817, 0, 0, 0, 0, '', 'Spell Necrotic Ritual (effect 0) will hit the potential target of the spell if target is unit Torgok.');

-- Condition for Spell Ping Garrick (DNT)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=316982 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 316982, 0, 0, 31, 0, 3, 174955, 0, 0, 0, 0, '', 'Spell Ping Garrick (DNT) (effect 0) will hit unit Alliance Captain.'),
(13, 1, 316982, 0, 1, 31, 0, 3, 167146, 0, 0, 0, 0, '', 'Spell Ping Garrick (DNT) (effect 0) will hit unit Horde Warrior.');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (305779,173426,306357,296843,325368);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(305779,'spell_summon_darkmaul_plains_questgivers_q55879'),
(173426,'spell_riding_giant_boar_q55879'),
(306357,'spell_knockback_hint_q56034'),
(296843,'spell_gear_repaired_aura_q55194'),
(325368, 'spell_re_sizer_slaughter');

-- Phase Area
DELETE FROM `phase_area` WHERE `AreaId`=10424 AND `PhaseId` IN (14663,13835);
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(10424,14663, 'Cosmetic - NPE - See Torgok <Binder of Souls>'),
(10424,13835, 'Cosmetic - NPE - See Captain Garrick, Lindie Springstock, Quartermaster Richter Ogre Ruins');

-- Phase Names
DELETE FROM `phase_name` WHERE `ID` IN (14663,13835);
INSERT INTO `phase_name` (`ID`,`Name`) VALUES
(14663,'Cosmetic - NPE - See Torgok <Binder of Souls>'),
(13835,'Cosmetic - NPE - See Captain Garrick, Lindie Springstock, Quartermaster Richter Ogre Ruins');

-- Phase Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (13775,13783) AND `ConditionValue1`=321670;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (13784,13779,13785,13780,13776,13766,13775) AND `ConditionValue1`=55879;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (13835,13794) AND `SourceEntry`=10424;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (14663) AND `SourceEntry`=10424 AND `ElseGroup`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,13775,10588, 0, 0, 1, 0, 321670, 0, 0, 1, 0, 0, '', 'See Re-sized Boar at Plains if quest Ride if player does not have aura'),
(26,13783,10529, 0, 0, 1, 0, 321670, 0, 0, 1, 0, 0, '', 'See See the Army of Undead if quest Ride if player does not have aura'),
(26,13784,10424, 0, 0, 47, 0, 55879, 66, 0, 1, 0, 0, '', 'See Henry Garrick at Ogre Ruins if quest Ride of the Scientifically Enhanced Boar is not completed | rewarded'),
(26,13779,10588, 0, 0, 47, 0, 55879, 74, 0, 1, 0, 0, '', 'See Captain Garrick at Plains if quest Ride of the Scientifically Enhanced Boar is not taken | completed | rewarded'),
(26,13785,10588, 0, 0, 47, 0, 55879, 64, 0, 1, 0, 0, '', 'See The Scout-o-Matic 5000 at Plains if quest Ride of the Scientifically Enhanced Boar is not rewarded'),
(26,13780,10588, 0, 0, 47, 0, 55879, 64, 0, 1, 0, 0, '', 'See Austin Huxworth at Darkmaul Plains if quest Ride of the Scientifically Enhanced Boar is not rewarded'),
(26,13780,10588, 0, 1, 47, 0, 55879, 64, 0, 1, 0, 0, '', 'See Austin Huxworth at Darkmaul Plains if quest Ride of the Scientifically Enhanced Boar is not rewarded'),
(26,13776,10588, 0, 0, 47, 0, 55879, 64, 0, 1, 0, 0, '', 'See Lindie Springstock at Darkmaul Plains if quest Ride of the Scientifically Enhanced Boar is not rewarded'),
(26,13766,10588, 0, 0, 47, 0, 55879, 64, 0, 1, 0, 0, '', 'See Alliance crew at Darkmaul Plains if quest Ride of the Scientifically Enhanced Boar is not rewarded'),
(26,13775,10588, 0, 0, 47, 0, 55879, 64, 0, 1, 0, 0, '', 'See Re-sized Boar at Plains if quest Ride of the Scientifically Enhanced Boar is not rewarded'),
(26,14663,10424, 0, 0, 47, 0, 55879, 64, 0, 1, 0, 0, '', 'See Torgok <Binder of Souls> if quest Ride of the Scientifically Enhanced Boar is not rewarded'),
(26,14663,10424, 0, 0, 48, 0, 396499, 0, 8, 0, 0, 0, '', 'See Torgok <Binder of Souls> if quest Ride if player has objective complete'),
(26,13835,10424, 0, 0, 47, 0, 55879, 64, 0, 0, 0, 0, '', 'See Garrick at ogre ruins if quest Ride of the Scientifically Enhanced Boar is rewarded'),
(26,13794,10424, 0, 0, 47, 0, 55879, 64, 0, 0, 0, 0, '', 'See Lindie and Richter at ogre ruins if quest Ride of the Scientifically Enhanced Boar is rewarded');

-- Quest data
DELETE FROM `creature_queststarter` WHERE `id`=156280 AND `quest`=55879;
DELETE FROM `creature_queststarter` WHERE `id`=156807 AND `quest`=55194;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(156280, 55879, 52649), -- Ride of the Scientifically Enhanced Boar accept from Captain Garrick
(156807, 55194, 52649); -- Stocking Up on Supplies accept from Captain Garrick

DELETE FROM `creature_questender` WHERE `id`=156799 AND `quest`=55879;
DELETE FROM `creature_questender` WHERE `id`=156807 AND `quest`=55194;
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(156799, 55879, 52649), -- Ride of the Scientifically Enhanced Boar turn in to Henry Garrick
(156807, 55194, 52649); -- Stocking Up on Supplies turn in to Captain Garrick

DELETE FROM `quest_template_addon` WHERE `ID` IN (55879,55194);
INSERT INTO `quest_template_addon` (`ID`,`AllowableClasses`,`PrevQuestID`,`NextQuestID`,`ScriptName`) VALUES
(55879,0,56034,0,'quest_ride_of_the_scientifically_enhanced_boar'), -- Ride of the Scientifically Enhanced Boar
(55194,0,55879,0,''); -- Stocking Up on Supplies

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (12090,12091,12092,12164,15615);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(12090,29443,0,'',52649),
(12091,29446,0,'',52649),
(12092,29447,0,'',52649),
(12164,29660,0,'',52649),
(15615,39167,0,'',52649);

DELETE FROM `conversation_actors` WHERE `ConversationId` IN (12090,12091,12092,12164,15615);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(12090,0,0,0,0,0,0,1,52649), -- Player
(12090,71372,0,1,0,0,0,0,52649), -- Captain Garrick
(12091,71587,8000023,0,0,0,0,0,52649), -- Henry Garrick
(12092,0,0,0,0,0,0,1,52649), -- Player
(12092,71372,0,1,0,0,0,0,52649), -- Captain Garrick
(12164,71372,0,0,0,0,0,0,52649), -- Captain Garrick
(15615,71372,0,0,0,0,0,0,52649), -- Captain Garrick
(15615,78493,0,1,0,0,0,0,52649); -- Henry Garrick

DELETE FROM `conversation_line_template` WHERE `Id` IN (29443,29444,29446,29660,29447,29448,29450,39167,39163,39164,39165,39166);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES
(29443,0,0,0,52649),
(29444,0,1,0,52649),
(29446,0,0,0,52649),
(29660,0,0,0,52649),
(29447,0,0,0,52649),
(29448,0,1,0,52649),
(29450,0,1,0,52649),
(39167,0,0,0,52649),
(39163,0,1,0,52649),
(39164,0,0,0,52649),
(39165,0,0,0,52649),
(39166,0,1,0,52649);

-- Lindie Springstock SAI 'Ogre Ruins'
SET @ENTRY := 150245;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 1, '', 1, 0, 100, 0, 8000, 10000, 8000, 10000, 66, 0, 0, 0, 0, 0, 0, 19, 156808, 10, 0, 0, 0, 0, 0, 'Every 8 - 10 seconds (OOC) - Self: Look at Closest alive creature Small Boar (156808) in 10 yards'),
(@ENTRY, 0, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 5, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 8 - 10 seconds (OOC) - Self: Play emote 4');

-- Captain Garrick SAI 'Ogre Ruins'
SET @ENTRY := 156807;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 47, 0, 100, 0, 55194, 0, 0, 0, 11, 296845, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On quest accepted - Self: Cast spell  296845 on Player who accepted');

-- Loot for Torgok
SET @ID := 162817;
UPDATE `creature_template_difficulty` SET `LootID`=@ID, GoldMin=4, GoldMax=20 WHERE `Entry` IN (@ID);
DELETE FROM `creature_loot_template` WHERE `Entry` IN (@ID);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ID,176398,0,100,0,1,0,1,1,'Torgok - Torgok\'s Reagent Pouch'),
(@ID,175245,0,5,0,1,0,1,1,'Torgok - Runetusk Necklace'),
(@ID,0,10100,10,0,1,0,1,1,'Torgok - Poor Quality Table Level 1 to 5');

-- Conditions for class loot
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=@ID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(1,@ID,176398,0,0,47,0,59610,64,0,1,0,0,'','Item drops if quest 59610 is not rewarded');

DELETE FROM `quest_template` WHERE `ID`=59610;
INSERT INTO `quest_template` (`ID`,`QuestType`,`RewardXPMultiplier`,`RewardMoneyMultiplier`,`RewardArtifactXPMultiplier`,`Flags`,`LogTitle`) VALUES
(59610,2,1,1,1,1024, '[Hidden Tracker] Torgok\'s Reagent Pouch Dropped');

-- Add missing scene spells "This will be updated in the future with end quest"
DELETE FROM `spell_area` WHERE `spell` IN (312605) AND `area` IN (10527);
DELETE FROM `spell_area` WHERE `spell` IN (321690,321691,321692,321693,325429) AND `area` IN (10424);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`flags`,`quest_start_status`,`quest_end_status`) VALUES
(312605,10527,55879,0,0,0,2,3,64,0),
(312605,10527,59942,0,0,0,2,3,64,0),
(321690,10424,55879,0,0,0,2,3,64,0),
(321690,10424,59942,0,0,0,2,3,64,0),
(321691,10424,55879,0,0,0,2,3,64,0),
(321691,10424,59942,0,0,0,2,3,64,0),
(321692,10424,55879,0,0,0,2,3,64,0),
(321692,10424,59942,0,0,0,2,3,64,0),
(321693,10424,55879,0,0,0,2,3,64,0),
(321693,10424,59942,0,0,0,2,3,64,0),
(325429,10424,59942,0,0,0,2,3,10,0);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceEntry` IN (325429));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(17, 0, 325429, 0, 0, 48, 0, 397279, 0, 8, '', 0, 'Caster of the spell has quest objective 397279 == 8 (but hasn\'t rewarded quest yet)');

-- Re-Deather

UPDATE `creature` SET `StringId` = 'shuja_grimaxe_ogre_ruins_prisoner' WHERE `guid`=8000024;
UPDATE `creature_template` SET `ScriptName`="npc_warlord_grimaxe_q59942" WHERE `entry`=167146;
UPDATE `creature_template` SET `ScriptName`="npc_prisoner_q55879" WHERE `entry`=167126;
UPDATE `creature_template` SET `npcflag`=16777216 WHERE entry IN (167142);

DELETE FROM `creature_equip_template` WHERE `CreatureID`=167146;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(167146, 1, 165616, 0, 0, 0, 0, 0, 0, 0, 0, 52808);

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (167142);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`,`InteractionPauseTimer`) VALUES
(167142,0,0,1,0,0,0,0); -- Choppy Booster Mk. 5

DELETE FROM `npc_vendor` WHERE `entry`=167213;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(167213, 2, 178120, 0, 0, 1, 0, 0, 52808),
(167213, 1, 117, 0, 0, 1, 0, 1, 52808);

-- Quest data
DELETE FROM `creature_queststarter` WHERE `id`=167019 AND `quest`=59942;
DELETE FROM `creature_queststarter` WHERE `id`=167212 AND `quest`=59950;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(167019, 59942, 52649), -- The Re-Deather accept from Cork Fizzlepop
(167212, 59950, 52649); -- Stocking Up on Supplies accept from Warlord Breka Grimaxe

DELETE FROM `creature_questender` WHERE `id`=167126 AND `quest`=59942;
DELETE FROM `creature_questender` WHERE `id`=167212 AND `quest`=59950;
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(167126, 59942, 52649), -- The Re-Deather turn in to Shuja Grimaxe
(167212, 59950, 52649); -- Stocking Up on Supplies turn in to Warlord Breka Grimaxe

DELETE FROM `quest_template_addon` WHERE `ID` IN (59942,59950);
INSERT INTO `quest_template_addon` (`ID`,`AllowableClasses`,`PrevQuestID`,`NextQuestID`,`ScriptName`) VALUES
(59942,0,59941,0,'quest_the_re_deather'), -- The Re-Deather
(59950,0,59942,0,''); -- Stocking Up on Supplies

-- Phase Area
DELETE FROM `phase_area` WHERE `AreaId`=10588 AND `PhaseId` IN (15331);
DELETE FROM `phase_area` WHERE `AreaId`=10424 AND `PhaseId` IN (15485,15447,15353,15338,15377);
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(10588,15331, 'Cosmetic - NPE - See Choppy Booster Mk. 5 for Re-Deather'),
(10424,15485, 'Cosmetic - NPE - See Warlord Breka Grimaxe at Ogre Ruins'),
(10424,15447, 'Cosmetic - NPE - See Grunt Throg at Ogre Ruins'),
(10424,15353, 'Cosmetic - NPE - See Shuja Grimaxe at Ogre Ruins pre quest at Ogre Ruins'),
(10424,15338, 'Cosmetic - NPE - See Won\'sa and Lana Jordan at Ogre Ruins pre quest at Ogre Ruins'),
(10424,15377, 'Cosmetic - NPE - See Mithdran Dawntracker at Ogre Ruins pre quest at Ogre Ruins');

-- Phase Names
DELETE FROM `phase_name` WHERE `ID` IN (15331,15485,15447,15353,15338,15377);
INSERT INTO `phase_name` (`ID`,`Name`) VALUES
(15331,'Cosmetic - NPE - See Choppy Booster Mk. 5 for Re-Deather'),
(15485,'Cosmetic - NPE - See Warlord Breka Grimaxe at Ogre Ruins'),
(15447,'Cosmetic - NPE - See Grunt Throg at Ogre Ruins'),
(15353,'Cosmetic - NPE - See Shuja Grimaxe at Ogre Ruins pre quest at Ogre Ruins'),
(15338,'Cosmetic - NPE - See Won\'sa and Lana Jordan at Ogre Ruins pre quest at Ogre Ruins'),
(15377,'Cosmetic - NPE - See Mithdran Dawntracker at Ogre Ruins pre quest at Ogre Ruins');

-- Phase Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (15331) AND `SourceEntry`=10588;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (15319) AND `ConditionValue1`=59942;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (13783) AND `ConditionValue1`=325368;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (15485,15447,15353,15338,15377,15553,15316,15315,15318) AND `ConditionValue1`=59942;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (15316) AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (14663,15327) AND `ConditionValue1`=59942;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (14663) AND `ConditionValue1`=397279;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,15331,10588, 0, 0, 47, 0, 59942, 8, 0, 0, 0, 0, '', 'Choppy Booster Mk. 5 if quest The Re-Deather is inprogress'),
(26,15331,10588, 0, 0, 1, 0, 325368, 0, 0, 1, 0, 0, '', 'See Choppy Booster Mk. 5 if player does not have aura'),
(26,15331,10588, 0, 0, 48, 0, 397279, 0, 0, 0, 0, 0, '', 'Player has quest objective 397279 == 0 (but hasn\'t rewarded quest yet)'),
(26,15319,10588, 0, 0, 47, 0, 59942, 1, 0, 0, 0, 0, '', 'Choppy Booster Mk. 5 if quest The Re-Deather is not taken'),
(26,13783,10529, 0, 0, 1, 0, 325368, 0, 0, 1, 0, 0, '', 'See See the Army of Undead if player does not have aura'),
(26,15485,10424, 0, 0, 47, 0, 59942, 64, 0, 0, 0, 0, '', 'See Warlord Breka Grimaxe at Ogre Ruins if quest The Re-Deather is rewarded'),
(26,15447,10424, 0, 0, 47, 0, 59942, 64, 0, 0, 0, 0, '', 'See Grunt Throg at Ogre Ruins if quest The Re-Deather is rewarded'),
(26,15353,10424, 0, 0, 47, 0, 59942, 64, 0, 0, 0, 0, '', 'See Shuja Grimaxe at Ogre Ruins pre quest if quest The Re-Deather is rewarded'),
(26,15338,10424, 0, 0, 47, 0, 59942, 64, 0, 0, 0, 0, '', 'See Won\'sa and Lana Jordan at Ogre Ruins pre quest if quest The Re-Deather is rewarded'),
(26,15377,10424, 0, 0, 47, 0, 59942, 64, 0, 0, 0, 0, '', 'See Mithdran Dawntracker at Ogre Ruins pre quest if quest The Re-Deather is rewarded'),
(26,15553,10588, 0, 0, 47, 0, 59942, 64, 0, 1, 0, 0, '', 'See Horde Crew at Darkmaul Plains if quest The Re-Deather is not rewarded'),
(26,15316,10588, 0, 0, 47, 0, 59942, 64, 0, 1, 0, 0, '', 'See Mithran Dawntracker at Darkmaul Plains if quest The Re-Deather is not rewarded'),
(26,15316,10588, 0, 1, 47, 0, 59942, 64, 0, 1, 0, 0, '', 'See Mithran Dawntracker at Darkmaul Plains if quest The Re-Deather is not rewarded'),
(26,15315,10588, 0, 0, 47, 0, 59942, 64, 0, 1, 0, 0, '', 'See Warlord Breka Grimaxe at Darkmaul Plains if quest The Re-Deather is not rewarded'),
(26,15318,10588, 0, 0, 47, 0, 59942, 64, 0, 1, 0, 0, '', 'See Cork Fizzlepop at Darkmaul Plains if quest The Re-Deather is not rewarded'),
(26,14663,10424, 0, 1, 47, 0, 59942, 64, 0, 1, 0, 0, '', 'See Torgok <Binder of Souls> if quest The Re-Deather is not rewarded'),
(26,14663,10424, 0, 1, 48, 0, 397279, 0, 8, 0, 0, 0, '', 'See Torgok <Binder of Souls> if quest Ride if player has objective complete'),
(26,15327,10424, 0, 0, 47, 0, 59942, 66, 0, 1, 0, 0, '', 'AND0 See Shuja Grimaxe at Ogre Ruins if quest  The Re-Deather is not completed | rewarded Horde.');

-- Add Scenes for The Re-Deather
DELETE FROM `scene_template` WHERE `SceneId` IN (2489,2489,2497,2423,2422,2421,2420);
INSERT INTO `scene_template` (`SceneId`,`Flags`,`ScriptPackageID`,`Encrypted`,`ScriptName`) VALUES
(2489,17,2896,0,'scene_darkmaul_plains_skeleton_army_horde'),
(2497,17,2933,0,''),
(2423,16,2825,0,''),
(2422,16,2824,0,''),
(2421,16,2823,0,''),
(2420,16,2822,0,'');

-- Spell Click
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (167142);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(167142,325368,1,0);

-- Condition for Spell click event condition type Queststate
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup` IN (167142) AND `SourceEntry` IN (325368) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 167142, 325368, 0, 0, 47, 0, 59942, 8, 0, 0, 0, 0, '', 'Spellclick unit Choppy Booster Mk. 5 will cast spell Riding Choppy Booster Mk 5 (DNT) on player if quest The Choppy Booster Mk. 5 queststate is INCOMPLETE');

-- Spell Target Position
DELETE FROM `spell_target_position` WHERE `ID` IN (325368);
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`VerifiedBuild`) VALUES
(325368,0,2175,107.87153,-2414.177,95.44844,52649);

-- Spell Target Position
DELETE FROM `spell_target_position` WHERE `ID` IN (325401);
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`VerifiedBuild`) VALUES
(325401,0,2175,233.55,-2332.52,80.84,52649);

-- Summon data for Warlord Grimaxe
DELETE FROM `creature_summoned_data` WHERE `CreatureID` IN (167146);
INSERT INTO `creature_summoned_data` (`CreatureID`,`CreatureIDVisibleToSummoner`,`GroundMountDisplayID`,`FlyingMountDisplayID`, `DespawnOnQuestsRemoved`) VALUES
(167146,167145,NULL,NULL,'');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (14525,14526,14527,15618);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(14525,36400,0,'',52649),
(14526,36402,0,'',52649),
(14527,36403,0,'',52649),
(15618,39171,0,'',52649);

DELETE FROM `conversation_actors` WHERE `ConversationId` IN (14525,14526,14527,15618);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(14525,75979,8000016,0,0,0,0,0,52649), -- Cork Fizzlepop
(14526,75979,0,0,167915,96314,0,0,52649), -- Cork Fizzlepop
(14527,76004,0,0,0,0,0,0,52649),
(14527,76357,0,1,0,0,0,0,52649),
(15618,76357,0,0,0,0,0,0,52649),
(15618,78501,0,1,0,0,0,0,52649);

DELETE FROM `conversation_line_template` WHERE `Id` IN (36400,36402,36403,36404,39171,39172,39173,39174,39175);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES
(36400,0,0,0,52649),
(36402,114,0,0,52649),
(36403,0,0,0,52649),
(36404,0,1,0,52649),
(39171,0,0,0,52649),
(39172,0,1,0,52649),
(39173,0,0,0,52649),
(39174,0,0,0,52649),
(39175,0,1,0,52649);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=14663 AND `ElseGroup`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,14663,10424, 0, 1, 47, 0, 59942, 64, 0, 1, 0, 0, '', 'See Torgok <Binder of Souls> if quest The Re-Deather is not rewarded'),
(26,14663,10424, 0, 1, 48, 0, 397279, 0, 8, 0, 0, 0, '', 'See Torgok <Binder of Souls> if quest Ride if player has objective complete');

-- Westward Bound

UPDATE `creature` SET `StringId`= "bjorn_stouthands_pit_pre_quest" WHERE `guid`=1051890;
UPDATE `creature` SET `StringId`= "alaria_pit_pre_quest" WHERE `guid`=1051889;
UPDATE `creature` SET `StringId`= "lana_joran_pit_pre_quest" WHERE `guid`=8000057;
UPDATE `creature` SET `StringId`= "wonsa_pit_pre_quest" WHERE `guid`=8000058;

UPDATE `creature_template` SET `npcflag`=2 WHERE `entry` IN (154300,156891,167225);
UPDATE `creature_template` SET `ScriptName`="npc_bjorn_stouthands_q55965" WHERE `entry`=156891;
UPDATE `creature_template` SET `ScriptName`="npc_alaria_q55965" WHERE `entry`=156803;
UPDATE `creature_template` SET `ScriptName`="npc_lana_jordan_q59948" WHERE `entry`=167225;
UPDATE `creature_template` SET `ScriptName`="npc_wonsa_q59948" WHERE `entry`=167226;

DELETE FROM `creature_template_addon` WHERE `entry` IN (156891,158803,167225,167226);
INSERT INTO `creature_template_addon` (`entry`,`visibilityDistanceType`,`emote`,`auras`) VALUES
(156891,3,0, ''), -- Bjorn Stouthands
(158803,3,0, ''), -- Alaria
(167225,3,0, ''), -- Lana Jordan
(167226,3,0, ''); -- Won'sa

DELETE FROM `creature_text` WHERE `CreatureID` IN (156891,167225);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(156891,0,0,'All right, let\'s see what we can find.', 12, 0, 100, 0, 0, 153011, 178906, 0, 'Bjorn Stouthands to Player'),
(156891,1,0,'Well... I think we can say we found somethin\'.', 12, 0, 100, 0, 0, 153012, 178907, 0, 'Bjorn Stouthands to Player'),
(167225,0,0,'Let\'s see if we can find one of those rituals.', 12, 0, 100, 0, 0, 155935, 196409, 0, 'Lana Jordan to Player'),
(167225,1,0,'A dark pit and darker magic. I think we found the ritual.', 12, 0, 100, 0, 0, 155936, 196410, 0, 'Lana Jordan to Player');

-- Pathing for Bjorn Stouthands Entry: 156891
SET @NPC := 1051890;
SET @PATH := @NPC * 10;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Bjorn Stouthands Ogre Ruins');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,143.74654,-2304.6077,89.66764,NULL,0),
(@PATH,2,129.32639,-2291.981,94.09912,NULL,0),
(@PATH,3,119.19444,-2285.2258,96.639084,NULL,0),
(@PATH,4,111.0816,-2275.9983,97.39326,NULL,0),
(@PATH,5,102.78819,-2265.302,96.73692,NULL,0),
(@PATH,6,89.68403,-2249.264,94.694824,NULL,0),
(@PATH,7,89.68403,-2249.264,94.694824,1.939347267150878906,0);

-- Pathing for Alaria Entry: 156803
SET @NPC := 1051889;
SET @PATH := @NPC * 10;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Alaria Ogre Ruins');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,165.59766,-2308.5781,83.23175,NULL,0),
(@PATH,2,153.73611,-2305.8403,86.4088,NULL,0),
(@PATH,3,140.17014,-2296.8699,90.521965,NULL,0),
(@PATH,4,129.96355,-2287.9636,95.05551,NULL,0),
(@PATH,5,91.98264,-2246.8298,94.39893,NULL,0),
(@PATH,6,91.98264,-2246.8298,94.39893,2.024514675140380859,0);

-- Pathing for Lana Jordan Entry: 167225
SET @NPC := @CGUID+16;
SET @PATH := @NPC * 10;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Lana Ogre Ruins');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,149.25081,-2299.1108,89.23349,NULL,0),
(@PATH,2,138.00081,-2287.6108,93.98349,NULL,0),
(@PATH,3,125.25081,-2278.8608,97.48349,NULL,0),
(@PATH,4,102.25081,-2260.3608,96.23349,NULL,0),
(@PATH,5,92.015625,-2246.9114,94.41398,NULL,0),
(@PATH,6,92.015625,-2246.9114,94.41398,2.622560739517211914,0);

-- Pathing for Won'sa Entry: 167226
SET @NPC := @CGUID+17;
SET @PATH := @NPC * 10;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Wansa Ogre Ruins');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,146.84831,-2298.0352,89.56113,NULL,0),
(@PATH,2,134.59831,-2287.7852,94.81113,NULL,0),
(@PATH,3,112.09831,-2268.2852,97.31113,NULL,0),
(@PATH,4,94.09831,-2252.7852,95.06113,NULL,0),
(@PATH,5,89.265625,-2248.9602,94.66245,NULL,0),
(@PATH,6,89.265625,-2248.9602,94.66245,1.861210823059082031,0);

-- Quest data
DELETE FROM `creature_queststarter` WHERE `id`=154300 AND `quest`=55965;
DELETE FROM `creature_queststarter` WHERE `id`=167221 AND `quest`=59948;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(154300, 55965, 52649), -- Westward Bound accept from Bjorn Stouthands Alliance
(167221, 59948, 52649); -- Westward Bound accept from Lana Jordan Horde

DELETE FROM `creature_questender` WHERE `id`=156891 AND `quest`=55965;
DELETE FROM `creature_questender` WHERE `id`=167225 AND `quest`=59948;
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(156891, 55965, 52649), -- Westward Bound turn in to Bjorn Stouthands Alliance
(167225, 59948, 52649); -- Westward Bound turn in to Lana Jordan Horde

DELETE FROM `quest_template_addon` WHERE `ID` IN (55965,59948);
INSERT INTO `quest_template_addon` (`ID`,`AllowableClasses`,`PrevQuestID`,`NextQuestID`,`ScriptName`) VALUES
(55965,0,55194,0,'quest_westward_bound_alliance'), -- Westward Bound Alliance
(59948,0,59950,0,'quest_westward_bound_horde'); -- Westward Bound Horde

-- Phase Area
DELETE FROM `phase_area` WHERE `AreaId`=10424 AND `PhaseId` IN (15337);
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(10424,15337, 'Cosmetic - NPE - See Won\'sa and Lana Jordan at pit pre quest');

-- Phase Names
DELETE FROM `phase_name` WHERE `ID` IN (15337);
INSERT INTO `phase_name` (`ID`,`Name`) VALUES
(15337,'Cosmetic - NPE - See Won\'sa and Lana Jordan at pit pre quest');

-- Phase Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (15338,15337) AND `ConditionValue1` IN (59948,59949);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,15338,10424, 0, 0, 47, 0, 59948, 74, 0, 1, 0, 0, '', 'See Won\'sa and Lana Jordan at Ogre Ruins pre quest if quest Westward Bound is not taken | complete | rewarded'),
(26,15337,10424, 0, 0, 47, 0, 59948, 74, 0, 0, 0, 0, '', 'See Won\'sa and Lana Jordan at pit pre quest if quest Westward Bound is taken | complete | rewarded'),
(26,15337,10424, 0, 0, 47, 0, 59949, 66, 0, 1, 0, 0, '', 'See Won\'sa and Lana Jordan at pit pre quest if quest Who Lurks in the Pit is not complete | rewarded');

UPDATE `creature` SET `PhaseUseFlags`=`PhaseUseFlags` | 0x01 WHERE `guid` IN(1051317, 1051942); -- fix spirithealer phases

UPDATE `creature_template_difficulty` SET `ContentTuningID`=957, `VerifiedBuild`=53262 WHERE (`Entry`=167146 AND `DifficultyID`=0); -- Horde Warrior
UPDATE `creature_template_difficulty` SET `ContentTuningID`=741, `VerifiedBuild`=53262 WHERE (`Entry`=167905 AND `DifficultyID`=0); -- Choppy Booster Mk. 5
UPDATE `creature_template_difficulty` SET `ContentTuningID`=741, `VerifiedBuild`=53262 WHERE (`Entry`=167915 AND `DifficultyID`=0); -- Cork Fizzlepop

UPDATE `creature_template` SET `faction`=116, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=16 WHERE `entry`=167146; -- Horde Warrior

DELETE FROM `phase_area` WHERE `AreaId`=10424 AND `PhaseId` IN (15558, 13795);
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(10424,15558, 'Cosmetic - NPE - See Breka and Shuja Grimaxe after freeing Shuja'),
(10424,13795, 'Cosmetic - NPE - See Captain and Henry Garrick after freeing Henry');

DELETE FROM `phase_name` WHERE `ID` IN (15558, 13795);
INSERT INTO `phase_name` (`ID`,`Name`) VALUES
(15558,'Cosmetic - NPE - See Breka and Shuja Grimaxe after freeing Shuja'),
(13795,'Cosmetic - NPE - See Captain and Henry Garrick after freeing Henry');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 26 AND `SourceEntry`=10424 AND `SourceGroup` IN(15558,13795);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 15558, 10424, 0, 0, 28, 0, 59942, 0, 0, '', 0, 'Player has completed quest quest The Re-Deather (59942) (but not yet rewarded)'),
(26, 13795, 10424, 0, 0, 28, 0, 55879, 0, 0, '', 0, 'Player has completed quest quest Ride of the Scientifically Enhanced Boar (55879) (but not yet rewarded)');

DELETE FROM `creature_template_addon` WHERE `entry` IN(156799, 167126);
DELETE FROM `creature_addon` WHERE `guid` IN(8000023, 8000024);
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(8000023, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '305513 325408'),
(8000024, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '305513 325408');

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN(156799, 167126);
DELETE FROM `creature_movement_override` WHERE `SpawnId` IN(8000023, 8000024);
INSERT INTO `creature_movement_override` (`SpawnId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(8000023, 1, 1, 1, 0, 0, 0, 0),
(8000024, 1, 1, 1, 0, 0, 0, 0);

DELETE FROM `quest_request_items` WHERE `ID`=55879;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(55879, 0, 0, 0, 0, 'Please... help! I won\'t last much longer!', 53262); -- Ride of the Scientifically Enhanced Boar

UPDATE `creature_template_difficulty` SET `ContentTuningID`=741, `VerifiedBuild`=53262 WHERE (`Entry`=156267 AND `DifficultyID`=0); -- Giant Boar
UPDATE `creature_template_difficulty` SET `ContentTuningID`=741, `VerifiedBuild`=53262 WHERE (`Entry`=156736 AND `DifficultyID`=0); -- Re-sized Boar
UPDATE `creature_template_difficulty` SET `ContentTuningID`=741, `VerifiedBuild`=53262 WHERE (`Entry`=156749 AND `DifficultyID`=0); -- Lindie Springstock
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1421, `VerifiedBuild`=53262 WHERE (`Entry`=174955 AND `DifficultyID`=0); -- Alliance Captain

UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=156807; -- Captain Garrick
UPDATE `creature_template` SET `faction`=2142, `speed_walk`=6.40000009536743164, `speed_run`=2.285714387893676757, `BaseAttackTime`=2000, `RangeAttackTime`=0, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=156267; -- Giant Boar
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=156595; -- Giant Boar
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048, `unit_flags3`=67633152 WHERE `entry`=156736; -- Re-sized Boar
UPDATE `creature_template` SET `faction`=2618, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=156749; -- Lindie Springstock
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=156799; -- Henry Garrick
UPDATE `creature_template` SET `faction`=4, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=174955; -- Alliance Captain
