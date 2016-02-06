
-- Estelle Gendry - Gossip
DELETE FROM `gossip_menu_option` WHERE (`menu_id`=161 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(161, 0, 0, 'I need another set of thieves'' tools.', 2643, 1, 1, 0, 0, 0, 0, NULL, 0);

-- Estelle Gendry SAI
SET @ENTRY := 6566;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,161,0,0,0,11,9949,2,0,0,0,0,7,0,0,0,0,0,0,0,"Estelle Gendry - On Gossip Option 0 Selected - Invoker Cast 'Thieves' Tool Rack Conjure'"),
(@ENTRY,0,1,0,61,0,100,0,161,0,0,0,72,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Estelle Gendry - On Gossip Option 0 Selected - Close Gossip");


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=161 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(15,161,0,0,0,9,0,1999,0,0,0,"","Show Gossip if player has Quest: Tools of the Trade", 0),
(15,161,0,0,0,2,0,5060,1,1,0,"","Show Gossip if player has not item: Thieves' Tools", 1);
