-- 
UPDATE `creature_template` SET `spell1`=49285,`spell2`=29577,`flags_extra`=2,`ainame`='SmartAI' WHERE `entry`=26472;

DELETE FROM `smart_scripts` WHERE `entryorguid`=26472 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26472,0,0,0,8,0,100,0,49266,0,0,0,69,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Highland Mustang - On Spell Hit(Dangle Wild Carrot) - Move To Player'),
(26472,0,1,2,34,0,100,0,0,1,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Highland Mustang - On Movement Inform - Set Root'),
(26472,0,2,0,61,0,100,0,0,0,0,0,85,49282,0,0,0,0,0,1,0,0,0,0,0,0,0,'Highland Mustang - Link With Previous - Invoker Cast Ride Highland Mustang'),
(26472,0,3,0,27,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Highland Mustang - On Passenger Boarded - Remove Root');

DELETE FROM `spell_script_names` WHERE `spell_id`=49285;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(49285,'spell_q12414_hand_over_reins');
