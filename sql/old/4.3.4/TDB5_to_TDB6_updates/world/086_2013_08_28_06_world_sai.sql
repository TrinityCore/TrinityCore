-- Fuel for the Fire (12690)
-- http://www.youtube.com/watch?v=3rC1yU1ytl8
SET @CREDIT             :=52590; -- Credit to Master
SET @CREDIT_MASTER      :=52587; -- Assign Kill Credit to Master
SET @TEXPLOSION         :=52565; -- Troll Explosion
SET @FFTF_EXPL          :=52575; -- Fuel for the Fire:Troll Explosion
SET @MEAT_EXPL          :=52578; -- Explode Troll:Meat
SET @BMEAT_EXPL         :=52580; -- Explode Troll:Bloody Meat
SET @SUICIDE_NL         :=51744; -- Suicide (No Log)
SET @DSC                :=28844; -- Drakkari Skullcrusher
SET @B_ABOM             :=28843; -- Bloated Abomination

DELETE FROM `spell_script_names` WHERE `spell_id`=52510;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(52510, 'spell_q12690_burst_at_the_seams');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@B_ABOM;
DELETE FROM `smart_scripts` WHERE entryorguid =@B_ABOM;

DELETE FROM `conditions` WHERE `SourceEntry`IN (52510);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 2, 52510, 0, 0, 31, 0, 3, 28844, 0, 0, 0, 0, '', 'Spell Burst at the Seams targets Drakkari Skullcrusher');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@DSC;
DELETE FROM `smart_scripts` WHERE `source_type`IN (0,9) AND `entryorguid`IN (@DSC,@DSC*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@DSC,0,0,0,8,0,100,0,52510,0,0,0,80,@DSC*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Drakkari Skullcrusher - On Spellhit - Start Timed Action Script'),
(@DSC*100,9,0,0,0,0,100,0,0,0,0,0,11,@TEXPLOSION,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakkari Skullcrusher - On Script - Cast Troll Explosion'),
(@DSC*100,9,1,0,0,0,100,0,0,0,0,0,11,@MEAT_EXPL,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakkari Skullcrusher - On Script - Cast Meat Explosion'),
(@DSC*100,9,2,0,0,0,100,0,0,0,0,0,11,@SUICIDE_NL,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakkari Skullcrusher - On Script - Cast Suicide');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`IN (@TEXPLOSION,@MEAT_EXPL);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(@TEXPLOSION,@FFTF_EXPL,1,'Trigger Troll Explosion with FFTF explosion'),
(@MEAT_EXPL,@BMEAT_EXPL,1,'Trigger Meat Explosion with Bloody Meat Explosion');
