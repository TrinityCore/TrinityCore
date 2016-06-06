-- NPC 4488 Parqual Fintallas creature_template script name update:
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName`= '' WHERE `entry` = 4488;

-- new gossip_menu_option 4764:
DELETE FROM `gossip_menu_option` WHERE `menu_id`= 4764 AND `id` IN (0,1,2,3);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(4764, 0, 0, "Kel'Thuzad is my answer.", 8377, 1, 1, 0,0,0,0,'',0),
(4764, 1, 0, "Gul'dan is my answer.",    8378, 1, 1, 0,0,0,0,'',0),
(4764, 2, 0, "Kil'jaeden is my answer.", 8379, 1, 1, 0,0,0,0,'',0),
(4764, 3, 0, "Ner'zhul is my answer.",   8380, 1, 1, 0,0,0,0,'',0);

-- new gossip_menu.entry linking quest text to gossip menu:
DELETE FROM `gossip_menu` WHERE `entry`= 4764 AND `text_id`= 5822;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (4764, 5822);

-- broadcast_text English grammar correction:
UPDATE `broadcast_text` SET `MaleText`= "Kel'Thuzad? If you know that name at all, then perhaps you did read the book I sent you to get.$B$BUnfortunately, your answer is incorrect." WHERE `ID`= 8373;

-- creature_text (say lines) in reply to the selected options:
DELETE FROM `creature_text` WHERE `entry` = 4488 AND `groupid` IN (0,1,2,3,4);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(4488,0,0,"Kel'Thuzad? If you know that name at all, then perhaps you did read the book I sent you to get.$B$BUnfortunately, your answer is incorrect.",12,0,100,1,5000,0,8373,0,'Parqual replies to option 1'),
(4488,1,0,"Gul'dan. Not a name many have heard on Azeroth.$B$BUnfortunately, not the correct answer.",                                                  12,0,100,1,5000,0,8374,0,'Parqual replies to option 2'),
(4488,2,0,'An interesting response to my question... and the wrong one.',                                                                               12,0,100,1,5000,0,8375,0,'Parqual replies to option 3'),
(4488,3,0,"Ah, Ner'zhul. Not a name that should be uttered lightly, but I did ask you for an answer.$B$BAnd Ner'zhul is the correct one.",              12,0,100,1,5000,0,8376,0,'Parqual replies to option 4'),
(4488,4,0,"I'm afraid not, $n. Now, feel the shame you have brought upon yourself.",                                                                    12,0,100,1,3000,0,8394,0,'Parqual, reply 2 to option 1-3');

-- new SmartAI script for NPC 4488 Parqual Fintallas:
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4488 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4488,0,  0,  1, 62,0,100,0, 4764,    0,0,0, 83,    3,    0,0,0,0,0, 10, 32022, 4488,0,0,0,0,0,'Parqual Fintallas - On Gossip Option 0 Selected - Remove npcflags Gossip & Questgiver'),
(4488,0,  1,  2, 61,0,100,0,    0,    0,0,0, 72,    0,    0,0,0,0,0,  7,     0,    0,0,0,0,0,0,'Parqual Fintallas - On Gossip Option 0 Selected - Close Gossip'),
(4488,0,  2,  0, 61,0,100,0,    0,    0,0,0,  1,    0, 5000,0,0,0,0,  7,     0,    0,0,0,0,0,0,'Parqual Fintallas - On Gossip Option 0 Selected - Say Text 0'),
(4488,0,  3,  0, 52,0,100,0,    0, 4488,0,0,  1,    4, 3000,0,0,0,0,  7,     0,    0,0,0,0,0,0,'Parqual Fintallas - On Text 0 Over - Say Text 4'),
(4488,0,  4,  5, 52,0,100,0,    4, 4488,0,0, 11, 6767,    2,0,0,0,0,  7,     0,    0,0,0,0,0,0,'Parqual Fintallas - On Text 4 Over - Cast \'Mark of Shame\''),
(4488,0,  5,  0, 61,0,100,0,    0,    0,0,0, 81,    3,    0,0,0,0,0, 10, 32022, 4488,0,0,0,0,0,'Parqual Fintallas - On Text 4 Over - Set npcflags Gossip & Questgiver'),
(4488,0,  6,  7, 62,0,100,0, 4764,    1,0,0, 83,    3,    0,0,0,0,0, 10, 32022, 4488,0,0,0,0,0,'Parqual Fintallas - On Gossip Option 1 Selected - Remove npcflags Gossip & Questgiver'),
(4488,0,  7,  8, 61,0,100,0,    0,    0,0,0, 72,    0,    0,0,0,0,0,  7,     0,    0,0,0,0,0,0,'Parqual Fintallas - On Gossip Option 1 Selected - Close Gossip'),
(4488,0,  8,  0, 61,0,100,0,    0,    0,0,0,  1,    1, 5000,0,0,0,0,  7,     0,    0,0,0,0,0,0,'Parqual Fintallas - On Gossip Option 1 Selected - Say Text 1'),
(4488,0,  9,  0, 52,0,100,0,    1, 4488,0,0,  1,    4, 3000,0,0,0,0,  7,     0,    0,0,0,0,0,0,'Parqual Fintallas - On Text 1 Over - Say Text 4'),
(4488,0, 10, 11, 62,0,100,0, 4767,    2,0,0, 83,    3,    0,0,0,0,0, 10, 32022, 4488,0,0,0,0,0,'Parqual Fintallas - On Gossip Option 2 Selected - Remove npcflags Gossip & Questgiver'),
(4488,0, 11, 12, 61,0,100,0,    0,    0,0,0, 72,    0,    0,0,0,0,0,  7,     0,    0,0,0,0,0,0,'Parqual Fintallas - On Gossip Option 2 Selected - Close Gossip'),
(4488,0, 12,  0, 61,0,100,0,    0,    0,0,0,  1,    2, 5000,0,0,0,0,  7,     0,    0,0,0,0,0,0,'Parqual Fintallas - On Gossip Option 2 Selected - Say Text 2'),
(4488,0, 13,  0, 52,0,100,0,    2, 4488,0,0,  1,    4, 3000,0,0,0,0,  7,     0,    0,0,0,0,0,0,'Parqual Fintallas - On Text 2 Over - Say Text 4'),
(4488,0, 14, 15, 62,0,100,0, 4764,    3,0,0, 83,    3,    0,0,0,0,0, 10, 32022, 4488,0,0,0,0,0,'Parqual Fintallas - On Gossip Option 3 Selected - Remove npcflags Gossip & Questgiver'),
(4488,0, 15, 16, 61,0,100,0,    0,    0,0,0, 72,    0,    0,0,0,0,0,  7,     0,    0,0,0,0,0,0,'Parqual Fintallas - On Gossip Option 3 Selected - Close Gossip'),
(4488,0, 16, 17, 61,0,100,0,    0,    0,0,0,  1,    3, 3000,0,0,0,0,  7,     0,    0,0,0,0,0,0,'Parqual Fintallas - On Gossip Option 3 Selected - Say Text 3'),
(4488,0, 17, 18, 61,0,100,0,    0,    0,0,0,  5,    2,    0,0,0,0,0,  7,     0,    0,0,0,0,0,0,'Parqual Fintallas - On Gossip Option 3 Selected - Play Emote 2 '),
(4488,0, 18, 19, 61,0,100,0,    0,    0,0,0, 15, 6628,    0,0,0,0,0,  7,     0,    0,0,0,0,0,0,'Parqual Fintallas - On Gossip Option 3 Selected - Credit quest 6628 \'Test of Lore\''),
(4488,0, 19,  0, 61,0,100,0,    0,    0,0,0, 81,    3,    0,0,0,0,0, 10, 32022, 4488,0,0,0,0,0,'Parqual Fintallas - On Gossip Option 3 Selected - Set npcflags Gossip & Questgiver');

-- conditions showing gossip menu and gossip menu options only when Quest 6628 is active and Mark of Shame is not.
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 4764 AND `SourceEntry` IN (5821,5822);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup`= 4764 AND `SourceEntry` IN (0,1,2,3);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14, 4764, 5821, 0, 0, 9, 0, 6628, 0, 0, 1, 0, 0, '', 'Show gossip dialog text 5821 if Quest 6628 is NOT taken'),
(14, 4764, 5822, 0, 0, 9, 0, 6628, 0, 0, 0, 0, 0, '', 'Show gossip dialog text 5822 if Quest 6628 is taken (active)'),
(15, 4764,    0, 0, 0, 9, 0, 6628, 0, 0, 0, 0, 0, '', 'Show gossip option 4764 id 0 if Quest 6628 is taken (active)'),
(15, 4764,    1, 0, 0, 9, 0, 6628, 0, 0, 0, 0, 0, '', 'Show gossip option 4764 id 1 if Quest 6628 is taken (active)'),
(15, 4764,    2, 0, 0, 9, 0, 6628, 0, 0, 0, 0, 0, '', 'Show gossip option 4764 id 2 if Quest 6628 is taken (active)'),
(15, 4764,    3, 0, 0, 9, 0, 6628, 0, 0, 0, 0, 0, '', 'Show gossip option 4764 id 3 if Quest 6628 is taken (active)'),
(15, 4764,    0, 0, 0, 1, 0, 6767, 0, 0, 1, 0, 0, '', 'Show gossip option 4764 id 0 if Player does NOT have Aura from spell 6767'),
(15, 4764,    1, 0, 0, 1, 0, 6767, 0, 0, 1, 0, 0, '', 'Show gossip option 4764 id 1 if Player does NOT have Aura from spell 6767'),
(15, 4764,    2, 0, 0, 1, 0, 6767, 0, 0, 1, 0, 0, '', 'Show gossip option 4764 id 2 if Player does NOT have Aura from spell 6767'),
(15, 4764,    3, 0, 0, 1, 0, 6767, 0, 0, 1, 0, 0, '', 'Show gossip option 4764 id 3 if Player does NOT have Aura from spell 6767');
