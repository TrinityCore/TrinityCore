--
DELETE FROM `creature_template_addon` WHERE `entry`= 29403; -- Onslaught Gryphon
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(29403, 0, 0, 0, 1, 0, 54422); -- add aura 'Flying' to Onslaught Gryphon
