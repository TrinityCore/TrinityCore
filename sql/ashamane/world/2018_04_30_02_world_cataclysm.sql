UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 48312;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 48316;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 48314;

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('12416','0','0','Talk....','0','1','1','29416');

SET @ENTRY := 48316;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,12416,0,0,0,33,48316,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('12414','0','0','Talk....','0','1','1','29416');

SET @ENTRY := 48312;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,12414,0,0,0,33,48312,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('12415','0','0','Talk....','0','1','1','29416');

SET @ENTRY := 48314;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,12415,0,0,0,33,48314,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");

replace  into `creature_queststarter`(`id`,`quest`) values (48307,28326);
replace  into `creature_questender`(`id`,`quest`) values (48307,28326);

replace  into `creature_queststarter`(`id`,`quest`) values (48569,28449);
replace  into `creature_questender`(`id`,`quest`) values (48569,28449);

UPDATE `creature_template` SET `InhabitType` = 5 WHERE `entry` = 16378;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `guid` = 163173;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `guid` = 163174;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `guid` = 163244;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `guid` = 163334;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `guid` = 163297;

UPDATE `quest_objectives` SET `Type` = '0' , `ObjectID` = '42248' , `Amount` = '1' , `Description` = 'Scout the ships on the Shattershore' WHERE `ID` = '255887';

UPDATE `creature_template` SET `MovementType` = 1, `InhabitType` = 4 WHERE `entry` = 42235;
DELETE FROM `creature` WHERE `id`=41404;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(164420, 41404, 0, 4, 5080, 1, 0, 0, 0, -1, 31533, 0, -12346.9, -3608.9, 18.5285, 3.78705, 300, 3, 0, 2699, 0, 1, 0, 0, 0, 0, 0, '', 0),
(164419, 41404, 0, 4, 5080, 1, 0, 0, 0, -1, 31533, 0, -12387.1, -3617.44, 19.477, 3.735, 300, 3, 0, 2699, 0, 1, 0, 0, 0, 0, 0, '', 0),
(164417, 41404, 0, 4, 5080, 1, 0, 0, 0, -1, 31533, 0, -12384.9, -3586.06, 18.7392, 2.80711, 300, 3, 0, 2699, 0, 1, 0, 0, 0, 0, 0, '', 0),
(164416, 41404, 0, 4, 5080, 1, 0, 0, 0, -1, 31533, 0, -12402.6, -3610.38, 19.4949, 2.93215, 300, 3, 0, 2699, 0, 1, 0, 0, 0, 0, 0, '', 0),
(164116, 41404, 0, 4, 5080, 1, 0, 0, 0, -1, 31533, 0, -12416, -3591.15, 19.5325, 4.79965, 300, 3, 0, 2699, 0, 1, 0, 0, 0, 0, 0, '', 0),
(164115, 41404, 0, 4, 5080, 1, 0, 0, 0, -1, 31533, 0, -12330.3, -3655.91, 19.3476, 5.84685, 300, 3, 0, 2699, 0, 1, 0, 0, 0, 0, 0, '', 0),
(164114, 41404, 0, 4, 5080, 1, 0, 0, 0, -1, 31533, 0, -12417.4, -3617.2, 19.2848, 1.51844, 300, 3, 0, 2699, 0, 1, 0, 0, 0, 0, 0, '', 0),
(164113, 41404, 0, 4, 5080, 1, 0, 0, 0, -1, 31533, 0, -12350.5, -3649.71, 18.8058, 3.49066, 300, 3, 0, 2699, 0, 1, 0, 0, 0, 0, 0, '', 0),
(164109, 41404, 0, 4, 5080, 1, 0, 0, 0, -1, 31533, 0, -12372.3, -3636.53, 18.6317, 5.75959, 300, 3, 0, 2699, 0, 1, 0, 0, 0, 0, 0, '', 0),
(164084, 41404, 0, 4, 5078, 1, 0, 0, 0, -1, 31533, 0, -12273.6, -3588.34, 17.0806, 2.06605, 300, 3, 0, 2699, 0, 1, 0, 0, 0, 0, 0, '', 0),
(164075, 41404, 0, 4, 5078, 1, 0, 0, 0, -1, 31533, 0, -12307.3, -3623.36, 16.3415, 2.88198, 300, 3, 0, 2699, 0, 1, 0, 0, 0, 0, 0, '', 0),
(164073, 41404, 0, 4, 5078, 1, 0, 0, 0, -1, 31533, 0, -12262.6, -3545.92, 17.0645, 1.61116, 300, 3, 0, 2699, 0, 1, 0, 0, 0, 0, 0, '', 0),
(163998, 41404, 0, 4, 5080, 1, 0, 0, 0, -1, 31533, 0, -12425.7, -3655.32, 20.0368, 1.61635, 300, 3, 0, 2699, 0, 1, 0, 0, 0, 0, 0, '', 0),
(163989, 41404, 0, 4, 5078, 1, 0, 0, 0, -1, 31533, 0, -12310.2, -3563.94, 18.4275, 3.69302, 300, 3, 0, 2699, 0, 1, 0, 0, 0, 0, 0, '', 0),
(163981, 41404, 0, 4, 5080, 1, 0, 0, 0, -1, 31533, 0, -12386.8, -3655.68, 19.3965, 6.15334, 300, 3, 0, 2699, 0, 1, 0, 0, 0, 0, 0, '', 0),
(163943, 41404, 0, 4, 5080, 1, 0, 0, 0, -1, 31533, 0, -12431.1, -3640.72, 21.46, 3.03687, 300, 3, 0, 2699, 0, 1, 0, 0, 0, 0, 0, '', 0),
(163977, 41404, 0, 4, 5080, 1, 0, 0, 0, -1, 31533, 0, -12372.4, -3657.55, 19.1882, 0.802851, 300, 3, 0, 2699, 0, 1, 0, 0, 0, 0, 0, '', 0),
(210115056, 41404, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12372.6, -3657.93, 19.2114, 0.684382, 300, 0, 0, 6399, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115055, 41404, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12412.4, -3650.58, 19.8281, 1.83735, 300, 0, 0, 6399, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115054, 41404, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12417.3, -3645.85, 20.014, 6.22929, 300, 0, 0, 6399, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115053, 41404, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12413.2, -3642.4, 19.92, 4.81008, 300, 0, 0, 6688, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115052, 41404, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12417.3, -3591.43, 19.4748, 4.7606, 300, 0, 0, 6399, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115051, 41404, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12406.9, -3594.57, 19.2349, 4.00661, 300, 0, 0, 6399, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115050, 41404, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12410.9, -3615.12, 19.0798, 1.67398, 300, 0, 0, 6688, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115049, 41404, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12421.7, -3614.46, 19.0943, 1.24672, 300, 0, 0, 6688, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115048, 41404, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12395.6, -3631.38, 19.3942, 4.11578, 300, 0, 0, 6399, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115047, 41404, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12388.2, -3611.8, 19.3919, 4.91689, 300, 0, 0, 6688, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115046, 41404, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12387.8, -3617.4, 19.3919, 3.95635, 300, 0, 0, 6399, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115057, 41404, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12362.7, -3661.72, 18.7151, 1.51612, 300, 0, 0, 6399, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115058, 41404, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12350.4, -3649.34, 18.7739, 3.65319, 300, 0, 0, 6688, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115059, 41404, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12369, -3632.86, 18.8163, 4.98522, 300, 0, 0, 6399, 0, 0, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature_template` SET `KillCredit1` = 41402 WHERE `entry` = 41404;

UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` = 51384;

SET @ENTRY := 7783;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,26171,0,0,0,62,0,0,0,0,0,0,7,0,0,0,-11244,-2851,162,1,'Teleport on Quest Add');


