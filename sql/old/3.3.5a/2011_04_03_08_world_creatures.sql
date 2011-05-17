UPDATE `creature_template` SET `speed_run`=1,`spell2`=30708 WHERE `entry`=17539; -- Totem of Wrath I
UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35,`speed_run`=1,`spell2`=30708 WHERE `entry`=30652; -- Totem of Wrath II
UPDATE `creature_template` SET `spell2`=30708 WHERE `entry`=30653; -- Totem of Wrath III
UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35,`spell2`=30708 WHERE `entry`=30654; -- Totem of Wrath IV

UPDATE `creature_model_info` SET `bounding_radius`=1,`combat_reach`=0,`gender`=2 WHERE `modelid`=4589;

DELETE FROM `creature_template_addon` WHERE `entry` IN (17539,30652,30653,30654);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(17539,0,0,257,0,NULL), -- Totem of Wrath I
(30652,0,0,257,0,NULL), -- Totem of Wrath II
(30653,0,0,257,0,NULL), -- Totem of Wrath III
(30654,0,0,1,0,NULL); -- Totem of Wrath IV

DELETE FROM `spell_group` WHERE `spell_id`=30708; -- Unneeded stack rules
