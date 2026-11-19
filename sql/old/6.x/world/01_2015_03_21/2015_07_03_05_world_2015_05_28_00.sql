UPDATE `creature_template` SET `gossip_menu_id`=5746, `npcflag`=1 WHERE  `entry`=11444;
UPDATE `gameobject_template` SET `faction`=114 ,`flags`=34 where  `entry`=177219;

DELETE FROM `smart_scripts` WHERE `entryorguid`=14323 AND `id`>6;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(14323, 0, 7, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, 14323, 1, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Slip\'kik - On Spawn - Start WP'),
(14323, 0, 8, 0, 38, 0, 100, 0, 1, 1, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Slip\'kik - On Data Set 1 1 - Set Phase 2'),
(14323, 0, 9, 10, 40, 2, 100, 0, 19, 14323, 0, 0, 55, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Slip\'kik - On Reached WP19 (Phase 2) - Stop WP'),
(14323, 0, 10, 11, 61, 2, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Slip\'kik - On Reached WP19 (Phase 2) - Set Home Position'),
(14323, 0, 11, 12, 61, 2, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Slip\'kik - On Reached WP19 (Phase 2) - Set Unit Flags'),
(14323, 0, 12, 0, 61, 2, 100, 0, 0, 0, 0, 0, 11, 22856, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Slip\'kik - On Reached WP19 (Phase 2) - Cast Icelock'),
(14323, 0, 13, 0, 62, 2, 100, 0, 5733, 0, 0, 0, 85, 22820, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Guard Slip\'kik - On Gossip Option Selected - Invoker Cast 22820');

DELETE FROM `waypoints` where `entry`=14323;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(14323, 1, 550.9423, 528.1198, -25.40169, 'Guard Slip kik'),
(14323, 2, 556.3312, 543.3906, -25.39986, 'Guard Slip kik'),
(14323, 3, 566.9871, 557.3884, -25.39788, 'Guard Slip kik'),
(14323, 4, 573.3212, 578.565, -25.40273, 'Guard Slip kik'),
(14323, 5, 532.9773, 586.9559, -25.40273, 'Guard Slip kik'),
(14323, 6, 515.2665, 599.5718, -25.40246, 'Guard Slip kik'),
(14323, 7, 494.9027, 606.5114, -25.40438, 'Guard Slip kik'),
(14323, 8, 480.8065, 598.4612, -25.40517, 'Guard Slip kik'),
(14323, 9, 477.7994, 587.293, -25.40587, 'Guard Slip kik'),
(14323, 10, 504.7797, 574.7651, -25.40086, 'Guard Slip kik'),
(14323, 11, 480.9391, 578.991, -25.40194, 'Guard Slip kik'),
(14323, 12, 477.7994, 587.293, -25.40587, 'Guard Slip kik'),
(14323, 13, 484.9685, 603.9871, -25.40483, 'Guard Slip kik'),
(14323, 14, 501.5791, 606.5353, -25.40406, 'Guard Slip kik'),
(14323, 15, 519.1758, 594.009, -25.403, 'Guard Slip kik'),
(14323, 16, 570.0894, 586.4958, -25.40273, 'Guard Slip kik'),
(14323, 17, 573.4045, 571.6358, -25.40239, 'Guard Slip kik'),
(14323, 18, 561.7436, 552.6977, -25.3998, 'Guard Slip kik'),
(14323, 19, 560.2891, 551.3965, -25.39884, 'Guard Slip kik');

UPDATE `gameobject_template` SET `AIName`= 'SmartGameObjectAI' WHERE  `entry` =179485;

DELETE FROM `smart_scripts` WHERE `entryorguid` =179485 AND `source_type`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES

(179485,1,0,1,20,0,100,0,1193,0,0,0,45,1,1,0,0,0,0,19,14323,0,0,0,0,0,0,'Broken Trap - On Quest Reward (A Broken Trap) - Set Data on Guard Slip kik'),
(179485,1,1,2,61,0,100,0,0,0,0,0,70,7200,0,0,0,0,0,1,0,0,0,0,0,0,0,'Broken Trap - On Quest Reward (A Broken Trap) - Despawn GO'),
(179485,1,2,0,61,0,100,0,0,0,0,0,50,179512,300,0,0,0,0,8,0,0,0,558.806, 550.065, -25.4008, 3.14159,'Broken Trap - On Quest Reward (A Broken Trap) - Summon Fixed Trap');


