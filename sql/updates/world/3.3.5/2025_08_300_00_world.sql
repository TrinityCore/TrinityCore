-- Magmadar
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_magmadar_lava_bomb';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(19411, 'spell_magmadar_lava_bomb'),
(20474, 'spell_magmadar_lava_bomb');

DELETE FROM `creature_text` WHERE `CreatureID` = 11982 AND `GroupID` = 1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11982,1,0,"%s becomes exhausted!",16,0,100,0,0,0,8252,0,"magmadar EMOTE_EXHAUSTED");

UPDATE `creature_text` SET `BroadcastTextId` = 7797 WHERE `CreatureID` = 11982 AND `GroupID` = 0;

-- Golemagg
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 20553;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,7,20553,0,0,31,0,3,11672,0,0,0,0,"","Group 0: Spell 'Golemagg's Trust' (Effect 0, 1, 2) targets creature 'Core Rager'");
