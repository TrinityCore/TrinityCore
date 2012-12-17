-- Vyragosa
UPDATE `creature_addon` SET `bytes1`=0x3000000 WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=32630);
-- Chillmaw
UPDATE `creature_addon` SET `bytes1`=0x3000000,`bytes2`=0x1 WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=33687);
DELETE FROM `creature_template_addon` WHERE `entry`=33687;
