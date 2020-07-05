--
UPDATE `creature_text` SET `comment` = "Exarch Admetius" WHERE `CreatureID` = 17658;

-- Injured Night Elf Priestess
UPDATE `creature_template` SET `gossip_menu_id` = 7543 WHERE `entry` = 17117;
DELETE FROM `gossip_menu` WHERE `MenuID` = 7543;
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES
(7543,9151),
(7543,9152);
DELETE FROM `npc_text` WHERE `ID` = 9151;
INSERT INTO `npc_text` (`ID`,`text0_0`,`text0_1`,`BroadcastTextID0`,`lang0`,`Probability0`,`EmoteDelay0_0`,`Emote0_0`) VALUES
(9151,"","I am here to give thanks to the one that saved my life.",14677,0,1,0,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 7543;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,7543,9151,0,0,8,0,9759,0,0,1,0,0,"","Group 0: Show gossip text 9151 if quest 'Ending Their World' is not rewarded"),
(14,7543,9151,0,0,23,1,3584,0,0,0,0,0,"","Group 0: Show gossip text 9151 if creature is located in Blood Watch"),
(14,7543,9152,0,0,8,0,9759,0,0,0,0,0,"","Group 0: Show gossip text 9152 if quest 'Ending Their World' is rewarded"),
(14,7543,9152,0,0,23,1,3584,0,0,0,0,0,"","Group 0: Show gossip text 9152 if creature is located in Blood Watch");

DELETE FROM `creature_text` WHERE `CreatureID` = 17117 AND `GroupID` = 5;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(17117,5,0,"%s hugs you.",16,0,100,0,0,0,14679,0,"Injured Night Elf Priestess");

