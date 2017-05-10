-- Augmented Arcane Prison
DELETE FROM `gossip_menu_option` WHERE `menu_id` in(9253);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(9253, 0, 0, 'I seem to have lost the Augmented Arcane Prison. Did I leave it here with you?', 25369, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN(9253);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 9253, 0, 0, 0, 8, 0, 11943, 0, 0, 0, 0, 0, '', 'Gossip Option requires The Cell Rewarded'),
(15, 9253, 0, 0, 0, 2, 0, 35671, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not Augmented Arcane Prison'),
(15, 9253, 0, 0, 0, 8, 0, 11967, 0, 0, 1, 0, 0, '', 'Gossip Option requires Mustering the Reds not rewarded');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(26117);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(26117) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26117,0,0,1,62,0,100,0,9253,0,0,0,85,46764,2,0,0,0,0,7,0,0,0,0,0,0,0,'Raelorasz - On Gossip Option 0 Selected - Invoker cast Push Arcane Prison'),
(26117,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Raelorasz - Link - Close Gossip');

-- Spectrecles
DELETE FROM `gossip_menu_option` WHERE `menu_id` in(8383,8392);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(8383, 1, 0, 'Hildagard, I need a new pair of goggles.', 19443, 1, 1, 0, 0, 0, 0, '', 0), -- Spectrecles T2
(8392, 0, 0, 'Zorus, I need a new pair of goggles.', 19564, 1, 1, 0, 0, 0, 0, '', 0), -- Spectrecles T1
(8383, 0, 0, 'Hildagard, I need a new pair of goggles.', 19443, 1, 1, 0, 0, 0, 0, '', 0), -- Spectrecles T1
(8392, 1, 0, 'Zorus, I need a new pair of goggles.', 19564, 1, 1, 0, 0, 0, 0, '', 0); -- Spectrecles T2

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN(8383,8392);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 8383, 0, 0, 0, 9, 0, 10625, 0, 0, 0, 0, 0, '', 'Gossip Option requires Spectrecles taken'),
(15, 8392, 0, 0, 0, 9, 0, 10643, 0, 0, 0, 0, 0, '', 'Gossip Option requires Harbringers of Shadowmoon taken'),
(15, 8383, 0, 0, 0, 2, 0, 30719, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Spectrecles T1'),
(15, 8392, 0, 0, 0, 2, 0, 30719, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Spectrecles T1'),
(15, 8383, 1, 0, 0, 9, 0, 10633, 0, 0, 0, 0, 0, '', 'Gossip Option requires Teron Gorefiend - Lore and Legend taken'),
(15, 8392, 1, 0, 0, 9, 0, 10644, 0, 0, 0, 0, 0, '', 'Gossip Option requires Teron Gorefiend - Lore and Legend taken'),
(15, 8383, 1, 0, 0, 2, 0, 30721, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Spectrecles T2'),
(15, 8392, 1, 0, 0, 2, 0, 30721, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Spectrecles T2'),
(15, 8383, 1, 0, 1, 8, 0, 10633, 0, 0, 0, 0, 0, '', 'Gossip Option requires Teron Gorefiend - Lore and Legend rewarded'),
(15, 8392, 1, 0, 1, 8, 0, 10644, 0, 0, 0, 0, 0, '', 'Gossip Option requires Teron Gorefiend - Lore and Legend rewarded'),
(15, 8383, 1, 0, 1, 2, 0, 30721, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Spectrecles T2'),
(15, 8392, 1, 0, 1, 2, 0, 30721, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Spectrecles T2'),
(15, 8383, 1, 0, 2, 28, 0, 10633, 0, 0, 0, 0, 0, '', 'Gossip Option requires Teron Gorefiend - Lore and Legend Complete'),
(15, 8392, 1, 0, 2, 28, 0, 10644, 0, 0, 0, 0, 0, '', 'Gossip Option requires Teron Gorefiend - Lore and Legend Complete'),
(15, 8383, 1, 0, 2, 2, 0, 30721, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Spectrecles T2'),
(15, 8392, 1, 0, 2, 2, 0, 30721, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Spectrecles T2');

UPDATE creature_template SET AIName='SmartAI' WHERE entry IN(21772,21774);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(21772,21774) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21772,0,0,2,62,0,100,0,8383,0,0,0,85,37602,2,0,0,0,0,7,0,0,0,0,0,0,0,'Chief Apothecary Hildagard - On Gossip Option 0 Selected - Invoker cast Replace Lost Spectrecles T1'),
(21772,0,1,2,62,0,100,0,8383,1,0,0,85,37700,2,0,0,0,0,7,0,0,0,0,0,0,0,'Chief Apothecary Hildagard - On Gossip Option 1 Selected - Invoker cast Replace Lost Spectrecles T2'),
(21772,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Chief Apothecary Hildagard - Link - Close Gossip'),
(21774,0,0,2,62,0,100,0,8392,0,0,0,85,37602,2,0,0,0,0,7,0,0,0,0,0,0,0,'Zorus the Judicator - On Gossip Option 0 Selected - Invoker cast Replace Lost Spectrecles T1'),
(21774,0,1,2,62,0,100,0,8392,1,0,0,85,37700,2,0,0,0,0,7,0,0,0,0,0,0,0,'Zorus the Judicator - On Gossip Option 1 Selected - Invoker cast Replace Lost Spectrecles T2'),
(21774,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Zorus the Judicator - Link - Close Gossip');

-- Winterhoof Emblem / Westguard Command Insignia
-- Horde
DELETE FROM `gossip_menu_option` WHERE `menu_id` in(8898);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(8898, 0, 0, 'My insignia! Yes. I did lose it. Where did you find it, tauren?', 41971, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN(8898);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 8898, 0, 0, 0, 8, 0, 11256, 0, 0, 0, 0, 0, '', 'Gossip Option requires Skorn Must Fall Rewarded'),
(15, 8898, 0, 0, 0, 8, 0, 11258, 0, 0, 1, 0, 0, '', 'Gossip Option requires Burn, Skorn, Burn not Rewarded'),
(15, 8898, 0, 0, 0, 2, 0, 33340, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not Winterhoof Emblem'),
(15, 8898, 0, 0, 1, 8, 0, 11256, 0, 0, 0, 0, 0, '', 'Gossip Option requires Skorn Must Fall Rewarded'),
(15, 8898, 0, 0, 1, 8, 0, 11257, 0, 0, 1, 0, 0, '', 'Gossip Option requires Gruesome but Necessary not Rewarded'),
(15, 8898, 0, 0, 1, 2, 0, 33340, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not Winterhoof Emblem'),
(15, 8898, 0, 0, 2, 8, 0, 11256, 0, 0, 0, 0, 0, '', 'Gossip Option requires Skorn Must Fall Rewarded'),
(15, 8898, 0, 0, 2, 8, 0, 11259, 0, 0, 1, 0, 0, '', 'Gossip Option requires Towers of Certain Doom not Rewarded'),
(15, 8898, 0, 0, 2, 2, 0, 33340, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not Winterhoof Emblem'),
(15, 8898, 0, 0, 3, 8, 0, 11256, 0, 0, 0, 0, 0, '', 'Gossip Option requires Skorn Must Fall Rewarded'),
(15, 8898, 0, 0, 3, 8, 0, 11261, 0, 0, 1, 0, 0, '', 'Gossip Option requires The Conqueror of Skorn! not Rewarded'),
(15, 8898, 0, 0, 3, 2, 0, 33340, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not Winterhoof Emblem');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(24129);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(24129) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24129,0,0,1,62,0,100,0,8898,0,0,0,85,43123,2,0,0,0,0,7,0,0,0,0,0,0,0,'Chieftain Ashtotem - On Gossip Option 0 Selected - Invoker cast Skorn Must Fall!: Create Token'),
(24129,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Chieftain Ashtotem - Link - Close Gossip');


-- Alliance Version
-- We must set gossip on Captain Adams as this was missing
UPDATE `creature_template` SET `gossip_menu_id`=8852,`npcflag`=3 WHERE  `entry`=23749;
DELETE FROM  `gossip_menu` WHERE `entry`=8852;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(8852, 11494); -- 23749

DELETE FROM `gossip_menu_option` WHERE `menu_id` in(8852);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(8852, 0, 0, 'Captain, I''ve somehow lost my command insignia.', 22809, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN(8852);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 8852, 0, 0, 0, 8, 0, 11248, 0, 0, 0, 0, 0, '', 'Gossip Option requires Operation: Skornful Wrath Rewarded'),
(15, 8852, 0, 0, 0, 8, 0, 11247, 0, 0, 1, 0, 0, '', 'Gossip Option requires Burn, Skorn, Burn not Rewarded'),
(15, 8852, 0, 0, 0, 2, 0, 33311, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Westguard Command Insignia'),
(15, 8852, 0, 0, 1, 8, 0, 11248, 0, 0, 0, 0, 0, '', 'Gossip Option requires Operation: Skornful Wrath Rewarded'),
(15, 8852, 0, 0, 1, 8, 0, 11246, 0, 0, 1, 0, 0, '', 'Gossip Option requires Gruesome but Necessary not Rewarded'),
(15, 8852, 0, 0, 1, 2, 0, 33311, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not Have Westguard Command Insignia'),
(15, 8852, 0, 0, 2, 8, 0, 11248, 0, 0, 0, 0, 0, '', 'Gossip Option requires Operation: Skornful Wrath Rewarded'),
(15, 8852, 0, 0, 2, 8, 0, 11245, 0, 0, 1, 0, 0, '', 'Gossip Option requires Towers of Certain Doom not Rewarded'),
(15, 8852, 0, 0, 2, 2, 0, 33311, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Westguard Command Insignia'),
(15, 8852, 0, 0, 3, 8, 0, 11248, 0, 0, 0, 0, 0, '', 'Gossip Option requires Operation: Skornful Wrath'),
(15, 8852, 0, 0, 3, 8, 0, 11250, 0, 0, 1, 0, 0, '', 'Gossip Option requires All Hail the Conqueror of Skorn! not Rewarded'),
(15, 8852, 0, 0, 3, 2, 0, 33311, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Westguard Command Insignia');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(23749);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(23749) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23749,0,0,1,62,0,100,0,8852,0,0,0,85,43122,2,0,0,0,0,7,0,0,0,0,0,0,0,'Captain Adams - On Gossip Option 0 Selected - Invoker cast Operation: Skornful Wrath: Create Insignia'),
(23749,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Captain Adams - Link - Close Gossip');
