update creature_loot_template
set Chance=25
where Item In (18563, 18564, 17204);

update creature_loot_template
set Chance=(Chance+0.25)
where Item = 18335;

update creature_loot_template
set Chance=15
where Item In (18290, 18264, 18257, 18252, 18259, 18260, 21371);

update creature_loot_template
set Chance=10
where Item In (13519, 13520, 13521, 13522);

update creature_loot_template
set Chance=4
where Item In (16249, 16255);

update creature_loot_template
set Chance=2
where Item In (16254, 16254, 16253);

update creature_loot_template
set Chance=1
where Item In (20727, 20727, 20727, 20727);

INSERT INTO `creature_loot_template`
(`Entry`,
`Item`,
`Reference`,
`Chance`,
`QuestRequired`,
`LootMode`,
`GroupId`,
`MinCount`,
`MaxCount`,
`Comment`)
VALUES
(14834,
22637,
0,
100,
0,
1,
0,
1,
1,
null);

INSERT INTO `creature_loot_template`
(`Entry`,
`Item`,
`Reference`,
`Chance`,
`QuestRequired`,
`LootMode`,
`GroupId`,
`MinCount`,
`MaxCount`,
`Comment`)
VALUES
(15085,
22637,
0,
100,
0,
1,
0,
1,
1,
null);