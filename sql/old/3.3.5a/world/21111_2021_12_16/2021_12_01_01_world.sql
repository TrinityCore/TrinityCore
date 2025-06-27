--
DELETE FROM `spell_script_names` WHERE `spell_id` IN (35268,39346) AND `ScriptName` = 'spell_nethermancer_sepethrea_inferno';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(35268,'spell_nethermancer_sepethrea_inferno'),
(39346,'spell_nethermancer_sepethrea_inferno');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 35277;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,35277,0,0,31,0,3,20481,0,0,0,0,"","Group 0: Spell 'Quell Raging Flames' (Effect 0) targets creature 'Raging Flames'");

-- They're not immune even to fire, only to all mechanics
UPDATE `creature_template` SET `ScriptName` = 'npc_raging_flames' WHERE `entry` = 20481;
UPDATE `creature_template` SET `mechanic_immune_mask` = 617299803, `spell_school_immune_mask` = 0 WHERE `entry` IN (20481,21538);

UPDATE `spell_dbc` SET `ProcFlags` = 20, `ProcChance` = 100, `BaseLevel` = 70, `SpellLevel` = 70, `Effect1` = 6, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 42, `EffectTriggerSpell1` = 45195, `DmgClass` = 1, `PreventionType` = 1, `DmgMultiplier1` = 1, `DmgMultiplier2` = 1 WHERE `Id` = 45196;
