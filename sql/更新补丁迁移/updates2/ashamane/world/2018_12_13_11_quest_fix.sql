UPDATE `npc_spellclick_spells` SET `cast_flags` = '1' WHERE `npc_entry` IN ('127648', '127673', '127677', '127680') AND `spell_id` = '253366'; 

-- Creating a new SmartAI script for [Creature] ENTRY 127648 (name: Cold Corpse)

-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN ('127648', '127673', '127677', '127680');

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid IN ('127648', '127673', '127677', '127680'));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(127648, 0, 0, 0, 8, 0, 100, 0, 253366, 0, 0, 0, 33, 127648, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Cold Corpse - On Spellhit \'253366\' - Quest Credit \'\''),
(127673, 0, 0, 0, 8, 0, 100, 0, 253366, 0, 0, 0, 33, 127673, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Hunter Corpse - On Spellhit \'253366\' - Quest Credit \'\''),
(127677, 0, 0, 0, 8, 0, 100, 0, 253366, 0, 0, 0, 33, 127677, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dead Quillrat - On Spellhit \'253366\' - Quest Credit \'\''),
(127680, 0, 0, 0, 8, 0, 100, 0, 253366, 0, 0, 0, 33, 127680, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Fresh Stag Corpse - On Spellhit \'253366\' - Quest Credit \'\'');