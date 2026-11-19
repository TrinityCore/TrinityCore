-- Fixing Lord Thorval, Lady Alistra and Amal'thazad in map 609
UPDATE `creature_template` SET `gossip_menu_id`=9691 WHERE `entry`=28471; -- Lady Alistra
UPDATE `creature_template` SET `gossip_menu_id`=9692 WHERE `entry`=28472; -- Lord Thorval
UPDATE `creature_template` SET `gossip_menu_id`=9693 WHERE `entry`=28474; -- Amal'thazad

DELETE FROM `gossip_menu` WHERE `entry`=9791 AND `text_id`=13475;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9791,13475);

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9691,9692,9693,9791,10371);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9691,0,3,'I seek training, Lady Alistra.',5,16,0,0,0,0,''),
(9691,1,0,'I wish to unlearn my talents.',1,1,9791,0,0,0,''),
(9691,2,0,'Learn about Dual Talent Specialization.',1,1,10371,0,0,0,''),
(9692,0,3,'I seek training, Lord Thorval.',5,16,0,0,0,0,''),
(9692,1,0,'I wish to unlearn my talents.',1,1,9791,0,0,0,''),
(9692,2,0,'Learn about Dual Talent Specialization.',1,1,10371,0,0,0,''),
(9693,0,3,'I seek training, Amal''thazad.',5,16,0,0,0,0,''),
(9693,1,0,'I wish to unlearn my talents.',1,1,9791,0,0,0,''),
(9693,2,0,'Learn about Dual Talent Specialization.',1,1,10371,0,0,0,''),
(9791,0,0,'Yes. I do.',16,16,0,0,0,0,''),
(10371,0,0,'Purchase a Dual Talent Specialization.',18,16,0,0,0,10000000,'Are you sure you wish to purchase a Dual Talent Specialization?'); -- Fixing this entry because Dual Talent Specialization needs confirmation by players.

-- Darion Mograine DK trainer (Since the quest 'Taking back Acherus' until go to Stormwind/Orgrimmar)
-- The gossip_menu (`entry` and `text_id`) are already in TDB UP41. Only needs this changes:
UPDATE `creature_template` SET `gossip_menu_id`=10027, `trainer_class`=6 WHERE `entry`=31084;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=10027;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(10027,0,3,'I require training, Highlord.',5,16,0,0,0,0,'');
