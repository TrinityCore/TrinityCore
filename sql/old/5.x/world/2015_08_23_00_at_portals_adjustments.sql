-- Stormwind  portal Pandaria destiantion 215457
UPDATE gameobject_template SET data0=130702 WHERE entry=215457;
DELETE FROM spell_target_position WHERE id=130702;
INSERT INTO `spell_target_position` VALUES ('130702', '0', '870', '-303.92', '-1771.27', '62.96', '4.88');

-- Orgrimmar portal Pandaria destination and faction 215424
UPDATE gameobject_template SET data0=130696 WHERE entry=215424;
UPDATE `gameobject_template` SET `data3`='1', `faction`='1735' WHERE entry=215424; 
DELETE FROM spell_target_position WHERE id=130696;
INSERT INTO `spell_target_position` VALUES ('130696', '0', '870', '3010.22', '-585.63', '243.02', '1.99');
UPDATE `gameobject` SET `zoneId`='1637', `areaId`='5168', `position_x`='2014.55', `position_y`='-4699.73', `position_z`='28.6165', `orientation`='4.16372', `rotation2`='0.872225', `rotation3`='-0.489106' WHERE (`guid`='173288');

-- fix the orgrimmar  portal tol barad  position spawn
UPDATE `gameobject` SET `zoneId`='1637', `areaId`='5171', `position_x`='2031.04', `position_y`='-4330.28', `position_z`='95.4706', `orientation`='1.94484', `rotation2`='0.826252', `rotation3`='0.563301' WHERE (`guid`='179390');

-- make the pandaria portal from orgrimmar to look like it's casted by Arcanist Xu npc
DELETE FROM creature_addon WHERE guid=286294;
DELETE FROM creature_template_addon WHERE entry=66437;
INSERT INTO `creature_addon` (`guid`, `emote`) VALUES ('286294', '469');

-- make the pandaria portal from Stormwind to look like it's casted by Ang the Wise npc
DELETE FROM creature WHERE guid=343801;
INSERT INTO `creature` VALUES ('343801', '66449', '0', '1519', '1519', '1', '3969', '0', '0', '-8191.12', '525.932', '117.158', '2.52673', '300', '0', '0', '156000', '0', '0', '0', '0', '0', '0', '0', '0', null);
DELETE FROM creature_addon WHERE guid=343801;
DELETE FROM creature_template_addon WHERE entry=66449;
INSERT INTO `creature_addon` (`guid`, `emote`) VALUES ('343801', '469');
