/*ALTER TABLE db_version CHANGE COLUMN required_7303_01_mangos_pools required_7312_01_mangos_mangos_string bit;*/

DELETE FROM `trinity_string` WHERE `entry`=810;
INSERT INTO `trinity_string` VALUES
(810,'|Hplayer:$N|h[$N]|h has earned the achievement $a!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);