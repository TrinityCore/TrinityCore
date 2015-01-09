-- Zanza's Potent Potables
UPDATE `quest_template` SET `RequestItemsText`='With your increased status amongst the tribe comes access to some of our more potent potables. Behold... these brews are strong in the mojo - blessed by Zanza and fit for adventurers from all walks of life!$B$BI will allow you to choose one from the three I offer; in exchange, I require one Zandalar Honor Token. Note that only the effects of a single one may course through your spirit at any given time.$B$BLet me know when you''re ready to barter!' WHERE `entry`=8243;

-- Essence Mangoes
UPDATE `quest_template` SET `RequestItemsText`='The extremely potent essence mango grows across many of the islands in the South Seas. A single mango will refresh those who eat it,both physically and mentally. If you''ve never had one,you do yourself a disservice!$B$BWe have enough of a supply here on the isle to offer you a handful in exchange for a Zandalar Honor Token. Speak with Vinchaxa if you need to learn how to get tokens; otherwise, let''s get to the business at hand!' WHERE `entry`=8196;

-- Signets of the Zandalar
UPDATE `quest_template` SET `RequestItemsText`='$N - for someone as exalted among the Zandalar as you are,I have something very special for you. Direct from our home in the South Seas... the Signets of the Zandalar! These signets are used to enhance any shoulder item you may possess. Should you seek might,mojo,or serenity - I have what you need!$B$BI ask for fifteen Zandalar Honor Tokens in exchange for your choice of one signet. If you have the tokens ready,then I''m ready to make a deal!' WHERE `entry`=8246;

-- Zandalar Headhsrinkers
UPDATE `creature` SET `position_x`=-11786.887695,`position_y`=1253.674072,`position_z`=0.959927,`orientation`=2.357351 WHERE `guid`=285;
UPDATE `creature` SET `position_x`=-11750.439453,`position_y`=1309.479858,`position_z`=2.551236,`orientation`=4.998511 WHERE `guid`=283;
UPDATE `creature` SET `MovementType`=0,`spawndist`=0 WHERE `guid` IN (285,283,284,280);

-- One missing Zandalar Headhsrinker spawn
-- This was the best guid I could find which was not in use
DELETE FROM `creature` WHERE `guid`=200615 AND `id`=14876;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(200615,14876,0,1,1,14998,0,-11775.231445,1358.505981,0.776265,1.409376,1800,0,0,7326,2434,2,0,0,0);

-- Set Zandalar Enforcer's home position next to cage
UPDATE `creature` SET `position_x`=-11834.728516,`position_y`=1257.751221,`position_z`=2.153508,`orientation`=5.568032 WHERE `guid`=314;

-- Set Captured Hakkari Zealot's home position in cage
UPDATE `creature` SET `position_x`=-11838.209961,`position_y`=1256.006836,`position_z`=2.081958,`orientation`=5.776157 WHERE `guid`=2368;
DELETE FROM `creature_addon` WHERE `guid`=2368; -- Remove kneel from Zealot, happens in conversation

-- Make Exzhal face his object, he faces Captured Hakkari Zealot in conversation
UPDATE `creature` SET `orientation`=5.821840 WHERE `guid`=312;

-- Remove Circle of Binding - should be summoned in conversation between Exzhal and Captured Hakkari Zealot
DELETE FROM `gameobject` WHERE `guid`=12165;

-- Molthor SAI
SET @ENTRY := 14875;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Molthor - On Gossip Hello - Play Emote Cheer");

-- Zandalar Headshrinker: 14876
SET @GUID := 287;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-11829.594727,`position_y`=1269.249512,`position_z`=1.430709,`orientation`=1.842991 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11835.188477,1288.131714,1.291541,0,0,0,100,0),
(@PATH,2,-11829.594727,1269.249512,1.430709,0,0,0,100,0),
(@PATH,3,-11823.579102,1251.472412,2.542836,0,0,0,100,0),
(@PATH,4,-11823.824219,1252.372681,2.492942,0,0,0,100,0),
(@PATH,5,-11814.262695,1246.662720,2.205406,0,0,0,100,0),
(@PATH,6,-11791.875977,1262.220703,1.538649,0,0,0,100,0),
(@PATH,7,-11766.643555,1275.045776,3.064182,0,0,0,100,0),
(@PATH,8,-11791.875977,1262.220703,1.538649,0,0,0,100,0),
(@PATH,9,-11814.262695,1246.662720,2.205406,0,0,0,100,0),
(@PATH,10,-11823.824219,1252.372681,2.492942,0,0,0,100,0),
(@PATH,11,-11823.579102,1251.472412,2.542836,0,0,0,100,0),
(@PATH,12,-11829.594727,1269.249512,1.430709,0,0,0,100,0),
(@PATH,13,-11835.188477,1288.131714,1.291541,0,0,0,100,0);

