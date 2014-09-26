SET @ENTRY := 8612;

-- Add missing gossip (by Malcrom)
DELETE FROM `gossip_menu` WHERE `entry`=1405;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1405,2039);
UPDATE `creature_template` SET `gossip_menu_id`=1405 WHERE entry=@ENTRY;

-- SAI (by Rushor)
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,64,0,100,0,0,0,0,0,33,8612,0,0,0,0,0,7,0,0,0,0,0,0,0,"Screecher Spirit - On Gossip Hello - Quest Credit 'Screecher Spirits'"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Screecher Spirit - On Gossip Hello - Set Flag Not Selectable"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Screecher Spirit - On Gossip Hello - Despawn In 3000 ms");
