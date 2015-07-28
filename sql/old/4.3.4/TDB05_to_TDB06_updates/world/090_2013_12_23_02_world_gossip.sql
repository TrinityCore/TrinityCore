-- Add Missing gossip for Engineer "Spark" Overgrind
UPDATE `creature_template` SET `gossip_menu_id`=7426 WHERE `entry`=17243;
DELETE FROM `gossip_menu` WHERE (`entry`=7426 AND `text_id`=8978);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7426,8978);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7426);
INSERT INTO `gossip_menu_option` (menu_id, id, option_icon, option_text, option_id, npc_option_npcflag, action_menu_id, action_poi_id, box_coded, box_money, box_text) VALUES
(7426,0,0, 'It''s over, Spark. The admiral knows it was you who betrayed the Alliance. Now you''re either going to cooperate with me and tell me everything that you know or we''re going to engage in some fisticuff.',1,1,0,0,0,0, '');

-- Add Conditions for Engineer "Spark" Overgrind gossip
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=7426;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,7426,0,0,0,9,0,9537,0,0,0,0,0, '', 'Gossip Option - Show Option if Quest 9537 is taken');
