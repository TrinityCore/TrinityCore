--
DELETE FROM `spell_custom_attr` WHERE `entry`=35009;
DELETE FROM `disables` WHERE `entry` IN(28098,28110);
UPDATE `creature_template` SET `type`=15 WHERE `entry` IN (48845,48828,48822,48818);
UPDATE `creature_template` SET `type`=5 WHERE `entry`=48693;
UPDATE `creature` SET `spawndist`=0 WHERE `MovementType`=0 AND `spawndist`!=0;
