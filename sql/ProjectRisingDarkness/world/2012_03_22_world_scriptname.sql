DELETE FROM `areatrigger_scripts` where `entry`= 5573;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5573,'at_pos_intro');

UPDATE creature_template SET scriptname = "pos_intro" WHERE entry IN (36990, 36993);

DELETE FROM `areatrigger_scripts` where `entry`= 5598;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5598,'at_slave_rescued_pos');

DELETE FROM `areatrigger_scripts` where `entry`= 5599;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5599,'at_geist_ambusher_pos');

UPDATE creature_template SET Scriptname = 'pos_outro' WHERE entry IN (38189, 38188);