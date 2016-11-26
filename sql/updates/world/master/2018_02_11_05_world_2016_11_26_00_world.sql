-- Disable PathFinding for High Warlord Naj'entus
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|536870912 WHERE `entry`=22887;

UPDATE `creature_addon` SET `auras`=19818 WHERE `guid`=40527;

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_najentus_needle_spine';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(39992,'spell_najentus_needle_spine');

DELETE FROM `creature_text` WHERE `CreatureID`=22887 AND (`GroupID` IN(5,6) OR (`GroupID`=4 AND `ID`=1));
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(22887,4,1,'My patience has run out! Die! Die!',14,0,100,0,0,11458,21096,0,"High Warlord Naj'entus SAY_ENRAGE2"),
(22887,5,0,'Lord Illidan will... crush you!',14,0,100,0,0,11459,21093,0,"High Warlord Naj'entus SAY_DEATH");

UPDATE `creature_text` SET `Text`='Stick around...',`BroadcastTextId`=21089 WHERE `CreatureID`=22887 AND `GroupID`=1 AND `ID`=0;
