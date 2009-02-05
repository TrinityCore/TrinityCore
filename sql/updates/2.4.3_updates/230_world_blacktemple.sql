DELETE FROM spell_linked_spell WHERE `spell_trigger` IN (39992, 39835, 42052, -41914, -41917, 41126, -41376, 39908);
-- INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (39992, 39835, 1, 'Needle Spine');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (39835, 39968, 1, 'Needle Spine');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (-41376, 41377, 0, 'Spite');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (41126, 41131, 1, 'Flame Crash');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (-41914, 41915, 0, 'Summon Parasitic Shadowfiend');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (-41917, 41915, 0, 'Summon Parasitic Shadowfiend');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (39908, 40017, 1, 'Eye Blast');

-- spine
update gameobject_template set scriptname = 'go_najentus_spine' where entry = 185584;
-- molten_flame
UPDATE creature_template SET spell1 = 40980, flags_extra = 128, speed = 1.0, scriptname = 'molten_flame' WHERE entry = 23095;
-- volcano
UPDATE creature_template SET spell1 = 40117, flags_extra = 128, scriptname = '' WHERE entry = 23085;
-- flame crash
update creature_template set spell1 = 40836, flags_extra = 128, scriptname = '' where entry = 23336;
-- blaze
update creature_template set spell1 = 40610, flags_extra = 128, scriptname = '' where entry = 23259;
-- glaive
update creature_template set scriptname = 'mob_blade_of_azzinoth' where entry = 22996;
-- parasitic shadowfiend
update creature_template set scriptname = 'mob_parasitic_shadowfiend' where entry = 23498;
-- Maiev
update creature_template set minlevel = 73, maxlevel = 73, minhealth = 500000, maxhealth = 500000, mindmg = 3000, maxdmg = 4000 where entry = 23197;