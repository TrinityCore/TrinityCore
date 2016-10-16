-- Bunthen Plainswind (NPC 11798) and Silva Fil'naveth (NPC 11800), Moonglade Druid Flight Masters
UPDATE `creature_template` SET `AIName`= 'SmartAI', `ScriptName`= '' WHERE `entry` IN (11798,11800);

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (4041,4042);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(4041,0,0,"I'd like to fly to Rut'theran Village.",                             7573,1,1,   0,0,0,0,'',0),
(4041,1,0,"Do you know where I may find the Half Pendant of Aquatic Agility?",  8035,1,1,4225,0,0,0,'',0),
(4041,2,0,"Do you know where I may find the Half Pendant of Aquatic Agility?",  8035,1,1,4226,0,0,0,'',0),
(4042,0,0,"I'd like to fly to Thunder Bluff.",                                 12804,1,1,   0,0,0,0,'',0),
(4042,1,0,"Do you know where I may find the Half Pendant of Aquatic Endurance?",8036,1,1,4223,0,0,0,'',0),
(4042,2,0,"Do you know where I may find the Half Pendant of Aquatic Endurance?",8036,1,1,4224,0,0,0,'',0);

-- Add gossip_menu entries to be linked to text_id gossip text (npc_text.id)
DELETE FROM `gossip_menu` WHERE `text_id` IN (4917,4918,5373,5374,5375,5376);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(4042,4917),
(4042,4918),
(4223,5373),
(4224,5374),
(4225,5375),
(4226,5376);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup` IN (4041,4042);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- conditions for Silva's gossip menus
(14,4041,4913,0, 0, 15,0,1024,0,0, 1, 0,0,'', "Show Gossip Menu entry 4041 text_id 4913 if player is NOT a Druid"),
(14,4041,4914,0, 1, 15,0,1024,0,0, 0, 0,0,'', "Show Gossip Menu entry 4041 text_id 4914 if player is a Druid"),
(14,4041,4914,0, 1,  6,0, 469,0,0, 0, 0,0,'', "Show Gossip Menu entry 4041 text_id 4914 if player is Alliance"),
(14,4041,4915,0, 2, 15,0,1024,0,0, 0, 0,0,'', "Show Gossip Menu entry 4041 text_id 4915 if player is a Druid"),
(14,4041,4915,0, 2,  6,0, 469,0,0, 1, 0,0,'', "Show Gossip Menu entry 4041 text_id 4915 if player is NOT Alliance"),
(15,4041,   0,0, 3, 15,0,1024,0,0, 0, 0,0,'', "Show Gossip Menu Option menu_id 4041 id 0 if player is a Druid"),
(15,4041,   0,0, 3,  6,0, 469,0,0, 0, 0,0,'', "Show Gossip Menu Option menu_id 4041 id 0 if player is Alliance"),
(15,4041,   1,0, 0,  9,0, 272,0,0, 0, 0,0,'', "Show Gossip Menu Option menu_id 4041 id 1 if Quest 272 is taken"),
(15,4041,   2,0, 0,  9,0,  30,0,0, 0, 0,0,'', "Show Gossip Menu Option menu_id 4041 id 2 if Quest 30 is taken"),
-- conditions for Bunthen's gossip menus
(14,4042,4916,0, 0, 15,0,1024,0,0, 1, 0,0,'', "Show Gossip Menu entry 4042 text_id 4916 if player is NOT a Druid"),
(14,4042,4918,0, 4, 15,0,1024,0,0, 0, 0,0,'', "Show Gossip Menu entry 4042 text_id 4918 if player is a Druid"),
(14,4042,4918,0, 4,  6,0,  67,0,0, 0, 0,0,'', "Show Gossip Menu entry 4042 text_id 4918 if player is Horde"),
(14,4042,4917,0, 5, 15,0,1024,0,0, 0, 0,0,'', "Show Gossip Menu entry 4042 text_id 4917 if player is a Druid"),
(14,4042,4917,0, 5,  6,0,  67,0,0, 1, 0,0,'', "Show Gossip Menu entry 4042 text_id 4917 if player is NOT Horde"),
(15,4042,   0,0, 6, 15,0,1024,0,0, 0, 0,0,'', "Show Gossip Menu Option menu_id 4042 id 0 if player is a Druid"),
(15,4042,   0,0, 6,  6,0,  67,0,0, 0, 0,0,'', "Show Gossip Menu Option menu_id 4042 id 0 if player is Horde"),
(15,4042,   1,0, 0,  9,0, 272,0,0, 0, 0,0,'', "Show Gossip Menu Option menu_id 4042 id 1 if Quest 272 is taken"),
(15,4042,   2,0, 0,  9,0,  30,0,0, 0, 0,0,'', "Show Gossip Menu Option menu_id 4042 id 2 if Quest 30 is taken");

-- SmartAI for Bunthen & Silva
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (11798, 11800) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(11798,0,0,1,62,0,100,0,4042,0,0,0,72,  0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bunthen Plainswind - on Gossip Menu Option 4042 id 0 selected - close Gossip"),
(11798,0,1,0,61,0,100,0,   0,0,0,0,52,316,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bunthen Plainswind - on Gossip Menu Option 4042 id 0 selected - activate Taxi Path 316(Moonglade - Thunder Bluff)"),
(11800,0,2,3,62,0,100,0,4041,0,0,0,72,  0,0,0,0,0,0,7,0,0,0,0,0,0,0,  "Silva Fil'naveth - on Gossip Menu Option 4041 id 0 selected - close Gossip"),
(11800,0,3,0,61,0,100,0,   0,0,0,0,52,315,0,0,0,0,0,7,0,0,0,0,0,0,0,  "Silva Fil'naveth - on Gossip Menu Option 4041 id 0 selected - activate Taxi Path 315(Moonglade - Rut'theran Village)");
