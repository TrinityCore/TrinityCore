/*
-- Ilkrud Magthrull
DELETE FROM `smart_scripts` WHERE `entryorguid`=3664 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3664,0,3,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ilkrud Magthrull - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=3664;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3664,0,0,"We'll cut your throats and bleed you dry!",12,0,100,0,0,0,1445,0,"Ilkrud Magthrull"),
(3664,0,1,"We'll have your heads!",12,0,100,0,0,0,1446,0,"Ilkrud Magthrull"),
(3664,0,2,"For the Dark Strand!",12,0,100,0,0,0,1447,0,"Ilkrud Magthrull");
*/
