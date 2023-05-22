-- 
UPDATE `creature_template_movement` SET `Flight`=1 WHERE `CreatureID` IN(8480, 9461, 10506, 14965, 17225, 21823, 22000, 22006, 22448, 24013, 24169, 24806, 24825, 25479, 26237, 27724, 27886, 28511, 28864, 29403, 29414, 29458, 30159, 33519, 34297, 36598, 36853, 38265, 38266, 38267, 37533, 37534, 38004, 38219, 38220, 38558, 39747, 39823, 40083, 40100, 40468, 40469, 40469);
UPDATE `creature_template_movement` SET `Flight`=0 WHERE `CreatureID` IN(8579, 24238, 24563, 26073);

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|512 WHERE `entry`=8579;
DELETE FROM `smart_scripts` WHERE `entryorguid`=857900 AND `source_type`=9 AND `id` IN (5,6);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(857900,9,5,0,0,0,100,0,0,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yeh'kinya - On Script - Disable gravity"),
(857900,9,6,0,0,0,100,0,0,0,0,0,53,1,8579,0,0,0,0,1,0,0,0,0,0,0,0,"Yeh'kinya - On Script - Start Waypoint");

DELETE FROM `creature_addon` WHERE `guid`=85240;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(85240, 0, 0, 1, 1, 0, '0');
