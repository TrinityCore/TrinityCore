-- [Q] Arelion's Mistress
-- Viera Sunwhisper SAI
-- Twinkle SAI
SET @ENTRY_VIERA := 17226;
SET @ENTRY_TWINKLE := 17230;
SET @QUEST_PLEASURES := 9483;
SET @SPELL_RETRIBUTION := 30077;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@ENTRY_VIERA,@ENTRY_TWINKLE);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY_VIERA,@ENTRY_TWINKLE,@ENTRY_VIERA*100,@ENTRY_VIERA*100+1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY_VIERA,0,0,0,20,0,100,0,@QUEST_PLEASURES,0,0,0,80,@ENTRY_VIERA*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Viera Sunwhisper - On Quest Finish - Run Script'),
(@ENTRY_VIERA*100,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Viera Sunwhisper - On Script - Remove Quest Flag"),
(@ENTRY_VIERA*100,9,1,0,0,0,100,0,2000,2000,0,0,53,0,@ENTRY_VIERA,0,0,0,0,1,0,0,0,0,0,0,0,'Viera Sunwhisper - On Script - Start WP 1'),
(@ENTRY_VIERA*100,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Viera Sunwhisper - On Script - Say Line 0'),
(@ENTRY_VIERA*100,9,3,0,0,0,100,0,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Viera Sunwhisper - On Script - Stand Up'),
(@ENTRY_VIERA*100,9,4,0,0,0,100,0,6500,6500,0,0,45,0,1,0,0,0,0,10,61963,@ENTRY_TWINKLE,0,0,0,0,0,'Viera Sunwhisper - On Script - Set Data 0 1 Twinkle'),
(@ENTRY_VIERA,0,1,2,40,0,100,0,10,@ENTRY_VIERA,0,0,66,0,0,0,0,0,0,11,@ENTRY_TWINKLE,15,0,0,0,0,0,'Viera Sunwhisper - On WP 10 - Face Twinkle'),
(@ENTRY_VIERA,0,2,0,61,0,100,0,0,0,0,0,54,1000000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Viera Sunwhisper - On WP 10 - Pause WP'),

(@ENTRY_TWINKLE,0,0,0,38,0,100,0,0,1,0,0,53,1,@ENTRY_TWINKLE,0,0,0,0,1,0,0,0,0,0,0,0,'Twinkle - On Data 0 1 Set - Start WP 1 (run)'),
(@ENTRY_TWINKLE,0,1,0,40,0,100,0,13,@ENTRY_TWINKLE,0,0,54,1000000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Twinkle - On WP 13 - Pause WP'),
(@ENTRY_TWINKLE,0,2,0,38,0,100,0,1,2,0,0,53,1,@ENTRY_TWINKLE*10,0,0,0,0,1,0,0,0,0,0,0,0,'Twinkle - On Data Set 1 2 - Start WP 2 (run)'),
(@ENTRY_TWINKLE,0,3,0,40,0,100,0,4,@ENTRY_TWINKLE*10,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Viera Sunwhisper - On WP 4 (2) - Force Despawn'),

(@ENTRY_VIERA,0,3,0,8,0,100,0,@SPELL_RETRIBUTION,0,0,0,80,@ENTRY_VIERA*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Viera Sunwhisper - On Spellhit - Run Second Script'),
(@ENTRY_VIERA*100+1,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Viera Sunwhisper - On Script - Say Line 1'),
(@ENTRY_VIERA*100+1,9,1,0,0,0,100,0,0,0,0,0,33,@ENTRY_VIERA,0,0,0,0,0,7,0,0,0,0,0,0,0,'Viera Sunwhisper - On Script - Quest Credit'),
(@ENTRY_VIERA*100+1,9,2,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Viera Sunwhisper - On Script - Say Line 2'),
(@ENTRY_VIERA*100+1,9,3,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,9,@ENTRY_TWINKLE,0,25,0,0,0,0,'Twinkle - On Script - Say Line 0'),
(@ENTRY_VIERA*100+1,9,4,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Viera Sunwhisper - On Script - Say Line 3'),
(@ENTRY_VIERA*100+1,9,5,0,0,0,100,0,0,0,0,0,45,1,2,0,0,0,0,10,61963,@ENTRY_TWINKLE,0,0,0,0,0,'Viera Sunwhisper - On Script - Set Data 1 2 Twinkle'),
(@ENTRY_VIERA*100+1,9,6,0,0,0,100,0,0,0,0,0,53,1,@ENTRY_VIERA*10,0,0,0,0,1,0,0,0,0,0,0,0,'Viera Sunwhisper - On Script - Start WP 2 (run)'),
(@ENTRY_VIERA,0,4,0,40,0,100,0,4,@ENTRY_VIERA*10,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Viera Sunwhisper - On WP 4 (2) - Force Despawn');

-- Waypoints for Viera Sunwhisper
DELETE FROM `waypoints` WHERE `entry` IN (@ENTRY_VIERA,@ENTRY_VIERA*10);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY_VIERA,1,-653.739197,4145.138184,64.200729,'Viera Sunwhisper'),
(@ENTRY_VIERA,2,-658.875732,4147.715332,64.168304,'Viera Sunwhisper'),
(@ENTRY_VIERA,3,-681.465088,4147.636230,64.118073,'Viera Sunwhisper'),
(@ENTRY_VIERA,4,-686.400696,4161.865234,59.707859,'Viera Sunwhisper'),
(@ENTRY_VIERA,5,-695.956909,4179.237305,57.618931,'Viera Sunwhisper'),
(@ENTRY_VIERA,6,-699.832153,4189.959473,57.503750,'Viera Sunwhisper'),
(@ENTRY_VIERA,7,-708.518616,4184.436035,55.275894,'Viera Sunwhisper'),
(@ENTRY_VIERA,8,-716.137268,4178.130371,52.637508,'Viera Sunwhisper'),
(@ENTRY_VIERA,9,-719.865295,4174.992676,51.554867,'Viera Sunwhisper'),
(@ENTRY_VIERA,10,-720.839417,4162.232422,50.805923,'Viera Sunwhisper'),

(@ENTRY_VIERA*10,1,-722.323486,4147.936523,50.337898,'Viera Sunwhisper'),
(@ENTRY_VIERA*10,2,-726.639343,4125.156250,48.479683,'Viera Sunwhisper'),
(@ENTRY_VIERA*10,3,-727.648315,4109.684082,47.528461,'Viera Sunwhisper'),
(@ENTRY_VIERA*10,4,-727.874329,4093.438721,46.446579,'Viera Sunwhisper');

-- Waypoints for Twinkle
DELETE FROM `waypoints` WHERE `entry` IN (@ENTRY_TWINKLE,@ENTRY_TWINKLE*10);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY_TWINKLE,1,-605.445190,4165.205078,64.081802,'Twinkle'),
(@ENTRY_TWINKLE,2,-619.293335,4161.776855,63.217815,'Twinkle'),
(@ENTRY_TWINKLE,3,-629.536560,4153.708984,64.067123,'Twinkle'),
(@ENTRY_TWINKLE,4,-644.773438,4151.062988,64.174675,'Twinkle'),
(@ENTRY_TWINKLE,5,-658.875732,4147.715332,64.168304,'Twinkle'),
(@ENTRY_TWINKLE,6,-681.465088,4147.636230,64.118073,'Twinkle'),
(@ENTRY_TWINKLE,7,-686.400696,4161.865234,59.707859,'Twinkle'),
(@ENTRY_TWINKLE,8,-695.956909,4179.237305,57.618931,'Twinkle'),
(@ENTRY_TWINKLE,9,-699.832153,4189.959473,57.503750,'Twinkle'),
(@ENTRY_TWINKLE,10,-708.518616,4184.436035,55.275894,'Twinkle'),
(@ENTRY_TWINKLE,11,-716.137268,4178.130371,52.637508,'Twinkle'),
(@ENTRY_TWINKLE,12,-719.865295,4174.992676,51.554867,'Twinkle'),
(@ENTRY_TWINKLE,13,-720.636292,4166.637695,50.815567,'Twinkle'),

(@ENTRY_TWINKLE*10,1,-722.323486,4147.936523,50.337898,'Twinkle'),
(@ENTRY_TWINKLE*10,2,-726.639343,4125.156250,48.479683,'Twinkle'),
(@ENTRY_TWINKLE*10,3,-727.648315,4109.684082,47.528461,'Twinkle'),
(@ENTRY_TWINKLE*10,4,-727.874329,4093.438721,46.446579,'Twinkle');

-- Spawn spell focus object on correct position
DELETE FROM `gameobject` WHERE `id`=300071 AND `guid`=303;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(303,300071,530,1,1,-720.803,4162.77,50.7916,4.61029,0,0,0.742267,-0.670104,300,0,1);

-- Texts
DELETE FROM `creature_text` WHERE `entry` IN (@ENTRY_VIERA,@ENTRY_TWINKLE);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY_VIERA,0,0,"Ok, let's go. I know just the perfect spot!",12,0,100,0,0,0,'Viera Sunwhisper'),
(@ENTRY_VIERA,1,0,"I can't wait to try this wine!",12,0,100,0,0,0,'Viera Sunwhisper'),
(@ENTRY_VIERA,2,0,"What... is happening... to me? Get this cat away from me!",12,0,100,0,0,0,'Viera Sunwhisper'),
(@ENTRY_VIERA,3,0,"%s scurries away, attempting to flee from Twinkle",16,0,100,0,0,0,'Viera Sunwhisper'),

(@ENTRY_TWINKLE,0,0,"%s looks at Viera Sunwhisper with very hungry eyes",16,0,100,0,0,0,'Twinkle');
