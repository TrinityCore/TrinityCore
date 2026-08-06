--
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_moroes_garrote_remove';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(37870, 'spell_moroes_garrote_remove');

DELETE FROM `creature_text` WHERE `CreatureID` = 15687 AND `GroupID` = 4;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15687,4,0,"%s goes into a frenzy!",16,0,100,0,0,0,1191,0,"moroes EMOTE_FRENZY");
