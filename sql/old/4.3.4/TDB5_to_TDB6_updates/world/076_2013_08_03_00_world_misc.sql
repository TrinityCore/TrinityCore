-- Sergeant Kregga, Captain Kendall, Opportunity and Exploiting an Opening fix by nelegalno
-- http://www.wowhead.com/zone=210#comments:id=838363
-- http://www.wowhead.com/zone=210#comments:id=838364
SET @GUID=115; -- Set by TDB team (4.x changed)
SET @ASPELL=59073;
SET @HSPELL=59087;
SET @AREA=4522;

-- Sergeant Kregga (31440)
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`exp`=2 WHERE `entry`=31440;
DELETE FROM `creature` WHERE `guid`=@GUID AND `id`=31440;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID,31440,571,1,8,0,0,5874.2,1948.5,516.1,2.8,300,0,0,32000,0,0,0,0,0);

-- Captain Kendall (31444)
UPDATE `creature` SET `phaseMask`=2 WHERE `id`=31444;

DELETE FROM `spell_area` WHERE `spell`=@HSPELL AND `area`=@AREA;
DELETE FROM `spell_area` WHERE `spell`=@ASPELL AND `area`=@AREA;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(@HSPELL,@AREA,12899,0,0, 690,2,1,64,43), -- Horde version
(@ASPELL,@AREA,12898,0,0,1101,2,1,64,43); -- Alliance version
