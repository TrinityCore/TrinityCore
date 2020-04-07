DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gift_of_the_harvester';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (52479,'spell_gift_of_the_harvester');

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=52479;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0,52479,64,'','','Gift of the Harvester (LOS)');
