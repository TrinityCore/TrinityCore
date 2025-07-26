SET @CGUID := 208564;
SET @OGUID := 152154;
SET @EVENT := 82;

-- TODO: Creature spawn @CGUID+5 after waypoint_data.point 6 plays emote 66 and recieve the same emote from formation (script)

-- Creature templates
UPDATE `creature_template` SET `unit_flags`=64 WHERE `entry`=39271; -- High Tinker Mekkatorque
UPDATE `creature_template` SET `faction`=35 WHERE `entry`=39273; -- "Doc" Cogspin
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=39275; -- Gnomeregan Medic
UPDATE `creature_template` SET `unit_flags2`=65536 WHERE `entry`=39860; -- Gnomeregan Mechano-Tank
UPDATE `creature_template` SET `faction`=1770, `unit_flags`=0, `unit_flags2`=2048 WHERE `entry`=39264; -- Gnomeregan Mechano-Tank Pilot
UPDATE `creature_template` SET `faction`=35 WHERE `entry`=39910; -- Hinkles Fastblast
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=40478; -- Elgin Clickspring
UPDATE `creature_template` SET `unit_flags2`=65536 WHERE `entry`=39759; -- Tankbuster Cannon
UPDATE `creature_template` SET `unit_flags`=256, `unit_flags2`=0 WHERE `entry`=39820; -- Rocket Launcher
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=39902; -- Gnomeregan Battle Suit
UPDATE `creature_template` SET `unit_flags2`=65536 WHERE `entry`=39819; -- Irradiated Mechano-Tank
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=39841; -- [DND] Boom Bunny
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=40617; -- [DND] Bunny

