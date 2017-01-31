-- Dire Bear form should require Bear Form
DELETE FROM `spell_required` WHERE `spell_id`=9634;
INSERT INTO `spell_required` (`spell_id`,`req_spell`) VALUES (9634,5487);
