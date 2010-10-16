DELETE FROM `spell_script_names` WHERE `spell_id`=70701 AND `ScriptName`='spell_putricide_expunged_gas';
DELETE FROM `spell_script_names` WHERE `spell_id`=70343 AND `ScriptName`='spell_putricide_slime_puddle';
DELETE FROM `spell_script_names` WHERE `spell_id` IN (70351,71966,71967,71968) AND `ScriptName`='spell_putricide_unstable_experiment';
DELETE FROM `spell_script_names` WHERE `spell_id` IN (71412,71415) AND `ScriptName`='spell_putricide_ooze_summon';
DELETE FROM `spell_script_names` WHERE `spell_id` IN (70672,72455,72832,72833) AND `ScriptName`='spell_putricide_gaseous_bloat';
DELETE FROM `spell_script_names` WHERE `spell_id`=70459 AND `ScriptName`='spell_putricide_ooze_eruption_searcher';
DELETE FROM `spell_script_names` WHERE `spell_id`=71255 AND `ScriptName`='spell_putricide_choking_gas_bomb';
DELETE FROM `spell_script_names` WHERE `spell_id`=70920 AND `ScriptName`='spell_putricide_unbound_plague';
DELETE FROM `spell_script_names` WHERE `spell_id` IN (70360,72527) AND `ScriptName`='spell_putricide_eat_ooze';
DELETE FROM `spell_script_names` WHERE `spell_id` IN (72451,72463,72671,72672) AND `ScriptName`='spell_putricide_mutated_plague';
DELETE FROM `spell_script_names` WHERE `spell_id`=70308 AND `ScriptName`='spell_putricide_mutation_init';
DELETE FROM `spell_script_names` WHERE `spell_id` IN (70311,71503) AND `ScriptName`='spell_putricide_mutated_transformation';
DELETE FROM `spell_script_names` WHERE `spell_id` IN (70405,72508,72509,72510) AND `ScriptName`='spell_putricide_mutated_transformation_dismiss';
DELETE FROM `spell_script_names` WHERE `spell_id` IN (70539,72457,72875,72876) AND `ScriptName`='spell_putricide_regurgitated_ooze';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(70701,'spell_putricide_expunged_gas'),
(70343,'spell_putricide_slime_puddle'),
(70351,'spell_putricide_unstable_experiment'),
(71966,'spell_putricide_unstable_experiment'),
(71967,'spell_putricide_unstable_experiment'),
(71968,'spell_putricide_unstable_experiment'),
(71412,'spell_putricide_ooze_summon'),
(71415,'spell_putricide_ooze_summon'),
(70672,'spell_putricide_gaseous_bloat'),
(72455,'spell_putricide_gaseous_bloat'),
(72832,'spell_putricide_gaseous_bloat'),
(72833,'spell_putricide_gaseous_bloat'),
(70459,'spell_putricide_ooze_eruption_searcher'),
(71255,'spell_putricide_choking_gas_bomb'),
(70920,'spell_putricide_unbound_plague'),
(70360,'spell_putricide_eat_ooze'),
(72527,'spell_putricide_eat_ooze'),
(72451,'spell_putricide_mutated_plague'),
(72463,'spell_putricide_mutated_plague'),
(72671,'spell_putricide_mutated_plague'),
(72672,'spell_putricide_mutated_plague'),
(70308,'spell_putricide_mutation_init'),
(70311,'spell_putricide_mutated_transformation'),
(71503,'spell_putricide_mutated_transformation'),
(70405,'spell_putricide_mutated_transformation_dismiss'),
(72508,'spell_putricide_mutated_transformation_dismiss'),
(72509,'spell_putricide_mutated_transformation_dismiss'),
(72510,'spell_putricide_mutated_transformation_dismiss'),
(70539,'spell_putricide_regurgitated_ooze'),
(72457,'spell_putricide_regurgitated_ooze'),
(72875,'spell_putricide_regurgitated_ooze'),
(72876,'spell_putricide_regurgitated_ooze');
