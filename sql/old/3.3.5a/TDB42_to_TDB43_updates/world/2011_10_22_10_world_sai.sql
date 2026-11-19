-- Farahlon Lasher SAI
SET @ENTRY := 20774;
SET @SPELL_ENTANGLING_ROOTS := 12747;
SET @SPELL_FRENZY := 3019;
SET @SPELL_FLANKING_GROWTH := 36604;
SET @SPELL_ENERGY_FIELD_MODULATOR := 35772;
UPDATE `creature_template` SET `AIName`='SmartAI',`dmgschool`=3 WHERE `entry`=@ENTRY;
DELETE FROM `creature` WHERE `id` IN (21331,20983); -- Those are supposed to be summoned
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,@SPELL_FLANKING_GROWTH,0,0,0,0,0,2,0,0,0,0,0,0,0,"Farahlon Lasher - On Aggro - Cast Flanking Growth"),
(@ENTRY,0,1,0,0,0,100,0,20000,20000,25000,25000,11,@SPELL_ENTANGLING_ROOTS,0,0,0,0,0,2,0,0,0,0,0,0,0,"Farahlon Lasher - In Combat - Cast Entanglin Roots"),
(@ENTRY,0,2,0,8,0,100,0,@SPELL_ENERGY_FIELD_MODULATOR,0,0,0,36,20983,0,0,0,0,0,1,0,0,0,0,0,0,0,"Farahlon Lasher - On Spellhit - Change Entry To Mutated"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,@SPELL_FRENZY,1,0,0,0,0,1,0,0,0,0,0,0,0,"Farahlon Lasher - At 30% HP - Cast Frenzy"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Farahlon Lasher - At 30% HP - Say Line 0");
-- Text
DELETE FROM `creature_text` WHERE `entry` IN (@ENTRY,20983);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Farahlon Lasher"),
(20983,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Mutated Farahlon Lasher");

-- To prevent being able to use the quest item more than once per creature
-- Removing previous entry which didn't work
DELETE FROM `conditions` WHERE `SourceEntry`=35772 AND `ConditionValue2`=20774;
DELETE FROM `conditions` WHERE `SourceEntry`=29818 AND `ConditionValue2`=20774;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,0,29818,0,24,1,20774,0,0,'',"Item Energy Field Modulator can only be used if target is Farahlon Lasher");
