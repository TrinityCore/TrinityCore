UPDATE `creature_template` SET `npcflag`=1, `gossip_menu_id`=10953 WHERE `entry`=37187;

DELETE FROM `gossip_menu` WHERE `entry` IN (10953, 10952) AND `text_id` IN (15217, 15218);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(10953, 15217),
(10952, 15218);

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (10953, 10952);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`, `OptionBroadcastTextID`, `option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(10953,0,0,"We are ready to go, High Overlord. The Lich King must fall!",37631,1,1,10952),
(10952,0,0,"Lok'tar ogar! We are ready! Onward, brother orc!",37633,1,1,0);

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (10933, 10934);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`, `OptionBroadcastTextID`, `option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(10933,0,0,"We're ready, Muradin",37446,1,1,10934),
(10934,0,0,"We're sure. Let's go!",37448,1,1,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup` IN (10933, 10953);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 10933, 0, 0, 0, 13, 1, 2, 4, 2, 1, 0, 0, '', 'Show gossip option only if Deathbringer Saurfang is not done'),
(15, 10953, 0, 0, 0, 13, 1, 2, 4, 2, 1, 0, 0, '', 'Show gossip option only if Deathbringer Saurfang is not done');
