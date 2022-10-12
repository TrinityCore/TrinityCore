/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

DELETE FROM `areatrigger_actions` WHERE entry = 4906;
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `chargeRecoveryTime`, `comment`) VALUES 
('4906', '0', '0', '0', 0x2 | 0x40, '143959', '0', '0', 'OO: Defiled Ground on enter cast'), 
('4906', '1', '1', '1', '0', '143959', '0', '0', 'OO: Defiled Ground on exit remove');

--
UPDATE `creature_template` SET unit_flags =  unit_flags | 0x2| 0x100| 0x200|0x2000000  WHERE `entry` in (71711, 71684, 71686, 71683);
UPDATE `creature` set modelid = 11686, unit_flags =  unit_flags | 0x2| 0x100| 0x200|0x2000000  WHERE `id` in (71711, 71684, 71686, 71683);
UPDATE `creature_template` SET `flags_extra` = '128' WHERE `entry` = 71683;
UPDATE `creature_template` SET `modelid1` = '11686' WHERE `creature_template`.`entry` = 71683;

--
UPDATE `creature_template` SET `lootid` = '0' WHERE `entry` in (71480, 71479);
DELETE FROM `creature_loot_template` WHERE `entry` in (71480, 71479);

--
UPDATE `creature` SET `spawnMask` = '16632' WHERE `id` in (71711, 71684, 71686, 71683, 71480, 71479, 71475);
UPDATE `gameobject` SET `spawnMask` = '16632', `phaseMask` = '1' WHERE id = 221611;

-- outro
DELETE FROM `creature_text` WHERE entry =73330 AND groupid > 13;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- падшие оутро 0xF1311E720000043D Type: Unit Entry: 73330 Low: 1085
(73330, 14, 0, 'Покойтесь с миром.', 14, 0, 100, 1, 0, 38136, 'Сунь Доброе Сердце'),
(73330, 15, 0, 'Пусть ваши души сольются с землей, за которую вы отдали жизни.', 14, 0, 100, 1, 0, 38137, 'Сунь Доброе Сердце');

-- Sha Field
UPDATE `creature` SET `spawntimesecs` = 604800 WHERE id in (72661, 72663, 72662);