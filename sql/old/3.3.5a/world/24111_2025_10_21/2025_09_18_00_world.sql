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

-- Garr
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (20482,19515,23487);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,3,20482,0,0,31,0,3,12099,0,0,0,0,"","Group 0: Spell 'Firesworn Eruption Trigger' (Effect 0, 1) targets creature 'Firesworn'"),
(13,1,19515,0,0,31,0,3,12057,0,0,0,0,"","Group 0: Spell 'Frenzy' (Effect 0) targets creature 'Garr'"),
(13,1,23487,0,0,31,0,3,12099,0,0,0,0,"","Group 0: Spell 'Separation Anxiety' (Effect 0) targets creature 'Firesworn'");

DELETE FROM `creature_text` WHERE `CreatureID` = 12057;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(12057,0,0,"%s forces one of his Firesworn minions to erupt!",16,0,100,0,0,0,8254,0,"Garr EMOTE_MASSIVE_ERUPTION");

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_garr_separation_anxiety';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(23487, 'spell_garr_separation_anxiety');
