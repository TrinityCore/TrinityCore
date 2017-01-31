UPDATE `creature_template` SET `AIName`='',`spell1`=11901 WHERE `entry`=8179; -- Greater Healing Ward
UPDATE `creature_template` SET `AIName`='',`spell1`=6276 WHERE `entry`=3844; -- Healing Ward IV
UPDATE `creature_template` SET `AIName`='',`spell1`=4972  WHERE `entry`=2992; -- Healing Ward V
UPDATE `creature_template` SET `spell1`=31986 WHERE `entry`=18177; -- Tainted Stoneskin Totem
UPDATE `creature_template` SET `AIName`='',`spell1`=34978 WHERE `entry`=20208; -- Mennu's Healing Ward
UPDATE `creature_template` SET `AIName`='',`spell1`=52894 WHERE `entry`=29225; -- Anti-Magic Zone
UPDATE `creature_template` SET `AIName`='',`spell1`=56762 WHERE `entry`=30444; -- The Chieftain's Totem
UPDATE `creature_template` SET `AIName`='',`spell1`=46373 WHERE `entry`=25987; -- Windsoul Totem
UPDATE `creature_template` SET `AIName`='',`spell1`=12507 WHERE `entry`=8510; -- Atal'ai Totem
UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35,`minlevel`=1,`maxlevel`=1,`baseattacktime`=2000,`unit_class`=1,`speed_walk`=1,`speed_run`=1 WHERE `entry`=3968; -- Sentry Totem
UPDATE `creature_template` SET `minlevel`=1,`maxlevel`=1,`unit_class`=1,`speed_walk`=1,`speed_run`=1 WHERE `entry`=7484; -- Windfury Totem III
UPDATE `creature_template` SET `minlevel`=1,`maxlevel`=1 WHERE `entry`=15483; -- Fire Nova Totem VII
UPDATE `creature_template` SET `faction_A`=1759,`faction_H`=1759 WHERE `entry`=19222; -- Magma Flow Totem
UPDATE `creature_template` SET `faction_A`=74,`faction_H`=74,`speed_walk`=1,`speed_run`=1,`spell1`=33134 WHERE `entry`=18179; -- Corrupted Nova Totem
UPDATE `creature_template` SET `faction_A`=74,`faction_H`=74,`baseattacktime`=2000,`speed_walk`=1,`speed_run`=1,`spell1`=31982 WHERE `entry`=18176; -- Tainted Earthgrab Totem
UPDATE `creature_template` SET `minlevel`=1,`maxlevel`=1,`unit_flags`=`unit_flags`|512,`speed_run`=0.99206 WHERE `entry`=20455; -- Terror Totem

DELETE FROM `creature_ai_scripts` WHERE `creature_id`=8179; -- Greater Healing Ward
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=3844; -- Healing Ward IV
DELETE FROM `creature_ai_scripts` WHERE `id`=1817702; -- Tainted Stoneskin Totem
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=20208; -- Mennu's Healing Ward
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=8510; -- Atal'ai Totem

DELETE FROM `creature_template_addon` WHERE `entry` IN (3968,7484,15483,19222,24046,24045,18179,18176);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(3968,0,0,1,0, NULL), -- Sentry Totem
(7484,0,0,1,0, NULL), -- Windfury Totem III
(15483,0,0,1,0, NULL), -- Fire Nova Totem VII
(19222,0,0,1,0, NULL), -- Magma Flow Totem
(24046,0,0,257,0, NULL), -- Fire Spirit Totem
(24045,0,0,257,0, NULL), -- Water Spirit Totem
(18179,0,0,1,0, NULL), -- Corrupted Nova Totem
(18176,0,0,1,0, NULL); -- Tainted Earthgrab Totem
