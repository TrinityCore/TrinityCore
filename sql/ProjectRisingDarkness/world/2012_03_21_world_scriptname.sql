DELETE FROM `areatrigger_scripts` where `entry`= 5598;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5598,'at_slave_rescued');

DELETE FROM `areatrigger_scripts` where `entry`= 5599;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5599,'at_geist_ambusher');

UPDATE creature_template set Scriptname = '' where entry = 36886;