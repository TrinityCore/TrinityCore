-- Quest: Gluttonous Lurkers (12527)
-- Zul'drak Rat: Spellclick spells
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=28202;
INSERT INTO `npc_spellclick_spells`(`npc_entry`,`spell_id`,`cast_flags`) VALUE
(28202,50926,1),
(28202,50927,2);

-- Zul'drak Rat: SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=28202;
DELETE FROM `smart_scripts` WHERE `entryorguid`=28202 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`event_type`,`event_param1`,`action_type`,`target_type`,`comment`) VALUES
(28202,8,50926,41,1,'Zuldrak Rat - On spell hit of Gluttonous Lurkers: Create ZulDrak Rat Cover - Despawn');

-- Zul'drak Rat spell: Script assignment
DELETE FROM `spell_script_names` WHERE `spell_id`=50894;
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUE
(50894,'spell_zuldrak_rat');

-- Zul'drak Rat spell: Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=50894;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ErrorType`,`Comment`) VALUE
(17,50894,31,1,3,28145,12,'Zuldrak Rat - Target has to be Lurking Basilisk');

-- Lurking Basilisk: SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=28145;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=28145; 4.x removed
DELETE FROM `smart_scripts` WHERE `entryorguid`=28145 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`event_type`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`target_type`,`comment`) VALUE
(28145,0,5000,5000,17000,27000,11,54470,2,'Lurking Basilisk - In Combat - Cast Venemous Bite');

-- Gorged Lurking Basilisk: SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=28203;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=28203; 4.x removed
DELETE FROM `smart_scripts` WHERE `entryorguid`=28203 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`event_type`,`event_param1`,`action_type`,`target_type`,`comment`) VALUES
(28203,8,50918,41,1,'Gorged Lurking Basilisk - On Spell Hit of Create Basilisk Crystals Cover - Despawn');
