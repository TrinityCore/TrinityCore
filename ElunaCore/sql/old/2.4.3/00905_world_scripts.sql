UPDATE `creature_template` SET `ScriptName`='npc_grimstone' WHERE `entry`=10096;
UPDATE `creature_template` SET `ScriptName`='mob_phalanx' WHERE `entry`=9502;
UPDATE `creature_template` SET `ScriptName`='npc_rocknot' WHERE `entry`=9503;

DELETE FROM `areatrigger_scripts` WHERE `entry`=1526;
INSERT INTO `areatrigger_scripts` VALUES (1526,'at_ring_of_law');

DELETE FROM `script_texts` WHERE `entry`=-1230000;
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
(-1230000,'Ah, hits the spot!',0,0,0,'rocknot SAY_GOT_BEER');
