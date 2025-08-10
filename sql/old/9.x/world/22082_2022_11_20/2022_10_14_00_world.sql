DELETE FROM `serverside_spell` WHERE `Id`=132334;
INSERT INTO `serverside_spell` (`Id`,`DifficultyID`,`CategoryId`,`Dispel`,`Mechanic`,`Attributes`,`AttributesEx`,`AttributesEx2`,`AttributesEx3`,`AttributesEx4`,`AttributesEx5`,`AttributesEx6`,`AttributesEx7`,`AttributesEx8`,`AttributesEx9`,`AttributesEx10`,`AttributesEx11`,`AttributesEx12`,`AttributesEx13`,`AttributesEx14`,`Stances`,`StancesNot`,`Targets`,`TargetCreatureType`,`RequiresSpellFocus`,`FacingCasterFlags`,`CasterAuraState`,`TargetAuraState`,`ExcludeCasterAuraState`,`ExcludeTargetAuraState`,`CasterAuraSpell`,`TargetAuraSpell`,`ExcludeCasterAuraSpell`,`ExcludeTargetAuraSpell`,`CastingTimeIndex`,`RecoveryTime`,`CategoryRecoveryTime`,`StartRecoveryCategory`,`StartRecoveryTime`,`InterruptFlags`,`AuraInterruptFlags1`,`AuraInterruptFlags2`,`ChannelInterruptFlags1`,`ChannelInterruptFlags2`,`ProcFlags`,`ProcFlags2`,`ProcChance`,`ProcCharges`,`ProcCooldown`,`ProcBasePPM`,`MaxLevel`,`BaseLevel`,`SpellLevel`,`DurationIndex`,`RangeIndex`,`Speed`,`LaunchDelay`,`StackAmount`,`EquippedItemClass`,`EquippedItemSubClassMask`,`EquippedItemInventoryTypeMask`,`ContentTuningId`,`SpellName`,`ConeAngle`,`ConeWidth`,`MaxTargetLevel`,`MaxAffectedTargets`,`SpellFamilyName`,`SpellFamilyFlags1`,`SpellFamilyFlags2`,`SpellFamilyFlags3`,`SpellFamilyFlags4`,`DmgClass`,`PreventionType`,`AreaGroupId`,`SchoolMask`,`ChargeCategoryId`) VALUES
(132334,0,0,0,0,0x2D800000,0x80000020,0x10024081,0x530000,0x100081,0x60408,0x10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,25,1,0,0,0,-1,0,0,0,'Trainer Heal Cooldown',0,0,0,0,0,0,0,0,0,0,0,0,0,0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID`=132334;
INSERT INTO `serverside_spell_effect` (`SpellID`,`Effect`,`EffectAura`,`EffectChainAmplitude`) VALUES
(132334,6,4,1);

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_trainer_heal_cooldown';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(132334,'spell_gen_trainer_heal_cooldown');
