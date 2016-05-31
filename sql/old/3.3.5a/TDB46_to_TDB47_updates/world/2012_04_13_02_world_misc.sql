UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (38308,38309,37824); -- Professor Putricide triggers
UPDATE `creature_template` SET `ScriptName`='npc_gas_cloud' WHERE `entry`=37562; -- Gas Cloud
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_putricide_ooze_summon';
DELETE FROM `spell_target_position` WHERE `id` IN (71413,71414);
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(71414,631,4335.00,3206.75,389.399,0),
(71413,631,4380.43,3206.55,389.398,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (71615,71618,71412,71415);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`Comment`) VALUES
(13,4,71615,31,3,37690,'Putricide - Tear Gas on Slime Puddle'),
(13,1,71618,31,3,37562,'Putricide - Tear Gas on Gas Cloud'),
(13,2,71618,31,3,37697,'Putricide - Tear Gas on Volatile Ooze'),
(13,4,71618,31,3,38159,'Putricide - Tear Gas on Choking Gas Bomb');

UPDATE `spell_script_names` SET `ScriptName`='spell_putricide_clear_aura_effect_value' WHERE `ScriptName`='spell_putricide_clear_mutated_plague';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(71620,'spell_putricide_clear_aura_effect_value');
