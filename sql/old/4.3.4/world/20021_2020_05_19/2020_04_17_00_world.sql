DELETE FROM `spell_proc` WHERE `SpellId` IN (96981, 97143, 96887, 97119, 92234);
INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Charges`, `Cooldown`) VALUES
(96981, 0, 1, 2, 0x2, 0, 0, 0, 0),
(97143, 0, 1, 2, 0x2, 0, 0, 0, 0),
(96887, 0, 1, 2, 0x2, 0, 0, 0, 2500),
(97119, 0, 1, 2, 0x2, 0, 0, 0, 2500),
(92234, 0, 0, 0, 0, 0, 0, 0, 30000);

DELETE FROM `spell_bonus_data` WHERE `entry`= 96891;
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(96891, 0, 0, 0, 0, 'Variable Pulse Lightning Capacitor - Lightning Bolt');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_item_variable_pulse_lightning_capacitor',
'spell_item_proc_dodge_below_35',
'spell_item_loom_of_fate');

INSERT INTO `spell_script_names` (`spell_Id`, `ScriptName`) VALUES
(96887, 'spell_item_variable_pulse_lightning_capacitor'),
(97119, 'spell_item_variable_pulse_lightning_capacitor'),
(96947, 'spell_item_loom_of_fate'),
(97130, 'spell_item_loom_of_fate'),
(92234, 'spell_item_proc_dodge_below_35');
