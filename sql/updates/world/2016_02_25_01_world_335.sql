-- new gossip_menus for Quest 5742 Redemption (Tirion's Tale)
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (3502,3681,3682,3683) AND `id` = 0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(3502, 0,0, 'I am ready to hear your tale, Tirion.',     7219, 1,1, 3681, 0,0,0,'',0),
(3681, 0,0, 'Thank you, Tirion. What of your identity?', 7221, 1,1, 3682, 0,0,0,'',0),
(3682, 0,0, 'That is terrible.',                         7223, 1,1, 3683, 0,0,0,'',0),
(3683, 0,0, 'I will, Tirion.',                           7225, 1,1,    0, 0,0,0,'',0);

-- update creature entry 1855 Tirion Fordring
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName`= '' WHERE `entry` = 1855;

-- SmartAI script actions for Quest 5742 Redemption (Tirion's Tale)
DELETE FROM `smart_scripts` WHERE `entryorguid`= 1855 AND `source_type`= 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1855,0, 0,0, 62, 0,100,0, 3502, 0,0,0, 98, 3681, 4493, 0,0,0,0, 7,0,0,0,0,0,0,0, 'Tirion Fordring - on gossip_menu 3502 selected - Send Gossip text 4493 with menu option 3681'),
(1855,0, 1,0, 62, 0,100,0, 3681, 0,0,0, 98, 3682, 4494, 0,0,0,0, 7,0,0,0,0,0,0,0, 'Tirion Fordring - on gossip_menu 3681 selected - Send Gossip text 4494 with menu option 3682'),
(1855,0, 2,0, 62, 0,100,0, 3682, 0,0,0, 98, 3683, 4495, 0,0,0,0, 7,0,0,0,0,0,0,0, 'Tirion Fordring - on gossip_menu 3682 selected - Send Gossip text 4495 with menu option 3683'),
(1855,0, 3,4, 62, 0,100,0, 3683, 0,0,0, 15, 5742,    0, 0,0,0,0, 7,0,0,0,0,0,0,0, 'Tirion Fordring - on gossip_menu 3683 selected - Give credit for Quest 5742 Redemption'),
(1855,0, 4,0, 61, 0,100,0,    0, 0,0,0, 72,    0,    0, 0,0,0,0, 7,0,0,0,0,0,0,0, 'Tirion Fordring - on gossip_menu 3683 selected - Close Gossip');

-- conditions for Quest 5742 Redemption (Tirion's Tale)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup`= 3502;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15, 3502,0, 0,1,  9,0, 5742, 0,0,0,0,0, '', 'Show gossip menu option 3502 only if Quest 5742 is taken (active)'),
(15, 3502,0, 0,1, 41,0,    1, 1,0,0,0,0, '', 'Show gossip menu option 3502 only if player is sitting (any type)');
