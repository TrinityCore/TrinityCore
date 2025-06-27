-- All three quests can be shown at once, we don't have to add such conditions to check if player has ring
-- https://youtu.be/7ag6xbC_Yrk?t=771
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 19 AND `SourceEntry` BETWEEN 8764 AND 8766;

-- Source: https://www.wowhead.com/quest=8752/the-path-of-the-conqueror#comments:id=1160265
-- I don't know if valid for 8.x.x
DELETE FROM `gossip_menu_option` WHERE `MenuID` = 6539 AND `OptionID` BETWEEN 1 AND 15;
INSERT INTO `gossip_menu_option` (`MenuID`,`OptionID`,`OptionIcon`,`OptionText`,`OptionBroadcastTextID`,`OptionType`,`OptionNpcFlag`,`ActionMenuID`,`ActionPoiID`,`BoxCoded`,`BoxMoney`,`BoxText`,`BoxBroadcastTextID`,`VerifiedBuild`) VALUES
(6539,1,0,"Anachronos, I have lost the signet ring. Could you supply me with a replacement?",11348,1,1,0,0,0,0,"",0,0),
(6539,2,0,"Anachronos, I have lost the signet ring. Could you supply me with a replacement?",11348,1,1,0,0,0,0,"",0,0),
(6539,3,0,"Anachronos, I have lost the signet ring. Could you supply me with a replacement?",11348,1,1,0,0,0,0,"",0,0),
(6539,4,0,"Anachronos, I have lost the signet ring. Could you supply me with a replacement?",11348,1,1,0,0,0,0,"",0,0),
(6539,5,0,"Anachronos, I have lost the signet ring. Could you supply me with a replacement?",11348,1,1,0,0,0,0,"",0,0),
(6539,6,0,"Anachronos, I have lost the signet ring. Could you supply me with a replacement?",11348,1,1,0,0,0,0,"",0,0),
(6539,7,0,"Anachronos, I have lost the signet ring. Could you supply me with a replacement?",11348,1,1,0,0,0,0,"",0,0),
(6539,8,0,"Anachronos, I have lost the signet ring. Could you supply me with a replacement?",11348,1,1,0,0,0,0,"",0,0),
(6539,9,0,"Anachronos, I have lost the signet ring. Could you supply me with a replacement?",11348,1,1,0,0,0,0,"",0,0),
(6539,10,0,"Anachronos, I have lost the signet ring. Could you supply me with a replacement?",11348,1,1,0,0,0,0,"",0,0),
(6539,11,0,"Anachronos, I have lost the signet ring. Could you supply me with a replacement?",11348,1,1,0,0,0,0,"",0,0),
(6539,12,0,"Anachronos, I have lost the signet ring. Could you supply me with a replacement?",11348,1,1,0,0,0,0,"",0,0),
(6539,13,0,"Anachronos, I have lost the signet ring. Could you supply me with a replacement?",11348,1,1,0,0,0,0,"",0,0),
(6539,14,0,"Anachronos, I have lost the signet ring. Could you supply me with a replacement?",11348,1,1,0,0,0,0,"",0,0),
(6539,15,0,"Anachronos, I have lost the signet ring. Could you supply me with a replacement?",11348,1,1,0,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 6539 AND `SourceEntry` BETWEEN 1 AND 15;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,6539,1,0,0,5,0,910,8,0,0,0,0,"","Group 0: Show Gossip Option 1 if player is Neutral with Brood of Nozdormu"),
(15,6539,2,0,0,5,0,910,16,0,0,0,0,"","Group 0: Show Gossip Option 2 if player is Friendly with Brood of Nozdormu"),
(15,6539,3,0,0,5,0,910,32,0,0,0,0,"","Group 0: Show Gossip Option 3 if player is Honored with Brood of Nozdormu"),
(15,6539,4,0,0,5,0,910,64,0,0,0,0,"","Group 0: Show Gossip Option 4 if player is Revered with Brood of Nozdormu"),
(15,6539,5,0,0,5,0,910,128,0,0,0,0,"","Group 0: Show Gossip Option 5 if player is Exalted with Brood of Nozdormu"),

(15,6539,6,0,0,5,0,910,8,0,0,0,0,"","Group 0: Show Gossip Option 6 if player is Neutral with Brood of Nozdormu"),
(15,6539,7,0,0,5,0,910,16,0,0,0,0,"","Group 0: Show Gossip Option 7 if player is Friendly with Brood of Nozdormu"),
(15,6539,8,0,0,5,0,910,32,0,0,0,0,"","Group 0: Show Gossip Option 8 if player is Honored with Brood of Nozdormu"),
(15,6539,9,0,0,5,0,910,64,0,0,0,0,"","Group 0: Show Gossip Option 9 if player is Revered with Brood of Nozdormu"),
(15,6539,10,0,0,5,0,910,128,0,0,0,0,"","Group 0: Show Gossip Option 10 if player is Exalted with Brood of Nozdormu"),

