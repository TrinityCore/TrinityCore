DELETE FROM `spell_script_names` WHERE `spell_id` IN (72378,73058) AND `ScriptName`='spell_deathbringer_blood_nova_targeting';
DELETE FROM `spell_script_names` WHERE `spell_id` IN (68921,69049) AND `ScriptName`='spell_bronjahm_soulstorm_targeting';
DELETE FROM `spell_script_names` WHERE `spell_id` IN (70402,72511,72512,72513) AND `ScriptName`='spell_putricide_mutated_transformation_dmg';
DELETE FROM `spell_script_names` WHERE `spell_id` IN (72255,72444,72445,72446) AND `ScriptName`='spell_deathbringer_mark_of_the_fallen_champion';
DELETE FROM `spell_script_names` WHERE `spell_id`=71390 AND `ScriptName`='spell_blood_queen_pact_of_the_darkfallen';
DELETE FROM `spell_script_names` WHERE `spell_id`=48743 AND `ScriptName`='spell_dk_death_pact';
DELETE FROM `spell_script_names` WHERE `spell_id`=59725 AND `ScriptName`='spell_warr_improved_spell_reflection';
DELETE FROM `spell_script_names` WHERE `spell_id`=-49821 AND `ScriptName`='spell_pri_mind_sear';
DELETE FROM `spell_script_names` WHERE `spell_id`=-27285 AND `ScriptName`='spell_warl_seed_of_corruption';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(72378,'spell_deathbringer_blood_nova_targeting'),
(73058,'spell_deathbringer_blood_nova_targeting'),
(68921,'spell_bronjahm_soulstorm_targeting'),
(69049,'spell_bronjahm_soulstorm_targeting'),
(70402,'spell_putricide_mutated_transformation_dmg'),
(72511,'spell_putricide_mutated_transformation_dmg'),
(72512,'spell_putricide_mutated_transformation_dmg'),
(72513,'spell_putricide_mutated_transformation_dmg'),
(72255,'spell_deathbringer_mark_of_the_fallen_champion'),
(72444,'spell_deathbringer_mark_of_the_fallen_champion'),
(72445,'spell_deathbringer_mark_of_the_fallen_champion'),
(72446,'spell_deathbringer_mark_of_the_fallen_champion'),
(71390,'spell_blood_queen_pact_of_the_darkfallen'),
(48743,'spell_dk_death_pact'),
(59725,'spell_warr_improved_spell_reflection'),
(-49821,'spell_pri_mind_sear'),
(-27285,'spell_warl_seed_of_corruption');
