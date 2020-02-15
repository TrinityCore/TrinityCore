-- 
-- Journal of Jandice Barov
UPDATE `npc_text` SET text0_0='', text0_1='The journal of Jandice Barov is filled with rantings and ravings about the undead. Towards the end of the book is what appears to be a tailoring pattern for the creation of a bag of some sort. Your understanding of tailoring is insufficient to decipher the pattern.' WHERE ID=8120;
UPDATE `npc_text` SET text0_0='', text0_1='The journal of Jandice Barov is filled with rantings and ravings about the undead. Towards the end of the book is what appears to be a tailoring pattern for the creation of a felcloth bag. This bag is used by warlocks to store soul shards. Do you wish to copy the pattern into your own journal?', `BroadcastTextID0`='11406' WHERE ID=8121;
UPDATE `npc_text` SET text0_0='', text0_1='The journal of Jandice Barov is filled with rantings and ravings about the undead. Towards the end of the book is what appears to be a tailoring pattern for the creation of a felcloth bag. This bag is used by warlocks to store soul shards. You already know how to create this bag.', `BroadcastTextID0`='11410' WHERE ID=8122;
DELETE FROM `gossip_menu` WHERE MenuID=6799;
INSERT INTO `gossip_menu` VALUES (6799, 8120, 0),(6799, 8121, 0),(6799, 8122, 0);
DELETE FROM `gossip_menu_option` WHERE `MenuID`=6799;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`) VALUES
(6799, 0, 0, '<Copy the pattern into my journal.>', 11407, 1, 1);

DELETE FROM `conditions` WHERE SourceTypeOrReferenceId IN(14, 15) AND SourceGroup=6799;
INSERT INTO `conditions` VALUES(14, 6799, 8120, 0, 0, 7, 0, 197, 280, 0, 1, 0, 0, '', 'Show text if player does not have tailoring');
INSERT INTO `conditions` VALUES(14, 6799, 8121, 0, 0, 7, 0, 197, 280, 0, 0, 0, 0, '', 'Show text if player have tailoring');
INSERT INTO `conditions` VALUES(14, 6799, 8121, 0, 0, 25, 0, 26086, 0, 0, 1, 0, 0, '', 'Show text if player does not have spell 26086');
INSERT INTO `conditions` VALUES(14, 6799, 8122, 0, 0, 7, 0, 197, 280, 0, 0, 0, 0, '', 'Show text if player have tailoring');
INSERT INTO `conditions` VALUES(14, 6799, 8122, 0, 0, 25, 0, 26086, 0, 0, 0, 0, 0, '', 'Show text if player have spell 26086');
INSERT INTO `conditions` VALUES(15, 6799, 0, 0, 0, 7, 0, 197, 280, 0, 0, 0, 0, '', 'Show gossip if player have tailoring');
INSERT INTO `conditions` VALUES(15, 6799, 0, 0, 0, 25, 0, 26086, 0, 0, 1, 0, 0, '', 'Show gossip if player does not have spell 26086');

-- Journal of Jandice Barov SAI
SET @ENTRY := 180794;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI", ScriptName='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,1,62,0,100,0,6799,0,0,0,85,26095,2,0,0,0,0,7,0,0,0,0,0,0,0,"Journal of Jandice Barov - On Gossip Option 0 Selected - Invoker Cast 'Felcloth Bag'"),
(@ENTRY,1,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Journal of Jandice Barov - On Gossip Option 0 Selected - Close Gossip");
