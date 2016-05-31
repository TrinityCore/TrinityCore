DELETE FROM `spell_script_names` WHERE `spell_id` IN (70877,71474) AND `ScriptName`='spell_blood_queen_frenzied_bloodthirst';
DELETE FROM `spell_script_names` WHERE `spell_id` IN (70946,71475,71476,71477) AND `ScriptName`='spell_blood_queen_vampiric_bite';
DELETE FROM `spell_script_names` WHERE `spell_id` IN (71899,71900,71901,71902) AND `ScriptName`='spell_blood_queen_bloodbolt';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(70877, 'spell_blood_queen_frenzied_bloodthirst'),
(71474, 'spell_blood_queen_frenzied_bloodthirst'),
(70946, 'spell_blood_queen_vampiric_bite'),
(71475, 'spell_blood_queen_vampiric_bite'),
(71476, 'spell_blood_queen_vampiric_bite'),
(71477, 'spell_blood_queen_vampiric_bite'),
(71899, 'spell_blood_queen_bloodbolt'),
(71900, 'spell_blood_queen_bloodbolt'),
(71901, 'spell_blood_queen_bloodbolt'),
(71902, 'spell_blood_queen_bloodbolt');
