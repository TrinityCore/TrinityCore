--
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_sartura_whirlwind';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(26084, 'spell_sartura_whirlwind'),
(26686, 'spell_sartura_whirlwind');

DELETE FROM `creature_text` WHERE `CreatureID` = 15516 AND `GroupID` = 3;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15516,3,0,"%s goes into a frenzy!",16,0,100,0,0,0,2384,0,"sartura EMOTE_FRENZY");
