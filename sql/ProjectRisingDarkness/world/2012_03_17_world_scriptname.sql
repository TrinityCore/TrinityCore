update gameobject_template set ScriptName = '' where entry = 201969;
update creature_template set ScriptName = '' where entry IN (36765, 36771);

DELETE FROM `areatrigger_scripts` where `entry`= 5573;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5573,'at_pit_of_saron_start');