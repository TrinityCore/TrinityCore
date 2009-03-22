DELETE FROM `spell_affect` WHERE `entry`='14177' AND `effectId`='0';
INSERT INTO `spell_affect` VALUES ('14177', '0', '61741335326');
 
DELETE FROM `spell_affect` WHERE `entry`='13733' AND `effectId`='1';
DELETE FROM `spell_affect` WHERE `entry`='13865' AND `effectId`='1';
DELETE FROM `spell_affect` WHERE `entry`='13866' AND `effectId`='1';
INSERT INTO `spell_affect` VALUES ('13733', '1', '25769803776');
INSERT INTO `spell_affect` VALUES ('13865', '1', '25769803776');
INSERT INTO `spell_affect` VALUES ('13866', '1', '25769803776');
 
DELETE FROM `spell_affect` WHERE `entry`='31234' AND `effectId`='0';
DELETE FROM `spell_affect` WHERE `entry`='31235' AND `effectId`='0';
DELETE FROM `spell_affect` WHERE `entry`='31236' AND `effectId`='0';
DELETE FROM `spell_affect` WHERE `entry`='31237' AND `effectId`='0';
DELETE FROM `spell_affect` WHERE `entry`='31238' AND `effectId`='0';
INSERT INTO `spell_affect` VALUES ('31234', '0', '1125920146191');
INSERT INTO `spell_affect` VALUES ('31235', '0', '1125920146191');
INSERT INTO `spell_affect` VALUES ('31236', '0', '1125920146191');
INSERT INTO `spell_affect` VALUES ('31237', '0', '1125920146191');
INSERT INTO `spell_affect` VALUES ('31238', '0', '1125920146191');
 
DELETE FROM `spell_proc_event` WHERE `entry`='14186';
DELETE FROM `spell_proc_event` WHERE `entry`='14190';
DELETE FROM `spell_proc_event` WHERE `entry`='14193';
DELETE FROM `spell_proc_event` WHERE `entry`='14194';
DELETE FROM `spell_proc_event` WHERE `entry`='14195';
INSERT INTO `spell_proc_event` VALUES ('14186', '0', '8', '26851935496', '0', '2', '0', '0', '1');
INSERT INTO `spell_proc_event` VALUES ('14190', '0', '8', '26851935496', '0', '2', '0', '0', '1');
INSERT INTO `spell_proc_event` VALUES ('14193', '0', '8', '26851935496', '0', '2', '0', '0', '1');
INSERT INTO `spell_proc_event` VALUES ('14194', '0', '8', '26851935496', '0', '2', '0', '0', '1');
INSERT INTO `spell_proc_event` VALUES ('14195', '0', '8', '26851935496', '0', '2', '0', '0', '1');
