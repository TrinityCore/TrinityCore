/*
-- 
-- Theramore Practicing Guard
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4951;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4951) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4951,0,0,0,25,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,19,4952,0,0,0,0,0,0,"Theramore Practicing Guard - On Reset - Start Attacking");
-- Theramore Combat Dummy
UPDATE `creature_template` SET `ScriptName`="npc_training_dummy" WHERE `entry`=4952;
*/
