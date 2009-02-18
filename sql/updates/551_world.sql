DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = '36574';
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES ('36574', '36650', '0', 'Apply Phase Slip Vulnerability');

UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=21807;
DELETE FROM `areatrigger_scripts` WHERE `entry`=4560;
INSERT INTO `areatrigger_scripts` VALUES (4560,'at_legion_teleporter');
UPDATE `creature_template` SET `ScriptName`='npc_commander_dawnforge' WHERE `entry`=19831;
DELETE FROM `areatrigger_scripts` WHERE `entry`=4497;
INSERT INTO `areatrigger_scripts` VALUES (4497,'at_commander_dawnforge');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000137 AND -1000128;
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
(-1000128, 'We need you to send reinforcements to Manaforge Duro, Ardonis. This is not a request, it\'s an order.', 0, 0, 0, 'dawnforge SAY_COMMANDER_DAWNFORGE_1'),
(-1000129, 'You cannot be serious! We are severely understaffed and can barely keep this manaforge functional!', 0, 0, 0, 'dawnforge SAY_ARCANIST_ARDONIS_1'),
(-1000130, 'You will do as ordered. Manaforge Duro has come under heavy attack by mana creatures and the situation is out of control. Failure to comply will not be tolerated!', 0, 0, 0, 'dawnforge SAY_COMMANDER_DAWNFORGE_2'),
(-1000131, 'Indeed, it is not a request.', 0, 0, 0, 'dawnforge SAY_PATHALEON_CULATOR_IMAGE_1'),
(-1000132, 'My lord!', 0, 0, 0, 'dawnforge SAY_COMMANDER_DAWNFORGE_3'),
(-1000133, 'Duro will be reinforced! Ultris was a complete disaster. I will NOT have that mistake repeated!', 0, 0, 0, 'dawnforge PATHALEON_CULATOR_IMAGE_2'),
(-1000134, 'We\'ve had too many setbacks along the way: Hellfire Citadel, Fallen Sky Ridge, Firewing Point... Prince Kael\'thas will tolerate no further delays. I will tolerate nothing other than complete success!', 0, 0, 0, 'dawnforge PATHALEON_CULATOR_IMAGE_2_1'),
(-1000135, 'I am returning to Tempest Keep. See to it that I do not have reason to return!', 0, 0, 0, 'dawnforge PATHALEON_CULATOR_IMAGE_2_2' ),
(-1000136, 'Yes, my lord.', 0, 0, 0, 'dawnforge COMMANDER_DAWNFORGE_4 SAY_ARCANIST_ARDONIS_2'),
(-1000137, 'See to it, Ardonis!', 0, 0, 0, 'dawnforge COMMANDER_DAWNFORGE_5');

