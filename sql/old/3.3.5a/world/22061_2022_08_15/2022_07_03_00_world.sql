--
UPDATE `creature_template` SET `unit_flags` = 33554688 WHERE `entry` = 28780;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 28778;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28780,28778) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2878000,2877800) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28780,0,0,0,11,0,100,0,0,0,0,0,0,80,2878000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Explosive Charges Bunny - On Spawn - Run Script"),

(2878000,9,0,0,0,0,100,0,0,0,0,0,0,11,52346,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Explosive Charges Bunny - On Script - Cast 'Kill Credit'"),
(2878000,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Explosive Charges Bunny - On Script - Say Line 0"),
(2878000,9,2,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Explosive Charges Bunny - On Script - Say Line 1"),
(2878000,9,3,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Explosive Charges Bunny - On Script - Say Line 2"),
(2878000,9,4,0,0,0,100,0,1000,1000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Explosive Charges Bunny - On Script - Say Line 3"),
(2878000,9,5,0,0,0,100,0,1000,1000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Explosive Charges Bunny - On Script - Say Line 4"),
(2878000,9,6,0,0,0,100,0,1000,1000,0,0,0,11,52322,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Explosive Charges Bunny - On Script - Cast 'Detonate Charges'"),
(2878000,9,7,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Explosive Charges Bunny - On Script - Despawn"),

(28778,0,0,0,8,0,100,0,52322,0,0,0,0,80,2877800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourgewagon Bunny - On Spellhit 'Detonate Charges' - Run Script"),

(2877800,9,0,0,0,0,100,0,0,0,0,0,0,11,52324,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourgewagon Bunny - On Script - Cast 'Scourgewagon Explosion'"),
(2877800,9,1,0,0,0,100,0,0,0,0,0,0,11,52335,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourgewagon Bunny - On Script - Cast 'Drop Scourge Disguise'"),
(2877800,9,2,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,20,190732,15,0,0,0,0,0,0,"Scourgewagon Bunny - On Script - Despawn Closest Gameobject 'Explosive Charges'"),
(2877800,9,3,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,20,190731,15,0,0,0,0,0,0,"Scourgewagon Bunny - On Script - Despawn Closest Gameobject 'Scourgewagon'"),
(2877800,9,4,0,0,0,100,0,5000,5000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourgewagon Bunny - On Script - Despawn");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (52322);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,52322,0,0,31,0,3,28778,0,0,0,0,"","Group 0: Spell 'Detonate Charges' (Effect 0) targets creature 'Scourgewagon Bunny'");

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 52322;

DELETE FROM `spell_script_names` WHERE `spell_id` = 52335 AND `ScriptName` = 'spell_zuldrak_drop_disguise';
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_zuldrak_scourgewagon_explosion';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(52335,'spell_zuldrak_drop_disguise'),
(52324,'spell_zuldrak_scourgewagon_explosion');
