-- "Plucky" Johnson (Magus Tirth's assistant) in quest 1950 "Get the Scoop":
SET @CHICKEN := 6626;
SET @HUMAN   := 6666;

UPDATE `creature_template` SET `gossip_menu_id`= 231, `AIName`= 'SmartAI' WHERE `entry`= @HUMAN;
UPDATE `creature_template` SET `AIName`= 'SmartAI', `ScriptName`= '' WHERE `entry`= @CHICKEN;

DELETE FROM `gossip_menu` WHERE `entry` IN (231,232) AND `text_id` IN (720,738);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(231, 720),
(232, 738);

DELETE FROM `gossip_menu_option` WHERE `menu_id`= 231 AND `OptionBroadcastTextID`= 2707;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(231, 0, 0, "Tell me the phrase to Tirth's lockbox.", 2707, 1, 1, 232, 0, 0, 0, '', 0);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@CHICKEN,@HUMAN) AND `source_type`= 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`comment`) VALUES
(@CHICKEN,0,0,1,22,0,100,0, 22,0,0,0,11,    9192,   2,0,0,0,0,1,0,0,0,0,0,0,'"Plucky" Johnson - Received Emote 22 - Cast "Plucky" Resumes Human Form'),
(@CHICKEN,0,1,2,61,0,100,0,  0,0,0,0, 3,  @HUMAN,6194,0,0,0,0,1,0,0,0,0,0,0,'"Plucky" Johnson - Received Emote 22 - Morph To Creature "Plucky" Johnson\'s Human Form'),
(@CHICKEN,0,2,3,61,0,100,0,  0,0,0,0, 5,       3,   0,0,0,0,0,1,0,0,0,0,0,0,'"Plucky" Johnson - Received Emote 22 - Play Emote 3'),
(@CHICKEN,0,3,4,61,0,100,0,  0,0,0,0,11,    9220,   0,0,0,0,0,1,0,0,0,0,0,0,'"Plucky" Johnson - Received Emote 22 - Cast "Plucky" Resumes Chicken Form'),
(@CHICKEN,0,4,0,61,0,100,0,  0,0,0,0, 3,@CHICKEN,5369,0,0,0,0,1,0,0,0,0,0,0,'"Plucky" Johnson - Received Emote 22 - Morph To Creature "Plucky" Johnson'),
(@CHICKEN,0,5,6,22,0,100,0,  7,0,0,0,11,    9192,   2,0,0,0,0,1,0,0,0,0,0,0,'"Plucky" Johnson - Received Emote 7 - Cast "Plucky" Resumes Human Form'),
(@CHICKEN,0,6,7,61,0,100,0,  0,0,0,0, 3,  @HUMAN,6194,0,0,0,0,1,0,0,0,0,0,0,'"Plucky" Johnson - Received Emote 7 - Morph To Creature "Plucky" Johnson\'s Human Form'),
(@CHICKEN,0,7,8,61,0,100,0,  0,0,0,0,82,       1,   0,0,0,0,0,1,0,0,0,0,0,0,'"Plucky" Johnson - Received Emote 7 - Add Npc Flags Gossip'),
(@CHICKEN,0,8,0,61,0,100,0,  0,0,0,0,69,       0,   0,0,0,0,0,7,0,0,0,0,0,0,'"Plucky" Johnson - Received Emote 7 - Move To Invoker'),
(@HUMAN,  0,0,1,62,0,100,0,231,0,0,0,72,       0,   0,0,0,0,0,7,0,0,0,0,0,0,'"Plucky" Johnson\'s Human Form - On Gossip Option 0 Selected - Close Gossip'),
(@HUMAN,  0,1,0,61,0,100,0,  0,0,0,0,15,    1950,   0,0,0,0,0,7,0,0,0,0,0,0,'"Plucky" Johnson\'s Human Form - On Gossip Option 0 Selected - Credit Quest 1950');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup`= 231;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,231,0, 0,0,9,0,1950,0,0,0,0,0,'', 'Show gossip menu option 231 only if Quest 1950 is taken (active)');
