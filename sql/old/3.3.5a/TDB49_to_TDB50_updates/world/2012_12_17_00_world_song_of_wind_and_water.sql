-- Add DB suport for quest ID: 12726 "Song of Wind and Water"
-- Indexes:
SET @HAIPHOON_W := 28999; -- WATER
SET @HAIPHOON_A := 28985; -- AIR
SET @STORM := 28858; -- Storm Revenant
SET @AQUEOUS := 28862; -- Aqueous Spirit
-- WATER VERSION SPELLS
SET @SPELL_W_1 := 61375; -- Water Bolt
SET @SPELL_W_2 := 61376; -- Frost Nova
SET @SPELL_W_3 := 52862; -- Devour Wind
-- Both version spell
SET @SPELL_AW := 52869; -- Evocation
-- AIR VERSION SPELLS
SET @SPELL_A_1 :=61374; -- Lightning Bolt
SET @SPELL_A_2 :=52870; -- Windshear
SET @SPELL_A_3 :=52864; -- Devour Water

-- Update both quest vehicles templates
-- Water version
UPDATE `creature_template` SET `spell1`=@SPELL_W_1,`spell2`=@SPELL_W_2,`spell3`=@SPELL_W_3,`spell6`=@SPELL_AW,`unit_flags`=`unit_flags`|16777216,`VehicleId`=257,`AIName`='',`exp`=2,`minlevel`=80,`maxlevel`=80,`ScriptName`='npc_haiphoon' WHERE `entry`=@HAIPHOON_W;
-- Wind version
UPDATE `creature_template` SET `spell1`=@SPELL_A_1,`spell2`=@SPELL_A_2,`spell3`=@SPELL_A_3,`spell6`=@SPELL_AW,`unit_flags`=`unit_flags`|16777216,`VehicleId`=257,`unit_class`=2,`exp`=2,`minlevel`=80,`maxlevel`=80,`ScriptName`='npc_haiphoon' WHERE `entry`=@HAIPHOON_A;

-- Insert conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (@SPELL_W_3,@SPELL_A_3);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17,0,@SPELL_W_3,0,0,31,1,3,@STORM,0,0,0,'', 'Spell Devour Wind can only target Storm Revenant'),
(17,0,@SPELL_A_3,0,0,31,1,3,@AQUEOUS,0,0,0,'', 'Spell Devour Water can only target Aqueous Spirit');

-- Add SAI and DB support for Storm Revenant and Aqueous Spirit
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@STORM,@AQUEOUS);
UPDATE `creature_template` SET `resistance3`=545 WHERE `entry`=@STORM; -- should've resistance according to video (tried to be precise as possible)
UPDATE `creature_template` SET `resistance4`=545 WHERE `entry`=@AQUEOUS; -- should've resistance according to video -//-
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (@STORM,@AQUEOUS);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@STORM,@AQUEOUS);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@STORM,0,0,0,0,0,100,0,2000,4000,5000,7000,11,32018,0,0,0,0,0,2,0,0,0,0,0,0,0,'Storm Revenant - IC - Cast Call Lightning'),
(@AQUEOUS,0,0,0,0,0,100,0,6000,9000,7000,10000,11,55087,0,0,0,0,0,2,0,0,0,0,0,0,0,'Aqueous Spirit - IC - Cast Typhoon');
