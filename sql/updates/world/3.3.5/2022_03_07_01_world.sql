-- From 2.0.12 DBC
UPDATE `spell_dbc` SET `Attributes` = 384, `AttributesEx2` = 128, `ProcChance` = 101, `RangeIndex` = 12, `Effect1` = 77, `EffectImplicitTargetA1` = 25, `SpellName` = 'Cancel Shadowy Disguise', `DmgMultiplier1` = 1 WHERE `Id` = 32780;

UPDATE `spell_script_names` SET `ScriptName` = 'spell_terokkar_free_webbed' WHERE `ScriptName` = 'spell_free_webbed_terokkar';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_terokkar_free_webbed_on_quest' WHERE `ScriptName` = 'spell_free_webbed_terokkar_on_quest';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_terokkar_shadowy_disguise_cast_from_questgiver' WHERE `ScriptName` = 'spell_q10041_q10040_who_are_they';

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_terokkar_shadowy_disguise','spell_terokkar_cancel_shadowy_disguise');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(32756,'spell_terokkar_shadowy_disguise'),
(32780,'spell_terokkar_cancel_shadowy_disguise');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = -32756;

UPDATE `quest_template_addon` SET `SourceSpellID` = 0 WHERE `ID` IN (10040,10041);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18714,18715) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18714,0,0,0,19,0,100,0,10041,0,0,0,0,11,48917,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Scout Neftis - On Quest 'Who Are They?' Taken - Cast 'Who Are They: Cast from Questgiver'"),
(18714,0,1,2,62,0,100,0,7772,0,0,0,0,11,48917,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Scout Neftis - On Gossip Option 0 Selected - Cast 'Who Are They: Cast from Questgiver'"),
(18714,0,2,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Scout Neftis - On Gossip Option 0 Selected - Close Gossip"),

(18715,0,0,0,19,0,100,0,10040,0,0,0,0,11,48917,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Private Weeks - On Quest 'Who Are They?' Taken - Cast 'Who Are They: Cast from Questgiver'"),
(18715,0,1,2,62,0,100,0,7771,0,0,0,0,11,48917,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Private Weeks - On Gossip Option 0 Selected - Cast 'Who Are They: Cast from Questgiver'"),
(18715,0,2,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Private Weeks - On Gossip Option 0 Selected - Close Gossip");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` IN (7771,7772);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,7771,0,0,0,47,0,10040,10,0,0,0,0,'',"Group 0: Show Gossip Option 0 if player has taken quest 'Who Are They?'"),
(15,7771,0,0,0,1,0,32756,0,0,1,0,0,"","Group 0: Show Gossip Option 0 if player does not have aura 'Shadowy Disguise'"),
(15,7772,0,0,0,47,0,10041,10,0,0,0,0,'',"Group 0: Show Gossip Option 0 if player has taken quest 'Who Are They?'"),
(15,7772,0,0,0,1,0,32756,0,0,1,0,0,"","Group 0: Show Gossip Option 0 if player does not have aura 'Shadowy Disguise'");
