UPDATE `creature_template` SET `ScriptName`='npc_bountiful_table' WHERE `entry`=32823;
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry` IN (34812,34819,34822,34823,34824);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_pilgrims_bounty_on_plate_turkey',
'spell_pilgrims_bounty_on_plate_cranberries',
'spell_pilgrims_bounty_on_plate_stuffing',
'spell_pilgrims_bounty_on_plate_sweet_potatoes',
'spell_pilgrims_bounty_on_plate_pie',
'spell_pilgrims_bounty_a_serving_of_cranberries',
'spell_pilgrims_bounty_a_serving_of_pie',
'spell_pilgrims_bounty_a_serving_of_stuffing',
'spell_pilgrims_bounty_a_serving_of_turkey',
'spell_pilgrims_bounty_a_serving_of_potatoes');
INSERT INTO `spell_script_names` (`spell_id` ,`ScriptName`) VALUES
(66250,'spell_pilgrims_bounty_on_plate_turkey'),
(66261,'spell_pilgrims_bounty_on_plate_cranberries'),
(66259,'spell_pilgrims_bounty_on_plate_stuffing'),
(66262,'spell_pilgrims_bounty_on_plate_sweet_potatoes'),
(66260,'spell_pilgrims_bounty_on_plate_pie'),
(61804,'spell_pilgrims_bounty_a_serving_of_cranberries'),
(61805,'spell_pilgrims_bounty_a_serving_of_pie'),
(61806,'spell_pilgrims_bounty_a_serving_of_stuffing'),
(61807,'spell_pilgrims_bounty_a_serving_of_turkey'),
(61808,'spell_pilgrims_bounty_a_serving_of_potatoes'),
(61793,'spell_pilgrims_bounty_a_serving_of_cranberries'),
(61794,'spell_pilgrims_bounty_a_serving_of_pie'),
(61795,'spell_pilgrims_bounty_a_serving_of_stuffing'),
(61796,'spell_pilgrims_bounty_a_serving_of_turkey'),
(61797,'spell_pilgrims_bounty_a_serving_of_potatoes');
