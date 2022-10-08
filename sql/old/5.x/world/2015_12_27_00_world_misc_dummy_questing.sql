-- trolls
UPDATE `quest_template` SET `RequiredNpcOrGo1`='38038' WHERE id IN (26274,24640,24760,24772,24777,24778,24784,25139,31162);
DELETE FROM `creature_questrelation` WHERE (`id`='37989') AND (`quest`='24626');

-- Orcs
UPDATE `quest_template` SET `RequiredNpcOrGo1`='44820' WHERE id IN (25141,25143,25145,25147,25149,31157);

-- gnoms
UPDATE `quest_template` SET `RequiredNpcOrGo1`='44171' WHERE (`Id`='26198');
UPDATE `quest_template` SET `RequiredNpcOrGo1`='44171' WHERE (`Id`='26200');
UPDATE `quest_template` SET `RequiredNpcOrGo1`='44171' WHERE (`Id`='26201');
UPDATE `quest_template` SET `RequiredNpcOrGo1`='44171' WHERE (`Id`='26207');
UPDATE `creature_template` SET `unit_flags`='0', `unit_flags2`='0' WHERE (`entry`='42316');
DELETE FROM `creature_template_addon` WHERE (`entry`='42316');

-- worgens
UPDATE `quest_template` SET `RequiredNpcOrGo1`='44548' WHERE id IN (14266,14272,14274,14276,14279,14281,14283);
DELETE FROM `creature_questrelation` WHERE (`id`='35118') AND (`quest`='24930');
DELETE FROM `creature_questrelation` WHERE (`id`='35463') AND (`quest`='14204');
DELETE FROM `creature_queststarter` WHERE (`id`='37989');
DELETE FROM `creature_questrelation` WHERE (`id`='37989');
DELETE FROM `creature_queststarter` WHERE (`id`='35118') AND (`quest`='24930');
DELETE FROM `creature_queststarter` WHERE (`id`='35463') AND (`quest`='14204');

-- goblins
UPDATE `quest_template` SET `RequiredNpcOrGo1`='48304' WHERE id IN (14007,14008,14009,14011,14013,14012);

-- blood elf
UPDATE `quest_template` SET RequiredNpcOrGo1=44937  WHERE id IN (31171,27091,10069,10070,10071,10072);
DELETE FROM gameobject WHERE guid IN (173346,171071);

-- Humans
UPDATE `quest_template` SET RequiredNpcOrGo1=44548  WHERE id IN (31142,26913,26914,26915,26916,26917,26918,31138);

-- dwarfs
UPDATE `quest_template` SET RequiredNpcOrGo1=44389 WHERE id IN (24526,24527,24530,24531,24532,24533,26904,31151);

-- nightelfs
UPDATE `quest_template` SET RequiredNpcOrGo1=44614 WHERE id IN (31169,26945,26946,26948,26949);

-- draenei
UPDATE `quest_template` SET RequiredNpcOrGo1=44703 WHERE id IN (26958,26963,26968,26970,31173);

-- tauren
UPDATE `quest_template` SET RequiredNpcOrGo1=44848 WHERE id IN (27020,27021,27023,27066,27067,31166);
