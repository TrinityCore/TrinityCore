--
DELETE FROM `creature_formations` WHERE `leaderGUID`=26233;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`)VALUES
(26233,26233,0,0,2),(26233,26192,15,0,2),(26233,26194,15,90,2),(26233,26193,9,0,2),(26233,26195,9,90,2);
UPDATE `creature` SET `MovementType`=2 WHERE `guid` IN (26233);
UPDATE `creature_addon`  SET `path_id`=262330 WHERE `guid` IN (26233);
DELETE FROM `creature_addon` WHERE `guid` IN  (26233);
INSERT INTO `creature_addon` (`guid`, `path_id`) VALUES (26233, 262330);
DELETE FROM `waypoint_data` WHERE `id` IN (262330);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(262330, 1,-1317.949951, -926.414978, 1.9346, 0, 0, 0, 0, 100, 0),
(262330, 2,-1244.693726, -980.329773, -4.920392, 0, 0, 0, 0, 100, 0), 
(262330, 3,-1193.669312, -948.340393, -3.643325, 0, 0, 0, 0, 100, 0), 
(262330, 4,-1182.622681, -859.417419, -11.058956, 0, 0, 0, 0, 100, 0),
(262330, 5,-1183.541138, -796.475952, -36.551662, 0, 0, 0, 0, 100, 0),
(262330, 6,-1182.812988, -740.116638, -52.754967, 0, 0, 0, 0, 100, 0),
(262330, 7,-1200.200806, -605.367249, -57.754887, 0, 0, 0, 0, 100, 0), 
(262330, 8,-1242.377563, -494.067078, -57.610630, 0, 0, 0, 0, 100, 0), 
(262330, 9,-1468.878052, -522.602173, -55.496475, 0, 0, 0, 0, 100, 0), 
(262330, 10,-1551.133789, -656.098145, -50.817574, 0, 0, 0, 0, 100, 0), 
(262330, 11,-1394.677490, -802.561279, -21.880009, 0, 0, 0, 0, 100, 0), 
(262330, 12,-1317.949951, -926.414978, 1.9346, 0, 0, 0, 0, 100, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=26213;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`)VALUES
(26213,26213,0,0,2),(26213,26185,15,0,2),(26213,26207,15,90,2),(26213,26186,9,0,2),(26213,26187,9,90,2);
UPDATE `creature` SET `MovementType`=2 WHERE `guid` IN (26213);
UPDATE `creature_addon`  SET `path_id`=262130 WHERE `guid` IN (26213);
DELETE FROM `creature_addon` WHERE `guid` IN  (26213);
INSERT INTO `creature_addon` (`guid`, `path_id`) VALUES (26213, 262130);
DELETE FROM `waypoint_data` WHERE `id` IN (262130);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(262130, 1,-2545.065918, 21.190157, 11.805480, 0, 0, 0, 0, 100, 0),
(262130, 2,-2487.883789, 100.192146, 33.786736, 0, 0, 0, 0, 100, 0),
(262130, 3,-2420.558350, 88.399445, 38.040539, 0, 0, 0, 0, 100, 0),
(262130, 4,-2318.995361, 115.247169, 50.718586, 0, 0, 0, 0, 100, 0),
(262130, 5,-2284.748779, 27.045509, 22.492968, 0, 0, 0, 0, 100, 0),
(262130, 6,-2349.130615, -61.506725, -8.763674, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `MovementType`=1, `spawndist`=15 WHERE `guid` IN (26214, 26231, 26189, 26188, 26196, 26184, 26210, 26209, 26211, 26232, 26190, 26191, 26212);
