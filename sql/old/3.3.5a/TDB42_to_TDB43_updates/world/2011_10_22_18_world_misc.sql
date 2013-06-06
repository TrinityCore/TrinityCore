-- Ancient Orc Ancestor SAI
SET @ENTRY := 18688;
SET @SPELL_SOUL_MIRROR := 34063; -- Soul Mirror
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,@SPELL_SOUL_MIRROR,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Ancient Orc Ancestor - On Spellhit - Run Script"),
(@ENTRY,0,1,0,0,0,100,0,20000,40000,60000,180000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ancient Orc Ancestor - Timed - Say Line (random)"),
(@ENTRY,0,2,0,6,0,100,0,0,0,0,0,12,19480,3,120000,0,0,0,1,0,0,0,0,0,0,0,"Ancient Orc Ancestor - On Death - Summon Darkened Spirit"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ancient Orc Ancestor - Script - Say Line (random)"),
(@ENTRY*100,9,1,0,0,0,100,1,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ancient Orc Ancestor - Script - Evade"),
(@ENTRY*100,9,2,0,0,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ancient Orc Ancestor - Script - Prevent Combat Movement"),
(@ENTRY*100,9,3,0,0,0,100,0,2000,2000,0,0,37,19480,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ancient Orc Ancestor - Script - Die");
-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Ancestors watch over you, kind one...",12,0,100,21,0,0,"Ancient Orc Ancestor"),
(@ENTRY,0,1,"Cease your crying! STOP!",12,0,100,21,0,0,"Ancient Orc Ancestor"),
(@ENTRY,0,2,"I remember everything...",12,0,100,21,0,0,"Ancient Orc Ancestor"),
(@ENTRY,0,3,"It cannot be...",12,0,100,21,0,0,"Ancient Orc Ancestor"),
(@ENTRY,0,4,"It comes for you...",12,0,100,21,0,0,"Ancient Orc Ancestor"),
(@ENTRY,1,0,"The spirits call... I am consumed.",12,0,100,21,0,0,"Ancient Orc Ancestor"),
(@ENTRY,1,1,"Cannot control... It draws me in... The void grows...",12,0,100,21,0,0,"Ancient Orc Ancestor"),
(@ENTRY,1,2,"It is dying. It is dying. It is dying.",12,0,100,21,0,0,"Ancient Orc Ancestor"),
(@ENTRY,1,3,"The cold embrace awaits...",12,0,100,21,0,0,"Ancient Orc Ancestor"),
(@ENTRY,1,4,"The pain is unbearable.",12,0,100,21,0,0,"Ancient Orc Ancestor"),
(@ENTRY,1,5,"What is happening to me?",12,0,100,21,0,0,"Ancient Orc Ancestor"),
(@ENTRY,1,6,"What is this trickery? I... ARGH...",12,0,100,21,0,0,"Ancient Orc Ancestor"),
(@ENTRY,1,7,"What will become of us when it falls?",12,0,100,21,0,0,"Ancient Orc Ancestor");

-- Voidwraith SAI
-- These are somehow summoned but can't find any info on sniffs or google..
SET @ENTRY := 18659;
UPDATE `creature_template` SET `AIName`='SmartAI',`faction_A`=91,`faction_H`=91,`dmgschool`=5 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature` SET `MovementType`=0,`spawndist`=0 WHERE `id`=18662; -- Ancestors
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,12,19480,3,120000,0,0,0,1,0,0,0,0,0,0,0,"Voidwraith - On Death - Summon Darkened Spirit");

-- Darkened Spirit SAI
SET @ENTRY := 19480;
SET @SPELL_CONSUMING_SHADOWS := 31293; -- Consuming Shadows
UPDATE `creature_template` SET `AIName`='SmartAI',`faction_A`=91,`faction_H`=91,`dmgschool`=5 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,11000,15000,11,@SPELL_CONSUMING_SHADOWS,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkened Spirit - In Combat - Cast Consuming Shadows"),
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkened Spirit - Force Despawn 5 Seconds After Death"),
(@ENTRY,0,2,0,1,0,100,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Darkened Spirit - Timed - Say Line");
-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"What... What have I become? Arrrgghhh...",12,0,100,21,0,0,"Darkened Spirit");

-- Spell Soul Mirror can only be cast at Ancient Orc Spectator
DELETE FROM `conditions` WHERE `SourceEntry`=34063 AND `ConditionValue2`=18688;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,34063,0,18,1,18688,0,0,'',"Spell Soul Mirror can only be cast at Ancient Orc Spectator");

-- these still need waypoints and proper aura
DELETE FROM `creature` WHERE `id`=18688;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(66946,18688,530,1,1,0,0,-2225.73,8586.74,-10.361,0.261799,300,0,0,6542,0,0,0,0,0),
(66947,18688,530,1,1,0,0,-1452.95,8533.52,12.8692,3.33358,300,0,0,6542,0,0,0,0,0),
(14337,18688,530,1,1,0,0,-1637.01,8569.54,-12.3352,5.65003,300,0,0,6326,0,0,0,0,0),
(14338,18688,530,1,1,0,0,-2300.29,8571.08,-22.0957,5.65003,300,0,0,6326,0,0,0,0,0),
(14339,18688,530,1,1,0,0,-2407.95,8655.04,-19.7505,5.65003,300,0,0,6542,0,0,0,0,0),
(14340,18688,530,1,1,0,0,-2530.94,8629.31,-25.5884,5.65003,300,0,0,6326,0,0,0,0,0),
(14341,18688,530,1,1,0,0,-2571.84,8558.23,-33.6043,5.65003,300,0,0,6542,0,0,0,0,0),
(14342,18688,530,1,1,0,0,-2218.21,8513.48,-17.1368,5.65003,300,0,0,6542,0,0,0,0,0),
(14343,18688,530,1,1,0,0,-2114.42,8743.48,11.699,5.65003,300,0,0,6326,0,0,0,0,0),
(14977,18688,530,1,1,0,0,-2017.31,8743.44,19.5169,5.65003,300,0,0,6542,0,0,0,0,0),
(14978,18688,530,1,1,0,0,-1812.61,8813.18,30.2393,6.13478,300,0,0,6326,0,0,0,0,0),
(14979,18688,530,1,1,0,0,-1750.87,8877.25,31.67,6.13478,300,0,0,6326,0,0,0,0,0),
(14980,18688,530,1,1,0,0,-1539.61,8686.33,24.643,6.13478,300,0,0,6326,0,0,0,0,0),
(14981,18688,530,1,1,0,0,-1653.31,8494.49,-12.8156,6.13478,300,0,0,6542,0,0,0,0,0),
(14982,18688,530,1,1,0,0,-1579.32,8426.67,-9.33804,6.13478,300,0,0,6326,0,0,0,0,0),
(14983,18688,530,1,1,0,0,-1040.87,7895.8,22.8202,6.13478,300,0,0,6326,0,0,0,0,0),
(14984,18688,530,1,1,0,0,-1059.54,7750.35,25.8758,6.13478,300,0,0,6326,0,0,0,0,0),
(14985,18688,530,1,1,0,0,-908.965,7783.44,40.1036,6.13478,300,0,0,6326,0,0,0,0,0),
(20556,18688,530,1,1,0,0,-886.413,7824.75,40.0754,6.13478,300,0,0,6542,0,0,0,0,0),
(21776,18688,530,1,1,0,0,-878.863,7881.25,38.6467,6.13478,300,0,0,6326,0,0,0,0,0),
(23111,18688,530,1,1,0,0,-1866.27,8098.74,-20.3459,6.13478,300,0,0,6542,0,0,0,0,0),
(24670,18688,530,1,1,0,0,-2106.82,8191.13,-15.5604,6.13478,300,0,0,6542,0,0,0,0,0),
(24761,18688,530,1,1,0,0,-2084.75,8286.22,-11.4935,6.13478,300,0,0,6542,0,0,0,0,0),
(24794,18688,530,1,1,0,0,-2206.14,8306.9,-26.191,6.13478,300,0,0,6542,0,0,0,0,0),
(25100,18688,530,1,1,0,0,-2256,8478.68,-24.6155,6.13478,300,0,0,6542,0,0,0,0,0),
(26559,18688,530,1,1,0,0,-2336.12,8477.34,-30.3842,6.13478,300,0,0,6326,0,0,0,0,0),
(26564,18688,530,1,1,0,0,-2350.53,8641.59,-15.5674,6.13478,300,0,0,6326,0,0,0,0,0),
(31807,18688,530,1,1,0,0,-2379.14,8531.65,-28.7321,6.13478,300,0,0,6326,0,0,0,0,0),
(31833,18688,530,1,1,0,0,-2411.61,8492.45,-33.4541,6.13478,300,0,0,6542,0,0,0,0,0),
(32072,18688,530,1,1,0,0,-2416.02,8330.76,-37.6002,6.13478,300,0,0,6542,0,0,0,0,0),
(40475,18688,530,1,1,0,0,-2336.04,8288.74,-36.3567,1.72398,300,0,0,6326,0,0,0,0,0),
(40476,18688,530,1,1,0,0,-2336.11,8225.27,-35.7699,1.72398,300,0,0,6326,0,0,0,0,0),
(40703,18688,530,1,1,0,0,-2258.45,8221.08,-31.2193,3.93488,300,0,0,6326,0,0,0,0,0),
(40716,18688,530,1,1,0,0,-2203.79,8149.55,-25.1002,3.93488,300,0,0,6326,0,0,0,0,0),
(40725,18688,530,1,1,0,0,-2184.8,8029.08,-17.6373,3.93488,300,0,0,6542,0,0,0,0,0),
(40727,18688,530,1,1,0,0,-2297.12,7848.94,-30.4255,3.93488,300,0,0,6326,0,0,0,0,0),
(42893,18688,530,1,1,0,0,-2544.55,7818.57,-45.0012,3.93488,300,0,0,6326,0,0,0,0,0),
(45204,18688,530,1,1,0,0,-2555.36,7930.22,-55.675,3.93488,300,0,0,6542,0,0,0,0,0),
(46570,18688,530,1,1,0,0,-2622.32,7987.03,-48.9066,3.93488,300,0,0,6542,0,0,0,0,0),
(46819,18688,530,1,1,0,0,-2126.06,8148.39,-15.8518,3.93488,300,0,0,6326,0,0,0,0,0);
