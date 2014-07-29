UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=8696;
DELETE FROM `smart_scripts` WHERE `entryorguid` =8696 and `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8696,0,0,0,62,0,100,0,1443,2,0,0,85,13029,0,0,0,0,0,7,0,0,0,0,0,0,0,'Henry Stern - On Gossip Select - Cast Spell Goldthorn Tea'),
(8696,0,1,0,62,0,100,0,1443,3,0,0,85,13030,0,0,0,0,0,7,0,0,0,0,0,0,0,'Henry Stern - On Gossip Select - Cast Spell Major Trolls Blood Potion'),
(8696,0,2,0,38,0,100,0,1,1,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Henry Stern - On Data Set 1 1 - Set Phase 2'),
(8696,0,3,0,1,2,100,1,3000,3000,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,'Henry Stern - OOC (Phase 2) - Say (No Repeat)');

DELETE FROM `creature_text` WHERE `entry`=8696;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(8696, 0, 0, 'Thank again, $n.  Now I''ll just wait here until it''s safe to leave.', 12, 0, 100, 0, 0, 0, 'Henry Stern', 4575);

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI',`ScriptName`='' WHERE `entry`=157818;
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=157818;

INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(157818,1,0,1,70,0,100,0,2,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Holding Pen - On State Changed - Store target'),
(157818,1,1,2,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,8696,0,0,0,0,0,0, 'Holding Pen - On State Changed - Send targetlist to Henry Stern'),
(157818,1,2,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,8696,0,0,0,0,0,0,'Holding Pen - On State Changed - Set data 1 1 on Henry Stern');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` =8696;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=1443;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,1443,0,0,0,7,0,185,1,0,0,0,'','Show gossip option only if player has cooking'),
(15,1443,0,0,0,25,0,13028,0,0,1,0,'','Show gossip option only if player does not already know goldthorn tea recipe'),
(15,1443,0,0,0,7,0,185,180,0,1,0,'','Show Gossip only if player does not have at least 180 skill in cooking'),
(15,1443,1,0,0,7,0,171,1,0,0,0,'','Show gossip option only if player has Alchemy'),
(15,1443,1,0,0,25,0,3451,1,0,1,0,'','Show gossip option only if player does not already know Major Trolls Blood Elixir'),
(15,1443,1,0,0,7,0,171,175,0,1,0,'','Show gossip only if player does not have at least 175 skill in Alchemy'),
(15,1443,2,0,0,7,0,185,1,0,0,0,'','Show gossip option only if player has cooking'),
(15,1443,2,0,0,25,0,13028,0,0,1,0,'','Show gossip option only if player does not already know goldthorn tea recipe'),
(15,1443,2,0,0,7,0,185,180,0,0,0,'','Show Gossip only if player has at least 180 skill in cooking'),
(15,1443,3,0,0,7,0,171,1,0,0,0,'','Show gossip option only if player has Alchemy'),
(15,1443,3,0,0,25,0,3451,1,0,1,0,'','Show gossip option only if player does not already know Major Trolls Blood Elixir'),
(15,1443,3,0,0,7,0,171,175,0,0,0,'','Show gossip only if player has at least 175 skill in Alchemy');

DELETE FROM `gossip_menu_option` WHERE `menu_id`=1443;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(1443, 0, 0, 'You can cook?  So can I!  Is there a recipe you can teach me?', 4535, 1, 1, 1501, 0, 0, 0, NULL, 0),
(1443, 1, 0, 'You''re an alchemist?  So am I.  Perhaps you can teach me what you know...', 4537, 1, 1, 1502, 0, 0, 0, NULL, 0),
(1443, 2, 0, 'You can cook?  So can I!  Is there a recipe you can teach me?', 4535, 1, 1, 1444, 0, 0, 0, NULL, 0),
(1443, 3, 0, 'You''re an alchemist?  So am I.  Perhaps you can teach me what you know...', 4537, 1, 1, 1442, 0, 0, 0, NULL, 0);
