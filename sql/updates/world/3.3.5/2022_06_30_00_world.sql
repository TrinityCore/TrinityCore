--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_pet_gen_lich_pet_onsummon' WHERE `ScriptName` = 'spell_gen_lich_pet_onsummon';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_pet_gen_lich_pet_aura_remove' WHERE `ScriptName` = 'spell_gen_lich_pet_aura_remove';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_pet_gen_lich_pet_aura' WHERE `ScriptName` = 'spell_gen_lich_pet_aura';

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_pet_gen_lich_pet_periodic_emote',
'spell_pet_gen_lich_pet_emote',
'spell_pet_gen_lich_pet_focus');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(70050,'spell_pet_gen_lich_pet_periodic_emote'),
(70049,'spell_pet_gen_lich_pet_emote'),
(69682,'spell_pet_gen_lich_pet_focus');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 70049;
DELETE FROM `spell_scripts` WHERE `id` IN (69731,69682);

UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 36979;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 36979 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3697900,3697901) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(36979,0,0,0,11,0,100,0,0,0,0,0,0,11,69735,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lil' K.T. - On Spawn - Cast 'Lich Pet OnSummon'"),
(36979,0,1,0,86,0,100,0,0,0,0,0,0,11,69736,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lil' K.T. - On Despawn - Cast 'Lich Pet Aura Remove'"),
(36979,0,2,0,8,0,100,0,69731,0,0,0,0,80,3697900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lil' K.T. - On Spellhit 'Lich Pet Aura OnKill' - Run Script"),
(36979,0,3,0,83,0,100,0,69681,0,0,0,0,80,3697901,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lil' K.T. - On Spell Cast 'Lil' Frost Blast' - Run Script"),

-- Movement is definitely paused in both cases.
-- If we root creature, and if both emote event and critter event will be executed at once, root will be cleared on aura remove, in other
-- words before we clean it manually in script. That will screw up entire critter event. And doesn't really look like it should be rooted,
-- more like movement is stopped. But packets are different.

-- The only way they can temporarily stop movement here is replace one action list by another.
-- But that would mean they somehow overwrited default pet follow by scripted follow, would be weird.
-- Actually we have a bunch of guardians and their default follow movement is somehow completely ignored by creature: Khadgar's Servant,
-- Ancestral Spirit Wolf. Both actually are scripted on retail using only one action list which handles everything from spawn to despawn.
-- At the same time Fel Guard Hound follows owner after spawn by default but has again one action list which interrupts default follow
-- movement and resumes it after action list is finished. Kindal Moonweaver is a bit different because follow movement is launched from
-- very first action list and is paused by another she executes(https://youtu.be/GV64q-i420o?t=115).
-- So it looks like execution of any action list pauses follow movement no matter is it scripted or is default. Will such global mechanic
-- work always without any problems? No idea. Something to think of.

(3697900,9,0,0,0,0,100,0,0,0,0,0,0,29,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lil' K.T. - On Script - Stop Follow"),
(3697900,9,1,0,0,0,100,0,0,0,0,0,0,4,16493,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Lil' K.T. - On Script - Play Sound 16493"),
(3697900,9,2,0,0,0,100,0,0,0,0,0,0,17,451,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lil' K.T. - On Script - Set Emote State 451"),
(3697900,9,3,0,0,0,100,0,1000,1000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lil' K.T. - On Script - Set Emote State 0"),
(3697900,9,4,0,0,0,100,0,3000,3000,0,0,0,29,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Lil' K.T. - On Script - Start Follow Owner"),

(3697901,9,0,0,0,0,100,0,0,0,0,0,0,29,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lil' K.T. - On Script - Stop Follow"),
(3697901,9,1,0,0,0,100,0,2000,2000,0,0,0,4,16493,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Lil' K.T. - On Script - Play Sound 16493"),
(3697901,9,2,0,0,0,100,0,0,0,0,0,0,17,451,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lil' K.T. - On Script - Set Emote State 451"),
(3697901,9,3,0,0,0,100,0,1000,1000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lil' K.T. - On Script - Set Emote State 0"),
(3697901,9,4,0,0,0,100,0,3000,3000,0,0,0,29,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Lil' K.T. - On Script - Start Follow Owner");

-- Never was needed, never will work the way author expected
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` IN (71849,69683);
