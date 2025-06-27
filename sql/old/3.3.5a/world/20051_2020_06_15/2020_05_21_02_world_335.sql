--
DELETE FROM `gossip_menu` WHERE `MenuID` = 6186 AND `TextID` = 7393;
INSERT INTO `gossip_menu` (`MenuID`,`TextID`,`VerifiedBuild`) VALUES
(6186,7393,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 6186;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,6186,7339,0,0,1,0,23770,0,0,1,0,0,"","Group 0: Show gossip text 7339 if player does not have aura 'Sayge's Carnie Buff'"),
(14,6186,7393,0,0,1,0,23770,0,0,0,0,0,"","Group 0: Show gossip text 7393 if player does have aura 'Sayge's Carnie Buff'");

UPDATE `gossip_menu_option` SET `ActionMenuID` = 6208 WHERE `MenuID` = 6185 AND `OptionID` = 1;
UPDATE `gossip_menu_option` SET `ActionMenuID` = 6209 WHERE `MenuID` = 6185 AND `OptionID` = 2;
UPDATE `gossip_menu_option` SET `ActionMenuID` = 6210 WHERE `MenuID` = 6185 AND `OptionID` = 3;
UPDATE `gossip_menu_option` SET `ActionMenuID` = 6211 WHERE `MenuID` IN (6187,6208,6209,6210);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID` = 10087 WHERE `MenuID` = 6210 AND `OptionID` = 0;
UPDATE `gossip_menu_option` SET `ActionMenuID` = 6212 WHERE `MenuID` = 6211;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 6186;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,6186,0,0,0,1,0,23770,0,0,1,0,0,"","Group 0: Show Gossip Option 0 if player does not have aura 'Sayge's Carnie Buff'");

-- Sayge SAI
SET @ID := 14822;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,10,0,100,0,1,10,120000,120000,1,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sayge - Within 0-10 Range Out of Combat LoS - Say Line 0"),

(@ID,0,1,14,62,0,100,0,6187,0,0,0,0,11,23768,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sayge - On Gossip Option 0 Selected - Cast 'Sayge's Dark Fortune of Damage'"),
(@ID,0,2,14,62,0,100,0,6187,1,0,0,0,11,23769,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sayge - On Gossip Option 1 Selected - Cast 'Sayge's Dark Fortune of Resistance'"),
(@ID,0,3,14,62,0,100,0,6187,2,0,0,0,11,23767,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sayge - On Gossip Option 2 Selected - Cast 'Sayge's Dark Fortune of Armor'"),

(@ID,0,4,14,62,0,100,0,6208,0,0,0,0,11,23738,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sayge - On Gossip Option 0 Selected - Cast 'Sayge's Dark Fortune of Spirit'"),
(@ID,0,5,14,62,0,100,0,6208,1,0,0,0,11,23766,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sayge - On Gossip Option 1 Selected - Cast 'Sayge's Dark Fortune of Intelligence'"),
(@ID,0,6,14,62,0,100,0,6208,2,0,0,0,11,23769,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sayge - On Gossip Option 2 Selected - Cast 'Sayge's Dark Fortune of Resistance'"),

(@ID,0,7,14,62,0,100,0,6209,0,0,0,0,11,23737,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sayge - On Gossip Option 0 Selected - Cast 'Sayge's Dark Fortune of Stamina'"),
(@ID,0,8,14,62,0,100,0,6209,1,0,0,0,11,23735,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sayge - On Gossip Option 1 Selected - Cast 'Sayge's Dark Fortune of Strength'"),
(@ID,0,9,14,62,0,100,0,6209,2,0,0,0,11,23736,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sayge - On Gossip Option 2 Selected - Cast 'Sayge's Dark Fortune of Agility'"),

(@ID,0,10,14,62,0,100,0,6210,0,0,0,0,11,23766,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sayge - On Gossip Option 0 Selected - Cast 'Sayge's Dark Fortune of Intelligence'"),
(@ID,0,11,14,62,0,100,0,6210,1,0,0,0,11,23738,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sayge - On Gossip Option 1 Selected - Cast 'Sayge's Dark Fortune of Spirit'"),
(@ID,0,12,14,62,0,100,0,6210,2,0,0,0,11,23767,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sayge - On Gossip Option 2 Selected - Cast 'Sayge's Dark Fortune of Armor'"),

(@ID,0,13,0,62,0,100,0,6211,0,0,0,0,11,23765,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sayge - On Gossip Option 0 Selected - Cast 'Darkmoon Faire Fortune'"),
(@ID,0,14,0,61,0,100,0,0,0,0,0,0,11,23770,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sayge - On Link - Cast 'Sayge's Carnie Buff'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Come to me and see what the future holds for you!",12,0,100,0,0,0,10125,0,"Sayge"),
(@ID,0,1,"Come speak with me, and what once was cloudy shall become crystal clear.",12,0,100,0,0,0,10126,0,"Sayge"),
(@ID,0,2,"Fear not!  All fortunes can be discerned for those who know the way.",12,0,100,0,0,0,10127,0,"Sayge"),
(@ID,0,3,"The longer you wait, the less future you have for me to foretell.",12,0,100,0,0,0,10128,0,"Sayge");
