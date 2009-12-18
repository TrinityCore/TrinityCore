DELETE FROM `spell_script_target` WHERE `entry`=45364 AND `type`=1 AND `targetEntry`=25478;
DELETE FROM `spell_script_target` WHERE `entry`=45634;
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(45634,1,25478);
