-- Add sniffed gossip text to menu
DELETE FROM `gossip_menu_option` WHERE `menu_id` = 8207;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(8207, 0, 0, 'I need a new phase disruptor, Professor.', 18635,1,1,0,0,0,0,'',0);

-- Migrate NPC to use SmartAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 20907;

-- Create SmartAI for Dabiri
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 20907);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20907,0, 0, 1, 62, 0, 100, 0, 8207, 0,0,0, 85, 35780, 0,0,0,0,0, 7, 0,0,0,0,0,0,0, "Professor Dabiri - On Gossip Option 0 Selected - Invoker Cast 'Summon Phase Disruptor'"),
(20907,0, 1, 0, 61, 0, 100, 0,    0, 0,0,0, 72,     0, 0,0,0,0,0, 7, 0,0,0,0,0,0,0, 'Professor Dabiri - On Linked Actions - Close Gossip');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 8207;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8207,0,0,0,2,0,29778,1,0,1,0,'','Professor Dabiri - Show gossip option 0 if player does not have item 29778 in inventory'),
(15,8207,0,0,0,9,0,10438,0,0,0,0,'','Professor Dabiri - Show gossip option 0 if player has accepted quest 10438');
