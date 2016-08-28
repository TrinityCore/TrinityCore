/*
-- Remove outdated ScriptName from NPC 7775 Gregan Brewspewer
UPDATE `creature_template` SET `ScriptName`= '' WHERE `entry`= 7775;

-- Remove broadcast_text link from Gregan's default gossip "What can I do for ya?"
-- to enable npc_text.ID 2433 "Hi there! The name's Gregan. What can I do for ya?"
-- This mixup is caused by invalid duplicate use of BroadcastTextID0 = 8275,
-- duplicate of npc_text.ID 5695, used by NPC entry 5167 Fenthwick <Rogue Trainer>
-- Lookup queries to verify this information:
-- SELECT * FROM `npc_text` WHERE `BroadcastTextID0`= 8275; -- (ID 2433 + 5695)
-- SELECT * FROM `gossip_menu` WHERE `text_id`= 5695; -- (4561,5695)
-- SELECT * FROM `gossip_menu_option` WHERE `menu_id`= 4561; -- (id 0,1,2,4) "I'm lookin' for rogue trainin'."
-- SELECT * FROM `creature_template` WHERE `gossip_menu_id`= 4561; -- (5167 Fenthwick <Rogue Trainer>)

UPDATE `npc_text` SET `BroadcastTextID0`= 0 WHERE `ID`= 2433; -- old (invalid) BroadcastTextID0 : 8275

-- Activate selection of the next gossip menus in the gossip dialogue
UPDATE `gossip_menu_option` SET `action_menu_id`= 1801 WHERE `menu_id`= 1802 AND `id`= 0;
UPDATE `gossip_menu_option` SET `action_menu_id`= 1915 WHERE `menu_id`= 1801 AND `id`= 0;

-- Condition for gossip_menu_option.menu_id 1802, shown in Gregan Brewspewer's default gossip menu 2433
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup`= 1802 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15, 1802, 0, 0, 0, 9, 0, 3909, 0, 0, 0, 0, 0, "", "Show Gossip Menu Option menu_id 1802 id 0 if Quest 3909 is taken (active)");
*/
