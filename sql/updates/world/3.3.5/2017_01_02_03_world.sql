-- [Q] The Flesh Lies... 
-- Withered Corpse SAI
SET @ENTRY := 20561;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,35372,0,0,0,33,20561,0,0,0,0,0,7,0,0,0,0,0,0,0,"Withered Corpse - On Spellhit 'Protectorate Igniter' - Quest Credit 'The Flesh Lies...''"),
(@ENTRY,0,1,2,61,0,100,0,35372,0,0,0,50,184445,60,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Corpse - On Spellhit 'Protectorate Igniter' - Summon Gameobject 'Charred Remains'"),
(@ENTRY,0,2,0,61,0,100,0,35372,0,0,0,51,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Corpse - On Spellhit 'Protectorate Igniter' - Kill Target"),
(@ENTRY,0,3,4,10,0,100,1,0,4,0,0,12,20335,3,120000,0,0,0,1,0,0,0,0,0,0,0,"Withered Corpse - Within 0-4 Range Out of Combat LoS - Summon Creature 'Parasitic Fleshbeast'"),
(@ENTRY,0,4,5,61,0,100,0,0,4,0,0,11,35309,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Corpse - Within 0-4 Range Out of Combat LoS - Cast 'Bloody Explosion'"),
(@ENTRY,0,5,0,61,0,100,0,0,4,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Corpse - Within 0-4 Range Out of Combat LoS - Despawn In 1000 ms");

DELETE FROM `creature_template_addon` WHERE `entry`=20561;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(20561, 0, 0, 3, 1, 0, '29266');

-- respawn creatures correctly
SET @CGUID := 77881; -- 25 spawns set by TC TEAM
DELETE FROM `creature` WHERE `id`=20561;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+24;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(@CGUID+0, 20561, 530, 0, 0, 1, 1, 0, 0, 3711.35, 2096.57, 151.984, 1.18682, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+1, 20561, 530, 0, 0, 1, 1, 0, 0, 3737.86, 2082.16, 148.9, 0.837758, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+2, 20561, 530, 0, 0, 1, 1, 0, 0, 3750.9, 2055.32, 148.853, 5.44543, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+3, 20561, 530, 0, 0, 1, 1, 0, 0, 3760.86, 2082.87, 152.837, 2.40855, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+4, 20561, 530, 0, 0, 1, 1, 0, 0, 3790.07, 2073.02, 153.16, 4.60767, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+5, 20561, 530, 0, 0, 1, 1, 0, 0, 3815.1, 2102.61, 148.003, 1.72788, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+6, 20561, 530, 0, 0, 1, 1, 0, 0, 3823.88, 2064.43, 147.579, 6.21337, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+7, 20561, 530, 0, 0, 1, 1, 0, 0, 3835.91, 2045.9, 145.151, 0.942478, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+8, 20561, 530, 0, 0, 1, 1, 0, 0, 3839.54, 2137.05, 145.967, 3.54302, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+9, 20561, 530, 0, 0, 1, 1, 0, 0, 3849.06, 2147.26, 140.311, 4.31096, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+10, 20561, 530, 0, 0, 1, 1, 0, 0, 3853.08, 2153.72, 140.589, 0.418879, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+11, 20561, 530, 0, 0, 1, 1, 0, 0, 3863.25, 2120.24, 146.842, 5.46288, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+12, 20561, 530, 0, 0, 1, 1, 0, 0, 3867.95, 2023.28, 144.585, 5.65487, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+13, 20561, 530, 0, 0, 1, 1, 0, 0, 3870.96, 2103.97, 133.353, 1.58825, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+14, 20561, 530, 0, 0, 1, 1, 0, 0, 3875.74, 2150.16, 139.272, 3.61283, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+15, 20561, 530, 0, 0, 1, 1, 0, 0, 3881.19, 2078.43, 131.736, 3.66519, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+16, 20561, 530, 0, 0, 1, 1, 0, 0, 3890.49, 2102.26, 153.708, 4.62512, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+17, 20561, 530, 0, 0, 1, 1, 0, 0, 3902.53, 2052.92, 150.162, 3.21141, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+18, 20561, 530, 0, 0, 1, 1, 0, 0, 3903.43, 2124.28, 137.706, 0.244346, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+19, 20561, 530, 0, 0, 1, 1, 0, 0, 3908.28, 2081.01, 133.479, 4.18879, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+20, 20561, 530, 0, 0, 1, 1, 0, 0, 3912.87, 2079.35, 153.77, 1.37881, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+21, 20561, 530, 0, 0, 1, 1, 0, 0, 3926.43, 2105.75, 159.264, 3.61283, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+22, 20561, 530, 0, 0, 1, 1, 0, 0, 3935.88, 2138.8, 160.69, 1.23918, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+23, 20561, 530, 0, 0, 1, 1, 0, 0, 3968.76, 2112.71, 162.382, 6.19592, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+24, 20561, 530, 0, 0, 1, 1, 0, 0, 3987.21, 2132.56, 162.681, 3.40339, 120, 0, 0, 1, 0, 0, 0, 0, 0);
