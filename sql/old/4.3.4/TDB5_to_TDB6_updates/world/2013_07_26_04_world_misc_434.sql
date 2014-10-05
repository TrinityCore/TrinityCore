DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10568,10570);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(10568,11,0,0,'achievement_he_feeds_on_your_tears'), -- He Feeds On Your Tears (10 player)
(10570,11,0,0,'achievement_he_feeds_on_your_tears'); -- He Feeds On Your Tears (25 player)

UPDATE `gameobject_template` SET `ScriptName`='go_blackhoof_cage' WHERE `entry`=186287;
UPDATE `creature_template` SET `ScriptName`='boss_daakara' WHERE `entry`=23863;
