-- Sets SmartAI for Mechagnomes
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=25814;

-- Says for Mechagnomes
DELETE FROM `creature_text` WHERE `entry`=25814;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(25814,1,1, 'We are Mechagnome...resistance is futile.',12,0,0,0,0,0, ''),
(25814,1,2, 'The flesh is weak. We will make you better, stronger...faster.',12,0,0,0,0,0, ''),
(25814,1,3, 'We can decurse you, we have the technology.',12,0,0,0,0,0, '');

-- Mechagnome SAI
-- NOTE: Mechagnome SAI required for Horde quest Souls of the Decursed
DELETE FROM `smart_scripts` WHERE `entryorguid`=25814 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25814,0,0,0,4,0,100,0,0,0,0,0,1,1,10000,0,0,0,0,0,0,0,0,0,0,0,0, 'Fizzcrank Mechagnome - Chance Say on Aggro'),
(25814,0,1,0,8,0,100,0,45980,0,0,0,33,25773,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Fizzcrank Mechagnome - Killcredit on spellhit - Recursive'),
(25814,0,2,0,8,0,100,0,46485,0,0,0,33,26096,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Fizzcrank Mechagnome - Killcredit on spellhit - Souls of the Decursed');
-- (25814,0,2,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fizzcrank Mechagnome - On Re-Cursive Transmatter Injection spellhit despawn self'),

-- Links item spell to spawn spell
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=45980;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (45980,46022,0, 'Re-Cursive quest');

-- Despawn Mechagnome after spellcast (Mechagnome would not despawn using SAI resulting in possibility of multiple uses of item for credit)
DELETE FROM `spell_scripts` WHERE `id`=45980;
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(45980,0,1,18,0,0,0,0,0,0,0);

-- FOR SURVIVOR

-- Sets smartAI for Fizzcrank Survivor
UPDATE `creature_template` SET `AIName` ='SmartAI' WHERE `entry`=25773;

-- Says for Fizzcrank Survivor
DELETE FROM `creature_text` WHERE `entry`=25773;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(25773,0,1, 'I survived and I''m flesh again!',12,0,0,0,0,0, ''),
(25773,0,2, 'But... but... I was perfect!',12,0,0,0,0,0, ''),
(25773,0,3, 'Where am I? Who are you? What''s that strange feeling?',12,0,0,0,0,0, ''),
(25773,0,4, 'I''m flesh and blood again! Thank you!',12,0,0,0,0,0, '');

-- Random says, Teleport spell effect & despawn
DELETE FROM `smart_scripts` WHERE `entryorguid`=25773 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25773,0,0,0,1,0,100,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Fizzcrank Survivor - On spawn talk'),
(25773,0,1,0,1,0,100,1,5000,5000,5000,5000,11,41232,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Survivor - OOC Cast spell'),
(25773,0,2,0,1,0,100,0,5000,5000,5000,5000,41,2000,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Fizzcrank Survivor - OOC Force despawn');

-- Remove Eventai and Eventai says
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (25814,25773);
DELETE FROM `creature_ai_texts` WHERE `entry` IN (-533,-534,-535);
