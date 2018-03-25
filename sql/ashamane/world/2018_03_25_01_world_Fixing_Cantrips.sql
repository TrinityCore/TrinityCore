-- Adding DisplayID to Model_info --
DELETE FROM creature_model_info WHERE displayID = 81477;
insert into `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) values
(81477,0,0,0,0);

-- Adding Creature to Template --
DELETE FROM creature_template WHERE entry = 129356;
insert into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
(129356,0,0,0,0,0,81477,0,0,0,"Eldritch Grimoire","","","","",0,0,0,-1,0,0,35,67108864,1,1.14286,1,0,0,2000,2000,0,0,2,131848,2048,0,0,0,0,0,0,4,16778240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"",0,8,1,1,1,1,1,1,1,1,0,0,1,0,0,"",25596);

-- Adding Hover --
DELETE FROM creature_template_addon WHERE entry = 129356;
insert into `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`) values
(129356,0,0,33554432,0,0,0,0,0);