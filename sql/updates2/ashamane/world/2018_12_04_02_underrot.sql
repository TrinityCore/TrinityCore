UPDATE creature_template SET scriptname = "boss_unbound_abomination" WHERE entry = 133007;
UPDATE creature_template SET scriptname = "npc_underrot_titan_keeper_hezrel" WHERE entry = 134419;
UPDATE creature_template SET scriptname = "npc_underrot_blood_visage" WHERE entry = 137103;
UPDATE creature_template SET scriptname = "npc_underrot_rotting_spore" WHERE entry = 137458;

UPDATE creature_template SET scriptname = "boss_sporecaller_zancha" WHERE entry = 131383;
UPDATE creature_template SET scriptname = "npc_underrot_spore_pod" WHERE entry = 131597;

UPDATE creature_template SET scriptname = "boss_cragmaw_infested" WHERE entry = 131817;
UPDATE creature_template SET scriptname = "npc_cragmaw_larva" WHERE entry = 132080;
UPDATE creature_template SET scriptname = "npc_cragmaw_blood_tick" WHERE entry = 132051;

UPDATE creature_template SET scriptname = "npc_underrot_faceless_corruptor" WHERE entry = 138281;

DELETE FROM `script_params` WHERE `entryOrGuid` IN (-280001512, -280001456, -280001437);
INSERT INTO `script_params` (`entryOrGuid`, `index`, `numericParam`, `stringParam`) VALUE
(-280001437, 1, 1, ''),
(-280001512, 1, 2, ''),
(-280001456, 1, 2, '');

DELETE FROM spell_script_names WHERE scriptname IN ("aura_unbound_abomination_blood_barrier",
                                                    "spell_underrot_vile_expulsion",
                                                    "spell_underrot_cleansing_light",
                                                    "aura_zancha_festering_harvest",
                                                    "aura_cragmaw_larva_transformation",
                                                    "aura_underrot_open_web_door");
INSERT INTO spell_script_names VALUES
(269185, "aura_unbound_abomination_blood_barrier"),
(269843, "spell_underrot_vile_expulsion"),
(269310, "spell_underrot_cleansing_light"),
(259888, "aura_zancha_festering_harvest"),
(260416, "aura_cragmaw_larva_transformation"),
(279271, "aura_underrot_open_web_door");

DELETE FROM creature WHERE guid = 280001732;
UPDATE creature_template SET mechanic_immune_mask = 2147467263  WHERE entry IN (131318, 131817, 131383, 137103, 137458, 133007);

UPDATE areatrigger_template SET scriptname = "at_underrot_vile_expulsion" WHERE id = 17928;
UPDATE areatrigger_template SET scriptname = "at_cragmaw_charge" WHERE id = 17014;
UPDATE areatrigger_template SET scriptname = "at_cragmaw_larva" WHERE id = 17026;

DELETE FROM conditions WHERE SourceTypeOrReferenceId = 13 AND SourceEntry IN (269692, 269312, 269310);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES
(13, 1, 269692, 31, 5, 133007),
(13, 1, 269312, 31, 5, 133007),
(13, 1, 269310, 31, 6, 0);

UPDATE `creature_template` SET `minlevel` = 110 , `maxlevel` = 120 WHERE `entry` = 137458; 

DELETE FROM `creature_template_scaling` WHERE `Entry` = 137458;
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingMin`, `LevelScalingMax`, `VerifiedBuild`) VALUES
(137458, 110, 120, 28153);

DELETE FROM `areatrigger` WHERE `guid` IN (50, 51, 52);
INSERT INTO `areatrigger` (`guid`, `id`, `map_id`, `spawn_mask`, `position_x`, `position_y`, `position_z`, `ScriptName`) VALUES
(50, 100007, 1841, 8388870, 1110.96, 1346.85, 5.028979, 'at_underrot_tunnel'),
(51, 100007, 1841, 8388870, 614.520, 1257.55, 100.316338, ''),
(52, 100007, 1642, 1, 1260.159546, 750.128418, -273.404541, '');

DELETE FROM `areatrigger_teleport` WHERE `ID` IN (-51, -52);
INSERT INTO `areatrigger_teleport` (`ID`, `PortLocID`, `Name`) VALUES
('-51', '6377', 'The Underrot - Exit Target'),
('-52', '6378', 'The Underrot - Entrance Target');

UPDATE creature_template_addon SET auras = "" WHERE entry = 134419;

DELETE FROM `creature_template_journal` WHERE entry IN (131318, 131817, 131383, 133007);
INSERT INTO `creature_template_journal` VALUES
(131318, 2157),
(131817, 2131),
(131383, 2130),
(133007, 2158);

DELETE FROM creature WHERE id = 132137;

INSERT IGNORE INTO creature_template_scaling VALUES
(132051, 110, 120, 0, 0, 28153);

UPDATE creature_template SET DamageModifier = 4 WHERE entry IN (SELECT id FROM creature WHERE map = 1841) AND minlevel > 100;
UPDATE creature_template SET DamageModifier = 5 WHERE entry IN (131318, 131817, 131383, 133007);

DELETE FROM `scenarios` WHERE `map` = 1841;
INSERT INTO `scenarios` (`map`, `scenario_A`, `scenario_H`) VALUES
('1841', '1563', '1563'); 

UPDATE `instance_template` SET `insideResurrection` = '1' WHERE `map` = '1841';
