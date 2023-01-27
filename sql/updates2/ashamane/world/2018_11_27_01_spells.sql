-- New scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_monk_teachings_of_the_monastery_passive',
'spell_monk_teachings_of_the_monastery_buff',
'spell_monk_spirit_of_the_crane_passive', 
'spell_monk_vivify',
'spell_monk_way_of_the_crane',
'spell_monk_touch_of_death_amplifier',
'spell_monk_touch_of_death_passive',
'spell_monk_touch_of_karma',
'spell_monk_touch_of_karma_buff',

'spell_mage_clearcasting',
'spell_mage_presence_of_mind',
'spell_mage_arcane_blast');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(116645, 'spell_monk_teachings_of_the_monastery_passive'),
(202090, 'spell_monk_teachings_of_the_monastery_buff'),
(210802, 'spell_monk_spirit_of_the_crane_passive'),
(116670, 'spell_monk_vivify'),
(216113, 'spell_monk_way_of_the_crane'),
(271233, 'spell_monk_touch_of_death_amplifier'),
(271232, 'spell_monk_touch_of_death_passive'),
(125174, 'spell_monk_touch_of_karma_buff'),
(122470, 'spell_monk_touch_of_karma'),

(79684, 'spell_mage_clearcasting'),
(205025, 'spell_mage_presence_of_mind'),
(30451, 'spell_mage_arcane_blast');

-- Not needed anymore, deprecated
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_monk_chi_torpedo', 
'spell_mage_arcane_missiles_proc', 
'spell_mage_arcane_missiles_charges');

-- Old Zen Pilgreimage coords, handled in spell script
DELETE FROM `spell_target_position` WHERE  `ID`=126892;

-- Old Arcane missiles
DELETE FROM `spell_linked_spell` WHERE  `spell_trigger`=-5143;