DELETE FROM `creature_text` WHERE `entry` IN(14353,11501);
DELETE FROM `creature_text` WHERE `entry` IN(14325) AND `groupid`>2;

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(14353, 0, 0, 'OH NOES!  Da king is dead!  Uh... hail to da new king!  Yeah!', 14, 0, 100, 0, 0, 0, 9348, 'Mizzle the Crafty to 58960'),
(14353, 1, 0, 'Yar, he''s dead all right.  That makes you da new king... well, all of you!  Gordok is yours now, boss!  You should talk to me so you can learn everything there is about being da king!  I was... is his assistant!  Yeah, that''s why I''m called da crafty one!', 12, 0, 100, 0, 0, 0, 9411, 'Mizzle the Crafty to 58960'),
(11501, 0, 0, 'You no challenge me, scrubs!  I''m da king now, and I stay king FOREVER!!!', 12, 0, 100, 0, 0, 0, 9481, 'King Gordok to Player'),
(14325, 3, 0, 'Hey, who Fengus callin'' a gnoll lover?!  Take da prisoners to da king; you smart to bring them with their weapons and show da king that they a threat.  I''ll go see if Fengus talk smack when I give him da beatdown!  HAR!', 12, 0, 100, 0, 0, 0, 9416, 'Captain Kromcrush'),
(14325, 4, 0, 'OK Fengus, where you at?!  You come call me a gnoll lover while I give you da hammer upside da head!', 14, 0, 100, 0, 0, 0, 9424, 'Captain Kromcrush');

UPDATE `creature_template` SET `gossip_menu_id`=5739, `npcflag`=1 WHERE  `entry`=14325;
UPDATE `creature_template` SET `gossip_menu_id`=5734, `npcflag`=1 WHERE  `entry`=14321;

DELETE FROM `creature` WHERE  `guid`IN(84194,84195);
DELETE FROM `gameobject` WHERE  `guid`=35834;

DELETE FROM `gossip_menu` WHERE `entry` IN(5739,5738,5734);
DELETE FROM `gossip_menu` WHERE `entry` =5733 AND `text_id`=6906;
DELETE FROM `gossip_menu` WHERE `entry` =5735 AND `text_id`=6908;

INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(5733, 6906),
(5734, 6903),
(5734, 6904),
(5735, 6908),
(5739, 6913),
(5739, 6914),
(5738, 6915);

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN(5738,5739,5733,5734,5735);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(5739, 0, 0, 'Um, I''m taking some prisoners we found outside before the king for punishment.', 9421, 1, 1, 5738, 0, 0, 0, '', 0),
(5738, 0, 0, 'Er... that''s how I found them.  I wanted to show the king that they were a threat!  Say Captain... I overheard Guard Fengus calling you a fat, useless gnoll lover!', 9423, 1, 1, 0, 0, 0, 0, '', 0),
(5733, 0, 0, 'Yeah, you''re a real brainiac.  Just how smart do you think you are, Slip''kik?', 9398, 1, 1, 5733, 0, 0, 0, '', 0),
(5734, 0, 0, 'So, now that I''m the king... what have you got for me?!', 9451, 1, 1, 5734, 0, 0, 0, '', 0),
(5735, 0, 0, 'Call me "Boss".  What have you got for me!', 9401, 1, 1, 5735, 0, 0, 0, '', 0);

UPDATE `gameobject_template` SET `faction`=0, `flags`=34 WHERE  `entry`=177217;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=14353;

DELETE FROM `smart_scripts` WHERE `entryorguid`=11501 AND `id`>3;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14324 AND `id`>27;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14325 AND `id`>7;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14326 AND `id`>6;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14321 AND `id`>6;

