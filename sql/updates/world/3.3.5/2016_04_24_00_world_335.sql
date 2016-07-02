--
-- spell aura effect 53055 from Hand of Salvation should not break invisibility
DELETE FROM `spell_custom_attr` WHERE `entry`=53055 AND `attributes`=64;
INSERT INTO `spell_custom_attr` (`entry`,`attributes`) VALUES (53055, 64);
