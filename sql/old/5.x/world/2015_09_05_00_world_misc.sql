UPDATE `creature_template` SET `ScriptName` = 'boss_koranthal' WHERE `entry` =61412;

UPDATE `creature_template` SET `ScriptName` = 'boss_adarogg' WHERE `entry` =61408;

UPDATE `creature_template` SET `ScriptName` = 'boss_slagmaw' WHERE `entry` =61463;

UPDATE `creature_template` SET `ScriptName` = 'boss_gordoth' WHERE `entry` =61528;

UPDATE `creature_template` SET `InhabitType` = '4' WHERE `entry` =61463;

UPDATE `creature_template` SET `minlevel` = '16', `maxlevel` = '16', `faction_A` = '16', `faction_H` = '16', `VehicleId` = '522', `ScriptName` = 'boss_slagmaw' WHERE `entry` =61463;

DELETE FROM `vehicle_template_accessory` WHERE `entry` = 61463;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(61463, 61800, 0, 1, 'Slagmaw', 6, 1000);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 61463;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(61463, 88066, 1, 0);

UPDATE `creature_template` SET `minlevel` = '16', `maxlevel` = '16', `faction_A` = '16', `faction_H` = '16', `InhabitType` = '4' WHERE `entry` =61800;

UPDATE `creature_template` SET `ScriptName` = 'boss_slagmaw_head' WHERE `entry` =61800;
