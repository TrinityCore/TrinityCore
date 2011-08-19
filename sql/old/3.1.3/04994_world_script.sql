/* Oculus: "Just for the logic, shouldn't be necessary": */
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=23035 AND `comment` LIKE 'Anzu%Death';
INSERT INTO `creature_ai_scripts` (`creature_id`,`event_type`,`event_chance`,`event_flags`,`action1_type`,`action1_param1`,`action1_param2`,`comment`) VALUES
(23035,6,100,6,34,2,3,'Anzu - Set Inst Data on Death');