DELETE FROM `smart_scripts` WHERE `entryorguid`=14353;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(11501, 0, 4, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'King Gordok - On Agro - Say'),
(11501, 0, 5, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 14324, 0, 0, 0, 0, 0, 0, 'King Gordok - On Death - Set Data on Cho Rush the Observer'),
(14324, 0, 28, 0, 11, 0, 100, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cho\'Rush the Observer - On Spawn - Set Invincibility HP'),
(14324, 0, 29, 30, 38, 0, 100, 0, 1, 1, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cho\'Rush the Observer - On Data Set - Set Unit Flags'),
(14324, 0, 30, 31, 61, 0, 100, 0, 0, 0, 0, 0, 12, 14353, 1, 720000, 0, 0, 0, 8, 0, 0, 0, 683.2966, 484.3845, 29.54451, 0.01745329, 'Cho\'Rush the Observer - On Data Set - Summon Mizzle the Crafty'),
(14324, 0, 31, 0, 61, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cho\'Rush the Observer - On Data Set - Evade'),
(14325, 0, 8, 9, 62, 0, 100, 0, 5738, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Captain Kromcrush - On Gossip Option Selected - Close Gossip'),
(14325, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captain Kromcrush - On Gossip Option Selected - Say Line 3'),
(14325, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captain Kromcrush - On Gossip Option Selected - Set Unit Flags'),
(14325, 0, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, 14325, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captain Kromcrush - On Gossip Option Selected - Start WP'),
(14325, 0, 12, 0, 40, 0, 100, 0, 1, 14325, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captain Kromcrush - On Reached WP1 - Say Line 4'),
(14325, 0, 13, 0, 40, 0, 100, 0, 2, 14325, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captain Kromcrush - On Reached WP2 - Set NPC Flags'),
(14326, 0, 7, 0, 62, 0, 100, 0, 5735, 0, 0, 0, 85, 22818, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Guard Mol\'dar - On Gossip Option Selected - Invoker Cast 22818'),
(14321, 0, 7, 0, 62, 0, 100, 0, 5734, 0, 0, 0, 85, 22817, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Guard Fengus - On Gossip Option Selected - Invoker Cast 22818'),
(14353, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 53, 0, 14353, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mizzle the Crafty - On Just Summoned - Start WP'),
(14353, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mizzle the Crafty - On Just Summoned - Set NPC Flags'),
(14353, 0, 2, 0, 40, 0, 100, 0, 1, 14353, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mizzle the Crafty - On Reached WP1 - Say Line 0'),
(14353, 0, 3, 4, 40, 0, 100, 0, 4, 14353, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mizzle the Crafty - On Reached WP4 - Say Line 1'),
(14353, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mizzle the Crafty - On Reached WP4 - Set NPC Flags'),
(14353, 0, 5, 0, 62, 0, 100, 0, 5708, 0, 0, 0, 11, 22799, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 'Mizzle the Crafty - On Gossip Option Selected - Cast King of the Gordok'),
(14353, 0, 6, 0, 62, 0, 100, 0, 5715, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mizzle the Crafty - On Gossip Option Selected - Close Gossip'),
(14353, 0, 7, 0, 62, 0, 100, 0, 5740, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mizzle the Crafty - On Gossip Option Selected - Close Gossip'),
(14353, 0, 8, 9, 62, 0, 100, 1, 5740, 0, 0, 0, 50, 179564, 7200, 0, 0, 0, 0, 8, 0, 0, 0, 808.3697, 482.1281, 37.3182, 3.194002, 'Mizzle the Crafty - On Gossip Option Selected - Summon Gordok Tribute (No Repeat)'),
(14353, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mizzle the Crafty - On Gossip Option Selected - Set NPC Flags');

DELETE FROM `waypoints` WHERE `entry`IN(14353,14325);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(14353, 1, 683.2966, 484.3845, 29.54451, 'Mizzle the Crafty'),
(14353, 2, 721.1365, 483.4832, 28.18014, 'Mizzle the Crafty'),
(14353, 3, 756.7082, 482.5323, 28.18394, 'Mizzle the Crafty'),
(14353, 4, 816.5302, 482.3017, 37.31819, 'Mizzle the Crafty'),
(14325, 1, 492.7128, 483.2709, 29.46278 , 'Captain Kromcrush'),
(14325, 2, 491.0189, 505.9179, 29.46236 , 'Captain Kromcrush');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`IN(14,15) AND `SourceGroup`IN(5708,5739,5733,5734,5735);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 5708, 0, 0, 0, 1, 0, 22799, 0, 0, 1, 0, 0, '', 'Mizzle the Crafty Show Gossip option 0 only if player does not have aura 22799'),
(15, 5708, 1, 0, 0, 1, 0, 22799, 0, 0, 0, 0, 0, '', 'Mizzle the Crafty Show Gossip option 1 only if player has aura 22799'),
(15, 5739, 0, 0, 0, 1, 0, 22799, 0, 0, 1, 0, 0, '', 'Captain Kromcrush Show Gossip option 0 only if player does not have aura 22799'),
(15, 5733, 0, 0, 0, 1, 0, 22799, 0, 0, 0, 0, 0, '', 'Guard Slip Kik Show Gossip option 0 only if player has aura 22799'),
(15, 5733, 0, 0, 0, 1, 0, 22820, 0, 0, 1, 0, 0, '', 'Guard Slip Kik Show Gossip option 0 only if player does not have aura 22820'),
(15, 5733, 0, 0, 0,27, 0, 63, 4, 0, 0, 0, 0, '', 'Guard Slip Kik Show Gossip option 0 only if player is level 63 or Lower'),
(15, 5735, 0, 0, 0, 1, 0, 22799, 0, 0, 0, 0, 0, '', 'Guard Mol Dar Show Gossip option 0 only if player has aura 22799'),
(15, 5735, 0, 0, 0, 1, 0, 22818, 0, 0, 1, 0, 0, '', 'Guard Mol Dar Show Gossip option 0 only if player does not have aura 22818'),
(15, 5735, 0, 0, 0,27, 0, 63, 4, 0, 0, 0, 0, '', 'Guard Mol Dar Show Gossip option 0 only if player is level 63 or Lower'),
(15, 5734, 0, 0, 0, 1, 0, 22799, 0, 0, 0, 0, 0, '', 'Guard Fengus Show Gossip option 0 only if player has aura 22799'),
(15, 5734, 0, 0, 0, 1, 0, 22817, 0, 0, 1, 0, 0, '', 'Guard Fengus Show Gossip option 0 only if player does not have aura 22817'),
(15, 5734, 0, 0, 0,27, 0, 63, 4, 0, 0, 0, 0, '', 'Guard Fengus Show Gossip option 0 only if player is level 63 or Lower'),
(14, 5739, 6913, 0, 0, 1, 0, 22799, 0, 0, 1, 0, 0, '', 'Captain Kromcrush Show text 6913 only if player does not have aura 22799'),
(14, 5739, 6914, 0, 0, 1, 0, 22799, 0, 0, 0, 0, 0, '', 'Captain Kromcrush Show text 6914 only if player has aura 22799'),
(14, 5733, 6905, 0, 0, 1, 0, 22820, 0, 0, 1, 0, 0, '', 'Guard Slip Kik Show text 6905 only if player does not have aura 22820'),
(14, 5733, 6905, 0, 0, 1, 0, 22799, 0, 0, 0, 0, 0, '', 'Guard Slip Kik Show text 6906 only if player has aura 22799'),
(14, 5733, 6906, 0, 0, 1, 0, 22820, 0, 0, 0, 0, 0, '', 'Guard Slip Kik Show text 6905 only if player does not have aura 22820'),
(14, 5733, 6906, 0, 0, 1, 0, 22799, 0, 0, 0, 0, 0, '', 'Guard Slip Kik Show text 6906 only if player has aura 22799'),
(14, 5734, 6903, 0, 0, 1, 0, 22817, 0, 0, 1, 0, 0, '', 'Guard Fengus Show text 6905 only if player does not have aura 22817'),
(14, 5734, 6903, 0, 0, 1, 0, 22799, 0, 0, 0, 0, 0, '', 'Guard Fengus Show text 6906 only if player has aura 22799'),
(14, 5734, 6904, 0, 0, 1, 0, 22817, 0, 0, 0, 0, 0, '', 'Guard Fengus Show text 6905 only if player does not have aura 22817'),
(14, 5734, 6904, 0, 0, 1, 0, 22799, 0, 0, 0, 0, 0, '', 'Guard Fengus Show text 6906 only if player has aura 22799'),
(14, 5735, 6907, 0, 0, 1, 0, 22818, 0, 0, 1, 0, 0, '', 'Guard Mol Dar Show text 6907 only if player does not have aura 22818'),
(14, 5735, 6907, 0, 0, 1, 0, 22799, 0, 0, 0, 0, 0, '', 'Guard Mol Dar Show text 6907 only if player has aura 22799'),
(14, 5735, 6908, 0, 0, 1, 0, 22818, 0, 0, 0, 0, 0, '', 'Guard Mol Dar Show text 6908 only if player does not have aura 22818'),
(14, 5735, 6908, 0, 0, 1, 0, 22799, 0, 0, 0, 0, 0, '', 'Guard Mol Dar Show text 6908 only if player has aura 22799');
