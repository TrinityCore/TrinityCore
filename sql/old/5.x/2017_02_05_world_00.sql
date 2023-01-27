UPDATE `creature_template` SET `ScriptName`='npc_roaming_fog' WHERE  `entry`=68313;
UPDATE `creature_template` SET `ScriptName`='boss_durumu' WHERE `entry` = 68036;
UPDATE `creature_template` SET `ScriptName`='npc_durumu_fog' WHERE `entry` = 69052;
UPDATE `creature_template` SET `ScriptName`='npc_durumu_fog' WHERE `entry` = 69050;
UPDATE `creature_template` SET `ScriptName`='npc_eyebeam_target' WHERE `entry` = 67829;
UPDATE `creature_template` SET `ScriptName`='npc_durumu_eye' WHERE `entry` = 67875;
UPDATE `creature_template` SET `ScriptName`='npc_durumu_eye' WHERE `entry` = 67859;
UPDATE `creature_template` SET `ScriptName`='npc_durumu_eye' WHERE `entry` = 67858;
UPDATE `creature_template` SET `ScriptName`='npc_durumu_eye' WHERE `entry` = 67856;
UPDATE `creature_template` SET `ScriptName`='npc_durumu_eye' WHERE `entry` = 67854;
UPDATE `creature_template` SET `ScriptName`='npc_durumu_eye' WHERE `entry` = 67855;
DELETE FROM `spell_script_names` WHERE `spell_id` IN (133768, 133798, 136932, 134626, 133732, 133677, 133738);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(133768, "spell_arterial_cut"),
(133798, "spell_drain_life_damage"),
(136932, "spell_force_of_will"),
(134626, "spell_lingering_gaze"),
(133732, "spell_beam_aoe_dmg"),
(133677, "spell_beam_aoe_dmg"),
(133738, "spell_beam_aoe_dmg");
