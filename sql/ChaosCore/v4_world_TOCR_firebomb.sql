-- Firebomb Spell difficulty entrys, the last two ones trigger the stackable dot.
DELETE FROM `spelldifficulty_dbc` WHERE `spellid0` = 66320;
INSERT INTO `spelldifficulty_dbc` VALUES
(3265,66320,67472,67473,67475);
-- Firebomb NPC script
UPDATE `creature_template` SET `unit_flags` = 33685504, `ScriptName` = 'mob_fire_bomb' WHERE `entry` = 34854;
-- Fire bomb NPC summon Trigger
-- Wy this spell isn't on DBC?
DELETE FROM `spell_dbc` WHERE `id` = 66319;
INSERT INTO `spell_dbc` (`id`, `SchoolMask`, `DurationIndex`, `Effect1`, `EffectBasePoints1`, `EffectImplicitTargetA1`, `EffectImplicitTargetB1`, `EffectMiscValue1`, `EffectMiscValueB1`, `Comment`) VALUES
(66319,1,3,28,1,18,0,34854,64,'Trial Of Crusader Firebomb Npc Summon trigger from 66313');