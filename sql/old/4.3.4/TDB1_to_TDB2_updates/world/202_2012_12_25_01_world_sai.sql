-- //1// Prevent Whitebark dying before awarding quest - http://old.wowhead.com/quest=10166
-- Closes: https://github.com/TrinityCore/TrinityCore/issues/4840
SET @WHITEBARK := 19456;

-- SAI support
DELETE FROM `smart_scripts` WHERE `entryorguid`=@WHITEBARK  AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@WHITEBARK,0,0,0,54,0,100,0,0,0,0,0,42,0,25,0,0,0,0,1,0,0,0,0,0,0,0,'Whitebark\'s Spirit - On summon - Set invincibility HP at 25%'),
(@WHITEBARK,0,1,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Whitebark\'s Spirit - On aggro (not repeatable) - Say 0'),
(@WHITEBARK,0,2,3,2,0,100,0,24,26,120000,120000,102,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Whitebark\'s Spirit - 24-26% HP - Disable HP reg /video/'),
(@WHITEBARK,0,3,4,61,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Whitebark\'s Spirit - Linked - Set home position'),
(@WHITEBARK,0,4,5,61,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Whitebark\'s Spirit - Linked - Change faction to friendly'),
(@WHITEBARK,0,6,7,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Whitebark\'s Spirit - Linked - Say 1'),
(@WHITEBARK,0,7,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Whitebark\'s Spirit - Linked - evade'),
(@WHITEBARK,0,8,0,0,0,100,0,2500,5500,12000,14500,11,31287,0,0,0,0,0,2,0,0,0,0,0,0,0,'Whitebark\'s Spirit - IC - Casts Entangling Roots'),
(@WHITEBARK,0,9,0,0,0,100,0,7500,7500,9500,16000,11,11442,0,0,0,0,0,2,0,0,0,0,0,0,0,'Whitebark\'s Spirit - IC - Casts Withered Touch'),
(@WHITEBARK,0,10,0,1,0,100,0,60000,60000,60000,60000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Whitebark\'s Spirit - After 60sec OOC - Despawn');

-- Assign creature_text correctly
DELETE FROM `creature_text` WHERE `entry`=@WHITEBARK;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@WHITEBARK,0,0,'Haven\'t you done enough harm? Must you also disturb my slumber?',12,0,100,0,2000,0,'Whitebark\'s Spirit - 19456'),
(@WHITEBARK,1,0,'What good does this violence serve? What is done is done. I have failed my people.',12,0,100,0,1000,0,'Whitebark\'s Spirit - 19456');

-- //2// Change quest end npc for http://www.wowhead.com/quest=24872/respite-for-a-tormented-soul
-- Closes: https://github.com/TrinityCore/TrinityCore/issues/6478
-- UPDATE `creature_involvedrelation` SET `id`=38017 WHERE `id`=38589 AND `quest`=24872; 4.x
-- UPDATE `creature_template` SET `npcflag`=0x00000002 WHERE `entry`=38017; -- add quest giver flag - 4.x
