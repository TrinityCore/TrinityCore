DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=28931;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(28931, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blightblood Troll - On Data Set 1 1 - Set Unit Flags'),
(28931, 0, 1, 6, 7, 0, 100, 0, 0, 0, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blightblood Troll - On Evade - Set Unit Flags'),
(28931, 0, 2, 0, 8, 0, 100, 0, 61492, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blightblood Troll - On Spellhit (Despawn Blightblood) - Despawn'),
(28931, 0, 3, 7, 54, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blightblood Troll - On Just Summoned - Set Phase 1'),
(28931, 0, 4, 0, 4, 0, 100, 1, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blightblood Troll - On Agro - Set Phase 2'),
(28931, 0, 5, 6, 8, 0, 100, 0, 53103, 0, 30000, 30000, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blightblood Troll - On Spellhit (Charm Blightblood Troll) - Set Phase 2'),
(28931, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blightblood Troll - On Spellhit (Charm Blightblood Troll) - Set Aggresie'),
(28931, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blightblood Troll - On Just Summoned - Set Passive'),
(28931, 0, 8, 0, 1, 2, 100, 1, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 19, 29100, 10, 0, 0, 0, 0, 0, 'Blightblood Troll - OOC (Phase 2) - Set Data 3 3 on Totally Generic Bunny (JSB)');
