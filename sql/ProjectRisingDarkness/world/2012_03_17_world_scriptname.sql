update gameobject_template set ScriptName = '' where entry = 201969;
update creature_template set ScriptName = '' where entry IN (36765, 36771);

DELETE FROM `areatrigger_scripts` where `entry`= 5573;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5573,'at_pit_of_saron_start');

DELETE FROM `areatrigger_scripts` where `entry`= 5578;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5578,'at_ymirjar_flamebearer_pos');

SET @ENTRY1=36840;
SET @ENTRY2=36892;
SET @ENTRY3=36893;
Delete from creature where id IN (@ENTRY1, @ENTRY2, @ENTRY3);