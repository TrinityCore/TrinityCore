update gameobject_template set ScriptName = '' where entry = 201969;
update creature_template set ScriptName = '' where entry IN (36765, 36771);

DELETE FROM `areatrigger_scripts` where `entry`= 5573;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5573,'at_pit_of_saron_start');

DELETE FROM `areatrigger_scripts` where `entry`= 5578;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5578,'at_ymirjar_flamebearer_pos');

DELETE FROM `areatrigger_scripts` where `entry`= 5579;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5579,'at_fallen_warrior_pos');

DELETE FROM `areatrigger_scripts` where `entry`= 5580;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5580,'at_ice_cicle_pos');