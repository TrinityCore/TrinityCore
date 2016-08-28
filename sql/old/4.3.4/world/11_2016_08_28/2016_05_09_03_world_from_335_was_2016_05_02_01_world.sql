-- Beaten Corpse (Mankrik's wife) in quest 4921 "Lost in Battle":
UPDATE `creature_template` SET `gossip_menu_id`= 2871 WHERE `entry`= 10668;

-- new gossip_menu.entry for creature 10668 (Beaten Corpse):
DELETE FROM `gossip_menu` WHERE `entry` IN (2871,2872) AND `text_id` IN (3557,3558);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(2871, 3557),
(2872, 3558);

-- new gossip_menu_option for creature 10668 (Beaten Corpse):
DELETE FROM `gossip_menu_option` WHERE `menu_id`= 2871 AND `OptionBroadcastTextID`= 5964;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(2871, 0, 0, 'I inspect the body further.', 5964, 1, 1, 2872, 0, 0, 0, '', 0);

-- condition for gossip_menu_option 2871 in Quest ID 4921 "Lost in Battle":
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup`= 2871;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15, 2871,0, 0,0,  9,0, 4921, 0,0,0,0,0, '', 'Show gossip menu option 2871 only if Quest 4921 is taken (active)');
