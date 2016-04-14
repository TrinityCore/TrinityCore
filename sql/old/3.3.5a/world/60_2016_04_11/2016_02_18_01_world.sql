UPDATE `creature_template` SET `spell2`=61784,`spell3`=61785,`spell4`=61788,`spell5`=61786,`spell6`=61787 WHERE `entry` IN (34812,34819,34822,34823,34824);
-- The Turkey Chair
UPDATE `creature_template` SET `spell1`=66250 WHERE `entry`=34812;
UPDATE `creature_template_addon` SET `auras`='61796 61801' WHERE `entry`=34812;
-- The Stuffing Chair
UPDATE `creature_template` SET `spell1`=66259 WHERE `entry`=34819;
UPDATE `creature_template_addon` SET `auras`='61795 61800' WHERE `entry`=34819;
-- The Pie Chair
UPDATE `creature_template` SET `spell1`=66260 WHERE `entry`=34822;
UPDATE `creature_template_addon` SET `auras`='61794 61799' WHERE `entry`=34822;
-- The Cranberry Chair
UPDATE `creature_template` SET `spell1`=66261 WHERE `entry`=34823;
UPDATE `creature_template_addon` SET `auras`='61793 61798' WHERE `entry`=34823;
-- The Potato Chair
UPDATE `creature_template` SET `spell1`=66262 WHERE `entry`=34824;
UPDATE `creature_template_addon` SET `auras`='61797 61802' WHERE `entry`=34824;

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pilgrims_bounty_feast_on';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(61784, 'spell_pilgrims_bounty_feast_on'), -- Feast On Turkey
(61785, 'spell_pilgrims_bounty_feast_on'), -- Feast On Cranberries
(61786, 'spell_pilgrims_bounty_feast_on'), -- Feast On Sweet Potatoes
(61787, 'spell_pilgrims_bounty_feast_on'), -- Feast On Pie
(61788, 'spell_pilgrims_bounty_feast_on'); -- Feast On Stuffing

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_pilgrims_bounty_well_fed_cranberry',
'spell_pilgrims_bounty_well_fed_turkey',
'spell_pilgrims_bounty_well_fed_stuffing',
'spell_pilgrims_bounty_well_fed_sweet_potatoes',
'spell_pilgrims_bounty_well_fed_pie');
INSERT INTO `spell_script_names` (`spell_id` ,`ScriptName`) VALUES
(61841, 'spell_pilgrims_bounty_well_fed_cranberry'),
(61842, 'spell_pilgrims_bounty_well_fed_turkey'),
(61843, 'spell_pilgrims_bounty_well_fed_stuffing'),
(61844, 'spell_pilgrims_bounty_well_fed_sweet_potatoes'),
(61845, 'spell_pilgrims_bounty_well_fed_pie');

-- Pilgrim's Paunch criterias
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (11078,11079,11080,11081,11082,11083,11084,11085);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`) VALUES
(11078,6,1657,0),
(11079,6,809,0),
(11080,6,3557,0),
(11081,6,12,0),
(11082,6,14,0),
(11083,6,3470,0),
(11084,6,1638,0),
(11085,6,1497,0);
