--
DELETE FROM `creature` WHERE `guid` = 131100 AND `id` = 31264;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(131100, 31264, 619, 3, 1, 0, 519.5499267578125, -447.876129150390625, 26.43937873840332031, 4.677482128143310546, 300, 0, 0, 12340);

DELETE FROM `creature_text` WHERE `CreatureID` = 31264;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(31264,0,0,"You will be alone in the end.",15,0,100,0,0,0,31911,0,"A Mysterious Voice"),
(31264,0,1,"Trust is your weakness.",15,0,100,0,0,0,31912,0,"A Mysterious Voice"),
(31264,0,2,"Hope is an illusion.",15,0,100,0,0,0,31913,0,"A Mysterious Voice"),
(31264,0,3,"All that you know will fade.",15,0,100,0,0,0,31914,0,"A Mysterious Voice");
