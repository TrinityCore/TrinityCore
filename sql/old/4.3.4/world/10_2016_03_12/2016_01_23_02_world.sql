--
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_energize_aoe','spell_ooze_zap','spell_ooze_zap_channel_end');
DELETE FROM `areatrigger_scripts` WHERE `ScriptName` = 'at_ancient_leaf';
UPDATE `gameobject_template` SET `ScriptName`='' WHERE `entry`=180526;
