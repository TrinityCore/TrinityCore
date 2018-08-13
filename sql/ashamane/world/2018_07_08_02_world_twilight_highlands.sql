
-- Twilight Highlands

update creature_template set InhabitType=4, npcflag=16777216, HoverHeight=1 where entry in (48197, 52025, 48256);

update creature set MovementType=1, spawndist=25 where id in (48197, 52025);

DELETE FROM creature_template_addon WHERE entry=52025;
INSERT INTO creature_template_addon 
(entry, path_id, mount, bytes1, bytes2, emote, aiAnimKit, movementAnimKit, meleeAnimKit, auras)
VALUES
(52025, 0, 0, 33554432, 1, 0, 0, 0, 0, "89643");

DELETE FROM creature_template_addon WHERE entry=48197;
INSERT INTO creature_template_addon 
(entry, path_id, mount, bytes1, bytes2, emote, aiAnimKit, movementAnimKit, meleeAnimKit, auras)
VALUES
(48197, 0, 0, 33554432, 1, 0, 0, 0, 0, "89643");

DELETE FROM creature_template_addon WHERE entry=48256;
INSERT INTO creature_template_addon 
(entry, path_id, mount, bytes1, bytes2, emote, aiAnimKit, movementAnimKit, meleeAnimKit, auras)
VALUES
(48256, 0, 0, 33554432, 1, 0, 0, 0, 0, "");

delete from vehicle_template_accessory where entry in (48197, 52025, 48256);
insert into vehicle_template_accessory values 
(48197, 48194, 0, 0, "Dragonmaw Skyclaw on Dragonmaw Black Drake", 6, 30000),
(52025, 52026, 0, 0, "Dragonmaw Skyclaw on Dragonmaw Black Drake", 6, 30000);

delete from npc_spellclick_spells where npc_entry in (48197, 52025, 48256);
insert into npc_spellclick_spells values 
(48197, 46598, 1, 0),
(52025, 46598, 1, 0),
(48256, 46598, 1, 0);

-- (48256, 48257, 0, 0, "Narkrall Rakeclaw on Torth The Ravenous", 6, 30000); should spawn as finish of fight.. spawn on gossip whith questgiver..
delete from creature where id in (48256, 48257);


