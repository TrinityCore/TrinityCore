-- 
DELETE FROM `creature` WHERE `guid` IN (80433,80434);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `curhealth`, `curmana`, `MovementType`) VALUES 
(80433, 10558, 329, '1', 0, 0, 0, 0, 1, 3692.93, -3363.16, 130.753, 3.24631, 604800, 0, 29850, 0, 0),
(80434, 10558, 329, '1', 0, 0, 0, 0, 1, 3595.64, -3461.16, 136.267, 4.63659, 604800, 0, 29850, 0, 0);

DELETE FROM `pool_template` WHERE `entry`=386;
INSERT INTO pool_template (`entry`,`max_limit`,`description`) VALUES
(386,1, 'Hearthsinger Forresten (1 out 3)');

DELETE FROM `pool_creature` WHERE `pool_entry`=386;
INSERT INTO pool_creature(`guid`,`pool_entry`,`chance`,`description`) VALUES
(52150,386,0, 'Hearthsinger Forresten1'),
(80433,386,0, 'Hearthsinger Forresten2'),
(80434,386,0, 'Hearthsinger Forresten3');
