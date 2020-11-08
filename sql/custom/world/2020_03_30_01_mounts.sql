update creature_loot_template clt
inner join item_template it on it.entry = clt.item
set clt.Chance = 5
where it.name='Deathcharger''s Reins';

update creature_loot_template clt
inner join item_template it on it.entry = clt.item
set clt.Chance = 30
where it.name='Swift Zulian Tiger';


UPDATE item_template SET RequiredSkillRank="150" WHERE entry=21321;
UPDATE item_template SET description="Teaches you how to summon this mount." WHERE entry=21321;
UPDATE item_template SET RequiredSkillRank="150" WHERE entry=21323;
UPDATE item_template SET description="Teaches you how to summon this mount." WHERE entry=21323;
UPDATE item_template SET RequiredSkillRank="150" WHERE entry=21324;
UPDATE item_template SET description="Teaches you how to summon this mount." WHERE entry=21324;
UPDATE item_template SET RequiredSkillRank="150" WHERE entry=21218;
UPDATE item_template SET description="Teaches you how to summon this mount." WHERE entry=21218;
