-- new gossip_menu_option and creature text entries for:
-- NPC ID 18538 Ishanah, High Priestess of the Aldor
-- NPC ID 18584 Sal'salabim, quest giver
-- NPC ID 18585 Raliq the Drunk, target
-- NPC ID 25967 Zephyr, portal provider

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7725,7729,7735,9205);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(7725,0,0,'Altruis sent me. He said that you could help me.',              15552,1,1,   0,0,0,0,'',0),
(7729,0,0,"I have been sent by Sal'salabim to collect a debt that you owe. Pay up or I'm going to have to hurt you.",15560,1,1,0,0,0,0,'',0),
(7735,0,0,"Who are the Sha'tar?",                                          15642,1,1,7736,0,0,0,'',0),
(7735,1,0,"Isn't Shattrath a draenei city?  Why do you allow others here?",15644,1,1,7737,0,0,0,'',0),
(9205,0,0,'Take me to the Caverns of Time.',                               25111,1,1,   0,0,0,0,'',0);

-- conditions for the gossip menu options as a preparation for future SAI scripts
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup` IN (7725,7729);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15, 7725,0, 0,0, 9,0, 10004,0,0,0,0,0,'', 'Show gossip menu option 7725 only if Quest 10004 is taken (active)'),
(15, 7729,0, 0,0, 9,0, 10009,0,0,0,0,0,'', 'Show gossip menu option 7729 only if Quest 10009 is taken (active)');

-- insert missing creature text (say lines) for Sal'salabim and Raliq the Drunk
DELETE FROM `creature_text` WHERE `entry` IN (18584,18585) AND `groupid`= 0;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(18584,0,0,'[Demonic] Ka kalix!',        12,0,100,0,0,0,15551,0,"Sal'salabim SAY_DEMONIC_AGGRO"),
(18585,0,0,'Raliq teach you lesson now!',12,0,100,0,0,0,15567,0,'Raliq the Drunk SAY_RALIQ_ATTACK');

-- insert missing quest Progress gossip, quest 10004
DELETE FROM `quest_request_items` WHERE `ID` = 10004;
INSERT INTO `quest_request_items` (`ID`,`EmoteOnComplete`,`EmoteOnIncomplete`,`CompletionText`,`VerifiedBuild`) VALUES
(10004,0,0,"<Sal'salabim rubs his head.>$B$B[Demonic] Ik il romath sardon.",0);

-- remove core script for Ishanah, High Priestess of the Aldor
UPDATE `creature_template` SET `ScriptName`= '' WHERE `entry`= 18538;
