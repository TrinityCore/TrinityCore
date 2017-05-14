-- add text for use in boss_apothecary_hummel.cpp
DELETE FROM `creature_text` WHERE `CreatureID`=36296 AND `GroupID`=6 AND `ID`=0;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(36296,6,0,"Apothecaries! Give your life for the Crown!",12,0,100,0,0,0,38594,3,'SAY_SUMMON_ADDS');
