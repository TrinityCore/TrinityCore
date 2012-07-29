UPDATE `creature` SET `spawntimesecs`=180 WHERE `id`=23689;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (23689,24170);

DELETE FROM `creature_ai_scripts` WHERE `creature_id`=23689;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23689,24170) AND `source_type`=0;
insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) values
(23689,0,1,2,65,0,100,0,0,0,0,0,11,36809,2,0,0,0,0,1,0,0,0,0,0,0,0,'Proto-Drake - Reach Target - Cast Spell (36809)'),
(23689,0,2,0,61,0,100,0,0,0,0,0,33,24170,0,0,0,0,0,18,35,0,0,0,0,0,0,'Draconis Gastritis Bunny - On Death - Quest Reward'),
(23689,0,3,5,1,0,100,0,10000,10000,10000,10000,29,0,0,24170,1,1,0,19,24170,75,0,0,0,0,0,'Proto-Drake - Find Target - Follow'),
(23689,0,4,0,65,0,100,0,0,0,0,0,51,0,0,0,0,0,0,19,24170,5,0,0,0,0,0,'Proto-Drake - Reach Target - Kill Dummy'),
(23689,0,5,3,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Proto-Drake - On Find Target - Set Phase 1'),
(23689,0,6,0,1,1,100,0,45000,45000,45000,45000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Proto-Drake - Idle on Ground(Phase 1) - Despawn'),
(24170,0,0,0,54,0,100,0,0,0,0,0,50,186598,60000,0,0,0,0,1,0,0,0,0,0,0,0,'Draconis Gastritis Bunny - On Create - Spawn GO'),
(24170,0,1,0,6,0,100,0,0,0,0,0,33,24170,0,0,0,0,0,18,20,0,0,0,0,0,0,'Draconis Gastritis Bunny - On Death - Quest Reward'),
(24170,0,2,0,54,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Draconis Gastritis Bunny - On Create - Hide'),
(24170,0,3,0,6,0,100,0,0,0,0,0,41,0,0,0,0,0,0,15,186598,5,0,0,0,0,0,'Draconis Gastritis Bunny - On Death - Remove Gobjects');
