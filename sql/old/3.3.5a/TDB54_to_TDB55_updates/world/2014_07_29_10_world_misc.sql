-- Ango'rosh Ogre SAI
SET @ENTRY := 18117;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,4000,4000,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Ogre - In Combat - Cast 'Kick'"),
(@ENTRY,0,1,2,2,0,100,1,0,25,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Ogre - Between 0-25% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Ogre - Between 0-25% Health - Say Line 0 (No Repeat)");

-- Ango'rosh Shaman SAI
SET @ENTRY := 18118;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Shaman - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,0,0,100,1,18000,25000,0,0,11,32062,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Shaman - In Combat - Cast 'Fire Nova Totem' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,49,0,0,11,23381,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shaman - Between 0-49% Health - Cast 'Healing Touch' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shaman - Between 0-30% Health - Cast 'Bloodlust' (No Repeat)");

-- Ango'rosh Brute SAI
SET @ENTRY := 18119;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,4000,4000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Brute - In Combat - Cast 'Knockdown'"),
(@ENTRY,0,1,2,2,0,100,1,0,25,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Brute - Between 0-25% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Brute - Between 0-25% Health - Say Line 0 (No Repeat)");

-- Ango'rosh Mauler SAI
SET @ENTRY := 18120;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,49,0,0,11,14895,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Mauler - Between 0-49% Health - Cast 'Overpower' (No Repeat)");

-- Ango'rosh Souleater SAI
SET @ENTRY := 18121;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Souleater - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,35195,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Souleater - Between 0-30% Health - Cast 'Siphon Life' (No Repeat)");

UPDATE creature SET `spawndist`=0,`MovementType`=0 WHERE `id` IN (18117);
UPDATE creature_template_addon SET `emote`=234 WHERE `entry` IN (18117);

-- Pathing for Voidshrieker Entry: 18870
SET @NPC := 67511;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4103.666,`position_y`=2008.716,`position_z`=230.7258 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4103.666,2008.716,230.7258,0,0,0,0,100,0),
(@PATH,2,4125.061,1977.475,222.0139,0,0,0,0,100,0),
(@PATH,3,4144.464,1974.719,217.2654,0,0,0,0,100,0),
(@PATH,4,4179.295,1998.64,200.3009,0,0,0,0,100,0),
(@PATH,5,4187.473,2032.222,181.2747,0,0,0,0,100,0),
(@PATH,6,4175.088,2063.897,166.8787,0,0,0,0,100,0),
(@PATH,7,4187.473,2032.222,181.4369,0,0,0,0,100,0),
(@PATH,8,4179.295,1998.64,200.3009,0,0,0,0,100,0),
(@PATH,9,4144.464,1974.719,217.2654,0,0,0,0,100,0),
(@PATH,10,4125.061,1977.475,222.0139,0,0,0,0,100,0),
(@PATH,11,4103.666,2008.716,230.7258,0,0,0,0,100,0),
(@PATH,12,4080.718,2041.648,241.5903,0,0,0,0,100,0),
(@PATH,13,4062.161,2056.093,248.8654,0,0,0,0,100,0),
(@PATH,14,4035.457,2075.88,254.4613,0,0,0,0,100,0),
(@PATH,15,4006.357,2097.843,254.2741,0,0,0,0,100,0),
(@PATH,16,4035.457,2075.88,254.4613,0,0,0,0,100,0),
(@PATH,17,4061.979,2056.222,248.8656,0,0,0,0,100,0),
(@PATH,18,4080.718,2041.648,241.5903,0,0,0,0,100,0);

-- Pathing for Voidshrieker Entry: 18870
SET @NPC := 67509;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3798.831,`position_y`=1750.282,`position_z`=178.7591 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3798.831,1750.282,178.7591,0,0,0,0,100,0),
(@PATH,2,3832.464,1753.988,196.8661,0,0,0,0,100,0),
(@PATH,3,3861.998,1759.556,211.6918,0,0,0,0,100,0),
(@PATH,4,3884.387,1775.794,220.648,0,0,0,0,100,0),
(@PATH,5,3899.43,1797.509,226.1601,0,0,0,0,100,0),
(@PATH,6,3903.543,1822.17,230.1046,0,0,0,0,100,0),
(@PATH,7,3886.774,1848.648,239.562,0,0,0,0,100,0),
(@PATH,8,3895.88,1866.627,248.396,0,0,0,0,100,0),
(@PATH,9,3897.675,1884.414,252.7833,0,0,0,0,100,0),
(@PATH,10,3882.037,1917.948,254.2183,0,0,0,0,100,0),
(@PATH,11,3897.675,1884.414,252.7833,0,0,0,0,100,0),
(@PATH,12,3895.88,1866.627,248.396,0,0,0,0,100,0),
(@PATH,13,3886.774,1848.648,239.562,0,0,0,0,100,0),
(@PATH,14,3903.543,1822.17,230.1046,0,0,0,0,100,0),
(@PATH,15,3899.43,1797.509,226.1601,0,0,0,0,100,0),
(@PATH,16,3884.387,1775.794,220.648,0,0,0,0,100,0),
(@PATH,17,3862.094,1759.63,211.6694,0,0,0,0,100,0),
(@PATH,18,3832.464,1753.988,196.8661,0,0,0,0,100,0);
