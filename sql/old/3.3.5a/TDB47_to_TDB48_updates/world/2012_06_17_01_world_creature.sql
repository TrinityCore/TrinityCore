-- Add aura missing aura to Nerub'ar Scarab
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM creature WHERE id=25652);
DELETE FROM `creature_template_addon` WHERE `entry`=25652;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (25652,1,'45814');