SET @ENTRY := 7783;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,25701,0,0,0,62,0,0,0,0,0,0,7,0,0,0,-11244,-2851,162,1,'Teleport on Quest Add');


DELETE FROM `creature` WHERE `id`=51542;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210115064, 51542, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12661.7, -2915.76, 1.5396, 5.8406, 300, 0, 0, 27581, 0, 0, 0, 0, 0, 0, 0, '', 0),
(10595366, 51542, 1190, 4, 5084, 1, 0, 0, 0, -1, 37500, 0, -12711.4, -2893.69, 1.51725, 0.243032, 300, 3, 0, 116235, 0, 1, 0, 0, 0, 0, 0, '', 0),
(10595367, 51542, 1190, 4, 5084, 1, 0, 0, 0, -1, 37498, 0, -12723.9, -2944.84, 7.13169, 0, 300, 3, 0, 116235, 0, 1, 0, 0, 0, 0, 0, '', 0),
(210115063, 51542, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12665.8, -2927.77, 1.36812, 6.0126, 300, 0, 0, 27581, 0, 0, 0, 0, 0, 0, 0, '', 0),
(164641, 51542, 0, 4, 5084, 1, 0, 0, 0, -1, 37498, 0, -12723.9, -2944.84, 7.13169, 0, 300, 3, 0, 116235, 0, 1, 0, 0, 0, 0, 0, '', 0),
(210115065, 51542, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12691.3, -2906.97, 2.1355, 4.1245, 300, 0, 0, 27581, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115066, 51542, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12689, -2887.48, 1.40728, 3.16946, 300, 0, 0, 27581, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115067, 51542, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12688.8, -2895.7, 1.41026, 3.16946, 300, 0, 0, 27581, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115068, 51542, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12714.5, -2891.81, 1.39302, 5.39292, 300, 0, 0, 27581, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115069, 51542, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12711, -2888.97, 1.39302, 5.39292, 300, 0, 0, 27581, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115070, 51542, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12741.8, -2919.31, 6.64676, 5.82646, 300, 0, 0, 27581, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115071, 51542, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12729.1, -2925.56, 6.64676, 2.71, 300, 0, 0, 27581, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115072, 51542, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12742.8, -2875.96, 1.5893, 1.25859, 300, 0, 0, 27581, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115073, 51542, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12742.4, -2851.36, 1.45708, 5.51859, 300, 0, 0, 27581, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115074, 51542, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12752.9, -2853.94, 2.68966, 2.65189, 300, 0, 0, 27581, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115075, 51542, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12755, -2853.39, 2.67898, 6.20346, 300, 0, 0, 27581, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115076, 51542, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12728.1, -2835.46, 5.57991, 4.83451, 300, 0, 0, 27581, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115077, 51542, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12722.3, -2835.68, 5.49486, 4.54941, 300, 0, 0, 27581, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115078, 51542, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -12687.2, -2863.6, 3.07448, 3.87319, 300, 0, 0, 27581, 0, 0, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE `guid` = 42235;
UPDATE `creature_template` SET `MovementType` = 1, `InhabitType` = 5 WHERE `entry` = 42338;
DELETE FROM `creature_template_addon` WHERE (`entry`=44337);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (44337, 0, 0, 0, 1, 233, '');
UPDATE `creature_loot_template` SET `Chance` = '55' , `MinCount` = '2' , `MaxCount` = '4' WHERE `Entry` = '42336' AND `Item` = '57177'; 
UPDATE `creature_loot_template` SET `Chance` = '55' WHERE `Entry` = '42338' AND `Item` = '57179'; 
DELETE FROM `creature_template_addon` WHERE (`entry`=41193);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (41193, 0, 0, 0, 1, 0, 84063);
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (41158,306,307);
UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE `id` IN (42338);
