-- VoidReaver 19516
UPDATE `creature_template` SET `ScriptName` = 'boss_void_reaver' WHERE `entry` = 19516;

-- Arcane Orb Target
REPLACE INTO `creature_template` (`entry`, `modelid_A`, `modelid_H`, `name`, `subname`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, `faction_H`, `npcflag`, `speed`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `baseattacktime`, `rangeattacktime`, `flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `class`, `race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `civilian`, `flag1`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `RacialLeader`, `RegenHealth`, `equipment_id`, `ScriptName`) VALUES (19577, 16946, 16946, 'Arcane Orb Target', '', 70, 70, 1, 1, 0, 0, 0, 35, 35, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 0, 1, 0, 'mob_arcane_orb_target');

UPDATE `creature_template` SET `ScriptName` = 'boss_omor_the_unscarred' WHERE `entry` = 17308;
UPDATE `creature_template` SET `ScriptName` = 'boss_watchkeeper_gargolmar' WHERE `entry` = 17306;

UPDATE `creature_template` SET `ScriptName` = 'boss_hungarfen' WHERE `entry` = 17770;
UPDATE `creature_template` SET `ScriptName` = 'mob_underbog_mushroom' WHERE `entry` = 17990;