DELETE FROM `creature_template_addon` WHERE `entry` IN (40617 /*40617 ([DND] Bunny) - Radiation Cloud*/, 39902 /*39902 (Gnomeregan Battle Suit) - Permanent Feign Death*/, 39860 /*39860 (Gnomeregan Mechano-Tank)*/, 39819 /*39819 (Irradiated Mechano-Tank)*/, 39755 /*39755 (Irradiated Infantry) - Ride Vehicle Hardcoded*/, 39275 /*39275 (Gnomeregan Medic)*/, 39264 /*39264 (Gnomeregan Mechano-Tank Pilot) - Ride Vehicle Hardcoded*/, 39252 /*39252 (Gnomeregan Infantry)*/, 39230 /*39230 (Gnomeregan Mechano-Tank Pilot)*/);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(39902, 0, 0, 0, 0, 2, 0, 0, 0, '74490'), -- 39902 (Gnomeregan Battle Suit) - Permanent Feign Death
(39860, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- 39860 (Gnomeregan Mechano-Tank)
(39819, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- 39819 (Irradiated Mechano-Tank)
(39755, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- 39755 (Irradiated Infantry)
(39275, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- 39275 (Gnomeregan Medic)
(39264, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- 39264 (Gnomeregan Mechano-Tank Pilot)
(39252, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- 39252 (Gnomeregan Infantry)
(39230, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- 39230 (Gnomeregan Mechano-Tank Pilot)
(40617, 0, 0, 0, 0, 1, 0, 0, 0, '74532'); -- 40617 ([DND] Bunny) - Radiation Cloud

UPDATE `creature_template_addon` SET `SheathState`=1 WHERE `entry`=40478; -- 40478 (Elgin Clickspring)
UPDATE `creature_template_addon` SET `SheathState`=1 WHERE `entry`=39910; -- 39910 (Hinkles Fastblast)
UPDATE `creature_template_addon` SET `auras`='74463' WHERE `entry`=39841; -- 39841 ([DND] Boom Bunny) - [DND] Boom
UPDATE `creature_template_addon` SET `auras`='74311' WHERE `entry`=39820; -- 39820 (Rocket Launcher) - Fire Rocket
UPDATE `creature_template_addon` SET `auras`='74458' WHERE `entry`=39759; -- 39759 (Tankbuster Cannon) - Power Shield XL-1
UPDATE `creature_template_addon` SET `SheathState`=1 WHERE `entry`=39273; -- 39273 ("Doc" Cogspin)
UPDATE `creature_template_addon` SET `SheathState`=1 WHERE `entry`=39271; -- 39271 (High Tinker Mekkatorque)
UPDATE `creature_template_addon` SET `AnimTier`=3, `SheathState`=1 WHERE `entry`=39259; -- 39259 (Gnomeregan Flying Machine)

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (40617, 39841, 39759, 39820, 39259);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(39841, 0, 0, 1, 0, 0, 0, NULL),
(39259, 0, 0, 1, 0, 0, 0, NULL),
(39759, 0, 0, 1, 1, 0, 0, NULL),
(39820, 0, 0, 1, 1, 0, 0, NULL),
(40617, 0, 0, 1, 1, 0, 0, NULL);

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=39755 AND `ID`=2);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES
(39755, 2, 53055, 0, 30128, 54261); -- Irradiated Infantry

UPDATE `creature_equip_template` SET `VerifiedBuild`=54261 WHERE (`ID`=1 AND `CreatureID` IN (40478,39910,39755,39273,39271,39264,39252,39230));

UPDATE `creature_template` SET `gossip_menu_id`=11194 WHERE `entry`=39271; -- High Tinker Mekkatorque
DELETE FROM `gossip_menu_option` WHERE (`MenuID` IN (11191,11194) AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(11194, 0, 0, 'What is going on here?', 39332, 1, 1, 11191, 0, 0, 0, NULL, 0, 54261),
(11191, 0, 0, 'What is your plan?', 39323, 1, 1, 11192, 0, 0, 0, NULL, 0, 54261);

DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (39819,39759,39860);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(39819, 39755, 0, 1, 'Irradiated Mechano-Tank - Irradiated Infantry', 7, 0), -- Irradiated Mechano-Tank - Irradiated Infantry
(39759, 39755, 0, 1, 'Tankbuster Cannon - Irradiated Infantry', 7, 0), -- Tankbuster Cannon - Irradiated Infantry
(39860, 39264, 0, 1, 'Gnomeregan Mechano-Tank - Gnomeregan Mechano-Tank Pilot', 7, 0); -- Gnomeregan Mechano-Tank - Gnomeregan Mechano-Tank Pilot

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (39819, 39759, 39860);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(39819, 46598, 1, 0),
(39759, 43671, 1, 0),
(39860, 46598, 1, 0);

-- Gameobject templates
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=202922; -- Irradiator 3000

-- Misc
DELETE FROM `spell_area` WHERE `spell`=74310;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(74310, 133, 25287, 25393, 0, 0, 2, 1, 74, 11),
(74310, 135, 25287, 25393, 0, 0, 2, 1, 74, 11),
(74310, 137, 25287, 25393, 0, 0, 2, 1, 74, 11),
(74310, 211, 25287, 25393, 0, 0, 2, 1, 74, 11);

-- SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (39230);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (39230) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39230,0,0,0,1,0,100,0,0,5000,8000,13000,0,10,6,273,274,396,0,0,1,0,0,0,0,0,0,0,0,'Gnomeregan Mechano-Tank Pilot - Out of combat (8-13s) - Play random emote');

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+130;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `VerifiedBuild`) VALUES
-- Frostmane Hold
(@CGUID+0, 39230, 0, 1, 135, 1, 256, 0, 1, -5429.52978515625, 533.54864501953125, 386.946197509765625, 1.797689080238342285, 120, 0, 0, 12600, 0, 0, 54261), -- Gnomeregan Mechano-Tank Pilot (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+1, 39230, 0, 1, 135, 1, 256, 0, 1, -5431.6025390625, 534.31597900390625, 386.98785400390625, 0.645771801471710205, 120, 0, 0, 12600, 0, 0, 54261), -- Gnomeregan Mechano-Tank Pilot (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+2, 39230, 0, 1, 135, 1, 256, 0, 1, -5429.626953125, 540.41668701171875, 386.821319580078125, 2.617993831634521484, 120, 0, 0, 12600, 0, 0, 54261), -- Gnomeregan Mechano-Tank Pilot (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+3, 39230, 0, 1, 135, 1, 256, 0, 1, -5431.0712890625, 541.15277099609375, 386.8350830078125, 5.951572895050048828, 120, 0, 0, 12600, 0, 0, 54261), -- Gnomeregan Mechano-Tank Pilot (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+4, 39230, 0, 1, 135, 1, 256, 0, 1, -5431.4912109375, 536.857666015625, 386.91973876953125, 5.567600250244140625, 120, 0, 0, 12600, 0, 0, 54261), -- Gnomeregan Mechano-Tank Pilot (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+5, 39252, 0, 1, 135, 1, 256, 0, 1, -5401.2603, 488.00522, 385.00113, 2.328075647354125976, 120, 0, 0, 315000, 0, 2, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+6, 39252, 0, 1, 135, 1, 256, 0, 1, -5404.40478515625, 485.171875, 384.94677734375, 0.837758064270019531, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+7, 39252, 0, 1, 135, 1, 256, 0, 1, -5404.57666015625, 488.588531494140625, 385.421875, 0.837758064270019531, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+8, 39252, 0, 1, 135, 1, 256, 0, 1, -5410.35791015625, 490.57464599609375, 386.207000732421875, 0.837758064270019531, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+9, 39252, 0, 1, 135, 1, 256, 0, 1, -5406.28466796875, 486.82464599609375, 385.328125, 0.837758064270019531, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+10, 39252, 0, 1, 135, 1, 256, 0, 1, -5406.48974609375, 490.505218505859375, 385.911956787109375, 0.837758064270019531, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+11, 39252, 0, 1, 135, 1, 256, 0, 1, -5402.60400390625, 486.734375, 384.986480712890625, 0.837758064270019531, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+12, 39252, 0, 1, 135, 1, 256, 0, 1, -5410.63720703125, 494.505218505859375, 386.5621337890625, 0.837758064270019531, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+13, 39252, 0, 1, 135, 1, 256, 0, 1, -5408.22216796875, 488.78125, 385.824005126953125, 0.837758064270019531, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+14, 39252, 0, 1, 135, 1, 256, 0, 1, -5408.53125, 492.369781494140625, 386.335357666015625, 0.837758064270019531, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+15, 39252, 0, 1, 135, 1, 256, 0, 1, -5410.34912109375, 486.720489501953125, 385.601318359375, 0.837758064270019531, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+16, 39252, 0, 1, 135, 1, 256, 0, 1, -5414.53662109375, 490.789947509765625, 386.328216552734375, 0.837758064270019531, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+17, 39252, 0, 1, 135, 1, 256, 0, 1, -5408.47216796875, 484.822906494140625, 385.164947509765625, 0.837758064270019531, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+18, 39252, 0, 1, 135, 1, 256, 0, 1, -5410.26025390625, 482.86285400390625, 384.8768310546875, 0.837758064270019531, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+19, 39252, 0, 1, 135, 1, 256, 0, 1, -5416.080078125, 488.798614501953125, 386.078857421875, 0.837758064270019531, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+20, 39252, 0, 1, 135, 1, 256, 0, 1, -5412.39599609375, 492.736114501953125, 386.483734130859375, 0.837758064270019531, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+21, 39252, 0, 1, 135, 1, 256, 0, 1, -5406.57275390625, 483.036468505859375, 384.77777099609375, 0.837758064270019531, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+22, 39252, 0, 1, 135, 1, 256, 0, 1, -5412.40966796875, 488.711822509765625, 386.022216796875, 0.837758064270019531, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+23, 39252, 0, 1, 135, 1, 256, 0, 1, -5414.14404296875, 486.932281494140625, 385.7724609375, 0.837758064270019531, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+24, 39252, 0, 1, 135, 1, 256, 0, 1, -5412.16162109375, 484.888885498046875, 385.323486328125, 0.837758064270019531, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+25, 39252, 0, 1, 135, 1, 256, 0, 1, -5408.45654296875, 481.28125, 384.630615234375, 0.837758064270019531, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+26, 39252, 0, 1, 135, 1, 256, 0, 1, -5393.02099609375, 518.60589599609375, 386.25390625, 0.575958669185638427, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+27, 39252, 0, 1, 135, 1, 256, 0, 1, -5396.3037109375, 523.63714599609375, 387.024322509765625, 0.401425719261169433, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+28, 39252, 0, 1, 135, 1, 256, 0, 1, -5398.64599609375, 533.1961669921875, 387.230560302734375, 0.453785598278045654, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+29, 39252, 0, 1, 135, 1, 256, 0, 1, -5401.89599609375, 547.248291015625, 387.5538330078125, 0.244346097111701965, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+30, 39252, 0, 1, 135, 1, 256, 0, 1, -5402.88525390625, 550.53643798828125, 387.97918701171875, 0.122173048555850982, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+31, 39252, 0, 1, 135, 1, 256, 0, 1, -5448.28662109375, 497.37152099609375, 385.70635986328125, 3.577924966812133789, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+32, 39252, 0, 1, 135, 1, 256, 0, 1, -5420.8505859375, 460.447906494140625, 385.935302734375, 3.59537816047668457, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+33, 39252, 0, 1, 135, 1, 256, 0, 1, -5453.84912109375, 514.36114501953125, 387.285919189453125, 3.839724302291870117, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+34, 39252, 0, 1, 135, 1, 256, 0, 1, -5441.25341796875, 481.0538330078125, 384.850341796875, 3.59537816047668457, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+35, 39252, 0, 1, 135, 1, 256, 0, 1, -5418.44091796875, 458.017364501953125, 386.95867919921875, 3.804817676544189453, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Infantry (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+36, 39259, 0, 1, 135, 1, 256, 0, 0, -5399.173828125, 534.484375, 394.620513916015625, 0.401425719261169433, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Flying Machine (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+37, 39259, 0, 1, 135, 1, 256, 0, 0, -5396.1181640625, 519.88714599609375, 394.06854248046875, 0.523598790168762207, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Flying Machine (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+38, 39259, 0, 1, 135, 1, 256, 0, 0, -5401.6025390625, 549.52606201171875, 395.183990478515625, 0.209439516067504882, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Flying Machine (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+39, 39259, 0, 1, 135, 1, 256, 0, 0, -5402.9375, 497.423614501953125, 392.82000732421875, 0.959931075572967529, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Flying Machine (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+40, 39259, 0, 1, 135, 1, 256, 0, 0, -5398.7099609375, 467.0382080078125, 391.05047607421875, 5.654866695404052734, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Flying Machine (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+41, 39259, 0, 1, 135, 1, 256, 0, 0, -5445.0537109375, 525.6875, 393.753662109375, 2.827433347702026367, 120, 0, 0, 315000, 0, 0, 54261), -- Gnomeregan Flying Machine (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+42, 39271, 0, 1, 135, 1, 256, 0, 1, -5424.76904296875, 528.06427001953125, 387.052642822265625, 5.288347721099853515, 120, 0, 0, 5578000, 0, 0, 54261), -- High Tinker Mekkatorque (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+43, 39273, 0, 1, 135, 1, 256, 0, 1, -5425.88916015625, 532.36285400390625, 387.012176513671875, 5.25344085693359375, 120, 0, 0, 630000, 0, 0, 54261), -- "Doc" Cogspin (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+44, 39275, 0, 1, 135, 1, 256, 0, 0, -5413.79541015625, 496.3507080078125, 386.696533203125, 5.183627605438232421, 120, 0, 0, 10635, 0, 0, 54261), -- Gnomeregan Medic (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+45, 39860, 0, 1, 135, 1, 256, 0, 0, -5402.34912109375, 519.94964599609375, 386.850830078125, 0.366519153118133544, 120, 0, 0, 1008000, 0, 0, 54261), -- Gnomeregan Mechano-Tank (Area: Frostmane Hold - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+46, 39860, 0, 1, 135, 1, 256, 0, 0, -5404.876953125, 534.078125, 387.093994140625, 0.296705961227416992, 120, 0, 0, 1008000, 0, 0, 54261), -- Gnomeregan Mechano-Tank (Area: Frostmane Hold - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+47, 39860, 0, 1, 135, 1, 256, 0, 0, -5407.6806640625, 546.092041015625, 387.715301513671875, 0.436332315206527709, 120, 0, 0, 1008000, 0, 0, 54261), -- Gnomeregan Mechano-Tank (Area: Frostmane Hold - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+48, 39860, 0, 1, 135, 1, 256, 0, 0, -5389.7412109375, 466.774322509765625, 384.623931884765625, 5.811946392059326171, 120, 0, 0, 1008000, 0, 0, 54261), -- Gnomeregan Mechano-Tank (Area: Frostmane Hold - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+49, 39860, 0, 1, 135, 1, 256, 0, 0, -5434.38720703125, 496.670135498046875, 385.328125, 4.084070205688476562, 120, 0, 0, 1008000, 0, 0, 54261), -- Gnomeregan Mechano-Tank (Area: Frostmane Hold - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+50, 39910, 0, 1, 135, 1, 256, 0, 1, -5429.142578125, 529.6475830078125, 387.16668701171875, 5.340707302093505859, 120, 0, 0, 630000, 0, 0, 54261), -- Hinkles Fastblast (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@CGUID+51, 40478, 0, 1, 135, 1, 256, 0, 1, -5423.81103515625, 537.6475830078125, 386.641998291015625, 4.258603572845458984, 120, 0, 0, 12600, 0, 0, 54261), -- Elgin Clickspring (Area: Frostmane Hold - Difficulty: 0) CreateObject1
-- New Tinkertown
(@CGUID+52, 23837, 0, 1, 133, 1, 256, 0, 0, -5359.27978515625, 540.08160400390625, 386.854766845703125, 0, 120, 0, 0, 42, 0, 0, 54261), -- ELM General Purpose Bunny (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 52855 - Cosmetic - Low Poly Fire (with Sound))
(@CGUID+53, 23837, 0, 1, 133, 1, 256, 0, 0, -5363.17041015625, 544.0069580078125, 387.032196044921875, 0, 120, 0, 0, 42, 0, 0, 54261), -- ELM General Purpose Bunny (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 52855 - Cosmetic - Low Poly Fire (with Sound))
(@CGUID+54, 39755, 0, 1, 133, 1, 256, 0, 1, -5348.0537109375, 540.51910400390625, 385.17822265625, 3.787364482879638671, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+55, 39755, 0, 1, 133, 1, 256, 0, 1, -5358.97900390625, 561.123291015625, 386.962799072265625, 3.735004663467407226, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+56, 39755, 0, 1, 133, 1, 256, 0, 1, -5356.1962890625, 556.7430419921875, 386.569091796875, 3.735004663467407226, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+57, 39755, 0, 1, 133, 1, 256, 0, 1, -5343.94287109375, 534.57989501953125, 384.838775634765625, 3.59537816047668457, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+58, 39755, 0, 1, 133, 1, 256, 0, 1, -5289.72216796875, 553.51739501953125, 383.84368896484375, 3.03687286376953125, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+59, 39755, 0, 1, 133, 1, 256, 0, 1, -5348.5380859375, 574.953125, 387.094207763671875, 0.087266460061073303, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+60, 39755, 0, 1, 133, 1, 256, 0, 1, -5300.033203125, 534.72052001953125, 385.281585693359375, 5.550147056579589843, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+61, 39755, 0, 1, 133, 1, 256, 0, 1, -5323.12353515625, 586.9930419921875, 389.009521484375, 5.288347721099853515, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+62, 39755, 0, 1, 133, 1, 256, 0, 1, -5352.486328125, 575.451416015625, 387.155853271484375, 3.50811171531677246, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+63, 39755, 0, 1, 133, 1, 256, 0, 1, -5344.283203125, 555.65802001953125, 384.487762451171875, 3.438298702239990234, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+64, 39755, 0, 1, 133, 1, 256, 0, 1, -5333.4130859375, 545.32293701171875, 385.25537109375, 3.159045934677124023, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+65, 39755, 0, 1, 133, 1, 256, 0, 1, -5287.76220703125, 541.69793701171875, 384.072845458984375, 5.567600250244140625, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+66, 39755, 0, 1, 133, 1, 256, 0, 1, -5306.359375, 523.84552001953125, 385.169189453125, 5.427973747253417968, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+67, 39755, 0, 1, 133, 1, 256, 0, 1, -5337.45166015625, 560.05902099609375, 395.717315673828125, 3.420845270156860351, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+68, 39755, 0, 1, 133, 1, 256, 0, 1, -5324.98779296875, 590.28472900390625, 389.05645751953125, 2.0245819091796875, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+69, 39755, 0, 1, 133, 1, 256, 0, 1, -5329.98974609375, 546.0711669921875, 385.19366455078125, 0.733038306236267089, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+70, 39755, 0, 1, 133, 1, 256, 0, 1, -5339.18408203125, 563.73614501953125, 395.96392822265625, 3.717551231384277343, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+71, 39755, 0, 1, 133, 1, 256, 0, 1, -5296.43212890625, 570.9913330078125, 386.973114013671875, 3.769911050796508789, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+72, 39755, 0, 1, 133, 1, 256, 0, 1, -5310.0224609375, 585.22052001953125, 389.62396240234375, 3.368485450744628906, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+73, 39755, 0, 1, 133, 1, 256, 0, 1, -5270.91650390625, 566.701416015625, 386.6964111328125, 3.141592741012573242, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+74, 39755, 0, 1, 133, 1, 256, 0, 1, -5274.78662109375, 550.732666015625, 386.570831298828125, 5.864306449890136718, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+75, 39755, 0, 1, 133, 1, 256, 0, 1, -5293.1025390625, 573.03302001953125, 386.90826416015625, 0.680678427219390869, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+76, 39755, 0, 1, 133, 1, 256, 0, 1, -5295.720703125, 600.4757080078125, 389.19757080078125, 2.530727386474609375, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+77, 39755, 0, 1, 133, 1, 256, 0, 1, -5185.734375, 575.54339599609375, 401.383087158203125, 4.747295379638671875, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+78, 39755, 0, 1, 133, 1, 256, 0, 1, -5192.05029296875, 572.5867919921875, 400.321258544921875, 4.747295379638671875, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+79, 39755, 0, 1, 133, 1, 256, 0, 1, -5193.22216796875, 586.21875, 405.40301513671875, 4.747295379638671875, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+80, 39755, 0, 1, 133, 1, 256, 0, 1, -5191.48974609375, 598.1336669921875, 408.924407958984375, 4.747295379638671875, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+81, 39755, 0, 1, 133, 1, 256, 0, 1, -5177.43603515625, 587.62677001953125, 405.4580078125, 4.747295379638671875, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+82, 39755, 0, 1, 133, 1, 256, 0, 1, -5178.9375, 572.71875, 399.95343017578125, 4.747295379638671875, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+83, 39755, 0, 1, 133, 1, 256, 0, 1, -5161.2880859375, 585.5625, 408.72576904296875, 3.420845270156860351, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+84, 39755, 0, 1, 133, 1, 256, 0, 1, -5176.828125, 598.717041015625, 408.84521484375, 4.747295379638671875, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+85, 39755, 0, 1, 133, 1, 256, 0, 1, -5119.81103515625, 468.4288330078125, 397.38916015625, 3.089232683181762695, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+86, 39755, 0, 1, 133, 1, 256, 0, 1, -5153.72412109375, 458.984375, 392.002197265625, 1.989675283432006835, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+87, 39755, 0, 1, 133, 1, 256, 0, 1, -5136.19091796875, 462.029510498046875, 393.539306640625, 3.141592741012573242, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+88, 39755, 0, 1, 133, 1, 256, 0, 1, -5091.3037109375, 465.352447509765625, 404.57794189453125, 3.141592741012573242, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+89, 39755, 0, 1, 133, 1, 256, 0, 1, -5087.20849609375, 480.064239501953125, 401.89154052734375, 4.049163818359375, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+90, 39755, 0, 1, 133, 1, 256, 0, 1, -5121.90625, 445.927093505859375, 396.843292236328125, 3.141592741012573242, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+91, 39755, 0, 1, 133, 1, 256, 0, 1, -5105.0068359375, 452.888885498046875, 401.898193359375, 3.141592741012573242, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+92, 39755, 0, 1, 133, 1, 256, 0, 1, -5081.77587890625, 475.982635498046875, 402.063934326171875, 3.909537553787231445, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+93, 39755, 0, 1, 133, 1, 256, 0, 1, -5130.9306640625, 432.317718505859375, 396.533203125, 1.675516128540039062, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+94, 39755, 0, 1, 133, 1, 256, 0, 1, -5090.65966796875, 488.920135498046875, 404.43701171875, 3.926990747451782226, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+95, 39755, 0, 1, 133, 1, 256, 0, 1, -5121.595703125, 456.645843505859375, 397.4964599609375, 3.490658521652221679, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+96, 39755, 0, 1, 133, 1, 256, 0, 1, -5103.5849609375, 422.873260498046875, 403.033447265625, 3.089232683181762695, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+97, 39755, 0, 1, 133, 1, 256, 0, 1, -5086.126953125, 447.140625, 409.984375, 2.059488534927368164, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+98, 39755, 0, 1, 133, 1, 256, 0, 1, -5078.2568359375, 463.953125, 406.89276123046875, 3.141592741012573242, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+99, 39755, 0, 1, 133, 1, 256, 0, 1, -5082.2431640625, 452.94097900390625, 409.813751220703125, 2.792526721954345703, 120, 0, 0, 189000, 0, 0, 54261), -- Irradiated Infantry (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+100, 39759, 0, 1, 133, 1, 256, 0, 0, -5147.05908203125, 436.289947509765625, 395.835784912109375, 1.972222089767456054, 120, 0, 0, 756000, 0, 0, 54261), -- Tankbuster Cannon (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+101, 39759, 0, 1, 133, 1, 256, 0, 0, -5112.57666015625, 426.373260498046875, 398.37225341796875, 2.408554315567016601, 120, 0, 0, 756000, 0, 0, 54261), -- Tankbuster Cannon (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 74458 - Power Shield XL-1)
(@CGUID+102, 39759, 0, 1, 133, 1, 256, 0, 0, -5108.5556640625, 478.145843505859375, 398.51495361328125, 3.996803998947143554, 120, 0, 0, 756000, 0, 0, 54261), -- Tankbuster Cannon (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+103, 39759, 0, 1, 133, 1, 256, 0, 0, -5097.0712890625, 454.213531494140625, 404.49664306640625, 3.089232683181762695, 120, 0, 0, 756000, 0, 0, 54261), -- Tankbuster Cannon (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+104, 39759, 0, 1, 133, 1, 256, 0, 0, -5087.56103515625, 432.217010498046875, 412.7264404296875, 2.775073528289794921, 120, 0, 0, 756000, 0, 0, 54261), -- Tankbuster Cannon (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 74458 - Power Shield XL-1)
(@CGUID+105, 39759, 0, 1, 133, 1, 256, 0, 0, -5074.6943359375, 460.59375, 409.74652099609375, 3.019419670104980468, 120, 0, 0, 756000, 0, 0, 54261), -- Tankbuster Cannon (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 74458 - Power Shield XL-1)
(@CGUID+106, 39819, 0, 1, 133, 1, 256, 0, 0, -5340.0747, 544.31946, 385.06015, 2.130715847015380859, 120, 0, 0, 1008000, 0, 2, 54261), -- Irradiated Mechano-Tank (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+107, 39819, 0, 1, 133, 1, 256, 0, 0, -5332.44970703125, 537.62152099609375, 385.172760009765625, 3.752457857131958007, 120, 0, 0, 1008000, 0, 0, 54261), -- Irradiated Mechano-Tank (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+108, 39819, 0, 1, 133, 1, 256, 0, 0, -5317.33837890625, 575.279541015625, 387.68310546875, 3.59537816047668457, 120, 0, 0, 1008000, 0, 0, 54261), -- Irradiated Mechano-Tank (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+109, 39819, 0, 1, 133, 1, 256, 0, 0, -5290.21728515625, 581.435791015625, 387.529052734375, 3.839724302291870117, 120, 0, 0, 1008000, 0, 0, 54261), -- Irradiated Mechano-Tank (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+110, 39819, 0, 1, 133, 1, 256, 0, 0, -5261.078125, 556.92706298828125, 387.381805419921875, 2.722713708877563476, 120, 0, 0, 1008000, 0, 0, 54261), -- Irradiated Mechano-Tank (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+111, 39819, 0, 1, 133, 1, 256, 0, 0, -5121.222, 417.56424, 396.6584, 4.833743095397949218, 120, 0, 0, 1008000, 0, 2, 54261), -- Irradiated Mechano-Tank (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+112, 39819, 0, 1, 133, 1, 256, 0, 0, -5116.6787, 453.06946, 398.87387, 0, 120, 0, 0, 1008000, 0, 2, 54261), -- Irradiated Mechano-Tank (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+113, 39819, 0, 1, 133, 1, 256, 0, 0, -5069.2255859375, 471.3125, 403.606353759765625, 0.231994718313217163, 120, 0, 0, 1008000, 0, 2, 54261), -- Irradiated Mechano-Tank (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+114, 39820, 0, 1, 133, 1, 256, 0, 0, -5294.63037109375, 571.828125, 386.8916015625, 5.323254108428955078, 120, 0, 0, 756000, 0, 0, 54261), -- Rocket Launcher (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 74311 - Fire Rocket)
(@CGUID+115, 39820, 0, 1, 133, 1, 256, 0, 0, -5350.45654296875, 575.029541015625, 387.189697265625, 4.694935798645019531, 120, 0, 0, 756000, 0, 0, 54261), -- Rocket Launcher (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 74311 - Fire Rocket)
(@CGUID+116, 39820, 0, 1, 133, 1, 256, 0, 0, -5324.21875, 588.55206298828125, 388.98089599609375, 3.682644605636596679, 120, 0, 0, 756000, 0, 0, 54261), -- Rocket Launcher (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 74311 - Fire Rocket)
(@CGUID+117, 39820, 0, 1, 133, 1, 256, 0, 0, -5331.4619140625, 544.87677001953125, 385.160614013671875, 4.991641521453857421, 120, 0, 0, 756000, 0, 0, 54261), -- Rocket Launcher (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 74311 - Fire Rocket)
(@CGUID+118, 39841, 0, 1, 133, 1, 256, 0, 0, -5335.8145, 545.21875, 403.1348, 0, 120, 0, 0, 26946, 0, 2, 54261), -- [DND] Boom Bunny (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 74463 - [DND] Boom) (possible waypoints or random movement)
(@CGUID+119, 39841, 0, 1, 133, 1, 256, 0, 0, -5295.0903, 574.07117, 404.9674, 0, 120, 0, 0, 26946, 0, 2, 54261), -- [DND] Boom Bunny (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 74463 - [DND] Boom) (possible waypoints or random movement)
(@CGUID+120, 39902, 0, 1, 133, 1, 256, 0, 0, -5074.22216796875, 481.795135498046875, 401.56805419921875, 4.502949237823486328, 120, 0, 0, 567000, 0, 0, 54261), -- Gnomeregan Battle Suit (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 74490 - Permanent Feign Death)
(@CGUID+121, 39902, 0, 1, 133, 1, 256, 0, 0, -5065.5068359375, 484.805572509765625, 401.56805419921875, 5.759586334228515625, 120, 0, 0, 567000, 0, 0, 54261), -- Gnomeregan Battle Suit (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 74490 - Permanent Feign Death)
(@CGUID+122, 39902, 0, 1, 133, 1, 256, 0, 0, -5069.8525390625, 481.984375, 401.67535400390625, 4.904375076293945312, 120, 0, 0, 567000, 0, 0, 54261), -- Gnomeregan Battle Suit (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 74490 - Permanent Feign Death)
(@CGUID+123, 40617, 0, 1, 133, 1, 256, 0, 0, -5182.75, 610.76043701171875, 409.047119140625, 4.607669353485107421, 120, 0, 0, 42, 0, 0, 54261), -- [DND] Bunny (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 74532 - Radiation Cloud)
(@CGUID+124, 40617, 0, 1, 133, 1, 256, 0, 0, -5181.376953125, 631.123291015625, 398.629638671875, 4.607669353485107421, 120, 0, 0, 42, 0, 0, 54261), -- [DND] Bunny (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 74532 - Radiation Cloud)
(@CGUID+125, 40617, 0, 1, 133, 1, 256, 0, 0, -5179.76416015625, 652.93231201171875, 389.968414306640625, 4.607669353485107421, 120, 0, 0, 42, 0, 0, 54261), -- [DND] Bunny (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 74532 - Radiation Cloud)
(@CGUID+126, 40617, 0, 1, 133, 1, 256, 0, 0, -5178.625, 668.34027099609375, 384.878265380859375, 4.607669353485107421, 120, 0, 0, 42, 0, 0, 54261), -- [DND] Bunny (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 74532 - Radiation Cloud)
(@CGUID+127, 40617, 0, 1, 133, 1, 256, 0, 0, -5162.89404296875, 670.34722900390625, 351.3189697265625, 4.607669353485107421, 120, 0, 0, 42, 0, 0, 54261), -- [DND] Bunny (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 74532 - Radiation Cloud)
(@CGUID+128, 40617, 0, 1, 133, 1, 256, 0, 0, -5177.3349609375, 690.43231201171875, 376.7799072265625, 4.607669353485107421, 120, 0, 0, 42, 0, 0, 54261), -- [DND] Bunny (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 74532 - Radiation Cloud)
(@CGUID+129, 40617, 0, 1, 133, 1, 256, 0, 0, -5159.84228515625, 700.420166015625, 367.409454345703125, 4.607669353485107421, 120, 0, 0, 42, 0, 0, 54261), -- [DND] Bunny (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 74532 - Radiation Cloud)
(@CGUID+130, 40617, 0, 1, 133, 1, 256, 0, 0, -5166.65966796875, 715.31427001953125, 369.1473388671875, 4.607669353485107421, 120, 0, 0, 42, 0, 0, 54261); -- [DND] Bunny (Area: New Tinkertown - Difficulty: 0) CreateObject1 (Auras: 74532 - Radiation Cloud)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+130;
INSERT INTO `creature_addon` (`guid`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+5, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Gnomeregan Infantry
(@CGUID+6, 0, 0, 0, 0, 1, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+7, 0, 0, 0, 0, 1, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+8, 0, 0, 0, 0, 1, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+9, 0, 0, 0, 0, 1, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+10, 0, 0, 0, 0, 1, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+11, 0, 0, 0, 0, 1, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+12, 0, 0, 0, 0, 1, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+13, 0, 0, 0, 0, 1, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+14, 0, 0, 0, 0, 1, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+15, 0, 0, 0, 0, 1, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+16, 0, 0, 0, 0, 1, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+17, 0, 0, 0, 0, 1, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+18, 0, 0, 0, 0, 1, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+19, 0, 0, 0, 0, 1, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+20, 0, 0, 0, 0, 1, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+21, 0, 0, 0, 0, 1, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+22, 0, 0, 0, 0, 1, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+23, 0, 0, 0, 0, 1, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+24, 0, 0, 0, 0, 1, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+25, 0, 0, 0, 0, 1, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+26, 0, 0, 0, 0, 2, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+27, 0, 0, 0, 0, 2, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+28, 0, 0, 0, 0, 2, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+29, 0, 0, 0, 0, 2, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+30, 0, 0, 0, 0, 2, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+31, 0, 0, 0, 0, 2, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+32, 0, 0, 0, 0, 2, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+33, 0, 0, 0, 0, 2, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+34, 0, 0, 0, 0, 2, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+35, 0, 0, 0, 0, 2, 0, 214, 0, ''), -- Gnomeregan Infantry
(@CGUID+52, 0, 0, 0, 0, 1, 0, 0, 0, '52855'), -- ELM General Purpose Bunny - 52855 - Cosmetic - Low Poly Fire (with Sound)
(@CGUID+53, 0, 0, 0, 0, 1, 0, 0, 0, '52855'), -- ELM General Purpose Bunny - 52855 - Cosmetic - Low Poly Fire (with Sound)
(@CGUID+54, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+55, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+56, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+57, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+58, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+59, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+60, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+61, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+62, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+63, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+64, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+65, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+66, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+67, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+68, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+69, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+70, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+71, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+72, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+73, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+74, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+75, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+76, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+77, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+78, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+79, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+80, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+81, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+82, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+83, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+84, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+85, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+86, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+87, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+88, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+89, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+90, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+91, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+92, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+93, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+94, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+95, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+96, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+97, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+98, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+99, 0, 0, 0, 0, 1, 0, 333, 0, ''), -- Irradiated Infantry
(@CGUID+106, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- Irradiated Mechano-Tank
(@CGUID+111, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- Irradiated Mechano-Tank
(@CGUID+112, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- Irradiated Mechano-Tank
(@CGUID+113, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- Irradiated Mechano-Tank
(@CGUID+118, 0, 0, 0, 0, 0, 0, 0, 3, '74463'), -- [DND] Boom Bunny
(@CGUID+119, 0, 0, 0, 0, 0, 0, 0, 3, '74463'); -- [DND] Boom Bunny

DELETE FROM `creature_movement_override` WHERE `SpawnId` BETWEEN @CGUID+0 AND @CGUID+130;
INSERT INTO `creature_movement_override` (`SpawnId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(@CGUID+6, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+7, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+8, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+9, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+10, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+11, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+12, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+13, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+14, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+15, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+16, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+17, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+18, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+19, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+20, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+21, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+22, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+23, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+24, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+25, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+26, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+27, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+28, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+29, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+30, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+31, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+32, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+33, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+34, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+35, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+36, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+37, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+38, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+45, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+46, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+47, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+57, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+59, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+61, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+62, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+63, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+64, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+68, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+69, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+71, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+72, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+73, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+75, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+77, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+78, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+82, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+90, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+92, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+94, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+95, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+97, 0, 0, 1, 1, 0, 0, NULL),
(@CGUID+99, 0, 0, 1, 1, 0, 0, NULL);

SET @ENTRY := 39252;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
UPDATE `creature_addon` SET `path_id`=@PATH WHERE `guid`=@CGUID+5;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -5409.3057, 495.4896, 386.48718, NULL, 3500, 0, 0, 100, 0),
(@PATH, 2, -5401.408, 487.97397, 384.9283, NULL, 3500, 0, 0, 100, 0),
(@PATH, 3, -5409.6875, 495.4861, 386.49844, NULL, 3500, 0, 0, 100, 0),
(@PATH, 4, -5405.3315, 491.64758, 385.8566, NULL, 1000, 0, 0, 100, 0),
(@PATH, 5, -5405.3315, 491.64758, 385.8566, 4.014257431030273437, 6500, 0, 0, 100, 0),
(@PATH, 6, -5401.222, 488.08508, 384.92426, NULL, 6000, 0, 0, 100, 0);

SET @ENTRY := 39819;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
UPDATE `creature_addon` SET `path_id`=@PATH WHERE `guid`=@CGUID+106;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -5355.243, 571.51215, 386.53516, NULL, 1500, 0, 0, 100, 0),
(@PATH, 2, -5343.557, 549.875, 384.94324, NULL, 1500, 0, 0, 100, 0);

SET @ENTRY := 39819;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
UPDATE `creature_addon` SET `path_id`=@PATH WHERE `guid`=@CGUID+111;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -5122.5903, 428.783, 396.64246, NULL, 0, 0, 0, 100, 0),
(@PATH, 2, -5124.2173, 436.50696, 396.5359, NULL, 0, 0, 0, 100, 0),
(@PATH, 3, -5126.3267, 442.71008, 396.0109, NULL, 1000, 0, 0, 100, 0),
(@PATH, 4, -5124.2173, 436.50696, 396.5359, NULL, 0, 0, 0, 100, 0),
(@PATH, 5, -5122.5903, 428.783, 396.64246, NULL, 0, 0, 0, 100, 0),
(@PATH, 6, -5121.222, 417.56424, 396.6584, NULL, 1000, 0, 0, 100, 0);

SET @ENTRY := 39819;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
UPDATE `creature_addon` SET `path_id`=@PATH WHERE `guid`=@CGUID+112;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -5116.6787, 453.06946, 398.87387, NULL, 0, 0, 0, 100, 0),
(@PATH, 2, -5107.7446, 457.31076, 401.8087, NULL, 0, 0, 0, 100, 0),
(@PATH, 3, -5097.547, 464.60764, 403.94888, NULL, 0, 0, 0, 100, 0),
(@PATH, 4, -5089.733, 473.17883, 402.79395, NULL, 1000, 0, 0, 100, 0),
(@PATH, 5, -5097.547, 464.60764, 403.94888, NULL, 0, 0, 0, 100, 0),
(@PATH, 6, -5107.7446, 457.31076, 401.8087, NULL, 0, 0, 0, 100, 0),
(@PATH, 7, -5116.6787, 453.06946, 398.87387, NULL, 0, 0, 0, 100, 0),
(@PATH, 8, -5123.259, 451.46527, 396.66833, NULL, 1000, 0, 0, 100, 0);

SET @ENTRY := 39819;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
UPDATE `creature_addon` SET `path_id`=@PATH WHERE `guid`=@CGUID+113;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -5069.2256, 471.3125, 403.60635, NULL, 0, 0, 0, 100, 0),
(@PATH, 2, -5079.887, 468.8021, 403.3521, NULL, 0, 0, 0, 100, 0),
(@PATH, 3, -5087.047, 465.6111, 404.56604, NULL, 0, 0, 0, 100, 0),
(@PATH, 4, -5088.943, 459.21527, 406.15045, NULL, 0, 0, 0, 100, 0),
(@PATH, 5, -5087.1523, 452.44727, 408.4521, NULL, 1000, 0, 0, 100, 0),
(@PATH, 6, -5088.9434, 459.21484, 406.20013, NULL, 0, 0, 0, 100, 0),
(@PATH, 7, -5087.047, 465.6111, 404.56604, NULL, 0, 0, 0, 100, 0),
(@PATH, 8, -5079.887, 468.8021, 403.3521, NULL, 0, 0, 0, 100, 0),
(@PATH, 9, -5069.2256, 471.3125, 403.60635, NULL, 0, 0, 0, 100, 0),
(@PATH, 10, -5060.5728, 472.1736, 404.02484, NULL, 1000, 0, 0, 100, 0);

SET @ENTRY := 39841;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
UPDATE `creature_addon` SET `path_id`=@PATH WHERE `guid`=@CGUID+118;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -5335.8145, 545.21875, 403.1348, NULL, 0, 1, 0, 100, 0),
(@PATH, 2, -5337.099, 544.67883, 403.88538, NULL, 0, 1, 0, 100, 0),
(@PATH, 3, -5329.5903, 541.2031, 408.67224, NULL, 0, 1, 0, 100, 0),
(@PATH, 4, -5335.424, 548.31946, 401.67233, NULL, 0, 1, 0, 100, 0),
(@PATH, 5, -5329.618, 547.0903, 406.5613, NULL, 0, 1, 0, 100, 0),
(@PATH, 6, -5325.625, 544.283, 401.1445, NULL, 0, 1, 0, 100, 0),
(@PATH, 7, -5309.5884, 565.88544, 400.3512, NULL, 0, 1, 0, 100, 0),
(@PATH, 8, -5298.0312, 567.6406, 406.6901, NULL, 0, 1, 0, 100, 0),
(@PATH, 9, -5298.271, 572.2083, 405.19037, NULL, 0, 1, 0, 100, 0),
(@PATH, 10, -5299.6426, 575.1597, 405.2173, NULL, 0, 1, 0, 100, 0),
(@PATH, 11, -5295.0903, 574.07117, 404.9674, NULL, 0, 1, 0, 100, 0),
(@PATH, 12, -5290.9585, 569.4583, 402.49527, NULL, 0, 1, 0, 100, 0),
(@PATH, 13, -5290.7466, 573.42365, 407.1339, NULL, 0, 1, 0, 100, 0),
(@PATH, 14, -5295.514, 578.3125, 404.24518, NULL, 0, 1, 0, 100, 0),
(@PATH, 15, -5318.318, 584.8785, 409.91238, NULL, 0, 1, 0, 100, 0),
(@PATH, 16, -5324.528, 583.7031, 406.21796, NULL, 0, 1, 0, 100, 0),
(@PATH, 17, -5322.6978, 589.25867, 411.66235, NULL, 0, 1, 0, 100, 0),
(@PATH, 18, -5325.2085, 597.2639, 409.05136, NULL, 0, 1, 0, 100, 0),
(@PATH, 19, -5329.9165, 592.0434, 411.99588, NULL, 0, 1, 0, 100, 0),
(@PATH, 20, -5327.297, 587.0417, 405.4404, NULL, 0, 1, 0, 100, 0),
(@PATH, 21, -5332.9097, 581.6528, 411.1069, NULL, 0, 1, 0, 100, 0),
(@PATH, 22, -5344.384, 578.0208, 411.32928, NULL, 0, 1, 0, 100, 0),
(@PATH, 23, -5349.408, 577.0972, 405.0239, NULL, 0, 1, 0, 100, 0),
(@PATH, 24, -5350.0815, 575.2899, 409.77377, NULL, 0, 1, 0, 100, 0),
(@PATH, 25, -5349.924, 572.79517, 405.44025, NULL, 0, 1, 0, 100, 0),
(@PATH, 26, -5356.08, 576.61115, 406.2459, NULL, 0, 1, 0, 100, 0),
(@PATH, 27, -5354.6353, 570.9149, 403.05142, NULL, 0, 1, 0, 100, 0),
(@PATH, 28, -5352.2207, 566.52606, 401.80142, NULL, 0, 1, 0, 100, 0),
(@PATH, 29, -5338.4653, 546.2344, 402.1904, NULL, 0, 1, 0, 100, 0);

SET @ENTRY := 39841;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
UPDATE `creature_addon` SET `path_id`=@PATH WHERE `guid`=@CGUID+119;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -5295.0903, 574.07117, 404.9674, NULL, 0, 1, 0, 100, 0),
(@PATH, 2, -5290.9585, 569.4583, 402.49527, NULL, 0, 1, 0, 100, 0),
(@PATH, 3, -5290.7466, 573.42365, 407.1339, NULL, 0, 1, 0, 100, 0),
(@PATH, 4, -5295.514, 578.3125, 404.24518, NULL, 0, 1, 0, 100, 0),
(@PATH, 5, -5318.318, 584.8785, 409.91238, NULL, 0, 1, 0, 100, 0),
(@PATH, 6, -5324.528, 583.7031, 406.21796, NULL, 0, 1, 0, 100, 0),
(@PATH, 7, -5322.6978, 589.25867, 411.66235, NULL, 0, 1, 0, 100, 0),
(@PATH, 8, -5325.2085, 597.2639, 409.05136, NULL, 0, 1, 0, 100, 0),
(@PATH, 9, -5329.9165, 592.0434, 411.99588, NULL, 0, 1, 0, 100, 0),
(@PATH, 10, -5327.297, 587.0417, 405.4404, NULL, 0, 1, 0, 100, 0),
(@PATH, 11, -5332.9097, 581.6528, 411.1069, NULL, 0, 1, 0, 100, 0),
(@PATH, 12, -5344.384, 578.0208, 411.32928, NULL, 0, 1, 0, 100, 0),
(@PATH, 13, -5349.408, 577.0972, 405.0239, NULL, 0, 1, 0, 100, 0),
(@PATH, 14, -5350.0815, 575.2899, 409.77377, NULL, 0, 1, 0, 100, 0),
(@PATH, 15, -5349.924, 572.79517, 405.44025, NULL, 0, 1, 0, 100, 0),
(@PATH, 16, -5356.08, 576.61115, 406.2459, NULL, 0, 1, 0, 100, 0),
(@PATH, 17, -5354.6353, 570.9149, 403.05142, NULL, 0, 1, 0, 100, 0),
(@PATH, 18, -5352.2207, 566.52606, 401.80142, NULL, 0, 1, 0, 100, 0),
(@PATH, 19, -5338.4653, 546.2344, 402.1904, NULL, 0, 1, 0, 100, 0),
(@PATH, 20, -5335.8145, 545.21875, 403.1348, NULL, 0, 1, 0, 100, 0),
(@PATH, 21, -5337.099, 544.67883, 403.88538, NULL, 0, 1, 0, 100, 0),
(@PATH, 22, -5329.5903, 541.2031, 408.67224, NULL, 0, 1, 0, 100, 0),
(@PATH, 23, -5335.424, 548.31946, 401.67233, NULL, 0, 1, 0, 100, 0),
(@PATH, 24, -5329.618, 547.0903, 406.5613, NULL, 0, 1, 0, 100, 0),
(@PATH, 25, -5325.625, 544.283, 401.1445, NULL, 0, 1, 0, 100, 0),
(@PATH, 26, -5309.5884, 565.88544, 400.3512, NULL, 0, 1, 0, 100, 0),
(@PATH, 27, -5298.0312, 567.6406, 406.6901, NULL, 0, 1, 0, 100, 0),
(@PATH, 28, -5298.271, 572.2083, 405.19037, NULL, 0, 1, 0, 100, 0),
(@PATH, 29, -5299.6426, 575.1597, 405.2173, NULL, 0, 1, 0, 100, 0);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+27;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Frostmane Hold
(@OGUID+0, 194498, 0, 1, 133, 1, 256, -5375.14599609375, 482.9757080078125, 384.44903564453125, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 54261), -- Gnomeregan Banner (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@OGUID+1, 194498, 0, 1, 133, 1, 256, -5376.38720703125, 472.720489501953125, 384.28338623046875, 5.445427894592285156, 0, 0, -0.40673637390136718, 0.913545548915863037, 120, 255, 1, 54261), -- Gnomeregan Banner (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@OGUID+2, 194498, 0, 1, 133, 1, 256, -5404.91162109375, 462.189239501953125, 384.778717041015625, 5.445427894592285156, 0, 0, -0.40673637390136718, 0.913545548915863037, 120, 255, 1, 54261), -- Gnomeregan Banner (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@OGUID+3, 194498, 0, 1, 133, 1, 256, -5429.35400390625, 547.78302001953125, 386.937896728515625, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 54261), -- Gnomeregan Banner (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@OGUID+4, 194498, 0, 1, 133, 1, 256, -5455.15966796875, 515.3975830078125, 387.597808837890625, 3.892086982727050781, 0, 0, -0.93041706085205078, 0.366502493619918823, 120, 255, 1, 54261), -- Gnomeregan Banner (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@OGUID+5, 194498, 0, 1, 133, 1, 256, -5418.6787109375, 459.5850830078125, 386.621673583984375, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 120, 255, 1, 54261), -- Gnomeregan Banner (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@OGUID+6, 202564, 0, 1, 135, 1, 256, -5430.0087890625, 535.7430419921875, 386.826568603515625, 4.869470596313476562, 0, 0, -0.64944744110107421, 0.760406434535980224, 120, 255, 1, 54261), -- Gnome Table (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@OGUID+7, 202713, 0, 1, 135, 1, 256, -5433.61279296875, 528.453125, 388.305389404296875, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 54261), -- Hazard Light Red 02 (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@OGUID+8, 202713, 0, 1, 135, 1, 256, -5440.0380859375, 524.28472900390625, 388.25738525390625, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 54261), -- Hazard Light Red 02 (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@OGUID+9, 202713, 0, 1, 135, 1, 256, -5430.1875, 526.1007080078125, 388.254608154296875, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 54261), -- Hazard Light Red 02 (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@OGUID+10, 202713, 0, 1, 135, 1, 256, -5439.31591796875, 520.19793701171875, 388.265106201171875, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 54261), -- Hazard Light Red 02 (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@OGUID+11, 202713, 0, 1, 135, 1, 256, -5431.72900390625, 518.65972900390625, 388.254974365234375, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 54261), -- Hazard Light Red 02 (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@OGUID+12, 202713, 0, 1, 135, 1, 256, -5437.625, 527.63018798828125, 388.274658203125, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 54261), -- Hazard Light Red 02 (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@OGUID+13, 202713, 0, 1, 135, 1, 256, -5429.4755859375, 522.06597900390625, 388.258941650390625, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 54261), -- Hazard Light Red 02 (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@OGUID+14, 202713, 0, 1, 135, 1, 256, -5435.77099609375, 517.82989501953125, 388.277984619140625, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 54261), -- Hazard Light Red 02 (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@OGUID+15, 202733, 0, 1, 135, 1, 256, -5418.14599609375, 476.55035400390625, 384.067718505859375, 0.663223206996917724, 0, 0, 0.325567245483398437, 0.945518851280212402, 120, 255, 1, 54261), -- Teleporter Pad (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@OGUID+16, 202733, 0, 1, 135, 1, 256, -5416.7568359375, 471.0382080078125, 383.983642578125, 0.645771682262420654, 0, 0, 0.317304611206054687, 0.948323667049407958, 120, 255, 1, 54261), -- Teleporter Pad (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@OGUID+17, 202733, 0, 1, 135, 1, 256, -5413.3193359375, 468.84375, 384.210052490234375, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 54261), -- Teleporter Pad (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@OGUID+18, 202733, 0, 1, 135, 1, 256, -5414.51904296875, 474.50347900390625, 383.9737548828125, 0.645771682262420654, 0, 0, 0.317304611206054687, 0.948323667049407958, 120, 255, 1, 54261), -- Teleporter Pad (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@OGUID+19, 202733, 0, 1, 135, 1, 256, -5420.3837890625, 473.0850830078125, 383.955657958984375, 0.663223206996917724, 0, 0, 0.325567245483398437, 0.945518851280212402, 120, 255, 1, 54261), -- Teleporter Pad (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@OGUID+20, 202733, 0, 1, 135, 1, 256, -5411.08154296875, 472.30902099609375, 384.00347900390625, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 54261), -- Teleporter Pad (Area: Frostmane Hold - Difficulty: 0) CreateObject1
(@OGUID+21, 202760, 0, 1, 135, 1, 256, -5434.7099609375, 523.17706298828125, 386.959228515625, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 54261), -- Large Teleporter Pad (Area: Frostmane Hold - Difficulty: 0) CreateObject1
-- New Tinkertown
(@OGUID+22, 202767, 0, 1, 133, 1, 256, -5074.42724609375, 442.46527099609375, 410.96624755859375, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 54261), -- Defensive Radiation Pump Control (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@OGUID+23, 202872, 0, 1, 133, 1, 256, -5331.56591796875, 544.982666015625, 384.62469482421875, 4.991643905639648437, 0, 0, -0.60181427001953125, 0.798636078834533691, 120, 255, 1, 54261), -- Rocket Platform (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@OGUID+24, 202872, 0, 1, 133, 1, 256, -5350.48974609375, 574.451416015625, 386.52813720703125, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 120, 255, 1, 54261), -- Rocket Platform (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@OGUID+25, 202872, 0, 1, 133, 1, 256, -5324.4306640625, 588.48785400390625, 388.4215087890625, 3.665196180343627929, 0, 0, -0.96592521667480468, 0.258821308612823486, 120, 255, 1, 54261), -- Rocket Platform (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@OGUID+26, 202872, 0, 1, 133, 1, 256, -5294.58349609375, 571.61114501953125, 386.342132568359375, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 120, 255, 1, 54261), -- Rocket Platform (Area: New Tinkertown - Difficulty: 0) CreateObject1
(@OGUID+27, 202922, 0, 1, 133, 1, 256, -4934.0380859375, 726.23956298828125, 261.645111083984375, 3.054326534271240234, 0, 0, 0.999048233032226562, 0.043619260191917419, 120, 255, 1, 54261); -- Irradiator 3000 (Area: New Tinkertown - Difficulty: 0) CreateObject1

UPDATE `gameobject` SET `phasemask`=257 WHERE `id`=106318 AND `guid` IN (9477,32370);
UPDATE `gameobject` SET `phasemask`=257 WHERE `id`=152614 AND `guid`=9290;
UPDATE `gameobject` SET `phasemask`=257 WHERE `id` IN (1936,80022,80023,90566,102984,179555);

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+130;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1),
(@EVENT, @CGUID+2),
(@EVENT, @CGUID+3),
(@EVENT, @CGUID+4),
(@EVENT, @CGUID+5),
(@EVENT, @CGUID+6),
(@EVENT, @CGUID+7),
(@EVENT, @CGUID+8),
(@EVENT, @CGUID+9),
(@EVENT, @CGUID+10),
(@EVENT, @CGUID+11),
(@EVENT, @CGUID+12),
(@EVENT, @CGUID+13),
(@EVENT, @CGUID+14),
(@EVENT, @CGUID+15),
(@EVENT, @CGUID+16),
(@EVENT, @CGUID+17),
(@EVENT, @CGUID+18),
(@EVENT, @CGUID+19),
(@EVENT, @CGUID+20),
(@EVENT, @CGUID+21),
(@EVENT, @CGUID+22),
(@EVENT, @CGUID+23),
(@EVENT, @CGUID+24),
(@EVENT, @CGUID+25),
(@EVENT, @CGUID+26),
(@EVENT, @CGUID+27),
(@EVENT, @CGUID+28),
(@EVENT, @CGUID+29),
(@EVENT, @CGUID+30),
(@EVENT, @CGUID+31),
(@EVENT, @CGUID+32),
(@EVENT, @CGUID+33),
(@EVENT, @CGUID+34),
(@EVENT, @CGUID+35),
(@EVENT, @CGUID+36),
(@EVENT, @CGUID+37),
(@EVENT, @CGUID+38),
(@EVENT, @CGUID+39),
(@EVENT, @CGUID+40),
(@EVENT, @CGUID+41),
(@EVENT, @CGUID+42),
(@EVENT, @CGUID+43),
(@EVENT, @CGUID+44),
(@EVENT, @CGUID+45),
(@EVENT, @CGUID+46),
(@EVENT, @CGUID+47),
(@EVENT, @CGUID+48),
(@EVENT, @CGUID+49),
(@EVENT, @CGUID+50),
(@EVENT, @CGUID+51),
(@EVENT, @CGUID+52),
(@EVENT, @CGUID+53),
(@EVENT, @CGUID+54),
(@EVENT, @CGUID+55),
(@EVENT, @CGUID+56),
(@EVENT, @CGUID+57),
(@EVENT, @CGUID+58),
(@EVENT, @CGUID+59),
(@EVENT, @CGUID+60),
(@EVENT, @CGUID+61),
(@EVENT, @CGUID+62),
(@EVENT, @CGUID+63),
(@EVENT, @CGUID+64),
(@EVENT, @CGUID+65),
(@EVENT, @CGUID+66),
(@EVENT, @CGUID+67),
(@EVENT, @CGUID+68),
(@EVENT, @CGUID+69),
(@EVENT, @CGUID+70),
(@EVENT, @CGUID+71),
(@EVENT, @CGUID+72),
(@EVENT, @CGUID+73),
(@EVENT, @CGUID+74),
(@EVENT, @CGUID+75),
(@EVENT, @CGUID+76),
(@EVENT, @CGUID+77),
(@EVENT, @CGUID+78),
(@EVENT, @CGUID+79),
(@EVENT, @CGUID+80),
(@EVENT, @CGUID+81),
(@EVENT, @CGUID+82),
(@EVENT, @CGUID+83),
(@EVENT, @CGUID+84),
(@EVENT, @CGUID+85),
(@EVENT, @CGUID+86),
(@EVENT, @CGUID+87),
(@EVENT, @CGUID+88),
(@EVENT, @CGUID+89),
(@EVENT, @CGUID+90),
(@EVENT, @CGUID+91),
(@EVENT, @CGUID+92),
(@EVENT, @CGUID+93),
(@EVENT, @CGUID+94),
(@EVENT, @CGUID+95),
(@EVENT, @CGUID+96),
(@EVENT, @CGUID+97),
(@EVENT, @CGUID+98),
(@EVENT, @CGUID+99),
(@EVENT, @CGUID+100),
(@EVENT, @CGUID+101),
(@EVENT, @CGUID+102),
(@EVENT, @CGUID+103),
(@EVENT, @CGUID+104),
(@EVENT, @CGUID+105),
(@EVENT, @CGUID+106),
(@EVENT, @CGUID+107),
(@EVENT, @CGUID+108),
(@EVENT, @CGUID+109),
(@EVENT, @CGUID+110),
(@EVENT, @CGUID+111),
(@EVENT, @CGUID+112),
(@EVENT, @CGUID+113),
(@EVENT, @CGUID+114),
(@EVENT, @CGUID+115),
(@EVENT, @CGUID+116),
(@EVENT, @CGUID+117),
(@EVENT, @CGUID+118),
(@EVENT, @CGUID+119),
(@EVENT, @CGUID+120),
(@EVENT, @CGUID+121),
(@EVENT, @CGUID+122),
(@EVENT, @CGUID+123),
(@EVENT, @CGUID+124),
(@EVENT, @CGUID+125),
(@EVENT, @CGUID+126),
(@EVENT, @CGUID+127),
(@EVENT, @CGUID+128),
(@EVENT, @CGUID+129),
(@EVENT, @CGUID+130);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID+0 AND @OGUID+27;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@EVENT, @OGUID+0),
(@EVENT, @OGUID+1),
(@EVENT, @OGUID+2),
(@EVENT, @OGUID+3),
(@EVENT, @OGUID+4),
(@EVENT, @OGUID+5),
(@EVENT, @OGUID+6),
(@EVENT, @OGUID+7),
(@EVENT, @OGUID+8),
(@EVENT, @OGUID+9),
(@EVENT, @OGUID+10),
(@EVENT, @OGUID+11),
(@EVENT, @OGUID+12),
(@EVENT, @OGUID+13),
(@EVENT, @OGUID+14),
(@EVENT, @OGUID+15),
(@EVENT, @OGUID+16),
(@EVENT, @OGUID+17),
(@EVENT, @OGUID+18),
(@EVENT, @OGUID+19),
(@EVENT, @OGUID+20),
(@EVENT, @OGUID+21),
(@EVENT, @OGUID+22),
(@EVENT, @OGUID+23),
(@EVENT, @OGUID+24),
(@EVENT, @OGUID+25),
(@EVENT, @OGUID+26),
(@EVENT, @OGUID+27);
