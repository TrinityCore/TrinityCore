UPDATE creature_template SET `ScriptName`='npc_watcher_narjil' WHERE `entry`=28729;
UPDATE creature_template SET `ScriptName`='npc_watcher_silthik' WHERE `entry`=28731;
UPDATE creature_template SET `ScriptName`='npc_watcher_gashra' WHERE `entry`=28730;
UPDATE `creature_template` SET `equipment_id`=2500 WHERE `entry`=33515; -- Freya
UPDATE `creature_template` SET `ScriptName`='npc_feral_defender' WHERE `entry`=34035; -- Feral Defender
UPDATE `creature_template` SET `ScriptName`='npc_sanctum_sentry' WHERE `entry`=34014; -- Sanctum Sentry
UPDATE `creature_template` SET `ScriptName`='npc_auriaya_seeping_trigger',`unit_flags`=33554692,`flags_extra`=130 WHERE `entry` =34098; -- Seeping Trigger
UPDATE `creature_template` SET `ScriptName`='',`unit_flags`=33554692,`flags_extra`=128 WHERE `entry` =34096; -- Feral Defender Trigger
DELETE FROM `spell_script_names` WHERE `spell_id`=64381;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`)
VALUES
(64381,'spell_auriaya_strenght_of_the_pack');
UPDATE `creature_template` SET `ScriptName`='npc_saronite_vapors' WHERE `entry`=33488; -- Saronite Vapors
UPDATE `creature_template` SET `ScriptName`='npc_saronite_animus' WHERE `entry`=33524; -- Saronite Animus
DELETE FROM `spell_script_names` WHERE `spell_id`=63276;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`)
VALUES
(63276,'spell_mark_of_the_faceless');
UPDATE `creature_template` SET `ScriptName`='boss_freya' WHERE `entry`=32906;
UPDATE `creature_template` SET `ScriptName`='boss_elder_brightleaf' WHERE `entry`=32915;
UPDATE `creature_template` SET `ScriptName`='boss_elder_ironbranch' WHERE `entry`=32913;
UPDATE `creature_template` SET `ScriptName`='boss_elder_stonebark' WHERE `entry`=32914;
UPDATE `creature_template` SET `ScriptName`='npc_ancient_conservator' WHERE `entry`=33203;
UPDATE `creature_template` SET `ScriptName`='npc_snaplasher' WHERE `entry`=32916;
UPDATE `creature_template` SET `ScriptName`='npc_storm_lasher' WHERE `entry`=32919;
UPDATE `creature_template` SET `ScriptName`='npc_ancient_water_spirit' WHERE `entry`=33202;
UPDATE `creature_template` SET `ScriptName`='npc_detonating_lasher' WHERE `entry`=32918;
UPDATE `creature_template` SET `ScriptName`='npc_sun_beam' WHERE `entry`=33170;
UPDATE `creature_template` SET `ScriptName`='npc_nature_bomb' WHERE `entry`=34129;
UPDATE `creature_template` SET `ScriptName`='npc_eonars_gift' WHERE `entry`=33228;
UPDATE `creature_template` SET `ScriptName`='npc_healthy_spore' WHERE `entry`=33215;
UPDATE `creature_template` SET `ScriptName`='npc_unstable_sun_beam' WHERE `entry`=33050;
UPDATE `creature_template` SET `ScriptName`='npc_iron_roots' WHERE `entry` IN (33088,33168);
-- Change spell script name for Attuned To Nature Dose Reduction
UPDATE `spell_script_names` SET `ScriptName`='spell_freya_attuned_to_nature_dose_reduction' WHERE `ScriptName`='spell_attuned_to_nature_dose_reduction';
DELETE FROM `disables` WHERE `entry`=7598 AND `sourceType`=4;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=7598 AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(7598,11,0,0,'achievement_kings_bane');
DELETE FROM `disables` WHERE `entry`=7587 AND `sourceType`=4;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=7587 AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(7587,11,0,0,'achievement_void_dance');
