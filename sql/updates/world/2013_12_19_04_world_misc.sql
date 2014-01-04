-- Caelyb <Pet Trainer>
UPDATE `creature_template` SET AIName='' WHERE `entry`=4320;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4320 AND `source_type`=0;

-- Milli Featherwhistle <Mechanostrider Merchant>
UPDATE `creature_template` SET ScriptName='' WHERE `entry`=7955;
-- Add Gossip Options
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (3186);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(3186,0,1, 'I would like to buy from you.',3,128,0);
-- Add Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=3186;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
-- Both of these must be true
(15,3186,0,0,0,16,0,8,0,0,0,0,0, '', 'Gossip Option - Show Option if Player is Gnome'),
(15,3186,0,0,0,5,0,54,128,0,1,0,0, '', 'Gossip Option - Show Option if player is Exalted with Gnomeregan');

-- Murkblood Overseer SAI
SET @ENTRY := 23309;
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,8697,0,0,0,11,41121,0,0,0,0,0,7,0,0,0,0,0,0,0,"Murkblood Overseer - On gossip Option select - cast spell"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,15,11082,0,0,0,0,0,7,0,0,0,0,0,0,0,"Murkblood Overseer - On gossip Option select - Complete quest");
-- Add Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8697;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,8697,0,0,0,9,0,11082,0,0,0,0,0, '', 'Gossip Option - Show Option if Quest 11082 taken');
