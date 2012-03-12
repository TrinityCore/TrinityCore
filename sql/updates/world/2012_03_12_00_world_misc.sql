SET @LEY_LINE_BEAM := 47334; -- Ley Line Beam (No kit)
SET @BUNNY_BEAM := 47635; -- The End of the Line: Ley Line Focus Bunny Beam
SET @TALISMAN_EFFECT := 50548; -- The End of the Line: Ley Line Focus Control Talisman Effect

-- ELM General Purpose Bunny (Scale x0.01) SAI
-- This is pure shit, those NPCs target some other NPCs with the same DB id, based on their GUIDs.
DELETE FROM `smart_scripts` WHERE `entryorguid`=-116051 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-116053 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-116054 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-116055 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-116056 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-116057 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-116058 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-116059 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-116060 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-116061 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-116065 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-116051,0,0,0,1,0,100,0,1000,1000,1000,2500,11,@LEY_LINE_BEAM,0,0,0,0,0,10,115958,24021,0,0,0,0,0, 'ELM General Purpose Bunny (Scale x0.01) - On update OOC - Cast Ley Line Beam (No kit) on ELM General Purpose Bunny (Scale x0.01)'),
(-116053,0,0,0,1,0,100,0,1000,1000,1000,2500,11,@LEY_LINE_BEAM,0,0,0,0,0,10,115976,24021,0,0,0,0,0, 'ELM General Purpose Bunny (Scale x0.01) - On update OOC - Cast Ley Line Beam (No kit) on ELM General Purpose Bunny (Scale x0.01)'),
(-116054,0,0,0,1,0,100,0,1000,1000,1000,2500,11,@LEY_LINE_BEAM,0,0,0,0,0,10,115973,24021,0,0,0,0,0, 'ELM General Purpose Bunny (Scale x0.01) - On update OOC - Cast Ley Line Beam (No kit) on ELM General Purpose Bunny (Scale x0.01)'),
(-116055,0,0,0,1,0,100,0,1000,1000,1000,3500,11,@LEY_LINE_BEAM,0,0,0,0,0,10,115976,24021,0,0,0,0,0, 'ELM General Purpose Bunny (Scale x0.01) - On update OOC - Cast Ley Line Beam (No kit) on ELM General Purpose Bunny (Scale x0.01)'),
(-116056,0,0,0,1,0,100,0,1000,1000,1000,3500,11,@LEY_LINE_BEAM,0,0,0,0,0,10,115958,24021,0,0,0,0,0, 'ELM General Purpose Bunny (Scale x0.01) - On update OOC - Cast Ley Line Beam (No kit) on ELM General Purpose Bunny (Scale x0.01)'),
(-116057,0,0,0,1,0,100,0,1000,1000,1000,3500,11,@LEY_LINE_BEAM,0,0,0,0,0,10,115975,24021,0,0,0,0,0, 'ELM General Purpose Bunny (Scale x0.01) - On update OOC - Cast Ley Line Beam (No kit) on ELM General Purpose Bunny (Scale x0.01)'),
(-116058,0,0,0,1,0,100,0,1000,1000,1000,4500,11,@LEY_LINE_BEAM,0,0,0,0,0,10,115959,24021,0,0,0,0,0, 'ELM General Purpose Bunny (Scale x0.01) - On update OOC - Cast Ley Line Beam (No kit) on ELM General Purpose Bunny (Scale x0.01)'),
(-116059,0,0,0,1,0,100,0,1000,1000,1000,2500,11,@LEY_LINE_BEAM,0,0,0,0,0,10,115976,24021,0,0,0,0,0, 'ELM General Purpose Bunny (Scale x0.01) - On update OOC - Cast Ley Line Beam (No kit) on ELM General Purpose Bunny (Scale x0.01)'),
(-116060,0,0,0,1,0,100,0,1000,1000,1000,3000,11,@LEY_LINE_BEAM,0,0,0,0,0,10,115973,24021,0,0,0,0,0, 'ELM General Purpose Bunny (Scale x0.01) - On update OOC - Cast Ley Line Beam (No kit) on ELM General Purpose Bunny (Scale x0.01)'),
(-116061,0,0,0,1,0,100,0,1000,1000,1000,2500,11,@LEY_LINE_BEAM,0,0,0,0,0,10,115976,24021,0,0,0,0,0, 'ELM General Purpose Bunny (Scale x0.01) - On update OOC - Cast Ley Line Beam (No kit) on ELM General Purpose Bunny (Scale x0.01)'),
(-116065,0,0,0,1,0,100,0,1000,1000,1000,2500,11,@LEY_LINE_BEAM,0,0,0,0,0,10,115959,24021,0,0,0,0,0, 'ELM General Purpose Bunny (Scale x0.01) - On update OOC - Cast Ley Line Beam (No kit) on ELM General Purpose Bunny (Scale x0.01)');

-- ELM General Purpose Bunny SAI
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=24021;
SET @ENTRY := -98564;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0x1,@TALISMAN_EFFECT,0,0,0,11,@BUNNY_BEAM,0,0,0,0,0,7,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On The End of the Line: Ley Line Focus Control Talisman Effect hit - Cast The End of the Line: Ley Line Focus Bunny Beam on action invoker');

-- ELM General Purpose Bunny SAI
SET @ENTRY := -98617;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0x1,@TALISMAN_EFFECT,0,0,0,11,@BUNNY_BEAM,0,0,0,0,0,7,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On The End of the Line: Ley Line Focus Control Talisman Effect hit - Cast The End of the Line: Ley Line Focus Bunny Beam on action invoker');

-- Wrong conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=47634;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@TALISMAN_EFFECT;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0x1,47634,0,0,31,3,23837,0,0, '', 'Ley Line Focus Control Talisman only targets ELM General Purpose Bunny'),
(13,0x1,@TALISMAN_EFFECT,0,0,31,1,23837,0,0, '', 'The End of the Line: Ley Line Focus Control Talisman Effect only targets ELM General Purpose Bunny');

-- Areatrigger script
DELETE FROM `areatrigger_scripts` WHERE `entry`=4956;
INSERT INTO `areatrigger_scripts` VALUES (4956, 'at_azure_dragons_sanctuary');
