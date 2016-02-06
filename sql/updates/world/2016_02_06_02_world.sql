-- 
-- Knockbackimmunity Cleanup
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x40000000 WHERE `entry` IN (
-- npc_kinetic_bomb
38454, 38775, 38776, 38777,
-- npc_iron_roots
33088, 33396, 33168, 33397,
-- npc_saronite_vapors
33488, 33789,
-- NPC_GAS_CLOUD
37562, 38602, 38760, 38761,
-- NPC_VOLATILE_OOZE
37697, 38604, 38758, 38759,
-- npc_training_dummy
2673, 2674, 17578, 16111, 24792, 32543, 32546, 32547, 32542, 32545, 30527, 31143, 31144, 31146, 32541, 32666, 32667,
-- npc_tournament_training_dummy
33229, 33243, 33272,
-- npc_ice_tomb
36980, 38320, 38321, 38322
);
