-- Parqual Fintallas
-- https://www.youtube.com/watch?v=_QI3SbSWQ3M&t=421
-- Text 8379 "Kil'jaeden is my answer." was never been used
UPDATE `gossip_menu_option` SET `OptionText` = "Ner'zhul is my answer.", `OptionBroadcastTextID` = 8380 WHERE `MenuID` = 4764 AND `OptionID` = 2;
DELETE FROM `gossip_menu_option` WHERE `MenuID` = 4764 AND `OptionID` = 3;
-- https://wow.gamepedia.com/Test_of_Lore_(6)#Details
-- Patchnote: By Patch 3.3, the mark only lasts 10 minutes, and does not prevent you from answering the question again.
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 4764;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,4764,0,0,0,9,0,6628,0,0,0,0,0,"","Group 0: Show Gossip Option 0 if player has taken quest 'Test of Lore'"),
(15,4764,1,0,0,9,0,6628,0,0,0,0,0,"","Group 0: Show Gossip Option 1 if player has taken quest 'Test of Lore'"),
(15,4764,2,0,0,9,0,6628,0,0,0,0,0,"","Group 0: Show Gossip Option 2 if player has taken quest 'Test of Lore'");

-- Parqual Fintallas SAI
SET @ID := 4488;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,4,62,0,100,0,4764,0,0,0,0,11,6767,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Parqual Fintallas - On Gossip Option 0 Selected - Cast 'Mark of Shame'"),
(@ID,0,1,4,62,0,100,0,4764,1,0,0,0,11,6767,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Parqual Fintallas - On Gossip Option 1 Selected - Cast 'Mark of Shame'"),
(@ID,0,2,3,62,0,100,0,4764,2,0,0,0,15,6628,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Parqual Fintallas - On Gossip Option 2 Selected - Quest Credit 'Test of Lore'"),
(@ID,0,3,5,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Parqual Fintallas - On Link - Say Line 0"),
(@ID,0,4,5,61,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Parqual Fintallas - On Link - Say Line 1"),
(@ID,0,5,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Parqual Fintallas - On Link - Close Gossip");

-- Previously added texts are not used, also creatures almost never uses texts with $B, those belongs only to gossip texts
DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"You have done well, $n. Continue your search for knowledge, and remember the history you have learned.",12,0,100,2,0,0,1608,0,"Parqual Fintallas"),
(@ID,1,0,"I'm afraid not, $n. Now, feel the shame you have brought upon yourself.",12,0,100,0,0,0,8394,0,"Parqual Fintallas");

-- Braug Dimspirit
-- https://www.youtube.com/watch?v=_QI3SbSWQ3M&t=277
-- Blizzard almost never checks if quest is completed in case of gossip options or texts,
-- they only check if quest is taken(shown in video)
-- So gossip options and texts are visible even if quest is completed
-- Also current conditions changes absolutely nothing
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 4763;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,4763,5819,0,0,9,0,6627,0,0,1,0,0,"","Group 0: Show gossip text 5819 if player has not taken quest 'Test of Lore'"),
(14,4763,5820,0,0,9,0,6627,0,0,0,0,0,"","Group 0: Show gossip text 5820 if player has taken quest 'Test of Lore'");

-- Braug Dimspirit SAI
SET @ID := 4489;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 448900 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,4,62,0,100,0,4763,0,0,0,0,11,6766,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Braug Dimspirit - On Gossip Option 0 Selected - Cast 'Test of Lore'"),
(@ID,0,1,6,62,0,100,0,4763,1,0,0,0,15,6627,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Braug Dimspirit - On Gossip Option 1 Selected - Quest Credit 'Test of Lore'"),
(@ID,0,2,4,62,0,100,0,4763,2,0,0,0,11,6766,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Braug Dimspirit - On Gossip Option 2 Selected - Cast 'Test of Lore'"),
(@ID,0,3,4,62,0,100,0,4763,3,0,0,0,11,6766,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Braug Dimspirit - On Gossip Option 3 Selected - Cast 'Test of Lore'"),
(@ID,0,4,5,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Braug Dimspirit - On Link - Say Line 0"),
-- I really don't like this part but without it player will be able to answer again in 2 sec before teleport
-- And noone said it is possible
(@ID,0,5,6,61,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Braug Dimspirit - On Link - Remove NPC Flags Gossip & Questgiver"),
(@ID,0,6,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Braug Dimspirit - On Link - Close Gossip"),
(@ID,0,7,0,31,0,100,0,6766,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Braug Dimspirit - On Target Spellhit 'Test of Lore' - Add NPC Flags Gossip & Questgiver");

-- https://classic.wowhead.com/npc=4489/braug-dimspirit
DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"That is the wrong answer, $n. Be off with you.",12,0,100,0,0,0,8393,0,"Braug Dimspirit");
