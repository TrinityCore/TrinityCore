UPDATE `npc_spellclick_spells` SET `aura_required`=0 WHERE `aura_required`=62853;
DELETE FROM `spell_script_names` WHERE `spell_id` IN (62774,62779,62780,62781,62782,62783,62784,62785,62786,62787,63663,63791,63792);
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES
(62774,'spell_gen_summon_argent_mount'),
(62779,'spell_gen_summon_argent_mount'),
(62780,'spell_gen_summon_argent_mount'),
(62781,'spell_gen_summon_argent_mount'),
(62782,'spell_gen_summon_argent_mount'),
(62783,'spell_gen_summon_argent_mount'),
(62784,'spell_gen_summon_argent_mount'),
(62785,'spell_gen_summon_argent_mount'),
(62786,'spell_gen_summon_argent_mount'),
(62787,'spell_gen_summon_argent_mount'),
(63663,'spell_gen_summon_argent_mount'),
(63791,'spell_gen_summon_argent_mount'),
(63792,'spell_gen_summon_argent_mount');