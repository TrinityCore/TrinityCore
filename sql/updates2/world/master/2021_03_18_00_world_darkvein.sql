UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='170199');
REPLACE INTO `smart_scripts` (`entryorguid`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `target_type`, `comment`) VALUES ('170199', '1500', '2000', '8000', '10000', '11', '331573', '2', 'Unconscionable Guilt');
REPLACE INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`) VALUES ('327125', '327125');
REPLACE INTO `areatrigger_template` (`Id`, `Data1`, `Data2`, `ScriptName`) VALUES ('327125', '2.5', '2.5', 'at_fragments_of_shadow');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('340452', 'aura_change_of_heart');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('332664', 'aura_concentrated_anima');
UPDATE `areatrigger_template` SET `ScriptName`='at_bottled_anima' WHERE (`Id`='24398');
UPDATE `areatrigger_template` SET `ScriptName`='at_lingering_anima' WHERE (`Id`='24030');
UPDATE `creature_template` SET `unit_flags`='768', `flags_extra`='128' WHERE (`entry`='166766');
