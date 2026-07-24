--
DELETE FROM `creature_text` WHERE `CreatureID` = 17978 AND `GroupID` = 8;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(17978,8,0,"Welcome my brothers! Bask in the glory of my power!",14,0,100,53,0,0,16961,0,"Thorngrin the Tender - Intro");

UPDATE `creature_template` SET `ScriptName` = 'boss_thorngrin_the_tender' WHERE `ScriptName` = 'thorngrin_the_tender';
