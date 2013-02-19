-- Crystal Spikes - Script Effect - Spell casted by Ormorok - Triggers one summon spell in every direction
DELETE FROM `spell_scripts` WHERE `id` IN (47958,57082);
INSERT INTO `spell_scripts`(`id`,`command`,`datalong`,`datalong2`) VALUES
-- Non heroic
(47958,15,47954,1),
(47958,15,47955,1),
(47958,15,47956,1),
(47958,15,47957,1),
-- Heroic
(57082,15,57077,1),
(57082,15,57078,1),
(57082,15,57080,1),
(57082,15,57081,1);

DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (47958,48016,48017) OR `spellid0` IN (47958,48016,48017);
INSERT INTO `spelldifficulty_dbc`(`id`,`spellid0`,`spellid1`) VALUES
(47958,47958,57082), -- Crystal Spikes
(48016,48016,57066), -- Trample
(48017,48017,57086); -- Frenzy

-- Assign aura script for spawning Crystal Spike rows
DELETE FROM `spell_script_names` WHERE `spell_id`=47941;
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES
(47941,'spell_crystal_spike');

-- Apply aura to triggers
DELETE FROM `creature_template_addon` WHERE `entry` IN (27101,27079);
INSERT INTO `creature_template_addon`(`entry`,`auras`) VALUES
(27101,'47941'), -- Aura to summon the next trigger after 250ms
(27079,'47941'); -- Aura to summon the next trigger after 250ms and visual effect

-- Assign core scripts and SmartAI to trigger
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_crystal_spike_trigger' WHERE `entry` IN (27101,27079);
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=27099;

-- SAI for Crystal Spike (Damage dealer)
DELETE FROM `smart_scripts` WHERE `entryorguid`=27099 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`event_type`,`action_type`,`action_param1`,`action_param2`,`target_type`,`comment`) VALUES
(27099,54,80,2709900,2,1,'Crystal Spike - Is summoned - Call timed action list');

-- Timed action list
DELETE FROM `smart_scripts` WHERE `entryorguid`=2709900 AND `source_type`=9;
INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`id`,`event_param1`,`event_param2`,`action_type`,`action_param1`,`action_param2`,`target_type`,`comment`) VALUES
(2709900,9,1,2100,2100,11,47944,2,1,'Crystal Spike - Timed action list - Cast damage spell'),
(2709900,9,2,0,0,41,0,0,1,'Crystal Spike - Timed action list - Despawn');

-- Creature texts for the boss
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1576024 AND -1576020;

DELETE FROM `creature_text` WHERE `entry`=26794;
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`sound`,`comment`) VALUES
(26794,1,'Noo!',14,13328,'ormorok SAY_AGGRO'),
(26794,2,'Aaggh!',14,13330,'ormorok SAY_DEATH'),
(26794,3,'Back!',14,13331,'ormorok SAY_REFLECT'),
(26794,4,'Bleed!',14,13332,'ormorok SAY_CRYSTAL_SPIKES'),
(26794,5,'Aaggh! Kill!',14,13329,'ormorok SAY_KILL');
