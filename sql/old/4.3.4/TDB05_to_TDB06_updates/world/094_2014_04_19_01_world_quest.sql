--
DELETE FROM `gossip_menu_option` WHERE `menu_id` in(524);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(524, 0, 0, 'Press the red button labeled ''E.C.A.C.''', 3166, 1, 1, 0, 0, 0, 0, NULL, 0),
(524, 1, 0, 'Press the yellow button labeled ''Thieves'' Tools.', 3149, 1, 1, 0, 0, 0, 0, NULL, 0);

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (7166,7167);

DELETE FROM `smart_scripts` WHERE `entryorguid`=7166;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`COMMENT`) VALUES
(7166,0,0,1,62,0,100,0,524,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Wrenixs Gizmotronic Apparatus - On Gossip Select - Close gossip'),
(7166,0,1,0,61,0,100,0,0,0,0,0,11,9977,0,0,0,0,0,7,0,0,0,0,0,0,0,'Wrenixs Gizmotronic Apparatus - Cast Conjure E.C.A.C'),
(7166,0,2,3,62,0,100,0,524,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Wrenixs Gizmotronic Apparatus - On Gossip Select - Close Gossip'),
(7166,0,3,0,61,0,100,0,0,0,0,0,11,9949,1,0,0,0,0,7,0,0,0,0,0,0,0,'Wrenixs Gizmotronic Apparatus - Cast Thieves Tool Rack Conjure');

DELETE FROM `smart_scripts` WHERE `entryorguid`=7167;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`COMMENT`) VALUES
(7167,0,0,0,1,0,100,1,73000,73000,60000,60000,11,8822,0,0,0,0,0,1,0,0,0,0,0,0,0,'Polly - OOC - Cast Stealth'),
(7167,0,1,0,8,0,100,0,9976,0,0,0,36,7168,0,0,0,0,0,1,0,0,0,0,0,0,0,'Polly - On Spell Hit Polly Eats the E.C.A.C - Change Entry to Polly JR ');

DELETE FROM `creature_loot_template` WHERE `entry`=7168 AND `item`=7968;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(7168, 7968, 100, 1, 0, 1, 1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=524 AND `SourceEntry` IN (0,1);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,524,0,0,0,9,0,2381,0,0,0,0,'','Wrenixs Gizmotronic Apparatus - Show gossip option only if player has taken quest Plundering the Plunderers'),
(15,524,1,0,0,9,0,2381,0,0,0,0,'','Wrenixs Gizmotronic Apparatus - Show gossip option only if player has taken quest Plundering the Plunderers'),
(15,524,0,0,0,2,0,7970,1,0,1,0,'','Wrenixs Gizmotronic Apparatus - Show gossip option only if player Does not have E.C.A.C'),
(15,524,1,0,0,2,0,5060,1,0,1,0,'','Wrenixs Gizmotronic Apparatus - Show gossip option only if player Does not have Thieves Tools');
