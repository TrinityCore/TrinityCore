UPDATE `creature_template` SET `unit_flags`=64 WHERE `entry`=25740;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=45947;
DELETE FROM `creature_template_addon` WHERE `entry`=25754;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(25754,0,0,1,1,0,NULL);
