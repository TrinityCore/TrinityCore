--
-- Weapon Master Hanashi: add the missing linked IDs in `action_menu_id`
UPDATE `gossip_menu_option` SET `action_menu_id`= 5262 WHERE `menu_id`= 5263 AND `OptionBroadcastTextID`= 8812;

-- Hanashi is a troll, using Low Common "Troll" speech, so link the correct text lines for him:
UPDATE `gossip_menu_option` SET `action_menu_id`= 8603 WHERE `menu_id`= 5262 AND `option_text`= 'Crossbow';
UPDATE `gossip_menu_option` SET `action_menu_id`= 8604 WHERE `menu_id`= 5262 AND `option_text`= 'Dagger';
UPDATE `gossip_menu_option` SET `action_menu_id`= 8605 WHERE `menu_id`= 5262 AND `option_text`= 'Fist Weapon';
UPDATE `gossip_menu_option` SET `action_menu_id`= 8606 WHERE `menu_id`= 5262 AND `option_text`= 'Gun';
UPDATE `gossip_menu_option` SET `action_menu_id`= 8607 WHERE `menu_id`= 5262 AND `option_text`= 'Mace';
UPDATE `gossip_menu_option` SET `action_menu_id`= 8608 WHERE `menu_id`= 5262 AND `option_text`= 'Polearm';
UPDATE `gossip_menu_option` SET `action_menu_id`= 8609 WHERE `menu_id`= 5262 AND `option_text`= 'Sword';

-- Weapon Master Archibald: add missing linked IDs to `action_menu_id` (using default gossip from npc_text)
UPDATE `gossip_menu_option` SET `action_menu_id`= 5268 WHERE `menu_id`= 5269 AND `OptionBroadcastTextID`= 8812;
UPDATE `gossip_menu_option` SET `action_menu_id`= 8592 WHERE `menu_id`= 5268 AND `option_text`= 'Axe';
UPDATE `gossip_menu_option` SET `action_menu_id`= 8593 WHERE `menu_id`= 5268 AND `option_text`= 'Bow';
UPDATE `gossip_menu_option` SET `action_menu_id`= 8596 WHERE `menu_id`= 5268 AND `option_text`= 'Fist Weapon';
UPDATE `gossip_menu_option` SET `action_menu_id`= 8597 WHERE `menu_id`= 5268 AND `option_text`= 'Gun';
UPDATE `gossip_menu_option` SET `action_menu_id`= 8598 WHERE `menu_id`= 5268 AND `option_text`= 'Mace';
UPDATE `gossip_menu_option` SET `action_menu_id`= 8600 WHERE `menu_id`= 5268 AND `option_text`= 'Staff';
UPDATE `gossip_menu_option` SET `action_menu_id`= 8602 WHERE `menu_id`= 5268 AND `option_text`= 'Thrown';

-- Weapon Master Sayoc: add the gossip link ID 5220 in `action_menu_id` and link it in `gossip_menu` too
UPDATE `gossip_menu_option` SET `action_menu_id` = 5222 WHERE `menu_id` = 5221 AND `OptionBroadcastTextID`= 8812;
-- Sayoc needs new lines in `gossip_menu_option` as well as the linked lines from npc_text :
DELETE FROM `gossip_menu_option` WHERE `menu_id` = 5222 AND `OptionBroadcastTextID` IN (20582,20585,20586,20587,20588,20589);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(5222,0,0,'Crossbow',20582,1,1,8594,0,0,0,'',0),
(5222,1,0,'Gun',20585,1,1,8597,0,0,0,'',0),
(5222,2,0,'Mace',20586,1,1,8598,0,0,0,'',0),
(5222,3,0,'Polearm',20587,1,1,8599,0,0,0,'',0),
(5222,4,0,'Staff',20588,1,1,8610,0,0,0,'',0), -- 
(5222,5,0,'Sword',20589,1,1,8601,0,0,0,'',0);

UPDATE `creature_template` SET `type_flags`=134217728  WHERE `entry` IN (17005);
DELETE FROM `gossip_menu_option` WHERE (`menu_id`=7337);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(7337,0,3,'Show me what you know, Larenis.',13168,5,16,0,0,0,0,'',0);
