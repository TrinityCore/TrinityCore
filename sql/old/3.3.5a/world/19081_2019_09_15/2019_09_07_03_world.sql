-- 
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN (18471) AND `source_type`=0 AND `id`=23;
UPDATE `smart_scripts` SET `event_type`=38, `event_param1`=15, `event_param2`=15 WHERE `entryorguid` IN (18471) AND `source_type`=0 AND `id`=27;
UPDATE `creature_text` SET `Type`=14 WHERE `CreatureID` IN (18471) AND `GroupID`=12;
DELETE FROM `creature_text` WHERE `CreatureID` IN (18471) AND `GroupID`=13;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(18471,13,0,"For the first time in the Ring of Blood's history, Mogor has chosen to exercise his right of battle! On this wartorn ground, $n will face Mogor, hero of the Warmaul!",14,0,100,0,0,0,15481,0,'Gurgthock');
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN (18069) AND `source_type`=0 AND `id`=9;
UPDATE `smart_scripts` SET `event_type`=40, `event_param1`=3, `event_param2`=18069, `action_type`=45, `action_param1`=1, `action_param2`=6, `target_type`=19, `target_param1`=18471  WHERE `entryorguid` IN (18069) AND `source_type`=0 AND `id`=10;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18471 AND `source_type`=0 AND `id` IN (29,30);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(18471, 0, 29, 0, 38, 0, 100, 0, 1, 6, 0, 0, 1, 13, 2000, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, "Gurgthock - On Data Set 1 13 - Say Line 13"),
(18471, 0, 30, 0, 52, 0, 100, 0, 13, 18471, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 18069, 0, 0, 0, 0, 0, 0, "Gurgthock - On text over - Say Line 3");
UPDATE `smart_scripts` SET `target_type`=7, `target_param1`=0  WHERE `entryorguid` IN (18471) AND `source_type`=0 AND `id` IN (4,10,0,6,8);
