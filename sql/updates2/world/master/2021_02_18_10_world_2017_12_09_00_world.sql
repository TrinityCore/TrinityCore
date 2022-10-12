-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=25800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25800 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25800,0,0,0,0,0,100,0,2000,5000,6000,8000,11,49711,0,0,0,0,0,2,0,0,0,0,0,0,0,"Clam Master K - IC - Cast "),
(25800,0,1,0,4,0,100,0,0,0,0,0,18,32768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Clam Master K - on aggro - Set unitflag UNK_15"),
(25800,0,2,0,25,0,100,0,0,0,0,0,19,32768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Clam Master K - on reset - remove unitflag UNK_15");
