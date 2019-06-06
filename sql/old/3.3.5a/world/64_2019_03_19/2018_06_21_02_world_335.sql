-- Rift Spawn
DELETE FROM `smart_scripts` WHERE `entryorguid`=6492 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=649200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6492,0,0,1,25,0,100,0,0,0,0,0,0,11,34426,2,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Spawn - On Reset - Cast 'Greater Invisibility'"),
(6492,0,1,0,61,0,100,0,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Spawn - On Reset - Set Invincibility at 1 HP"),
(6492,0,2,3,8,0,100,0,9095,0,0,0,0,28,34426,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Spawn - On Spellhit 'Cantation of Manifestation' - Remove Aura 'Greater Invisibility'"),
(6492,0,3,4,61,0,100,0,0,0,0,0,0,11,9096,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Spawn - On Spellhit 'Cantation of Manifestation' - Cast 'Rift Spawn Manifestation'"),
(6492,0,4,5,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Rift Spawn - On Spellhit 'Cantation of Manifestation' - Start Attacking"),
(6492,0,5,0,61,0,100,0,0,0,0,0,0,28,9095,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Spawn - On Spellhit 'Cantation of Manifestation' - Remove Aura 'Cantation of Manifestation'"),
(6492,0,6,7,2,0,100,1,0,1,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Spawn - Between 0-1% Health - Set Faction 35"),
(6492,0,7,8,61,0,100,0,0,0,0,0,0,11,9032,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Spawn - Between 0-1% Health - Cast 'Self Stun - 30 seconds'"),
(6492,0,8,9,61,0,100,0,0,0,0,0,0,27,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Spawn - Between 0-1% Health - Stop Combat"),
(6492,0,9,10,61,0,100,0,0,0,0,0,0,80,649200,2,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Spawn - Between 0-1% Health - Run Script"),
(6492,0,10,0,61,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Spawn - Between 0-1% Health - Set Event Phase 1"),
(6492,0,11,12,38,1,100,0,1,1,0,0,0,12,23837,1,15000,0,0,0,1,0,0,0,0,0,0,0,"Rift Spawn - On Data 1 Set - Summon Creature 'ELM General Purpose Bunny'"),
(6492,0,12,0,61,1,100,0,0,0,0,0,0,45,32,32,0,0,0,0,19,23837,0,0,0,0,0,0,"Rift Spawn - On Data 1 Set - Set Data to ELM General Purpose Bunny"),
(6492,0,13,0,38,1,100,0,2,2,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Spawn - On Data 2 Set - Despawn"),
(6492,0,14,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Spawn - On Aggro - Say Line 0"),
(6492,0,15,0,7,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Spawn - On Evade - Say Line 1"),
(649200,9,0,0,0,0,100,0,30000,30000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Spawn - On Script - Say line 1"),
(649200,9,1,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Spawn - On Script - Despawn");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=6492;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=9082 AND `ConditionTypeOrReference`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,9082,0,0,1,0,9032,0,0,0,0,0,"","Create Containment Coffer can only be casted if target has aura 'Self Stun - 30 seconds'");
