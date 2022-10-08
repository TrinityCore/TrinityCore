-- updates
UPDATE `creature_template` SET `ScriptName` = 'mob_return_to_the_terrace' WHERE `entry` = 65736;
UPDATE `creature_template` SET `ScriptName` = 'npc_embodied_terror' WHERE `entry` = 62969;
UPDATE `creature_template` SET `ScriptName` = 'npc_unstable_sha' WHERE `entry` = 62919;
UPDATE `creature_template` SET `ScriptName` = 'npc_frigten_spawn' WHERE `entry` = 62977;
UPDATE `creature_template` SET `ScriptName` = 'mob_pure_light_terrace' WHERE `entry` = 60788;
-- sha globe
UPDATE `creature_template` SET `ScriptName` = 'mob_globue' WHERE `entry` = 65691;
-- guardians
UPDATE `creature_template` SET `ScriptName` = 'mob_guardian' WHERE `entry` = 61038;
UPDATE `creature_template` SET `ScriptName` = 'mob_guardian' WHERE `entry` = 61042;
UPDATE `creature_template` SET `ScriptName` = 'mob_guardian' WHERE `entry` = 61046;
-- triggers
UPDATE `creature_template` SET `ScriptName` = 'trigger_PureLight_Visual' WHERE `entry` = 61797;

-- inserts
REPLACE INTO `creature_template`(`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) VALUES (657361, 0, 90, 90, 0, 0, 0, 0, 0, 4, 35, 16777216, 0, 2, 0.714286, 1.14286, 1, 580, 870, 0, 218, 1, 2000, 2000, 1, 0, 69208064, 0, 0, 0, 0, 0, 0, 464, 696, 174, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 'mob_return_to_the_terrace');
REPLACE INTO `creature_template`(`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) VALUES (657360, 0, 90, 90, 0, 0, 0, 0, 0, 4, 35, 16777216, 0, 2, 0.714286, 1.14286, 1, 580, 870, 0, 218, 1, 2000, 2000, 1, 0, 69208064, 0, 0, 0, 0, 0, 0, 464, 696, 174, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 'mob_return_to_the_terrace');
-- triggers
REPLACE INTO `creature_template`(`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) VALUES (654840, 0, 1, 1, 0, 0, 0, 0, 0, 4, 35, 1091568640, 0, 1, 1.14286, 1.14286, 1, 0, 0, 0, 0, 1, 2000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 'trigger_PureLight');
REPLACE INTO `creature_template`(`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) VALUES (654841, 0, 1, 1, 0, 0, 0, 0, 0, 4, 35, 1091568640, 0, 1, 1.14286, 1.14286, 1, 0, 0, 0, 0, 1, 2000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_template`(`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) VALUES (654842, 0, 1, 1, 0, 0, 0, 0, 0, 4, 35, 1091568640, 0, 1, 1.14286, 1.14286, 1, 0, 0, 0, 0, 1, 2000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, '');

-- script names
UPDATE `creature_template` SET `ScriptName` = 'boss_protector_kaolan' WHERE `entry` = 60583;
UPDATE `creature_template` SET `ScriptName` = 'boss_ancient_regail' WHERE `entry` = 60585;
UPDATE `creature_template` SET `ScriptName` = 'boss_ancient_asani' WHERE `entry` = 60586;
UPDATE `creature_template` SET `ScriptName` = 'mob_corrupting_waters' WHERE `entry` = 60621;
UPDATE `creature_template` SET `ScriptName` = 'mob_defiled_ground' WHERE `entry` = 60906;
UPDATE `creature_template` SET `ScriptName` = 'mob_coalesced_corruption' WHERE `entry` = 60886;
UPDATE `creature_template` SET `ScriptName` = 'mob_cleansing_water' WHERE `entry` = 60646;
UPDATE `creature_template` SET `ScriptName` = 'npc_springtender_ashani' WHERE `entry` = 64846;
UPDATE `creature_template` SET `ScriptName` = 'npc_apparition_of_fear' WHERE `entry` = 64368;
UPDATE `creature_template` SET `ScriptName` = 'npc_apparition_of_terror' WHERE `entry` = 66100;
UPDATE `creature_template` SET `ScriptName` = 'mob_night_terrors' WHERE `entry` = 64390;
UPDATE `creature_template` SET `ScriptName` = 'mob_night_terror_summon' WHERE `entry` = 64393;
UPDATE `creature_template` SET `ScriptName` = 'creature_blacktalon_quartermaster' WHERE `entry` = 70436;
UPDATE `creature_template` SET `ScriptName` = 'mob_animated_protector' WHERE `entry` = 62995;
UPDATE `creature_template` SET `ScriptName` = 'mob_lei_shi_hidden' WHERE `entry` = 63099;
UPDATE `creature_template` SET `ScriptName` = 'mob_pure_light_terrace' WHERE `entry` = 60788;
UPDATE `creature_template` SET `ScriptName` = 'mob_terror_spawn' WHERE `entry` = 61034;

-- spell script names
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (117988, 'spell_defiled_ground_damage');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (117955, 'spell_expelled_corruption');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (118064, 'spell_lightning_storm_aura');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (118040, 'spell_lightning_storm_aura');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (118053, 'spell_lightning_storm_aura');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (118054, 'spell_lightning_storm_aura');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (118055, 'spell_lightning_storm_aura');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (118077, 'spell_lightning_storm_aura');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (118004, 'spell_lightning_storm_damage');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (118005, 'spell_lightning_storm_damage');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (118007, 'spell_lightning_storm_damage');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (118008, 'spell_lightning_storm_damage');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (111850, 'spell_lightning_prison');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (118191, 'spell_corrupted_essence');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (117905, 'spell_superior_corrupted_essence');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (117283, 'spell_cleansing_waters_regen');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (125736, 'spell_night_terrors_missile');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (125745, 'spell_night_terrors_periodic');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (123461, 'spell_get_away');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (123244, 'spell_hide');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (123233, 'spell_hide_stacks');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (123705, 'spell_scary_fog_dot');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (123712, 'spell_scary_fog_stacks');  
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (117866, 'spell_champion_of_light');  
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (119108, 'spell_conjure_terror_spawn'); 
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (120047, 'dread_spray_buff'); 
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (119953, 'spell_dread_spray_hit'); 
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (129075, 'spell_penetrating_bolt'); 
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (119888, 'spell_death_blossom'); 
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (119887, 'spell_death_blossom_damage'); 
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (117283, 'spell_breath_of_fear_spell'); 
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (119958, 'spell_dread_spray_damage_ori'); 
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (119593, 'spell_ominous_cackle'); 
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (125843, 'spell_dread_shadows_damage'); 
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (122768, 'spell_dread_shadows_malus');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (122789, 'spell_sunbeam'); 
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (122789, 'terroize_creature_restriction'); 
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (123011, 'spell_player_terrorize'); 

-- spawns
DELETE FROM `gameobject` WHERE `map` = 996 AND `id` = 214634;
DELETE FROM `gameobject` WHERE `map` = 996 AND `id` = 212916;