(15,6539,11,0,0,5,0,910,8,0,0,0,0,"","Group 0: Show Gossip Option 11 if player is Neutral with Brood of Nozdormu"),
(15,6539,12,0,0,5,0,910,16,0,0,0,0,"","Group 0: Show Gossip Option 12 if player is Friendly with Brood of Nozdormu"),
(15,6539,13,0,0,5,0,910,32,0,0,0,0,"","Group 0: Show Gossip Option 13 if player is Honored with Brood of Nozdormu"),
(15,6539,14,0,0,5,0,910,64,0,0,0,0,"","Group 0: Show Gossip Option 14 if player is Revered with Brood of Nozdormu"),
(15,6539,15,0,0,5,0,910,128,0,0,0,0,"","Group 0: Show Gossip Option 15 if player is Exalted with Brood of Nozdormu"),

(15,6539,1,0,0,2,0,21196,1,1,1,0,0,"","Group 0: Show Gossip Option 1 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),
(15,6539,2,0,0,2,0,21197,1,1,1,0,0,"","Group 0: Show Gossip Option 2 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),
(15,6539,3,0,0,2,0,21198,1,1,1,0,0,"","Group 0: Show Gossip Option 3 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),
(15,6539,4,0,0,2,0,21199,1,1,1,0,0,"","Group 0: Show Gossip Option 4 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),
(15,6539,5,0,0,2,0,21200,1,1,1,0,0,"","Group 0: Show Gossip Option 5 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),
(15,6539,5,0,0,2,0,21205,1,1,1,0,0,"","Group 0: Show Gossip Option 5 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),
(15,6539,5,0,0,2,0,21210,1,1,1,0,0,"","Group 0: Show Gossip Option 5 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),

(15,6539,6,0,0,2,0,21201,1,1,1,0,0,"","Group 0: Show Gossip Option 6 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),
(15,6539,7,0,0,2,0,21202,1,1,1,0,0,"","Group 0: Show Gossip Option 7 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),
(15,6539,8,0,0,2,0,21203,1,1,1,0,0,"","Group 0: Show Gossip Option 8 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),
(15,6539,9,0,0,2,0,21204,1,1,1,0,0,"","Group 0: Show Gossip Option 9 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),
(15,6539,10,0,0,2,0,21205,1,1,1,0,0,"","Group 0: Show Gossip Option 10 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),
(15,6539,10,0,0,2,0,21200,1,1,1,0,0,"","Group 0: Show Gossip Option 10 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),
(15,6539,10,0,0,2,0,21210,1,1,1,0,0,"","Group 0: Show Gossip Option 10 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),

(15,6539,11,0,0,2,0,21206,1,1,1,0,0,"","Group 0: Show Gossip Option 11 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),
(15,6539,12,0,0,2,0,21207,1,1,1,0,0,"","Group 0: Show Gossip Option 12 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),
(15,6539,13,0,0,2,0,21208,1,1,1,0,0,"","Group 0: Show Gossip Option 13 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),
(15,6539,14,0,0,2,0,21209,1,1,1,0,0,"","Group 0: Show Gossip Option 14 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),
(15,6539,15,0,0,2,0,21210,1,1,1,0,0,"","Group 0: Show Gossip Option 15 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),
(15,6539,15,0,0,2,0,21200,1,1,1,0,0,"","Group 0: Show Gossip Option 15 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),
(15,6539,15,0,0,2,0,21205,1,1,1,0,0,"","Group 0: Show Gossip Option 15 if player does not have item 'Signet Ring of the Bronze Dragonflight'"),

(15,6539,1,0,0,8,0,8747,0,0,0,0,0,"","Group 0: Show Gossip Option 1 if quest 'The Path of the Protector' is rewarded"),
(15,6539,2,0,0,8,0,8748,0,0,0,0,0,"","Group 0: Show Gossip Option 2 if quest 'The Path of the Protector' is rewarded"),
(15,6539,3,0,0,8,0,8749,0,0,0,0,0,"","Group 0: Show Gossip Option 3 if quest 'The Path of the Protector' is rewarded"),
(15,6539,4,0,0,8,0,8750,0,0,0,0,0,"","Group 0: Show Gossip Option 4 if quest 'The Path of the Protector' is rewarded"),
(15,6539,5,0,0,8,0,8751,0,0,0,0,0,"","Group 0: Show Gossip Option 5 if quest 'The Protector of Kalimdor' is rewarded"),

(15,6539,6,0,0,8,0,8752,0,0,0,0,0,"","Group 0: Show Gossip Option 6 if quest 'The Path of the Conqueror' is rewarded"),
(15,6539,7,0,0,8,0,8753,0,0,0,0,0,"","Group 0: Show Gossip Option 7 if quest 'The Path of the Conqueror' is rewarded"),
(15,6539,8,0,0,8,0,8754,0,0,0,0,0,"","Group 0: Show Gossip Option 8 if quest 'The Path of the Conqueror' is rewarded"),
(15,6539,9,0,0,8,0,8755,0,0,0,0,0,"","Group 0: Show Gossip Option 9 if quest 'The Path of the Conqueror' is rewarded"),
(15,6539,10,0,0,8,0,8756,0,0,0,0,0,"","Group 0: Show Gossip Option 10 if quest 'The Qiraji Conqueror' is rewarded"),

(15,6539,11,0,0,8,0,8757,0,0,0,0,0,"","Group 0: Show Gossip Option 11 if quest 'The Path of the Invoker' is rewarded"),
(15,6539,12,0,0,8,0,8758,0,0,0,0,0,"","Group 0: Show Gossip Option 12 if quest 'The Path of the Invoker' is rewarded"),
(15,6539,13,0,0,8,0,8759,0,0,0,0,0,"","Group 0: Show Gossip Option 13 if quest 'The Path of the Invoker' is rewarded"),
(15,6539,14,0,0,8,0,8760,0,0,0,0,0,"","Group 0: Show Gossip Option 14 if quest 'The Path of the Invoker' is rewarded"),
(15,6539,15,0,0,8,0,8761,0,0,0,0,0,"","Group 0: Show Gossip Option 15 if quest 'The Grand Invoker' is rewarded");

SET @ID := 15192;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Source: https://www.youtube.com/watch?v=0ExXIlU4EYM
(@ID,0,0,1,2,0,100,1,0,20,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anachronos - Between 0-20% Health - Despawn (3000) (No Repeat)"),
(@ID,0,1,2,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anachronos - On Link - Say Line 0"),
(@ID,0,2,0,61,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anachronos - On Link - Set Reactstate Passive"),
-- Source: https://youtu.be/7ag6xbC_Yrk?t=771
(@ID,0,3,19,62,0,100,0,6539,0,0,0,11,25861,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anachronos - On Gossip Option 0 Selected - Cast 'Call Scepter'"),

(@ID,0,4,19,62,0,100,0,6539,1,0,0,11,25932,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anachronos - On Gossip Option 1 Selected - Cast 'Signet Ring of the Bronze Dragonflight TANK R1'"),
(@ID,0,5,19,62,0,100,0,6539,2,0,0,11,25933,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anachronos - On Gossip Option 2 Selected - Cast 'Signet Ring of the Bronze Dragonflight TANK R2'"),
(@ID,0,6,19,62,0,100,0,6539,3,0,0,11,25934,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anachronos - On Gossip Option 3 Selected - Cast 'Signet Ring of the Bronze Dragonflight TANK R3'"),
(@ID,0,7,19,62,0,100,0,6539,4,0,0,11,25935,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anachronos - On Gossip Option 4 Selected - Cast 'Signet Ring of the Bronze Dragonflight TANK R4'"),
(@ID,0,8,19,62,0,100,0,6539,5,0,0,11,25936,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anachronos - On Gossip Option 5 Selected - Cast 'Signet Ring of the Bronze Dragonflight TANK R5'"),
(@ID,0,9,19,62,0,100,0,6539,6,0,0,11,25927,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anachronos - On Gossip Option 6 Selected - Cast 'Signet Ring of the Bronze Dragonflight DPS R1'"),
(@ID,0,10,19,62,0,100,0,6539,7,0,0,11,25928,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anachronos - On Gossip Option 7 Selected - Cast 'Signet Ring of the Bronze Dragonflight DPS R2'"),
(@ID,0,11,19,62,0,100,0,6539,8,0,0,11,25929,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anachronos - On Gossip Option 8 Selected - Cast 'Signet Ring of the Bronze Dragonflight DPS R3'"),
(@ID,0,12,19,62,0,100,0,6539,9,0,0,11,25930,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anachronos - On Gossip Option 9 Selected - Cast 'Signet Ring of the Bronze Dragonflight DPS R4'"),
(@ID,0,13,19,62,0,100,0,6539,10,0,0,11,25931,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anachronos - On Gossip Option 10 Selected - Cast 'Signet Ring of the Bronze Dragonflight DPS R5'"),
(@ID,0,14,19,62,0,100,0,6539,11,0,0,11,25921,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anachronos - On Gossip Option 11 Selected - Cast 'Signet Ring of the Bronze Dragonflight CASTER R1'"),
(@ID,0,15,19,62,0,100,0,6539,12,0,0,11,25922,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anachronos - On Gossip Option 12 Selected - Cast 'Signet Ring of the Bronze Dragonflight CASTER R2'"),
(@ID,0,16,19,62,0,100,0,6539,13,0,0,11,25923,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anachronos - On Gossip Option 13 Selected - Cast 'Signet Ring of the Bronze Dragonflight CASTER R3'"),
(@ID,0,17,19,62,0,100,0,6539,14,0,0,11,25924,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anachronos - On Gossip Option 14 Selected - Cast 'Signet Ring of the Bronze Dragonflight CASTER R4'"),
(@ID,0,18,19,62,0,100,0,6539,15,0,0,11,25925,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anachronos - On Gossip Option 15 Selected - Cast 'Signet Ring of the Bronze Dragonflight CASTER R5'"),
(@ID,0,19,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Anachronos - On Link - Close Gossip");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"A terrible and costly mistake you have made. It is not my time, mortals.",12,0,100,0,0,0,10658,0,"Anachronos");
