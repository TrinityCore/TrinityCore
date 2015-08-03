-- Life or Death (12296)

SET @ENTRY := 27482; -- Wounded Westfall Infantry npc
SET @SOURCETYPE := 0;
SET @CREDIT := 27466; -- Kill Credit Bunny - Wounded Skirmishers npc
SET @ITEM := 37576; -- Renewing Bandage item

DELETE FROM `conditions` WHERE `SourceEntry`=@ITEM;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,0,@ITEM,0,24,1,@ENTRY,0,0,'', "Item Renewing Bandage target Wounded Westfall Infantry");

-- Wounded Westfall Infantry SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,8,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On creature spellhit - Set phasemask 1 - self"),
(@ENTRY,@SOURCETYPE,1,0,1,1,100,0,0,0,3000,3000,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On OOC - Talk - Self"),
(@ENTRY,@SOURCETYPE,2,3,1,1,100,0,2000,2000,2000,2000,53,1,@ENTRY,0,12296,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On OOC Update 2 sec - Start WP 1 - Self"),
(@ENTRY,@SOURCETYPE,3,4,61,1,100,0,0,0,0,0,18,128,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Link - Set unit_flag 128 - Self"),
(@ENTRY,@SOURCETYPE,4,5,61,1,100,0,0,0,0,0,33,@CREDIT,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Link - Give credit - Invoker"),
(@ENTRY,@SOURCETYPE,5,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Link - Set phasemask 2 - Self"),
(@ENTRY,@SOURCETYPE,6,0,40,2,100,0,2,@ENTRY,0,0,41,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On WP 2 - Force despawn - Self");

DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"I'd nearly given up.You've given me new life!",12,0,50,0,0,0,"Wounded Westfall Infantry say text"),
(@ENTRY,0,1,"Bless you, friend.I nearly expired....",12,0,50,0,0,0,"Wounded Westfall Infantry say text"),
(@ENTRY,0,2,"Without your help, I surely would have died....",12,0,50,0,0,0,"Wounded Westfall Infantry say text"),
(@ENTRY,0,3,"Thank you $r.",12,0,50,0,0,0,"Wounded Westfall Infantry say text");

DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,4105.278809,-2917.963867,280.320129,'Wounded Westfall Infantry'),
(@ENTRY,2,4048.682861,-2936.736572,275.191681,'Wounded Westfall Infantry');
