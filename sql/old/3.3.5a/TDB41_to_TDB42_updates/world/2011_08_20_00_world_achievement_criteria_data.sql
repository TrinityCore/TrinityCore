UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_kelthuzad_abomination' WHERE `entry`=16428;

DELETE FROM `creature_ai_scripts` WHERE `creature_id`=16428;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (7614, 7615) AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(7614,11,0,0,'achievement_just_cant_get_enough'),
(7615,11,0,0,'achievement_just_cant_get_enough');

DELETE FROM `disables` WHERE `entry` IN (7614, 7615);