-- Zandalar Headshrinker: 14876
SET @GUID := 286;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-11832.375977,`position_y`=1271.938721,`position_z`=1.459813,`orientation`=1.842991 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11837.279297,1288.950317,1.512615,0,0,0,100,0),
(@PATH,2,-11832.375977,1271.938721,1.459813,0,0,0,100,0),
(@PATH,3,-11825.054688,1251.701782,2.429044,0,0,0,100,0),
(@PATH,4,-11823.474609,1249.535645,2.501543,0,0,0,100,0),
(@PATH,5,-11813.486328,1243.423096,1.650653,0,0,0,100,0),
(@PATH,6,-11809.788086,1243.615967,1.399789,0,0,0,100,0),
(@PATH,7,-11794.386719,1257.631592,1.222988,0,0,0,100,0),
(@PATH,8,-11789.625000,1260.664429,1.522318,0,0,0,100,0),
(@PATH,9,-11764.781250,1273.674072,2.998039,0,0,0,100,0),
(@PATH,10,-11789.625000,1260.664429,1.522318,0,0,0,100,0),
(@PATH,11,-11794.386719,1257.631592,1.222988,0,0,0,100,0),
(@PATH,12,-11809.788086,1243.615967,1.399789,0,0,0,100,0),
(@PATH,13,-11813.486328,1243.423096,1.650653,0,0,0,100,0),
(@PATH,14,-11823.474609,1249.535645,2.501543,0,0,0,100,0),
(@PATH,15,-11825.054688,1251.701782,2.429044,0,0,0,100,0),
(@PATH,16,-11832.375977,1271.938721,1.459813,0,0,0,100,0),
(@PATH,17,-11837.279297,1288.950317,1.512615,0,0,0,100,0);

-- Zandalar Headshrinker: 14876
SET @GUID := 282;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-11828.326172,`position_y`=1234.463989,`position_z`=0.780894,`orientation`=5.261924 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11824.317383,1227.511108,0.670448,0,0,0,100,0),
(@PATH,2,-11839.237305,1241.058105,1.519958,0,0,0,100,0),
(@PATH,3,-11846.645508,1243.729980,4.5744192,0,0,0,100,0),
(@PATH,4,-11841.049805,1260.212158,10.099603,0,0,0,100,0),
(@PATH,5,-11841.225586,1264.016235,11.571445,0,0,0,100,0),
(@PATH,6,-11842.425781,1267.932251,12.456536,0,0,0,100,0),
(@PATH,7,-11846.776367,1270.782959,14.125699,0,0,0,100,0),
(@PATH,8,-11850.278320,1271.012329,15.261613,0,0,0,100,0),
(@PATH,9,-11853.373047,1268.856567,16.700747,0,0,0,100,0),
(@PATH,10,-11855.116211,1264.943848,18.011517,0,0,0,100,0),
(@PATH,11,-11857.451172,1254.989014,21.714193,0,0,0,100,0),
(@PATH,12,-11851.708008,1250.510010,21.714193,0,0,0,100,0),
(@PATH,13,-11857.451172,1254.989014,21.714193,0,0,0,100,0),
(@PATH,14,-11855.116211,1264.943848,18.011517,0,0,0,100,0),
(@PATH,15,-11853.373047,1268.856567,16.700747,0,0,0,100,0),
(@PATH,16,-11850.278320,1271.012329,15.261613,0,0,0,100,0),
(@PATH,17,-11846.776367,1270.782959,14.125699,0,0,0,100,0),
(@PATH,18,-11842.425781,1267.932251,12.456536,0,0,0,100,0),
(@PATH,19,-11841.225586,1264.016235,11.571445,0,0,0,100,0),
(@PATH,20,-11841.049805,1260.212158,10.099603,0,0,0,100,0),
(@PATH,21,-11846.645508,1243.729980,4.5744192,0,0,0,100,0),
(@PATH,22,-11839.237305,1241.058105,1.519958,0,0,0,100,0),
(@PATH,23,-11824.317383,1227.511108,0.670448,0,0,0,100,0);

