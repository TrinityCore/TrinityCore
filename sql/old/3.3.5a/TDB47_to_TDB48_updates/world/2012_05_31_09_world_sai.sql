 -- EAI to SAI Convert Ragefire Trogg
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=11318;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11318;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=11318;
INSERT INTO smart_scripts (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)
VALUES (11318, 0, 0, 0, 9, 0, 100, 2, 0, 5, 5000, 8000, 11, 11976, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ragefire Trogg - Cast Strike');

-- EAI to SAI Convert Earthborer
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=11320;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11320;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=11320;
INSERT INTO smart_scripts (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)
VALUES (11320, 0, 0, 0, 0, 0, 70, 2, 6000, 6000, 10000, 10000, 11, 18070, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Earthborer - Cast Earthborer Acid');

-- EAI to SAI Convert Searing Blade Cultist
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=11322;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11322;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=11322;
INSERT INTO smart_scripts (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)
VALUES (11322, 0, 0, 0, 0, 0, 85, 2, 12000, 12000, 30000, 30000, 11, 18266, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Searing Blade Cultist - Cast Curse of Agony');

-- EAI to SAI Convert Searing Blade Enforcer
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=11323;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11323;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=11323;
INSERT INTO smart_scripts (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)
VALUES (11323, 0, 0, 0, 0, 0, 75, 2, 8000, 8000, 10000, 10000, 11, 8242, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Searing Blade Enforcer - Cast Shield Slam');
