-- 
UPDATE `spell_dbc` SET `Effect1`=1, `EffectDieSides1`=1, `EffectBasePoints1`=-1, `EffectImplicitTargetA1`=1, `EffectMultipleValue1`=1, `DmgClass`=1, `PreventionType`=1, `DmgMultiplier1`=1, `DmgMultiplier2`=1, `DmgMultiplier3`=1 WHERE `id` IN (43388);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23564,24198,24199) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23564, 0, 0, 1, 8, 0, 100, 1, 42166, 0, 0, 0, 0, 11, 43399, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Tribesman - On Spellhit 'Plagued Blood Explosion' - Cast 'Plagued Vrykul Force Credit'"),
(23564, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 11, 42167, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Tribesman - On Spellhit 'Plagued Blood Explosion' - Cast 'Plagued Blood Explosion'"),
(23564, 0, 2, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 11, 43506, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Tribesman - On Aggro - Cast 'Plague Blight'"),
(23564, 0, 3, 4, 8, 0, 100, 1, 43381, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Tribesman - On Spellhit 'Plague Spray' - Say Line 0"),
(23564, 0, 4, 5, 61, 0, 100, 512, 0, 0, 0, 0, 0, 2, 1925, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Tribesman - On Spellhit 'Plague Spray' - Set Faction 1925"),
(23564, 0, 5, 0, 61, 0, 100, 512, 0, 0, 0, 0, 0, 11, 43384, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Tribesman - On Spellhit 'Plague Spray' - Cast 'Spray Credit'"),
(23564, 0, 6, 0, 8, 0, 100, 1, 43385, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 0, 30, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Tribesman - On Spellhit 'Plagued Vrykul Dummy' - Start Attacking"),
(23564, 0, 7, 0, 1, 0, 35, 0, 0, 30000, 25000, 45000, 0, 11, 43327, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Tribesman - Out of Combat - Cast 'Vomit'"),
(23564, 0, 8, 0, 0, 0, 100, 0, 2000, 4000, 5000, 8000, 0, 11, 32736, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Tribesman - In Combat - Cast 'Mortal Strike'"),
(23564, 0, 9, 0, 0, 0, 100, 0, 1000, 1000, 4000, 5000, 0, 11, 15496, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Tribesman - In Combat - Cast 'Cleave'"),
(24198, 0, 0, 1, 8, 0, 100, 1, 42166, 0, 0, 0, 0, 11, 43399, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Rune-Caster - On Spellhit 'Plagued Blood Explosion' - Cast 'Plagued Vrykul Force Credit'"),
(24198, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 11, 42167, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Rune-Caster - Out of Combat - Cast 'Plagued Blood Explosion'"),
(24198, 0, 2, 3, 8, 0, 100, 1, 43381, 0, 0, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Rune-Caster - On Spellhit 'Plague Spray' - Say Line 0"),
(24198, 0, 3, 4, 61, 0, 100, 512, 0, 0, 0, 0, 0, 2, 1925, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Rune-Caster - On Spellhit 'Plagued Blood Explosion' - Set Faction 1925"),
(24198, 0, 4, 0, 61, 0, 100, 512, 0, 0, 0, 0, 0, 11, 43384, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Rune-Caster - On Spellhit 'Plague Spray' - Cast 'Spray Credit'"),
(24198, 0, 5, 0, 8, 0, 100, 1, 43385, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 0, 30, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Rune-Caster - On Spellhit 'Plagued Vrykul Dummy' - Start Attacking"),
(24198, 0, 6, 0, 1, 0, 35, 0, 0, 30000, 25000, 45000, 0, 11, 43327, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Rune-Caster - Out of Combat - Cast 'Vomit'"),
(24198, 0, 7, 0, 0, 0, 100, 0, 0, 0, 18000, 20000, 0, 11, 47782, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Rune-Caster - In Combat - Cast 'Corruption'"),
(24198, 0, 8, 0, 0, 0, 100, 0, 10000, 12000, 15000, 17000, 0, 11, 15616, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Rune-Caster - In Combat - Cast 'Flame Shock'"),
(24199, 0, 0, 1, 8, 0, 100, 1, 42166, 0, 0, 0, 0, 11, 43399, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Handler - On Spellhit 'Plagued Blood Explosion' - Cast 'Plagued Vrykul Force Credit'"),
(24199, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 11, 42167, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Handler - On Spellhit 'Plague Spray' - Cast 'Plagued Blood Explosion'"),
(24199, 0, 2, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 11, 43506, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Handler - On Aggro - Cast 'Plague Blight'"),
(24199, 0, 3, 4, 8, 0, 100, 1, 43381, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Handler - On Spellhit 'Plague Spray' - Say Line 0"),
(24199, 0, 4, 5, 61, 0, 100, 512, 0, 0, 0, 0, 0, 2, 1925, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Handler - On Spellhit 'Plague Spray' - Set Faction 1925"),
(24199, 0, 5, 0, 61, 0, 100, 512, 0, 0, 0, 0, 0, 11, 43384, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Handler - On Spellhit 'Plague Spray' - Cast 'Spray Credit'"),
(24199, 0, 6, 0, 8, 0, 100, 1, 43385, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 0, 30, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Handler - On Spellhit 'Plagued Vrykul Dummy' - Start Attacking"),
(24199, 0, 7, 0, 1, 0, 35, 0, 0, 30000, 25000, 45000, 0, 11, 43327, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plagued Dragonflayer Handler - Out of Combat - Cast 'Vomit'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=43381;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`,`ScriptName`, `Comment`) VALUES
(17, 0, 43381, 0, 0, 31, 1, 3, 23564, 0, 0, 173, 0, "", "Plague Spray - Plagued Dragonflayer Tribesman"),
(17, 0, 43381, 0, 0, 1, 1, 43381, 0, 0, 1, 173, 0, "", "Plague Spray - Plagued Dragonflayer Tribesman"),
(17, 0, 43381, 0, 1, 31, 1, 3, 24198, 0, 0, 173, 0, "", "Plague Spray - Plagued Dragonflayer Rune-Caster"),
(17, 0, 43381, 0, 1, 1, 1, 43381, 0, 0, 1, 173, 0, "", "Plague Spray - Plagued Dragonflayer Rune-Caster"),
(17, 0, 43381, 0, 2, 31, 1, 3, 24199, 0, 0, 173, 0, "", "Plague Spray - Plagued Dragonflayer Handler"),
(17, 0, 43381, 0, 2, 1, 1, 43381, 0, 0, 1, 173, 0, "", "Plague Spray - Plagued Dragonflayer Handler");
