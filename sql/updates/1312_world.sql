UPDATE `creature_template` SET `scriptname` = 'boss_keleseth' WHERE `entry` = '23953';
UPDATE `creature_template` SET `scriptname` = 'mob_frost_tomb' WHERE `entry` = '23965';
UPDATE `instance_template` SET `script`='instance_utgarde_keep' WHERE `map`= '574';

INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
(-1574000, 'Your blood is mine!',13221,1,0,'keleseth SAY_AGGRO'),
(-1574001, 'Darkness waits',13223,1,0, 'keleseth SAY_KILL'),
(-1574002, 'I join... the night.',13225,1,0, 'keleseth SAY_DEATH'),
(-1574003, 'Not so fast.',13222,1,0, 'keleseth SAY_FROST_TOMB'),
(-1574004, 'Aranal, lidel! Their fate shall be yours!',13224,1,0, 'keleseth SAY_SKELETONS');

-- DB Data for testing
-- REPLACE INTO `creature_template` (`entry`, `heroic_entry`, `modelid_A`, `modelid_A2`, `modelid_H`, `modelid_H2`, `name`, `subname`, `IconName`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, `faction_H`, `npcflag`, `speed`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `baseattacktime`, `rangeattacktime`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `class`, `race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `PetSpellDataId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `RacialLeader`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES
-- (23953, 0, 25338, 0, 25338, 0, 'Prince Keleseth', NULL, NULL, 70, 80, 192200, 417056, 0, 0, 6700, 16, 16, 2, 1, 1, 0, 445, 1200, 0, 58, 2000, 2200, 0, 0, 0, 0, 0, 0, 0, 1, 2, 100, 6, 76, 23953, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '0', 0, 3, 3, 0, 0, 0, 0, 'boss_keleseth'),
-- (23965, 0, 25865, 0, 25865, 0, 'Frost Tomb', NULL, NULL, 70, 80, 7345, 10465, 0, 0, 6700, 16, 16, 0, 1, 1, 0, 445, 1200, 0, 58, 2000, 2200, 0, 0, 0, 0, 0, 0, 0, 1, 2, 100, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '0', 0, 3, 3, 0, 0, 0, 0, 'mob_frost_tomb'),
-- (23970, 0, 27651, 0, 27651, 0, 'Vrykul Skeleton', NULL, NULL, 70, 80, 7345, 10465, 0, 0, 6700, 16, 16, 0, 1, 1, 0, 445, 1200, 0, 58, 2000, 2200, 0, 0, 0, 0, 0, 0, 0, 1, 2, 100, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '0', 0, 3, 3, 0, 716, 0, 0, '0');