-- Seems she doesn't play any emote, removed
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17117 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17117,0,0,1,54,0,100,0,0,0,0,0,0,91,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Night Elf Priestess - On Just Summoned - Remove Flag Standstate Sleep"),
(17117,0,1,0,61,0,100,0,0,0,0,0,0,82,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Night Elf Priestess - On Link - Add Npc Flag Gossip"),
(17117,0,2,0,64,0,100,0,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Night Elf Priestess - On Gossip Hello - Say Line 5"),
(17117,0,3,0,38,0,100,0,1,1,0,0,0,91,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Night Elf Priestess - On Data Set 1 1 - Set Bytes 1"),
(17117,0,4,0,38,0,100,0,2,2,0,0,0,90,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Night Elf Priestess - On Data Set 2 2 - Set Bytes 1");

-- Acteon
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17110 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17110,0,0,1,54,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Acteon - On Just Summoned - Set Event Phase 1"),
(17110,0,1,0,61,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Acteon - On Link - Remove Npc Flag Questgiver"),
(17110,0,2,0,1,1,100,0,5000,5000,5000,5000,0,10,4,21,0,0,0,0,1,0,0,0,0,0,0,0,0,"Acteon - Out of Combat - Play Random Emote (4, 21) (Phase 1)");

-- Priestess Kyleen Il'dinare
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17241 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17241,0,0,1,54,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Priestess Kyleen Il'dinare - On Just Summoned - Set Event Phase 1"),
(17241,0,1,0,61,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Priestess Kyleen Il'dinare - On Link - Remove Npc Flag Questgiver"),
(17241,0,2,0,1,1,100,0,5000,5000,5000,5000,0,10,10,71,0,0,0,0,1,0,0,0,0,0,0,0,0,"Priestess Kyleen Il'dinare - Out of Combat - Play Random Emote (10, 71) (Phase 1)"),
(17241,0,3,0,20,0,100,0,9514,0,0,0,0,80,1724100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Priestess Kyleen Il'dinare - On Quest 'Rune Covered Tablet' Rewarded - Run Script");

-- Archaeologist Adamant Ironheart
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17242 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17242,0,0,1,54,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Archaeologist Adamant Ironheart - On Just Summoned - Set Event Phase 1"),
(17242,0,1,0,61,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Archaeologist Adamant Ironheart - On Link - Remove Npc Flag Questgiver"),
(17242,0,2,0,1,1,100,0,6000,6000,6000,6000,0,10,10,71,0,0,0,0,1,0,0,0,0,0,0,0,0,"Archaeologist Adamant Ironheart - Out of Combat - Play Random Emote (10, 71) (Phase 1)"),
(17242,0,3,0,38,0,100,0,1,1,0,0,0,53,0,1724200,0,0,0,1,1,0,0,0,0,0,0,0,0,"Archaeologist Adamant Ironheart - On Data Set 1 1 - Start Waypoint"),
(17242,0,4,0,38,0,100,0,2,2,0,0,0,53,0,1724201,0,0,0,1,1,0,0,0,0,0,0,0,0,"Archaeologist Adamant Ironheart - On Data Set 2 2 - Start Waypoint"),
(17242,0,5,0,40,0,100,0,1,1724201,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,6.26573,"Archaeologist Adamant Ironheart - On Reached Waypoint 1 - Set Orientation");

-- Stillpine the Younger
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17445 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17445,0,0,0,54,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine the Younger - On Just Summoned - Remove Npc Flag Questgiver"),
(17445,0,1,0,20,0,100,0,9573,0,0,0,0,80,1744500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine the Younger - On Quest 'Chieftain Oomooroo' Finished - Run Script");

-- Diktynna
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17101 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17101,0,0,0,54,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Diktynna - On Just Summoned - Set Event Phase 1"),
(17101,0,1,0,1,1,100,0,5000,5000,5000,5000,0,10,4,21,0,0,0,0,1,0,0,0,0,0,0,0,0,"Diktynna - Out of Combat - Play Random Emote (4, 21) (Phase 1)"),
(17101,0,2,0,20,0,100,0,9452,0,0,0,0,5,24,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Diktynna - On Quest 'Red Snapper - Very Tasty!' Rewarded - Play Emote 24");

-- Daedal
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17215 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17215,0,0,0,54,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Daedal - On Just Summoned - Set Event Phase 1"),
(17215,0,1,0,1,1,100,0,5000,5000,5000,5000,0,10,4,21,0,0,0,0,1,0,0,0,0,0,0,0,0,"Daedal - Out of Combat - Play Random Emote (4, 21) (Phase 1)"),
(17215,0,2,0,38,0,100,0,1,1,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Daedal - On Data Set 1 1 - Set NPC Flags"),
(17215,0,3,0,38,0,100,0,2,2,0,0,0,81,83,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Daedal - On Data Set 2 2 - Set NPC Flags"),
(17215,0,4,0,20,0,100,0,9473,0,0,0,0,80,1721500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Daedal - On Quest 'An Alternative Alternative' Rewarded - Run Script");

-- High Chief Stillpine
DELETE FROM `gossip_menu` WHERE `MenuID` = 7434 AND `TextID` IN (9145,9146);
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES
(7434,9145),
(7434,9146);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 7434 AND `SourceEntry` IN (9145,9146);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,7434,9145,0,0,8,0,9759,0,0,1,0,0,"","Group 0: Show gossip text 9145 if quest 'Ending Their World' is not rewarded"),
(14,7434,9145,0,0,23,1,3584,0,0,0,0,0,"","Group 0: Show gossip text 9145 if creature is located in Blood Watch"),
(14,7434,9146,0,0,8,0,9759,0,0,0,0,0,"","Group 0: Show gossip text 9146 if quest 'Ending Their World' is rewarded"),
(14,7434,9146,0,0,23,1,3584,0,0,0,0,0,"","Group 0: Show gossip text 9146 if creature is located in Blood Watch");

-- Exarch Menelaous
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17116 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17116,0,0,0,54,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Exarch Menelaous - On Just Summoned - Set Event Phase 1"),
(17116,0,1,0,1,1,100,0,6000,6000,6000,6000,0,10,4,21,0,0,0,0,1,0,0,0,0,0,0,0,0,"Exarch Menelaous - Out of Combat - Play Random Emote (4, 21) (Phase 1)"),
(17116,0,2,0,64,0,100,0,0,0,0,0,0,33,17116,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Exarch Menelaous - On Gossip Hello - Quest Credit 'The Kessel Run'");

DELETE FROM `gossip_menu` WHERE `MenuID` = 7370 AND `TextID` IN (9153,9154);
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES
(7370,9153),
(7370,9154);
DELETE FROM `npc_text` WHERE `ID` = 9153;
INSERT INTO `npc_text` (`ID`,`text0_0`,`text0_1`,`BroadcastTextID0`,`lang0`,`Probability0`,`EmoteDelay0_0`,`Emote0_0`) VALUES
(9153,"We are here to support our hero!","",14680,0,1,0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 7370 AND `SourceEntry` IN (9153,9154);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,7370,9153,0,0,8,0,9759,0,0,1,0,0,"","Group 0: Show gossip text 9153 if quest 'Ending Their World' is not rewarded"),
(14,7370,9153,0,0,23,1,3584,0,0,0,0,0,"","Group 0: Show gossip text 9153 if creature is located in Blood Watch"),
(14,7370,9154,0,0,8,0,9759,0,0,0,0,0,"","Group 0: Show gossip text 9154 if quest 'Ending Their World' is rewarded"),
(14,7370,9154,0,0,23,1,3584,0,0,0,0,0,"","Group 0: Show gossip text 9154 if creature is located in Blood Watch");

-- Prophet Velen
DELETE FROM `gossip_menu` WHERE `MenuID` = 7414 AND `TextID` IN (9162,9163);
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES
(7414,9162),
(7414,9163);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 7414 AND `SourceEntry` IN (9162,9163);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,7414,9162,0,0,8,0,9759,0,0,1,0,0,"","Group 0: Show gossip text 9162 if quest 'Ending Their World' is not rewarded"),
(14,7414,9162,0,0,23,1,3584,0,0,0,0,0,"","Group 0: Show gossip text 9162 if creature is located in Blood Watch"),
(14,7414,9163,0,0,8,0,9759,0,0,0,0,0,"","Group 0: Show gossip text 9163 if quest 'Ending Their World' is rewarded"),
(14,7414,9163,0,0,23,1,3584,0,0,0,0,0,"","Group 0: Show gossip text 9163 if creature is located in Blood Watch");

-- Admiral Odesyus
DELETE FROM `gossip_menu` WHERE `MenuID` = 7399 AND `TextID` IN (9148,9149);
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES
(7399,9148),
(7399,9149);
DELETE FROM `npc_text` WHERE `ID` = 9148;
INSERT INTO `npc_text` (`ID`,`text0_0`,`text0_1`,`BroadcastTextID0`,`lang0`,`Probability0`,`EmoteDelay0_0`,`Emote0_0`) VALUES
(9148,"A glorious victory!","",14674,0,1,0,5);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 7399 AND `SourceEntry` IN (9148,9149);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,7399,9148,0,0,8,0,9759,0,0,1,0,0,"","Group 0: Show gossip text 9148 if quest 'Ending Their World' is not rewarded"),
(14,7399,9148,0,0,23,1,3584,0,0,0,0,0,"","Group 0: Show gossip text 9148 if creature is located in Blood Watch"),
(14,7399,9149,0,0,8,0,9759,0,0,0,0,0,"","Group 0: Show gossip text 9149 if quest 'Ending Their World' is rewarded"),
(14,7399,9149,0,0,23,1,3584,0,0,0,0,0,"","Group 0: Show gossip text 9149 if creature is located in Blood Watch");

-- Cowlen
DELETE FROM `gossip_menu` WHERE `MenuID` = 7403 AND `TextID` IN (9158,9159);
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES
(7403,9158),
(7403,9159);
DELETE FROM `npc_text` WHERE `ID` = 9158;
INSERT INTO `npc_text` (`ID`,`text0_0`,`text0_1`,`BroadcastTextID0`,`lang0`,`Probability0`,`EmoteDelay0_0`,`Emote0_0`,`EmoteDelay0_1`,`Emote0_1`) VALUES
(9158,"We have traveled far to celebrate the hero of the draenei people.","",14685,0,1,0,1,0,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 7403 AND `SourceEntry` IN (9158,9159);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 7403;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,7403,9158,0,0,8,0,9759,0,0,1,0,0,"","Group 0: Show gossip text 9158 if quest 'Ending Their World' is not rewarded"),
(14,7403,9158,0,0,23,1,3584,0,0,0,0,0,"","Group 0: Show gossip text 9158 if creature is located in Blood Watch"),
(14,7403,9159,0,0,8,0,9759,0,0,0,0,0,"","Group 0: Show gossip text 9159 if quest 'Ending Their World' is rewarded"),
(14,7403,9159,0,0,23,1,3584,0,0,0,0,0,"","Group 0: Show gossip text 9159 if creature is located in Blood Watch"),
(15,7403,0,0,0,23,1,3584,0,0,1,0,0,"","Group 0: Show Gossip Option 0 if creature is not located in Blood Watch");

-- Kessel
DELETE FROM `gossip_menu` WHERE `MenuID` = 7462 AND `TextID` IN (9155,9156);
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES
(7462,9155),
(7462,9156);
DELETE FROM `npc_text` WHERE `ID` = 9155;
INSERT INTO `npc_text` (`ID`,`text0_0`,`text0_1`,`BroadcastTextID0`,`lang0`,`Probability0`,`EmoteDelay0_0`,`Emote0_0`) VALUES
(9155,"I have come to support the draenei champion!","",14682,0,1,0,5);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 7462 AND `SourceEntry` IN (9155,9156);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,7462,9155,0,0,8,0,9759,0,0,1,0,0,"","Group 0: Show gossip text 9155 if quest 'Ending Their World' is not rewarded"),
(14,7462,9155,0,0,23,1,3584,0,0,0,0,0,"","Group 0: Show gossip text 9155 if creature is located in Blood Watch"),
(14,7462,9156,0,0,8,0,9759,0,0,0,0,0,"","Group 0: Show gossip text 9156 if quest 'Ending Their World' is rewarded"),
(14,7462,9156,0,0,23,1,3584,0,0,0,0,0,"","Group 0: Show gossip text 9156 if creature is located in Blood Watch");

-- "Cookie" McWeaksauce
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 17246 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,12,17246,0,0,23,1,3584,0,0,1,0,0,"","Group 0: Execute SAI (Action 11) if creature is not located in Blood Watch");
