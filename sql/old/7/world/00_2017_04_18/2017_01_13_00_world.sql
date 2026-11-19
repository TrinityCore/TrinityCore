--
UPDATE `npc_spellclick_spells` SET `spell_id`=94120 WHERE `npc_entry`=44776;
 
UPDATE `creature_template` SET `speed_run`=3.23333, `unit_flags`=33554440, `ScriptName`="npc_sharpbeak", `VehicleId`=1434, `InhabitType`=4 WHERE `entry` IN (43161,51125);
 
DELETE FROM `creature_template_addon` WHERE `entry` IN (43161,51125);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(43161,0,0,50331648,1,0,''),(51125,0,0,50331648,1,0,'');
--
