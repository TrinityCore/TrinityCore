--
DELETE FROM `creature_text` WHERE `CreatureID` = 15931;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(15931,0,0,"%s sprays slime across the room!",41,0,100,0,0,0,32318,0,"Grobbulus EMOTE_SLIME"),
(15931,1,0,"%s injects you with a mutagen!",42,0,100,0,0,0,32319,0,"Grobbulus EMOTE_MUTAGEN");

UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 1800 WHERE `entry` IN (16290,29388);
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_fallout_slime" WHERE `entry` = 16290;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 16290 AND `source_type` = 0;
