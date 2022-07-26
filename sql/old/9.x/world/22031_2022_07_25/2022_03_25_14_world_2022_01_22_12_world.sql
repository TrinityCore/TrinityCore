-- Torp
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 45877;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,2,45877,0,0,31,0,3,25607,0,0,0,0,"","Group 0: Spell 'Deliver Kodo' (Effect 1) targets creature 'Farmer Torp'");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 25607 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2560700 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25607,0,0,0,8,0,100,0,45877,0,0,0,0,80,2560700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Farmer Torp - On Spellhit 'Deliver Kodo' - Run Script"),

(2560700,9,0,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Farmer Torp - On Script - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = 25607;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25607,0,0,"YES! It worked!",12,1,100,71,0,0,24883,0,"Farmer Torp"),
(25607,0,1,"Great job!",12,1,100,71,0,0,24884,0,"Farmer Torp");

-- Kodo, his script need more updates
UPDATE `smart_scripts` SET `link` = 0, `action_type` = 41, `action_param2` = 0, `target_type` = 1, `target_param1` = 0, `target_param2` = 0, `comment` = "Infected Kodo Beast - On Target Spell Hit 'Deliver Kodo' - Despawn" WHERE `entryorguid` = 25596 AND `source_type` = 0 AND `id` = 6;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25596 AND `source_type` = 0 AND `id` = 7;

DELETE FROM `spell_script_names` WHERE (
`spell_id` = 45877 AND `ScriptName` = 'spell_deliver_kodo' OR
`spell_id` = 48204 AND `ScriptName` = 'spell_kodo_delivered');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(45877,'spell_deliver_kodo'),
(48204,'spell_kodo_delivered');
