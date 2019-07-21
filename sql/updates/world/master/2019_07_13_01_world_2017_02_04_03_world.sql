
UPDATE `creature_template_addon` SET `auras`=32648 WHERE `entry` IN(19698);
DELETE FROM `spell_area` WHERE `spell`=32649 AND `area`=3688;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`, `quest_end`,`aura_spell`,`racemask`,`gender`,`flags`,quest_start_status) VALUES
(32649,3688,10252,0,0,0,2,1,64);
DELETE FROM `creature_template_addon` WHERE `entry`=19879;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES
(19879,1,"32648");
