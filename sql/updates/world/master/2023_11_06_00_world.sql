DELETE FROM `instance_template` WHERE `map`= 755;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(755, 1, 'instance_lost_city_of_the_tolvir');

-- General Husam
UPDATE `creature_template` SET `mechanic_immune_mask`= 667893759, `ScriptName`= 'boss_general_husam' WHERE `entry`= 44577;
-- Shockwave Stalker
UPDATE `creature_template` SET `faction`= 35, `unit_flags`= 33554432, `flags_extra`= 128, `speed_run`= 1.14286 WHERE `entry`= 44711;
-- Shockwave Visual
UPDATE `creature_template` SET `faction`= 14, `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 44712;
-- Tol'Vir Land Mine
UPDATE `creature_template` SET `faction`= 14, `unit_flags`= 33554432, `flags_extra`= 0,  `ScriptName`= 'npc_husam_tolvir_land_mine' WHERE `entry`= 44840;
-- Tol'Vir Land Mine Vehicle
UPDATE `creature_template` SET `faction`= 14, `unit_flags`= 33554432, `flags_extra`= 0, `VehicleId`= 1050, `ScriptName`= 'npc_husam_tolvir_land_mine' WHERE `entry`= 44798;
-- Tol'Vir Land Mine 2 
UPDATE `creature_template` SET `faction`= 14, `unit_flags`= 33554432, `flags_extra`= 0, `ScriptName`= 'npc_husam_tolvir_land_mine' WHERE `entry`= 44796;
-- Bad Intentions Target
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 44586;

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (44711, 44712, 44840, 44798, 44796, 44586);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(44711, 0, 0, 1, 0),
(44712, 0, 0, 1, 1),
(44840, 0, 0, 1, 1),
(44798, 0, 0, 1, 1),
(44796, 0, 0, 1, 0),
(44586, 0, 0, 1, 0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 44798;
DELETE FROM `vehicle_template_accessory` WHERE `entry`= 44798;

UPDATE `creature_template` SET `ScriptName`= 'npc_husam_bad_intentions_target', `AIName`='' WHERE `entry`= 44586;
UPDATE `creature_template` SET `ScriptName`= 'npc_husam_shockwave_visual', `AIName`='' WHERE `entry`= 44712;

DELETE FROM `creature_text` WHERE `CreatureID`= 44577;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(44577, 0, 0, 'Invaders, you shall go no further!', 14, 0, 100, 0, 0, 0, 49310, 'General Husam - Aggro'),
(44577, 1, 0, 'Insolent rat!', 14, 0, 100, 0, 0, 0, 49311, 'General Husam - Slay'),
(44577, 2, 0, 'Murkash!', 14, 0, 100, 0, 0, 0, 49313, 'General Husam - Shockwave'),
(44577, 3, 0, '|TInterface\\Icons\\spell_nature_earthquake.blp:20|t%s begins to cast |cFFFF0000|Hspell:83445|h[Shockwave]!|h|r', 41, 0, 100, 0, 0, 0, 44921, 'General Husam - Announce Shockwave'),
(44577, 4, 0, 'Tread Lightly.', 14, 0, 100, 0, 0, 0, 49314, 'General Husam - Detonate Mines'),
(44577, 5, 0, 'Siamat must not be freed! Turn back before it is too late!', 14, 0, 100, 0, 0, 0, 49312, 'General Husam - Death');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_husam_hammer_fist', 
'spell_husam_shockwave_summon_search',
'spell_husam_shockwave',
'spell_husam_detonate_traps',
'spell_husam_bad_intentions',
'spell_husam_hurl',
'spell_husam_hurl_vehicle',
'spell_husam_land_mine_player_search_effect');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(83654, 'spell_husam_hammer_fist'),
(83466, 'spell_husam_shockwave_summon_search'),
(83445, 'spell_husam_shockwave'),
(91263, 'spell_husam_detonate_traps'),
(83113, 'spell_husam_bad_intentions'),
(83236, 'spell_husam_hurl'),
(83235, 'spell_husam_hurl_vehicle'),
(83112, 'spell_husam_land_mine_player_search_effect');

DELETE FROM `creature_template_addon` WHERE `entry` IN (44712, 44840, 44798, 44796);
INSERT INTO `creature_template_addon` (`entry`, `SheathState`, `Auras`) VALUES
(44712, 1, '83127');

DELETE FROM conditions WHERE `SourceTypeOrReferenceId`= 13 AND `SourceEntry` IN (83466, 83445, 91263);
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ScriptName, Comment) VALUES
(13, 0x1, 83466, 0, 0, 51, 0, 5, 44712, 0, 0, 0, '', 'Shockwave Summon Search - Target Shockwave Visual'),
(13, 0x1, 83445, 0, 0, 51, 0, 5, 44711, 0, 0, 0, '', 'Shockwave - Target Shockwave Stalker'),
(13, 0x1, 91263, 0, 0, 51, 0, 5, 44796, 0, 0, 0, '', 'Detonate Traps - Target Tolvir Land Mine');
