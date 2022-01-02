-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-84658, -84697, -84667, -84666, -84665, -84664, -84662, -84661, -84660, -84659, 35475);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3547500,3547501,3547502,3547503,3547504) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(35475, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 88, 3547500, 3547504, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Visiting Warlock - On reset - Random Action list'),
(3547500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 23503, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Visiting Warlock - Action list - cast Serverside - Summon Imp'),
(3547501, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 23500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Visiting Warlock - Action list - cast Serverside - Summon Felhunter'),
(3547502, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 23502, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Visiting Warlock - Action list - cast Serverside - Summon Succubus'),
(3547503, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 23501, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Visiting Warlock - Action list - cast Serverside - Summon Voidwalker'),
(3547504, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 32782, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Visiting Warlock - Action list - cast Serverside - Summon Felguard');
