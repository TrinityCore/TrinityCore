UPDATE `creature_template` SET `minlevel`='115', `maxlevel`='115' WHERE  `entry`=1642;
UPDATE `creature_template` SET `minlevel`='110', `maxlevel`='110' WHERE  `entry`=42218;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=951;
DELETE FROM `smart_scripts` WHERE `entryorguid`=951;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(951, 0, 0, 0, 14, 0, 100, 0, 30, 40, 12000, 14000, '', 11, 13864, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Brother Paxton - Cast Power Word: Fortitude on Friendlies'),
(951, 0, 1, 0, 14, 0, 100, 0, 80, 40, 3000, 6000, '', 11, 93094, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Brother Paxton - Cast Renew on Friendlies'),
(951, 0, 2, 0, 14, 0, 100, 0, 50, 40, 8000, 10000, '', 11, 93091, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Brother Paxton - Cast Prayer of Healing Friendlies');
UPDATE `creature_addon` SET `path_id`='0' WHERE  `guid`=177921;
UPDATE `creature` SET `spawndist`='10', `MovementType`='1' WHERE  `guid`=177921;

UPDATE `creature` SET `spawndist`='5', `MovementType`='1' WHERE  `guid` IN (178122,178215,178291,178292,178293,178295,178296,178297,178327,178331,178346,178369,178382,178386,178390,178396,178398,178408,178411,178412,178414,178415,178422,178422);

