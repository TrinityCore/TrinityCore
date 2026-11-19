DELETE FROM `spell_script_names` WHERE `spell_id`=45759;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(45759,'spell_gen_orc_disguise');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=45742;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,45742,0,0,1,0,45760,0,0,0,0,'','Spell Plant Warsong Banner can be casted only if player has aura Warsong Orc Disguise (Male)'),
(17,0,45742,0,0,31,1,3,25430,0,0,0,'','Spell Plant Warsong Banner can be casted only on Magmothregar'),
(17,0,45742,0,0,36,1,0,0,0,1,0,'','Spell Plant Warsong Banner can be casted only if target is dead'),
(17,0,45742,0,1,1,0,45762,0,0,0,0,'','Spell Plant Warsong Banner can be casted only if player has aura Warsong Orc Disguise (Female)'),
(17,0,45742,0,1,31,1,3,25430,0,0,0,'','Spell Plant Warsong Banner can be casted only on Magmothregar'),
(17,0,45742,0,1,36,1,0,0,0,1,0,'','Spell Plant Warsong Banner can be casted only if target is dead');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=25430;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=25430;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25430 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25430,0,0,0,4,0,100,0,0,0,0,0,11,50413,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Magmothregar - On aggro - Spellcast Magnataur Charge'),
(25430,0,1,0,0,0,100,0,3500,12800,10100,14000,11,50822,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Magmothregar - On update IC - Spellcast Fervor'),
(25430,0,2,0,8,0,100,0,45742,0,0,0,11,45744,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Magmothregar - On spellhit Plant Warsong Banner - Spellcast It Was The Orcs, Honest!: Plant Banner Kill Credit');
