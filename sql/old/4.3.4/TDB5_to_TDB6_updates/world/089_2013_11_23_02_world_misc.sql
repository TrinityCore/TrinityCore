-- Fixing quest 13010 Krolmir, Hammer of Storms
UPDATE `conditions` SET `ConditionTypeOrReference`=9, `ConditionValue1`=13010, `NegativeCondition`=0, `Comment`= 'Show gossip option if player has quest taken' WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9900 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9900 AND `SourceEntry`=1;
UPDATE `gossip_menu_option` SET `action_menu_id`=9899 WHERE `menu_id`=9900 AND `id`=0;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9900 AND `id`=1;

-- King Jokkum SAI
SET @ENTRY := 30105;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,9899,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"King Jokkum - Gossip Option Select - Cloase gossip window"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,61319,0,0,0,0,0,7,0,0,0,0,0,0,0,"King Jokkum - Gossip Option Select - Cast Jokkum Scriptcast on player");

-- NPC talk text for King Jokkum Quest 13010 Krolmir, Hammer of Storms
DELETE FROM `creature_text` WHERE `entry`=30331;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(30331,0,0, 'Hold on, little $r.',12,0,100,0,0,0, 'King Jokkum - Mount up'),
(30331,1,0, 'Thorim! Come, show yourself!',14,0,100,0,0,0, 'King Jokkum - Conversation start'),
(30331,2,0, 'The deeds of your $r servant defy $g his:her; stature, Stormlord. $g His:Her; efforts have succeeded in softening the hearts of my people.',12,0,100,396,0,0, 'King Jokkum - Conversation 20 sec in'),
(30331,3,0, 'Never have such humble words come from mighty Thorim. I shall deliver your words to Dun Niffelem.',12,0,100,396,0,0, 'King Jokkum - Conversation 40 sec in'),
(30331,4,0, 'The events of that dark day are hereby forgiven by my people.  They shall never again be spoken of.',12,0,100,396,0,0, 'King Jokkum - Conversation 48 sec in'),
(30331,5,0, 'To signify our reforged friendship, I have something which belongs to you...',12,0,100,0,0,0, 'King Jokkum - Conversation 57 sec in'),
(30331,6,0, 'As the great explosion filled the region, my father cast a rune at the great hammer that it might not be had by our enemies. It was his final act...',12,0,100,396,0,0, 'King Jokkum - Conversation 63 sec in'),
(30331,7,0, 'We welcome the opportunity to fight by your side, mighty Thorim.',12,0,100,0,0,0, 'King Jokkum - Conversation 75 sec in'),
(30331,8,0, 'I must return to Dun Niffilem. We shall speak again soon, Stormlord.',12,0,100,396,0,0, 'King Jokkum - Conversation 80 sec in');

-- NPC talk text for Thorim Quest 13010 Krolmir, Hammer of Storms
DELETE FROM `creature_text` WHERE `entry`=30390;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(30390,0,0, 'King Jokkum, you have summoned me?',12,0,100,0,0,0, 'Thorim  - Conversation 18 sec in'),
(30390,1,0, 'Jokkum, son of Arngrim, I have always regretted my actions here. In my grief, I brought great harm to those closest to me.',12,0,100,0,0,0, 'Thorim  - Conversation 26 sec in'),
(30390,2,0, 'I would ask your forgiveness for the suffering I have caused you and your people.',12,0,100,0,0,0, 'Thorim - Conversation 32 sec in'),
(30390,3,0, 'Krolmir... I thank you Jokkum. I hadn''t dared hope it still existed. It shall soon see glorious battle once again!',12,0,100,396,0,0, 'Thorim - Conversation 68 sec in');
