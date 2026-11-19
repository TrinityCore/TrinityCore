--
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=22932;
DELETE FROM `smart_scripts` WHERE `entryorguid`=22932 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22932,0,0,0,25,0,100,0,0,0,0,0,11,39680,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sai''kkal the Elder - On Spawn/Respawn/After Combat - Cast Sai''kkal Invisibility'),
(22932,0,1,0,62,0,100,0,8617,0,0,0,33,22932,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sai''kkal the Elder - On Gossip Menu Option Selected - Give Quest Credit');
