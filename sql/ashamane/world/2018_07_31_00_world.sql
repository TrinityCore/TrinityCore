-- General --
UPDATE `creature` SET `MovementType` = 0 WHERE `id` IN (40588,43049,52296,52295,52291,53000,52982,52223,51533,43219,12034,35162,14551,14552,14553,12367,12363,12366,12365,14718,1059,2530,26078);
UPDATE `creature` SET `MovementType` = 0 WHERE `id` IN (41398,41393,43173,43178,43080,43081,932,933,935,27801,28113,35190,35296,36748,35484,52018,48340,37145,46414,51789,46714,866,46190,46188,46189,46187,45852,45856,37015,39657,40497,40493);
UPDATE `creature` SET `MovementType` = 0 WHERE `guid` IN (183806,183746);
UPDATE `creature_template` SET `minlevel` = 0, `maxlevel` = 0 WHERE `minlevel` = 110 AND (`HealthScalingExpansion` = -1);

-- Remove Nightmare Dragons
DELETE FROM `creature` WHERE `id` IN (14887,14888,14889,14890);

-- Trol Starting Area --
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 37961;
DELETE FROM `creature_queststarter` WHERE `id` = 37961;
DELETE FROM `gossip_menu_option` WHERE `MenuId` = 10974 AND (`OptionIndex` = 1);

-- Azshara --
DELETE FROM `creature` WHERE `guid` IN (243917,243935,243970) AND (`id` = 36541);
DELETE FROM `creature` WHERE `guid` = 242701 AND (`id` = 8408);
DELETE FROM `creature_loot_template` WHERE `item` = 20772 AND (`entry` = 35245);
DELETE FROM `creature_loot_template` WHERE `entry` = 36756;
DELETE FROM `creature_loot_template` WHERE `entry` IN (36943,37070) AND (`item` = 22889);
UPDATE `creature_loot_template` SET `QuestRequired` = 1 WHERE `item` = 58949;
UPDATE `gameobject_loot_template` SET `MaxCount` = 5 WHERE `item` = 48128 AND (`entry` = 195447);
UPDATE `npc_spellclick_spells` SET `spell_id` = 69261, `cast_flags` = 2 WHERE `npc_entry` = 36756;
UPDATE `creature_template` SET `faction` = 714 WHERE `entry` = 36756;
UPDATE `creature_template_addon` SET `bytes1` = 7 WHERE `entry` = 36756;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=36756 AND `SourceEntry`=69261;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,36756,69261,0,0,9,0,14469,0,0,0,0,0,"","Allow Spellclick only if Quest 14469 Taken");

-- Ashenvale --
DELETE FROM `creature` WHERE `guid` = 238072;
DELETE FROM `creature_queststarter` WHERE `quest` = 2 AND (`id` = 12696);

-- Stranglethon Vale --
DELETE FROM `creature` WHERE `id` = 53569;
DELETE FROM `creature` WHERE `guid` IN (183878,183759,183877,312919);
DELETE FROM `creature_queststarter` WHERE `quest` = 583 AND (`id` = 715);
DELETE FROM `creature_queststarter` WHERE `quest` = 26350 AND (`id` = 42812);
UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 2530;

-- Tanaris --
DELETE FROM `creature_queststarter` WHERE `quest` = 26896 AND `id` = 39034;

-- Northrend --
DELETE FROM `creature` WHERE `guid` IN (125540,125541);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
('125540','25273','571','0','0','1','0','0','23041','1','2822.7','6171.69','122.061','0.802851','300','0','0','9940','0','0','0','0','0','0','0','','0'),
('125541','25273','571','0','0','1','0','0','23041','1','2903.6','6246.42','208.834','0.575959','300','0','0','9940','0','0','0','0','0','0','0','','0');
UPDATE `creature_template` SET `faction` = 1981 WHERE `entry` = 25610;
UPDATE `creature_template` SET `InhabitType` = 8 WHERE `entry` = 25284;
UPDATE `creature` SET `id` = 6491, `modelid` = 5233 WHERE `id` = 29259 AND (`map` = 571);
UPDATE `creature` SET `id` = 25584 WHERE `id` = 25474;
DELETE FROM `creature_template_addon` WHERE `entry` = 25328;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(25328,0,0,7,0,0,0,0,0,'19502');

-- Durotar --
UPDATE `creature_template` SET `minlevel` = 0, `maxlevel` = 0 WHERE `entry` IN (88701,88702,88703);
DELETE FROM `creature` WHERE `guid` = 21011206;
DELETE FROM `creature_template_addon` WHERE `entry` = 62194;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(62194,0,0,0,0,69,0,0,0,'');

-- Tirisfal Glades --
DELETE FROM `game_event_creature` WHERE `guid` IN (176243,176282,186838,186839,186840,186841,186843,186962,187056,192582,192583,192584,192886,192888,193047,193048,193146,193147,193148,193149,193207,193243,193244,194428,194429,194436,194439,201164,201187,201188,201197,201198,201199,201200,201214,201215,201216,201217,201224,201225,201230,201232,201233);
DELETE FROM `game_event_creature` WHERE `guid` IN (357514,357515,357516,357517,357518,357519,357520,357521,357522,357523,357524,357525,357526,357528,357529,357530,357531);
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(8,357514),
(8,357515),
(8,357516),
(8,357517),
(8,357518),
(8,357519),
(8,357520),
(8,357521),
(8,357522),
(8,357523),
(8,357524),
(8,357525),
(8,357526),
(8,357528),
(8,357529),
(8,357530),
(8,357531);

-- Elwynn Forest --
UPDATE `creature_template` SET `flags_extra` = 128 WHERE `entry` = 37574;
DELETE FROM `gameobject` WHERE guid IN (20373637,20373636,20373650,20373649,20373648,20373667,20373657,20373658,20373666,20373668,20373669,20373665,20373670,20373671,20373661,20373647,20373631,20373630,20373629,20373625,20373619,20373623,20373624,20373622,20373684);
DELETE FROM `game_event_gameobject` WHERE guid IN (20373616,20373639,20373643,20373662,20373575);
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(3,20373616),
(3,20373639),
(3,20373643),
(3,20373662),
(3,20373575);

-- New Tinkertown --
UPDATE `creature_questender` SET `id` = 63238 WHERE `quest` = 31135;
DELETE FROM `creature_queststarter` WHERE `id` = 63238 AND `quest` IN (31137,31138);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(63238,31137),
(63238,31138);

-- Ebon Hold --
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.28968 WHERE `entry` = 28912;

-- New Dalaran --
DELETE FROM `npc_vendor` WHERE `ExtendedCost` IN (5835,5836,5837,5838) AND (`entry` = 92489);

-- Mac'Aree --
DELETE FROM `creature` WHERE `id` = 123889;
DELETE FROM `creature` WHERE `guid` IN (2100887,21008867,21008787,21008886,21008886) AND (`id` = 126869);
DELETE FROM `creature_addon` WHERE `guid` IN (21008867,21008787);
UPDATE `creature_template` SET `modelid1` = 39810, `modelid2` = 0 WHERE `entry` = 120693;
