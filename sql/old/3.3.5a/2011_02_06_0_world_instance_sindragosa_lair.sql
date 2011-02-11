-- Creature templates
UPDATE `creature_template` SET `difficulty_entry_1`=38139 WHERE `entry`=37531;
UPDATE `creature_template` SET `difficulty_entry_1`=38151 WHERE `entry`=37532;
UPDATE `creature_template` SET `difficulty_entry_2`=0,`difficulty_entry_3`=0 WHERE `entry`=37533;
UPDATE `creature_template` SET `difficulty_entry_2`=0,`difficulty_entry_3`=0 WHERE `entry`=37534;
UPDATE `creature_template` SET `difficulty_entry_1`=38320,`difficulty_entry_2`=38321,`difficulty_entry_3`=38322 WHERE `entry`=36980;
UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82,`unit_class`=1,`faction_A`=14,`faction_H`=14,`unit_flags`=`unit_flags`|33554432,`baseattacktime`=2000,`flags_extra`=`flags_extra`|128 WHERE `entry`=38223; -- Icy Blast
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`unit_class`=1,`faction_A`=2209,`faction_H`=2209,`dynamicflags`=8,`baseattacktime`=2000,`equipment_id`=523,`speed_walk`=1,`speed_run`=1.42857 WHERE `entry` IN (37531,38139); -- Frostwarden Handler
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`unit_class`=2,`faction_A`=16,`faction_H`=16,`dynamicflags`=8,`baseattacktime`=2000,`speed_run`=1 WHERE `entry` IN (37532,38151); -- Frostwing Whelp
UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82,`unit_class`=2,`faction_A`=21,`faction_H`=21,`unit_flags`=`unit_flags`|64,`baseattacktime`=2000,`speed_walk`=2,`speed_run`=1.5873,`MovementType`=2,`InhabitType`=5 WHERE `entry` IN (37533,38220); -- Rimefang
UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82,`unit_class`=2,`faction_A`=21,`faction_H`=21,`unit_flags`=`unit_flags`|64,`baseattacktime`=2000,`speed_walk`=2,`speed_run`=1.5873,`MovementType`=2,`InhabitType`=5 WHERE `entry` IN (37534,38219); -- Spinestalker
UPDATE `creature_template` SET `minlevel`=83,`maxlevel`=83,`unit_class`=1,`faction_A`=2068,`faction_H`=2068,`unit_flags`=0,`baseattacktime`=1500,`speed_walk`=4.8,`speed_run`=4.28571 WHERE `entry` IN (36853,38265,38266,38267); -- Sindragosa
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`unit_class`=2,`faction_A`=14,`faction_H`=14,`unit_flags`=`unit_flags`|33554944,`baseattacktime`=2000,`flags_extra`=`flags_extra`|128 WHERE `entry`=37186; -- Frost Bomb
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`unit_class`=1,`faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`speed_run`=1 WHERE `entry` IN (36980,38320,38321,38322); -- Ice Tomb

-- Linked respawns
SET @GUID := 151761;
SET @SPINESTALKER := 207211;
SET @RIMEFANG := 207210;
DELETE FROM `linked_respawn` WHERE guid IN (@SPINESTALKER,@RIMEFANG) OR `guid` BETWEEN @GUID+22 AND @GUID+51;
INSERT INTO `linked_respawn` (`guid`,`linkedGuid`,`linkType`) VALUES
(@SPINESTALKER,@SPINESTALKER,0), -- Spinestalker
(@RIMEFANG,@RIMEFANG,0), -- Rimefang
(@GUID+22,@SPINESTALKER,0), --  Frostwarden Handler
(@GUID+23,@RIMEFANG,0), --  Frostwarden Handler
(@GUID+24,@SPINESTALKER,0), --  Frostwing Whelp
(@GUID+25,@SPINESTALKER,0), --  Frostwing Whelp
(@GUID+26,@SPINESTALKER,0), --  Frostwing Whelp
(@GUID+27,@SPINESTALKER,0), --  Frostwing Whelp
(@GUID+28,@SPINESTALKER,0), --  Frostwing Whelp
(@GUID+29,@SPINESTALKER,0), --  Frostwing Whelp
(@GUID+30,@SPINESTALKER,0), --  Frostwing Whelp
(@GUID+31,@SPINESTALKER,0), --  Frostwing Whelp
(@GUID+32,@RIMEFANG,0), --  Frostwing Whelp
(@GUID+33,@RIMEFANG,0), --  Frostwing Whelp
(@GUID+34,@RIMEFANG,0), --  Frostwing Whelp
(@GUID+35,@SPINESTALKER,0), --  Frostwing Whelp
(@GUID+36,@SPINESTALKER,0), --  Frostwing Whelp
(@GUID+37,@RIMEFANG,0), --  Frostwing Whelp
(@GUID+38,@RIMEFANG,0), --  Frostwing Whelp
(@GUID+39,@RIMEFANG,0), --  Frostwing Whelp
(@GUID+40,@SPINESTALKER,0), --  Frostwing Whelp
(@GUID+41,@RIMEFANG,0), --  Frostwing Whelp
(@GUID+42,@SPINESTALKER,0), --  Frostwing Whelp
(@GUID+43,@SPINESTALKER,0), --  Frostwing Whelp
(@GUID+44,@SPINESTALKER,0), --  Frostwing Whelp
(@GUID+45,@RIMEFANG,0), --  Frostwing Whelp
(@GUID+46,@RIMEFANG,0), --  Frostwing Whelp
(@GUID+47,@RIMEFANG,0), --  Frostwing Whelp
(@GUID+48,@RIMEFANG,0), --  Frostwing Whelp
(@GUID+49,@RIMEFANG,0), --  Frostwing Whelp
(@GUID+50,@RIMEFANG,0), --  Frostwing Whelp
(@GUID+51,@RIMEFANG,0); --  Frostwing Whelp

-- Creature addon
UPDATE `creature_addon` SET `bytes1`=0 WHERE `guid` IN (@SPINESTALKER,@RIMEFANG);

-- Creature model data
UPDATE `creature_model_info` SET `gender`=1 WHERE `modelid`=30362;

-- Gameobject templates
UPDATE `gameobject_template` SET `flags`=33,`faction`=114 WHERE `entry`=202396; -- Ice Wall
UPDATE `gameobject_template` SET `flags`=32,`faction`=114 WHERE `entry`=201722; -- Ice Block

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `id`=202396;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(121712,202396,631,15,1,4309.686,2491.27441,211.170792,0.209439442,0,0,0,0,120,0,0); -- Ice Wall

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=70598;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`Comment`) VALUES
(13,70598,18,1, 'Sindragosa''s Fury - player targets');
