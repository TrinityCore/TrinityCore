-- Highlord Demitrian SAI
SET @ENTRY := 14347;
UPDATE `creature_template` SET `gossip_menu_id`=5689, `AIName`='SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,5704,0,0,0,56,19016,1,0,0,0,0,7,0,0,0,0,0,0,0,"Highlord Demitrian - On Gossip Select - Add item Vessel of Rebirth to player"),
(@ENTRY,0,1,0,20,0,100,0,7786,0,0,0,12,14435,2,0,0,0,0,7,0,0,0,0,0,0,0,"Highlord Demitrian - On Quest Thunderaan the Windseeker rewarded - Summon creature");
-- Add Gossip
DELETE FROM `gossip_menu` WHERE `entry` IN (5675,5687,5688,5689,5701,5702,5703,5704);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(5675,6812),(5687,6844),(5688,6843),(5689,6842),(5701,6868),(5702,6867),(5703,6870),(5704,6869);
-- Add Gossip Options
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (5675,5687,5688,5689,5701,5702,5704);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(5675,0,0, 'What do you know of it?',1,1,5689),
(5689,0,0, 'I am listening, Demitrian.',1,1,5688),
(5688,0,0, 'Continue, please.',1,1,5687),
(5687,0,0, 'A battle?',1,1,5702),
(5702,0,0, '<Nod>',1,1,5701),
(5701,0,0, 'Caught unaware? How?',1,1,5704),
(5704,0,0, 'So what did Ragnaros do next?',1,1,5703);
-- Add Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=5675;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
-- Both of these must be true
(15,5675,0,0,0,14,0,7785,0,0,0,0,0, '', 'Gossip Option - Show Option if Quest 7785 is not taken'),
(15,5675,0,0,1,2,0,19016,1,0,1,0,0, '', 'Gossip Option - Show Option if player does not have Vessel of Rebirth'),
-- One of these must be true
(15,5675,0,0,2,2,0,18563,1,0,1,0,0, '', 'Gossip Option - Show Option if player has Bindings of the Windseeker'),
(15,5675,0,0,2,2,0,18564,1,0,1,0,0, '', 'Gossip Option - Show Option if player has Bindings of the Windseeker');
