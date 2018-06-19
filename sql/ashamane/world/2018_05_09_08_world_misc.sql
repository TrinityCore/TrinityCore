UPDATE `creature_template` SET `npcflag`='0' WHERE  `entry`=49874;
UPDATE `creature` SET `spawntimesecs`='180', `spawndist`='5', `MovementType`='1' WHERE  `guid` IN (178184,178204,178205,178233,178238,178242,178248,178249,178250,178271,178340,178341,178342,178345,178347,178432,178475,178484,178240,178254,178280,178460);
UPDATE `creature_addon` SET `path_id`='0', `bytes2`='1', `emote`='234' WHERE  `guid`IN (5881,6028,6364,6366,10373,10954,43766);
UPDATE `creature_addon` SET `path_id`='0' WHERE  `guid`IN (178240,178254,178280,178460);
UPDATE `creature_addon` SET `auras`='' WHERE  `guid` IN (178448,178449,178788,178789,178790,178791,178792,178793,178794,178795,179871,179873,179874,179876,179877);
UPDATE `creature` SET `modelid`='11035' WHERE  `guid` IN (5881,6028,6364,6366,10373,10954,43766);
UPDATE `creature` SET `modelid`='89', `spawndist`='5' WHERE  `guid` IN (177908,177909,177910);
DELETE FROM `creature_queststarter` WHERE  `id`=49874 AND `quest` IN (28759,28769,28770,28771,28772,28773,28774,29079);
DELETE FROM `smart_scripts` WHERE `entryorguid`=42218;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(42218, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 95826, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Shoot');

