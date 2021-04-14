-- Mountaineer Pebblebitty (creature_template.entry 3836)
SET @ENTRY := 3836;

UPDATE `creature_template` SET `AIName`= "SmartAI", `ScriptName`= '' WHERE `entry`= @ENTRY;

-- Correct gossip_menu_options for Quest 3181 gossip
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (1201,1202,1203,1204,1205,1206) AND `id` = 0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(1201, 0,0, "What's the worst that could happen?", 4266, 1,1, 1202, 0,0,0,'',0),
(1202, 0,0, "Another way? Do tell...",             4268, 1,1, 1203, 0,0,0,'',0),
(1203, 0,0, "Orcs? Badlands? I'm invulnerable!",   4270, 1,1, 1204, 0,0,0,'',0),
(1204, 0,0, "Absolutely!",                         4272, 1,1, 1205, 0,0,0,'',0),
(1205, 0,0, "My apologies, Pebblebitty.",          4274, 1,1, 1206, 0,0,0,'',0),
(1206, 0,0, "Done, done, and done.",               4276, 1,1,    0, 0,0,0,'',0);

-- Link gossip_menu_option.menu_id to npc_text.ID (1201,1833 already in TDB)
DELETE FROM `gossip_menu` WHERE `entry` IN (1202,1203,1204,1205,1206);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(1202,1834),
(1203,1835),
(1204,1836),
(1205,1837),
(1206,1838);

-- Mountaineer Pebblebitty gossip SAI for quest 3181 (gossip has to be closed)
DELETE FROM `smart_scripts` WHERE `entryorguid`= @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,1206,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mountaineer Pebblebitty - on Gossip Menu Option 1206 selected - Close Gossip");

-- Condition for gossip_menu_option 1201 and Quest 3181 (The Horn of the Beast)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup`= 1201;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15, 1201,0, 0,0, 28,0, 3181,0,0, 0,0,0, '', 'Show gossip menu option 1201 only if Quest 3181 is completed');
