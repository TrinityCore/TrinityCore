DELETE FROM `gossip_menu` WHERE `entry` IN (7757,7758,7759,7760,7761,7772,21253,7775,7776,7755,7774);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(7757,9497),
(7758,9503),
(7759,9502),
(7760,9505),
(7761,9506),
(7772,9520),
(21253,9520),
(7775,9523),
(7776,9524),
(7755,9498),
(7774,9522);

UPDATE `creature_template` SET `gossip_menu_id`=7774 WHERE `entry`=18712;
UPDATE `creature_template` SET `gossip_menu_id`=7775 WHERE `entry`=17088;
UPDATE `creature_template` SET `gossip_menu_id`=7776 WHERE `entry`=18720;
UPDATE `creature_template` SET `gossip_menu_id`=7775 WHERE `entry`=16519;
UPDATE `creature_template` SET `gossip_menu_id`=7772 WHERE `entry`=18714;
UPDATE `creature_template` SET `gossip_menu_id`=21253 WHERE `entry`=18715;
UPDATE `creature_template` SET `gossip_menu_id`=7759 WHERE `entry`=18716;
UPDATE `creature_template` SET `gossip_menu_id`=7757 WHERE `entry`=18717;
UPDATE `creature_template` SET `gossip_menu_id`=7760 WHERE `entry`=18719;

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7772,21253,7757,7759,7760);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(7772,0,0, 'Scout Neftis, I need another disguise.',1,1,0,0,0,0,0,NULL),
(21253,0,0, 'Private Weeks, I need another disguise.',1,1,0,0,0,0,0,NULL),
(7757,0,0, 'Why are you fixing all of this up?',1,1,7755,0,0,0,0,NULL),
(7759,0,0, 'What are you doing there?',1,1,7758,0,0,0,0,NULL),
(7760,0,0, 'Advisor, what''s the latest news?',1,1,7761,0,0,0,0,NULL);

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (18714,18717,18716,18719,18715);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18714,18717,18716,18719,18715);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18714,0,0,0,19,0,100,0,10041,0,0,0,11,48917,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Neftis - On Quest Accept - Cast spell 48917 on player'),
(18714,0,1,0,20,0,100,0,10041,0,0,0,28,32756,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Neftis - On Quest Reward - Remove spell 32756 on player'),
(18714,0,2,0,62,0,100,0,7772,0,0,0,11,48917,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Neftis - On Gossip option - Cast spell 48917 on player'),
(18715,0,0,0,19,0,100,0,10040,0,0,0,11,48917,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Private Weeks - On Quest Accept - Cast spell 48917 on player'),
(18715,0,1,0,20,0,100,0,10040,0,0,0,28,32756,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Private Weeks - On Quest Reward - Remove spell 32756 on player'),
(18715,0,2,0,62,0,100,0,21253,0,0,0,11,48917,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Private Week - On Gossip option - Cast spell 48917 on player'),
(18717,0,0,0,62,0,100,0,7757,0,0,0,11,47069,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Who Are They - Shadowy Laborer - On Gossip option - Cast spell 47069 on player'),
(18716,0,0,0,62,0,100,0,7759,0,0,0,11,47068,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Who Are They - Shadowy Initiate - On Gossip option - Cast spell 47068 on player'),
(18719,0,0,0,62,0,100,0,7760,0,0,0,11,47070,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Who Are They - Shadowy Advisor - On Gossip option - Cast spell 47070 on player');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (7772,7757,7759,7760,21253);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`Comment`) VALUES
(15,21253,0,0,9,10040,0,0,0, 'Show gossip option 21253 if player has quest 10040'),
(15,7757,0,0,9,10040,0,0,0, 'Show gossip option 7757 if player has quest 10040'),
(15,7759,0,0,9,10040,0,0,0, 'Show gossip option 7759 if player has quest 10040'),
(15,7760,0,0,9,10040,0,0,0, 'Show gossip option 7760 if player has quest 10040'),
(15,7772,0,1,9,10041,0,0,0, 'Show gossip option 7772 if player has quest 10041'),
(15,7757,0,1,9,10041,0,0,0, 'Show gossip option 7757 if player has quest 10041'),
(15,7759,0,1,9,10041,0,0,0, 'Show gossip option 7759 if player has quest 10041'),
(15,7760,0,1,9,10041,0,0,0, 'Show gossip option 7760 if player has quest 10041');
