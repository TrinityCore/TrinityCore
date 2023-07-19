SET @CGUID := 850277;
SET @OGUID := 500934;

-- Areatrigger templates
DELETE FROM `areatrigger_template` WHERE (`Id`=5379 AND `IsServerSide`=0);
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) VALUES
(5379, 0, 0, 4, 8, 8, 0, 0, 0, 0, 0, 0, 45745);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=1342;
INSERT INTO `areatrigger_create_properties` (`Id`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(1342, 5379, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 45745); -- SpellId : 302192

-- Creature templates
UPDATE `creature_template` SET `gossip_menu_id`=8988 WHERE `entry`=19148; -- Dwarf Commoner
UPDATE `creature_template` SET `gossip_menu_id`=8988 WHERE `entry`=19172; -- Gnome Commoner
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23481; -- Keiran Donoghue
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23486; -- Goldark Snipehunter
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23487; -- Wild Wolpertinger
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23488; -- Brewfest Crowd
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=24364; -- Flynn Firebrew
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23521; -- Anne Summers
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23522; -- Arlen Lochlan
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23558; -- Neill Ramstein
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23627; -- Becan Barleybrew
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23628; -- Daran Thunderbrew
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23683; -- Maeve Barleybrew
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23684; -- Ita Thunderbrew
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23685; -- Gordok Brew Barker
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23696; -- Gordok Brew Chief
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23710; -- Belbi Quikswitch
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=24108; -- Self-Turning and Oscillating Utility Target
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=24463; -- Swift Racing Ram
UPDATE `creature_template` SET `gossip_menu_id`=8958, `minlevel`=60, `maxlevel`=60 WHERE `entry`=24468; -- Pol Amberstill
UPDATE `creature_template` SET `gossip_menu_id`=8994, `minlevel`=60, `maxlevel`=60 WHERE `entry`=24710; -- Ipfelkofer Ironkeg
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `flags_extra`=`flags_extra`|128 WHERE `entry`=24766; -- [DND] Brewfest Face Me Bunny
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=27215; -- Boxey Boltspinner
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=73913; -- Brewmaster Tsing
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=16777216, `flags_extra`=`flags_extra`|128 WHERE `entry`=152643; -- Despawn Bunny
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=152829; -- Arcti
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=152849; -- Vinter Tysiel
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=152871; -- Brewer Gerrat
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=152941; -- Verra Fireblood
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=153029; -- Lucky Sachi
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=153030; -- Haru
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=153054; -- Racing Ram
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=153146; -- Su Li
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=153166; -- Sobrietus
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `unit_flags3`=16777216 WHERE `entry`=153198; -- Chowdown Participant's Seat
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=16777216 WHERE `entry`=153227; -- Chowdown Participant's Platter
UPDATE `creature_template` SET `gossip_menu_id`=24211 WHERE `entry`=153574; -- Britta Steinheart
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=154003; -- Melanie Charles
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=55, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=154012; -- Ragnar Thunderbrew
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=55, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=154013; -- Marleth Barleybrew
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=16777216, `flags_extra`=`flags_extra`|128 WHERE `entry`=154078; -- Brewfest Crowd
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=16777216, `flags_extra`=`flags_extra`|128 WHERE `entry`=154086; -- Keg Tap
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=154463; -- Mischevious Alemental
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=16777216, `flags_extra`=`flags_extra`|128 WHERE `entry`=154477; -- Event Controller
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=16777216, `flags_extra`=`flags_extra`|128 WHERE `entry`=154508; -- Alemental Controller
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=16777216, `flags_extra`=`flags_extra`|128 WHERE `entry`=154605; -- Dark Iron Controller
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=154632; -- Direbrew Invader
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags`=768 WHERE `entry`=154729; -- Hozen Raider
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=16777216, `flags_extra`=`flags_extra`|128 WHERE `entry`=154730; -- Hozen Controller
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=154745; -- Hozen Flyer
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=16777216, `flags_extra`=`flags_extra`|128 WHERE `entry`=154765; -- Hozen Bunny
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=16777216 WHERE `entry`=155303; -- Apple Bucket
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=155345; -- [DNT] Brewfest Music
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=155602; -- Hozen Raider
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry` IN (153098, 153101, 153102, 153104, 153159, 153160, 153161, 153162); -- Brewfest Reveler

DELETE FROM `creature_template_addon` WHERE `entry` IN (19148, 19172, 73913, 152643, 152829, 152849, 152871, 152941, 153029, 153030, 153054, 153098, 153101, 153102, 153104, 153146, 153159, 153160, 153161, 153162, 153166, 153198, 153227, 153574, 153931, 154003, 154012, 154013, 154078, 154086, 154463, 154477, 154508, 154605, 154632, 154729, 154730, 154745, 154765, 155303, 155345, 155345, 155602);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(19148, 0, 0, 0, 257, 0, 0, 0, 0, 0, '33209 33207 33208'), -- Aura 65511 - Gossip NPC Appearance (only during Brewfest)
(19172, 0, 0, 0, 257, 0, 0, 0, 0, 0, '33209 33207 33208'), -- Aura 65511 - Gossip NPC Appearance (only during Brewfest)
(73913, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 73913 (Brewmaster Tsing)
(152643, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 152643 (Despawn Bunny) - Aura 182641 - Game Object Despawn Periodic (deleted until we know what it should affect)
(152829, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 152829 (Arcti)
(152849, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 152849 (Vinter Tysiel)
(152871, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 152871 (Brewer Gerrat)
(152941, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 152941 (Verra Fireblood)
(153029, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 153029 (Lucky Sachi)
(153030, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 153030 (Haru)
(153054, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 153054 (Racing Ram)
(153098, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153098 (Brewfest Reveler)
(153101, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153101 (Brewfest Reveler)
(153102, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153102 (Brewfest Reveler)
(153104, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153104 (Brewfest Reveler)
(153146, 0, 0, 0, 1, 0, 0, 0, 0, 0, '297197'), -- 153146 (Su Li)
(153159, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153159 (Brewfest Reveler)
(153160, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153160 (Brewfest Reveler)
(153161, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153161 (Brewfest Reveler)
(153162, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153162 (Brewfest Reveler)
(153166, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153166 (Sobrietus)
(153198, 0, 0, 0, 1, 0, 0, 0, 0, 0, '297978'), -- 153198 (Chowdown Participant's Seat) - [DNT] Seat Preparation
(153227, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 153227 (Chowdown Participant's Platter) - Ride Vehicle Hardcoded
(153574, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 153574 (Britta Steinheart) - [DNT] Chowdown Organizer
(153931, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153931 (Brewfest Reveler)
(154003, 0, 0, 0, 1, 0, 0, 0, 0, 0, '299038'), -- 154003 (Melanie Charles) - Serving Platter
(154012, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 154012 (Ragnar Thunderbrew)
(154013, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 154013 (Marleth Barleybrew)
(154078, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 154078 (Brewfest Crowd)
(154086, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 154086 (Keg Tap)
(154463, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 154463 (Mischevious Alemental)
(154477, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 154477 (Event Controller)
(154508, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 154508 (Alemental Controller)
(154605, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 154605 (Dark Iron Controller)
(154632, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 154632 (Direbrew Invader)
(154729, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 154729 (Hozen Raider)
(154730, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 154730 (Hozen Controller)
(154745, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- 154745 (Hozen Flyer)
(154765, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 154765 (Hozen Bunny)
(155303, 0, 0, 0, 1, 0, 0, 0, 0, 4, '302192'), -- 155303 (Apple Bucket)
(155345, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 155345 ([DNT] Brewfest Music)
(155602, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''); -- 155602 (Hozen Raider)

UPDATE `creature_template_addon` SET `bytes1`=65536, `auras`='39707 29920' WHERE `entry`=23487; -- 23487 (Wild Wolpertinger)
UPDATE `creature_template_addon` SET `auras`='268057' WHERE `entry`=23521; -- 23521 (Anne Summers) - Cradle Basket
UPDATE `creature_template_addon` SET `auras`='281819' WHERE `entry`=23627; -- 23627 (Becan Barleybrew) - Bar Tend Stand
UPDATE `creature_template_addon` SET `auras`='281819' WHERE `entry`=23628; -- 23628 (Daran Thunderbrew) - Bar Tend Stand

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (23488, 152643, 153198, 153227, 154078, 154086, 154477, 154508, 154605, 154730, 154745, 154765, 155303, 155345);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(23488, 0, 0, 1, 0, 0, 0, NULL),
(152643, 0, 0, 1, 1, 0, 0, NULL),
(153198, 0, 0, 1, 1, 0, 0, NULL),
(153227, 0, 0, 1, 1, 0, 0, NULL),
(154078, 0, 0, 1, 1, 0, 0, NULL),
(154086, 0, 0, 1, 1, 0, 0, NULL),
(154477, 0, 0, 1, 1, 0, 0, NULL),
(154508, 0, 0, 1, 1, 0, 0, NULL),
(154605, 0, 0, 1, 1, 0, 0, NULL),
(154730, 0, 0, 1, 1, 0, 0, NULL),
(154745, 0, 0, 1, 0, 0, 0, NULL),
(154765, 0, 0, 1, 1, 0, 0, NULL),
(155303, 0, 0, 1, 1, 0, 0, NULL),
(155345, 0, 0, 1, 1, 0, 0, NULL);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (153198, 154729, 154745, 155602);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(153198, 105080, 1, 0),
(154729, 300956, 1, 0),
(154745, 300956, 1, 0),
(155602, 300956, 1, 0);

-- Vehicle data
DELETE FROM `vehicle_template_accessory` WHERE `entry`=154765;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(154765, 154729, 0, 0, 'Hozen Bunny - Hozen Raider', 8, 0); -- Hozen Bunny - Hozen Raider

DELETE FROM `vehicle_seat_addon` WHERE `SeatEntry`=20613;
INSERT INTO `vehicle_seat_addon` (`SeatEntry`, `SeatOrientation`, `ExitParamX`, `ExitParamY`, `ExitParamZ`, `ExitParamO`, `ExitParamValue`) VALUES
(20613, 0, 2.928, 0, 0, 0, 1);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=154765;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(154765, 46598, 0, 0);

DELETE FROM `creature_template_spell` WHERE `CreatureID`=153198;
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES
(153198, 2, 303242, 45745), -- Chowdown Participant's Seat
(153198, 1, 303241, 45745), -- Chowdown Participant's Seat
(153198, 0, 303240, 45745); -- Chowdown Participant's Seat

-- Gossips
DELETE FROM `gossip_menu` WHERE `MenuID` IN (24211, 24308);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(24211, 37918, 45745), -- 153574 (Britta Steinheart)
(24308, 38124, 45745); -- 153574 (Britta Steinheart)

UPDATE `gossip_menu` SET `VerifiedBuild`=45745 WHERE `MenuID`=8988 AND `TextID`=12134;

DELETE FROM `gossip_menu_option` WHERE `MenuID`=24211;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(24211, 0, 0, 'How do I play?', 176229, 1, 0, 24308, 0, 0, 0, NULL, 0, 45745),
(24211, 1, 1, 'I would like to retrieve my trophy.', 177504, 128, 0, 0, 0, 0, 0, NULL, 0, 45745);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=8958 AND `OptionID`=6;
UPDATE `gossip_menu_option` SET `ActionPoiID`=0 WHERE `MenuID`=8783 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `VerifiedBuild`=45745 WHERE `MenuID` IN (8783, 8955, 8958, 8959, 8960, 8961, 8962, 8963, 9006, 9561, 10604);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8988 AND `SourceEntry`=12134;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (8958, 8960, 9006);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,8988,12134,0,0,12,0,24,0,0,0,0,0,'','Show gossip text if event "Brewfest" is active'),
(15,9006,0,0,0,2,0,46735,1,1,1,0,0,'','Show gossip option if the player does not have the item 46735');

-- Equipments
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=153102 AND `ID`=6) OR (`CreatureID`=153162 AND `ID`=5) OR (`CreatureID`=153161 AND `ID`=4) OR (`ID`=1 AND `CreatureID` IN (154013,154012)) OR (`ID`=4 AND `CreatureID`=153101);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(154012, 1, 168670, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Ragnar Thunderbrew
(154013, 1, 168670, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Marleth Barleybrew
(153101, 4, 37059, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler
(153102, 6, 159383, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler
(153161, 4, 37059, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler
(153162, 5, 46733, 0, 0, 0, 0, 0, 0, 0, 0, 45745); -- Brewfest Reveler

-- Scaling
DELETE FROM `creature_template_scaling` WHERE `DifficultyID`=0 AND `Entry` IN (24364, 23481, 23486, 23487, 23488, 23521, 23522, 23558, 23627, 23628, 23683, 23684, 23685, 23696, 23710, 24108, 24463, 24468, 24710, 24766, 27215, 73913, 152829, 152849, 152871, 152941, 153029, 153030, 153054, 153098, 153101, 153102, 153104, 153146, 153159, 153160, 153161, 153162, 153166, 153198, 153227, 153574, 154003, 154012, 154013, 154078, 154086, 154463, 154477, 154508, 154605, 154632, 154729, 154730, 154745, 154765, 155303, 155602);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(24364, 0, 0, 0, 298, 45745),
(23481, 0, 0, 0, 298, 45745),
(23486, 0, 0, 0, 298, 45745),
(23487, 0, 0, 0, 298, 45745),
(23488, 0, 0, 0, 298, 45745),
(23521, 0, 0, 0, 298, 45745),
(23522, 0, 0, 0, 298, 45745),
(23558, 0, 0, 0, 298, 45745),
(23627, 0, 0, 0, 298, 45745),
(23628, 0, 0, 0, 298, 45745),
(23683, 0, 0, 0, 298, 45745),
(23684, 0, 0, 0, 298, 45745),
(23685, 0, 0, 0, 298, 45745),
(23696, 0, 0, 0, 298, 45745),
(23710, 0, 0, 0, 298, 45745),
(24108, 0, 0, 0, 298, 45745),
(24463, 0, 0, 0, 872, 45745),
(24468, 0, 0, 0, 298, 45745),
(24710, 0, 0, 0, 298, 45745),
(24766, 0, 0, 0, 298, 45745),
(27215, 0, 0, 0, 298, 45745),
(73913, 0, 0, 0, 298, 45745),
(152829, 0, 0, 0, 298, 45745),
(152849, 0, 0, 0, 298, 45745),
(152871, 0, 0, 0, 298, 45745),
(152941, 0, 0, 0, 298, 45745),
(153029, 0, 0, 0, 298, 45745),
(153030, 0, 0, 0, 298, 45745),
(153054, 0, 0, 0, 298, 45745),
(153098, 0, 0, 0, 298, 45745),
(153101, 0, 0, 0, 298, 45745),
(153102, 0, 0, 0, 298, 45745),
(153104, 0, 0, 0, 298, 45745),
(153146, 0, 0, 0, 298, 45745),
(153159, 0, 0, 0, 298, 45745),
(153160, 0, 0, 0, 298, 45745),
(153161, 0, 0, 0, 298, 45745),
(153162, 0, 0, 0, 298, 45745),
(153166, 0, 0, 0, 298, 45745),
(153198, 0, 0, 0, 2068, 45745),
(153227, 0, 0, 0, 298, 45745),
(153574, 0, 0, 0, 298, 45745),
(154003, 0, 0, 0, 298, 45745),
(154012, 0, 0, 0, 298, 45745),
(154013, 0, 0, 0, 298, 45745),
(154078, 0, 0, 0, 298, 45745),
(154086, 0, 0, 0, 298, 45745),
(154463, 0, 0, 0, 298, 45745),
(154477, 0, 0, 0, 298, 45745),
(154508, 0, 0, 0, 298, 45745),
(154605, 0, 0, 0, 298, 45745),
(154632, 0, 0, 0, 2068, 45745),
(154729, 0, 0, 0, 2068, 45745),
(154730, 0, 0, 0, 298, 45745),
(154745, 0, 0, 0, 2068, 45745),
(154765, 0, 0, 0, 298, 45745),
(155303, 0, 0, 0, 298, 45745),
(155602, 0, 0, 0, 2068, 45745);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=45745 WHERE (`DifficultyID`=0 AND `Entry` IN (41182,41175,41188,41189,6119,12427,43701,41335,2878,6328,1252,5612,40950,47396,1269,1378,1377,40951,1692,1231,1273,1238,1373,1241,1240,1375,1229,9980,1234,1374,2326,1267,1699,1247,1691,1232,1226,6806,1228,11941,43464,1872,63075,63074,1245,43224,1690,41181,40994,41056,42933,40939,40941,12996,14552,1268,5568,32639,32638,23511,41122,41121,61689,152643,727,23482,23510,1125,41478,61690,122323,52335,6181,155345,153931,14367,1959,11146,6031,4259,16013,50309,50308,1573,2092,5150,5138,5137,5605,5140,5570,8517,2695,6114,10090,34991,7298,5116,5115,5113,5117,9984,35007,1901,5114,31146,7976,5119,5120,5124,5121,153285,5129,5126,5125,2790,51495,6175,5049,5130,5101,5100,5132,1274,8879,52321,51596,5099,5103,5102,2461,19148,8720,9859,53568,8671,2460,40441,7292,49748,5109,5108,13843,5107,5106,5110,89830,27478,14183,62425,5112,5111,29141,118889,2918,34281,42147,42146,42129,51978,51976,42928,14363,5128,5127,42131,1466,6291,121541,5152,5133,5149,5148,5147,5141,6178,5143,2489,5142,50717,50720,50716,5146,5145,7978,5151,5144,8507,7312,11406,6179,175411,175410,175412,5153,8681,6826,5154,5155,5156,1703,5163,6120,10455,5170,5162,5161,53544,10456,10277,10276,42152,11145,4258,50732,5172,2943,5173,2786,15186,50729,50723,5167,5171,2737,5165,6382,97762,7936,4254,5166,5169,52586,3842,52584,4256,9099,23127,35073,61317,8256,6294,39718,2916,1356,3979,5637,5387,62822,62821,9616,5160,5159,48972,51383,14365,19172,6169,175403,7950,7944,5178,5177,5175,4081,5174,10877,47582,5123,5122,5158,5157,96490,1246,6569,30733,5569,5595,30717,11065,24110,48935,11029,11028));

-- Models
UPDATE `creature_template_model` SET `VerifiedBuild`=45745 WHERE (`Idx`=0 AND `CreatureID` IN (9980,106283,153227,153098,122323,175411,2786,97762,5159,5178,5177,7944,27215,153159,7298,5113,5114,53568,13843,5152,5148,11406,52586,4254,9099,5123,1252,12996,61689,23684,11146,2092,8671,5127,50720,8507,6826,50723,5637,14365,11028,5595,1269,1228,40939,24364,153166,23710,14367,50309,34991,5049,7292,5112,34281,1466,5141,50717,6120,5172,23127,5387,51383,11029,96490,48935,41175,1267,1690,153162,153029,24108,152849,154003,5140,9984,153285,2790,5132,1274,2461,19148,27478,42147,42146,2489,175412,2943,4256,5160,6569,6119,41335,1375,1232,73913,24463,153574,154086,16013,5124,5126,14183,118889,51978,6179,5156,10277,62822,5122,19172,43701,6328,1377,1374,6806,63074,40941,14552,132969,153160,153030,153104,24710,5108,42131,6178,5143,5146,5144,5154,53544,2737,35073,5158,24110,41188,40950,1247,63075,174170,23511,23488,154078,61690,155303,155345,153931,50308,2695,5121,9859,5106,5111,2918,51976,5151,10455,4258,6382,7936,47582,175403,40951,1273,1240,1699,40994,41056,42933,32639,16085,23521,24766,23628,5137,5570,35007,51495,5100,52321,5099,5128,6291,7978,5163,5170,50729,5169,62821,6169,1246,1238,153146,41121,23481,152643,153101,1959,5150,5138,1901,31146,5130,5102,49748,121541,11145,50732,2916,3979,9616,5175,5157,1378,1231,1241,1229,2326,43464,41122,154477,1125,6031,7976,8720,5107,8681,5155,5166,7950,41182,41189,12427,1373,1226,23696,24468,152829,23683,23510,4259,1573,8517,5119,6175,8879,5109,175410,10456,5167,39718,48972,59979,30733,5612,153198,153161,23482,152941,128396,5605,5115,5117,2460,89830,42129,42928,10276,5173,5171,1356,5569,11065,2878,47396,1234,11941,1245,5568,1268,23685,23522,10090,5120,5101,51596,40441,62425,29141,5147,50716,1703,5165,52584,10877,4081,1692,727,153102,41478,6181,5116,5125,5103,5110,5149,5142,5145,7312,5153,5162,15186,165189,5174,175155,1691,43224,1872,41181,32638,153054,23486,23558,23627,152871,52335,6114,5129,14363,5133,5161,42152,3842,61317,8256,6294,30717)) OR (`Idx`=3 AND `CreatureID` IN (153098,153159,5595,51383,153162,41335,153160,153104,153931,153101,153161,89830,5568,153102,41181)) OR (`Idx`=2 AND `CreatureID` IN (153098,153159,53568,5595,51383,41175,153162,42147,41335,153160,153104,153931,153101,41182,59979,153161,89830,5568,153102,43224,41181)) OR (`Idx`=1 AND `CreatureID` IN (153098,122323,153159,53568,12996,5595,40939,34281,51383,41175,153162,19148,42147,41335,154086,19172,40941,153160,153104,24110,41188,23488,154078,155303,155345,153931,24766,41121,152643,153101,41122,154477,41182,41189,48972,59979,153161,89830,5568,727,153102,43224,41181,42152,61317)) OR (`Idx`=7 AND `CreatureID` IN (5595,51383)) OR (`Idx`=6 AND `CreatureID` IN (5595,51383)) OR (`Idx`=5 AND `CreatureID` IN (5595,51383)) OR (`Idx`=4 AND `CreatureID` IN (5595,51383));

UPDATE `creature_model_info` SET `VerifiedBuild`=45745 WHERE `DisplayID` IN (32334, 3762, 3837, 1801, 32336, 22769, 4864, 12474, 32403, 31934, 5040, 5042, 1376, 3607, 32194, 35581, 3440, 5105, 5106, 1786, 1811, 3414, 3558, 3417, 3420, 3438, 3422, 3425, 3405, 3431, 9253, 3436, 3398, 3433, 1684, 3435, 3434, 3430, 1622, 3429, 5525, 10215, 11899, 33381, 33279, 3415, 30586, 328, 3513, 33278, 1608, 3427, 1782, 32240, 381, 1785, 32193, 33141, 950, 14376, 22449, 3441, 28282, 28111, 21859, 91758, 51672, 21861, 21860, 22628, 27499, 27498, 27494, 42203, 22631, 22630, 91664, 91663, 91738, 21863, 22162, 22390, 91752, 91615, 21574, 24419, 22603, 91772, 91843, 1598, 22454, 22455, 91737, 91954, 22384, 22385, 21849, 91750, 21853, 91614, 91744, 91732, 21836, 22394, 22450, 16925, 91751, 21837, 91653, 21844, 91731, 21847, 21701, 22396, 91747, 91620, 91745, 22451, 607, 604, 92423, 37844, 4893, 43152, 91742, 21842, 21843, 91733, 91746, 21845, 304, 14405, 1891, 10694, 4950, 3098, 15965, 37017, 37018, 3007, 3600, 3068, 3064, 3063, 3591, 3065, 3458, 7598, 1670, 4995, 9338, 29512, 6062, 3072, 3056, 3054, 3073, 9258, 29520, 3053, 3055, 27510, 7120, 3075, 3057, 3078, 3076, 28048, 37350, 3106, 3080, 3079, 5410, 37401, 4889, 2999, 3081, 3041, 3040, 3107, 1655, 8171, 37836, 37514, 3039, 3043, 3042, 3038, 21848, 21846, 7989, 9131, 26184, 7990, 3037, 31847, 6588, 36597, 3050, 3049, 13850, 3045, 3044, 3046, 24982, 22397, 14235, 42481, 3051, 3047, 25955, 99840, 74943, 3598, 8755, 9289, 8826, 32680, 99842, 37695, 37693, 99841, 33140, 14396, 3105, 3104, 32681, 10620, 4986, 27823, 3110, 3082, 3087, 3088, 3089, 3086, 4891, 3085, 10548, 3066, 36936, 36934, 36937, 3109, 10214, 7119, 3119, 3108, 7805, 6072, 11053, 4892, 99617, 3091, 7951, 5647, 3069, 3070, 3071, 10629, 3112, 4865, 9818, 3103, 3121, 3096, 15395, 9821, 9740, 9741, 10693, 3097, 36940, 3116, 7916, 3122, 3599, 15369, 36941, 36938, 3113, 3115, 9817, 3101, 5085, 65406, 7003, 3092, 3100, 3114, 37957, 1935, 37956, 3093, 99838, 8353, 21265, 29573, 7769, 4988, 35687, 3595, 3594, 2049, 3756, 3596, 36357, 42722, 42720, 8829, 3095, 3094, 4959, 3526, 77915, 99839, 37351, 14404, 99837, 21851, 21850, 4999, 99600, 7041, 7028, 3125, 3124, 3118, 2184, 3117, 10184, 35706, 99836, 5408, 3077, 3120, 3111, 64921, 10635, 3525, 5377, 3524, 27298, 3457, 3527, 27274, 10588, 11686, 36342, 10722, 10571);
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=45745 WHERE `DisplayID`=6926;
UPDATE `creature_model_info` SET `BoundingRadius`=0.292084097862243652, `VerifiedBuild`=45745 WHERE `DisplayID`=85209;
UPDATE `creature_model_info` SET `BoundingRadius`=0.89310389757156372, `CombatReach`=0.75, `VerifiedBuild`=45745 WHERE `DisplayID`=88619;
UPDATE `creature_model_info` SET `BoundingRadius`=0.166421771049499511, `CombatReach`=0.60000002384185791, `VerifiedBuild`=45745 WHERE `DisplayID`=5554;
UPDATE `creature_model_info` SET `BoundingRadius`=0.199706122279167175, `CombatReach`=0.719999969005584716, `VerifiedBuild`=45745 WHERE `DisplayID`=88407;

-- Vendor Data
DELETE FROM `npc_vendor` WHERE (`entry`=153166 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=154003 AND `item`=34065 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=154003 AND `item`=33043 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152941 AND `item`=163143 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152941 AND `item`=169436 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152941 AND `item`=170202 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152941 AND `item`=169439 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152871 AND `item`=163019 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152871 AND `item`=163103 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152871 AND `item`=162560 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152871 AND `item`=169397 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73913 AND `item`=105704 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73913 AND `item`=105707 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73913 AND `item`=105703 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73913 AND `item`=105708 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73913 AND `item`=105706 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73913 AND `item`=105700 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73913 AND `item`=105701 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73913 AND `item`=105711 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73913 AND `item`=105705 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73913 AND `item`=105702 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153146 AND `item`=105704 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153146 AND `item`=105707 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153146 AND `item`=105703 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153146 AND `item`=105708 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153146 AND `item`=105706 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153146 AND `item`=105700 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153146 AND `item`=105701 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153146 AND `item`=105711 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153146 AND `item`=105705 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153146 AND `item`=105702 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23522 AND `item`=82451 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23522 AND `item`=82450 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23481 AND `item`=138884 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23481 AND `item`=138900 AND `ExtendedCost`=2275 AND `type`=1) OR (`entry`=23710 AND `item`=37736 AND `ExtendedCost`=2397 AND `type`=1) OR (`entry`=23710 AND `item`=187998 AND `ExtendedCost`=5795 AND `type`=1) OR (`entry`=23710 AND `item`=167732 AND `ExtendedCost`=5795 AND `type`=1) OR (`entry`=23710 AND `item`=151615 AND `ExtendedCost`=5795 AND `type`=1) OR (`entry`=23710 AND `item`=122341 AND `ExtendedCost`=5795 AND `type`=1) OR (`entry`=23710 AND `item`=122339 AND `ExtendedCost`=5794 AND `type`=1) OR (`entry`=23710 AND `item`=166747 AND `ExtendedCost`=2276 AND `type`=1) OR (`entry`=23710 AND `item`=138730 AND `ExtendedCost`=2276 AND `type`=1) OR (`entry`=23710 AND `item`=116758 AND `ExtendedCost`=2275 AND `type`=1) OR (`entry`=23710 AND `item`=116757 AND `ExtendedCost`=2276 AND `type`=1) OR (`entry`=23710 AND `item`=116756 AND `ExtendedCost`=2276 AND `type`=1) OR (`entry`=23710 AND `item`=90427 AND `ExtendedCost`=2275 AND `type`=1) OR (`entry`=23710 AND `item`=90426 AND `ExtendedCost`=2398 AND `type`=1) OR (`entry`=23710 AND `item`=39476 AND `ExtendedCost`=2424 AND `type`=1) OR (`entry`=23710 AND `item`=37571 AND `ExtendedCost`=2397 AND `type`=1) OR (`entry`=23710 AND `item`=168915 AND `ExtendedCost`=2276 AND `type`=1) OR (`entry`=23710 AND `item`=169461 AND `ExtendedCost`=6597 AND `type`=1) OR (`entry`=23710 AND `item`=169448 AND `ExtendedCost`=6582 AND `type`=1) OR (`entry`=152849 AND `item`=128833 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152849 AND `item`=151774 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152849 AND `item`=168607 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152849 AND `item`=2723 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152849 AND `item`=63299 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153574 AND `item`=169865 AND `ExtendedCost`=6619 AND `type`=1) OR (`entry`=152829 AND `item`=169443 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152829 AND `item`=169442 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152829 AND `item`=169441 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153030 AND `item`=104344 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153030 AND `item`=104348 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153030 AND `item`=81414 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153030 AND `item`=104343 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(23481, 2, 138884, 0, 0, 1, 0, 0, 45745), -- Throwing Sausage
(23481, 1, 138900, 0, 2275, 1, 0, 0, 45745), -- Gravil Goldbraid's Famous Sausage Hat
(23522, 14, 82451, 0, 0, 1, 0, 0, 45745), -- Frybread
(23522, 13, 82450, 0, 0, 1, 0, 0, 45745), -- Cornmeal Biscuit
(23710, 33, 187998, 0, 5795, 1, 0, 0, 45745), -- Eternal Heirloom Scabbard
(23710, 32, 167732, 0, 5795, 1, 0, 0, 45745), -- Battle-Hardened Heirloom Scabbard
(23710, 31, 151615, 0, 5795, 1, 0, 0, 45745), -- Weathered Heirloom Scabbard
(23710, 30, 122341, 0, 5795, 1, 0, 0, 45745), -- Timeworn Heirloom Scabbard
(23710, 29, 122339, 0, 5794, 1, 0, 0, 45745), -- Ancient Heirloom Scabbard
(23710, 28, 166747, 0, 2276, 1, 0, 0, 45745), -- Brewfest Reveler's Hearthstone
(23710, 27, 138730, 0, 2276, 1, 0, 0, 45745), -- Synthebrew Goggles XL
(23710, 25, 116758, 0, 2275, 1, 0, 0, 45745), -- Brewfest Banner
(23710, 24, 116757, 0, 2276, 1, 0, 0, 45745), -- Steamworks Sausage Grill
(23710, 21, 116756, 0, 2276, 1, 0, 0, 45745), -- Stout Alemental
(23710, 16, 90427, 0, 2275, 1, 0, 0, 45745), -- Pandaren Brewpack
(23710, 15, 90426, 0, 2398, 1, 0, 0, 45745), -- Brewhelm
(23710, 14, 39476, 0, 2424, 1, 0, 0, 45745), -- Fresh Goblin Brewfest Hops
(23710, 12, 37571, 0, 2397, 1, 0, 0, 45745), -- "Brew of the Month" Club Membership Form
(23710, 11, 168915, 0, 2276, 1, 0, 0, 45745), -- Tabard of Brew
(23710, 10, 169461, 0, 6597, 1, 0, 0, 45745), -- Garland of Grain
(23710, 1, 169448, 0, 6582, 1, 0, 0, 45745), -- Bottomless Brewfest Stein
(73913, 10, 105704, 0, 0, 1, 0, 0, 45745), -- Yan-Zhu's Blazing Brew
(73913, 9, 105707, 0, 0, 1, 0, 0, 45745), -- Unga Brew
(73913, 8, 105703, 0, 0, 1, 0, 0, 45745), -- Stormstout Brew
(73913, 7, 105708, 0, 0, 1, 0, 0, 45745), -- Shimmering Amber-Brew
(73913, 6, 105706, 0, 0, 1, 0, 0, 45745), -- Shado-Pan Brew
(73913, 5, 105700, 0, 0, 1, 0, 0, 45745), -- Kun-Lai Kicker
(73913, 4, 105701, 0, 0, 1, 0, 0, 45745), -- Greenstone Brew
(73913, 3, 105711, 0, 0, 1, 0, 0, 45745), -- Funky Monkey Brew
(73913, 2, 105705, 0, 0, 1, 0, 0, 45745), -- Chani's Bitter Brew
(73913, 1, 105702, 0, 0, 1, 0, 0, 45745), -- Boomer Brew
(152829, 3, 169443, 0, 0, 1, 0, 0, 45745), -- Shadowmoon Schnapps
(152829, 2, 169442, 0, 0, 1, 0, 0, 45745), -- Exodar Martini
(152829, 1, 169441, 0, 0, 1, 0, 0, 45745), -- Azuremyst Mead
(152849, 5, 128833, 0, 0, 1, 0, 0, 45745), -- Kaldorei Ginger Wine
(152849, 4, 151774, 0, 0, 1, 0, 0, 45745), -- Distilled Voidblend
(152849, 3, 168607, 0, 0, 1, 0, 0, 45745), -- Bottle of Voidwine
(152849, 2, 2723, 0, 0, 1, 0, 0, 45745), -- Bottle of Dalaran Noir
(152849, 1, 63299, 0, 0, 1, 0, 0, 45745), -- Sunkissed Wine
(152871, 4, 163019, 0, 0, 1, 0, 0, 45745), -- Drop Anchor Dunkel
(152871, 3, 163103, 0, 0, 1, 0, 0, 45745), -- Admiralty-Issued Grog
(152871, 2, 162560, 0, 0, 1, 0, 0, 45745), -- Patina Pale Ale
(152871, 1, 169397, 0, 0, 1, 0, 0, 45745), -- Admiralty Ale
(152941, 4, 163143, 0, 0, 1, 0, 0, 45745), -- The Burning Black Beverage
(152941, 3, 169436, 0, 0, 1, 0, 0, 45745), -- Fireblood Stout
(152941, 2, 170202, 0, 0, 1, 0, 0, 45745), -- Shwayderbrau
(152941, 1, 169439, 0, 0, 1, 0, 0, 45745), -- Dark Iron Ale
(153030, 4, 104344, 0, 0, 1, 0, 0, 45745), -- Lucky Mushroom Noodles
(153030, 3, 104348, 0, 0, 1, 0, 0, 45745), -- Timeless Tea
(153030, 2, 81414, 0, 0, 1, 0, 0, 45745), -- Pearl Milk Tea
(153030, 1, 104343, 0, 0, 1, 0, 0, 45745), -- Golden Dragon Noodles
(153146, 10, 105704, 0, 0, 1, 0, 0, 45745), -- Yan-Zhu's Blazing Brew
(153146, 9, 105707, 0, 0, 1, 0, 0, 45745), -- Unga Brew
(153146, 8, 105703, 0, 0, 1, 0, 0, 45745), -- Stormstout Brew
(153146, 7, 105708, 0, 0, 1, 0, 0, 45745), -- Shimmering Amber-Brew
(153146, 6, 105706, 0, 0, 1, 0, 0, 45745), -- Shado-Pan Brew
(153146, 5, 105700, 0, 0, 1, 0, 0, 45745), -- Kun-Lai Kicker
(153146, 4, 105701, 0, 0, 1, 0, 0, 45745), -- Greenstone Brew
(153146, 3, 105711, 0, 0, 1, 0, 0, 45745), -- Funky Monkey Brew
(153146, 2, 105705, 0, 0, 1, 0, 0, 45745), -- Chani's Bitter Brew
(153146, 1, 105702, 0, 0, 1, 0, 0, 45745), -- Boomer Brew
(153166, 1, 159, 0, 0, 1, 0, 0, 45745), -- Refreshing Spring Water
(153574, 1, 169865, 0, 6619, 1, 0, 0, 45745), -- Brewfest Chowdown Trophy
(154003, 2, 34065, 0, 0, 1, 0, 0, 45745), -- Spiced Onion Cheese
(154003, 1, 33043, 0, 0, 1, 0, 0, 45745); -- The Essential Brewfest Pretzel

UPDATE `npc_vendor` SET `VerifiedBuild`=45745 WHERE (`entry`=23522 AND `item`=58261 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23522 AND `item`=58260 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23522 AND `item`=35950 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23522 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23522 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23522 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23522 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23522 AND `item`=4544 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23522 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23522 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23522 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23522 AND `item`=33043 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23482 AND `item`=138867 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23482 AND `item`=46400 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23482 AND `item`=33029 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23482 AND `item`=33028 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23482 AND `item`=33030 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23510 AND `item`=138868 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23510 AND `item`=138871 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23510 AND `item`=46399 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23510 AND `item`=33033 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23510 AND `item`=33032 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23510 AND `item`=33031 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23511 AND `item`=138869 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23511 AND `item`=46403 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23511 AND `item`=33036 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23511 AND `item`=33035 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23511 AND `item`=33034 AND `ExtendedCost`=0 AND `type`=1);
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=45745 WHERE (`entry`=23481 AND `item`=29451 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Ribs
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=45745 WHERE (`entry`=23481 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=45745 WHERE (`entry`=23481 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=45745 WHERE (`entry`=23481 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=45745 WHERE (`entry`=23481 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=45745 WHERE (`entry`=23481 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=45745 WHERE (`entry`=23481 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1); -- Haunch of Meat
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=45745 WHERE (`entry`=23481 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1); -- Tough Jerky
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=45745 WHERE (`entry`=23481 AND `item`=33026 AND `ExtendedCost`=0 AND `type`=1); -- The Golden Link
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=45745 WHERE (`entry`=23481 AND `item`=33025 AND `ExtendedCost`=0 AND `type`=1); -- Spicy Smoked Sausage
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=45745 WHERE (`entry`=23481 AND `item`=33024 AND `ExtendedCost`=0 AND `type`=1); -- Pickled Sausage
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=45745 WHERE (`entry`=23481 AND `item`=33023 AND `ExtendedCost`=0 AND `type`=1); -- Savory Sausage
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=45745 WHERE (`entry`=23481 AND `item`=34064 AND `ExtendedCost`=0 AND `type`=1); -- Succulent Sausage
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=45745 WHERE (`entry`=23481 AND `item`=34063 AND `ExtendedCost`=0 AND `type`=1); -- Dried Sausage
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=45745 WHERE (`entry`=23521 AND `item`=29448 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Mild Cheese
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=45745 WHERE (`entry`=23521 AND `item`=27857 AND `ExtendedCost`=0 AND `type`=1); -- Garadar Sharp
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=45745 WHERE (`entry`=23521 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1); -- Alterac Swiss
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=45745 WHERE (`entry`=23521 AND `item`=3927 AND `ExtendedCost`=0 AND `type`=1); -- Fine Aged Cheddar
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=45745 WHERE (`entry`=23521 AND `item`=1707 AND `ExtendedCost`=0 AND `type`=1); -- Stormwind Brie
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=45745 WHERE (`entry`=23521 AND `item`=422 AND `ExtendedCost`=0 AND `type`=1); -- Dwarven Mild
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=45745 WHERE (`entry`=23521 AND `item`=414 AND `ExtendedCost`=0 AND `type`=1); -- Dalaran Sharp
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=45745 WHERE (`entry`=23521 AND `item`=2070 AND `ExtendedCost`=0 AND `type`=1); -- Darnassian Bleu
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=45745 WHERE (`entry`=23521 AND `item`=34065 AND `ExtendedCost`=0 AND `type`=1); -- Spiced Onion Cheese
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=45745 WHERE (`entry`=23710 AND `item`=37816 AND `ExtendedCost`=2399 AND `type`=1); -- Preserved Brewfest Hops
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=45745 WHERE (`entry`=23710 AND `item`=37750 AND `ExtendedCost`=2398 AND `type`=1); -- Fresh Brewfest Hops
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=45745 WHERE (`entry`=23710 AND `item`=32233 AND `ExtendedCost`=2276 AND `type`=1); -- Wolpertinger's Tankard
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=45745 WHERE (`entry`=23710 AND `item`=46707 AND `ExtendedCost`=2275 AND `type`=1); -- Pint-Sized Pink Pachyderm
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=45745 WHERE (`entry`=23710 AND `item`=33927 AND `ExtendedCost`=2275 AND `type`=1); -- Brewfest Pony Keg
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=45745 WHERE (`entry`=23710 AND `item`=71137 AND `ExtendedCost`=2276 AND `type`=1); -- Brewfest Keg Pony
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=45745 WHERE (`entry`=23710 AND `item`=33047 AND `ExtendedCost`=2275 AND `type`=1); -- Belbi's Eyesight Enhancing Romance Goggles
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=45745 WHERE (`entry`=23710 AND `item`=33868 AND `ExtendedCost`=2275 AND `type`=1); -- Brewfest Boots
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=45745 WHERE (`entry`=23710 AND `item`=33862 AND `ExtendedCost`=2276 AND `type`=1); -- Brewfest Regalia
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=45745 WHERE (`entry`=23710 AND `item`=33966 AND `ExtendedCost`=2275 AND `type`=1); -- Brewfest Slippers
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=45745 WHERE (`entry`=23710 AND `item`=33863 AND `ExtendedCost`=2276 AND `type`=1); -- Brewfest Dress
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=45745 WHERE (`entry`=23710 AND `item`=33969 AND `ExtendedCost`=2274 AND `type`=1); -- Purple Brewfest Hat
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=45745 WHERE (`entry`=23710 AND `item`=33967 AND `ExtendedCost`=2274 AND `type`=1); -- Green Brewfest Hat
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=45745 WHERE (`entry`=23710 AND `item`=33864 AND `ExtendedCost`=2274 AND `type`=1); -- Brown Brewfest Hat
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=45745 WHERE (`entry`=23710 AND `item`=33968 AND `ExtendedCost`=2274 AND `type`=1); -- Blue Brewfest Hat

-- Gameobject templates
DELETE FROM `gameobject_template` WHERE `entry` In (327669, 328413);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(327669, 2, 11072, 'Contained Alemental', '', '', '', 1, 57, 23083, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 298, 45745), -- Contained Alemental
(328413, 2, 11304, 'Hozen Totem', '', '', '', 1, 57, 23096, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 298, 45745); -- Hozen Totem

UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=45745 WHERE `entry`=246194; -- Wine Glass
UPDATE `gameobject_template` SET `ContentTuningId`=298, `VerifiedBuild`=45745 WHERE `entry`=327681; -- Direbrew Mole Machine
UPDATE `gameobject_template` SET `ContentTuningId`=298, `VerifiedBuild`=45745 WHERE `entry`=328343; -- Direbrew Cog

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (259880, 326028, 326044, 326045, 326052, 326106, 326707, 326708, 326709, 326710, 326711, 326712, 326713, 326714, 326715, 327133, 327134, 327182, 327669, 327681, 328343, 328413);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(259880, 1375, 16, 0, 0), -- Collision Wall
(326028, 0, 32, 0, 0), -- Void Elf Tent
(326044, 0, 32, 0, 0), -- Kul Tiran Tent
(326045, 0, 8192, 0, 0), -- Kul Tiran Bar
(326052, 0, 32, 0, 13176), -- Mole Machine
(326106, 0, 32, 0, 0), -- Pandaren Noodle Cart
(326707, 0, 8192, 0, 0), -- Fence
(326708, 0, 8192, 0, 0), -- Fence
(326709, 0, 8192, 0, 0), -- Fence
(326710, 0, 8192, 0, 0), -- Fence
(326711, 0, 8192, 0, 0), -- Fence
(326712, 0, 8192, 0, 0), -- Fence
(326713, 0, 8192, 0, 0), -- Fence
(326714, 0, 8192, 0, 0), -- Fence
(326715, 0, 8192, 0, 0), -- Fence
(327133, 0, 32, 0, 0), -- Shoutbox
(327134, 0, 32, 0, 0), -- Brewfest Ceremonial Keg
(327182, 0, 8192, 0, 0), -- Table
(327669, 0, 4, 0, 0), -- Contained Alemental
(327681, 0, 48, 0, 0), -- Direbrew Mole Machine
(328343, 0, 4, 0, 0), -- Direbrew Cog
(328413, 0, 4, 0, 0); -- Hozen Totem

UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=221482; -- PA Mug Bamboo 06
UPDATE `gameobject_template_addon` SET `flags`=8192 WHERE `entry`=231782; -- Draenei Wagon

-- Misc
DELETE FROM `spell_target_position` WHERE (`ID`=304163 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(304163, 0, 0, -5193.10986328125, -545.22998046875, 397.079986572265625, 45745); -- Spell: 304163 (Teleport) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

UPDATE `serverside_spell` SET `SpellName`='Drunk Invisibility (Strong)' WHERE `Id`=39707;

-- Old creature spawns
DELETE FROM `creature` WHERE `guid` IN (361970, 361971, 361972, 361973, 361974);
DELETE FROM `game_event_creature` WHERE `guid` IN (361970, 361971, 361972, 361973, 361974);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+98;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Ironforge & Gates of Ironforge
(@CGUID+0, 19148, 0, 1537, 5719, '0', 0, 0, 0, 0, -4948.93212890625, -957.6007080078125, 501.72283935546875, 4.171336650848388671, 120, 0, 0, 11791, 0, 0, 3, 0, 0, 45745), -- Dwarf Commoner (Area: The Commons - Difficulty: 0) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+1, 19148, 0, 1537, 5719, '0', 0, 0, 0, 0, -4949.861328125, -959.23956298828125, 501.72076416015625, 1.01229095458984375, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Dwarf Commoner (Area: The Commons - Difficulty: 0) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+2, 19172, 0, 1537, 1537, '0', 0, 0, 0, 0, -4831.73681640625, -1172.5758056640625, 502.27752685546875, 6.195918560028076171, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Gnome Commoner (Area: Ironforge - Difficulty: 0) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+3, 19172, 0, 1537, 1537, '0', 0, 0, 0, 0, -4829.8798828125, -1173.2542724609375, 502.27734375, 2.49582076072692871, 120, 0, 0, 11791, 0, 0, 3, 0, 0, 45745), -- Gnome Commoner (Area: Ironforge - Difficulty: 0) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+4, 40441, 0, 1537, 5719, '0', 0, 0, 0, 0, -4939.44775390625, -937.36981201171875, 503.2398681640625, 0.767944872379302978, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Battered Brewmaster (Area: The Commons - Difficulty: 0)
(@CGUID+5, 155345, 0, 1537, 809, '0', 0, 0, 0, 0, -5036.80712890625, -788.3680419921875, 495.215728759765625, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- [DNT] Brewfest Music (Area: 0 - Difficulty: 0)
(@CGUID+6, 153931, 0, 1537, 809, '0', 0, 0, 0, 5, -5038.423828125, -796.685791015625, 495.211822509765625, 2.156079292297363281, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0)
(@CGUID+7, 153931, 0, 1537, 809, '0', 0, 0, 0, 4, -5039.51904296875, -793.7430419921875, 495.220489501953125, 4.470478057861328125, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0)
(@CGUID+8, 153931, 0, 1537, 809, '0', 0, 0, 0, 6, -5040.79150390625, -789.84027099609375, 495.21063232421875, 2.833275318145751953, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0)
(@CGUID+9, 153931, 0, 1537, 809, '0', 0, 0, 0, 5, -5041.29150390625, -795.717041015625, 495.2119140625, 0.184281155467033386, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0)
(@CGUID+10, 153931, 0, 1537, 809, '0', 0, 0, 0, 6, -5042.64404296875, -787.94793701171875, 495.21044921875, 4.830263137817382812, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0)
(@CGUID+11, 153931, 0, 1537, 809, '0', 0, 0, 0, 4, -5043.79541015625, -790.7430419921875, 495.21051025390625, 0.518876433372497558, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0)
-- Kharanos
(@CGUID+12, 24364, 0, 1, 131, '0', 0, 0, 0, 1, -5615.111328125, -473.9288330078125, 397.0635986328125, 5.704004287719726562, 120, 0, 0, 12381, 0, 0, 0, 0, 0, 45745), -- Flynn Firebrew (Area: Kharanos - Difficulty: 0) (Auras: 44067 - Supplier Mark)
(@CGUID+13, 155303, 0, 1, 131, '0', 0, 0, 0, 0, -5633.4619140625, -492.357635498046875, 396.756072998046875, 4.276056766510009765, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Apple Bucket (Area: 0 - Difficulty: 0) (Auras: 302192 - Apple Bucket)
(@CGUID+14, 155303, 0, 1, 0, '0', 0, 0, 0, 0, -5354.359375, -527.51910400390625, 391.57666015625, 3.892084121704101562, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Apple Bucket (Area: Gates of Ironforge - Difficulty: 0) (Auras: 302192 - Apple Bucket)
-- Brewfest area
(@CGUID+15, 23481, 0, 1, 0, '0', 0, 0, 0, 1, -5154.8662109375, -572.40625, 397.259521484375, 3.994099140167236328, 120, 0, 0, 12381, 0, 0, 0, 0, 0, 45745), -- Keiran Donoghue (Area: 0 - Difficulty: 0)
(@CGUID+16, 23482, 0, 1, 0, '0', 0, 0, 0, 0, -5187.87353515625, -602.65277099609375, 397.259521484375, 0.592996478080749511, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Barleybrew Apprentice (Area: 0 - Difficulty: 0)
(@CGUID+17, 23486, 0, 1, 0, '0', 0, 0, 0, 1, -5172.609375, -559.015625, 397.259521484375, 4.218060970306396484, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Goldark Snipehunter (Area: 0 - Difficulty: 0)
(@CGUID+18, 23488, 0, 1, 0, '0', 0, 0, 0, 0, -5122.5556640625, -633.529541015625, 399.58355712890625, 3.979350566864013671, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Crowd (Area: 0 - Difficulty: 0)
(@CGUID+19, 23510, 0, 1, 0, '0', 0, 0, 0, 0, -5147.27978515625, -633.84552001953125, 397.264678955078125, 1.727875947952270507, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Thunderbrew Apprentice (Area: Gates of Ironforge - Difficulty: 0)
(@CGUID+20, 23511, 0, 1, 0, '0', 0, 0, 0, 0, -5137.8662109375, -578.859375, 397.259521484375, 4.031710624694824218, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Gordok Brew Apprentice (Area: 0 - Difficulty: 0)
(@CGUID+21, 23521, 0, 1, 0, '0', 0, 0, 0, 0, -5136.640625, -615.5694580078125, 397.728179931640625, 2.677447319030761718, 120, 0, 0, 12381, 0, 0, 0, 0, 0, 45745), -- Anne Summers (Area: 0 - Difficulty: 0) (Auras: 268057 - Cradle Basket)
(@CGUID+22, 23522, 0, 1, 0, '0', 0, 0, 0, 1, -5193.03125, -585.80731201171875, 397.340484619140625, 0.356846541166305541, 120, 0, 0, 12381, 0, 0, 0, 0, 0, 45745), -- Arlen Lochlan (Area: 0 - Difficulty: 0)
(@CGUID+23, 23558, 0, 1, 0, '0', 0, 0, 0, 0, -5200.2119140625, -490.44964599609375, 388.5909423828125, 3.193952560424804687, 120, 0, 0, 12381, 0, 0, 0, 0, 0, 45745), -- Neill Ramstein (Area: 0 - Difficulty: 0)
(@CGUID+24, 23627, 0, 1, 0, '0', 0, 0, 0, 1, -5186.28466796875, -605.69097900390625, 397.165283203125, 0.41040271520614624, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Becan Barleybrew (Area: 0 - Difficulty: 0) (Auras: 281819 - Bar Tend Stand)
(@CGUID+25, 23628, 0, 1, 0, '0', 0, 0, 0, 1, -5144.18408203125, -633.19964599609375, 397.26416015625, 1.926930189132690429, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Daran Thunderbrew (Area: Gates of Ironforge - Difficulty: 0) (Auras: 281819 - Bar Tend Stand)
(@CGUID+26, 23683, 0, 1, 0, '0', 0, 0, 0, 1, -5181.37841796875, -607.3836669921875, 397.301177978515625, 0.470823436975479125, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Maeve Barleybrew (Area: 0 - Difficulty: 0)
(@CGUID+27, 23684, 0, 1, 0, '0', 0, 0, 0, 1, -5140.859375, -629.453125, 397.2244873046875, 1.623156189918518066, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Ita Thunderbrew (Area: Gates of Ironforge - Difficulty: 0)
(@CGUID+28, 23685, 0, 1, 0, '0', 0, 0, 0, 1, -5136.1591796875, -586.455322265625, 397.301177978515625, 3.577924966812133789, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Gordok Brew Barker (Area: 0 - Difficulty: 0)
(@CGUID+29, 23696, 0, 1, 0, '0', 0, 0, 0, 0, -5135.82666015625, -581.27777099609375, 397.259521484375, 3.455751895904541015, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Gordok Brew Chief (Area: 0 - Difficulty: 0)
(@CGUID+30, 23710, 0, 1, 0, '0', 0, 0, 0, 0, -5170.52978515625, -626.50177001953125, 397.259552001953125, 1.010327696800231933, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Belbi Quikswitch (Area: Gates of Ironforge - Difficulty: 0)
(@CGUID+31, 24108, 0, 1, 0, '0', 0, 0, 0, 0, -5170.799, -542.5313, 397.2794, 0, 120, 5, 0, 11791, 0, 1, 0, 0, 0, 45745), -- Self-Turning and Oscillating Utility Target (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+32, 24463, 0, 1, 0, '0', 0, 0, 0, 0, -5187.22216796875, -488.265838623046875, 387.00482177734375, 5.613784313201904296, 120, 3, 0, 11791, 2434, 1, 0, 0, 0, 45745), -- Swift Racing Ram (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+33, 24468, 0, 1, 0, '0', 0, 0, 0, 1, -5200.6875, -485.94097900390625, 388.796630859375, 3.506814002990722656, 120, 0, 0, 12381, 0, 0, 0, 0, 0, 45745), -- Pol Amberstill (Area: 0 - Difficulty: 0)
(@CGUID+34, 24710, 0, 1, 0, '0', 0, 0, 0, 1, -5184.68408203125, -562.37200927734375, 397.259521484375, 2.111848354339599609, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Ipfelkofer Ironkeg (Area: 0 - Difficulty: 0)
(@CGUID+35, 24766, 0, 1, 0, '0', 0, 0, 0, 0, -5165.24560546875, -603.43280029296875, 398.00518798828125, 2.530727386474609375, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- [DND] Brewfest Face Me Bunny (Area: 0 - Difficulty: 0)
(@CGUID+36, 24766, 0, 1, 0, '0', 0, 0, 0, 0, -5209.470703125, -488.23388671875, 388.91217041015625, 3.03687286376953125, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- [DND] Brewfest Face Me Bunny (Area: 0 - Difficulty: 0)
(@CGUID+37, 27215, 0, 1, 0, '0', 0, 0, 0, 1, -5183.4443359375, -542.22052001953125, 397.216552734375, 3.351032257080078125, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Boxey Boltspinner (Area: 0 - Difficulty: 0)
(@CGUID+38, 73913, 0, 1, 0, '0', 0, 0, 0, 1, -5131.62353515625, -605.9913330078125, 397.61175537109375, 3.013373136520385742, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewmaster Tsing (Area: 0 - Difficulty: 0)
(@CGUID+39, 152643, 0, 1, 0, '0', 0, 0, 0, 0, -5201.8525390625, -551.670166015625, 395.36956787109375, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Despawn Bunny (Area: 0 - Difficulty: 0) (Auras: 182641 - Game Object Despawn Periodic)
(@CGUID+40, 152829, 0, 1, 0, '0', 0, 0, 0, 0, -5192.8974609375, -573.75, 397.259521484375, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Arcti (Area: 0 - Difficulty: 0)
(@CGUID+41, 152849, 0, 1, 0, '0', 0, 0, 0, 0, -5165.3525390625, -564.107666015625, 397.259521484375, 4.057967662811279296, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Vinter Tysiel (Area: 0 - Difficulty: 0)
(@CGUID+42, 152871, 0, 1, 0, '0', 0, 0, 0, 0, -5162.8369140625, -630.50518798828125, 397.2669677734375, 1.468774318695068359, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewer Gerrat (Area: Gates of Ironforge - Difficulty: 0)
(@CGUID+43, 152941, 0, 1, 0, '0', 0, 0, 0, 0, -5175.5, -617.109375, 397.25970458984375, 0.675921976566314697, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Verra Fireblood (Area: Gates of Ironforge - Difficulty: 0)
(@CGUID+44, 153029, 0, 1, 0, '0', 0, 0, 0, 0, -5216.5068359375, -504.118072509765625, 388.2978515625, 5.304293632507324218, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Lucky Sachi (Area: 0 - Difficulty: 0)
(@CGUID+45, 153030, 0, 1, 0, '0', 0, 0, 0, 0, -5215.876953125, -499.111114501953125, 387.99945068359375, 0.485027670860290527, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Haru (Area: 0 - Difficulty: 0)
(@CGUID+46, 153054, 0, 1, 0, '0', 0, 0, 0, 0, -5186.36181640625, -484.530059814453125, 387.10308837890625, 0.901639878749847412, 120, 3, 0, 11791, 2434, 1, 0, 0, 0, 45745), -- Racing Ram (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+47, 153098, 0, 1, 0, '0', 0, 0, 0, 1, -5170.0556640625, -618.29864501953125, 397.30499267578125, 3.135460853576660156, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Gates of Ironforge - Difficulty: 0)
(@CGUID+48, 153101, 0, 1, 0, '0', 0, 0, 0, 0, -5189.4375, -571.79168701171875, 397.259521484375, 3.327027559280395507, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0)
(@CGUID+49, 153102, 0, 1, 0, '0', 0, 0, 0, 0, -5163.7099609375, -627.3055419921875, 397.237701416015625, 4.500928878784179687, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Gates of Ironforge - Difficulty: 0)
(@CGUID+50, 153102, 0, 1, 0, '0', 0, 0, 0, 3, -5172.09375, -620.47393798828125, 397.266632080078125, 1.428292751312255859, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Gates of Ironforge - Difficulty: 0)
(@CGUID+51, 153102, 0, 1, 0, '0', 0, 0, 0, 1, -5121.13720703125, -588.45831298828125, 397.259521484375, 4.010109424591064453, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0)
(@CGUID+52, 153104, 0, 1, 0, '0', 0, 0, 0, 1, -5165.375, -567.4774169921875, 397.176177978515625, 1.297124147415161132, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0)
(@CGUID+53, 153146, 0, 1, 0, '0', 0, 0, 0, 0, -5132.4599609375, -601.11114501953125, 397.24700927734375, 3.40476536750793457, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Su Li (Area: 0 - Difficulty: 0)
(@CGUID+54, 153159, 0, 1, 0, '0', 0, 0, 0, 0, -5145.392578125, -624.65802001953125, 397.5498046875, 1.518400788307189941, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Gates of Ironforge - Difficulty: 0)
(@CGUID+55, 153160, 0, 1, 0, '0', 0, 0, 0, 2, -5126.13916015625, -591.73614501953125, 397.259521484375, 0.47118455171585083, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0)
(@CGUID+56, 153160, 0, 1, 0, '0', 0, 0, 0, 1, -5119.85595703125, -587.045166015625, 397.260101318359375, 0.550998449325561523, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0)
(@CGUID+57, 153161, 0, 1, 0, '0', 0, 0, 0, 2, -5142.9912109375, -606.4757080078125, 399.28118896484375, 3.167812585830688476, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0)
(@CGUID+58, 153161, 0, 1, 0, '0', 0, 0, 0, 4, -5123.76220703125, -590.53472900390625, 397.259521484375, 0.454383760690689086, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0)
(@CGUID+59, 153162, 0, 1, 0, '0', 0, 0, 0, 2, -5117.642578125, -585.375, 397.2769775390625, 0.667579889297485351, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0)
(@CGUID+60, 153162, 0, 1, 0, '0', 0, 0, 0, 5, -5122.3662109375, -589.79168701171875, 397.259521484375, 0.890182375907897949, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0)
(@CGUID+61, 153162, 0, 1, 0, '0', 0, 0, 0, 1, -5128.078125, -592.78302001953125, 397.259521484375, 0.587613701820373535, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0)
(@CGUID+62, 153166, 0, 1, 0, '0', 0, 0, 0, 0, -5181.031, -579.9063, 397.8012, 0, 120, 0, 0, 11791, 0, 2, 0, 0, 0, 45745), -- Sobrietus (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+63, 153198, 0, 1, 0, '0', 0, 0, 0, 0, -5200.892578125, -550.3055419921875, 397.170379638671875, 0.610247373580932617, 120, 0, 0, 11791, 100, 0, 0, 0, 0, 45745), -- Chowdown Participant's Seat (Area: 0 - Difficulty: 0) (Auras: 297978 - [DNT] Seat Preparation)
(@CGUID+64, 153198, 0, 1, 0, '0', 0, 0, 0, 0, -5201.66650390625, -549.18231201171875, 397.12286376953125, 0.583577394485473632, 120, 0, 0, 11791, 100, 0, 0, 0, 0, 45745), -- Chowdown Participant's Seat (Area: 0 - Difficulty: 0) (Auras: 297978 - [DNT] Seat Preparation)
(@CGUID+65, 153198, 0, 1, 0, '0', 0, 0, 0, 0, -5199.98779296875, -551.5069580078125, 397.176300048828125, 0.657003939151763916, 120, 0, 0, 11791, 100, 0, 0, 0, 0, 45745), -- Chowdown Participant's Seat (Area: 0 - Difficulty: 0) (Auras: 297978 - [DNT] Seat Preparation)
(@CGUID+66, 153198, 0, 1, 0, '0', 0, 0, 0, 0, -5199.25, -552.46356201171875, 397.176361083984375, 0.581134796142578125, 120, 0, 0, 11791, 100, 0, 0, 0, 0, 45745), -- Chowdown Participant's Seat (Area: 0 - Difficulty: 0) (Auras: 297978 - [DNT] Seat Preparation)
(@CGUID+67, 153574, 0, 1, 0, '0', 0, 0, 0, 0, -5201.5849609375, -547.26910400390625, 397.095458984375, 0.391155511140823364, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Britta Steinheart (Area: 0 - Difficulty: 0) (Auras: 300158 - [DNT] Chowdown Organizer)
(@CGUID+68, 153931, 0, 1, 0, '0', 0, 0, 0, 0, -5143.623046875, -595.958740234375, 397.676177978515625, 3.19249892234802246, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300441 - [DNT] Brewfest Reveler)
(@CGUID+69, 153931, 0, 1, 0, '0', 0, 0, 0, 3, -5194.76416015625, -517.12847900390625, 389.934356689453125, 6.053356647491455078, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300450 - [DNT] Brewfest Reveler)
(@CGUID+70, 153931, 0, 1, 0, '0', 0, 0, 0, 6, -5191.9658203125, -518.04449462890625, 390.382843017578125, 2.851971626281738281, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300447 - [DNT] Brewfest Reveler)
(@CGUID+71, 153931, 0, 1, 0, '0', 0, 0, 0, 1, -5212.51953125, -507.44195556640625, 388.771392822265625, 4.830263137817382812, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300441 - [DNT] Brewfest Reveler)
(@CGUID+72, 153931, 0, 1, 0, '0', 0, 0, 0, 4, -5213.765625, -510.217010498046875, 389.267974853515625, 0.518876433372497558, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300442 - [DNT] Brewfest Reveler)
(@CGUID+73, 153931, 0, 1, 0, '0', 0, 0, 0, 2, -5210.76220703125, -509.314239501953125, 388.926177978515625, 2.833275318145751953, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300446 - [DNT] Brewfest Reveler)
(@CGUID+74, 153931, 0, 1, 0, '0', 0, 0, 0, 0, -5161.31591796875, -571.91668701171875, 397.301177978515625, 3.864611148834228515, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300447 - [DNT] Brewfest Reveler)
(@CGUID+75, 153931, 0, 1, 0, '0', 0, 0, 0, 0, -5163.919921875, -572.55438232421875, 397.301177978515625, 5.83640909194946289, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300447 - [DNT] Brewfest Reveler)
(@CGUID+76, 153931, 0, 1, 0, '0', 0, 0, 0, 0, -5161.71533203125, -574.70489501953125, 397.301177978515625, 1.867624759674072265, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300446 - [DNT] Brewfest Reveler)
(@CGUID+77, 153931, 0, 1, 0, '0', 0, 0, 0, 0, -5156.33349609375, -584.73614501953125, 397.301177978515625, 3.864611148834228515, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300442 - [DNT] Brewfest Reveler)
(@CGUID+78, 153931, 0, 1, 0, '0', 0, 0, 0, 0, -5146.57666015625, -596.03125, 397.887359619140625, 0.110699079930782318, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300447 - [DNT] Brewfest Reveler)
(@CGUID+79, 153931, 0, 1, 0, '0', 0, 0, 0, 0, -5156.73291015625, -587.5242919921875, 397.426177978515625, 1.867624759674072265, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300442 - [DNT] Brewfest Reveler)
(@CGUID+80, 153931, 0, 1, 0, '0', 0, 0, 0, 0, -5158.966796875, -585.3912353515625, 397.426177978515625, 5.83640909194946289, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300441 - [DNT] Brewfest Reveler)
(@CGUID+81, 153931, 0, 1, 0, '0', 0, 0, 0, 0, -5174.46728515625, -592.078125, 397.802642822265625, 4.830263137817382812, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300448 - [DNT] Brewfest Reveler)
(@CGUID+82, 153931, 0, 1, 0, '0', 0, 0, 0, 0, -5184.19970703125, -576.22222900390625, 397.302337646484375, 6.053356647491455078, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300445 - [DNT] Brewfest Reveler)
(@CGUID+83, 153931, 0, 1, 0, '0', 0, 0, 0, 0, -5181.234375, -577.19097900390625, 397.676177978515625, 2.851971626281738281, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300447 - [DNT] Brewfest Reveler)
(@CGUID+84, 153931, 0, 1, 0, '0', 0, 0, 0, 0, -5146.59228515625, -621.42364501953125, 397.9661865234375, 5.03859567642211914, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300446 - [DNT] Brewfest Reveler)
(@CGUID+85, 153931, 0, 1, 0, '0', 0, 0, 0, 0, -5157.18212890625, -614.91143798828125, 398.1751708984375, 4.45032358169555664, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300448 - [DNT] Brewfest Reveler)
(@CGUID+86, 153931, 0, 1, 0, '0', 0, 0, 0, 0, -5173.15625, -604.80035400390625, 397.37762451171875, 5.821129798889160156, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300441 - [DNT] Brewfest Reveler)
(@CGUID+87, 153931, 0, 1, 0, '0', 0, 0, 0, 0, -5169.892578125, -606.890625, 397.476470947265625, 2.619745731353759765, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300446 - [DNT] Brewfest Reveler)
(@CGUID+88, 153931, 0, 1, 0, '0', 0, 0, 0, 0, -5145.3232421875, -606.78369140625, 398.4759521484375, 0.009405219927430152, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300444 - [DNT] Brewfest Reveler)
(@CGUID+89, 153931, 0, 1, 0, '0', 0, 0, 0, 0, -5172.61474609375, -593.97052001953125, 398.051177978515625, 2.833275318145751953, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300441 - [DNT] Brewfest Reveler)
(@CGUID+90, 153931, 0, 1, 0, '0', 0, 0, 0, 0, -5156.27099609375, -618.0850830078125, 398.0343017578125, 2.586220264434814453, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Gates of Ironforge - Difficulty: 0) (Auras: 300447 - [DNT] Brewfest Reveler)
(@CGUID+91, 153931, 0, 1, 0, '0', 0, 0, 0, 0, -5175.6181640625, -594.873291015625, 397.789459228515625, 0.518876433372497558, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: 0 - Difficulty: 0) (Auras: 300445 - [DNT] Brewfest Reveler)
(@CGUID+92, 153931, 0, 1, 0, '0', 0, 0, 0, 0, -5160.625, -617.6649169921875, 397.7618408203125, 0.361292958259582519, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Gates of Ironforge - Difficulty: 0) (Auras: 300441 - [DNT] Brewfest Reveler)
(@CGUID+93, 154003, 0, 1, 0, '0', 0, 0, 0, 0, -5137.382, -599.7031, 397.59952, 0, 120, 0, 0, 11791, 0, 2, 0, 0, 0, 45745), -- Melanie Charles (Area: 0 - Difficulty: 0) (Auras: 299038 - Serving Platter) (possible waypoints or random movement)
(@CGUID+94, 154078, 0, 1, 0, '0', 0, 0, 0, 0, -5165.4443359375, -595.4375, 397.756500244140625, 5.435611724853515625, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Crowd (Area: 0 - Difficulty: 0)
(@CGUID+95, 154086, 0, 1, 0, '0', 0, 0, 0, 0, -5161.79345703125, -602.07464599609375, 400.668060302734375, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Keg Tap (Area: 0 - Difficulty: 0)
(@CGUID+96, 154477, 0, 1, 0, '0', 0, 0, 0, 0, -5162.60595703125, -598.3125, 416.00927734375, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Event Controller (Area: 0 - Difficulty: 0)
(@CGUID+97, 155303, 0, 1, 0, '0', 0, 0, 0, 0, -5201.095703125, -483.267364501953125, 388.974517822265625, 0.331612557172775268, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Apple Bucket (Area: 0 - Difficulty: 0)
(@CGUID+98, 155345, 0, 1, 0, '0', 0, 0, 0, 0, -5162.67529296875, -598.7100830078125, 409.176544189453125, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745); -- [DNT] Brewfest Music (Area: 0 - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+48, @CGUID+49, @CGUID+52, @CGUID+54, @CGUID+57, @CGUID+62, @CGUID+93);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+48, 0, 0, 0, 257, 876, 0, 0, 0, 0, ''), -- 153101 (Brewfest Reveler)
(@CGUID+49, 0, 0, 6, 257, 0, 0, 0, 0, 0, ''), -- 153102 (Brewfest Reveler)
(@CGUID+52, 0, 0, 6, 257, 0, 0, 0, 0, 0, ''), -- 153104 (Brewfest Reveler)
(@CGUID+54, 0, 0, 0, 257, 876, 0, 0, 0, 0, ''), -- 153159 (Brewfest Reveler)
(@CGUID+57, 0, 0, 0, 257, 876, 0, 0, 0, 0, ''), -- 153161 (Brewfest Reveler)
(@CGUID+62, (@CGUID+62)*10, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153166 (Sobrietus)
(@CGUID+93, (@CGUID+93)*10, 0, 0, 1, 0, 0, 0, 0, 0, '299038'); -- 154003 (Melanie Charles)

DELETE FROM `waypoint_data` WHERE `id` IN ((@CGUID+62)*10, (@CGUID+93)*10);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
((@CGUID+62)*10, 0, -5181.031, -579.9063, 397.8012, NULL, 0),
((@CGUID+62)*10, 1, -5182.054, -589.908, 397.4496, NULL, 0),
((@CGUID+62)*10, 2, -5180.991, -598.6441, 397.3012, NULL, 0),
((@CGUID+62)*10, 3, -5184.083, -601.4427, 397.3012, NULL, 0),
((@CGUID+62)*10, 4, -5179.747, -602.6788, 397.3012, NULL, 0),
((@CGUID+62)*10, 5, -5171.637, -609.1858, 397.3012, NULL, 0),
((@CGUID+62)*10, 6, -5169.377, -612.6094, 397.2885, NULL, 0),
((@CGUID+62)*10, 8, -5169.002, -618.1302, 397.3012, NULL, 0),
((@CGUID+62)*10, 9, -5167.514, -621.4965, 397.3012, NULL, 0),
((@CGUID+62)*10,10, -5161.952, -622.1285, 397.4745, NULL, 0),
((@CGUID+62)*10,11, -5156.708, -618.6719, 397.9818, NULL, 0),
((@CGUID+62)*10,12, -5156.814, -618.7422, 397.9745, NULL, 0),
((@CGUID+62)*10,13, -5151.979, -620.5555, 397.9454, NULL, 0),
((@CGUID+62)*10,14, -5146.436, -619.3542, 398.0895, NULL, 0),
((@CGUID+62)*10,15, -5142.628, -614.6354, 398.2245, NULL, 0),
((@CGUID+62)*10,16, -5144.778, -605.4636, 398.3175, NULL, 0),
((@CGUID+62)*10,17, -5139.717, -601.309, 397.9281, NULL, 0),
((@CGUID+62)*10,18, -5131.455, -597.8489, 397.3012, NULL, 0),
((@CGUID+62)*10,19, -5126.634, -595.1163, 397.3012, NULL, 0),
((@CGUID+62)*10,20, -5122.571, -592.5712, 397.3012, NULL, 0),
((@CGUID+62)*10,21, -5118.606, -590.191, 397.3012, NULL, 0),
((@CGUID+62)*10,22, -5117.556, -586.8507, 397.3012, NULL, 0),
((@CGUID+62)*10,23, -5120.587, -585.1129, 397.3012, NULL, 0),
((@CGUID+62)*10,24, -5127.469, -589.5174, 397.3012, NULL, 0),
((@CGUID+62)*10,25, -5131.75, -592.3038, 397.3012, NULL, 0),
((@CGUID+62)*10,26, -5135.7, -593.9618, 397.3012, NULL, 0),
((@CGUID+62)*10,27, -5140.809, -592.342, 397.5107, NULL, 0),
((@CGUID+62)*10,28, -5150.757, -585.0746, 397.4828, NULL, 0),
((@CGUID+62)*10,29, -5161.733, -577.8629, 397.3012, NULL, 0),
((@CGUID+62)*10,30, -5174.778, -573.2136, 397.3012, NULL, 0),
((@CGUID+93)*10, 0, -5137.382, -599.7031, 397.59952, NULL, 0),
((@CGUID+93)*10, 1, -5143.144, -590.46704, 397.29117, NULL, 0),
((@CGUID+93)*10, 2, -5155.8457, -580.2969, 397.30118, NULL, 0),
((@CGUID+93)*10, 3, -5166.4287, -575.74133, 397.30118, NULL, 0),
((@CGUID+93)*10, 4, -5176.472, -576.5208, 397.66544, NULL, 0),
((@CGUID+93)*10, 5, -5181.866, -586.59894, 397.72183, NULL, 0),
((@CGUID+93)*10, 6, -5178.6978, -599.4844, 397.42007, NULL, 0),
((@CGUID+93)*10, 7, -5172.0176, -611.42535, 397.30118, NULL, 0),
((@CGUID+93)*10, 8, -5165.241, -617.68054, 397.45813, NULL, 0),
((@CGUID+93)*10, 9, -5156.983, -624.9149, 397.4491, NULL, 0),
((@CGUID+93)*10,10, -5151.269, -621.8143, 397.9193, NULL, 0),
((@CGUID+93)*10,11, -5150.608, -612.99304, 398.4745, NULL, 0),
((@CGUID+93)*10,12, -5143.644, -612.9184, 398.3495, NULL, 0),
((@CGUID+93)*10,13, -5137.441, -609.184, 398.11536, NULL, 0);

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid`=218268; -- Related to the Festival Lunar probably
DELETE FROM `gameobject` WHERE `guid` BETWEEN 226383 AND 226661;
DELETE FROM `game_event_gameobject` WHERE `guid`=218268;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 226383 AND 226661;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+415;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Ironforge & Gates of Ironforge
(@OGUID+0, 186717, 0, 1537, 1537, '0', 0, 0, -4920.193359375, -940.24395751953125, 501.57171630859375, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 120, 255, 1, 45745), -- Brewfest Banner (Area: Ironforge - Difficulty: 0)
(@OGUID+1, 186717, 0, 1537, 1537, '0', 0, 0, -4905.15625, -956.520751953125, 501.469635009765625, 2.914689540863037109, 0, 0, 0.993571281433105468, 0.113208353519439697, 120, 255, 1, 45745), -- Brewfest Banner (Area: Ironforge - Difficulty: 0)
(@OGUID+2, 186717, 0, 1537, 1537, '0', 0, 0, -4649.4921875, -972.01129150390625, 501.6597900390625, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 120, 255, 1, 45745), -- Brewfest Banner (Area: Ironforge - Difficulty: 0)
(@OGUID+3, 186717, 0, 1537, 1537, '0', 0, 0, -4678.1103515625, -968.151611328125, 501.659332275390625, 3.78736734390258789, 0, 0, -0.94832324981689453, 0.317305892705917358, 120, 255, 1, 45745), -- Brewfest Banner (Area: Ironforge - Difficulty: 0)
(@OGUID+4, 186717, 0, 1537, 1537, '0', 0, 0, -4673.0234375, -935.65106201171875, 501.659027099609375, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 45745), -- Brewfest Banner (Area: Ironforge - Difficulty: 0)
(@OGUID+5, 186717, 0, 1537, 1537, '0', 0, 0, -4960.08447265625, -1200.375, 501.659393310546875, 0.680676698684692382, 0, 0, 0.333806037902832031, 0.942641794681549072, 120, 255, 1, 45745), -- Brewfest Banner (Area: Ironforge - Difficulty: 0)
(@OGUID+6, 186717, 0, 1537, 1537, '0', 0, 0, -4983.48779296875, -1204.277587890625, 501.6689453125, 2.321286916732788085, 0, 0, 0.917059898376464843, 0.398749500513076782, 120, 255, 1, 45745), -- Brewfest Banner (Area: Ironforge - Difficulty: 0)
(@OGUID+7, 186717, 0, 1537, 1537, '0', 0, 0, -4969.7890625, -1222.796142578125, 501.669586181640625, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 45745), -- Brewfest Banner (Area: Ironforge - Difficulty: 0)
(@OGUID+8, 186717, 0, 1537, 1537, '0', 0, 0, -4698.12890625, -1246.365966796875, 501.659332275390625, 3.892086982727050781, 0, 0, -0.93041706085205078, 0.366502493619918823, 120, 255, 1, 45745), -- Brewfest Banner (Area: Ironforge - Difficulty: 0)
(@OGUID+9, 186717, 0, 1537, 1537, '0', 0, 0, -4675.359375, -1228.1741943359375, 501.6593017578125, 0.663223206996917724, 0, 0, 0.325567245483398437, 0.945518851280212402, 120, 255, 1, 45745), -- Brewfest Banner (Area: Ironforge - Difficulty: 0)
(@OGUID+10, 186717, 0, 1537, 1537, '0', 0, 0, -4712.87060546875, -1213.87109375, 501.659332275390625, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 45745), -- Brewfest Banner (Area: Ironforge - Difficulty: 0)
(@OGUID+11, 195255, 0, 1537, 1537, '0', 0, 0, -4720.98291015625, -1235.19873046875, 510.422576904296875, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Large - Brewfest (Area: Ironforge - Difficulty: 0)
(@OGUID+12, 195255, 0, 1537, 1537, '0', 0, 0, -4684.71630859375, -1205.30712890625, 510.450103759765625, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Large - Brewfest (Area: Ironforge - Difficulty: 0)
(@OGUID+13, 195255, 0, 1537, 4679, '0', 0, 0, -4672.89892578125, -992.93902587890625, 510.1920166015625, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Large - Brewfest (Area: The Forlorn Cavern - Difficulty: 0)
(@OGUID+14, 195255, 0, 1537, 4679, '0', 0, 0, -4700.93505859375, -958.9013671875, 510.295135498046875, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Large - Brewfest (Area: The Forlorn Cavern - Difficulty: 0)
(@OGUID+15, 195255, 0, 1537, 5719, '0', 0, 0, -4878.06005859375, -879.94696044921875, 510.241851806640625, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Large - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+16, 195255, 0, 1537, 5719, '0', 0, 0, -4928.48681640625, -902.7635498046875, 510.451171875, 5.288348197937011718, 0, 0, -0.4771585464477539, 0.878817260265350341, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Large - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+17, 195255, 0, 1537, 5719, '0', 0, 0, -4971.14892578125, -937.86602783203125, 510.348785400390625, 5.532694816589355468, 0, 0, -0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Large - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+18, 195255, 0, 1537, 5719, '0', 0, 0, -5003.4814453125, -983.32867431640625, 510.498046875, 5.794494152069091796, 0, 0, -0.24192142486572265, 0.970295846462249755, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Large - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+19, 195255, 0, 1537, 5719, '0', 0, 0, -4959.70703125, -1172.3468017578125, 509.829864501953125, 3.700104713439941406, 0, 0, -0.96126079559326171, 0.275640487670898437, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Large - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+20, 195255, 0, 1537, 5343, '0', 0, 0, -4931.61474609375, -1206.3570556640625, 509.640350341796875, 3.961898565292358398, 0, 0, -0.91705989837646484, 0.398749500513076782, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Large - Brewfest (Area: The Military Ward - Difficulty: 0)
(@OGUID+21, 195256, 0, 1537, 4679, '0', 0, 0, -4618.0244140625, -925.11968994140625, 501.0621337890625, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: The Forlorn Cavern - Difficulty: 0)
(@OGUID+22, 195256, 0, 1537, 4679, '0', 0, 0, -4623.98583984375, -917.63336181640625, 501.06304931640625, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: The Forlorn Cavern - Difficulty: 0)
(@OGUID+23, 195256, 0, 1537, 4679, '0', 0, 0, -4602.83056640625, -912.78594970703125, 501.066070556640625, 3.78736734390258789, 0, 0, -0.94832324981689453, 0.317305892705917358, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: The Forlorn Cavern - Difficulty: 0)
(@OGUID+24, 195256, 0, 1537, 5344, '0', 0, 0, -4609.134765625, -905.39166259765625, 501.067718505859375, 3.90954136848449707, 0, 0, -0.92718315124511718, 0.37460830807685852, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+25, 195256, 0, 1537, 5719, '0', 0, 0, -4980.03466796875, -865.87548828125, 501.659332275390625, 3.735006093978881835, 0, 0, -0.95630455017089843, 0.292372345924377441, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+26, 195256, 0, 1537, 5719, '0', 0, 0, -4990.28857421875, -853.3427734375, 501.659332275390625, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+27, 195256, 0, 1537, 5719, '0', 0, 0, -4997.84912109375, -880.6900634765625, 501.659332275390625, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+28, 195256, 0, 1537, 5719, '0', 0, 0, -5008.32275390625, -868.1883544921875, 501.659332275390625, 0.767943859100341796, 0, 0, 0.374606132507324218, 0.927184045314788818, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+29, 195256, 0, 1537, 0, '0', 0, 0, -5018.2275390625, -855.9774169921875, 501.659332275390625, 0.680676698684692382, 0, 0, 0.333806037902832031, 0.942641794681549072, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: 0 - Difficulty: 0)
(@OGUID+30, 195256, 0, 1537, 0, '0', 0, 0, -5000.1611328125, -841.3087158203125, 501.659332275390625, 3.822272777557373046, 0, 0, -0.94264125823974609, 0.333807557821273803, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: 0 - Difficulty: 0)
(@OGUID+31, 195259, 0, 1537, 4679, '0', 0, 0, -4630.103515625, -928.94500732421875, 506.122406005859375, 0.733038187026977539, 0, 0, 0.358367919921875, 0.933580458164215087, 120, 255, 1, 45745), -- Hanging, Square, Small - Brewfest (Area: The Forlorn Cavern - Difficulty: 0)
(@OGUID+32, 195260, 0, 1537, 5719, '0', 0, 0, -4885.0947265625, -1005.57061767578125, 506.957855224609375, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+33, 195260, 0, 1537, 5719, '0', 0, 0, -4877.7509765625, -999.52667236328125, 506.957855224609375, 3.22885894775390625, 0, 0, -0.99904823303222656, 0.043619260191917419, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+34, 195260, 0, 1537, 5719, '0', 0, 0, -4875.5341796875, -997.69598388671875, 506.957855224609375, 5.811946868896484375, 0, 0, -0.2334451675415039, 0.972369968891143798, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+35, 195260, 0, 1537, 5719, '0', 0, 0, -4888.35205078125, -1008.2703857421875, 506.957855224609375, 1.884953022003173828, 0, 0, 0.809016227722167968, 0.587786316871643066, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+36, 195264, 0, 1537, 5719, '0', 0, 0, -4881.06103515625, -989.32257080078125, 504.7578125, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 120, 255, 1, 45745), -- Standing, Interior, Medium - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+37, 195264, 0, 1537, 5719, '0', 0, 0, -4877.421875, -986.307861328125, 504.7578125, 5.70722818374633789, 0, 0, -0.28401470184326171, 0.958819925785064697, 120, 255, 1, 45745), -- Standing, Interior, Medium - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+38, 195264, 0, 1537, 5719, '0', 0, 0, -4905.373046875, -979.254150390625, 503.518463134765625, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 120, 255, 1, 45745), -- Standing, Interior, Medium - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+39, 195264, 0, 1537, 5719, '0', 0, 0, -4900.673828125, -975.40972900390625, 503.49066162109375, 2.70525527000427246, 0, 0, 0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- Standing, Interior, Medium - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+40, 195264, 0, 1537, 5719, '0', 0, 0, -4886.38330078125, -993.6834716796875, 504.7578125, 2.321286916732788085, 0, 0, 0.917059898376464843, 0.398749500513076782, 120, 255, 1, 45745), -- Standing, Interior, Medium - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+41, 195264, 0, 1537, 5719, '0', 0, 0, -4895.28857421875, -1001.1298828125, 504.7578125, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 120, 255, 1, 45745), -- Standing, Interior, Medium - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+42, 195264, 0, 1537, 5719, '0', 0, 0, -4890.2255859375, -996.79949951171875, 504.7578125, 0.418878614902496337, 0, 0, 0.207911491394042968, 0.978147625923156738, 120, 255, 1, 45745), -- Standing, Interior, Medium - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+43, 195264, 0, 1537, 5719, '0', 0, 0, -4899.34814453125, -1004.4788818359375, 504.7578125, 5.602506637573242187, 0, 0, -0.33380699157714843, 0.942641437053680419, 120, 255, 1, 45745), -- Standing, Interior, Medium - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+44, 195266, 0, 1537, 1537, '0', 0, 0, -4927.70654296875, -1279.470458984375, 509.795623779296875, 2.652894020080566406, 0, 0, 0.970294952392578125, 0.241925001144409179, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: Ironforge - Difficulty: 0)
(@OGUID+45, 195266, 0, 1537, 1537, '0', 0, 0, -4804.95654296875, -1180.3507080078125, 510.45892333984375, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: Ironforge - Difficulty: 0)
(@OGUID+46, 195266, 0, 1537, 5341, '0', 0, 0, -4691.63525390625, -1183.8958740234375, 509.914825439453125, 5.550147056579589843, 0, 0, -0.358367919921875, 0.933580458164215087, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+47, 195266, 0, 1537, 5341, '0', 0, 0, -4732.765625, -1146.4896240234375, 507.5391845703125, 2.652894020080566406, 0, 0, 0.970294952392578125, 0.241925001144409179, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+48, 195266, 0, 1537, 5341, '0', 0, 0, -4614.03662109375, -1114.4791259765625, 509.549957275390625, 3.333590030670166015, 0, 0, -0.99539566040039062, 0.095851235091686248, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+49, 195266, 0, 1537, 5341, '0', 0, 0, -4612.87841796875, -1093.2603759765625, 509.64056396484375, 3.054326534271240234, 0, 0, 0.999048233032226562, 0.043619260191917419, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+50, 195266, 0, 1537, 4679, '0', 0, 0, -4601.875, -1010.21527099609375, 509.9107666015625, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: The Forlorn Cavern - Difficulty: 0)
(@OGUID+51, 195266, 0, 1537, 4679, '0', 0, 0, -4591.765625, -999.46356201171875, 508.2066650390625, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: The Forlorn Cavern - Difficulty: 0)
(@OGUID+52, 195266, 0, 1537, 4679, '0', 0, 0, -4730.88720703125, -1063.310791015625, 508.73834228515625, 3.665196180343627929, 0, 0, -0.96592521667480468, 0.258821308612823486, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: The Forlorn Cavern - Difficulty: 0)
(@OGUID+53, 195266, 0, 1537, 5344, '0', 0, 0, -4707.56591796875, -948.40972900390625, 509.871734619140625, 0.907570242881774902, 0, 0, 0.438370704650878906, 0.898794233798980712, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+54, 195266, 0, 1537, 5344, '0', 0, 0, -4765.7744140625, -913.38714599609375, 508.2344970703125, 1.32644820213317871, 0, 0, 0.615660667419433593, 0.788011372089385986, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+55, 195266, 0, 1537, 5342, '0', 0, 0, -4798.3662109375, -908.9757080078125, 503.249847412109375, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: The Great Forge - Difficulty: 0)
(@OGUID+56, 195266, 0, 1537, 5719, '0', 0, 0, -4880.09716796875, -957.7725830078125, 509.6275634765625, 1.937312245368957519, 0, 0, 0.824125289916992187, 0.566407561302185058, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+57, 195266, 0, 1537, 5719, '0', 0, 0, -4899.02783203125, -982.31427001953125, 510.77691650390625, 2.286378860473632812, 0, 0, 0.909960746765136718, 0.414694398641586303, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+58, 195266, 0, 1537, 5719, '0', 0, 0, -4974.47900390625, -1033.467041015625, 509.7349853515625, 2.775068521499633789, 0, 0, 0.983254432678222656, 0.182238012552261352, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+59, 195266, 0, 1537, 5719, '0', 0, 0, -4989.77783203125, -1117.27783203125, 508.185760498046875, 3.316144466400146484, 0, 0, -0.99619388580322265, 0.087165042757987976, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+60, 195266, 0, 1537, 5719, '0', 0, 0, -5017.75, -1125.0382080078125, 509.957183837890625, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+61, 195266, 0, 1537, 5719, '0', 0, 0, -5030.98095703125, -1153.90283203125, 509.76019287109375, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 120, 255, 1, 45745), -- Hanging; Streamer - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+62, 195266, 0, 1537, 5719, '0', 0, 0, -5041.65283203125, -1166.185791015625, 508.227386474609375, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+63, 195266, 0, 1537, 5343, '0', 0, 0, -4868.57470703125, -1144.732666015625, 510.406951904296875, 0.383971005678176879, 0, 0, 0.190808296203613281, 0.981627285480499267, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: The Military Ward - Difficulty: 0)
(@OGUID+64, 195266, 0, 1537, 5342, '0', 0, 0, -4847.69091796875, -1162.9617919921875, 508.74658203125, 0.837757468223571777, 0, 0, 0.406736373901367187, 0.913545548915863037, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: The Great Forge - Difficulty: 0)
(@OGUID+65, 195273, 0, 1537, 5719, '0', 0, 0, -4879.8349609375, -987.32989501953125, 509.98291015625, 2.146752834320068359, 0, 0, 0.878816604614257812, 0.477159708738327026, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+66, 195273, 0, 1537, 5719, '0', 0, 0, -4888.8212890625, -994.73785400390625, 510.048828125, 2.321286916732788085, 0, 0, 0.917059898376464843, 0.398749500513076782, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+67, 195273, 0, 1537, 5719, '0', 0, 0, -4897.69091796875, -1002.0504150390625, 510.0543212890625, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: The Commons - Difficulty: 0)
(@OGUID+68, 186680, 0, 1537, 809, '0', 0, 0, -5033.79931640625, -789.79864501953125, 495.177642822265625, 3.508116960525512695, 0, 0, -0.98325443267822265, 0.182238012552261352, 120, 255, 1, 45745), -- Brewfest Canopy (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+69, 186717, 0, 1537, 809, '0', 0, 0, -5091.11865234375, -734.7432861328125, 469.9097900390625, 4.799657344818115234, 0, 0, -0.67558956146240234, 0.737277925014495849, 120, 255, 1, 45745), -- Brewfest Banner (Area: The Commons - Difficulty: 0)
(@OGUID+70, 186717, 0, 1537, 809, '0', 0, 0, -5191.740234375, -736.32208251953125, 447.284332275390625, 0.837757468223571777, 0, 0, 0.406736373901367187, 0.913545548915863037, 120, 255, 1, 45745), -- Brewfest Banner (Area: The Commons - Difficulty: 0)
(@OGUID+71, 186717, 0, 1, 0, '0', 0, 0, -5236.78125, -635.82470703125, 421.801300048828125, 0.558503925800323486, 0, 0, 0.275636672973632812, 0.961261868476867675, 120, 255, 1, 45745), -- Brewfest Banner (Area: 0 - Difficulty: 0)
(@OGUID+72, 326138, 0, 1537, 809, '0', 0, 0, -5059.7431640625, -812.64581298828125, 495.141265869140625, 5.969027042388916015, 0, 0, -0.1564340591430664, 0.987688362598419189, 120, 255, 1, 45745), -- Party Table (Area: 0 - Difficulty: 0)
(@OGUID+73, 326138, 0, 1537, 809, '0', 0, 0, -5034.8818359375, -790.35418701171875, 495.166839599609375, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 120, 255, 1, 45745), -- Party Table (Area: 0 - Difficulty: 0)
(@OGUID+74, 326139, 0, 1537, 809, '0', 0, 0, -5059.4443359375, -813.01214599609375, 496.1612548828125, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+75, 326139, 0, 1537, 809, '0', 0, 0, -5034.65087890625, -790.11285400390625, 496.2041015625, 2.897245407104492187, 0, 0, 0.99254608154296875, 0.121869951486587524, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+76, 326139, 0, 1537, 809, '0', 0, 0, -5035.13720703125, -790.7742919921875, 496.193023681640625, 4.97418975830078125, 0, 0, -0.60876083374023437, 0.793353796005249023, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+77, 326139, 0, 1537, 809, '0', 0, 0, -5060.13525390625, -812.2569580078125, 496.189849853515625, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+78, 326139, 0, 1537, 809, '0', 0, 0, -5059.44091796875, -812.359375, 496.1636962890625, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
-- Kharanos
(@OGUID+79, 186709, 0, 1, 131, '0', 0, 0, -5611.814453125, -471.024322509765625, 396.985748291015625, 4.690916061401367187, 0, 0, -0.71465778350830078, 0.699474275112152099, 120, 255, 1, 45745), -- Standing Brewfest Keg (Area: Kharanos - Difficulty: 0)
(@OGUID+80, 186709, 0, 1, 131, '0', 0, 0, -5609.85595703125, -471.1007080078125, 397.0107421875, 4.708369255065917968, 0, 0, -0.708526611328125, 0.705684065818786621, 120, 255, 1, 45745), -- Standing Brewfest Keg (Area: Kharanos - Difficulty: 0)
(@OGUID+81, 186709, 0, 1, 131, '0', 0, 0, -5610.828125, -471.0694580078125, 398.182769775390625, 4.708369255065917968, 0, 0, -0.708526611328125, 0.705684065818786621, 120, 255, 1, 45745), -- Standing Brewfest Keg (Area: Kharanos - Difficulty: 0)
(@OGUID+82, 186709, 0, 1, 131, '0', 0, 0, -5620.79345703125, -476.81597900390625, 396.988922119140625, 5.553114891052246093, 0, 0, -0.35698223114013671, 0.934111177921295166, 120, 255, 1, 45745), -- Standing Brewfest Keg (Area: Kharanos - Difficulty: 0)
(@OGUID+83, 186709, 0, 1, 131, '0', 0, 0, -5619.546875, -475.38714599609375, 396.991729736328125, 5.570568561553955078, 0, 0, -0.3488168716430664, 0.937190890312194824, 120, 255, 1, 45745), -- Standing Brewfest Keg (Area: Kharanos - Difficulty: 0)
(@OGUID+84, 186709, 0, 1, 131, '0', 0, 0, -5620.15087890625, -476.145843505859375, 398.23828125, 5.553114891052246093, 0, 0, -0.35698223114013671, 0.934111177921295166, 120, 255, 1, 45745), -- Standing Brewfest Keg (Area: Kharanos - Difficulty: 0)
(@OGUID+85, 186717, 0, 1, 0, '0', 0, 0, -5337.041015625, -542.3472900390625, 393.658111572265625, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 120, 255, 1, 45745), -- Brewfest Banner (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+86, 186717, 0, 1, 131, '0', 0, 0, -5614.29541015625, -470.458343505859375, 397.272979736328125, 5.404072761535644531, 0, 0, -0.4255380630493164, 0.904940545558929443, 120, 255, 1, 45745), -- Brewfest Banner (Area: 0 - Difficulty: 0)
(@OGUID+87, 186717, 0, 1, 131, '0', 0, 0, -5617.8818359375, -453.87152099609375, 407.706939697265625, 5.160597801208496093, 0, 0, -0.53228187561035156, 0.846567213535308837, 120, 255, 1, 45745), -- Brewfest Banner (Area: 0 - Difficulty: 0)
(@OGUID+88, 186717, 0, 1, 131, '0', 0, 0, -5644.70556640625, -477.0167236328125, 396.748382568359375, 4.607671737670898437, 0, 0, -0.74314403533935546, 0.669131457805633544, 120, 255, 1, 45745), -- Brewfest Banner (Area: 0 - Difficulty: 0)
(@OGUID+89, 186737, 0, 1, 131, '0', 0, 0, -5623.07275390625, -472.848968505859375, 396.9107666015625, 3.750173568725585937, 0.04653024673461914, -0.00302696228027343, -0.95324134826660156, 0.298591256141662597, 120, 255, 1, 45745), -- Brewfest Wagon Loaded (Area: 0 - Difficulty: 0)
(@OGUID+90, 195253, 0, 1, 131, '0', 0, 0, -5582.82666015625, -503.69293212890625, 411.73980712890625, 1.553341388702392578, 0, 0, 0.700908660888671875, 0.713251054286956787, 120, 255, 1, 45745), -- Hanging, Streamer x3 - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+91, 195253, 0, 1, 131, '0', 0, 0, -5575.9365234375, -509.47369384765625, 411.79248046875, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 45745), -- Hanging, Streamer x3 - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+92, 195253, 0, 1, 131, '0', 0, 0, -5578.94287109375, -461.7431640625, 409.891021728515625, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 120, 255, 1, 45745), -- Hanging, Streamer x3 - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+93, 195253, 0, 1, 131, '0', 0, 0, -5576.13427734375, -520.75164794921875, 411.746185302734375, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 45745), -- Hanging, Streamer x3 - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+94, 195253, 0, 1, 131, '0', 0, 0, -5593.0302734375, -509.22906494140625, 411.613677978515625, 3.106652259826660156, 0, 0, 0.999847412109375, 0.017469281330704689, 120, 255, 1, 45745), -- Hanging, Streamer x3 - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+95, 195253, 0, 1, 131, '0', 0, 0, -5604.44775390625, -512.76007080078125, 411.590911865234375, 1.535889506340026855, 0, 0, 0.694658279418945312, 0.719339847564697265, 120, 255, 1, 45745), -- Hanging, Streamer x3 - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+96, 195253, 0, 1, 131, '0', 0, 0, -5596.97705078125, -512.89947509765625, 411.596710205078125, 1.553341388702392578, 0, 0, 0.700908660888671875, 0.713251054286956787, 120, 255, 1, 45745), -- Hanging, Streamer x3 - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+97, 195253, 0, 1, 131, '0', 0, 0, -5612.13818359375, -518.682373046875, 411.9815673828125, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 120, 255, 1, 45745), -- Hanging, Streamer x3 - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+98, 195256, 0, 1, 131, '0', 0, 0, -5461.14892578125, -479.123748779296875, 396.699859619140625, 5.811946868896484375, 0, 0, -0.2334451675415039, 0.972369968891143798, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+99, 195256, 0, 1, 131, '0', 0, 0, -5535.453125, -476.932281494140625, 398.091217041015625, 5.619962215423583984, 0, 0, -0.32556724548339843, 0.945518851280212402, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+100, 195256, 0, 1, 131, '0', 0, 0, -5568.5068359375, -501.36285400390625, 402.859588623046875, 1.362257122993469238, 0, 0, 0.629670143127441406, 0.776862621307373046, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+101, 195256, 0, 1, 131, '0', 0, 0, -5605.66064453125, -489.755035400390625, 397.5626220703125, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+102, 195256, 0, 1, 131, '0', 0, 0, -5588.75634765625, -425.283660888671875, 397.32537841796875, 5.166176319122314453, 0, 0, -0.52991867065429687, 0.84804844856262207, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+103, 195256, 0, 1, 131, '0', 0, 0, -5643.27978515625, -503.156005859375, 396.680999755859375, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+104, 195256, 0, 1, 189, '0', 0, 0, -5483.44384765625, -669.21466064453125, 392.697967529296875, 0.226892471313476562, 0, 0, 0.113203048706054687, 0.993571877479553222, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Steelgrill's Depot - Difficulty: 0)
(@OGUID+105, 195259, 0, 1, 131, '0', 0, 0, -5579.73095703125, -525.05029296875, 404.4669189453125, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 120, 255, 1, 45745), -- Hanging, Square, Small - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+106, 195259, 0, 1, 131, '0', 0, 0, -5590.89892578125, -513.91668701171875, 405.771484375, 1.658061861991882324, 0, 0, 0.737277030944824218, 0.67559051513671875, 120, 255, 1, 45745), -- Hanging, Square, Small - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+107, 195259, 0, 1, 131, '0', 0, 0, -5593.12939453125, -489.43658447265625, 398.36334228515625, 1.535889506340026855, 0, 0, 0.694658279418945312, 0.719339847564697265, 120, 255, 1, 45745), -- Hanging, Square, Small - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+108, 195259, 0, 1, 131, '0', 0, 0, -5608.68359375, -529.57647705078125, 401.06591796875, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 120, 255, 1, 45745), -- Hanging, Square, Small - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+109, 195259, 0, 1, 131, '0', 0, 0, -5608.47900390625, -521.5130615234375, 401.2120361328125, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 45745), -- Hanging, Square, Small - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+110, 195259, 0, 1, 131, '0', 0, 0, -5607.9619140625, -525.49951171875, 402.748626708984375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Hanging, Square, Small - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+111, 195259, 0, 1, 0, '0', 0, 0, -5357.0439453125, -528.7659912109375, 392.575164794921875, 0.645771682262420654, 0, 0, 0.317304611206054687, 0.948323667049407958, 120, 255, 1, 45745), -- Hanging, Square, Small - Brewfest (Area: Steelgrill's Depot - Difficulty: 0)
(@OGUID+112, 195260, 0, 1, 131, '0', 0, 0, -5591.759765625, -508.474273681640625, 405.010467529296875, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+113, 195260, 0, 1, 131, '0', 0, 0, -5594.52880859375, -525.8619384765625, 400.54742431640625, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+114, 195260, 0, 1, 131, '0', 0, 0, -5600.69775390625, -525.1802978515625, 400.54510498046875, 6.213373661041259765, 0, 0, -0.03489875793457031, 0.999390840530395507, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+115, 195260, 0, 1, 131, '0', 0, 0, -5606.85595703125, -527.50006103515625, 402.5877685546875, 3.316144466400146484, 0, 0, -0.99619388580322265, 0.087165042757987976, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+116, 195260, 0, 1, 131, '0', 0, 0, -5604.2412109375, -532.39361572265625, 400.522308349609375, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+117, 195260, 0, 1, 131, '0', 0, 0, -5606.69384765625, -532.3543701171875, 400.522186279296875, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+118, 195260, 0, 1, 131, '0', 0, 0, -5654.71533203125, -502.60589599609375, 398.256683349609375, 4.136432647705078125, 0, 0, -0.87881660461425781, 0.477159708738327026, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+119, 195263, 0, 1, 131, '0', 0, 0, -5576.63720703125, -514.95648193359375, 405.19049072265625, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 120, 255, 1, 45745), -- Hanging, Square, Medium - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+120, 195263, 0, 1, 131, '0', 0, 0, -5573.33447265625, -461.34625244140625, 404.842559814453125, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 120, 255, 1, 45745), -- Hanging, Square, Medium - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+121, 195263, 0, 1, 131, '0', 0, 0, -5585.3916015625, -461.50640869140625, 404.84967041015625, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 120, 255, 1, 45745), -- Hanging, Square, Medium - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+122, 195263, 0, 1, 131, '0', 0, 0, -5592.18212890625, -532.53363037109375, 401.9100341796875, 1.553341388702392578, 0, 0, 0.700908660888671875, 0.713251054286956787, 120, 255, 1, 45745), -- Hanging, Square, Medium - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+123, 195263, 0, 1, 131, '0', 0, 0, -5580.91162109375, -418.451568603515625, 400.41900634765625, 4.956737518310546875, 0, 0, -0.61566066741943359, 0.788011372089385986, 120, 255, 1, 45745), -- Hanging, Square, Medium - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+124, 195264, 0, 1, 131, '0', 0, 0, -5584.56787109375, -528.398193359375, 401.642303466796875, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 120, 255, 1, 45745), -- Standing, Interior, Medium - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+125, 195264, 0, 1, 131, '0', 0, 0, -5584.5546875, -533.061767578125, 404.420074462890625, 0.872663915157318115, 0, 0, 0.422617912292480468, 0.906307935714721679, 120, 255, 1, 45745), -- Standing, Interior, Medium - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+126, 195264, 0, 1, 131, '0', 0, 0, -5586.7158203125, -528.23089599609375, 400.20721435546875, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 120, 255, 1, 45745), -- Standing, Interior, Medium - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+127, 195266, 0, 1, 131, '0', 0, 0, -5480.08056640625, -461.806304931640625, 401.465240478515625, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+128, 195266, 0, 1, 131, '0', 0, 0, -5597.30029296875, -532.34722900390625, 403.071380615234375, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: Kharanos - Difficulty: 0)
(@OGUID+129, 195266, 0, 1, 189, '0', 0, 0, -5519.25927734375, -663.923828125, 403.041656494140625, 0.401424884796142578, 0, 0, 0.199367523193359375, 0.979924798011779785, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: Steelgrill's Depot - Difficulty: 0)
(@OGUID+130, 195266, 0, 1, 189, '0', 0, 0, -5496.23291015625, -689.7177734375, 398.201934814453125, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: Steelgrill's Depot - Difficulty: 0)
-- Brewfest area
(@OGUID+131, 180749, 0, 1, 0, '0', 0, 0, -5127.9306640625, -598.03302001953125, 397.235443115234375, 2.949595451354980468, 0, 0, 0.995395660400390625, 0.095851235091686248, 120, 255, 1, 45745), -- Cheer Speaker (Area: The Commons - Difficulty: 0)
(@OGUID+132, 180749, 0, 1, 0, '0', 0, 0, -5182.361328125, -613.826416015625, 397.176177978515625, 3.892086982727050781, 0, 0, -0.93041706085205078, 0.366502493619918823, 120, 255, 1, 45745), -- Cheer Speaker (Area: The Commons - Difficulty: 0)
(@OGUID+133, 180749, 0, 1, 0, '0', 0, 0, -5141.32470703125, -578.420166015625, 397.176177978515625, 2.426007747650146484, 0, 0, 0.936672210693359375, 0.350207358598709106, 120, 255, 1, 45745), -- Cheer Speaker (Area: The Commons - Difficulty: 0)
(@OGUID+134, 180749, 0, 1, 0, '0', 0, 0, -5182.85400390625, -539.3350830078125, 397.03533935546875, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 45745), -- Cheer Speaker (Area: 0 - Difficulty: 0)
(@OGUID+135, 180749, 0, 1, 0, '0', 0, 0, -5214.48291015625, -514.37847900390625, 389.759490966796875, 0.767943859100341796, 0, 0, 0.374606132507324218, 0.927184045314788818, 120, 255, 1, 45745), -- Cheer Speaker (Area: 0 - Difficulty: 0)
(@OGUID+136, 186183, 0, 1, 0, '0', 0, 0, -5189.96533203125, -595.921875, 397.176177978515625, 0.367745578289031982, 0, 0, 0.18283843994140625, 0.983142971992492675, 120, 255, 1, 45745), -- Barleybrew Festive Keg (Area: 0 - Difficulty: 0)
(@OGUID+137, 186184, 0, 1, 0, '0', 0, 0, -5155.236328125, -634.94793701171875, 397.176177978515625, 1.512226700782775878, 0, 0, 0.686099052429199218, 0.727508127689361572, 120, 255, 1, 45745), -- Thunderbrew Festive Keg (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+138, 186185, 0, 1, 0, '0', 0, 0, -5145.74658203125, -575.6669921875, 397.176177978515625, 3.996806621551513671, 0, 0, -0.90996074676513671, 0.414694398641586303, 120, 255, 1, 45745), -- Gordok Festive Keg (Area: 0 - Difficulty: 0)
(@OGUID+139, 186229, 0, 1, 0, '0', 0, 0, -5191.23095703125, -561.26043701171875, 397.176177978515625, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 120, 255, 1, 45745), -- BREWFEST (Area: 0 - Difficulty: 0)
(@OGUID+140, 186229, 0, 1, 0, '0', 0, 0, -5219.01416015625, -475.206939697265625, 386.661102294921875, 5.532694816589355468, 0, 0, -0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- BREWFEST (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+141, 186680, 0, 1, 0, '0', 0, 0, -5179.603515625, -543.4095458984375, 396.918212890625, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 120, 255, 1, 45745), -- Brewfest Canopy (Area: 0 - Difficulty: 0)
(@OGUID+142, 186680, 0, 1, 0, '0', 0, 0, -5203.517578125, -553.40277099609375, 397.05535888671875, 0.656261026859283447, -0.01025056838989257, 0.000290870666503906, 0.322289466857910156, 0.946585655212402343, 120, 255, 1, 45745), -- Brewfest Canopy (Area: 0 - Difficulty: 0)
(@OGUID+143, 186680, 0, 1, 0, '0', 0, 0, -5195.27978515625, -487.28472900390625, 387.340545654296875, 3.289957761764526367, -0.02402973175048828, -0.00104331970214843, -0.99696254730224609, 0.074075259268283843, 120, 255, 1, 45745), -- Brewfest Canopy (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+144, 186681, 0, 1, 0, '0', 0, 0, -5133.68603515625, -616.80902099609375, 397.386444091796875, 2.691748857498168945, 0, 0, 0.974811553955078125, 0.223030179738998413, 120, 255, 1, 45745), -- Brewfest Food Tent (Area: The Commons - Difficulty: 0)
(@OGUID+145, 186681, 0, 1, 0, '0', 0, 0, -5152.14404296875, -569.76043701171875, 397.176177978515625, 3.906833171844482421, 0, 0, -0.9276895523071289, 0.373352497816085815, 120, 255, 1, 45745), -- Brewfest Food Tent (Area: 0 - Difficulty: 0)
(@OGUID+146, 186681, 0, 1, 0, '0', 0, 0, -5196.408203125, -586.765625, 397.345306396484375, 0.305203020572662353, -0.00017213821411132, 0.000223159790039062, 0.152009963989257812, 0.988378942012786865, 120, 255, 1, 45745), -- Brewfest Food Tent (Area: 0 - Difficulty: 0)
(@OGUID+147, 186682, 0, 1, 0, '0', 0, 0, -5145.57275390625, -635.06427001953125, 397.058685302734375, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 120, 255, 1, 45745), -- Brewfest Beer Tent (Area: The Commons - Difficulty: 0)
(@OGUID+148, 186682, 0, 1, 0, '0', 0, 0, -5136.07275390625, -579.4149169921875, 396.929840087890625, 3.903813838958740234, -0.00360298156738281, -0.00970077514648437, -0.92818260192871093, 0.371981143951416015, 120, 255, 1, 45745), -- Brewfest Beer Tent (Area: The Commons - Difficulty: 0)
(@OGUID+149, 186682, 0, 1, 0, '0', 0, 0, -5188.40966796875, -604.7430419921875, 397.22119140625, 0.383555203676223754, 0, 0, 0.190604209899902343, 0.981666982173919677, 120, 255, 1, 45745), -- Brewfest Beer Tent (Area: 0 - Difficulty: 0)
(@OGUID+150, 186709, 0, 1, 0, '0', 0, 0, -5199.19775390625, -482.0625, 388.743072509765625, 1.87280893325805664, 0.034667491912841796, -0.00905227661132812, 0.805176734924316406, 0.591951549053192138, 120, 255, 1, 45745), -- Standing Brewfest Keg (Area: 0 - Difficulty: 0)
(@OGUID+151, 186709, 0, 1, 0, '0', 0, 0, -5197.49462890625, -481.48785400390625, 388.539215087890625, 1.904643177986145019, 0.0253753662109375, 0.006776809692382812, 0.814679145812988281, 0.57931685447692871, 120, 255, 1, 45745), -- Standing Brewfest Keg (Area: 0 - Difficulty: 0)
(@OGUID+152, 186709, 0, 1, 0, '0', 0, 0, -5198.6162109375, -485.37847900390625, 388.463409423828125, 3.389041423797607421, -0.0312199592590332, 0.022108078002929687, -0.99171924591064453, 0.122594818472862243, 120, 255, 1, 45745), -- Standing Brewfest Keg (Area: 0 - Difficulty: 0)
(@OGUID+153, 186717, 0, 1, 0, '0', 0, 0, -5136.81103515625, -631.40802001953125, 397.179443359375, 1.692969322204589843, 0, 0, 0.748955726623535156, 0.662620067596435546, 120, 255, 1, 45745), -- Brewfest Banner (Area: The Commons - Difficulty: 0)
(@OGUID+154, 186717, 0, 1, 0, '0', 0, 0, -5134.11474609375, -586.72259521484375, 397.176177978515625, 3.473210096359252929, 0, 0, -0.98628520965576171, 0.165049895644187927, 120, 255, 1, 45745), -- Brewfest Banner (Area: The Commons - Difficulty: 0)
(@OGUID+155, 186717, 0, 1, 0, '0', 0, 0, -5164.85791015625, -603.02081298828125, 398.0625, 2.101161479949951171, 0, 0, 0.867712020874023437, 0.497067242860794067, 120, 255, 1, 45745), -- Brewfest Banner (Area: The Commons - Difficulty: 0)
(@OGUID+156, 186717, 0, 1, 0, '0', 0, 0, -5157.57470703125, -597.72222900390625, 398.04681396484375, 2.258240699768066406, 0, 0, 0.904036521911621093, 0.427455246448516845, 120, 255, 1, 45745), -- Brewfest Banner (Area: The Commons - Difficulty: 0)
(@OGUID+157, 186717, 0, 1, 0, '0', 0, 0, -5182.33154296875, -609.93402099609375, 397.176177978515625, 0.505728900432586669, 0, 0, 0.250178337097167968, 0.968199789524078369, 120, 255, 1, 45745), -- Brewfest Banner (Area: The Commons - Difficulty: 0)
(@OGUID+158, 186717, 0, 1, 0, '0', 0, 0, -5207.18408203125, -535.75421142578125, 393.794586181640625, 1.780233979225158691, 0, 0, 0.7771453857421875, 0.629321098327636718, 120, 255, 1, 45745), -- Brewfest Banner (Area: 0 - Difficulty: 0)
(@OGUID+159, 186717, 0, 1, 0, '0', 0, 0, -5189.30029296875, -525.50616455078125, 392.525360107421875, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 45745), -- Brewfest Banner (Area: 0 - Difficulty: 0)
(@OGUID+160, 186717, 0, 1, 0, '0', 0, 0, -5197.20947265625, -505.30718994140625, 388.59759521484375, 2.007128477096557617, 0, 0, 0.84339141845703125, 0.537299633026123046, 120, 255, 1, 45745), -- Brewfest Banner (Area: 0 - Difficulty: 0)
(@OGUID+161, 186717, 0, 1, 0, '0', 0, 0, -5214.62841796875, -514.1524658203125, 389.731689453125, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 120, 255, 1, 45745), -- Brewfest Banner (Area: 0 - Difficulty: 0)
(@OGUID+162, 186717, 0, 1, 0, '0', 0, 0, -5205.44775390625, -479.062347412109375, 389.14642333984375, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 120, 255, 1, 45745), -- Brewfest Banner (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+163, 186717, 0, 1, 0, '0', 0, 0, -5218.609375, -491.612640380859375, 387.8887939453125, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 45745), -- Brewfest Banner (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+164, 186717, 0, 1, 0, '0', 0, 0, -5252.0107421875, -477.250335693359375, 386.6239013671875, 4.904376029968261718, 0, 0, -0.636077880859375, 0.771624863147735595, 120, 255, 1, 45745), -- Brewfest Banner (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+165, 186717, 0, 1, 0, '0', 0, 0, -5199.62158203125, -432.817718505859375, 390.41156005859375, 2.72271275520324707, 0, 0, 0.978147506713867187, 0.207912087440490722, 120, 255, 1, 45745), -- Brewfest Banner (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+166, 186737, 0, 1, 0, '0', 0, 0, -5218.58349609375, -528.55731201171875, 390.734710693359375, 6.253242969512939453, -0.08941602706909179, -0.08510684967041015, -0.02253150939941406, 0.992095708847045898, 120, 255, 1, 45745), -- Brewfest Wagon Loaded (Area: 0 - Difficulty: 0)
(@OGUID+167, 209654, 0, 1, 0, '0', 0, 0, -5125.5537109375, -606.68231201171875, 397.66583251953125, 3.039757966995239257, -0.03496217727661132, 0.021801948547363281, 0.997818946838378906, 0.051572069525718688, 120, 255, 1, 45745), -- Pandaren Tent (Area: 0 - Difficulty: 0)
(@OGUID+168, 211694, 0, 1, 0, '0', 0, 0, -5128.595703125, -606.3055419921875, 397.227203369140625, 3.024551153182983398, 0, 0, 0.998288154602050781, 0.058487351983785629, 120, 255, 1, 45745), -- Pandaren Brew (Area: 0 - Difficulty: 0)
(@OGUID+169, 211694, 0, 1, 0, '0', 0, 0, -5126.609375, -605.38543701171875, 397.246307373046875, 2.554158210754394531, 0, 0, 0.957174301147460937, 0.289512276649475097, 120, 255, 1, 45745), -- Pandaren Brew (Area: 0 - Difficulty: 0)
(@OGUID+170, 211694, 0, 1, 0, '0', 0, 0, -5126.93212890625, -607.92535400390625, 397.358367919921875, 3.514313697814941406, 0, 0, -0.98268508911132812, 0.185283601284027099, 120, 255, 1, 45745), -- Pandaren Brew (Area: 0 - Difficulty: 0)
(@OGUID+171, 211694, 0, 1, 0, '0', 0, 0, -5124.939453125, -606.951416015625, 397.59014892578125, 4.401078701019287109, 0, 0, -0.80817890167236328, 0.588937103748321533, 120, 255, 1, 45745), -- Pandaren Brew (Area: 0 - Difficulty: 0)
(@OGUID+172, 211694, 0, 1, 0, '0', 0, 0, -5123.20654296875, -605.44964599609375, 397.632415771484375, 1.078956365585327148, -0.01513099670410156, -0.02004241943359375, 0.513338088989257812, 0.857818961143493652, 120, 255, 1, 45745), -- Pandaren Brew (Area: 0 - Difficulty: 0)
(@OGUID+173, 211694, 0, 1, 0, '0', 0, 0, -5123.1162109375, -608.4461669921875, 397.986541748046875, 4.367090702056884765, 0.051519393920898437, -0.06827735900878906, -0.81521415710449218, 0.572808682918548583, 120, 255, 1, 45745), -- Pandaren Brew (Area: 0 - Difficulty: 0)
(@OGUID+174, 221481, 0, 1, 0, '0', 0, 0, -5129.921875, -606.1319580078125, 397.397491455078125, 6.168809890747070312, -0.0073862075805664, 0.002363204956054687, -0.05714035034179687, 0.998336017131805419, 120, 255, 1, 45745), -- Pandaren Kitchen Table (Area: 0 - Difficulty: 0)
(@OGUID+175, 221482, 0, 1, 0, '0', 0, 0, -5132.37353515625, -604.842041015625, 398.2662353515625, 4.305674552917480468, 0, 0, -0.8353424072265625, 0.549730002880096435, 120, 255, 1, 45745), -- PA Mug Bamboo 06 (Area: The Commons - Difficulty: 0)
(@OGUID+176, 221482, 0, 1, 0, '0', 0, 0, -5132.8662109375, -606.904541015625, 398.27825927734375, 5.296348094940185546, 0, 0, -0.47363948822021484, 0.880718827247619628, 120, 255, 1, 45745), -- PA Mug Bamboo 06 (Area: The Commons - Difficulty: 0)
(@OGUID+177, 221482, 0, 1, 0, '0', 0, 0, -5132.85595703125, -606.24481201171875, 398.26959228515625, 4.72117471694946289, 0, 0, -0.70399379730224609, 0.710206151008605957, 120, 255, 1, 45745), -- PA Mug Bamboo 06 (Area: The Commons - Difficulty: 0)
(@OGUID+178, 231782, 0, 1, 0, '0', 0, 0, -5200.220703125, -574.58331298828125, 397.350555419921875, 3.250709056854248046, -0.05051612854003906, -0.01075077056884765, -0.99715709686279296, 0.054865412414073944, 120, 255, 1, 45745), -- Draenei Wagon (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+179, 231868, 0, 1, 0, '0', 0, 0, -5190.69091796875, -573.6632080078125, 397.181488037109375, 0.129276603460311889, -0.01019811630249023, 0.012632369995117187, 0.064708709716796875, 0.997772097587585449, 120, 255, 1, 45745), -- Draenei Table (Area: 0 - Difficulty: 0)
(@OGUID+180, 233577, 0, 1, 0, '0', 0, 0, -5198.0712890625, -575.7100830078125, 398.69427490234375, 0.250584542751312255, 0, 0, 0.124964714050292968, 0.992161214351654052, 120, 255, 1, 45745), -- Crystal Crates (Area: 0 - Difficulty: 0)
(@OGUID+181, 233577, 0, 1, 0, '0', 0, 0, -5197.92724609375, -572.8507080078125, 398.575225830078125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Crystal Crates (Area: 0 - Difficulty: 0)
(@OGUID+182, 246194, 0, 1, 0, '0', 0, 0, -5168.40283203125, -564.55902099609375, 398.311065673828125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Wine Glass (Area: 0 - Difficulty: 0)
(@OGUID+183, 246194, 0, 1, 0, '0', 0, 0, -5165.064453125, -566.83331298828125, 398.293914794921875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Wine Glass (Area: 0 - Difficulty: 0)
(@OGUID+184, 246194, 0, 1, 0, '0', 0, 0, -5167.859375, -564.8680419921875, 398.302581787109375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Wine Glass (Area: 0 - Difficulty: 0)
(@OGUID+185, 259240, 0, 1, 0, '0', 0, 0, -5169.09716796875, -542.9375, 397.176177978515625, 0.21569843590259552, 0, 0, 0.107640266418457031, 0.994189918041229248, 120, 255, 1, 45745), -- Hay (Area: 0 - Difficulty: 0)
(@OGUID+186, 279592, 0, 1, 0, '0', 0, 0, -5183.61474609375, -482.83160400390625, 387.448394775390625, 0.963018059730529785, 0.017711639404296875, -0.09468650817871093, 0.458652496337890625, 0.883379101753234863, 120, 255, 1, 45745), -- Trough (Area: 0 - Difficulty: 0)
(@OGUID+187, 280648, 0, 1, 0, '0', 0, 0, -5164.1787109375, -636.8663330078125, 397.17620849609375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Barrel 02 (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+188, 280648, 0, 1, 0, '0', 0, 0, -5164.6494140625, -633.5625, 397.17620849609375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Barrel 02 (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+189, 280928, 0, 1, 0, '0', 0, 0, -5159.63720703125, -633.1180419921875, 397.123138427734375, 1.885481953620910644, 0, 0, 0.809171676635742187, 0.587572276592254638, 120, 255, 1, 45745), -- Barrel Rack (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+190, 280928, 0, 1, 0, '0', 0, 0, -5167.60595703125, -630.875, 397.176177978515625, 0.886673569679260253, 0, 0, 0.428956031799316406, 0.903325378894805908, 120, 255, 1, 45745), -- Barrel Rack (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+191, 281065, 0, 1, 0, '0', 0, 0, -5171.57666015625, -618.73785400390625, 398.1895751953125, 5.485543251037597656, 0, 0, -0.38833236694335937, 0.921519398689270019, 120, 255, 1, 45745), -- Cup (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+192, 281065, 0, 1, 0, '0', 0, 0, -5171.908203125, -618.19268798828125, 398.1895751953125, 1.914103865623474121, 0, 0, 0.81749725341796875, 0.575932502746582031, 120, 255, 1, 45745), -- Cup (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+193, 281065, 0, 1, 0, '0', 0, 0, -5175.0556640625, -613.93402099609375, 398.1895751953125, 4.951069831848144531, 0, 0, -0.61789131164550781, 0.786263525485992431, 120, 255, 1, 45745), -- Cup (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+194, 281065, 0, 1, 0, '0', 0, 0, -5171.54541015625, -618.1163330078125, 398.1895751953125, 0.430601328611373901, 0, 0, 0.213641166687011718, 0.976912200450897216, 120, 255, 1, 45745), -- Cup (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+195, 281065, 0, 1, 0, '0', 0, 0, -5175.46337890625, -613.0694580078125, 398.1895751953125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Cup (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+196, 282271, 0, 1, 0, '0', 0, 0, -5182.80224609375, -488.34375, 386.33673095703125, 2.678557634353637695, 0.036777496337890625, -0.01990890502929687, 0.9723663330078125, 0.229684174060821533, 120, 255, 1, 45745), -- Haypile (Area: 0 - Difficulty: 0)
(@OGUID+197, 288421, 0, 1, 0, '0', 0, 0, -5114.96533203125, -589.99652099609375, 397.177398681640625, 1.203696250915527343, 0, 0, 0.566166877746582031, 0.824290633201599121, 120, 255, 1, 45745), -- Hay Bale (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+198, 288422, 0, 1, 0, '0', 0, 0, -5115.55224609375, -590.04864501953125, 397.621673583984375, 2.615433216094970703, -0.30772686004638671, 0.098198890686035156, 0.912507057189941406, 0.250982135534286499, 120, 255, 1, 45745), -- Hay Bale (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+199, 288422, 0, 1, 0, '0', 0, 0, -5168.890625, -538.97222900390625, 397.176666259765625, 6.043868064880371093, 0, 0, -0.11937332153320312, 0.992849469184875488, 120, 255, 1, 45745), -- Hay Bale (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+200, 292549, 0, 1, 0, '0', 0, 0, -5117.33154296875, -590.99652099609375, 397.17620849609375, 0.107637859880924224, 0, 0, 0.053792953491210937, 0.99855208396911621, 120, 255, 1, 45745), -- Hay Bale (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+201, 292549, 0, 1, 0, '0', 0, 0, -5113.5, -584.0555419921875, 397.397979736328125, 5.420305252075195312, 0, 0, -0.41817951202392578, 0.908364415168762207, 120, 255, 1, 45745), -- Hay Bale (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+202, 292549, 0, 1, 0, '0', 0, 0, -5166.970703125, -538.93231201171875, 397.17645263671875, 5.575615406036376953, 0, 0, -0.3464508056640625, 0.938068151473999023, 120, 255, 1, 45745), -- Hay Bale (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+203, 298876, 0, 1, 0, '0', 0, 0, -5160.63525390625, -629.32293701171875, 398.328765869140625, 4.86590576171875, 0, 0, -0.65080165863037109, 0.759247779846191406, 120, 255, 1, 45745), -- Kul Tiras Mug (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+204, 298876, 0, 1, 0, '0', 0, 0, -5162.2431640625, -628.810791015625, 398.369384765625, 1.768260955810546875, 0, 0, 0.773364067077636718, 0.633962154388427734, 120, 255, 1, 45745), -- Kul Tiras Mug (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+205, 326019, 0, 1, 0, '0', 0, 0, -5200.8505859375, -574.6492919921875, 399.01861572265625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Draenei Barrel (Area: 0 - Difficulty: 0)
(@OGUID+206, 326019, 0, 1, 0, '0', 0, 0, -5200.6318359375, -573.18231201171875, 398.967987060546875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Draenei Barrel (Area: 0 - Difficulty: 0)
(@OGUID+207, 326019, 0, 1, 0, '0', 0, 0, -5200.484375, -575.99481201171875, 398.97705078125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Draenei Barrel (Area: 0 - Difficulty: 0)
(@OGUID+208, 326019, 0, 1, 0, '0', 0, 0, -5199.078125, -574.43927001953125, 398.927520751953125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Draenei Barrel (Area: 0 - Difficulty: 0)
(@OGUID+209, 326020, 0, 1, 0, '0', 0, 0, -5194.8037109375, -577.8819580078125, 397.176177978515625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Draenei Lantern (Area: 0 - Difficulty: 0)
(@OGUID+210, 326020, 0, 1, 0, '0', 0, 0, -5195.455078125, -569.55206298828125, 397.176177978515625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Draenei Lantern (Area: 0 - Difficulty: 0)
(@OGUID+211, 326022, 0, 1, 0, '0', 0, 0, -5190.8037109375, -571.3819580078125, 398.416473388671875, 0.703427672386169433, 0, 0, 0.344507217407226562, 0.938783645629882812, 120, 255, 1, 45745), -- Draenei Jug (Area: 0 - Difficulty: 0)
(@OGUID+212, 326023, 0, 1, 0, '0', 0, 0, -5197.77783203125, -574.609375, 398.610748291015625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Draenei Jar (Area: 0 - Difficulty: 0)
(@OGUID+213, 326023, 0, 1, 0, '0', 0, 0, -5190.5, -575.201416015625, 398.475830078125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Draenei Jar (Area: 0 - Difficulty: 0)
(@OGUID+214, 326025, 0, 1, 0, '0', 0, 0, -5190.25537109375, -575.62677001953125, 398.400970458984375, 1.443730115890502929, 0, 0, 0.660785675048828125, 0.750574648380279541, 120, 255, 1, 45745), -- Draenei Cup (Area: 0 - Difficulty: 0)
(@OGUID+215, 326025, 0, 1, 0, '0', 0, 0, -5190.45166015625, -572.92364501953125, 398.400970458984375, 1.668605923652648925, 0, 0, 0.740828514099121093, 0.67169421911239624, 120, 255, 1, 45745), -- Draenei Cup (Area: 0 - Difficulty: 0)
(@OGUID+216, 326025, 0, 1, 0, '0', 0, 0, -5189.93408203125, -575.84722900390625, 398.400970458984375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Draenei Cup (Area: 0 - Difficulty: 0)
(@OGUID+217, 326025, 0, 1, 0, '0', 0, 0, -5189.72412109375, -575.092041015625, 398.400970458984375, 2.225578546524047851, 0, 0, 0.896935462951660156, 0.442161440849304199, 120, 255, 1, 45745), -- Draenei Cup (Area: 0 - Difficulty: 0)
(@OGUID+218, 326028, 0, 1, 0, '0', 0, 0, -5163.8369140625, -561.97393798828125, 397.18011474609375, 0.96457529067993164, 0, 0, 0.463807106018066406, 0.885936200618743896, 120, 255, 1, 45745), -- Void Elf Tent (Area: 0 - Difficulty: 0)
(@OGUID+219, 326032, 0, 1, 0, '0', 0, 0, -5164.96533203125, -566.623291015625, 397.176177978515625, 4.280599594116210937, 0, 0, -0.84216880798339843, 0.539213955402374267, 120, 255, 1, 45745), -- Void Elf Bar (Area: 0 - Difficulty: 0)
(@OGUID+220, 326032, 0, 1, 0, '0', 0, 0, -5168.01025390625, -564.54168701171875, 397.176177978515625, 3.905273675918579101, 0, 0, -0.92798042297363281, 0.372628986835479736, 120, 255, 1, 45745), -- Void Elf Bar (Area: 0 - Difficulty: 0)
(@OGUID+221, 326033, 0, 1, 0, '0', 0, 0, -5163.7099609375, -627.3055419921875, 397.237701416015625, 4.500928878784179687, 0, 0, -0.77778148651123046, 0.628534793853759765, 120, 255, 1, 45745), -- Stool (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+222, 326033, 0, 1, 0, '0', 0, 0, -5162.173828125, -627.66668701171875, 397.237701416015625, 4.546746253967285156, 0, 0, -0.76317977905273437, 0.646186232566833496, 120, 255, 1, 45745), -- Stool (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+223, 326033, 0, 1, 0, '0', 0, 0, -5160.65478515625, -628, 397.237701416015625, 4.534585475921630859, 0, 0, -0.76709461212158203, 0.641533970832824707, 120, 255, 1, 45745), -- Stool (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+224, 326033, 0, 1, 0, '0', 0, 0, -5168.67724609375, -565.17364501953125, 397.176177978515625, 0.878904163837432861, 0, 0, 0.425443649291992187, 0.904984891414642333, 120, 255, 1, 45745), -- Stool (Area: 0 - Difficulty: 0)
(@OGUID+225, 326033, 0, 1, 0, '0', 0, 0, -5165.375, -567.4774169921875, 397.176177978515625, 1.297124147415161132, 0, 0, 0.604041099548339843, 0.796953141689300537, 120, 255, 1, 45745), -- Stool (Area: 0 - Difficulty: 0)
(@OGUID+226, 326035, 0, 1, 0, '0', 0, 0, -5164.65625, -566.8507080078125, 398.300628662109375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Voidwine (Area: 0 - Difficulty: 0)
(@OGUID+227, 326039, 0, 1, 0, '0', 0, 0, -5160.85400390625, -562.045166015625, 396.997955322265625, 3.822455406188964843, 0, 0, -0.94261074066162109, 0.33389371633529663, 120, 255, 1, 45745), -- Voidwine Barrel (Area: 0 - Difficulty: 0)
(@OGUID+228, 326040, 0, 1, 0, '0', 0, 0, -5162.67724609375, -560.70831298828125, 396.904144287109375, 3.818240880966186523, -0.12697172164916992, -0.05511856079101562, -0.93377494812011718, 0.330006778240203857, 120, 255, 1, 45745), -- Void Elf Banner (Area: 0 - Difficulty: 0)
(@OGUID+229, 326041, 0, 1, 0, '0', 0, 0, -5164.921875, -558.4461669921875, 397.176177978515625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Voidwine Barrel (Area: 0 - Difficulty: 0)
(@OGUID+230, 326041, 0, 1, 0, '0', 0, 0, -5165.7568359375, -558.6024169921875, 397.176177978515625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Voidwine Barrel (Area: 0 - Difficulty: 0)
(@OGUID+231, 326042, 0, 1, 0, '0', 0, 0, -5164.3212890625, -558.9930419921875, 397.5264892578125, 5.115803718566894531, 0.594038963317871093, -0.38591194152832031, -0.3934640884399414, 0.585982680320739746, 120, 255, 1, 45745), -- Voidwine Barrel (Area: 0 - Difficulty: 0)
(@OGUID+232, 326044, 0, 1, 0, '0', 0, 0, -5164.44091796875, -636.59027099609375, 397.17620849609375, 1.319617033004760742, 0, 0, 0.612965583801269531, 0.790109574794769287, 120, 255, 1, 45745), -- Kul Tiran Tent (Area: The Commons - Difficulty: 0)
(@OGUID+233, 326045, 0, 1, 0, '0', 0, 0, -5162.48291015625, -628.94097900390625, 397.230377197265625, 1.343426108360290527, 0, 0, 0.622327804565429687, 0.782756745815277099, 120, 255, 1, 45745), -- Kul Tiran Bar (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+234, 326046, 0, 1, 0, '0', 0, 0, -5163.54541015625, -638.6632080078125, 397.17620849609375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Kul Tiran Barrel (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+235, 326046, 0, 1, 0, '0', 0, 0, -5166.27978515625, -637.73614501953125, 397.17620849609375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Kul Tiran Barrel (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+236, 326046, 0, 1, 0, '0', 0, 0, -5162.68408203125, -635.28125, 397.043609619140625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Kul Tiran Barrel (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+237, 326046, 0, 1, 0, '0', 0, 0, -5159.35595703125, -634.0069580078125, 398.117950439453125, 0.293403208255767822, -0.70722818374633789, 0.113614082336425781, 0.317144393920898437, 0.621562182903289794, 120, 255, 1, 45745), -- Kul Tiran Barrel (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+238, 326046, 0, 1, 0, '0', 0, 0, -5164.78466796875, -635.96356201171875, 397.12091064453125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Kul Tiran Barrel (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+239, 326046, 0, 1, 0, '0', 0, 0, -5168.20654296875, -631.578125, 398.170989990234375, 5.577785968780517578, -0.56644344329833984, 0.4384307861328125, -0.01925373077392578, 0.697531044483184814, 120, 255, 1, 45745), -- Kul Tiran Barrel (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+240, 326051, 0, 1, 0, '0', 0, 0, -5119.0380859375, -581.779541015625, 397.2867431640625, 4.202334880828857421, 0, 0, -0.86261940002441406, 0.505853474140167236, 120, 255, 1, 45745), -- Outhouse (Area: 0 - Difficulty: 0)
(@OGUID+241, 326051, 0, 1, 0, '0', 0, 0, -5116.064453125, -584.234375, 397.23968505859375, 3.831080198287963867, 0, 0, -0.941162109375, 0.337955445051193237, 120, 255, 1, 45745), -- Outhouse (Area: 0 - Difficulty: 0)
(@OGUID+242, 326051, 0, 1, 0, '0', 0, 0, -5114.15966796875, -587.6649169921875, 397.21405029296875, 3.442747354507446289, 0, 0, -0.98868465423583984, 0.150008872151374816, 120, 255, 1, 45745), -- Outhouse (Area: 0 - Difficulty: 0)
(@OGUID+243, 326052, 0, 1, 0, '0', 0, 0, -5180.767578125, -621.8524169921875, 397.176177978515625, 3.980662107467651367, 0, 0, -0.91327857971191406, 0.407335519790649414, 120, 255, 1, 45745), -- Mole Machine (Area: The Commons - Difficulty: 0)
(@OGUID+244, 326063, 0, 1, 0, '0', 0, 0, -5171.80908203125, -618.3992919921875, 396.7427978515625, 4.633829593658447265, 0, 0, -0.7343292236328125, 0.678793489933013916, 120, 255, 1, 45745), -- Dark Iron Table (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+245, 326063, 0, 1, 0, '0', 0, 0, -5175.515625, -613.623291015625, 396.728424072265625, 5.868887901306152343, 0, 0, -0.20567035675048828, 0.978621363639831542, 120, 255, 1, 45745), -- Dark Iron Table (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+246, 326106, 0, 1, 0, '0', 0, 0, -5218.3837890625, -501.517364501953125, 387.872711181640625, 0.598423898220062255, -0.02807378768920898, -0.01465415954589843, 0.2944488525390625, 0.955142378807067871, 120, 255, 1, 45745), -- Pandaren Noodle Cart (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+247, 326138, 0, 1, 0, '0', 0, 0, -5145.91650390625, -623.3507080078125, 397.682159423828125, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 120, 255, 1, 45745), -- Party Table (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+248, 326138, 0, 1, 0, '0', 0, 0, -5174.27783203125, -594.07293701171875, 397.849090576171875, 0.016056232154369354, 0, 0, 0.008028030395507812, 0.999967753887176513, 120, 255, 1, 45745), -- Party Table (Area: 0 - Difficulty: 0)
(@OGUID+249, 326138, 0, 1, 0, '0', 0, 0, -5183.34228515625, -583.8507080078125, 397.643951416015625, 0.401424884796142578, 0, 0, 0.199367523193359375, 0.979924798011779785, 120, 255, 1, 45745), -- Party Table (Area: 0 - Difficulty: 0)
(@OGUID+250, 326138, 0, 1, 0, '0', 0, 0, -5142.04345703125, -606.40972900390625, 398.206787109375, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 120, 255, 1, 45745), -- Party Table (Area: 0 - Difficulty: 0)
(@OGUID+251, 326138, 0, 1, 0, '0', 0, 0, -5160.45654296875, -593.65625, 397.989593505859375, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 120, 255, 1, 45745), -- Party Table (Area: 0 - Difficulty: 0)
(@OGUID+252, 326138, 0, 1, 0, '0', 0, 0, -5179.06787109375, -545.79339599609375, 397.17510986328125, 3.281238555908203125, 0, 0, -0.99756336212158203, 0.069766148924827575, 120, 255, 1, 45745), -- Party Table (Area: 0 - Difficulty: 0)
(@OGUID+253, 326138, 0, 1, 0, '0', 0, 0, -5162.3837890625, -573.11285400390625, 397.176177978515625, 3.78736734390258789, 0, 0, -0.94832324981689453, 0.317305892705917358, 120, 255, 1, 45745), -- Party Table (Area: 0 - Difficulty: 0)
(@OGUID+254, 326138, 0, 1, 0, '0', 0, 0, -5179.36962890625, -540.63543701171875, 397.0732421875, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 120, 255, 1, 45745), -- Party Table (Area: 0 - Difficulty: 0)
(@OGUID+255, 326138, 0, 1, 0, '0', 0, 0, -5212.578125, -509.3125, 389.029327392578125, 0.174532130360603332, 0, 0, 0.087155342102050781, 0.996194720268249511, 120, 255, 1, 45745), -- Party Table (Area: 0 - Difficulty: 0)
(@OGUID+256, 326138, 0, 1, 0, '0', 0, 0, -5192.580078125, -516.39410400390625, 389.979248046875, 3.612837791442871093, 0, 0, -0.97236919403076171, 0.233448356389999389, 120, 255, 1, 45745), -- Party Table (Area: 0 - Difficulty: 0)
(@OGUID+257, 326138, 0, 1, 0, '0', 0, 0, -5136.16162109375, -591.39581298828125, 397.176177978515625, 0.383971005678176879, 0, 0, 0.190808296203613281, 0.981627285480499267, 120, 255, 1, 45745), -- Party Table (Area: 0 - Difficulty: 0)
(@OGUID+258, 326139, 0, 1, 0, '0', 0, 0, -5146.20166015625, -623.54864501953125, 398.764007568359375, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+259, 326139, 0, 1, 0, '0', 0, 0, -5145.5400390625, -623.375, 398.770843505859375, 3.45575571060180664, 0, 0, -0.98768806457519531, 0.156436234712600708, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+260, 326139, 0, 1, 0, '0', 0, 0, -5146.24658203125, -622.99481201171875, 398.756195068359375, 2.984498262405395507, 0, 0, 0.996916770935058593, 0.078466430306434631, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+261, 326139, 0, 1, 0, '0', 0, 0, -5173.74658203125, -594.33331298828125, 398.915008544921875, 5.60111236572265625, 0, 0, -0.33446407318115234, 0.942408502101898193, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+262, 326139, 0, 1, 0, '0', 0, 0, -5174.111328125, -593.67364501953125, 398.901580810546875, 1.551945924758911132, 0, 0, 0.700410842895507812, 0.713739931583404541, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+263, 326139, 0, 1, 0, '0', 0, 0, -5174.4443359375, -594.3367919921875, 398.887420654296875, 0.766549289226531982, 0, 0, 0.373959541320800781, 0.927444994449615478, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+264, 326139, 0, 1, 0, '0', 0, 0, -5145.84912109375, -622.9461669921875, 398.762054443359375, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+265, 326139, 0, 1, 0, '0', 0, 0, -5182.86962890625, -583.61456298828125, 398.705963134765625, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+266, 326139, 0, 1, 0, '0', 0, 0, -5142.08837890625, -606.05731201171875, 399.255279541015625, 5.427974700927734375, 0, 0, -0.41469287872314453, 0.909961462020874023, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+267, 326139, 0, 1, 0, '0', 0, 0, -5182.88037109375, -584.07989501953125, 398.705963134765625, 1.361356139183044433, 0, 0, 0.629320144653320312, 0.77714616060256958, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+268, 326139, 0, 1, 0, '0', 0, 0, -5160.75341796875, -593.59552001953125, 399.090789794921875, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+269, 326139, 0, 1, 0, '0', 0, 0, -5160.361328125, -593.3680419921875, 399.051025390625, 5.427974700927734375, 0, 0, -0.41469287872314453, 0.909961462020874023, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+270, 326139, 0, 1, 0, '0', 0, 0, -5141.84228515625, -606.51043701171875, 399.271392822265625, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+271, 326139, 0, 1, 0, '0', 0, 0, -5183.470703125, -584.2882080078125, 398.705963134765625, 6.195919513702392578, 0, 0, -0.04361915588378906, 0.999048233032226562, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+272, 326139, 0, 1, 0, '0', 0, 0, -5183.48779296875, -583.55902099609375, 398.705963134765625, 3.892086982727050781, 0, 0, -0.93041706085205078, 0.366502493619918823, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+273, 326139, 0, 1, 0, '0', 0, 0, -5160.11474609375, -593.8211669921875, 399.065673828125, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+274, 326139, 0, 1, 0, '0', 0, 0, -5142.17724609375, -606.7899169921875, 399.283111572265625, 2.643405437469482421, 0, 0, 0.969136238098144531, 0.246525704860687255, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+275, 326139, 0, 1, 0, '0', 0, 0, -5160.44775390625, -594.1007080078125, 399.100341796875, 2.643405437469482421, 0, 0, 0.969136238098144531, 0.246525704860687255, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+276, 326139, 0, 1, 0, '0', 0, 0, -5161.9755859375, -573.53643798828125, 398.244903564453125, 4.999567985534667968, 0, 0, -0.59864521026611328, 0.801014304161071777, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+277, 326139, 0, 1, 0, '0', 0, 0, -5162.55224609375, -573.59893798828125, 398.244903564453125, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+278, 326139, 0, 1, 0, '0', 0, 0, -5162.28125, -573.1788330078125, 398.251861572265625, 5.900098323822021484, 0, 0, -0.19037437438964843, 0.981711566448211669, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+279, 326139, 0, 1, 0, '0', 0, 0, -5162.953125, -573.265625, 398.244903564453125, 0.401424884796142578, 0, 0, 0.199367523193359375, 0.979924798011779785, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+280, 326139, 0, 1, 0, '0', 0, 0, -5179.62158203125, -545.93402099609375, 398.24468994140625, 3.351046562194824218, 0, 0, -0.99452114105224609, 0.104535527527332305, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+281, 326139, 0, 1, 0, '0', 0, 0, -5179.13720703125, -546.0225830078125, 398.25177001953125, 3.420850038528442382, 0, 0, -0.99026775360107421, 0.139175355434417724, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+282, 326139, 0, 1, 0, '0', 0, 0, -5162.35791015625, -572.51910400390625, 398.23046875, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+283, 326139, 0, 1, 0, '0', 0, 0, -5178.8125, -545.625, 398.24395751953125, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+284, 326139, 0, 1, 0, '0', 0, 0, -5179.3037109375, -545.545166015625, 398.243804931640625, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+285, 326139, 0, 1, 0, '0', 0, 0, -5179.20849609375, -540.17706298828125, 398.10089111328125, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+286, 326139, 0, 1, 0, '0', 0, 0, -5179.1630859375, -540.81427001953125, 398.08917236328125, 5.70722818374633789, 0, 0, -0.28401470184326171, 0.958819925785064697, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+287, 326139, 0, 1, 0, '0', 0, 0, -5179.82666015625, -540.4305419921875, 398.110565185546875, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+288, 326139, 0, 1, 0, '0', 0, 0, -5179.59375, -540.96527099609375, 398.12139892578125, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+289, 326139, 0, 1, 0, '0', 0, 0, -5193.017578125, -516.328125, 391.02032470703125, 5.644706249237060546, 0, 0, -0.31384468078613281, 0.949474334716796875, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+290, 326139, 0, 1, 0, '0', 0, 0, -5212.33154296875, -509.095489501953125, 390.1075439453125, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+291, 326139, 0, 1, 0, '0', 0, 0, -5212.796875, -509.154510498046875, 390.0870361328125, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+292, 326139, 0, 1, 0, '0', 0, 0, -5192.625, -516.8663330078125, 391.000030517578125, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+293, 326139, 0, 1, 0, '0', 0, 0, -5192.39599609375, -516.13018798828125, 391.023468017578125, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+294, 326139, 0, 1, 0, '0', 0, 0, -5212.267578125, -509.5382080078125, 390.0928955078125, 0.645771682262420654, 0, 0, 0.317304611206054687, 0.948323667049407958, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+295, 326139, 0, 1, 0, '0', 0, 0, -5136.125, -591.75, 398.24188232421875, 1.361356139183044433, 0, 0, 0.629320144653320312, 0.77714616060256958, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+296, 326139, 0, 1, 0, '0', 0, 0, -5135.95166015625, -591.295166015625, 398.24188232421875, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+297, 326139, 0, 1, 0, '0', 0, 0, -5136.2744140625, -590.96527099609375, 398.24188232421875, 4.48549652099609375, 0, 0, -0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: 0 - Difficulty: 0)
(@OGUID+298, 326705, 0, 1, 0, '0', 0, 0, -5192.1181640625, -591.28302001953125, 397.17620849609375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: 0 - Difficulty: 0)
(@OGUID+299, 326705, 0, 1, 0, '0', 0, 0, -5166.546875, -603.31597900390625, 397.92095947265625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: 0 - Difficulty: 0)
(@OGUID+300, 326705, 0, 1, 0, '0', 0, 0, -5138.65625, -619.8125, 397.58795166015625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: 0 - Difficulty: 0)
(@OGUID+301, 326705, 0, 1, 0, '0', 0, 0, -5157.1630859375, -596.28472900390625, 398.020111083984375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: 0 - Difficulty: 0)
(@OGUID+302, 326705, 0, 1, 0, '0', 0, 0, -5194.423828125, -580.84722900390625, 397.176177978515625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: 0 - Difficulty: 0)
(@OGUID+303, 326705, 0, 1, 0, '0', 0, 0, -5134.09716796875, -611.03302001953125, 397.53985595703125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: 0 - Difficulty: 0)
(@OGUID+304, 326705, 0, 1, 0, '0', 0, 0, -5184.548828125, -539.83331298828125, 397.09051513671875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: 0 - Difficulty: 0)
(@OGUID+305, 326705, 0, 1, 0, '0', 0, 0, -5208.515625, -531.592041015625, 392.644378662109375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: 0 - Difficulty: 0)
(@OGUID+306, 326705, 0, 1, 0, '0', 0, 0, -5184.2431640625, -547.513916015625, 397.175201416015625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: 0 - Difficulty: 0)
(@OGUID+307, 326705, 0, 1, 0, '0', 0, 0, -5151.45849609375, -575.546875, 397.17620849609375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: 0 - Difficulty: 0)
(@OGUID+308, 326705, 0, 1, 0, '0', 0, 0, -5157.70654296875, -567.998291015625, 397.176177978515625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: 0 - Difficulty: 0)
(@OGUID+309, 326705, 0, 1, 0, '0', 0, 0, -5190.642578125, -523.23785400390625, 391.599761962890625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: 0 - Difficulty: 0)
(@OGUID+310, 326705, 0, 1, 0, '0', 0, 0, -5222.125, -473.25347900390625, 386.369781494140625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: 0 - Difficulty: 0)
(@OGUID+311, 326705, 0, 1, 0, '0', 0, 0, -5213.21533203125, -464.263885498046875, 386.511962890625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: 0 - Difficulty: 0)
(@OGUID+312, 326705, 0, 1, 0, '0', 0, 0, -5132.625, -591.373291015625, 397.17681884765625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: 0 - Difficulty: 0)
(@OGUID+313, 326705, 0, 1, 0, '0', 0, 0, -5129.68408203125, -599.31597900390625, 397.193511962890625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: 0 - Difficulty: 0)
(@OGUID+314, 326707, 0, 1, 0, '0', 0, 0, -5125.3662109375, -617.22052001953125, 397.93609619140625, 0.166002079844474792, 0, 0, 0.082905769348144531, 0.996557414531707763, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+315, 326707, 0, 1, 0, '0', 0, 0, -5170.8974609375, -553.65625, 397.17620849609375, 4.760150432586669921, 0, 0, -0.69002056121826171, 0.723789811134338378, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+316, 326708, 0, 1, 0, '0', 0, 0, -5125.94970703125, -614.62847900390625, 397.799224853515625, 0.286381840705871582, 0, 0, 0.142702102661132812, 0.989765703678131103, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+317, 326708, 0, 1, 0, '0', 0, 0, -5128.18603515625, -599.359375, 397.176300048828125, 3.162077665328979492, 0, 0, -0.99994754791259765, 0.010242274031043052, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+318, 326708, 0, 1, 0, '0', 0, 0, -5131.4755859375, -587.44964599609375, 397.176177978515625, 0.470459818840026855, 0, 0, 0.233066558837890625, 0.972460806369781494, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+319, 326708, 0, 1, 0, '0', 0, 0, -5143.52978515625, -572.1805419921875, 397.176177978515625, 3.868233680725097656, 0, 0, -0.93472194671630859, 0.355379939079284667, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+320, 326708, 0, 1, 0, '0', 0, 0, -5197.18603515625, -593.63714599609375, 397.49725341796875, 0.214370891451835632, 0, 0, 0.106980323791503906, 0.994261145591735839, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+321, 326708, 0, 1, 0, '0', 0, 0, -5173.56103515625, -553.7430419921875, 397.176177978515625, 1.723410487174987792, 0, 0, 0.758954048156738281, 0.651144206523895263, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+322, 326708, 0, 1, 0, '0', 0, 0, -5198.6318359375, -567.01043701171875, 397.20025634765625, 5.476744651794433593, 0, 0, -0.39238262176513671, 0.919802069664001464, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+323, 326709, 0, 1, 0, '0', 0, 0, -5200.60400390625, -568.935791015625, 397.281463623046875, 2.507968902587890625, 0, 0, 0.95023345947265625, 0.311538755893707275, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+324, 326710, 0, 1, 0, '0', 0, 0, -5144.22412109375, -641.15802001953125, 397.17620849609375, 1.729996323585510253, 0, 0, 0.761094093322753906, 0.648641467094421386, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+325, 326710, 0, 1, 0, '0', 0, 0, -5141.6650390625, -640.6649169921875, 397.17620849609375, 1.776776552200317382, 0, 0, 0.776056289672851562, 0.630663633346557617, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+326, 326710, 0, 1, 0, '0', 0, 0, -5154.08349609375, -642.8367919921875, 397.17620849609375, 1.746273636817932128, 0, 0, 0.766347885131835937, 0.642425775527954101, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+327, 326710, 0, 1, 0, '0', 0, 0, -5136.96875, -638.79168701171875, 397.176116943359375, 2.090372085571289062, 0, 0, 0.865017890930175781, 0.501740992069244384, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+328, 326710, 0, 1, 0, '0', 0, 0, -5161.8193359375, -643.67706298828125, 397.17620849609375, 1.624502897262573242, 0, 0, 0.72583770751953125, 0.687865972518920898, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+329, 326710, 0, 1, 0, '0', 0, 0, -5129.142578125, -632.20831298828125, 397.212677001953125, 2.427927494049072265, 0, 0, 0.937007904052734375, 0.349308162927627563, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+330, 326710, 0, 1, 0, '0', 0, 0, -5130.80224609375, -634.1319580078125, 397.19097900390625, 2.381143093109130859, 0, 0, 0.92858123779296875, 0.371129155158996582, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+331, 326710, 0, 1, 0, '0', 0, 0, -5139.27099609375, -639.94964599609375, 397.176239013671875, 1.907614588737487792, 0, 0, 0.815624237060546875, 0.578581988811492919, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+332, 326710, 0, 1, 0, '0', 0, 0, -5159.22216796875, -643.5242919921875, 397.17620849609375, 1.632976174354553222, 0, 0, 0.728745460510253906, 0.68478471040725708, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+333, 326710, 0, 1, 0, '0', 0, 0, -5125.5625, -625.51043701171875, 397.928924560546875, 2.857323169708251953, 0, 0, 0.989915847778320312, 0.141656696796417236, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+334, 326710, 0, 1, 0, '0', 0, 0, -5125.3125, -620.01739501953125, 397.878997802734375, 3.236804723739624023, 0, 0, -0.99886703491210937, 0.047588013112545013, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+335, 326710, 0, 1, 0, '0', 0, 0, -5126.501953125, -628.05731201171875, 397.70086669921875, 2.725889444351196289, 0, 0, 0.978476524353027343, 0.206358194351196289, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+336, 326710, 0, 1, 0, '0', 0, 0, -5132.876953125, -635.97222900390625, 397.196197509765625, 2.258870124816894531, 0, 0, 0.904170989990234375, 0.42717069387435913, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+337, 326710, 0, 1, 0, '0', 0, 0, -5134.8193359375, -637.421875, 397.17620849609375, 2.13715362548828125, 0, 0, 0.876516342163085937, 0.481372088193893432, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+338, 326710, 0, 1, 0, '0', 0, 0, -5149.080078125, -642.12847900390625, 397.17620849609375, 1.729905247688293457, 0, 0, 0.761064529418945312, 0.648676156997680664, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+339, 326710, 0, 1, 0, '0', 0, 0, -5127.69091796875, -630.26043701171875, 397.463531494140625, 2.549642324447631835, 0, 0, 0.956518173217773437, 0.291672766208648681, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+340, 326710, 0, 1, 0, '0', 0, 0, -5125.16650390625, -622.875, 397.89874267578125, 3.030885696411132812, 0, 0, 0.998468399047851562, 0.05532519519329071, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+341, 326710, 0, 1, 0, '0', 0, 0, -5146.55908203125, -641.5625, 397.17620849609375, 1.796420812606811523, 0, 0, 0.782213211059570312, 0.623010814189910888, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+342, 326710, 0, 1, 0, '0', 0, 0, -5151.65966796875, -642.50347900390625, 397.17620849609375, 1.683123469352722167, 0, 0, 0.745684623718261718, 0.666299104690551757, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+343, 326710, 0, 1, 0, '0', 0, 0, -5156.63037109375, -643.27606201171875, 397.17620849609375, 1.679760217666625976, 0, 0, 0.744563102722167968, 0.667552053928375244, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+344, 326710, 0, 1, 0, '0', 0, 0, -5166.859375, -642.90625, 397.17620849609375, 1.146090626716613769, 0, 0, 0.542193412780761718, 0.840253710746765136, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+345, 326710, 0, 1, 0, '0', 0, 0, -5169.11962890625, -641.67535400390625, 397.17620849609375, 0.969405174255371093, 0, 0, 0.465945243835449218, 0.884813547134399414, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+346, 326710, 0, 1, 0, '0', 0, 0, -5164.32275390625, -643.6024169921875, 397.17620849609375, 1.382834315299987792, 0, 0, 0.637629508972167968, 0.770343184471130371, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+347, 326710, 0, 1, 0, '0', 0, 0, -5171.158203125, -640.232666015625, 397.17620849609375, 0.943816900253295898, 0, 0, 0.454586982727050781, 0.890702366828918457, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+348, 326710, 0, 1, 0, '0', 0, 0, -5173.22216796875, -638.685791015625, 397.176177978515625, 0.903493523597717285, 0, 0, 0.436537742614746093, 0.899685919284820556, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+349, 326710, 0, 1, 0, '0', 0, 0, -5177.27978515625, -635.421875, 397.176177978515625, 0.872886896133422851, 0, 0, 0.422719001770019531, 0.906260788440704345, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+350, 326710, 0, 1, 0, '0', 0, 0, -5175.30908203125, -637.0399169921875, 397.176177978515625, 0.903493523597717285, 0, 0, 0.436537742614746093, 0.899685919284820556, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+351, 326710, 0, 1, 0, '0', 0, 0, -5183.3681640625, -630.21875, 397.176177978515625, 0.756322264671325683, 0, 0, 0.369212150573730468, 0.929345130920410156, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+352, 326710, 0, 1, 0, '0', 0, 0, -5179.3369140625, -633.7274169921875, 397.176177978515625, 0.872886896133422851, 0, 0, 0.422719001770019531, 0.906260788440704345, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+353, 326710, 0, 1, 0, '0', 0, 0, -5181.390625, -631.984375, 397.176177978515625, 0.872886896133422851, 0, 0, 0.422719001770019531, 0.906260788440704345, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+354, 326710, 0, 1, 0, '0', 0, 0, -5185.18603515625, -628.30035400390625, 397.176177978515625, 0.745153367519378662, 0, 0, 0.364016532897949218, 0.931392490863800048, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+355, 326710, 0, 1, 0, '0', 0, 0, -5186.8125, -626.22052001953125, 397.176177978515625, 0.505139827728271484, 0, 0, 0.2498931884765625, 0.968273401260375976, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+356, 326710, 0, 1, 0, '0', 0, 0, -5187.98095703125, -623.78643798828125, 397.176177978515625, 0.308157920837402343, 0, 0, 0.153470039367675781, 0.988153278827667236, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+357, 326710, 0, 1, 0, '0', 0, 0, -5190.03125, -616.50177001953125, 397.176177978515625, 0.250782549381256103, 0, 0, 0.125062942504882812, 0.992148816585540771, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+358, 326710, 0, 1, 0, '0', 0, 0, -5193.5087890625, -606.51910400390625, 397.1788330078125, 0.354274392127990722, 0, 0, 0.176212310791015625, 0.984352171421051025, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+359, 326710, 0, 1, 0, '0', 0, 0, -5189.28466796875, -619.09552001953125, 397.176177978515625, 0.225481539964675903, 0, 0, 0.112502098083496093, 0.993651449680328369, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+360, 326710, 0, 1, 0, '0', 0, 0, -5188.67041015625, -621.4913330078125, 397.176177978515625, 0.276720911264419555, 0, 0, 0.137919425964355468, 0.99044346809387207, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+361, 326710, 0, 1, 0, '0', 0, 0, -5192.63916015625, -609.01043701171875, 397.17926025390625, 0.342590510845184326, 0, 0, 0.170458793640136718, 0.985364794731140136, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+362, 326710, 0, 1, 0, '0', 0, 0, -5194.38916015625, -604.07989501953125, 397.396820068359375, 0.255781680345535278, 0, 0, 0.127542495727539062, 0.991833090782165527, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+363, 326710, 0, 1, 0, '0', 0, 0, -5190.8681640625, -614.0399169921875, 397.176177978515625, 0.265682846307754516, 0, 0, 0.132451057434082031, 0.991189539432525634, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+364, 326710, 0, 1, 0, '0', 0, 0, -5191.72900390625, -611.56427001953125, 397.176177978515625, 0.342365980148315429, 0, 0, 0.170348167419433593, 0.985383927822113037, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+365, 326710, 0, 1, 0, '0', 0, 0, -5195.15087890625, -601.498291015625, 397.503326416015625, 0.255781680345535278, 0, 0, 0.127542495727539062, 0.991833090782165527, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+366, 326710, 0, 1, 0, '0', 0, 0, -5196.51904296875, -596.310791015625, 397.507720947265625, 0.255781680345535278, 0, 0, 0.127542495727539062, 0.991833090782165527, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+367, 326710, 0, 1, 0, '0', 0, 0, -5148.44775390625, -566.01043701171875, 397.176177978515625, 3.798154354095458984, 0, 0, -0.94659805297851562, 0.322416037321090698, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+368, 326710, 0, 1, 0, '0', 0, 0, -5146.90087890625, -567.99652099609375, 397.176177978515625, 3.791561841964721679, 0, 0, -0.94765567779541015, 0.319294124841690063, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+369, 326710, 0, 1, 0, '0', 0, 0, -5195.861328125, -598.99481201171875, 397.6397705078125, 0.255781680345535278, 0, 0, 0.127542495727539062, 0.991833090782165527, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+370, 326710, 0, 1, 0, '0', 0, 0, -5145.30712890625, -570.1163330078125, 397.176177978515625, 3.791561841964721679, 0, 0, -0.94765567779541015, 0.319294124841690063, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+371, 326710, 0, 1, 0, '0', 0, 0, -5154.1787109375, -560.57989501953125, 397.176177978515625, 3.952394485473632812, 0, 0, -0.91894435882568359, 0.39438718557357788, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+372, 326710, 0, 1, 0, '0', 0, 0, -5152.25341796875, -562.27606201171875, 397.176177978515625, 3.952394485473632812, 0, 0, -0.91894435882568359, 0.39438718557357788, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+373, 326710, 0, 1, 0, '0', 0, 0, -5150.25, -564.1649169921875, 397.176177978515625, 3.952394485473632812, 0, 0, -0.91894435882568359, 0.39438718557357788, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+374, 326710, 0, 1, 0, '0', 0, 0, -5156.25, -558.8367919921875, 397.176177978515625, 3.989417552947998046, 0, 0, -0.91148662567138671, 0.411329716444015502, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+375, 326710, 0, 1, 0, '0', 0, 0, -5165.5712890625, -553.810791015625, 397.176177978515625, 4.519698143005371093, 0, 0, -0.77184867858886718, 0.635806262493133544, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+376, 326710, 0, 1, 0, '0', 0, 0, -5163.04541015625, -554.6319580078125, 397.176177978515625, 4.18112945556640625, 0, 0, -0.86793422698974609, 0.496679127216339111, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+377, 326710, 0, 1, 0, '0', 0, 0, -5160.6806640625, -555.920166015625, 397.176177978515625, 4.18112945556640625, 0, 0, -0.86793422698974609, 0.496679127216339111, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+378, 326710, 0, 1, 0, '0', 0, 0, -5168.23974609375, -553.59375, 397.176177978515625, 4.641857147216796875, 0, 0, -0.7315988540649414, 0.681735336780548095, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+379, 326710, 0, 1, 0, '0', 0, 0, -5158.42041015625, -557.25, 397.176177978515625, 4.05233001708984375, 0, 0, -0.89809894561767578, 0.439793437719345092, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+380, 326711, 0, 1, 0, '0', 0, 0, -5172.98779296875, -548.0538330078125, 397.13677978515625, 1.665784955024719238, 0.008561134338378906, 0.076592445373535156, 0.735773086547851562, 0.672828555107116699, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+381, 326711, 0, 1, 0, '0', 0, 0, -5188.47900390625, -491.864593505859375, 386.9805908203125, 1.759848356246948242, 0.004950523376464843, 0.076910972595214843, 0.766592025756835937, 0.637492656707763671, 120, 255, 1, 45745), -- Fence (Area: 0 - Difficulty: 0)
(@OGUID+382, 326712, 0, 1, 0, '0', 0, 0, -5117.66162109375, -592.404541015625, 397.178680419921875, 4.84009552001953125, 0, 0, -0.66054534912109375, 0.750786125659942626, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+383, 326712, 0, 1, 0, '0', 0, 0, -5121.44775390625, -582.22052001953125, 397.17633056640625, 5.839450359344482421, 0, 0, -0.22005176544189453, 0.975488185882568359, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+384, 326712, 0, 1, 0, '0', 0, 0, -5174.2431640625, -537.6163330078125, 397.027008056640625, 1.649347543716430664, 0.020443916320800781, 0.009914398193359375, 0.734255790710449218, 0.678492605686187744, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+385, 326712, 0, 1, 0, '0', 0, 0, -5190.173828125, -481.267364501953125, 387.583587646484375, 1.651724457740783691, 0.020432472229003906, 0.009938240051269531, 0.7350616455078125, 0.677619457244873046, 120, 255, 1, 45745), -- Fence (Area: 0 - Difficulty: 0)
(@OGUID+386, 326713, 0, 1, 0, '0', 0, 0, -5123.578125, -584.623291015625, 397.176177978515625, 2.0926666259765625, 0, 0, 0.86559295654296875, 0.500748276710510253, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+387, 326713, 0, 1, 0, '0', 0, 0, -5120.80224609375, -593.65277099609375, 397.176177978515625, 2.0926666259765625, 0, 0, 0.86559295654296875, 0.500748276710510253, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+388, 326714, 0, 1, 0, '0', 0, 0, -5123.765625, -595.25177001953125, 397.176177978515625, 2.0926666259765625, 0, 0, 0.86559295654296875, 0.500748276710510253, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+389, 326714, 0, 1, 0, '0', 0, 0, -5129.45849609375, -587.9757080078125, 397.176177978515625, 2.0926666259765625, 0, 0, 0.86559295654296875, 0.500748276710510253, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+390, 326714, 0, 1, 0, '0', 0, 0, -5126.517578125, -597.05902099609375, 397.176177978515625, 2.204650163650512695, 0, 0, 0.892259597778320312, 0.451522767543792724, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+391, 326714, 0, 1, 0, '0', 0, 0, -5126.54345703125, -586.31427001953125, 397.176177978515625, 2.0926666259765625, 0, 0, 0.86559295654296875, 0.500748276710510253, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+392, 326714, 0, 1, 0, '0', 0, 0, -5169.54345703125, -547.62677001953125, 397.13385009765625, 4.813327312469482421, -0.01427030563354492, -0.01123428344726562, -0.67046451568603515, 0.741719245910644531, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+393, 326714, 0, 1, 0, '0', 0, 0, -5166.1875, -547.40277099609375, 397.13385009765625, 4.802457332611083984, -0.00433015823364257, -0.0470895767211914, -0.67300605773925781, 0.738123714923858642, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+394, 326714, 0, 1, 0, '0', 0, 0, -5164.845703125, -545.55731201171875, 397.10760498046875, 0.144406542181968688, 0.011277198791503906, -0.02405261993408203, 0.072350502014160156, 0.99702543020248413, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+395, 326714, 0, 1, 0, '0', 0, 0, -5165.34228515625, -542.15972900390625, 397.13385009765625, 0.105491809546947479, 0.027575016021728515, -0.0208740234375, 0.053278923034667968, 0.997980594635009765, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+396, 326714, 0, 1, 0, '0', 0, 0, -5165.6650390625, -538.78125, 397.134185791015625, 0.126816213130950927, 0.046977043151855468, -0.02099895477294921, 0.064371109008789062, 0.996598482131958007, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+397, 326714, 0, 1, 0, '0', 0, 0, -5170.908203125, -537.3992919921875, 397.13385009765625, 1.5889512300491333, 0.026137351989746093, -0.0079355239868164, 0.713444709777832031, 0.700178921222686767, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+398, 326714, 0, 1, 0, '0', 0, 0, -5167.5224609375, -537.28125, 397.134674072265625, 1.580087900161743164, 0.026101589202880859, -0.00805091857910156, 0.71033477783203125, 0.703333735466003417, 120, 255, 1, 45745), -- Fence (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+399, 326714, 0, 1, 0, '0', 0, 0, -5181.546875, -482.229156494140625, 387.47320556640625, 0.166832908987998962, 0.047387599945068359, -0.02005481719970703, 0.08429718017578125, 0.995111167430877685, 120, 255, 1, 45745), -- Fence (Area: 0 - Difficulty: 0)
(@OGUID+400, 326714, 0, 1, 0, '0', 0, 0, -5185.064453125, -491.22222900390625, 386.694244384765625, 4.853343486785888671, -0.01404285430908203, -0.01151752471923828, -0.65549087524414062, 0.754984676837921142, 120, 255, 1, 45745), -- Fence (Area: 0 - Difficulty: 0)
(@OGUID+401, 326714, 0, 1, 0, '0', 0, 0, -5181.71728515625, -490.86285400390625, 386.747802734375, 4.842473506927490234, -0.00338697433471679, -0.04716682434082031, -0.65810394287109375, 0.751440644264221191, 120, 255, 1, 45745), -- Fence (Area: 0 - Difficulty: 0)
(@OGUID+402, 326714, 0, 1, 0, '0', 0, 0, -5186.84228515625, -480.98089599609375, 387.292205810546875, 1.60205698013305664, 0.026188850402832031, -0.00776386260986328, 0.718017578125, 0.69548875093460083, 120, 255, 1, 45745), -- Fence (Area: 0 - Difficulty: 0)
(@OGUID+403, 326714, 0, 1, 0, '0', 0, 0, -5183.46728515625, -480.755218505859375, 387.535064697265625, 1.671592354774475097, 0.026442527770996093, -0.00684833526611328, 0.741759300231933593, 0.670109689235687255, 120, 255, 1, 45745), -- Fence (Area: 0 - Difficulty: 0)
(@OGUID+404, 326714, 0, 1, 0, '0', 0, 0, -5180.45166015625, -488.96527099609375, 386.878448486328125, 0.162047371268272399, 0.050759315490722656, -0.02096176147460937, 0.082033157348632812, 0.995115399360656738, 120, 255, 1, 45745), -- Fence (Area: 0 - Difficulty: 0)
(@OGUID+405, 326714, 0, 1, 0, '0', 0, 0, -5181.08154296875, -485.59375, 387.21612548828125, 0.144628554582595825, 0.050574779510498046, -0.02140331268310546, 0.073363304138183593, 0.995792090892791748, 120, 255, 1, 45745), -- Fence (Area: 0 - Difficulty: 0)
(@OGUID+406, 327133, 0, 1, 0, '0', 0, 0, -5157.5869140625, -604.07293701171875, 397.884490966796875, 2.235637664794921875, 0, 0, 0.899147987365722656, 0.437644720077514648, 120, 255, 1, 45745), -- Shoutbox (Area: The Commons - Difficulty: 0)
(@OGUID+407, 327134, 0, 1, 0, '0', 0, 0, -5161.94287109375, -601.87152099609375, 400.393829345703125, 0.635089218616485595, 0, 0, 0.312234878540039062, 0.950004935264587402, 120, 255, 1, 45745), -- Brewfest Ceremonial Keg (Area: The Commons - Difficulty: 0)
(@OGUID+408, 327165, 0, 1, 0, '0', 0, 0, -5172.90625, -628.5069580078125, 397.176177978515625, 4.959664344787597656, 0, 0, -0.61450672149658203, 0.78891158103942871, 120, 255, 1, 45745), -- Keg (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+409, 327165, 0, 1, 0, '0', 0, 0, -5172.080078125, -627.3038330078125, 397.176177978515625, 3.633215665817260742, 0, 0, -0.969940185546875, 0.243343427777290344, 120, 255, 1, 45745), -- Keg (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+410, 327165, 0, 1, 0, '0', 0, 0, -5171.3662109375, -628.65625, 397.176177978515625, 0.351994037628173828, 0, 0, 0.175089836120605468, 0.984552443027496337, 120, 255, 1, 45745), -- Keg (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+411, 327182, 0, 1, 0, '0', 0, 0, -5199.470703125, -550.09722900390625, 397.13055419921875, 0.629682838916778564, 0, 0, 0.309665679931640625, 0.95084547996520996, 120, 255, 1, 45745), -- Table (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+412, 327538, 0, 1, 0, '0', 0, 0, -5201.3837890625, -554.40802001953125, 397.176177978515625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Flag (Area: 0 - Difficulty: 0)
(@OGUID+413, 327539, 0, 1, 0, '0', 0, 0, -5202.22412109375, -553.23785400390625, 397.176177978515625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Flag (Area: 0 - Difficulty: 0)
(@OGUID+414, 327540, 0, 1, 0, '0', 0, 0, -5203.109375, -551.9288330078125, 397.163970947265625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Flag (Area: 0 - Difficulty: 0)
(@OGUID+415, 327541, 0, 1, 0, '0', 0, 0, -5203.939453125, -550.640625, 397.14215087890625, 0, 0, 0, 0, 1, 120, 255, 1, 45745); -- Flag (Area: 0 - Difficulty: 0)

DELETE FROM `gameobject_addon` WHERE `guid`=@OGUID+243;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+243, 0, 0, 0, 1, 0, 13176); -- Mole Machine

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=24 AND `guid` BETWEEN @CGUID+0 AND @CGUID+98;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(24, @CGUID+0), 
(24, @CGUID+1), 
(24, @CGUID+2), 
(24, @CGUID+3), 
(24, @CGUID+4), 
(24, @CGUID+5), 
(24, @CGUID+6), 
(24, @CGUID+7), 
(24, @CGUID+8), 
(24, @CGUID+9), 
(24, @CGUID+10),
(24, @CGUID+11),
(24, @CGUID+12),
(24, @CGUID+13),
(24, @CGUID+14),
(24, @CGUID+15),
(24, @CGUID+16),
(24, @CGUID+17),
(24, @CGUID+18),
(24, @CGUID+19),
(24, @CGUID+20),
(24, @CGUID+21),
(24, @CGUID+22),
(24, @CGUID+23),
(24, @CGUID+24),
(24, @CGUID+25),
(24, @CGUID+26),
(24, @CGUID+27),
(24, @CGUID+28),
(24, @CGUID+29),
(24, @CGUID+30),
(24, @CGUID+31),
(24, @CGUID+32),
(24, @CGUID+33),
(24, @CGUID+34),
(24, @CGUID+35),
(24, @CGUID+36),
(24, @CGUID+37),
(24, @CGUID+38),
(24, @CGUID+39),
(24, @CGUID+40),
(24, @CGUID+41),
(24, @CGUID+42),
(24, @CGUID+43),
(24, @CGUID+44),
(24, @CGUID+45),
(24, @CGUID+46),
(24, @CGUID+47),
(24, @CGUID+48),
(24, @CGUID+49),
(24, @CGUID+50),
(24, @CGUID+51),
(24, @CGUID+52),
(24, @CGUID+53),
(24, @CGUID+54),
(24, @CGUID+55),
(24, @CGUID+56),
(24, @CGUID+57),
(24, @CGUID+58),
(24, @CGUID+59),
(24, @CGUID+60),
(24, @CGUID+61),
(24, @CGUID+62),
(24, @CGUID+63),
(24, @CGUID+64),
(24, @CGUID+65),
(24, @CGUID+66),
(24, @CGUID+67),
(24, @CGUID+68),
(24, @CGUID+69),
(24, @CGUID+70),
(24, @CGUID+71),
(24, @CGUID+72),
(24, @CGUID+73),
(24, @CGUID+74),
(24, @CGUID+75),
(24, @CGUID+76),
(24, @CGUID+77),
(24, @CGUID+78),
(24, @CGUID+79),
(24, @CGUID+80),
(24, @CGUID+81),
(24, @CGUID+82),
(24, @CGUID+83),
(24, @CGUID+84),
(24, @CGUID+85),
(24, @CGUID+86),
(24, @CGUID+87),
(24, @CGUID+88),
(24, @CGUID+89),
(24, @CGUID+90),
(24, @CGUID+91),
(24, @CGUID+92),
(24, @CGUID+93),
(24, @CGUID+94),
(24, @CGUID+95),
(24, @CGUID+96),
(24, @CGUID+97),
(24, @CGUID+98);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=24 AND `guid` BETWEEN @OGUID+0 AND @OGUID+415;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(24, @OGUID+0),
(24, @OGUID+1),
(24, @OGUID+2),
(24, @OGUID+3),
(24, @OGUID+4),
(24, @OGUID+5),
(24, @OGUID+6),
(24, @OGUID+7),
(24, @OGUID+8),
(24, @OGUID+9),
(24, @OGUID+10),
(24, @OGUID+11),
(24, @OGUID+12),
(24, @OGUID+13),
(24, @OGUID+14),
(24, @OGUID+15),
(24, @OGUID+16),
(24, @OGUID+17),
(24, @OGUID+18),
(24, @OGUID+19),
(24, @OGUID+20),
(24, @OGUID+21),
(24, @OGUID+22),
(24, @OGUID+23),
(24, @OGUID+24),
(24, @OGUID+25),
(24, @OGUID+26),
(24, @OGUID+27),
(24, @OGUID+28),
(24, @OGUID+29),
(24, @OGUID+30),
(24, @OGUID+31),
(24, @OGUID+32),
(24, @OGUID+33),
(24, @OGUID+34),
(24, @OGUID+35),
(24, @OGUID+36),
(24, @OGUID+37),
(24, @OGUID+38),
(24, @OGUID+39),
(24, @OGUID+40),
(24, @OGUID+41),
(24, @OGUID+42),
(24, @OGUID+43),
(24, @OGUID+44),
(24, @OGUID+45),
(24, @OGUID+46),
(24, @OGUID+47),
(24, @OGUID+48),
(24, @OGUID+49),
(24, @OGUID+50),
(24, @OGUID+51),
(24, @OGUID+52),
(24, @OGUID+53),
(24, @OGUID+54),
(24, @OGUID+55),
(24, @OGUID+56),
(24, @OGUID+57),
(24, @OGUID+58),
(24, @OGUID+59),
(24, @OGUID+60),
(24, @OGUID+61),
(24, @OGUID+62),
(24, @OGUID+63),
(24, @OGUID+64),
(24, @OGUID+65),
(24, @OGUID+66),
(24, @OGUID+67),
(24, @OGUID+68),
(24, @OGUID+69),
(24, @OGUID+70),
(24, @OGUID+71),
(24, @OGUID+72),
(24, @OGUID+73),
(24, @OGUID+74),
(24, @OGUID+75),
(24, @OGUID+76),
(24, @OGUID+77),
(24, @OGUID+78),
(24, @OGUID+79),
(24, @OGUID+80),
(24, @OGUID+81),
(24, @OGUID+82),
(24, @OGUID+83),
(24, @OGUID+84),
(24, @OGUID+85),
(24, @OGUID+86),
(24, @OGUID+87),
(24, @OGUID+88),
(24, @OGUID+89),
(24, @OGUID+90),
(24, @OGUID+91),
(24, @OGUID+92),
(24, @OGUID+93),
(24, @OGUID+94),
(24, @OGUID+95),
(24, @OGUID+96),
(24, @OGUID+97),
(24, @OGUID+98),
(24, @OGUID+99),
(24, @OGUID+100),
(24, @OGUID+101),
(24, @OGUID+102),
(24, @OGUID+103),
(24, @OGUID+104),
(24, @OGUID+105),
(24, @OGUID+106),
(24, @OGUID+107),
(24, @OGUID+108),
(24, @OGUID+109),
(24, @OGUID+110),
(24, @OGUID+111),
(24, @OGUID+112),
(24, @OGUID+113),
(24, @OGUID+114),
(24, @OGUID+115),
(24, @OGUID+116),
(24, @OGUID+117),
(24, @OGUID+118),
(24, @OGUID+119),
(24, @OGUID+120),
(24, @OGUID+121),
(24, @OGUID+122),
(24, @OGUID+123),
(24, @OGUID+124),
(24, @OGUID+125),
(24, @OGUID+126),
(24, @OGUID+127),
(24, @OGUID+128),
(24, @OGUID+129),
(24, @OGUID+130),
(24, @OGUID+131),
(24, @OGUID+132),
(24, @OGUID+133),
(24, @OGUID+134),
(24, @OGUID+135),
(24, @OGUID+136),
(24, @OGUID+137),
(24, @OGUID+138),
(24, @OGUID+139),
(24, @OGUID+140),
(24, @OGUID+141),
(24, @OGUID+142),
(24, @OGUID+143),
(24, @OGUID+144),
(24, @OGUID+145),
(24, @OGUID+146),
(24, @OGUID+147),
(24, @OGUID+148),
(24, @OGUID+149),
(24, @OGUID+150),
(24, @OGUID+151),
(24, @OGUID+152),
(24, @OGUID+153),
(24, @OGUID+154),
(24, @OGUID+155),
(24, @OGUID+156),
(24, @OGUID+157),
(24, @OGUID+158),
(24, @OGUID+159),
(24, @OGUID+160),
(24, @OGUID+161),
(24, @OGUID+162),
(24, @OGUID+163),
(24, @OGUID+164),
(24, @OGUID+165),
(24, @OGUID+166),
(24, @OGUID+167),
(24, @OGUID+168),
(24, @OGUID+169),
(24, @OGUID+170),
(24, @OGUID+171),
(24, @OGUID+172),
(24, @OGUID+173),
(24, @OGUID+174),
(24, @OGUID+175),
(24, @OGUID+176),
(24, @OGUID+177),
(24, @OGUID+178),
(24, @OGUID+179),
(24, @OGUID+180),
(24, @OGUID+181),
(24, @OGUID+182),
(24, @OGUID+183),
(24, @OGUID+184),
(24, @OGUID+185),
(24, @OGUID+186),
(24, @OGUID+187),
(24, @OGUID+188),
(24, @OGUID+189),
(24, @OGUID+190),
(24, @OGUID+191),
(24, @OGUID+192),
(24, @OGUID+193),
(24, @OGUID+194),
(24, @OGUID+195),
(24, @OGUID+196),
(24, @OGUID+197),
(24, @OGUID+198),
(24, @OGUID+199),
(24, @OGUID+200),
(24, @OGUID+201),
(24, @OGUID+202),
(24, @OGUID+203),
(24, @OGUID+204),
(24, @OGUID+205),
(24, @OGUID+206),
(24, @OGUID+207),
(24, @OGUID+208),
(24, @OGUID+209),
(24, @OGUID+210),
(24, @OGUID+211),
(24, @OGUID+212),
(24, @OGUID+213),
(24, @OGUID+214),
(24, @OGUID+215),
(24, @OGUID+216),
(24, @OGUID+217),
(24, @OGUID+218),
(24, @OGUID+219),
(24, @OGUID+220),
(24, @OGUID+221),
(24, @OGUID+222),
(24, @OGUID+223),
(24, @OGUID+224),
(24, @OGUID+225),
(24, @OGUID+226),
(24, @OGUID+227),
(24, @OGUID+228),
(24, @OGUID+229),
(24, @OGUID+230),
(24, @OGUID+231),
(24, @OGUID+232),
(24, @OGUID+233),
(24, @OGUID+234),
(24, @OGUID+235),
(24, @OGUID+236),
(24, @OGUID+237),
(24, @OGUID+238),
(24, @OGUID+239),
(24, @OGUID+240),
(24, @OGUID+241),
(24, @OGUID+242),
(24, @OGUID+243),
(24, @OGUID+244),
(24, @OGUID+245),
(24, @OGUID+246),
(24, @OGUID+247),
(24, @OGUID+248),
(24, @OGUID+249),
(24, @OGUID+250),
(24, @OGUID+251),
(24, @OGUID+252),
(24, @OGUID+253),
(24, @OGUID+254),
(24, @OGUID+255),
(24, @OGUID+256),
(24, @OGUID+257),
(24, @OGUID+258),
(24, @OGUID+259),
(24, @OGUID+260),
(24, @OGUID+261),
(24, @OGUID+262),
(24, @OGUID+263),
(24, @OGUID+264),
(24, @OGUID+265),
(24, @OGUID+266),
(24, @OGUID+267),
(24, @OGUID+268),
(24, @OGUID+269),
(24, @OGUID+270),
(24, @OGUID+271),
(24, @OGUID+272),
(24, @OGUID+273),
(24, @OGUID+274),
(24, @OGUID+275),
(24, @OGUID+276),
(24, @OGUID+277),
(24, @OGUID+278),
(24, @OGUID+279),
(24, @OGUID+280),
(24, @OGUID+281),
(24, @OGUID+282),
(24, @OGUID+283),
(24, @OGUID+284),
(24, @OGUID+285),
(24, @OGUID+286),
(24, @OGUID+287),
(24, @OGUID+288),
(24, @OGUID+289),
(24, @OGUID+290),
(24, @OGUID+291),
(24, @OGUID+292),
(24, @OGUID+293),
(24, @OGUID+294),
(24, @OGUID+295),
(24, @OGUID+296),
(24, @OGUID+297),
(24, @OGUID+298),
(24, @OGUID+299),
(24, @OGUID+300),
(24, @OGUID+301),
(24, @OGUID+302),
(24, @OGUID+303),
(24, @OGUID+304),
(24, @OGUID+305),
(24, @OGUID+306),
(24, @OGUID+307),
(24, @OGUID+308),
(24, @OGUID+309),
(24, @OGUID+310),
(24, @OGUID+311),
(24, @OGUID+312),
(24, @OGUID+313),
(24, @OGUID+314),
(24, @OGUID+315),
(24, @OGUID+316),
(24, @OGUID+317),
(24, @OGUID+318),
(24, @OGUID+319),
(24, @OGUID+320),
(24, @OGUID+321),
(24, @OGUID+322),
(24, @OGUID+323),
(24, @OGUID+324),
(24, @OGUID+325),
(24, @OGUID+326),
(24, @OGUID+327),
(24, @OGUID+328),
(24, @OGUID+329),
(24, @OGUID+330),
(24, @OGUID+331),
(24, @OGUID+332),
(24, @OGUID+333),
(24, @OGUID+334),
(24, @OGUID+335),
(24, @OGUID+336),
(24, @OGUID+337),
(24, @OGUID+338),
(24, @OGUID+339),
(24, @OGUID+340),
(24, @OGUID+341),
(24, @OGUID+342),
(24, @OGUID+343),
(24, @OGUID+344),
(24, @OGUID+345),
(24, @OGUID+346),
(24, @OGUID+347),
(24, @OGUID+348),
(24, @OGUID+349),
(24, @OGUID+350),
(24, @OGUID+351),
(24, @OGUID+352),
(24, @OGUID+353),
(24, @OGUID+354),
(24, @OGUID+355),
(24, @OGUID+356),
(24, @OGUID+357),
(24, @OGUID+358),
(24, @OGUID+359),
(24, @OGUID+360),
(24, @OGUID+361),
(24, @OGUID+362),
(24, @OGUID+363),
(24, @OGUID+364),
(24, @OGUID+365),
(24, @OGUID+366),
(24, @OGUID+367),
(24, @OGUID+368),
(24, @OGUID+369),
(24, @OGUID+370),
(24, @OGUID+371),
(24, @OGUID+372),
(24, @OGUID+373),
(24, @OGUID+374),
(24, @OGUID+375),
(24, @OGUID+376),
(24, @OGUID+377),
(24, @OGUID+378),
(24, @OGUID+379),
(24, @OGUID+380),
(24, @OGUID+381),
(24, @OGUID+382),
(24, @OGUID+383),
(24, @OGUID+384),
(24, @OGUID+385),
(24, @OGUID+386),
(24, @OGUID+387),
(24, @OGUID+388),
(24, @OGUID+389),
(24, @OGUID+390),
(24, @OGUID+391),
(24, @OGUID+392),
(24, @OGUID+393),
(24, @OGUID+394),
(24, @OGUID+395),
(24, @OGUID+396),
(24, @OGUID+397),
(24, @OGUID+398),
(24, @OGUID+399),
(24, @OGUID+400),
(24, @OGUID+401),
(24, @OGUID+402),
(24, @OGUID+403),
(24, @OGUID+404),
(24, @OGUID+405),
(24, @OGUID+406),
(24, @OGUID+407),
(24, @OGUID+408),
(24, @OGUID+409),
(24, @OGUID+410),
(24, @OGUID+411),
(24, @OGUID+412),
(24, @OGUID+413),
(24, @OGUID+414),
(24, @OGUID+415);
