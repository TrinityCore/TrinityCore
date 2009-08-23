UPDATE creature_template SET scriptname = "spell_pool_of_tar" WHERE entry = 33090;

UPDATE creature_template SET spell1=62288 WHERE entry = 33090;
UPDATE creature_template SET speed=1 WHERE entry=33113;
UPDATE creature_template SET speed=1.25 WHERE entry IN (33060,33109);
UPDATE creature_template SET speed=2 WHERE entry=33062;
UPDATE creature_template SET faction_A=1965,faction_H=1965 WHERE entry IN (33090,33113,33139);

UPDATE creature_template SET flags_extra = 0 WHERE entry IN (33114);

DELETE FROM `spell_script_target` WHERE `entry` IN (62427,62374,62399);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(62427, 1, 33109), # Load into Catapult
(62374, 1, 33060), # Pursued
(62374, 1, 33109),
(62399, 1, 33139); # Overload Circuit

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-62475,62427);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-62475,-62399, 0, 'System Shutdown'),
(-62475, 62472, 0, 'System Shutdown'), #inform, not correct spell
( 62427, 62340, 2, 'Load into Catapult - Passenger Loaded');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (33143);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `quest_start`, `quest_start_active`, `quest_end`, `cast_flags`) VALUES
(33143, 62399, 0, 0, 0, 0); # Overide device
