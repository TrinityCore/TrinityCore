-- Sepethrea
DELETE FROM `creature_text` WHERE `CreatureID` = 19221;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(19221,0,0,"Don't value your life very much, do you?",14,0,100,0,0,11186,19959,0,"Sepethrea SAY_AGGRO"),
(19221,1,0,"And don't come back!",14,0,100,0,0,11187,19961,0,"Sepethrea SAY_SLAY_1"),
(19221,1,1,"Endala finel endal!",14,0,100,0,0,11188,19962,0,"Sepethrea SAY_SLAY_2"),
(19221,2,0,"Think you can take the heat?",14,0,100,0,0,11189,19963,0,"Sepethrea SAY_DRAGONS_BREATH_1"),
(19221,2,1,"Anar'endal dracon!",14,0,100,0,0,11190,19964,0,"Sepethrea SAY_DRAGONS_BREATH_2"),
(19221,3,0,"I am not alone.",14,0,100,0,0,11191,19965,0,"Sepethrea SAY_SUMMON"),
(19221,4,0,"Anu... bala belore...alon.",14,0,100,0,0,11192,19966,0,"Sepethrea SAY_DEATH");

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_nethermancer_sepethrea_arcane_blast';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(35314, 'spell_nethermancer_sepethrea_arcane_blast');
