-- areatrigger for Kelthuzads chamber center
DELETE FROM `areatrigger_scripts` WHERE `entry`=4112;
INSERT INTO `areatrigger_scripts`(`entry`,`ScriptName`) VALUES(4112,'at_kelthuzad_center');
