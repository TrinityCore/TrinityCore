--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 54581;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_storm_peaks_mammoth_explosion_master','spell_storm_peaks_unstable_explosive_detonation');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(54581,'spell_storm_peaks_mammoth_explosion_master'),
(54892,'spell_storm_peaks_unstable_explosive_detonation');

UPDATE `smart_scripts` SET `action_param1` = 2000, `comment` = "Ironwool Mammoth - On Spellhit 'Throw U.D.E.D.' - Delayed Despawn" WHERE `entryorguid` = 29402 AND `source_type` = 0 AND `id` = 2;

UPDATE `smart_scripts` SET `action_type` = 11, `comment` = "U.D.E.D. Dispenser - On Gossip Option 0 Selected - Cast 'Forceitem U.D.E.D.'" WHERE `entryorguid` = 191553 AND `source_type` = 1 AND `id` = 1;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 29524 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29524,0,0,1,11,0,100,0,0,0,0,0,0,11,54625,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mammoth Meat Bunny - On Spawn - Cast 'Summon Mammoth Meat'"),
(29524,0,1,0,61,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mammoth Meat Bunny - On Spawn - Despawn");

DELETE FROM `gameobject` WHERE `id` = 191567;
DELETE FROM `spawn_group` WHERE `spawnId` IN (57902,57903,57904,57905,57906,57907) AND `spawnType` = 1;
