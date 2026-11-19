-- *Zum'Rah Area Trigger Script, Zum'Rah should become hostile when approached. By totoro.
DELETE FROM `areatrigger_scripts` WHERE `entry`=962;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES('962','at_zumrah');
