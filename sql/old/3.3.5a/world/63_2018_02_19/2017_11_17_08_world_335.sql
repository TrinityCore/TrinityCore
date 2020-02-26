-- Tammra Windfield
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11864;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11864 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1186400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11864,0,0,0,20,0,100,0,6301,0,0,0,80,1186400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tammra Windfield - On Quest 'Cycle of Rebirth' Finished - Run Script"),
(1186400,9,0,0,0,0,100,0,0,0,0,0,11,32618,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tammra Windfield - On Script - Cast Cosmetic Nature Cast"),
(1186400,9,1,0,0,0,100,0,5000,5000,0,0,9,0,0,0,0,0,0,14,33531,177927,0,0,0,0,0,"Tammra Windfield - On Script - Activate Gameobject"),
(1186400,9,2,0,0,0,100,0,1000,1000,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tammra Windfield - On Script - Play Emote 25");

UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=177927;
UPDATE `gameobject` SET `spawntimesecs`=10 WHERE `guid`=33531;
