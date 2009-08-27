INSERT INTO creature_template (entry, vehicleid) VALUES
(32930, 312), # Kologarn
(33214, 348) # Mechanolift 304-A
ON DUPLICATE KEY UPDATE
vehicleid = VALUES(vehicleid);

UPDATE creature_template SET InhabitType = 4 WHERE entry = 33214;

update creature_template set spell1=62395, AIName = 'TurretAI', scriptname='' where entry = 33139;
update creature_template set spell1=62402 where entry = 33142;
update creature_template set ScriptName = 'boss_kologarn' where entry = 32930;

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-62475,62427);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-62475,-62399, 0, 'System Shutdown - Overload Circuit'),
(-62475,-62375, 0, 'System Shutdown - Gathering Speed'),
(-62475, 62472, 0, 'System Shutdown'), #inform, not correct spell
( 62427, 62340, 2, 'Load into Catapult - Passenger Loaded');