-- Hakkari Oracle: 14876
SET @GUID := 748;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-11915.200195,`position_y`=-943.197021,`position_z`=52.455700,`orientation`=1.575122 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11915.455078,-884.229614,32.811508,10000,0,0,100,0),
(@PATH,2,-11915.200195,-943.197021,52.455700,0,0,0,100,0),
(@PATH,3,-11915.335938,-971.741028,62.940353,0,0,0,100,0),
(@PATH,4,-11915.582031,-997.877869,67.938759,0,0,0,100,0),
(@PATH,5,-11915.845703,-1047.903076,69.805588,0,0,0,100,0),
(@PATH,6,-11915.582031,-997.877869,67.938759,0,0,0,100,0),
(@PATH,7,-11915.335938,-971.741028,62.940353,0,0,0,100,0),
(@PATH,8,-11915.200195,-943.197021,52.455700,0,0,0,100,0);

-- Hakkari Oracle SAI
SET @ENTRY := 11346;
SET @SPELL_EARTH_SHOCK := 15501; -- Earth Shock
SET @SPELL_CHAIN_LIGHTNING := 16006; -- Chain Lightning
SET @SPELL_HEALING_WAVE := 15982; -- Healing Wave
UPDATE `creature_template` SET `AIName`='SmartAI',`spell1`=0,`spell2`=0,`spell3`=0,`spell4`=0 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,12000,15000,11,@SPELL_CHAIN_LIGHTNING,0,0,0,0,0,2,0,0,0,0,0,0,0,'Hakkari Oracle - In Combat - Cast Chain Lightning'),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,19000,20000,11,@SPELL_EARTH_SHOCK,0,0,0,0,0,2,0,0,0,0,0,0,0,'Hakkari Oracle - In Combat - Cast Earth Shock'),
(@ENTRY,0,2,0,2,0,100,1,0,50,0,0,11,@SPELL_HEALING_WAVE,1,0,0,0,0,1,0,0,0,0,0,0,0,'Hakkari Oracle - At 50% HP - Cast Healing Wave');

-- Gurubashi Warrior SAI
SET @ENTRY := 11355;
SET @SPELL_KNOCKDOWN := 11428; -- Knockdown
SET @SPELL_ENRAGE := 8599; -- Enrage
UPDATE `creature_template` SET `AIName`='SmartAI',`spell1`=0,`spell2`=0,`spell3`=0,`spell4`=0,`mechanic_immune_mask`=1 WHERE `entry`=@ENTRY; -- Immune to charm effects (mind control)
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,12000,15000,11,@SPELL_KNOCKDOWN,0,0,0,0,0,2,0,0,0,0,0,0,0,'Gurubashi Warrior - In Combat - Cast Knockdown'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,@SPELL_ENRAGE,1,0,0,0,0,1,0,0,0,0,0,0,0,'Gurubashi Warrior - At 30% HP - Cast Enrage'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Gurubashi Warrior - At 30% HP - Say Line 0');
-- Enrage text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'%s becomes enraged!',16,0,100,0,0,0,'Gurubashi Warrior - At 30% HP - Say Line 0');

-- High Priestess Hai'watna SAI
SET @ENTRY := 11383;
SET @SPELL_SHADOW_BOLT_VOLLEY := 14887; -- Shadow Bolt Volley
SET @SPELL_HEAL := 15586; -- Heal
UPDATE `creature_template` SET `AIName`='SmartAI',`spell1`=0,`spell2`=0,`spell3`=0,`spell4`=0 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,12000,15000,11,@SPELL_SHADOW_BOLT_VOLLEY,0,0,0,0,0,2,0,0,0,0,0,0,0,'High Priestess Haiwatna - In Combat - Cast Shadow Bolt Volley'),
(@ENTRY,0,1,0,0,0,100,0,20000,25000,29000,31000,11,@SPELL_HEAL,0,0,0,0,0,1,0,0,0,0,0,0,0,'High Priestess Haiwatna - In Combat - Cast Heal');
