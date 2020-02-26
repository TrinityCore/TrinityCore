-- 
-- Quest "Troubled Spirits of Kel'Theril"
-- Highborne Relic Fragment
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry` IN (175888,175891,175892,175893);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (175888,175891,175892,175893) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(175888,1,0,0,70,0,100,1,2,0,0,0,12,7523,1,180000,0,0,0,8,0,0,0,6505.45,-4230.91,658.636,3.31351,"Highborne Relic Fragment - On Gameobject State Changed - Summon Creature 'Suffering Highborne'"),
(175888,1,1,0,70,0,100,1,2,0,0,0,12,7524,1,180000,0,0,0,8,0,0,0,6494.32,-4228.23,658.549,5.63829,"Highborne Relic Fragment - On Gameobject State Changed - Summon Creature 'Anguished Highborne'"),
(175891,1,0,0,70,0,100,1,2,0,0,0,12,7523,1,180000,0,0,0,8,0,0,0,6562.16,-3919.21,658.297,4.42878,"Highborne Relic Fragment - On Gameobject State Changed - Summon Creature 'Suffering Highborne'"),
(175891,1,1,0,70,0,100,1,2,0,0,0,12,7524,1,180000,0,0,0,8,0,0,0,6556.55,-3938.87,658.313,1.30682,"Highborne Relic Fragment - On Gameobject State Changed - Summon Creature 'Anguished Highborne'"),
(175892,1,0,0,70,0,100,1,2,0,0,0,12,7523,1,180000,0,0,0,8,0,0,0,6482.59,-4109.64,658.291,2.21004,"Highborne Relic Fragment - On Gameobject State Changed - Summon Creature 'Suffering Highborne'"),
(175892,1,1,0,70,0,100,1,2,0,0,0,12,7524,1,180000,0,0,0,8,0,0,0,6482.84,-4093.91,658.412,4.11463,"Highborne Relic Fragment - On Gameobject State Changed - Summon Creature 'Anguished Highborne'"),
(175893,1,0,0,70,0,100,1,2,0,0,0,12,7523,1,180000,0,0,0,8,0,0,0,6563.31,-4047.92,658.329,1.18116,"Highborne Relic Fragment - On Gameobject State Changed - Summon Creature 'Suffering Highborne'"),
(175893,1,1,0,70,0,100,1,2,0,0,0,12,7524,1,180000,0,0,0,8,0,0,0,6557.38,-4041.45,658.408,0.313297,"Highborne Relic Fragment - On Gameobject State Changed - Summon Creature 'Anguished Highborne'");

-- Anguished Highborne
DELETE FROM `smart_scripts` WHERE `entryorguid`=7524 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7524,0,1,0,11,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Anguished Highborne - On Respawn - Start Attacking");

-- Suffering Highborne
DELETE FROM `smart_scripts` WHERE `entryorguid`=7523 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7523,0,1,0,11,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Suffering Highborne - On Respawn - Start Attacking");
