DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10447,10448,10449,10459,10460,10461) AND `type` IN (11,18);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(10447,11,0,0,'achievement_knock_on_wood'),
(10447,12,0,0,''),
(10448,11,0,0,'achievement_knock_knock_on_wood'),
(10448,12,0,0,''),
(10449,11,0,0,'achievement_knock_knock_knock_on_wood'),
(10449,12,0,0,''),
(10459,11,0,0,'achievement_knock_on_wood'),
(10459,12,1,0,''),
(10460,11,0,0,'achievement_knock_knock_on_wood'),
(10460,12,1,0,''),
(10461,11,0,0,'achievement_knock_knock_knock_on_wood'),
(10461,12,1,0,'');

UPDATE `creature_template` SET `AIName`='' WHERE `entry` IN (33354,33355,33430,33431,33525,33526,33527,33528);



DELETE FROM `smart_scripts` WHERE `entryorguid` IN (33354,33355,33430,33431,33525,33526,33527,33528);
