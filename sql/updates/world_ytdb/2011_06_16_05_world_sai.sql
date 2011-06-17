UPDATE `creature_template` SET `AIName`='SmartAI',`exp`=2,`minlevel`=83,`maxlevel`=83,`baseattacktime`=2000,`flags_extra`=`flags_extra`|0x80 WHERE `entry`=36536; -- Well of Souls

DELETE FROM `smart_scripts` WHERE `entryorguid`=36536;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(36536,0,0,0,54,0,0,0,0,0,0,0,11,68854,0,0,0,0,0,1,0,0,0,0,0,0,0,'Well of Souls - On summon - Cast Well of Souls');
