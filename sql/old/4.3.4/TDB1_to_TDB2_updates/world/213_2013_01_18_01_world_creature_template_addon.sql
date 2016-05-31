-- remove auras that are already applied in SAI
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry` IN (
215, -- Defias Night Runner
579, -- Shadowhide Assassin
938, -- Kurzen Commando
1040, -- Fen Creeper
8550, -- Shadowmage
9299, -- Gaeriyan
10414, -- Patchwork Horror
10426, -- Crimson Inquisitor
10471, -- Scholomance Acolyte
11885, -- Blighthound
16017, -- Patchwork Golem
16375, -- Sewage Slime
21080, -- Dormant Infernal
22853, -- Illidari Defiler
24818, -- Anvilrage Taskmaster
25596, -- Infected Kodo Beast
25781, -- Oil Pool
26624, -- Wretched Belcher
26782, -- Crystalline Keeper
28161); -- Chicken Escapee
