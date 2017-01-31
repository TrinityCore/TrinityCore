-- The Torch of Retribution (3454)
/*
SET @KALARAN := 8479; -- Kalaran Windblade
SET @QUEST   := 3454; -- Quest: The Torch of Retribution

DELETE FROM `smart_scripts` WHERE `entryorguid`=@KALARAN AND `id` IN (5,6);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@KALARAN,0,5,6,19,0,100,0,@QUEST,0,0,0,70,0,0,0,0,0,0,14,24166,149410,0,0,0,0,0,"Kalaran Windblade - On Quest Accept (4354) - Respawn Light of Retribution"),
(@KALARAN,0,6,0,61,0,100,0,0,0,0,0,70,0,0,0,0,0,0,14,16762,149047,0,0,0,0,0,"Kalaran Windblade - Linked with Previous Event - Respawn Torch of Retribution");
*/
