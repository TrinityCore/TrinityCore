UPDATE `creature_template` SET `ScriptName`="npc_pet_pri_shadowfiend_mindbender" WHERE `entry` IN (19668, 62982);

DELETE FROM `creature_template_addon` WHERE `entry`=62982;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(62982, 0, 0, 0, 0, 0, 0, 1, 40, 0, 0, 0, 0, 0, '34429 63623 284621'); -- 34429 - Shadowform | 63623 - Avoidance (Passive) | 284621 - Power Leech (Passive)

UPDATE `creature_template_addon` SET `auras`='34429 63623 262484' WHERE `entry`=19668; -- 34429 - Shadowform | 63623 - Avoidance (Passive) | 262484 - Power Leech (Passive)

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_atonement_passive', 'spell_pri_power_leech_passive', 'spell_pri_essence_devourer_heal');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(195178, 'spell_pri_atonement_passive'),
(262484, 'spell_pri_power_leech_passive'),
(284621, 'spell_pri_power_leech_passive'),
(415673, 'spell_pri_essence_devourer_heal'),
(415676, 'spell_pri_essence_devourer_heal');
