-- Shadow Fissure
UPDATE `creature_template` SET `unit_flags` = 33554432, `unit_flags2` = `unit_flags2` &~ 2048, `BaseAttackTime` = 2000, `ScriptName` = 'npc_kelthuzad_shadow_fissure' WHERE `entry` = 16129;
DELETE FROM `creature_template_spell` WHERE `CreatureID` = 16129;

-- Sapphiron's Wing Buffet
UPDATE `creature_template` SET `BaseAttackTime` = 2000, `ScriptName` = 'npc_sapphiron_wing_buffet', `flags_extra` = `flags_extra` &~ 0x00002000 WHERE `entry` = 17025;
DELETE FROM `creature_template_addon` WHERE `entry` = 17025;

DELETE FROM `spell_script_names` WHERE `spell_id` = 29330 AND `ScriptName` = 'spell_sapphiron_wing_buffet_despawn_periodic';
DELETE FROM `spell_script_names` WHERE `spell_id` = 29336 AND `ScriptName` = 'spell_sapphiron_despawn_buffet';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(29330,'spell_sapphiron_wing_buffet_despawn_periodic'),
(29336,'spell_sapphiron_despawn_buffet');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 29336;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,29336,0,0,31,0,3,17025,0,0,0,0,"","Group 0: Spell 'Despawn Buffet' (Effect 0) targets creature 'Sapphiron's Wing Buffet'");

-- Void Zone
UPDATE `creature_template` SET `unit_flags2` = `unit_flags2` &~ 2048, `BaseAttackTime` = 2000, `ScriptName` = 'npc_gen_void_zone' WHERE `entry` = 16697;
DELETE FROM `creature_template_spell` WHERE `CreatureID` = 16697;
